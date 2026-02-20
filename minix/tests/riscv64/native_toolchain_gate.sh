#!/bin/bash
#
# Native toolchain runtime gate for MINIX/riscv64.
#
# This gate boots MINIX in QEMU, verifies native toolchain commands in guest,
# and compiles/runs a small C program using guest-side compiler.
#
# Exit codes:
#   0 = pass
#   1 = fail
#   2 = skip (missing prerequisites / native compiler not present in target root)
#

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
MINIX_ROOT="$(cd "${SCRIPT_DIR}/../../.." && pwd)"

QEMU_SCRIPT="${MINIX_ROOT}/minix/scripts/qemu-riscv64.sh"
RUNTIME_PROBE="${SCRIPT_DIR}/qemu_runtime_probe.py"

KERNEL=""
DESTDIR=""
DISK_IMAGE=""
TIMEOUT=180
CMD_TIMEOUT=60

usage() {
  cat <<'USAGE'
Usage: native_toolchain_gate.sh [options]

Options:
  --qemu-script <path>   QEMU launcher script (default: minix/scripts/qemu-riscv64.sh)
  --kernel <path>        Kernel image path (default: auto-detect)
  --destdir <path>       DESTDIR root for boot modules (default: auto-detect)
  --disk-image <path>    Optional disk image passed to QEMU (-i)
  --timeout <sec>        Prompt/login timeout (default: 180)
  --cmd-timeout <sec>    Per-command timeout (default: 60)
  -h, --help             Show this help
USAGE
}

detect_kernel() {
  local candidates=(
    "${MINIX_ROOT}/obj.intrgcc/minix/kernel/kernel"
    "${MINIX_ROOT}/minix/kernel/obj/kernel"
    "${MINIX_ROOT}/obj/minix/kernel/kernel"
  )
  local c
  for c in "${candidates[@]}"; do
    if [ -f "$c" ]; then
      echo "$c"
      return 0
    fi
  done
  return 1
}

detect_destdir() {
  local candidates=(
    "${MINIX_ROOT}/obj.intrgcc/destdir.evbriscv64"
    "${MINIX_ROOT}/obj/destdir.evbriscv64"
  )
  local c
  for c in "${candidates[@]}"; do
    if [ -d "$c" ]; then
      echo "$c"
      return 0
    fi
  done
  return 1
}

while [ $# -gt 0 ]; do
  case "$1" in
    --qemu-script)
      QEMU_SCRIPT="$2"
      shift 2
      ;;
    --kernel)
      KERNEL="$2"
      shift 2
      ;;
    --destdir)
      DESTDIR="$2"
      shift 2
      ;;
    --disk-image)
      DISK_IMAGE="$2"
      shift 2
      ;;
    --timeout)
      TIMEOUT="$2"
      shift 2
      ;;
    --cmd-timeout)
      CMD_TIMEOUT="$2"
      shift 2
      ;;
    -h|--help)
      usage
      exit 0
      ;;
    *)
      echo "Unknown option: $1" >&2
      usage
      exit 1
      ;;
  esac
done

if [ -z "$KERNEL" ]; then
  KERNEL="$(detect_kernel || true)"
fi
if [ -z "$DESTDIR" ]; then
  DESTDIR="$(detect_destdir || true)"
fi

if [ ! -x "$QEMU_SCRIPT" ]; then
  echo "SKIP: qemu script not executable: $QEMU_SCRIPT"
  exit 2
fi
if [ ! -f "$RUNTIME_PROBE" ]; then
  echo "SKIP: runtime probe missing: $RUNTIME_PROBE"
  exit 2
fi
if [ -z "$KERNEL" ] || [ ! -f "$KERNEL" ]; then
  echo "SKIP: kernel not found"
  exit 2
fi
if [ -z "$DESTDIR" ] || [ ! -d "$DESTDIR" ]; then
  echo "SKIP: destdir not found"
  exit 2
fi
if [ -z "$DISK_IMAGE" ]; then
  echo "SKIP: --disk-image is required for native toolchain runtime gate"
  exit 2
fi
if [ ! -f "$DISK_IMAGE" ]; then
  echo "SKIP: disk image not found: $DISK_IMAGE"
  exit 2
fi

if [ ! -e "$DESTDIR/usr/bin/cc" ] && [ ! -e "$DESTDIR/usr/bin/gcc" ] && [ ! -e "$DESTDIR/usr/bin/clang" ]; then
  echo "SKIP: native compiler (cc/gcc/clang) not found in $DESTDIR/usr/bin"
  exit 2
fi

echo "[native-gate] kernel: $KERNEL"
echo "[native-gate] destdir: $DESTDIR"
echo "[native-gate] qemu script: $QEMU_SCRIPT"
echo "[native-gate] disk image: $DISK_IMAGE"

PREP_EXT2_CMD='prepare_ext2=PATH=/sbin:/bin:/usr/bin; test -x /service/ext2 && (minix-service up /service/ext2 >/dev/null 2>&1 || minix-service -c up /service/ext2 >/dev/null 2>&1 || true)'
PREP_USR_MOUNT_CMD='prepare_usr_mount=PATH=/sbin:/bin:/usr/bin; umount /usr >/dev/null 2>&1 || true; mount -t ext2 /dev/c0d0p2 /usr >/dev/null 2>&1'
PREP_TMP_CMD='prepare_tmp=PATH=/sbin:/bin:/usr/bin; test -w /usr'
CC_DETECT_CMD='native_cc_detect=PATH=/sbin:/bin:/usr/bin; test -x /usr/bin/cc || test -x /usr/bin/gcc || test -x /usr/bin/clang'
CXX_DETECT_CMD='native_cxx_detect=PATH=/sbin:/bin:/usr/bin; command -v c++ >/dev/null 2>&1 || command -v g++ >/dev/null 2>&1'
TOOLS_CMD='native_tools=PATH=/sbin:/bin:/usr/bin; command -v as >/dev/null 2>&1 && command -v ld >/dev/null 2>&1 && command -v ar >/dev/null 2>&1 && command -v ranlib >/dev/null 2>&1'
TOOLS_EXT_CMD='native_tools_ext=PATH=/sbin:/bin:/usr/bin; command -v nm >/dev/null 2>&1 && command -v objcopy >/dev/null 2>&1 && command -v objdump >/dev/null 2>&1 && command -v readelf >/dev/null 2>&1 && command -v strip >/dev/null 2>&1'
HELLO_PREPROCESS_CMD="native_hello_preprocess=PATH=/sbin:/bin:/usr/bin; printf 'int main(void){return 0;}\\n' | cc -pipe -x c - -E >/dev/null"
HELLO_TO_ASM_CMD="native_hello_to_asm=PATH=/sbin:/bin:/usr/bin; printf 'int main(void){return 0;}\\n' | cc -pipe -x c - -S -o /dev/null"
AS_STDIN_CMD="native_as_stdin=PATH=/sbin:/bin:/usr/bin; printf '.text\\n.globl _start\\n_start:\\n  nop\\n' | as -o /dev/null"
HELLO_BUILD_CMD="native_hello_build=PATH=/sbin:/bin:/usr/bin; printf 'int main(void){return 0;}\\n' | TMPDIR=/ TMP=/ TEMP=/ cc -pipe -x c - -c -o /dev/null"
AR_RANLIB_CMD='native_ar_ranlib=PATH=/sbin:/bin:/usr/bin; printf ".text\n.globl nt\nnt:\n  nop\n" | as -o /usr/nt.o && ar rcs /usr/nt.a /usr/nt.o && ranlib /usr/nt.a && test -s /usr/nt.a'
HELLO_LINK_RUN_CMD='native_hello_link_run=PATH=/sbin:/bin:/usr/bin; printf "#include <stdio.h>\nint main(void){puts(\"NATIVE_TOOLCHAIN_OK\");return 0;}\n" | TMPDIR=/usr TMP=/usr TEMP=/usr cc -pipe -static -x c - -o /usr/ntc && /usr/ntc | grep -q NATIVE_TOOLCHAIN_OK'
CXX_LINK_RUN_CMD='native_cxx_link_run=PATH=/sbin:/bin:/usr/bin; c=$(command -v c++ || command -v g++); printf "int main(){return 0;}\n" | TMPDIR=/usr TMP=/usr TEMP=/usr "$c" -pipe -static -x c++ - -o /usr/ntcxx && /usr/ntcxx >/dev/null 2>&1'

base_probe_args=(
  --qemu-script "$QEMU_SCRIPT"
  --kernel "$KERNEL"
  --destdir "$DESTDIR"
  --disk "$DISK_IMAGE"
  --timeout "$TIMEOUT"
  --cmd-timeout "$CMD_TIMEOUT"
)

probe_args=(
  "${base_probe_args[@]}"
  --require-disk-node
  --only-custom-cmds
  --cmd "$PREP_EXT2_CMD"
  --cmd "$PREP_USR_MOUNT_CMD"
  --cmd "$PREP_TMP_CMD"
  --cmd "$CC_DETECT_CMD"
  --cmd "$CXX_DETECT_CMD"
  --cmd "$TOOLS_CMD"
  --cmd "$TOOLS_EXT_CMD"
  --cmd "$HELLO_PREPROCESS_CMD"
  --cmd "$HELLO_TO_ASM_CMD"
  --cmd "$AS_STDIN_CMD"
  --cmd "$AR_RANLIB_CMD"
  --cmd "$HELLO_BUILD_CMD"
  --cmd "$HELLO_LINK_RUN_CMD"
  --cmd "$CXX_LINK_RUN_CMD"
)

if python3 "$RUNTIME_PROBE" "${probe_args[@]}"; then
  echo "[native-gate] PASS"
  exit 0
else
  rc=$?
  if [ "$rc" -eq 2 ]; then
    echo "[native-gate] SKIP"
  else
    echo "[native-gate] FAIL: full native toolchain link/run checks failed"
  fi
  exit "$rc"
fi
