# MINIX RISC-V 64-bit Port Status / MINIX RISC-V 64 位移植状态

**Date / 日期**: 2026-02-20  
**Version / 版本**: 1.15
**Status / 状态**: Phase 2 stabilization — boots to shell; P0 closed and key P1 hygiene fixes landed
**Progress / 进度**: ~80% (boot/userland path stabilized; runtime-aware gate hardened; core follow-ups remain)

## Summary / 摘要

**中文**
- 构建可通过（GCC + workaround 组合），详见 `README-RISCV64.md`。
- QEMU 可稳定进入 shell，并已通过交互冒烟：`echo SMOKE_OK`、`ps -aux`、`cat /proc/meminfo`。
- 系统大版本已滚动到 `Minix Cat 4.0.0`（`OS_RELEASE=4.0.0`，
  `MINIX_VERSION=4.0.0-riscv64`）。
- ramdisk 现在内置 `neofetch`（`pfetch` 为兼容包装），默认通过 `/proc/service`
  统计服务信息，避免默认走 `ps` 路径导致的噪声。
- P0 复验：基于 GCC 重建内核的 QEMU 冒烟中，`ps -aux`、`cat /proc/meminfo`、
  `minix-service sysctl srv_status` 均返回 `RC=0`，未见 `SIGSEGV`/kernel panic。
- 已验证 `obj.intrgcc` 独立链路可完成 `tools -> distribution -> QEMU`，并消除此前
  `Boot module not found: ds` 的启动报错。
- 本轮已确认并修复 RV64 用户态 `memset` 递归导致的栈顶 SIGSEGV（见 `issue.md` A3 进展）。
- 含盘 smoke 复测通过：`virtio_blk_mmio` 报告 capacity/initialized，未再出现
  `device not found` / `Request 0x700 to RS failed` / `couldn't start virtio_blk_mmio`。
- `minix/releasetools/riscv64/mkdisk.sh` 已重构为非 root 可产出 U-Boot 自动探测镜像
  （含 `boot.scr.uimg` + `/boot/kernel.bin` + 模块/`modinfo` 载荷）。
- A4 已闭环：U-Boot 纯磁盘路径在正确 S-mode 链路
  （`-bios default -kernel /usr/lib/u-boot/qemu-riscv64_smode/uboot.elf`）下
  可进入 MINIX shell（见 `issue.md` A4 归档）。
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
- 本轮已修复 RV64 FDT 启动指针命名空间错配（`__k_unpaged__boot_fdt` 与 `_boot_fdt`）；
  内存探测恢复到完整 256MB，日志显示 `Memory: 0x80000000 - 0x90000000`，
  `neofetch` 的 `Mem(raw)` 总页数提升到 `61767`。
- 已完成一次完整 `riscv64` 套件回归：`run_tests.sh all` 结果为
  `Passed=21, Failed=0, Skipped=1`，其中 `multi_smoke_gate` 为
  `4/4` 通过，runtime probe `4/4` 通过。
- 本轮网络权限链路修复：`service lwip` IPC 白名单补充 `pm` 后，
  raw socket 鉴权恢复，`ping/ping6` 不再因 `Permission denied` 失败
  （详见 `issue.md` `#34`）。
- 新发现待修：`ping6 fe80::...%vio0` 在用户态出现 `SIGSEGV (bad addr 0x0)`，
  属于 scoped link-local 诊断路径崩溃（见 `issue.md` `#35`）。
- Native toolchain 进入 Stage N1/N2 推进：已新增构建入口
  `minix/tests/riscv64/native_toolchain_build.sh` 与自动验收脚本
  `minix/tests/riscv64/native_toolchain_gate.sh`，用于来宾内验证
  `as/ld/ar/ranlib` 与本地 `hello.c` 编译运行闭环。
- 仍有待闭环风险：`procfs` safecopy 回退噪声（#17）。

**English**
- Build passes with GCC + workaround flags; see `README-RISCV64.md` for exact commands.
- QEMU now reaches a stable shell and passes interactive smoke commands:
  `echo SMOKE_OK`, `ps -aux`, and `cat /proc/meminfo`.
- The system major version is now `Minix Cat 4.0.0`
  (`OS_RELEASE=4.0.0`, `MINIX_VERSION=4.0.0-riscv64`).
- Ramdisk now ships `neofetch` (`pfetch` kept as compatibility wrapper);
  default service summary uses `/proc/service` to avoid noisy default `ps` probing.
- P0 revalidation: with a GCC-rebuilt kernel, QEMU smoke confirms
  `ps -aux`, `cat /proc/meminfo`, and `minix-service sysctl srv_status`
  all return `RC=0` without `SIGSEGV` or kernel panic signatures.
- The isolated `obj.intrgcc` path now completes `tools -> distribution -> QEMU`, and
  the previous `Boot module not found: ds` startup failure is no longer reproduced.
- This cycle confirms and mitigates the RV64 userland `memset` recursion SIGSEGV signature
  (see `issue.md` A3 update).
- With-disk smoke now passes: `virtio_blk_mmio` reports capacity/initialized and no longer logs
  `device not found`, `Request 0x700 to RS failed`, or `couldn't start virtio_blk_mmio`.
- `minix/releasetools/riscv64/mkdisk.sh` has been reworked to create a non-root
  U-Boot autodiscovery image (`boot.scr.uimg` + `/boot/kernel.bin` +
  module/modinfo payloads).
- A4 is now closed: the disk-only U-Boot path reaches MINIX shell when using the
  correct S-mode chain
  (`-bios default -kernel /usr/lib/u-boot/qemu-riscv64_smode/uboot.elf`);
  see archived A4 notes in `issue.md`.
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
- This cycle fixes RV64 FDT boot-pointer namespace mismatch
  (`__k_unpaged__boot_fdt` vs `_boot_fdt`); memory detection returns to the
  full 256MB range (`Memory: 0x80000000 - 0x90000000`), and `neofetch`
  `Mem(raw)` total pages rise to `61767`.
- A full `riscv64` regression has been completed:
  `run_tests.sh all` reports `Passed=21, Failed=0, Skipped=1`,
  with `multi_smoke_gate` `4/4` pass and runtime probe `4/4` pass.
- This cycle fixes raw-socket credential lookup permissioning for networking:
  `service lwip` now allows IPC to `pm`, removing false `ping/ping6`
  `Permission denied` failures (`issue.md` `#34`).
- New open follow-up: `ping6 fe80::...%vio0` can still crash in userspace
  (`SIGSEGV`, `bad addr 0x0`) on the scoped link-local path (`issue.md` `#35`).
- Native toolchain work has entered Stage N1/N2 with both a build helper
  (`minix/tests/riscv64/native_toolchain_build.sh`) and an automated in-guest
  gate (`minix/tests/riscv64/native_toolchain_gate.sh`) to validate
  `as/ld/ar/ranlib` and native `hello.c` compile-and-run closure.
- Remaining open risk: procfs safecopy retry noise (#17).

## Build Status / 构建状态

**中文**
- 基线命令：使用 GCC、禁用 LLVM/C++、放宽 `checkflist`（见 `README-RISCV64.md`）。
- 产物：`minix/kernel/obj/kernel` 与 `obj/destdir.evbriscv64`。
- 已补充 `obj.intrgcc` 自举输出：`obj.intrgcc/minix/kernel/kernel` 与
  `obj.intrgcc/destdir.evbriscv64` 可直接用于 QEMU。
- 限制：`CHECKFLIST_FLAGS='-m -e'` 为临时绕过，需在 sets 完整后移除。
- ramdisk 更新：新增 `/bin/neofetch`（`pfetch` 兼容包装）与 `/etc/build-id` 注入。
- 工具链进展：in-tree `ld`（NetBSD binutils 2.23.2）已通过补丁兼容
  `R_RISCV_RELAX`（见 `issue.md` #24）。
- 更新：#25 已在当前工作树修复；riscv64 默认编译参数已收敛为
  `-march=RV64IMAFD -mcmodel=medany`，避免默认 `-mabi=lp64d` 兼容性分歧。

**English**
- Baseline: GCC, LLVM/C++ disabled, relaxed `checkflist` (see `README-RISCV64.md`).
- Outputs: `minix/kernel/obj/kernel` and `obj/destdir.evbriscv64`.
- Added validated self-bootstrap outputs: `obj.intrgcc/minix/kernel/kernel` and
  `obj.intrgcc/destdir.evbriscv64` are bootable in QEMU.
- Limitation: `CHECKFLIST_FLAGS='-m -e'` is a temporary workaround until sets are complete.
- Ramdisk update: adds `/bin/neofetch` (with `pfetch` compatibility wrapper)
  and injects `/etc/build-id`.
- Toolchain update: in-tree `ld` (NetBSD binutils 2.23.2) now accepts `R_RISCV_RELAX`
  via a compatibility patch; see `issue.md` #24.
- Update: #25 is fixed in the current working tree; riscv64 default compile flags
  now use `-march=RV64IMAFD -mcmodel=medany` to avoid default `-mabi=lp64d`
  compatibility drift.

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
- U-Boot 纯磁盘路径已可自动发现并执行 `/boot.scr.uimg`，并在
  `-bios default -kernel /usr/lib/u-boot/qemu-riscv64_smode/uboot.elf`
  链路下进入 shell（`/tmp/qemu-uboot-diskonly-new-smode.log`）。
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
- 最新全量回归（`/tmp/minix-full-riscv64-tests.log`）通过：
  `Passed: 21, Failed: 0, Skipped: 1`；
  其中门禁日志在 `/tmp/minix-smoke-gate-20260217-165805/`，结果为
  `Passed: 4, Failed: 0, Runtime passed: 4, Runtime failed: 0`。
- FDT 启动指针桥接修复后，启动日志恢复完整内存窗口
  `Memory: 0x80000000 - 0x90000000`，`neofetch` 显示
  `Mem(raw): 4096 61767 52676 48338 1185`
  （见 `/tmp/qemu-memfix.log` 与 `/tmp/qemu-neofetch-memfix.log`）。
- `neofetch` 默认服务探测模式已从 `off` 切换为 `auto`，优先读取 `/proc/service`；
  `NEOFETCH_SERVICE_PROBE=ps` 仍可显式启用旧 `ps` 探测路径。
- 2026-02-20：修复 VM `alloc_pages()` 在 RV64 上的 `NO_MEM` 哨兵宽度/符号扩展问题
  （`minix/servers/vm/alloc.c`），消除 `native_as_stdin` 与 `cc -c` 路径的 VM panic 触发点。
  在 fresh native 镜像
  （`.ci-artifact-test/minix-native-gcc-test-fixed.img`）上，
  `native_toolchain_gate.sh` 全链路通过（含 `native_as_stdin`、`native_hello_build`）。
  同时 release/nightly 流水中的 native gate 已升级为阻断式（blocking）。

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
- U-Boot disk-only boot now auto-discovers and executes `/boot.scr.uimg`, and
  reaches shell when launched via the S-mode chain
  (`-bios default -kernel /usr/lib/u-boot/qemu-riscv64_smode/uboot.elf`);
  see `/tmp/qemu-uboot-diskonly-new-smode.log`.
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
- Latest full regression (`/tmp/minix-full-riscv64-tests.log`) passes with
  `Passed: 21, Failed: 0, Skipped: 1`;
  the embedded gate run under `/tmp/minix-smoke-gate-20260217-165805/` reports
  `Passed: 4, Failed: 0, Runtime passed: 4, Runtime failed: 0`.
- After the FDT boot-pointer bridge fix, boot logs restore the full memory span
  `Memory: 0x80000000 - 0x90000000`, and `neofetch` reports
  `Mem(raw): 4096 61767 52676 48338 1185`
  (see `/tmp/qemu-memfix.log` and `/tmp/qemu-neofetch-memfix.log`).
- `neofetch` default service probe switched from `off` to `auto`, preferring
  `/proc/service`; the old `ps` path remains available via
  `NEOFETCH_SERVICE_PROBE=ps`.
- 2026-02-20: fixed RV64 `NO_MEM` sentinel width/sign-extension mismatch in
  VM `alloc_pages()` (`minix/servers/vm/alloc.c`), removing the VM panic
  reproducer on `native_as_stdin` and `cc -c`.
  Strict revalidation passes on a fresh native image
  (`.ci-artifact-test/minix-native-gcc-test-fixed.img`) with full
  `native_toolchain_gate.sh` coverage.
  Native toolchain gate in release/nightly workflows is now blocking.

## Key Issues (Snapshot) / 关键问题（摘要）

**Critical / 严重**
- None newly confirmed in current workspace.

**Major / 重要**
- #16: VFS service endpoint pre-resync path still needs stricter generation-safe validation.
- #17: recoverable safecopy fallback noise on `/proc/*` path remains.
- #35: `ping6 fe80::...%vio0` crashes in userspace (`SIGSEGV`) on scoped link-local path.
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
3) 将 native toolchain 阻断门禁持续运行在 release/nightly，并补充可写介质场景下
   的可选 `link+run` 验收（规避 root mfs inode 上限带来的假阴性）。
4) 在 clean 环境做一次从 `fetch.sh` 到 `tools/binutils` 的复验，确认 #24 补丁可重复生效。
5) 在稳定后恢复动态装载链路（`MKPIC/MKPICLIB`）并验证最小动态程序。
6) 将 `repro_build_gate.sh` 纳入例行流水（至少每日一次），验证构建链路不依赖手工注入。

**English**
1) Fix #16 by tightening VFS endpoint-generation validation on service remap paths.
2) Continue closing #17 with counters/rate-limit + stress validation.
3) Keep native toolchain gate blocking in release/nightly and add optional
   writable-filesystem `link+run` acceptance to avoid false negatives from
   root mfs inode limits.
4) Re-run from clean `fetch.sh` to `tools/binutils` and confirm #24 patch reproducibility.
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
- Incremental rebuild works without ad-hoc linker substitution (`R_RISCV_RELAX` link failures gone).
- procfs safecopy noise is reduced to an acceptable level with measurable counters.
