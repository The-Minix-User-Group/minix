# MINIX RISC-V 64-bit Port Status / MINIX RISC-V 64 位移植状态

**Date / 日期**: 2026-02-16  
**Version / 版本**: 1.5  
**Status / 状态**: Phase 2 stabilization — boots to shell; core smoke mostly passes  
**Progress / 进度**: ~72% (boot/userland path stabilized; with-disk/driver/toolchain gaps remain)

## Summary / 摘要

**中文**
- 构建可通过（GCC + workaround 组合），详见 `README-RISCV64.md`。
- QEMU 可稳定进入 shell，并已通过交互冒烟：`echo SMOKE_OK`、`ps -aux`、`cat /proc/meminfo`。
- P0 复验：基于 GCC 重建内核的 QEMU 冒烟中，`ps -aux`、`cat /proc/meminfo`、
  `minix-service sysctl srv_status` 均返回 `RC=0`，未见 `SIGSEGV`/kernel panic。
- 已验证 `obj.intrgcc` 独立链路可完成 `tools -> distribution -> QEMU`，并消除此前
  `Boot module not found: ds` 的启动报错。
- 本轮已确认并修复 RV64 用户态 `memset` 递归导致的栈顶 SIGSEGV（见 `issue.md` A3 进展）。
- #24 已缓解：in-tree binutils 增加 `R_RISCV_RELAX` 兼容补丁，`ld` 不再因 `0x33` 中断链接。
- 仍有待闭环风险：含盘 virtio 启动链路复核、`procfs` safecopy 回退噪声（#17）、
  GCC-only 增量构建 ABI 参数兼容性（#25）。

**English**
- Build passes with GCC + workaround flags; see `README-RISCV64.md` for exact commands.
- QEMU now reaches a stable shell and passes interactive smoke commands:
  `echo SMOKE_OK`, `ps -aux`, and `cat /proc/meminfo`.
- P0 revalidation: with a GCC-rebuilt kernel, QEMU smoke confirms
  `ps -aux`, `cat /proc/meminfo`, and `minix-service sysctl srv_status`
  all return `RC=0` without `SIGSEGV` or kernel panic signatures.
- The isolated `obj.intrgcc` path now completes `tools -> distribution -> QEMU`, and
  the previous `Boot module not found: ds` startup failure is no longer reproduced.
- This cycle confirms and mitigates the RV64 userland `memset` recursion SIGSEGV signature
  (see `issue.md` A3 update).
- #24 is now mitigated: in-tree binutils has a compatibility patch for `R_RISCV_RELAX`,
  and `ld` no longer aborts on relocation `0x33`.
- Remaining open risks: with-disk virtio startup recheck, procfs safecopy retry noise (#17),
  and GCC-only incremental ABI-flag compatibility (#25).

## Build Status / 构建状态

**中文**
- 基线命令：使用 GCC、禁用 LLVM/C++、放宽 `checkflist`（见 `README-RISCV64.md`）。
- 产物：`minix/kernel/obj/kernel` 与 `obj/destdir.evbriscv64`。
- 已补充 `obj.intrgcc` 自举输出：`obj.intrgcc/minix/kernel/kernel` 与
  `obj.intrgcc/destdir.evbriscv64` 可直接用于 QEMU。
- 限制：`CHECKFLIST_FLAGS='-m -e'` 为临时绕过，需在 sets 完整后移除。
- 工具链进展：in-tree `ld`（NetBSD binutils 2.23.2）已通过补丁兼容
  `R_RISCV_RELAX`（见 `issue.md` #24）。
- 新发现：显式 GCC-only 组件增量构建可能触发 `-mabi=lp64d` 参数不兼容（见 `issue.md` #25）。

**English**
- Baseline: GCC, LLVM/C++ disabled, relaxed `checkflist` (see `README-RISCV64.md`).
- Outputs: `minix/kernel/obj/kernel` and `obj/destdir.evbriscv64`.
- Added validated self-bootstrap outputs: `obj.intrgcc/minix/kernel/kernel` and
  `obj.intrgcc/destdir.evbriscv64` are bootable in QEMU.
- Limitation: `CHECKFLIST_FLAGS='-m -e'` is a temporary workaround until sets are complete.
- Toolchain update: in-tree `ld` (NetBSD binutils 2.23.2) now accepts `R_RISCV_RELAX`
  via a compatibility patch; see `issue.md` #24.
- New finding: explicit GCC-only component rebuilds can hit `-mabi=lp64d` incompatibility
  (see `issue.md` #25).

## Runtime Status / 运行状态

**中文**
- 启动链路已稳定可进入 `#` 提示符，`init` 与核心服务可完成基本握手。
- 交互复测通过：`ps -aux` 返回进程列表；`cat /proc/meminfo` 可返回内存信息。
- 使用 `./minix/scripts/qemu-riscv64.sh -k obj.intrgcc/minix/kernel/kernel -B obj.intrgcc/destdir.evbriscv64`
  可直接进入 shell，验证 `obj.intrgcc` 轮廓启动可用。
- `/proc/meminfo` 路径仍可见一次可恢复 safecopy 回退（先失败后重试成功），属于已知噪声问题（#17）。
- 新一轮 `qemu-p0-smoke`（`/tmp/qemu-p0-smoke.log`）同样显示 procfs/safecopy 可恢复回退噪声，
  但命令返回保持成功（`RC=0`）。
- 含盘 virtio 启动链路仍需单独复测后才能确认 A3 全量闭环。

**English**
- Boot path is stable to the `#` shell prompt; init and core services complete basic startup handshake.
- Interactive retest passes: `ps -aux` returns process list; `cat /proc/meminfo` returns data.
- `./minix/scripts/qemu-riscv64.sh -k obj.intrgcc/minix/kernel/kernel -B obj.intrgcc/destdir.evbriscv64`
  now boots directly to shell, validating the `obj.intrgcc` runtime profile.
- `/proc/meminfo` still shows one recoverable safecopy fallback (fail-then-retry-success),
  tracked as known noise in #17.
- The latest `qemu-p0-smoke` run (`/tmp/qemu-p0-smoke.log`) shows the same recoverable
  procfs/safecopy fallback noise while command return codes remain successful (`RC=0`).
- With-disk virtio startup path still needs dedicated revalidation to close A3 end-to-end.

## Key Issues (Snapshot) / 关键问题（摘要）

**Critical / 严重**
- None newly confirmed in current workspace.

**Major / 重要**
- A3: with-disk virtio startup path still needs revalidation after `memset` fix.
- #17: recoverable safecopy fallback noise on `/proc/*` path remains.
- #25: GCC-only incremental build path may fail on unsupported `-mabi=lp64d`.
- #23: RV64 `vm_memset` recovery plumbing is implemented and smoke-validated; targeted
  fault-injection validation is still required for full closure.

详见 `issue.md` 的证据与修复建议 / See `issue.md` for evidence and fixes.

## Evidence Sources / 证据来源

- `issue.md` (code review evidence with file/line references)
- `docs/RISCV64_KERNEL_BUILD_LOG.md` (build history and commands)
- `README-RISCV64.md` (boot/test notes and baseline procedures)

## Next Priorities / 下一阶段优先级

**中文**
1) 跑含盘 QEMU 轮廓，验证 `minix-service` + `virtio_blk_mmio` 路径是否已闭环。
2) 在 clean 环境做一次从 `fetch.sh` 到 `tools/binutils` 的复验，确认 #24 补丁可重复生效。
3) 修复 #25：统一 GCC 路径的 `-mabi` 参数能力探测与回退策略。
4) 继续收敛 #17（统计/限流 + 负载下验证），区分噪声与真实功能缺陷。
5) 在稳定后恢复动态装载链路（`MKPIC/MKPICLIB`）并验证最小动态程序。

**English**
1) Run with-disk QEMU profile and revalidate `minix-service` + `virtio_blk_mmio` path.
2) Re-run from clean `fetch.sh` to `tools/binutils` and confirm #24 patch reproducibility.
3) Fix #25 by normalizing GCC `-mabi` probing/fallback in incremental paths.
4) Continue closing #17 with counters/rate-limit + stress validation.
5) Restore dynamic loader path (`MKPIC/MKPICLIB`) and test a minimal dynamic binary.

## Success Criteria / 下一里程碑判定

**中文**
- 无盘与含盘两种 QEMU 轮廓均可稳定进入 shell 且不出现 `minix-service` SIGSEGV。
- `ps -aux`、`cat /proc/meminfo` 在连续回归中稳定通过。
- 增量重建可在不替换链接器的前提下完成（不再出现 `R_RISCV_RELAX` 链接错误）。
- `procfs` 路径 safecopy 错误噪声降到可接受水平并有计数证据。

**English**
- Both diskless and with-disk QEMU profiles reach shell without `minix-service` SIGSEGV.
- `ps -aux` and `cat /proc/meminfo` pass consistently across regressions.
- Incremental rebuild works without ad-hoc linker substitution (`R_RISCV_RELAX` link failures gone),
  and GCC-only path no longer fails on unsupported ABI flags.
- procfs safecopy noise is reduced to an acceptable level with measurable counters.
