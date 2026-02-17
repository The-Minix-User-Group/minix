# MINIX RISC-V 64-bit Port Status / MINIX RISC-V 64 位移植状态

**Date / 日期**: 2026-02-17  
**Version / 版本**: 1.8
**Status / 状态**: Phase 2 stabilization — boots to shell; P0 closed and key P1 hygiene fixes landed
**Progress / 进度**: ~80% (boot/userland path stabilized; runtime-aware gate hardened; core follow-ups remain)

## Summary / 摘要

**中文**
- 构建可通过（GCC + workaround 组合），详见 `README-RISCV64.md`。
- QEMU 可稳定进入 shell，并已通过交互冒烟：`echo SMOKE_OK`、`ps -aux`、`cat /proc/meminfo`。
- P0 复验：基于 GCC 重建内核的 QEMU 冒烟中，`ps -aux`、`cat /proc/meminfo`、
  `minix-service sysctl srv_status` 均返回 `RC=0`，未见 `SIGSEGV`/kernel panic。
- 已验证 `obj.intrgcc` 独立链路可完成 `tools -> distribution -> QEMU`，并消除此前
  `Boot module not found: ds` 的启动报错。
- 本轮已确认并修复 RV64 用户态 `memset` 递归导致的栈顶 SIGSEGV（见 `issue.md` A3 进展）。
- 含盘 smoke 复测通过：`virtio_blk_mmio` 报告 capacity/initialized，未再出现
  `device not found` / `Request 0x700 to RS failed` / `couldn't start virtio_blk_mmio`。
- 已完成 source-driven 复现门禁全链路：`repro_build_gate.sh` 在同一 `obj.intrgcc`
  跑通 `tools -> distribution -> smoke`（无需手工补丁/手工拷贝产物）。
- 多轮自动门禁通过：`minix/tests/riscv64/multi_smoke_gate.sh --rounds 2 --timeout 90`
  在无盘+带盘共 4 轮全部通过，`safecopy` 首错被自动定性为 `acceptable_noise`。
- #26 已修复：RS `do_up`/`do_update` 在 `init_slot()` 后失败路径补齐 slot 清理，
  并修正 regular-update `create_service` 失败时的 `r_new_rp/r_old_rp` 链接回滚。
- 门禁脚本已加固为“每轮独立可复现”：`multi_smoke_gate.sh` 默认按轮创建
  `...roundN.img`，仅在显式 `--reuse-disk` 时复用单镜像。
- 门禁进一步收敛为“启动 + 运行时”双阶段：
  `multi_smoke_gate.sh` 默认执行 `qemu_runtime_probe.py`，每轮要求
  `cat /proc/meminfo`、`ps -aux`、`minix-service sysctl srv_status` 成功；
  带盘轮次额外校验 `/dev/c0d0` 存在。
- `repro_build_gate.sh` 的 relax 行为探针改为
  `ld -r --whole-archive ... --no-whole-archive`，避免空对象误通过。
- #24 已缓解：in-tree binutils 增加 `R_RISCV_RELAX` 兼容补丁，`ld` 不再因 `0x33` 中断链接。
- 仍有待闭环风险：`procfs` safecopy 回退噪声（#17）、GCC-only 增量构建 ABI 参数兼容性（#25）。

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
- With-disk smoke now passes: `virtio_blk_mmio` reports capacity/initialized and no longer logs
  `device not found`, `Request 0x700 to RS failed`, or `couldn't start virtio_blk_mmio`.
- A source-driven reproducibility gate now passes end-to-end:
  `repro_build_gate.sh` completes `tools -> distribution -> smoke`
  on the same `obj.intrgcc` without manual patching/artifact injection.
- Multi-run automated gate now passes: `minix/tests/riscv64/multi_smoke_gate.sh --rounds 2 --timeout 90`
  completes 4/4 passes across diskless + with-disk runs, and safecopy first-error
  triage reports `acceptable_noise`.
- #26 is fixed: RS `do_up`/`do_update` now clean up allocated slots on post-`init_slot()`
  failures, and regular-update linkage is rolled back on `create_service` failure.
- Gate behavior is now per-round reproducible by default:
  `multi_smoke_gate.sh` creates `...roundN.img` images unless `--reuse-disk` is set.
- Gate now enforces a two-stage signal by default (boot + runtime probe):
  `multi_smoke_gate.sh` runs `qemu_runtime_probe.py` each round and requires
  successful `meminfo/ps/srv_status` commands, plus `/dev/c0d0` existence in with-disk rounds.
- `repro_build_gate.sh` relax probe now uses
  `ld -r --whole-archive ... --no-whole-archive` to exercise real archive-member paths.
- #24 is now mitigated: in-tree binutils has a compatibility patch for `R_RISCV_RELAX`,
  and `ld` no longer aborts on relocation `0x33`.
- Remaining open risks: procfs safecopy retry noise (#17) and GCC-only incremental
  ABI-flag compatibility (#25).

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
- 含盘 smoke（`/tmp/qemu-smoke-disk.log`）已验证 `virtio_blk_mmio` 初始化成功；
  `-i` 轮廓下未复现 `device not found` / `Request 0x700 ... not alive` 告警。
- 多轮日志门禁输出位于 `/tmp/minix-smoke-gate-20260216-221610/` 与
  `/tmp/minix-smoke-gate-20260216-224157/`，含每轮 `.log` 与 `.triage.txt`，
  可用于回归比较与首错审计。
- 每轮独立镜像复验通过：`multi_smoke_gate.sh --rounds 2 --timeout 60`
  在 `/tmp/minix-smoke-gate-indep-20260216-234830/` 生成
  `...round1.img` 与 `...round2.img`，并完成 4/4 通过。
- `repro_build_gate.sh --objdir obj.intrgcc --smoke-rounds 1 --smoke-timeout 60 --without-disk`
  全链路通过，产出日志 `/tmp/minix-smoke-gate-20260216-223948/`（diskless 1/1 通过）。
- `repro_build_gate.sh --objdir obj.intrgcc --skip-tools --skip-distribution
  --smoke-rounds 1 --smoke-timeout 45 --without-disk` 复验通过，
  日志位于 `/tmp/minix-smoke-gate-20260217-000150/`。
- 严格门禁复测：
  `multi_smoke_gate.sh --rounds 1 --timeout 70 --runtime-timeout 70 --runtime-cmd-timeout 35`
  在 `/tmp/minix-smoke-gate-20260217-070246/` 完成
  `Passed: 2, Failed: 0, Runtime passed: 2, Runtime failed: 0`。

**English**
- Boot path is stable to the `#` shell prompt; init and core services complete basic startup handshake.
- Interactive retest passes: `ps -aux` returns process list; `cat /proc/meminfo` returns data.
- `./minix/scripts/qemu-riscv64.sh -k obj.intrgcc/minix/kernel/kernel -B obj.intrgcc/destdir.evbriscv64`
  now boots directly to shell, validating the `obj.intrgcc` runtime profile.
- `/proc/meminfo` still shows one recoverable safecopy fallback (fail-then-retry-success),
  tracked as known noise in #17.
- The latest `qemu-p0-smoke` run (`/tmp/qemu-p0-smoke.log`) shows the same recoverable
  procfs/safecopy fallback noise while command return codes remain successful (`RC=0`).
- The with-disk smoke run (`/tmp/qemu-smoke-disk.log`) confirms `virtio_blk_mmio`
  initialization and does not reproduce the previous startup warning signature.
- Multi-run gate artifacts are under `/tmp/minix-smoke-gate-20260216-221610/` and
  `/tmp/minix-smoke-gate-20260216-224157/` with per-round `.log` and `.triage.txt`
  outputs for regression auditing.
- Per-round disk-image reproducibility revalidation passes with
  `multi_smoke_gate.sh --rounds 2 --timeout 60`; logs under
  `/tmp/minix-smoke-gate-indep-20260216-234830/` show distinct
  `...round1.img` / `...round2.img` images and 4/4 pass.
- `repro_build_gate.sh --objdir obj.intrgcc --smoke-rounds 1 --smoke-timeout 60 --without-disk`
  also passed end-to-end, with artifacts under `/tmp/minix-smoke-gate-20260216-223948/`.
- `repro_build_gate.sh --objdir obj.intrgcc --skip-tools --skip-distribution
  --smoke-rounds 1 --smoke-timeout 45 --without-disk` also passed with artifacts
  under `/tmp/minix-smoke-gate-20260217-000150/`.
- Strict gate revalidation:
  `multi_smoke_gate.sh --rounds 1 --timeout 70 --runtime-timeout 70 --runtime-cmd-timeout 35`
  passed under `/tmp/minix-smoke-gate-20260217-070246/` with
  `Passed: 2, Failed: 0, Runtime passed: 2, Runtime failed: 0`.

## Key Issues (Snapshot) / 关键问题（摘要）

**Critical / 严重**
- None newly confirmed in current workspace.

**Major / 重要**
- #16: VFS service endpoint pre-resync path still needs stricter generation-safe validation.
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
1) 修复 #16：收敛 VFS 服务端点“先写后验”路径，补齐代际安全校验。
2) 继续收敛 #17（统计/限流 + 负载下验证），区分噪声与真实功能缺陷。
3) 在 clean 环境做一次从 `fetch.sh` 到 `tools/binutils` 的复验，确认 #24 补丁可重复生效。
4) 修复 #25：统一 GCC 路径的 `-mabi` 参数能力探测与回退策略。
5) 在稳定后恢复动态装载链路（`MKPIC/MKPICLIB`）并验证最小动态程序。
6) 将 `repro_build_gate.sh` 纳入例行流水（至少每日一次），验证构建链路不依赖手工注入。

**English**
1) Fix #16 by tightening VFS endpoint-generation validation on service remap paths.
2) Continue closing #17 with counters/rate-limit + stress validation.
3) Re-run from clean `fetch.sh` to `tools/binutils` and confirm #24 patch reproducibility.
4) Fix #25 by normalizing GCC `-mabi` probing/fallback in incremental paths.
5) Restore dynamic loader path (`MKPIC/MKPICLIB`) and test a minimal dynamic binary.
6) Run `repro_build_gate.sh` in routine CI (at least daily) to enforce source-driven reproducibility.

## Success Criteria / 下一里程碑判定

**中文**
- 无盘与含盘两种 QEMU 轮廓在连续回归中稳定进入 shell，且含盘场景保持 `virtio_blk_mmio` 初始化成功。
- `ps -aux`、`cat /proc/meminfo` 在连续回归中稳定通过。
- 增量重建可在不替换链接器的前提下完成（不再出现 `R_RISCV_RELAX` 链接错误）。
- `procfs` 路径 safecopy 错误噪声降到可接受水平并有计数证据。

**English**
- Diskless and with-disk QEMU profiles keep reaching shell across regressions, with
  `virtio_blk_mmio` initialization preserved in with-disk runs.
- `ps -aux` and `cat /proc/meminfo` pass consistently across regressions.
- Incremental rebuild works without ad-hoc linker substitution (`R_RISCV_RELAX` link failures gone),
  and GCC-only path no longer fails on unsupported ABI flags.
- procfs safecopy noise is reduced to an acceptable level with measurable counters.
