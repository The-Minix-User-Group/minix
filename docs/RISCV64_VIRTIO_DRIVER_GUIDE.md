# RISC-V VirtIO Driver Guide / RISC-V VirtIO 驱动指南

## Overview / 概述

This document describes the current VirtIO driver implementation used by
MINIX on `evbriscv64` (QEMU `virt`), with focus on practical bring-up,
debugging, and acceptance.

本文档说明 MINIX 在 `evbriscv64`（QEMU `virt`）上的 VirtIO 驱动现状，
重点覆盖可落地的启动、调试和验收流程。

## Document Info / 文档信息

- Version / 版本: `1.0`
- Last updated / 最后更新: `2026-02-18`
- Baseline / 基线: `obj.intrgcc`
- Scope / 范围: VirtIO MMIO transport (`virtio_blk_mmio`, `virtio_net_mmio`)

## 1) Scope and Non-Goals / 范围与非目标

In scope / 在范围内:
- VirtIO MMIO transport on QEMU `virt`.
- Block device driver: `virtio_blk_mmio`.
- Network device driver: `virtio_net_mmio`.
- Network stack integration with `lwip` (IPv4 + IPv6 path used in current tests).

Out of scope / 不在范围内:
- VirtIO PCI transport.
- Non-QEMU hardware platform differences.
- VirtIO GPU/Input deep dive (only launch flags may be mentioned).

## 2) Driver Stack Map / 驱动栈映射

Core files / 核心文件:

- MMIO transport header:
  `minix/include/minix/virtio_mmio.h`
- MMIO transport implementation:
  `minix/lib/libvirtio_mmio/virtio_mmio.c`
- Block driver:
  `minix/drivers/storage/virtio_blk_mmio/virtio_blk_mmio.c`
- Net driver:
  `minix/drivers/net/virtio_net_mmio/virtio_net_mmio.c`
- Legacy/common net logic reference:
  `minix/drivers/net/virtio_net/virtio_net.c`
- Service policy (riscv64):
  `minix/releasetools/riscv64/system.conf`
- Boot startup logic (ramdisk profile):
  `minix/drivers/storage/ramdisk/rc`

Library dependencies / 依赖库:
- `virtio_blk_mmio` links `-lblockdriver -lvirtio_mmio -lsys -lmthread`.
- `virtio_net_mmio` links `-lnetdriver -lsys -lvirtio_mmio`.

## 3) MMIO and IRQ Layout / MMIO 与 IRQ 布局

Current constants are defined in `minix/include/minix/virtio_mmio.h`:

- MMIO base: `0x10001000`
- MMIO stride: `0x1000`
- device slots: `8`
- IRQ base: `1` (thus VirtIO IRQs `1..8`)

QEMU `virt` mapping usually appears as:
- slot0: `0x10001000` (commonly block device if enabled first)
- slot1: `0x10002000` (commonly net device)

Actual slot usage is runtime-probed by `virtio_mmio_setup(...)`, not hardcoded
by a single driver instance.

## 4) Service Wiring / 服务编排

### 4.1 system.conf Permissions

`minix/releasetools/riscv64/system.conf` includes:

- `service virtio_blk_mmio` with `UMAP/VUMAP/DEVIO/IRQCTL/PRIVCTL`
  and MMIO range `0x10001000:0x10008000`.
- `service virtio_net_mmio` with `UMAP/VUMAP/DEVIO/IRQCTL/PRIVCTL`
  and MMIO range `0x10002000:0x10003000`.
- `service lwip` with domain `INET INET6 ROUTE LINK`.
- `service lwip` IPC includes `pm` (required for root credential lookup in
  raw socket path, relevant to `ping/ping6`).

### 4.2 Boot-Time Startup Behavior

In `minix/drivers/storage/ramdisk/rc`:

- `virtio_blk_mmio` and `virtio_net_mmio` are started in `auto` mode by default.
- `auto` mode suppresses expected no-device noise.
- `yes/no` can be controlled through `sysenv`:
  - `virtio_blk_mmio=yes|no|auto`
  - `virtio_net_mmio=yes|no|auto`
- `lwip` is started after `virtio_net_mmio`.

## 5) Build and Refresh Workflow / 构建与刷新流程

For fast iteration on VirtIO path (baseline `obj.intrgcc`):

```bash
TOOLDIR=$(echo /home/donz/minix/obj.intrgcc/tooldir.*)
NBMAKE="$TOOLDIR/bin/nbmake-evbriscv64"

# net + block drivers
"$NBMAKE" -C minix/drivers/net/virtio_net_mmio all install
"$NBMAKE" -C minix/drivers/storage/virtio_blk_mmio all install

# lwip if network behavior is touched
"$NBMAKE" -C minix/net/lwip all install

# rebuild ramdisk + memory service for bootramdisk profile
"$NBMAKE" -C minix/drivers/storage/ramdisk RAMDISK_TESTS=1 image
"$NBMAKE" -C minix/drivers/storage/memory RAMDISK_TESTS=1 all install
```

If testing disk-only boot image:

```bash
OUTPUT=/tmp/minix-rv64-virtio.img \
DESTDIR=/home/donz/minix/obj.intrgcc \
minix/releasetools/riscv64/mkdisk.sh
```

## 6) Runtime Profiles / 运行时轮廓

### 6.1 Scripted QEMU (recommended)

```bash
./minix/scripts/qemu-riscv64.sh \
  -k obj.intrgcc/minix/kernel/kernel \
  -B obj.intrgcc/destdir.evbriscv64 \
  -i /tmp/minix-rv64-virtio.img \
  -n
```

Notes:
- `-n` uses QEMU user-net and currently sets
  `hostfwd=tcp::2222-:22` in the script.
- if host port `2222` is occupied, either free it or run a custom QEMU command.

### 6.2 Direct QEMU (explicit net config)

```bash
qemu-system-riscv64 -machine virt -m 256M -nographic \
  -bios default \
  -kernel /usr/lib/u-boot/qemu-riscv64_smode/uboot.elf \
  -drive if=none,file=/tmp/minix-rv64-virtio.img,format=raw,id=hd0 \
  -device virtio-blk-device,drive=hd0 \
  -netdev user,id=net0,ipv6=on \
  -device virtio-net-device,netdev=net0,mac=52:54:00:12:34:56
```

## 7) Acceptance Checklist / 验收清单

In-guest quick checks:

```sh
minix-service sysctl srv_status
ifconfig -a
route -n show
```

### 7.1 Block path

Expect / 期望:
- `/dev/c0d0` exists when block device is attached.
- boot log contains:
  - `virtio-blk-mmio: capacity: ... sectors`
  - `virtio-blk-mmio: initialized`

Optional smoke:

```sh
/bin/test_virtio_blk_mmio -p /dev/c0d0 -o 1048576 -s 4096 -b
```

### 7.2 Network path

Expect / 期望:
- interface `vio0` present.
- IPv4 gateway ping works in user-net profile.
- IPv6 loopback and link-local checks are stable.

Smoke commands:

```sh
ping -c 2 10.0.2.2
ping -c 2 1.1.1.1
ping6 -c 5 ::1
```

For dual-VM link-local validation:

```sh
ping6 -q -c 1 fe80::...%vio0
```

## 8) Common Failure Signatures / 常见故障签名

1. `virtio-blk-mmio: device not found`
- Cause: no block device attached (for example no `-i`/no virtio-blk QEMU device).
- Action: attach disk with `-drive ... -device virtio-blk-device,...`.

2. `WARNING: couldn't start virtio_net_mmio`
- Cause: no virtio-net device attached or startup mode is strict.
- Action: attach `-netdev ... -device virtio-net-device,...` and retry.

3. `ping/ping6: Permission denied` on raw socket path
- Cause: policy drift where `lwip` cannot talk to `pm`.
- Action: verify `lwip` IPC includes `pm` in both:
  - `minix/releasetools/riscv64/system.conf`
  - `minix/net/lwip/lwip.conf`

4. `hostfwd=tcp::2222-:22` already in use
- Cause: host port conflict.
- Action: pick a different hostfwd port or run without hostfwd.

5. `-netdev bridge` fails with bridge-helper errors
- Cause: host bridge prerequisites missing (for example `/etc/qemu/bridge.conf`).
- Action: validate functionality with user-net (slirp) first, then configure
  host bridge environment.

## 9) Implementation Notes for Developers / 开发实现要点

1. Transport bring-up:
- use `virtio_mmio_setup(...)` to probe by VirtIO device ID.
- negotiate features through `exchange_features()` path in
  `minix/lib/libvirtio_mmio/virtio_mmio.c`.

2. Queue ownership:
- descriptor direction is encoded through `vp_addr` LSB in current path
  (read/write marker), so keep buffer-direction handling consistent when adding
  request types.

3. Memory ordering:
- use `virtio_mb()/virtio_rmb()/virtio_wmb()` for descriptor/doorbell ordering
  guarantees on RISC-V.

4. Service policy:
- MMIO drivers need `DEVIO`, `IRQCTL`, `UMAP`, `VUMAP`, and proper MMIO range.
- net path additionally depends on `virtio_net_mmio <-> lwip` IPC chain.

5. Regression gate:
- keep both disk and network profiles in regular smoke runs.
- for network, include both IPv4 (`10.0.2.2`) and IPv6 (`ping6 ::1`) checks.

## 10) Related Docs / 关联文档

- `README-RISCV64.md`
- `RISC64-STATUS.md`
- `docs/RISCV64_KERNEL_BUILD_LOG.md`
- `docs/RISCV64_TEST_MATRIX.md`
- `issue.md`

