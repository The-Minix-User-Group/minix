# MINIX 3 RISC-V 64 Port (Workspace) / MINIX 3 RISC-V 64 移植（工作区）

This repository contains the full MINIX 3 source tree plus an active RISC-V 64-bit
(evbriscv64) port targeting the QEMU virt platform.
本仓库包含完整的 MINIX 3 源码树，以及面向 QEMU virt 平台的 RISC-V 64 位移植版本。

**Documentation Version / 文档版本**: 1.4 (2026-02-20)

## Current Status / 当前状态（as of 2026-02-20 / 截至 2026-02-20）

- Build: passes on the `obj.intrgcc` profile; exact baseline commands are in `README-RISCV64.md`.
  构建：`obj.intrgcc` 轮廓可通过，完整基线命令见 `README-RISCV64.md`。
- Runtime: QEMU reaches stable shell on `evbriscv64`; see `RISC64-STATUS.md`.
  运行：`evbriscv64` 在 QEMU 下可稳定进入 shell，详见 `RISC64-STATUS.md`。
- Version: system major version is `Minix Cat 4.0.0`.
  版本：系统大版本已为 `Minix Cat 4.0.0`。
- Native toolchain: stage N1/N2 is closed on fresh images; guest-side
  `as/ld/ar/ranlib` and `cc -c` pass under automated gate.
  本地工具链：在 fresh 镜像上 N1/N2 已闭环；来宾侧 `as/ld/ar/ranlib` 与 `cc -c`
  已通过自动门禁。
- CI policy: native toolchain runtime gate is blocking in both release/nightly
  workflows.
  CI 策略：release/nightly 两条流水线的 native toolchain 运行时门禁均为阻断式。
- Memory probe fix: RV64 FDT boot-pointer bridge is in place; boot log shows
  `Memory: 0x80000000 - 0x90000000` and `neofetch` reports full-range `Mem(raw)`.
  内存识别修复：RV64 FDT 启动指针桥接已合入；启动日志恢复
  `Memory: 0x80000000 - 0x90000000`，`neofetch` 的 `Mem(raw)` 也恢复到完整区间。
- Latest regression: `./minix/tests/riscv64/run_tests.sh all` result
  `Passed: 21, Failed: 0, Skipped: 1` (SMP still marked not implemented).
  最新回归：`./minix/tests/riscv64/run_tests.sh all` 结果为
  `Passed: 21, Failed: 0, Skipped: 1`（SMP 仍标注为未实现）。
- Risk tracking: code-review issues with file/line evidence are in `issue.md`.
  风险跟踪：带文件/行号证据的评审问题见 `issue.md`。

## Quick Links / 快速链接

- `README-RISCV64.md` — build/run/test manual / 构建、运行、测试说明
- `RISC64-STATUS.md` — status snapshot and risk list / 状态快照与风险清单
- `issue.md` — code-review issues with evidence / 评审问题与证据
- `docs/RISCV64_PORTING_GUIDE.md` — porting workflow and reading coverage / 移植流程与阅读覆盖
- `docs/RISCV64_KERNEL_BUILD_LOG.md` — build log and commands / 构建日志与命令记录
- `docs/RISCV64_PORT_PLAN.md` — plan and checklist / 计划与检查清单
- `docs/RISCV64_NATIVE_TOOLCHAIN_GUIDE.md` — native toolchain stage model and validation / 本地工具链阶段模型与验收
- `.github/workflows/release-riscv64.yml` — release pipeline / 发布流水线
- `.github/workflows/nightly-riscv64.yml` — nightly pipeline / 夜间流水线

## Repository Layout / 目录结构

- `minix/`        MINIX kernel, servers, drivers, libraries, tests / 内核、服务器、驱动、库、测试
- `sys/`          NetBSD compatibility layer / NetBSD 兼容层
- `include/`      Userland headers / 用户态头文件
- `tools/`        Build toolchain / 构建工具链
- `docs/`         Porting documentation / 移植文档
- `scripts/`      Build and QEMU helpers / 构建与 QEMU 脚本

## Build (RISC-V 64) / 构建（RISC-V 64）

Recommended baseline (GCC, no LLVM/C++). See `README-RISCV64.md` for details.
推荐基线（GCC、禁用 LLVM/C++），详细说明见 `README-RISCV64.md`。

```bash
MKPCI=no HOST_CFLAGS="-O -fcommon" HAVE_GOLD=no HAVE_LLVM=no MKLLVM=no \
./build.sh -j$(nproc) -m evbriscv64 \
  -V AVAILABLE_COMPILER=gcc -V ACTIVE_CC=gcc -V ACTIVE_CPP=gcc -V ACTIVE_CXX=gcc -V ACTIVE_OBJC=gcc \
  -V RISCV_ARCH_FLAGS='-march=RV64IMAFD -mcmodel=medany' \
  -V NOGCCERROR=yes \
  -V MKPIC=no -V MKPICLIB=no -V MKPICINSTALL=no \
  -V MKCXX=no -V MKLIBSTDCXX=no -V MKATF=no \
  -V USE_PCI=no \
  -V CHECKFLIST_FLAGS='-m -e' \
  distribution
```

## Run in QEMU / QEMU 运行

```bash
./minix/scripts/qemu-riscv64.sh -k obj.intrgcc/minix/kernel/kernel -B obj.intrgcc/destdir.evbriscv64
```

## Tests / 测试

```bash
./minix/tests/riscv64/run_tests.sh all
```

Native toolchain gate / 本地工具链门禁:

```bash
./minix/tests/riscv64/native_toolchain_gate.sh \
  --kernel obj.intrgcc/minix/kernel/kernel \
  --destdir obj.intrgcc/destdir.evbriscv64 \
  --disk-image /path/to/minix-native-toolchain.img
```

## CI Artifacts / CI 产物

Release/Nightly both publish these five files:
Release/Nightly 均发布以下五件产物：

- `minix-cat-<tag>-<shortsha>.img`
- `minix-cat-<tag>-<shortsha>.img.gz`
- `minix-cat-<tag>-<shortsha>.elf`
- `minix-cat-<tag>-<shortsha>-sysroot.tar.gz`
- `SHA256SUMS.txt`

For detailed trigger rules and tag formats, see `README-RISCV64.md`.
详细触发规则与 tag 规范见 `README-RISCV64.md`。

## Documentation Update Rules / 文档更新规则

- New issues: record in `issue.md` with symptoms, logs, file/line evidence, and impact.
  新问题：在 `issue.md` 记录症状、日志、文件/行号证据与影响。
- Status changes: update `RISC64-STATUS.md` with date and outcome.
  状态变更：更新 `RISC64-STATUS.md`，包含日期与结果。
- Build/test changes: append to `docs/RISCV64_KERNEL_BUILD_LOG.md` and adjust
  `README-RISCV64.md` if the baseline command changes.
  构建/测试变更：追加到 `docs/RISCV64_KERNEL_BUILD_LOG.md`，若基线命令变化则同步更新
  `README-RISCV64.md`。
- Doc-only refresh: append a note to `docs/RISCV64_KERNEL_BUILD_LOG.md` and bump
  doc dates where applicable.
  仅文档更新：在 `docs/RISCV64_KERNEL_BUILD_LOG.md` 记录说明并同步更新文档日期。
- Reading notes: add findings to `docs/RISCV64_PORTING_GUIDE.md`.
  阅读记录：补充到 `docs/RISCV64_PORTING_GUIDE.md`。
