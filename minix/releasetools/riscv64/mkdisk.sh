#!/bin/bash
#
# Create bootable disk image for MINIX RISC-V 64-bit
#
# The generated image is intended for U-Boot S-mode boot (disk-only):
#   qemu-system-riscv64 ... -bios default \
#       -kernel /usr/lib/u-boot/qemu-riscv64_smode/uboot.elf -drive ...
#

set -euo pipefail

# Ensure admin tools are discoverable even for non-root users.
PATH="/usr/sbin:/sbin:${PATH}"

# Default values
DESTDIR="${DESTDIR:-/usr/obj/minix/riscv64}"
OUTPUT="${OUTPUT:-minix-riscv64.img}"
SIZE_MB=256
KERNEL=""

# Partition layout
BOOT_SIZE_MB=8
ROOT_SIZE_MB=64
USR_SIZE_MB=128
HOME_SIZE_MB=0
BOOT_START_MB=1
ROOT_START_MB=9
USR_START_MB=73
EXT_START_MB=201
LOG_START_MB=202
MODULE_BASE_ADDR="${MODULE_BASE_ADDR:-0x81000000}"
MODINFO_ADDR="${MODINFO_ADDR:-0x80f00000}"
MODINFO_MAGIC="${MODINFO_MAGIC:-0x584e494d}"
MODULE_ALIGN="${MODULE_ALIGN:-0x1000}"
KERNEL_ENTRY_ADDR="${KERNEL_ENTRY_ADDR:-0x80200000}"

TMPDIRS=()
TMPFILES=()
MODULE_NAMES=()
MODULE_PATHS=()
MODULE_ADDRS=()
MODULE_SIZES=()
MODROOT=""
KERNEL_IMAGE=""
KERNEL_BIN_IMAGE=""
OBJCOPY_TOOL=""

log_info() {
    echo "[INFO] $1"
}

log_error() {
    echo "[ERROR] $1" >&2
}

cleanup() {
    local path
    for path in "${TMPFILES[@]:-}"; do
        [ -f "$path" ] && rm -f "$path"
    done
    for path in "${TMPDIRS[@]:-}"; do
        [ -d "$path" ] && rm -rf "$path"
    done
}
trap cleanup EXIT

usage() {
    cat << EOF
Usage: $0 [options]

Create bootable disk image for MINIX RISC-V 64-bit.

Options:
    -d DESTDIR     Build output root (default: /usr/obj/minix/riscv64)
    -o OUTPUT      Output disk image (default: minix-riscv64.img)
    -s SIZE        Disk size in MB (default: 256)
    -k KERNEL      Explicit kernel ELF path
    -h             Show help

Examples:
    $0 -d /home/user/minix/obj.intrgcc -o minix-evbriscv64.img
    $0 -k /path/to/kernel -o minix-evbriscv64.img
EOF
    exit 0
}

while getopts "d:o:s:k:h" opt; do
    case $opt in
        d) DESTDIR="$OPTARG" ;;
        o) OUTPUT="$OPTARG" ;;
        s) SIZE_MB="$OPTARG" ;;
        k) KERNEL="$OPTARG" ;;
        h) usage ;;
        *) usage ;;
    esac
done

need_tool() {
    local tool="$1"
    command -v "$tool" >/dev/null 2>&1 || {
        log_error "Missing required tool: $tool"
        exit 1
    }
}

check_tools() {
    local tooldir_objcopy

    need_tool dd
    need_tool stat
    need_tool mke2fs
    need_tool mkimage
    need_tool python3

    if [ -n "${OBJCOPY_TOOL:-}" ]; then
        if command -v "$OBJCOPY_TOOL" >/dev/null 2>&1 || [ -x "$OBJCOPY_TOOL" ]; then
            :
        else
            log_error "Requested OBJCOPY_TOOL is not executable: $OBJCOPY_TOOL"
            exit 1
        fi
    elif command -v riscv64-elf32-minix-objcopy >/dev/null 2>&1; then
        OBJCOPY_TOOL="riscv64-elf32-minix-objcopy"
    else
        tooldir_objcopy=$(find "$DESTDIR" -maxdepth 3 -type f \
            -path '*/tooldir.*/bin/riscv64-elf32-minix-objcopy' \
            -print -quit 2>/dev/null || true)
        if [ -n "$tooldir_objcopy" ]; then
            OBJCOPY_TOOL="$tooldir_objcopy"
        fi
    fi

    if [ -z "$OBJCOPY_TOOL" ] && \
       command -v riscv64-linux-gnu-objcopy >/dev/null 2>&1; then
        OBJCOPY_TOOL="riscv64-linux-gnu-objcopy"
    elif [ -z "$OBJCOPY_TOOL" ] && \
         command -v objcopy >/dev/null 2>&1; then
        OBJCOPY_TOOL="objcopy"
    fi
    if [ -z "$OBJCOPY_TOOL" ]; then
        log_error "Need riscv64-elf32-minix-objcopy, riscv64-linux-gnu-objcopy, or objcopy"
        exit 1
    fi
    log_info "Using objcopy tool: $OBJCOPY_TOOL"
    if ! command -v parted >/dev/null 2>&1 && \
       ! command -v sfdisk >/dev/null 2>&1; then
        log_error "Need parted or sfdisk to create partition table"
        exit 1
    fi
}

calc_layout() {
    HOME_SIZE_MB=$((SIZE_MB - BOOT_SIZE_MB - ROOT_SIZE_MB - USR_SIZE_MB - 16))
    if [ "$HOME_SIZE_MB" -lt 16 ]; then
        log_error "Disk size too small: $SIZE_MB MB"
        log_error "Need at least 216 MB (recommended >=256 MB)"
        exit 1
    fi
}

resolve_paths() {
    if [ -n "$KERNEL" ]; then
        KERNEL_IMAGE="$KERNEL"
    elif [ -f "$DESTDIR/minix/kernel/kernel" ]; then
        KERNEL_IMAGE="$DESTDIR/minix/kernel/kernel"
    else
        log_error "Kernel not found. Provide -k or ensure $DESTDIR/minix/kernel/kernel exists."
        exit 1
    fi
    [ -f "$KERNEL_IMAGE" ] || {
        log_error "Kernel image not found: $KERNEL_IMAGE"
        exit 1
    }

    if [ -d "$DESTDIR/destdir.evbriscv64" ]; then
        MODROOT="$DESTDIR/destdir.evbriscv64"
    elif [ -d "$DESTDIR/service" ]; then
        MODROOT="$DESTDIR"
    else
        log_error "Boot module root not found under: $DESTDIR"
        log_error "Expected either $DESTDIR/destdir.evbriscv64 or $DESTDIR/service"
        exit 1
    fi
}

find_boot_module() {
    local name="$1"
    shift
    local rel
    for rel in "$@"; do
        if [ -f "$MODROOT/$rel" ]; then
            echo "$MODROOT/$rel"
            return 0
        fi
    done
    log_error "Boot module not found: $name"
    return 1
}

collect_modules() {
    local path
    MODULE_NAMES=(
        ds rs pm sched vfs memory tty mib vm pfs mfs init
    )
    MODULE_PATHS=()

    path=$(find_boot_module ds "service/ds" "minix/servers/ds/ds") || exit 1
    MODULE_PATHS+=("$path")
    path=$(find_boot_module rs "service/rs" "minix/servers/rs/rs") || exit 1
    MODULE_PATHS+=("$path")
    path=$(find_boot_module pm "service/pm" "minix/servers/pm/pm") || exit 1
    MODULE_PATHS+=("$path")
    path=$(find_boot_module sched "service/sched" "minix/servers/sched/sched") || exit 1
    MODULE_PATHS+=("$path")
    path=$(find_boot_module vfs "service/vfs" "minix/servers/vfs/vfs") || exit 1
    MODULE_PATHS+=("$path")
    path=$(find_boot_module memory \
        "service/memory" \
        "minix/drivers/storage/memory/memory" \
        "minix/drivers/system/memory/memory") || exit 1
    MODULE_PATHS+=("$path")
    path=$(find_boot_module tty "service/tty" "minix/drivers/tty/tty/tty") || exit 1
    MODULE_PATHS+=("$path")
    path=$(find_boot_module mib "service/mib" "minix/servers/mib/mib") || exit 1
    MODULE_PATHS+=("$path")
    path=$(find_boot_module vm "service/vm" "minix/servers/vm/vm") || exit 1
    MODULE_PATHS+=("$path")
    path=$(find_boot_module pfs "service/pfs" "minix/fs/pfs/pfs") || exit 1
    MODULE_PATHS+=("$path")
    path=$(find_boot_module mfs "service/mfs" "minix/fs/mfs/mfs") || exit 1
    MODULE_PATHS+=("$path")
    path=$(find_boot_module init "sbin/init" "sbin/init/init") || exit 1
    MODULE_PATHS+=("$path")
}

compute_module_layout() {
    local i addr size
    MODULE_ADDRS=()
    MODULE_SIZES=()
    addr=$((MODULE_BASE_ADDR))

    for i in "${!MODULE_PATHS[@]}"; do
        size=$(stat -c%s "${MODULE_PATHS[$i]}")
        addr=$(( (addr + MODULE_ALIGN - 1) & ~(MODULE_ALIGN - 1) ))
        if (( addr > 0xffffffff )); then
            log_error "Module address above 4GB: ${MODULE_PATHS[$i]}"
            exit 1
        fi
        MODULE_ADDRS+=("$addr")
        MODULE_SIZES+=("$size")
        addr=$((addr + size))
    done
}

create_modinfo() {
    local out="$1"
    local args=()
    local i
    for i in "${!MODULE_PATHS[@]}"; do
        args+=("${MODULE_ADDRS[$i]}" "${MODULE_SIZES[$i]}")
    done
    python3 - "$out" "$MODINFO_MAGIC" "${#MODULE_PATHS[@]}" \
        "${args[@]}" << 'PY'
import struct
import sys

out = sys.argv[1]
magic = int(sys.argv[2], 0)
count = int(sys.argv[3], 0)
vals = sys.argv[4:]
if len(vals) != count * 2:
    raise SystemExit("invalid module argument count")

mods = []
for i in range(count):
    start = int(vals[i * 2], 0)
    size = int(vals[i * 2 + 1], 0)
    end = start + size
    if end > 0xffffffff:
        raise SystemExit("module end above 4GB")
    mods.append((start, end))

with open(out, "wb") as f:
    f.write(struct.pack("<II", magic, count))
    for start, end in mods:
        f.write(struct.pack("<IIII", start, end, 0, 0))
PY
}

create_disk() {
    log_info "Creating disk image: $OUTPUT ($SIZE_MB MB)"
    dd if=/dev/zero of="$OUTPUT" bs=1M count="$SIZE_MB" status=none
}

create_partitions() {
    log_info "Creating partition table..."
    if command -v parted >/dev/null 2>&1; then
        parted -s "$OUTPUT" mklabel msdos
        parted -s "$OUTPUT" mkpart primary ext2 1MiB 9MiB
        parted -s "$OUTPUT" mkpart primary ext2 9MiB 73MiB
        parted -s "$OUTPUT" mkpart primary ext2 73MiB 201MiB
        parted -s "$OUTPUT" mkpart extended 201MiB 100%
        parted -s "$OUTPUT" mkpart logical ext2 202MiB 100%
        parted -s "$OUTPUT" set 1 boot on
    else
        cat << EOF | sfdisk --no-reread "$OUTPUT" >/dev/null
label: dos
unit: sectors

p1 : start=2048, size=$((BOOT_SIZE_MB * 2048)), type=83, bootable
p2 : start=$((2048 + BOOT_SIZE_MB * 2048)), size=$((ROOT_SIZE_MB * 2048)), type=83
p3 : start=$((2048 + (BOOT_SIZE_MB + ROOT_SIZE_MB) * 2048)), size=$((USR_SIZE_MB * 2048)), type=83
p4 : start=$((2048 + (BOOT_SIZE_MB + ROOT_SIZE_MB + USR_SIZE_MB) * 2048)), size=$((HOME_SIZE_MB * 2048)), type=83
EOF
    fi
}

write_partition_image() {
    local part_img="$1"
    local start_mb="$2"
    dd if="$part_img" of="$OUTPUT" bs=1M seek="$start_mb" conv=notrunc status=none
}

build_kernel_payload() {
    local payload
    payload=$(mktemp)
    TMPFILES+=("$payload")

    # Raw binary boot requires BSS bytes in the payload; force both BSS
    # sections to be emitted as file contents.
    "$OBJCOPY_TOOL" -O binary \
        --set-section-flags .unpaged_bss=alloc,load,contents \
        --set-section-flags .bss=alloc,load,contents \
        "$KERNEL_IMAGE" "$payload"

    if [ ! -s "$payload" ]; then
        log_error "Generated kernel payload is empty"
        exit 1
    fi

    KERNEL_BIN_IMAGE="$payload"
}

create_boot_script() {
    local script_txt="$1"
    local i
    cat >"$script_txt" << EOF
echo "MINIX/RISC-V boot script"
setenv kernel_addr_r ${KERNEL_ENTRY_ADDR}
setenv minix_part 0:2

if virtio scan; then
  echo "virtio scan done"
fi

echo "Loading kernel from virtio \${minix_part}"
load virtio \${minix_part} \${kernel_addr_r} /boot/kernel.bin
load virtio \${minix_part} ${MODINFO_ADDR} /boot/minix.modinfo
EOF

    for i in "${!MODULE_PATHS[@]}"; do
        cat >>"$script_txt" << EOF
load virtio \${minix_part} 0x$(printf '%x' "${MODULE_ADDRS[$i]}") /boot/modules/${MODULE_NAMES[$i]}
EOF
    done

    cat >>"$script_txt" << 'EOF'
echo "Starting MINIX kernel..."
go ${kernel_addr_r}
EOF
}

build_filesystems() {
    local stage_boot stage_root modinfo boot_txt boot_scr
    local boot_img root_img stage_size max_bytes
    local i

    stage_boot=$(mktemp -d)
    stage_root=$(mktemp -d)
    TMPDIRS+=("$stage_boot" "$stage_root")

    mkdir -p "$stage_boot" "$stage_root/boot/modules"

    modinfo=$(mktemp)
    boot_txt=$(mktemp)
    boot_scr=$(mktemp)
    TMPFILES+=("$modinfo" "$boot_txt" "$boot_scr")

    create_modinfo "$modinfo"
    create_boot_script "$boot_txt"

    mkimage -A riscv -T script -C none -n "MINIX RISC-V boot" \
        -d "$boot_txt" "$boot_scr" >/dev/null

    cp "$boot_scr" "$stage_boot/boot.scr.uimg"
    cp "$boot_scr" "$stage_boot/boot.scr"
    cp "$KERNEL_BIN_IMAGE" "$stage_root/boot/kernel.bin"
    cp "$modinfo" "$stage_root/boot/minix.modinfo"

    for i in "${!MODULE_PATHS[@]}"; do
        cp "${MODULE_PATHS[$i]}" "$stage_root/boot/modules/${MODULE_NAMES[$i]}"
    done

    stage_size=$(du -sb "$stage_boot" | awk '{print $1}')
    max_bytes=$((BOOT_SIZE_MB * 1024 * 1024))
    if [ "$stage_size" -ge "$max_bytes" ]; then
        log_error "Boot partition payload too large (${stage_size} bytes >= ${max_bytes} bytes)"
        exit 1
    fi

    stage_size=$(du -sb "$stage_root" | awk '{print $1}')
    max_bytes=$((ROOT_SIZE_MB * 1024 * 1024))
    if [ "$stage_size" -ge "$max_bytes" ]; then
        log_error "Root partition payload too large (${stage_size} bytes >= ${max_bytes} bytes)"
        exit 1
    fi

    boot_img=$(mktemp)
    root_img=$(mktemp)
    TMPFILES+=("$boot_img" "$root_img")

    dd if=/dev/zero of="$boot_img" bs=1M count="$BOOT_SIZE_MB" status=none
    dd if=/dev/zero of="$root_img" bs=1M count="$ROOT_SIZE_MB" status=none

    mke2fs -q -t ext2 -F -d "$stage_boot" "$boot_img"
    mke2fs -q -t ext2 -F -d "$stage_root" "$root_img"

    write_partition_image "$boot_img" "$BOOT_START_MB"
    write_partition_image "$root_img" "$ROOT_START_MB"
}

print_summary() {
    local bytes mib
    bytes=$(stat -c%s "$OUTPUT")
    mib=$((bytes / 1024 / 1024))
    echo ""
    echo "========================================"
    echo "Disk Image Created"
    echo "========================================"
    echo "Output:     $OUTPUT"
    echo "Size:       ${mib} MiB (${bytes} bytes)"
    echo "Kernel:     $KERNEL_IMAGE"
    echo "Modroot:    $MODROOT"
    echo ""
    echo "Boot firmware command (disk-only):"
    echo "  qemu-system-riscv64 -machine virt -m 256M -nographic \\"
    echo "    -bios default \\"
    echo "    -kernel /usr/lib/u-boot/qemu-riscv64_smode/uboot.elf \\"
    echo "    -drive if=none,file=$OUTPUT,format=raw,id=hd0 \\"
    echo "    -device virtio-blk-device,drive=hd0"
    echo "========================================"
}

main() {
    check_tools
    calc_layout
    resolve_paths
    collect_modules
    compute_module_layout
    build_kernel_payload
    create_disk
    create_partitions
    build_filesystems
    print_summary
    log_info "Done!"
}

main "$@"
