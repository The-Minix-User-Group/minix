#!/bin/bash
#
# Build helper for MINIX/riscv64 native-toolchain profile.
#
# This script captures the current recommended baseline flags for building a
# runtime image that is expected to include native compiler commands.
#

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
MINIX_ROOT="$(cd "${SCRIPT_DIR}/../../.." && pwd)"
cd "$MINIX_ROOT"

OBJDIR="obj.intrgcc"
MACHINE="evbriscv64"
JOBS="$(getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)"
WITH_TOOLS=0
TMPDIR_OVERRIDE=""

usage() {
  cat <<'USAGE'
Usage: native_toolchain_build.sh [options]

Options:
  --objdir <name>      Object directory (default: obj.intrgcc)
  --machine <name>     Target machine (default: evbriscv64)
  -j, --jobs <n>       Parallel jobs for distribution (default: host cpu count)
  --tmpdir <path>      Host temp directory used during build (default: <objdir>/tmp.host)
  --with-tools         Rebuild tools before distribution
  -h, --help           Show this help

Notes:
  - This helper uses MKGCC=yes + MKGCCCMDS=yes to target native compiler command
    availability in guest image.
  - Build time is significant (especially with --with-tools).
USAGE
}

while [ $# -gt 0 ]; do
  case "$1" in
    --objdir)
      OBJDIR="$2"
      shift 2
      ;;
    --machine)
      MACHINE="$2"
      shift 2
      ;;
    -j|--jobs)
      JOBS="$2"
      shift 2
      ;;
    --tmpdir)
      TMPDIR_OVERRIDE="$2"
      shift 2
      ;;
    --with-tools)
      WITH_TOOLS=1
      shift
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

if [ -n "$TMPDIR_OVERRIDE" ]; then
  TMPROOT="$TMPDIR_OVERRIDE"
else
  TMPROOT="$OBJDIR/tmp.host"
fi
case "$TMPROOT" in
  /*) ;;
  *) TMPROOT="$MINIX_ROOT/$TMPROOT" ;;
esac
mkdir -p "$TMPROOT"
if ! touch "$TMPROOT/.native_build_tmp_test" 2>/dev/null; then
  echo "[native-build] ERROR: temp directory not writable: $TMPROOT" >&2
  exit 1
fi
rm -f "$TMPROOT/.native_build_tmp_test"
export TMPDIR="$TMPROOT"
export TMP="$TMPROOT"
export TEMP="$TMPROOT"

echo "[native-build] root: $MINIX_ROOT"
echo "[native-build] machine: $MACHINE"
echo "[native-build] objdir: $OBJDIR"
echo "[native-build] jobs: $JOBS"
echo "[native-build] tmpdir: $TMPDIR"
echo "[native-build] with-tools: $WITH_TOOLS"

sync_riscv64_libstdcxx_headers() {
  case "$MACHINE" in
    evbriscv64|riscv64)
      local gthr_src="$MINIX_ROOT/external/gpl3/gcc/dist/libgcc/gthr-single.h"
      local gthr_dst="$MINIX_ROOT/$OBJDIR/destdir.$MACHINE/usr/include/g++/bits/gthr-default.h"
      local cxxcfg_src="$MINIX_ROOT/external/gpl3/gcc/lib/libstdc++-v3/arch/riscv64/c++config.h"
      local cxxcfg_dst="$MINIX_ROOT/$OBJDIR/destdir.$MACHINE/usr/include/g++/bits/c++config.h"
      mkdir -p "$(dirname "$gthr_dst")"
      cp -pf "$gthr_src" "$gthr_dst"
      cp -pf "$cxxcfg_src" "$cxxcfg_dst"
      ;;
  esac
}

COMMON_FLAGS=(
  -V AVAILABLE_COMPILER=gcc
  -V ACTIVE_CC=gcc
  -V ACTIVE_CPP=gcc
  -V ACTIVE_CXX=gcc
  -V ACTIVE_OBJC=gcc
  -V RISCV_ARCH_FLAGS='-march=RV64IMAFD -mcmodel=medany'
  -V NOGCCERROR=yes
  -V MKGCC=yes
  -V MKGCCCMDS=yes
  -V MKCXX=yes
  -V MKLIBSTDCXX=yes
  -V MKLIBOBJC=no
  -V MKLIBGOMP=no
  -V MKATF=no
  -V MKKYUA=no
  -V MKTESTS=no
  -V USE_PCI=no
  -V CHECKFLIST_FLAGS='-m -e'
)

if [ "$WITH_TOOLS" -eq 1 ]; then
  echo "[native-build] building tools..."
  MKPCI=no HOST_CFLAGS='-O -fcommon' HAVE_GOLD=no HAVE_LLVM=no MKLLVM=no \
  ./build.sh -U -m "$MACHINE" -O "$OBJDIR" \
    "${COMMON_FLAGS[@]}" \
    tools
fi

echo "[native-build] syncing riscv64 libstdc++ headers..."
sync_riscv64_libstdcxx_headers

echo "[native-build] building distribution..."
MKPCI=no HOST_CFLAGS='-O -fcommon' HAVE_GOLD=no HAVE_LLVM=no MKLLVM=no \
./build.sh -U -u -j"$JOBS" -m "$MACHINE" -O "$OBJDIR" \
  "${COMMON_FLAGS[@]}" \
  distribution

echo "[native-build] done"
echo "[native-build] next: ./minix/releasetools/riscv64/mkdisk.sh -d $OBJDIR -o /tmp/minix-native-toolchain.img -s 1024 -u 768 -U"
echo "[native-build] then: ./minix/tests/riscv64/native_toolchain_gate.sh --kernel $OBJDIR/minix/kernel/kernel --destdir $OBJDIR/destdir.evbriscv64 --disk-image /tmp/minix-native-toolchain.img"
