# MINIX RISC-V Native Toolchain Guide / MINIX RISC-V 本地工具链指南

## Document Info / 文档信息

**中文**
- 版本：1.1
- 最后更新：2026-02-20
- 适用范围：`evbriscv64` + QEMU `virt`
- 基线：`obj.intrgcc`

**English**
- Version: 1.1
- Last updated: 2026-02-20
- Scope: `evbriscv64` + QEMU `virt`
- Baseline: `obj.intrgcc`

## Executive Summary / 摘要

**中文**
- Native toolchain N1/N2 已闭环：来宾内 `as/ld/ar/ranlib` 与 `cc -c` 路径可稳定通过。
- 关键修复在 `minix/servers/vm/alloc.c`：修正 RV64 下 `NO_MEM` 哨兵宽度/符号扩展问题，消除 `native_as_stdin` / `cc -c` VM panic。
- Release/Nightly 的 native gate 已改为阻断式（blocking）。

**English**
- Native toolchain N1/N2 is closed: guest-side `as/ld/ar/ranlib` and `cc -c` are stable.
- Key fix is in `minix/servers/vm/alloc.c`: RV64 `NO_MEM` sentinel width/sign-extension handling in `alloc_pages()`.
- Native gate is now blocking in both release and nightly CI workflows.

## Stage Model / 阶段模型

### Stage N0 (Done) — Cross Build Baseline / 交叉构建基线（已完成）
- `tools -> distribution -> QEMU` on `obj.intrgcc` is reproducible.

### Stage N1 (Done) — Native Binutils Presence / 来宾 binutils 可用（已完成）
- `command -v as ld ar ranlib` passes in guest.
- `native_as_stdin` runtime probe passes.

### Stage N2 (Done) — Native C Compiler MVP / 来宾 C 编译 MVP（已完成）
- `native_hello_preprocess`, `native_hello_to_asm`, `native_hello_build` pass.
- Native gate returns `PASS` (`rc=0`) on fresh native image.

### Stage N3 (Open) — Practical Self-Host / 实用自举（进行中）
- Focus shifts to sustained workloads (`bmake`, larger packages, long-run stability).

## Root Cause and Fix / 根因与修复

### Symptom / 现象
- Native probe crashed in VM path while running:
  - `printf '.text ...' | as -o /dev/null`
  - `printf ... | cc -pipe -x c - -c -o /dev/null`
- Typical signature:
  - `rv64: VM pagefault ...`
  - `kernel panic: pagefault in VM`

### Root cause / 根因
- `alloc_pages()` used page-index variables as `phys_bytes` (64-bit on RV64),
  while `NO_MEM` is a 32-bit click sentinel (`0xFFFFFFFE`).
- Failed `findbit()` values could be sign-extended and bypass `mem == NO_MEM`
  checks, then flow into bitmap index access with invalid negative page numbers.

### Fix / 修复
- File: `minix/servers/vm/alloc.c`
- Changes:
  - `alloc_pages` return type: `phys_bytes` -> `phys_clicks`
  - page-index locals: `phys_bytes` -> `phys_clicks`
  - `findbit()` return values cast to `phys_clicks` before compare/use

## Build and Image Baseline / 构建与镜像基线

### 1) Build native-oriented distribution / 构建 native 轮廓

```bash
./minix/tests/riscv64/native_toolchain_build.sh
```

Optional full rebuild with tools:

```bash
./minix/tests/riscv64/native_toolchain_build.sh --with-tools
```

### 2) Build a fresh native image / 生成 fresh native 镜像

```bash
mkdir -p .ci-artifact-test/tmphost
TMPDIR=$PWD/.ci-artifact-test/tmphost \
TEMP=$PWD/.ci-artifact-test/tmphost \
TMP=$PWD/.ci-artifact-test/tmphost \
minix/releasetools/riscv64/mkdisk.sh \
  -d obj.intrgcc \
  -o $PWD/.ci-artifact-test/minix-native-toolchain.img \
  -s 1024 -u 768 -U
```

Notes:
- `-U` enables `/usr` payload in the image.
- Prefer a fresh image per validation run to avoid ext2 dirty-state carryover.

### 3) Image plumbing requirements / 镜像侧必要改动

Native gate depends on ext2-backed `/usr` being available at runtime.
Native 门禁依赖运行时可用的 ext2 `/usr` 挂载链路。

Current implementation points:
- `minix/drivers/storage/ramdisk/Makefile`
  - includes `ext2` in RAM-disk program set.
- `minix/drivers/storage/ramdisk/proto`
  - includes `ext2` service in the riscv ramdisk service list.
- `minix/releasetools/riscv64/system.conf`
  - defines `service ext2 { ... }` with required VM permissions.

If these are missing from a branch or image profile, `prepare_usr_mount` in
the gate can fail or skip unexpectedly.
若分支/镜像配置缺失以上任一项，门禁中的 `prepare_usr_mount` 可能失败或异常 `SKIP`。

## Strict Validation Playbook / 严格验收流程

### A. Native gate (required) / Native 门禁（必跑）

```bash
./minix/tests/riscv64/native_toolchain_gate.sh \
  --kernel obj.intrgcc/minix/kernel/kernel \
  --destdir obj.intrgcc/destdir.evbriscv64 \
  --disk-image $PWD/.ci-artifact-test/minix-native-toolchain.img \
  --timeout 240 \
  --cmd-timeout 120
```

Expected:
- Exit code `0`
- Log contains:
  - `native_as_stdin`
  - `native_hello_build`
  - `[native-gate] PASS`

### B. Interactive smoke (recommended) / 交互烟测（建议）

Use workflow-equivalent smoke chain:
- shell prompt
- `neofetch`
- shutdown chain (`shutdown/halt/poweroff/reboot` fallback)

This confirms that image usability did not regress while fixing toolchain path.

### C. Negative-path sanity check (recommended) / 负路径校验（建议）

- Run the gate against a known-dirty/old image.
- Confirm non-pass return code is propagated (`!= 0`).
- This prevents false-green from shell script exit-code mistakes.

## CI Policy / CI 策略

### Release workflow / Release 流水线
- File: `.github/workflows/release-riscv64.yml`
- Native step: `Native toolchain runtime gate`
- Policy: **blocking**
- Behavior:
  - success: writes `rc=0`
  - fail: writes `rc=<nonzero>`, prints log tail, exits nonzero

### Nightly workflow / Nightly 流水线
- File: `.github/workflows/nightly-riscv64.yml`
- Native step: `Native toolchain runtime gate`
- Policy: **blocking**
- Behavior is aligned with release workflow.

## Runtime Caveats / 运行注意事项

1. `native_toolchain_gate.sh` requires `--disk-image`
- Without disk image, gate returns `SKIP` by design.

2. Root mfs inode pressure
- Root mfs may report `Out of i-nodes on device 1/6`.
- Avoid temp-file-heavy probes on root mfs.
- Prefer stdin-pipe probes or writable ext2-backed locations.

3. ext2 dirty-state noise
- After crash/reboot loops, ext2 may report
  `filesystem wasn't cleanly unmounted last time`.
- Rebuild a fresh test image before final pass/fail judgment.

4. `/tmp` assumptions in guest
- Some images may not provide writable `/tmp` semantics as expected.
- For file-based checks, use verified writable paths.

## Troubleshooting Matrix / 故障矩阵

### `SKIP: --disk-image is required`
- Cause: missing `--disk-image`
- Fix: provide native image path explicitly

### `SKIP: native compiler unavailable in runtime image`
- Cause: `/usr` not mounted or compiler commands not present in image
- Fix:
  - rebuild distribution with native profile
  - regenerate image with `-U`
  - rerun with fresh image

### `native_as_stdin` fail + VM panic
- Cause: likely VM allocator regression or stale unfixed runtime image
- Fix:
  - ensure patched `service/vm` is installed into destdir
  - regenerate image
  - rerun strict gate

### `prepare_usr_mount` fail with ext2 dirty-state
- Cause: previous abnormal shutdown / test interruption
- Fix:
  - regenerate fresh image
  - avoid reusing panic-tainted image for acceptance

## Logging and Evidence / 日志与证据

Recommended artifacts per milestone run:
- native gate full log
- interactive smoke log
- command line snapshot (kernel/destdir/disk-image)
- resulting image checksum

Update docs after each meaningful state change:
- `docs/RISCV64_KERNEL_BUILD_LOG.md`
- `RISC64-STATUS.md`
- `issue.md` (for unresolved regressions)

## References / 参考

- `minix/tests/riscv64/native_toolchain_build.sh`
- `minix/tests/riscv64/native_toolchain_gate.sh`
- `minix/tests/riscv64/qemu_runtime_probe.py`
- `minix/releasetools/riscv64/mkdisk.sh`
- `.github/workflows/release-riscv64.yml`
- `.github/workflows/nightly-riscv64.yml`
