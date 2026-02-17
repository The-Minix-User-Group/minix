#!/bin/bash
#
# Multi-run QEMU smoke gate for riscv64.
# Runs diskless and with-disk smoke for several rounds and fails on:
#   - boot failure
#   - fatal signatures
#   - safecopy classification == potential consistency issue
#   - with-disk virtio startup regressions
#

set -eu

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
MINIX_ROOT="$(cd "$SCRIPT_DIR/../../.." && pwd)"
QEMU_SCRIPT="$MINIX_ROOT/minix/scripts/qemu-riscv64.sh"
TRIAGE_SCRIPT="$SCRIPT_DIR/safecopy_triage.py"
RUNTIME_PROBE_SCRIPT="$SCRIPT_DIR/qemu_runtime_probe.py"

KERNEL_DEFAULT="$MINIX_ROOT/obj.intrgcc/minix/kernel/kernel"
DESTDIR_DEFAULT="$MINIX_ROOT/obj.intrgcc/destdir.evbriscv64"

KERNEL="${KERNEL:-$KERNEL_DEFAULT}"
DESTDIR="${DESTDIR:-$DESTDIR_DEFAULT}"
ROUNDS=3
TIMEOUT_SEC=140
WITH_DISK=1
DISK_IMAGE="${DISK_IMAGE:-}"
DISK_SIZE_MB=128
LOG_ROOT="${LOG_ROOT:-/tmp/minix-smoke-gate-$(date +%Y%m%d-%H%M%S)}"
MAX_TOTAL_SAFECOPY=24
MAX_PRE_SHELL_SAFECOPY=8
REUSE_DISK=0
RUNTIME_PROBE=1
RUNTIME_TIMEOUT=120
RUNTIME_CMD_TIMEOUT=45

passed=0
failed=0
runtime_passed=0
runtime_failed=0

usage() {
    cat <<EOF
Usage: $0 [options]

Options:
  --kernel PATH                  Kernel image (default: $KERNEL_DEFAULT)
  --destdir PATH                 Destdir root (default: $DESTDIR_DEFAULT)
  --rounds N                     Number of rounds (default: 3)
  --timeout SEC                  Per-run timeout seconds (default: 140)
  --with-disk                    Enable with-disk runs (default: on)
  --without-disk                 Disable with-disk runs
  --disk-image PATH              Disk image base path (default: <log-root>/minix-smoke-gate.img)
  --reuse-disk                   Reuse a single disk image across rounds
  --disk-size-mb N               Disk image size in MB if created (default: 128)
  --log-root PATH                Output log directory
  --max-total-safecopy N         Triage threshold (default: 24)
  --max-pre-shell-safecopy N     Triage threshold (default: 8)
  --runtime-probe                Enable runtime command probe (default: on)
  --no-runtime-probe             Disable runtime command probe
  --runtime-timeout SEC          Runtime probe boot timeout (default: 120)
  --runtime-cmd-timeout SEC      Runtime probe per-command timeout (default: 45)
EOF
}

while [ $# -gt 0 ]; do
    case "$1" in
        --kernel) KERNEL="$2"; shift 2 ;;
        --destdir) DESTDIR="$2"; shift 2 ;;
        --rounds) ROUNDS="$2"; shift 2 ;;
        --timeout) TIMEOUT_SEC="$2"; shift 2 ;;
        --with-disk) WITH_DISK=1; shift ;;
        --without-disk) WITH_DISK=0; shift ;;
        --disk-image) DISK_IMAGE="$2"; shift 2 ;;
        --reuse-disk) REUSE_DISK=1; shift ;;
        --disk-size-mb) DISK_SIZE_MB="$2"; shift 2 ;;
        --log-root) LOG_ROOT="$2"; shift 2 ;;
        --max-total-safecopy) MAX_TOTAL_SAFECOPY="$2"; shift 2 ;;
        --max-pre-shell-safecopy) MAX_PRE_SHELL_SAFECOPY="$2"; shift 2 ;;
        --runtime-probe) RUNTIME_PROBE=1; shift ;;
        --no-runtime-probe) RUNTIME_PROBE=0; shift ;;
        --runtime-timeout) RUNTIME_TIMEOUT="$2"; shift 2 ;;
        --runtime-cmd-timeout) RUNTIME_CMD_TIMEOUT="$2"; shift 2 ;;
        -h|--help) usage; exit 0 ;;
        *) echo "unknown option: $1" >&2; usage; exit 1 ;;
    esac
done

prepare_disk_image() {
    local disk_image="$1"

    mkdir -p "$(dirname "$disk_image")"
    if [ "$REUSE_DISK" -eq 1 ] && [ -f "$disk_image" ]; then
        echo "[INFO] reusing disk image: $disk_image"
    else
        rm -f "$disk_image"
        truncate -s "${DISK_SIZE_MB}M" "$disk_image"
        echo "[INFO] fresh disk image prepared: $disk_image"
    fi
}

disk_image_for_round() {
    local round="$1"

    if [ "$REUSE_DISK" -eq 1 ]; then
        echo "$DISK_IMAGE"
        return
    fi

    case "$DISK_IMAGE" in
        *.img) echo "${DISK_IMAGE%.img}.round${round}.img" ;;
        *) echo "${DISK_IMAGE}.round${round}.img" ;;
    esac
}

if [ ! -x "$QEMU_SCRIPT" ]; then
    echo "qemu script not found: $QEMU_SCRIPT" >&2
    exit 1
fi
if [ ! -f "$KERNEL" ]; then
    echo "kernel not found: $KERNEL" >&2
    exit 1
fi
if [ ! -d "$DESTDIR" ]; then
    echo "destdir not found: $DESTDIR" >&2
    exit 1
fi
if ! command -v python3 >/dev/null 2>&1; then
    echo "python3 is required" >&2
    exit 1
fi
if [ ! -f "$TRIAGE_SCRIPT" ]; then
    echo "triage script not found: $TRIAGE_SCRIPT" >&2
    exit 1
fi
if [ "$RUNTIME_PROBE" -eq 1 ] && [ ! -f "$RUNTIME_PROBE_SCRIPT" ]; then
    echo "runtime probe script not found: $RUNTIME_PROBE_SCRIPT" >&2
    exit 1
fi

mkdir -p "$LOG_ROOT"

if [ "$WITH_DISK" -eq 1 ]; then
    if [ -z "$DISK_IMAGE" ]; then
        DISK_IMAGE="$LOG_ROOT/minix-smoke-gate.img"
    fi

    if [ "$REUSE_DISK" -eq 1 ]; then
        prepare_disk_image "$DISK_IMAGE"
    fi
fi

run_one() {
    local case_name="$1"
    local round="$2"
    shift 2

    local log_file="$LOG_ROOT/${case_name}.round${round}.log"
    local triage_file="$LOG_ROOT/${case_name}.round${round}.triage.txt"
    local rc

    echo "[INFO] round=${round} case=${case_name}"
    if timeout "$TIMEOUT_SEC" "$QEMU_SCRIPT" -s -k "$KERNEL" -B "$DESTDIR" "$@" \
        >"$log_file" 2>&1; then
        rc=0
    else
        rc=$?
    fi

    case "$rc" in
        0)
            echo "[INFO] ${case_name} round ${round}: runner exited cleanly (rc=0)"
            ;;
        124|137)
            echo "[INFO] ${case_name} round ${round}: runner timeout/terminated (rc=${rc})"
            ;;
        *)
            echo "[FAIL] ${case_name} round ${round}: runner exited abnormally (rc=${rc})"
            failed=$((failed + 1))
            return 1
            ;;
    esac

    if ! grep -Eq 'MINIX 3\.4\.0|exec path="/bin/sh"' "$log_file"; then
        echo "[FAIL] ${case_name} round ${round}: boot marker missing"
        failed=$((failed + 1))
        return 1
    fi

    if grep -Eq 'panic|PANIC|SIGSEGV|Segmentation fault|assertion failed|kernel panic' "$log_file"; then
        echo "[FAIL] ${case_name} round ${round}: fatal signature in log"
        failed=$((failed + 1))
        return 1
    fi

    if python3 "$TRIAGE_SCRIPT" "$log_file" \
        --max-total-safecopy "$MAX_TOTAL_SAFECOPY" \
        --max-pre-shell-safecopy "$MAX_PRE_SHELL_SAFECOPY" \
        >"$triage_file"; then
        :
    else
        rc=$?
        if [ "$rc" -eq 2 ]; then
            echo "[FAIL] ${case_name} round ${round}: safecopy triage flagged potential consistency issue"
        else
            echo "[FAIL] ${case_name} round ${round}: safecopy triage failed (rc=${rc})"
        fi
        failed=$((failed + 1))
        return 1
    fi

    if [ "$case_name" = "withdisk" ]; then
        if ! grep -q 'virtio-blk-mmio: initialized' "$log_file"; then
            echo "[FAIL] ${case_name} round ${round}: virtio-blk-mmio initialization marker missing"
            failed=$((failed + 1))
            return 1
        fi
        if grep -Eq "virtio-blk-mmio: device not found|Request 0x700 to RS failed|WARNING: couldn't start virtio_blk_mmio" "$log_file"; then
            echo "[FAIL] ${case_name} round ${round}: old virtio startup failure signature reproduced"
            failed=$((failed + 1))
            return 1
        fi
    else
        if grep -Eq "virtio-blk-mmio: device not found|Request 0x700 to RS failed|WARNING: couldn't start virtio_blk_mmio" "$log_file"; then
            echo "[FAIL] ${case_name} round ${round}: unexpected diskless virtio startup noise"
            failed=$((failed + 1))
            return 1
        fi
    fi

    echo "[PASS] ${case_name} round ${round}"
    passed=$((passed + 1))
    return 0
}

run_runtime_probe() {
    local case_name="$1"
    local round="$2"
    local round_disk_image="${3:-}"
    local runtime_log="$LOG_ROOT/${case_name}.round${round}.runtime.log"
    local rc
    local args=(
        --qemu-script "$QEMU_SCRIPT"
        --kernel "$KERNEL"
        --destdir "$DESTDIR"
        --timeout "$RUNTIME_TIMEOUT"
        --cmd-timeout "$RUNTIME_CMD_TIMEOUT"
    )

    if [ -n "$round_disk_image" ]; then
        args+=(--disk "$round_disk_image" --require-disk-node)
    fi

    echo "[INFO] runtime probe round=${round} case=${case_name}"
    if python3 "$RUNTIME_PROBE_SCRIPT" "${args[@]}" >"$runtime_log" 2>&1; then
        runtime_passed=$((runtime_passed + 1))
        echo "[PASS] runtime ${case_name} round ${round}"
        return 0
    else
        rc=$?
    fi

    runtime_failed=$((runtime_failed + 1))
    failed=$((failed + 1))
    if [ "$rc" -eq 2 ]; then
        echo "[FAIL] runtime ${case_name} round ${round}: probe skipped unexpectedly"
    else
        echo "[FAIL] runtime ${case_name} round ${round}: probe failed (rc=${rc})"
    fi
    return 1
}

i=1
while [ "$i" -le "$ROUNDS" ]; do
    round_disk_image=""

    if run_one "diskless" "$i"; then
        if [ "$RUNTIME_PROBE" -eq 1 ]; then
            run_runtime_probe "diskless" "$i" || true
        fi
    fi

    if [ "$WITH_DISK" -eq 1 ]; then
        round_disk_image="$(disk_image_for_round "$i")"
        if [ "$REUSE_DISK" -eq 0 ]; then
            prepare_disk_image "$round_disk_image"
        fi
        if run_one "withdisk" "$i" -i "$round_disk_image"; then
            if [ "$RUNTIME_PROBE" -eq 1 ]; then
                run_runtime_probe "withdisk" "$i" "$round_disk_image" || true
            fi
        fi
    fi
    i=$((i + 1))
done

echo ""
echo "========================================="
echo "Multi Smoke Gate Summary"
echo "========================================="
echo "Log root: $LOG_ROOT"
echo "Passed:   $passed"
echo "Failed:   $failed"
if [ "$RUNTIME_PROBE" -eq 1 ]; then
    echo "Runtime passed: $runtime_passed"
    echo "Runtime failed: $runtime_failed"
fi
echo "========================================="

if [ "$failed" -ne 0 ]; then
    exit 1
fi

exit 0
