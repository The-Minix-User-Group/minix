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
# In CI guest boots, /usr may already be mounted or exposed under a different
# block node. Accept existing writable /usr; otherwise try common ext2 nodes.
PREP_USR_MOUNT_CMD='prepare_usr_mount=PATH=/sbin:/bin:/usr/bin; if ! test -w /usr; then umount /usr >/dev/null 2>&1 || true; for dev in /dev/c0d0p2 /dev/c0d1p2 /dev/c0d0 /dev/c0d1; do mount -t ext2 "$dev" /usr >/dev/null 2>&1 && break; done; test -w /usr || mount /usr >/dev/null 2>&1 || true; fi; test -w /usr'
PREP_TMP_CMD='prepare_tmp=PATH=/sbin:/bin:/usr/bin; test -w /usr'
CC_DETECT_CMD='native_cc_detect=PATH=/sbin:/bin:/usr/bin; test -x /usr/bin/cc || test -x /usr/bin/gcc || test -x /usr/bin/clang'
CXX_DETECT_CMD='native_cxx_detect=PATH=/sbin:/bin:/usr/bin; command -v c++ >/dev/null 2>&1 || command -v g++ >/dev/null 2>&1'
PP_DETECT_CMD='native_pp_detect=PATH=/sbin:/bin:/usr/bin; command -v cpp >/dev/null 2>&1 || command -v gcpp >/dev/null 2>&1'
TOOLS_CMD='native_tools=PATH=/sbin:/bin:/usr/bin; command -v as >/dev/null 2>&1 && command -v ld >/dev/null 2>&1 && command -v ar >/dev/null 2>&1 && command -v ranlib >/dev/null 2>&1'
TOOLS_EXT_CMD='native_tools_ext=PATH=/sbin:/bin:/usr/bin; command -v nm >/dev/null 2>&1 && command -v objcopy >/dev/null 2>&1 && command -v objdump >/dev/null 2>&1 && command -v readelf >/dev/null 2>&1 && command -v strip >/dev/null 2>&1'
WORKDIR_PREP_CMD='native_workdir_prep=PATH=/sbin:/bin:/usr/bin; mkdir -p /usr/nt && rm -f /usr/nt/*'
CC_ALIAS_BUILD_CMD='native_cc_alias_build=PATH=/sbin:/bin:/usr/bin; ok=0; for c in cc gcc; do if command -v "$c" >/dev/null 2>&1; then printf "int main(void){return 0;}\n" | TMPDIR=/usr TMP=/usr TEMP=/usr "$c" -pipe -x c - -c -o /usr/nt/"$c".o || exit 1; ok=1; fi; done; test "$ok" -eq 1'
CPP_ALIAS_RUN_CMD='native_cpp_alias_run=PATH=/sbin:/bin:/usr/bin; ok=0; for p in cpp gcpp; do if command -v "$p" >/dev/null 2>&1; then printf "#define V 9\nV\n" | "$p" -P - >/usr/nt/"$p".txt || exit 1; test -s /usr/nt/"$p".txt || exit 1; ok=1; fi; done; test "$ok" -eq 1'
AS_OBJ_CMD='native_as_obj=PATH=/sbin:/bin:/usr/bin; printf ".text\n.globl nt\nnt:\n  nop\n" | as -o /usr/nt/asm.o && test -s /usr/nt/asm.o'
AR_RANLIB_CMD='native_ar_ranlib=PATH=/sbin:/bin:/usr/bin; ar rcs /usr/nt/libnt.a /usr/nt/asm.o && ranlib /usr/nt/libnt.a && test -s /usr/nt/libnt.a'
LD_RELOC_CMD='native_ld_reloc=PATH=/sbin:/bin:/usr/bin; cc_bin=$(command -v cc || command -v gcc); printf "int foo(void){return 42;}\n" | TMPDIR=/usr TMP=/usr TEMP=/usr "$cc_bin" -pipe -x c - -c -o /usr/nt/foo.o && ld -r /usr/nt/foo.o /usr/nt/asm.o -o /usr/nt/combo.o && test -s /usr/nt/combo.o'
NM_CHECK_CMD='native_nm_check=PATH=/sbin:/bin:/usr/bin; nm /usr/nt/libnt.a >/usr/nt/nm.txt && grep -q "nt$" /usr/nt/nm.txt'
OBJCOPY_CMD='native_objcopy=PATH=/sbin:/bin:/usr/bin; objcopy /usr/nt/combo.o /usr/nt/combo.copy.o && test -s /usr/nt/combo.copy.o'
OBJDUMP_CMD='native_objdump=PATH=/sbin:/bin:/usr/bin; objdump -t /usr/nt/combo.o >/usr/nt/objdump.txt && test -s /usr/nt/objdump.txt'
READELF_CMD='native_readelf=PATH=/sbin:/bin:/usr/bin; readelf -h /usr/nt/combo.o >/usr/nt/readelf.txt && grep -q "ELF" /usr/nt/readelf.txt'
STRIP_CMD='native_strip=PATH=/sbin:/bin:/usr/bin; cp /usr/nt/combo.copy.o /usr/nt/combo.strip.o && strip /usr/nt/combo.strip.o >/dev/null 2>&1 && test -s /usr/nt/combo.strip.o'
CC_LINK_RUN_CMD='native_cc_link_run=PATH=/sbin:/bin:/usr/bin; cc_bin=$(command -v cc || command -v gcc); printf "#include <stdio.h>\nint main(void){puts(\"CC_LINK_OK\");return 0;}\n" | TMPDIR=/usr TMP=/usr TEMP=/usr "$cc_bin" -pipe -static -x c - -o /usr/nt/cc_link && /usr/nt/cc_link | grep -q CC_LINK_OK'
GCC_LINK_RUN_CMD='native_gcc_link_run=PATH=/sbin:/bin:/usr/bin; if command -v gcc >/dev/null 2>&1; then printf "#include <stdio.h>\nint main(void){puts(\"GCC_LINK_OK\");return 0;}\n" | TMPDIR=/usr TMP=/usr TEMP=/usr gcc -pipe -static -x c - -o /usr/nt/gcc_link && /usr/nt/gcc_link | grep -q GCC_LINK_OK; fi'
CXX_ALIAS_LINK_RUN_CMD='native_cxx_alias_link_run=PATH=/sbin:/bin:/usr/bin; ok=0; n=0; for c in c++ g++; do if command -v "$c" >/dev/null 2>&1; then printf "#include <iostream>\nint main(){std::cout<<\"CXX_LINK_OK\";return 0;}\n" | TMPDIR=/usr TMP=/usr TEMP=/usr "$c" -pipe -static -x c++ - -o /usr/nt/cxx_link${n} || exit 1; /usr/nt/cxx_link${n} | grep -q CXX_LINK_OK || exit 1; n=$((n+1)); ok=1; fi; done; test "$ok" -eq 1'
OPTIONAL_TOOLS_CMD='native_optional_tools=PATH=/sbin:/bin:/usr/bin; for t in size strings; do if command -v "$t" >/dev/null 2>&1; then "$t" /usr/nt/combo.o >/dev/null 2>&1 || exit 1; fi; done'

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
  --cmd "$PP_DETECT_CMD"
  --cmd "$TOOLS_CMD"
  --cmd "$TOOLS_EXT_CMD"
  --cmd "$WORKDIR_PREP_CMD"
  --cmd "$CC_ALIAS_BUILD_CMD"
  --cmd "$CPP_ALIAS_RUN_CMD"
  --cmd "$AS_OBJ_CMD"
  --cmd "$AR_RANLIB_CMD"
  --cmd "$LD_RELOC_CMD"
  --cmd "$NM_CHECK_CMD"
  --cmd "$OBJCOPY_CMD"
  --cmd "$OBJDUMP_CMD"
  --cmd "$READELF_CMD"
  --cmd "$STRIP_CMD"
  --cmd "$CC_LINK_RUN_CMD"
  --cmd "$GCC_LINK_RUN_CMD"
  --cmd "$CXX_ALIAS_LINK_RUN_CMD"
  --cmd "$OPTIONAL_TOOLS_CMD"
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
