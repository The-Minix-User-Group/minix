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

# Keep each runtime command short: long single-line commands can be truncated
# by the guest TTY line discipline and hang waiting for completion.
PREP_USR_UMOUNT_CMD='prepare_usr_umount=/bin/umount /usr >/dev/null 2>&1 || true'
PREP_USR_MOUNT_STAGE1_CMD='prepare_usr_mount_stage1=[ -x /usr/bin/cc -o -x /usr/bin/gcc ] || /bin/mount -t ext2 /dev/c0d0p2 /usr'
PREP_USR_MOUNT_STAGE2_CMD='prepare_usr_mount_stage2=[ -x /usr/bin/cc -o -x /usr/bin/gcc ] || /bin/mount -t ext2 /dev/c0d1p2 /usr || true'
PREP_USR_CHECK_CMD='prepare_usr_check=/bin/mount | /bin/grep /usr >/dev/null || (/bin/mount; false)'
PREP_TMP_CMD='prepare_tmp=test -w /usr'
CC_DETECT_CMD='native_cc_detect=test -x /usr/bin/cc || test -x /usr/bin/gcc || (/bin/mount | /bin/grep /usr >/dev/null || /bin/mount; ls -l /usr/bin/cc /usr/bin/gcc /usr/bin/clang 2>&1; false)'
CXX_DETECT_CMD='native_cxx_detect=PATH=/sbin:/bin:/usr/bin; command -v c++ >/dev/null 2>&1 || command -v g++ >/dev/null 2>&1'
PP_DETECT_CMD='native_pp_detect=PATH=/sbin:/bin:/usr/bin; command -v cpp >/dev/null 2>&1 || command -v gcpp >/dev/null 2>&1'
TOOLS_CMD='native_tools=PATH=/sbin:/bin:/usr/bin; command -v as >/dev/null 2>&1 && command -v ld >/dev/null 2>&1 && command -v ar >/dev/null 2>&1 && command -v ranlib >/dev/null 2>&1'
TOOLS_EXT_CMD='native_tools_ext=PATH=/sbin:/bin:/usr/bin; command -v nm >/dev/null 2>&1 && command -v objcopy >/dev/null 2>&1 && command -v objdump >/dev/null 2>&1 && command -v readelf >/dev/null 2>&1 && command -v strip >/dev/null 2>&1'
WORKDIR_PREP_CMD='native_workdir_prep=test -w /usr'
SRC_C_PREP_CMD='native_src_c_prep=PATH=/sbin:/bin:/usr/bin; printf "int main(void){return 0;}\n" >/usr/nt_t.c'
CC_ALIAS_CC_BUILD_CMD='native_cc_alias_cc_build=PATH=/sbin:/bin:/usr/bin; if command -v cc >/dev/null 2>&1; then TMPDIR=/usr TMP=/usr TEMP=/usr cc -pipe -c /usr/nt_t.c -o /usr/nt_cc.o; fi'
CC_ALIAS_GCC_BUILD_CMD='native_cc_alias_gcc_build=PATH=/sbin:/bin:/usr/bin; if command -v gcc >/dev/null 2>&1; then TMPDIR=/usr TMP=/usr TEMP=/usr gcc -pipe -c /usr/nt_t.c -o /usr/nt_gcc.o; fi'
CC_ALIAS_BUILD_CHECK_CMD='native_cc_alias_build_check=PATH=/sbin:/bin:/usr/bin; test -s /usr/nt_cc.o || test -s /usr/nt_gcc.o'
SRC_CPP_PREP_CMD='native_src_cpp_prep=PATH=/sbin:/bin:/usr/bin; printf "#define V 9\nV\n" >/usr/nt_macro.c'
CPP_ALIAS_CPP_RUN_CMD='native_cpp_alias_cpp_run=PATH=/sbin:/bin:/usr/bin; if command -v cpp >/dev/null 2>&1; then cpp -P /usr/nt_macro.c >/usr/nt_cpp.txt; fi'
CPP_ALIAS_GCPP_RUN_CMD='native_cpp_alias_gcpp_run=PATH=/sbin:/bin:/usr/bin; if command -v gcpp >/dev/null 2>&1; then gcpp -P /usr/nt_macro.c >/usr/nt_gcpp.txt; fi'
CPP_ALIAS_RUN_CHECK_CMD='native_cpp_alias_run_check=PATH=/sbin:/bin:/usr/bin; test -s /usr/nt_cpp.txt || test -s /usr/nt_gcpp.txt'
AS_OBJ_CMD='native_as_obj=PATH=/sbin:/bin:/usr/bin; printf ".text\n.globl nt\nnt:\n  nop\n" | as -o /usr/nt_asm.o && test -s /usr/nt_asm.o'
AR_RANLIB_CMD='native_ar_ranlib=PATH=/sbin:/bin:/usr/bin; ar rcs /usr/nt_libnt.a /usr/nt_asm.o && ranlib /usr/nt_libnt.a && test -s /usr/nt_libnt.a'
LD_SRC_PREP_CMD='native_ld_src_prep=PATH=/sbin:/bin:/usr/bin; printf "int foo(void){return 42;}\n" >/usr/nt_foo.c'
LD_OBJ_PREP_CMD='native_ld_obj_prep=PATH=/sbin:/bin:/usr/bin; cc_bin=$(command -v cc || command -v gcc); TMPDIR=/usr TMP=/usr TEMP=/usr "$cc_bin" -pipe -c /usr/nt_foo.c -o /usr/nt_foo.o'
LD_RELOC_CMD='native_ld_reloc=PATH=/sbin:/bin:/usr/bin; ld -r /usr/nt_foo.o /usr/nt_asm.o -o /usr/nt_combo.o && test -s /usr/nt_combo.o'
NM_CHECK_CMD='native_nm_check=PATH=/sbin:/bin:/usr/bin; nm /usr/nt_libnt.a >/usr/nt_nm.txt && test -s /usr/nt_nm.txt'
OBJCOPY_CMD='native_objcopy=PATH=/sbin:/bin:/usr/bin; objcopy /usr/nt_combo.o /usr/nt_combo.copy.o && test -s /usr/nt_combo.copy.o'
OBJDUMP_CMD='native_objdump=PATH=/sbin:/bin:/usr/bin; objdump -t /usr/nt_combo.o >/usr/nt_objdump.txt && test -s /usr/nt_objdump.txt'
READELF_CMD='native_readelf=PATH=/sbin:/bin:/usr/bin; readelf -h /usr/nt_combo.o >/usr/nt_readelf.txt && test -s /usr/nt_readelf.txt'
STRIP_CMD='native_strip=PATH=/sbin:/bin:/usr/bin; objcopy /usr/nt_combo.copy.o /usr/nt_combo.strip.o && strip /usr/nt_combo.strip.o >/dev/null 2>&1 && test -s /usr/nt_combo.strip.o'
CC_LINK_SRC_CMD='native_cc_link_src=PATH=/sbin:/bin:/usr/bin; printf "#include <stdio.h>\nint main(void){puts(\"CC_LINK_OK\");return 0;}\n" >/usr/nt_cc_link.c'
CC_LINK_BUILD_CMD='native_cc_link_build=PATH=/sbin:/bin:/usr/bin; cc_bin=$(command -v cc || command -v gcc); TMPDIR=/usr TMP=/usr TEMP=/usr "$cc_bin" -pipe -static /usr/nt_cc_link.c -o /usr/nt_cc_link'
CC_LINK_RUN_CMD='native_cc_link_run=PATH=/sbin:/bin:/usr/bin; /usr/nt_cc_link >/usr/nt_cc_link.out && test -s /usr/nt_cc_link.out'
GCC_LINK_BUILD_CMD='native_gcc_link_build=PATH=/sbin:/bin:/usr/bin; if command -v gcc >/dev/null 2>&1; then TMPDIR=/usr TMP=/usr TEMP=/usr gcc -pipe -static /usr/nt_cc_link.c -o /usr/nt_gcc_link; fi'
GCC_LINK_RUN_CMD='native_gcc_link_run=PATH=/sbin:/bin:/usr/bin; if test -x /usr/nt_gcc_link; then /usr/nt_gcc_link >/usr/nt_gcc_link.out && test -s /usr/nt_gcc_link.out; fi'
CXX_LINK_SRC_CMD='native_cxx_link_src=PATH=/sbin:/bin:/usr/bin; printf "#include <iostream>\nint main(){std::cout<<\"CXX_LINK_OK\";return 0;}\n" >/usr/nt_cxx_link.cc'
CXX_LINK_CXX_BUILD_CMD='native_cxx_link_cxx_build=PATH=/sbin:/bin:/usr/bin; if command -v c++ >/dev/null 2>&1; then TMPDIR=/usr TMP=/usr TEMP=/usr c++ -pipe -static /usr/nt_cxx_link.cc -o /usr/nt_cxx_link_cxx; fi'
CXX_LINK_GPP_BUILD_CMD='native_cxx_link_gpp_build=PATH=/sbin:/bin:/usr/bin; if command -v g++ >/dev/null 2>&1; then TMPDIR=/usr TMP=/usr TEMP=/usr g++ -pipe -static /usr/nt_cxx_link.cc -o /usr/nt_cxx_link_gpp; fi'
CXX_LINK_CXX_RUN_CMD='native_cxx_link_cxx_run=PATH=/sbin:/bin:/usr/bin; if test -x /usr/nt_cxx_link_cxx; then /usr/nt_cxx_link_cxx >/usr/nt_cxx_link_cxx.out && test -s /usr/nt_cxx_link_cxx.out; fi'
CXX_LINK_GPP_RUN_CMD='native_cxx_link_gpp_run=PATH=/sbin:/bin:/usr/bin; if test -x /usr/nt_cxx_link_gpp; then /usr/nt_cxx_link_gpp >/usr/nt_cxx_link_gpp.out && test -s /usr/nt_cxx_link_gpp.out; fi'
CXX_LINK_CHECK_CMD='native_cxx_link_check=PATH=/sbin:/bin:/usr/bin; test -x /usr/nt_cxx_link_cxx || test -x /usr/nt_cxx_link_gpp'
OPTIONAL_TOOLS_CMD='native_optional_tools=PATH=/sbin:/bin:/usr/bin; for t in size strings; do if command -v "$t" >/dev/null 2>&1; then "$t" /usr/nt_combo.o >/dev/null 2>&1 || exit 1; fi; done'

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
  --cmd "$PREP_USR_UMOUNT_CMD"
  --cmd "$PREP_USR_MOUNT_STAGE1_CMD"
  --cmd "$PREP_USR_MOUNT_STAGE2_CMD"
  --cmd "$PREP_USR_CHECK_CMD"
  --cmd "$PREP_TMP_CMD"
  --cmd "$CC_DETECT_CMD"
  --cmd "$CXX_DETECT_CMD"
  --cmd "$PP_DETECT_CMD"
  --cmd "$TOOLS_CMD"
  --cmd "$TOOLS_EXT_CMD"
  --cmd "$WORKDIR_PREP_CMD"
  --cmd "$SRC_C_PREP_CMD"
  --cmd "$CC_ALIAS_CC_BUILD_CMD"
  --cmd "$CC_ALIAS_GCC_BUILD_CMD"
  --cmd "$CC_ALIAS_BUILD_CHECK_CMD"
  --cmd "$SRC_CPP_PREP_CMD"
  --cmd "$CPP_ALIAS_CPP_RUN_CMD"
  --cmd "$CPP_ALIAS_GCPP_RUN_CMD"
  --cmd "$CPP_ALIAS_RUN_CHECK_CMD"
  --cmd "$AS_OBJ_CMD"
  --cmd "$AR_RANLIB_CMD"
  --cmd "$LD_SRC_PREP_CMD"
  --cmd "$LD_OBJ_PREP_CMD"
  --cmd "$LD_RELOC_CMD"
  --cmd "$NM_CHECK_CMD"
  --cmd "$OBJCOPY_CMD"
  --cmd "$OBJDUMP_CMD"
  --cmd "$READELF_CMD"
  --cmd "$STRIP_CMD"
  --cmd "$CC_LINK_SRC_CMD"
  --cmd "$CC_LINK_BUILD_CMD"
  --cmd "$CC_LINK_RUN_CMD"
  --cmd "$GCC_LINK_BUILD_CMD"
  --cmd "$GCC_LINK_RUN_CMD"
  --cmd "$CXX_LINK_SRC_CMD"
  --cmd "$CXX_LINK_CXX_BUILD_CMD"
  --cmd "$CXX_LINK_GPP_BUILD_CMD"
  --cmd "$CXX_LINK_CXX_RUN_CMD"
  --cmd "$CXX_LINK_GPP_RUN_CMD"
  --cmd "$CXX_LINK_CHECK_CMD"
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
