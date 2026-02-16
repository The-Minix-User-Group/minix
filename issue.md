# MINIX RISC-V Port Issues / MINIX RISC-V 移植问题清单

**Date / 日期**: 2026-02-16  
**Version / 版本**: 1.19
**Scope / 范围**: RISC-V 64-bit port, evidence includes file/line references.

本文件记录 RISC-V 64 位移植的具体问题与证据（含文件/行号），并给出修复建议。  
This file records concrete issues in the RISC-V 64-bit port with evidence and suggested fixes.

**复核说明**：2026-02-16 完成启动链路稳定化验证；QEMU 可进入交互 shell 并通过 `echo SMOKE_OK`。同日补充代码/日志复核问题，并完成一轮 RS P0 端点映射防护加固（定向编译 + QEMU 启动复测），随后在带盘 smoke 中确认 `virtio_blk_mmio` 可正常初始化。
**Review note**: 2026-02-16 validated boot-path stabilization; QEMU reaches interactive shell and passes `echo SMOKE_OK`. Additional code/log review findings were added the same day, followed by an RS P0 endpoint-mapping hardening pass (targeted build + QEMU boot revalidation), and a with-disk smoke that confirms `virtio_blk_mmio` initialization.

**编号说明 / Numbering note**: 问题编号采用历史保留，不保证连续；已归档到 “Fixed in Current Working Tree” 的历史编号包括 `#1`, `#2`, `#3`, `#10`, `#12`, `#24`。  
Issue IDs are historically stable and intentionally non-contiguous; archived IDs moved to “Fixed in Current Working Tree” include `#1`, `#2`, `#3`, `#10`, `#12`, `#24`.

## Repair Priority / 修复优先级（从重到轻）

- P0 / 最高优先（已闭环，2026-02-16，smoke-validated）:
  1) `[DONE]` `#22` RS `free_slot()` endpoint unset 时越界写 `rproc_ptr[]`
  2) `[DONE]` `#21` RS endpoint 校验接受 task slot，导致 `rproc_ptr[]` 越界访问
  3) `[DONE]` `#20` RS `do_upd_ready()` 异常消息路径空指针解引用
  4) `[DONE]` `#18` RS `do_init_ready()` / `catch_boot_init_ready()` 异常路径空指针解引用
  5) `[DONE]` `#23` RISC-V `vm_memset` 无故障恢复，可能把可恢复故障升级为 kernel panic
- P1 / 高优先（高概率影响功能正确性）:
  1) `#16` VFS 服务端点“先写后验”可能弱化代际校验
  2) `#17` 启动期 safecopy 噪声错误闭环（定位根因并降噪）
  3) `A3` 含盘场景 `minix-service`/`virtio_blk_mmio` SIGSEGV
  4) `#25` 内建 GCC 不支持 `-mabi=lp64d`，阻断部分 GCC-only 增量构建
  5) `#26` RS `do_up`/`do_update` 失败路径未回收 slot 资源，`RSS_COPY` 可触发可重复内存泄漏
- P2 / 中优先（功能完备性与平台能力）:
  1) `A2` RV64 动态装载链路（`MKPIC`/`ld.elf_so`）补齐与验证
  2) `#15` RISC-V SMP 核心实现缺失
  3) `#13` `phys_copy` fault handler 注册缺失
  4) `#14` DT 多段内存/保留区解析补齐
- P3 / 低优先（可维护性与技术债）:
  1) `#19` kernel/VM/RS 无条件调试日志收敛
  2) `#11` `minimal_kernel` RISC-V 适配
  3) `TD1`/`TD2`/`TD3` 技术债
- Validation backlog / 已有代码修复待运行复验:
  - `#4`, `#5`, `#6`, `#7`, `#8`, `#9`（建议在每轮 P0/P1 修复后都做最小 QEMU 回归）

## Active Investigation / 当前主问题跟踪

### A1) Boot-time user pagefault loop (mostly mitigated) / 启动期用户态反复缺页（大部分已缓解）
- Evidence / 证据:
  - VFS: `sef_receive_status` at `minix/lib/libsys/sef.c:150`, `mthread_trampoline` at `minix/lib/libmthread/allocate.c:531`,
    `malloc_bytes` at `lib/libc/stdlib/malloc.c:875`, `memset` at `common/lib/libc/string/memset.c:156`
  - MFS: `extend_pgdir` at `lib/libc/stdlib/malloc.c:534`, `imalloc` at `lib/libc/stdlib/malloc.c:934`,
    `kdoprnt` at `sys/lib/libsa/subr_prf.c:189`
  - DS: `_regcomp` at `lib/libc/regex/regcomp.c:333`, `extend_pgdir` at `lib/libc/stdlib/malloc.c:534`,
    `imalloc` at `lib/libc/stdlib/malloc.c:934`, `kdoprnt` at `sys/lib/libsa/subr_prf.c:189`
- Impact / 影响:
  - Historically blocked stable boot; currently boot can reach interactive shell, but related memory-path regressions must still be watched. / 历史上阻断稳定启动；当前已可进入交互 shell，但相关内存路径仍需持续监控回归。
- Hypothesis / 假设:
  - RV64 heap growth or page table extension path (`extend_pgdir` / `malloc_pages`) maps invalid VA. / RV64 堆扩展或页表扩展路径可能映射了非法 VA。
  - May be related to address-space handoff or missing TLB flush after leaf splits (Major #4). / 可能与地址空间切换或叶子拆分页后的 TLB 刷新缺失（Major #4）相关。
- Next steps / 下一步:
  - Capture faulting `addr` with matching `pc` to confirm heap boundaries. / 采集 fault addr 与 pc 对应关系以确认堆边界。
  - Audit `malloc.c` + VM mappings on RV64; verify `brk`/`sbrk` flow and VM map permissions. / 审核 RV64 的 `malloc.c` 与 VM 映射；核对 `brk`/`sbrk` 路径与权限。
- Update / 进展:
  - 2026-02-16: after startup-handshake fixes (PFS/MFS/RS) and ilp32 user-address-top adjustment,
    no pre-shell SIGSEGV reproduced in QEMU smoke; shell command `echo SMOKE_OK` succeeds.
    / 2026-02-16：修复 PFS/MFS/RS 启动握手并调整 ilp32 用户地址上限后，QEMU 冒烟未再复现 shell 前 SIGSEGV，`echo SMOKE_OK` 成功。
  - Boot now reaches shell after mapping `.usermapped` into the boot page table for `minix_kerninfo_user`. / 启动页表加入 `.usermapped` 后可进入 shell（修复早期 `minix_kerninfo_user` 缺页）。
    Evidence: `minix/kernel/arch/riscv64/protect.c`
  - `virtio_blk_mmio` sys_vumap failures are fixed by using SELF iovec addresses; `/usr` mount succeeds. / `virtio_blk_mmio` 的 sys_vumap 失败已修复（SELF 用地址），`/usr` 可挂载。
    Evidence: `minix/drivers/storage/virtio_blk_mmio/virtio_blk_mmio.c`, `minix/drivers/storage/virtio_blk/virtio_blk.c`
  - VM slaballoc assert on `ls /usr` is addressed by expanding slab size classes for RV64 message sizes. / `ls /usr` 触发的 slaballoc 断言已通过扩展 RV64 slab 大小类修复。
    Evidence: `minix/servers/vm/slaballoc.c`
- Remaining / 保留问题:
  - `loadramdisk` had failures when `ramimagename` was unset; a kernel default has been added, but this path still needs rebuild/runtime re-validation before it can be considered closed. / `ramimagename` 未设置时的 `loadramdisk` 失败已有内核默认值补丁，但在重建与运行复验完成前仍不视为闭环。
    Evidence: `minix/kernel/arch/riscv64/kernel.c`
  - `REQ_GETDENTS` may hit `sys_safecopyto` EFAULT with `CPF_TRY` grants; VFS retries and succeeds, but logs are noisy. / `REQ_GETDENTS` 在 `CPF_TRY` 下可能触发 `sys_safecopyto` EFAULT；VFS 会重试成功，但日志较噪。
    Evidence: `minix/kernel/system/do_safecopy.c`, `minix/servers/vfs/request.c`

### A2) RV64 process support exists in loader/CPU mode but is not stable end-to-end / RV64 进程支持具备基础但端到端不稳定
- Evidence / 证据:
  - U-mode is configured by clearing `SSTATUS_SPP` in `prot_init`. / 内核已配置 U-mode 入口。  
    Evidence: `minix/kernel/arch/riscv64/protect.c:48`
  - VM boot loader expects ELF64/EM_RISCV for the VM image. / VM 引导加载器按 ELF64/EM_RISCV 校验。  
    Evidence: `minix/kernel/arch/riscv64/protect.c:138`
  - Exec loader is built as 64-bit on `__riscv64__`, and ELF target class is 64 for RISC-V. / exec 加载器按 RV64 构建并期望 ELF64。  
    Evidence: `minix/lib/libexec/exec_elf.c:4`, `sys/arch/riscv/include/elf_machdep.h:24`
  - Current status explicitly says userland is not yet stable. / 现状明确用户态仍不稳定。  
    Evidence: `README-RISCV64.md:27`
  - `ld.elf_so` only builds when `MKPIC != "no"`, but current riscv64 builds report `MKPIC=no`, so no dynamic loader is produced/installed. / `ld.elf_so` 仅在 `MKPIC != "no"` 时构建，而当前 riscv64 构建为 `MKPIC=no`，动态加载器未生成/安装。  
    Evidence: `libexec/ld.elf_so/Makefile:31-47`
- Impact / 影响:
  - Kernel has RV64 U-mode + ELF64 exec plumbing, but user processes are not reliably runnable yet. / 内核具备基础通路，但 RV64 进程尚不可稳定运行。
  - No `ld.elf_so` means dynamic binaries cannot be validated; only static ELF64 execs are currently exercised. / 缺少 `ld.elf_so` 导致动态二进制无法验证，当前仅运行静态 ELF64 可执行文件。
- Suggested fix / 修复建议:
  - Resolve A1 and top Major issues (VM/PT/TLB/IPI), then validate exec with a minimal ELF64 user binary + ld.so. / 先修复 A1 与主要问题（VM/PT/TLB/IPI），再用最小 ELF64 用户程序验证 exec/ld.so。
  - Enable `MKPIC`/`MKPICLIB` for riscv64 and build/install `ld.elf_so`, then test a small dynamic binary with `PT_INTERP=/libexec/ld.elf_so`. / 为 riscv64 开启 `MKPIC`/`MKPICLIB` 并构建安装 `ld.elf_so`，再用带 `PT_INTERP=/libexec/ld.elf_so` 的小动态程序验证。
  - Validation checklist (doc-only): / 验证清单（文档）:
    1) Confirm target ELF64/EM_RISCV via `readelf -h` on the test binary. / 通过 `readelf -h` 确认 ELF64/EM_RISCV。
    2) Prefer a minimal static executable if available; otherwise verify `PT_INTERP` points to `/libexec/ld.elf_so`. / 尽量使用静态可执行文件；否则确认 `PT_INTERP` 指向 `/libexec/ld.elf_so`。  
       Evidence: `minix/drivers/storage/ramdisk/proto.common.dynamic:2`, `minix/servers/vfs/exec.c:282`
    3) Ensure dynamic loader is mapped below stack as per VFS logic. / 确认动态加载器按 VFS 逻辑映射到栈下。  
      Evidence: `minix/servers/vfs/exec.c:306`
    4) Keep the test binary minimal (single `main`, no threads) to isolate VM/exec issues. / 测试程序保持最小化以隔离 VM/exec 问题。

### A3) userland `memset` stack-top SIGSEGV (mitigated and smoke-validated in both diskless/with-disk profiles) / 用户态 `memset` 栈顶 SIGSEGV（已缓解，并在无盘/带盘 smoke 验证）
- Evidence / 证据:
  - `./minix/tests/riscv64/run_tests.sh all` (2026-01-31, with-disk profile) fails the VirtIO block I/O smoke test; running
    `/sbin/minix-service -c up /service/virtio_blk_mmio -dev /dev/c0d0` triggers SIGSEGV.  
    Logs: `/tmp/minix-riscv64-tests.log`, `/home/donz/minix/obj/test-logs/boot_test.*.log`
  - 2026-02-16 ramdisk smoke repro: `/bin/mount -t procfs none /proc` invokes `/sbin/minix-service up /service/procfs ...` and crashes with SIGSEGV, so `/proc` cannot be mounted and `cat /proc/meminfo` fails with `No such file or directory`.
    Log: `/tmp/qemu-proctest.log`
  - 2026-02-16 interactive shell repro: `ps -aux` crashes with
    `VM: pagefault: SIGSEGV ... bad addr 0xefbffff0; err 0xf nopage write`,
    `stacktrace ps/... pc=0x50608 sp=0xefbffff0`, then `Segmentation fault`.
    This matches the same stack-top fault signature seen in `minix-service`/`init`.
    Log excerpt provided in-session.
  - Stacktrace in QEMU output: `pc=0x3bb38 sp=0xefbffff0 ra=0x3bbf0`, VM reports `SIGSEGV ... err 0xf nopage write`.
  - Symbol mapping (no DWARF line info): `minix/commands/minix-service/obj/minix-service` shows
    `0x3bb34 T memset`, so the fault PC is inside `memset` in the minix-service binary.
  - Symbol mapping for `ps`: `obj/destdir.evbriscv64/bin/ps` shows
    `0x50604 T memset`; the observed `pc=0x50608` is inside the same function.
  - Root-cause codegen check: RV64 `memset` in affected binaries showed self-call recursion on short-length path (stack growth until fault).  
    受影响二进制中的 RV64 `memset` 在短长度路径出现自调用递归，导致栈持续增长至缺页。
  - Fix applied in tree: disable recursive memset codegen pattern for RV64 generic `memset.c` via  
    `lib/libc/arch/riscv/string/Makefile.inc` (`COPTS.memset.c+= -fno-builtin-memset -fno-tree-loop-distribute-patterns`).
- Impact / 影响:
  - Before fix: user commands (`ps`) and service startup paths (`minix-service`) could crash with stack-top SIGSEGV, blocking `/proc` functional checks.
  - After fix in current working tree: ramdisk smoke no longer reproduces this crash signature.
- Update / 进展:
  - 2026-02-16 QEMU re-test (ramdisk profile) after rebuilding libc/ramdisk/memory:
    - `ps -aux` completes and returns shell prompt, no SIGSEGV.
    - `cat /proc/meminfo` returns data successfully (still shows one recoverable safecopy fallback; tracked in `#17`).
  - 2026-02-16 QEMU re-test (with-disk profile using `-i /tmp/minix-smoke-disk.img`):
    `virtio-blk-mmio` reports capacity and initialization, no `minix-service` SIGSEGV signature observed.
    Log: `/tmp/qemu-smoke-disk.log`
  - Status / 状态: fixed + smoke-validated for current bring-up scope; keep long-run stress/regression under P1 follow-up.

### A4) virtio_blk_mmio startup failure in diskless QEMU smoke (configuration-driven) / 无盘 QEMU 冒烟中 virtio_blk_mmio 启动失败（配置驱动）
- Evidence / 证据:
  - `virtio-blk-mmio: device not found` appears in `/tmp/qemu-fix20.log` around line 3760.
  - RS request failure follows: `Request 0x700 to RS failed: specified endpoint is not alive (error 215)` at `/tmp/qemu-fix20.log:3770`.
  - rc warning emitted: `WARNING: couldn't start virtio_blk_mmio` at `/tmp/qemu-fix20.log:3785`.
- Impact / 影响:
  - Boot still reaches shell, but storage/virtio path is not actually validated in this smoke mode.
  - 该失败会污染启动日志，容易与真正的服务崩溃混淆。
- Hypothesis / 假设:
  - The smoke run uses no extra block image (`qemu-riscv64.sh` without `-i`), so virtio block device is absent by design.
  - 当前现象更像“配置缺设备”而非驱动立即崩溃；与 A3 的“含盘场景下 SIGSEGV”应分开跟踪。
- Next steps / 下一步:
  - Split smoke into diskless and with-disk profiles.
  - For virtio validation, run QEMU with `-i <disk image>` and assert service start success before I/O tests.

## Critical / 严重

- None confirmed in current workspace; former Critical #1 moved to Fixed. / 当前工作区未确认有严重问题，原 Critical #1 已移至 Fixed。

## Major / 重要

### 4) Leaf → non-leaf page table split lacks TLB flush / 叶子页拆分后未刷新 TLB
- Evidence / 证据:
  - `minix/servers/vm/pagetable.c:50-147` (`pt_l0alloc`) and `150-193` (`pt_l1alloc`) convert
    leaf mappings to non-leaf PTEs without a TLB invalidation.
- Impact / 影响:
  - Stale large-page TLB entries may persist, causing wrong mappings. / 旧的大页 TLB 项可能继续生效，导致映射错误。
- Suggested fix / 修复建议:
  - Issue `VMCTL_FLUSHTLB` or targeted `sfence.vma` after the split. / 拆分后执行 `VMCTL_FLUSHTLB` 或定向 `sfence.vma`。
- Update / 进展:
  - Added `VMCTL_FLUSHTLB` after leaf-to-non-leaf splits in `pt_l0alloc`/`pt_l1alloc` (needs runtime validation).  
    在 `pt_l0alloc`/`pt_l1alloc` 的叶子拆分后增加 `VMCTL_FLUSHTLB`（需运行时验证）。  
    Evidence: `minix/servers/vm/pagetable.c`

### 5) SBI legacy IPI/fence calls pass virtual addresses / SBI v0.1 旧接口传递 VA
- Evidence / 证据:
  - `minix/kernel/arch/riscv64/sbi.c:131-151` passes `&hart_mask` for legacy SBI v0.1 calls
- Impact / 影响:
  - SBI v0.1 expects PA; VA breaks once paging is enabled. / SBI v0.1 期望 PA，启用分页后传 VA 会失败。
  - IPI and remote fence may silently fail. / IPI 与远程指令缓存刷新可能失效。
- Suggested fix / 修复建议:
  - Use SBI v0.2+ extensions or translate to PA. / 切换到 SBI v0.2+ 扩展或传递物理地址。
- Update / 进展:
  - Legacy SBI IPI/RFENCE calls now translate the hart mask pointer to PA via `umap_local` (needs kernel rebuild to validate).  
    旧 SBI IPI/RFENCE 已通过 `umap_local` 将 hart mask 指针转为 PA（需重建内核验证）。  
    Evidence: `minix/kernel/arch/riscv64/sbi.c`

### 6) UART driver blocks reads without replying / UART 阻塞读无延迟回复
- Evidence / 证据:
  - `minix/drivers/tty/ns16550/ns16550.c:171-195` returns `EDONTREPLY` when no data
  - `minix/drivers/tty/ns16550/ns16550.c:256-298` interrupt handler does not issue deferred replies
- Impact / 影响:
  - Blocking reads hang indefinitely; userland console read stalls. / 阻塞读无限期挂起，用户态无法读取。
- Suggested fix / 修复建议:
  - Track pending reads and reply on RX interrupts. / 保存挂起请求并在 RX 中断时回复。
- Update / 进展:
  - Added pending read tracking plus RX interrupt reply; adjusted ioctl handling to NetBSD-style `TIOC*` and SEF startup flow (needs rebuild/runtime validation).  
    增加挂起读记录并在 RX 中断时回复；ioctl 改为 `TIOC*` 风格并调整 SEF 启动（需重建/运行验证）。  
    Evidence: `minix/drivers/tty/ns16550/ns16550.c`

### 7) vm_map_range marks pages executable unconditionally / vm_map_range 无条件设置可执行
- Evidence / 证据:
  - `minix/kernel/arch/riscv64/memory.c:198-205` sets `PTE_X` in all mappings
- Impact / 影响:
  - W^X is violated; data pages become executable. / 违反 W^X，数据页被标记为可执行。
- Suggested fix / 修复建议:
  - Set `PTE_X` only for executable mappings (use VMMF flags). / 仅在可执行映射时设置 `PTE_X`。
- Update / 进展:
  - Drop unconditional `PTE_X`; only add execute on non-writable mappings to keep W^X with current VMMF flags (needs rebuild/runtime validation).  
    移除无条件 `PTE_X`；仅对非写映射设置执行位以保持 W^X（需重建/运行验证）。  
    Evidence: `minix/kernel/arch/riscv64/memory.c`

### 8) Breakpoint exception always advances PC by 4 bytes / 断点异常固定前移 4 字节
- Evidence / 证据:
  - `minix/kernel/arch/riscv64/exception.c:162-168`
- Impact / 影响:
  - Compressed `ebreak` is 2 bytes; advancing by 4 skips the next instruction. / 压缩 `ebreak` 为 2 字节，前移 4 字节会跳过下一条指令。
- Suggested fix / 修复建议:
  - Decode instruction length before advancing `sepc`. / 根据指令长度推进 `sepc`。
- Update / 进展:
  - Use 16-bit low bits to pick 2 vs 4 byte instruction length when skipping kernel breakpoints (needs rebuild/runtime validation).  
    内核断点前移时按低位判断 2/4 字节指令长度（需重建/运行验证）。  
    Evidence: `minix/kernel/arch/riscv64/exception.c`

### 9) Software interrupts (IPI) not enabled in SIE / SIE 中未开启 SSIE
- Evidence / 证据:
  - `minix/kernel/arch/riscv64/exception.c:60-61` enables only STIE/SEIE
- Impact / 影响:
  - SMP IPIs will not be delivered even if SBI works. / 即使 SBI 正常，SMP IPI 也不会送达。
- Suggested fix / 修复建议:
  - Enable `SIE_SSIE` when SMP is configured. / SMP 场景下开启 `SIE_SSIE`。
- Update / 进展:
  - Enable `SIE_SSIE` under `CONFIG_SMP` during exception init (needs rebuild/runtime validation).  
    在异常初始化中为 `CONFIG_SMP` 启用 `SIE_SSIE`（需重建/运行验证）。  
    Evidence: `minix/kernel/arch/riscv64/exception.c`

### 15) RISC-V SMP core missing (arch_smp + smp.c not implemented) / RISC-V SMP 核心缺失
- Evidence / 证据:
  - `minix/kernel/arch/riscv64/include/arch_proto.h:143-151` declares SMP entrypoints with no riscv64 definitions
  - `minix/kernel/arch/riscv64/head.S:149-152` calls `smp_ap_entry` when `CONFIG_SMP` is enabled
  - `docs/RISCV64_PORT_PLAN.md:1618-1621` and `README-RISCV64.md:213-218` state SMP core is planned/skip-marked
- Impact / 影响:
  - CONFIG_SMP builds will not link or will only boot BSP; AP bring-up and IPI paths are missing. / 打开 CONFIG_SMP 时无法链接或仅能启动 BSP；从核启动与 IPI 路径缺失。
- Suggested fix / 修复建议:
  - Add `minix/kernel/arch/riscv64/smp.c` with `smp_init`, `smp_ap_entry`, `smp_send_ipi`, `smp_broadcast_ipi`, `smp_ipi_handler`, `arch_send_smp_schedule_ipi`, `arch_smp_halt_cpu`. / 增加 riscv64 `smp.c` 并实现上述入口。
  - Add `minix/kernel/arch/riscv64/include/arch_smp.h` with SMP `cpuid` definition, plus per-CPU PLIC/timer init and `SIE_SSIE` enablement. / 增加 riscv64 `arch_smp.h`，定义 SMP `cpuid`，并接入每 CPU 的 PLIC/定时器初始化及 `SIE_SSIE` 使能。

### 16) VFS service endpoint pre-resync may weaken endpoint validation / VFS 服务端点预同步可能弱化端点校验
- Evidence / 证据:
  - `map_service()` rewrites `fproc[pub_slot].fp_endpoint` before validation in `minix/servers/vfs/dmap.c:214-218`.
  - `isokendpt_f()` validates by comparing `fproc[*proc].fp_endpoint` against the input endpoint in `minix/servers/vfs/utility.c:117`.
  - This creates a "write-then-check" path where generation mismatch can be masked.
- Impact / 影响:
  - Endpoint generation inconsistencies may be accepted too early.
  - 可能降低 VFS 对服务端点代际错误的检测能力，增加隐性状态污染风险。
- Suggested fix / 修复建议:
  - Validate endpoint/generation first (without mutating `fproc`), then apply resync only when explicitly proven safe.
  - Add a guarded path (and log) for legitimate RS republish cases.

### 18) RS init-ready path may dereference null service slot on unexpected RS_INIT / RS 初始化就绪路径在异常 RS_INIT 下可能空指针解引用
- Evidence / 证据:
  - `do_init_ready()` dereferences `rproc_ptr[who_p]` without null check:
    `minix/servers/rs/request.c:474-476`.
  - `catch_boot_init_ready()` also dereferences `rproc_ptr[_ENDPOINT_P(m.m_source)]` without validating non-null:
    `minix/servers/rs/main.c:812`, `minix/servers/rs/main.c:835`.
  - `rs_isokendpt()` only validates numeric range, not slot binding:
    `minix/servers/rs/utility.c:352-358`.
- Impact / 影响:
  - A malformed or unexpected `RS_INIT` message can crash RS (null dereference), which is high impact because RS is core service management infrastructure.
  - 若触发，可能导致服务管理中枢异常并引发系统级连锁故障。
- Suggested fix / 修复建议:
  - Add `rp == NULL` checks before dereference in both paths and return `EINVAL`/ignore unexpected senders.
  - In boot catch path, validate source endpoint against expected initializing set before accepting `RS_INIT`.
- Update / 进展:
  - Added strict source validation via `rs_isokservice()` before dereferencing in both `do_init_ready()` and `catch_boot_init_ready()`, with explicit invalid-source handling. Runtime/QEMU smoke validation has completed.
    已在 `do_init_ready()` 与 `catch_boot_init_ready()` 中通过 `rs_isokservice()` 先做严格来源校验，再解引用；异常来源路径已显式处理。运行时/QEMU 冒烟复验已完成。
    Evidence: `minix/servers/rs/request.c`, `minix/servers/rs/main.c`, `minix/servers/rs/utility.c`
  - Status / 状态: fixed + smoke-validated on 2026-02-16.

### 20) RS update-ready path may dereference null slot on unexpected RS_LU_PREPARE / RS 更新就绪路径在异常 RS_LU_PREPARE 下可能空指针解引用
- Evidence / 证据:
  - `do_upd_ready()` reads `rproc_ptr[_ENDPOINT_P(m_source)]` and then dereferences `rp` without null guard:
    `minix/servers/rs/request.c:899-901`, `minix/servers/rs/request.c:911`.
  - The unexpected-message branch logs `srv_to_string(rp)` as well:
    `minix/servers/rs/request.c:905-909` (unsafe when `rp == NULL`).
- Impact / 影响:
  - A malformed/stale `RS_LU_PREPARE` message can crash RS during live-update coordination.
  - 该路径属于核心更新控制面，触发后会中断服务更新流程并可能导致系统管理失稳。
- Suggested fix / 修复建议:
  - Validate `who_p` binding and `rp != NULL` before any dereference.
  - Reject senders that do not match `rupdate.curr_rpupd->rp` with `EINVAL` and keep RS running.
- Update / 进展:
  - `do_upd_ready()` now validates service endpoint binding using `rs_isokservice()` before touching `rproc_ptr[]`/`rp`, so malformed or stale senders are rejected safely. Runtime/QEMU smoke validation has completed.
    `do_upd_ready()` 已在访问 `rproc_ptr[]`/`rp` 前使用 `rs_isokservice()` 校验端点绑定，畸形或陈旧来源会被安全拒绝。运行时/QEMU 冒烟复验已完成。
    Evidence: `minix/servers/rs/request.c`, `minix/servers/rs/utility.c`
  - Hardened live-update init-done probes: `RUPDATE_IS_VM_INIT_DONE()` / `RUPDATE_IS_RS_INIT_DONE()` now go through `rs_service_flag_is_set()`, preventing null-deref when VM/RS mapping is temporarily unavailable during update sequencing.
    补强 live update 的 init-done 判定：`RUPDATE_IS_VM_INIT_DONE()` / `RUPDATE_IS_RS_INIT_DONE()` 已改为经 `rs_service_flag_is_set()` 查询，避免在更新编排阶段 VM/RS 映射暂不可用时发生空指针解引用。
    Evidence: `minix/servers/rs/const.h`, `minix/servers/rs/utility.c`, `minix/servers/rs/update.c`
  - Status / 状态: fixed + smoke-validated on 2026-02-16.

### 21) RS endpoint validation accepts task numbers, enabling out-of-bounds `rproc_ptr[]` access / RS 端点校验接受任务号，可能导致 `rproc_ptr[]` 越界访问
- Evidence / 证据:
  - `rs_isokendpt()` allows endpoint slots in `[-NR_TASKS, NR_PROCS)`:
    `minix/servers/rs/utility.c:352-358`.
  - Callers index `rproc_ptr[proc]` directly after this check:
    `minix/servers/rs/main.c:64-66`, `minix/servers/rs/main.c:86-87`,
    `minix/servers/rs/main.c:655-661`.
  - `rproc_ptr` is sized as `NR_PROCS` only:
    `minix/servers/rs/glo.h:35`.
- Impact / 影响:
  - Task endpoints (negative proc slots) can drive negative indexing into `rproc_ptr[]`, causing out-of-bounds read/write and RS state corruption.
  - 在异常通知/信号路径上属于高危内存安全问题。
- Suggested fix / 修复建议:
  - Introduce a strict service-endpoint validator (`0 <= proc < NR_PROCS`) for all `rproc_ptr[]` indexing paths.
  - Keep task-range acceptance only in paths that never index process-slot arrays.
- Update / 进展:
  - Introduced `rs_isokservice()` (`0 <= proc < NR_PROCS`, mapping exists) and switched `rproc_ptr[]` indexing paths in RS main/signal/init/update handling to this strict validator, preventing negative-index task-slot access. Endpoint-generation hard match is intentionally not enforced in boot catch path due startup endpoint encoding differences.
    新增 `rs_isokservice()`（要求 `0 <= proc < NR_PROCS` 且映射存在），并将 RS main/signal/init/update 中访问 `rproc_ptr[]` 的路径切换为严格校验，阻断 task slot 负索引。考虑启动期 endpoint 编码差异，boot catch 路径未强制端点代际硬匹配。
    Evidence: `minix/servers/rs/utility.c`, `minix/servers/rs/main.c`, `minix/servers/rs/request.c`, `minix/servers/rs/proto.h`
  - Added `rs_isokprocnr()` for strict endpoint-to-slot conversion (`0 <= proc < NR_PROCS`) and applied it to remaining internal `rproc_ptr[]` map access points (boot table mapping, child endpoint publish, slot swap/update remap, RS restart/LU handoff lookups).
    新增 `rs_isokprocnr()` 作为严格 endpoint->slot 转换（`0 <= proc < NR_PROCS`），并覆盖剩余内部 `rproc_ptr[]` 访问点（boot 映射、子进程 endpoint 发布、slot swap/update 重映射、RS restart/LU 交接查找）。
    Evidence: `minix/servers/rs/utility.c`, `minix/servers/rs/main.c`, `minix/servers/rs/manager.c`, `minix/servers/rs/update.c`
  - 2026-02-16 quick revalidation: `nbmake-evbriscv64 -C minix/servers/rs` completed, and `timeout 120 ./minix/scripts/qemu-riscv64.sh -s -k obj.intrgcc/minix/kernel/kernel -B obj.intrgcc/destdir.evbriscv64` reached boot shell path (`MINIX 3.4.0`) without RS panic/SIGSEGV signature in `/tmp/qemu-rs-p0.log`.
    2026-02-16 快速复验：`nbmake-evbriscv64 -C minix/servers/rs` 编译通过；`timeout 120 ./minix/scripts/qemu-riscv64.sh -s -k obj.intrgcc/minix/kernel/kernel -B obj.intrgcc/destdir.evbriscv64` 可走到 `MINIX 3.4.0` 启动 shell 路径，`/tmp/qemu-rs-p0.log` 未见 RS panic/SIGSEGV 特征。
  - 2026-02-16 with-disk smoke revalidation: `timeout 140 ./minix/scripts/qemu-riscv64.sh -s -k obj.intrgcc/minix/kernel/kernel -B obj.intrgcc/destdir.evbriscv64 -i /tmp/minix-smoke-disk.img` reached shell path and did not reproduce RS endpoint/oob crash signatures.
    2026-02-16 带盘冒烟复验：`timeout 140 ./minix/scripts/qemu-riscv64.sh -s -k obj.intrgcc/minix/kernel/kernel -B obj.intrgcc/destdir.evbriscv64 -i /tmp/minix-smoke-disk.img` 可走到 shell 路径，未复现 RS endpoint/oob 崩溃特征。
    Log: `/tmp/qemu-smoke-disk.log`
  - Status / 状态: fixed + smoke-validated on 2026-02-16.

### 22) RS can write out of bounds in `free_slot()` when endpoint is unset (-1) / `free_slot()` 在端点未设置(-1)时可能越界写
- Evidence / 证据:
  - Clone slots are created with an unset endpoint:
    `minix/servers/rs/manager.c:1831` (`clone_rpub->endpoint = -1`).
  - `create_service()` has multiple early-failure paths calling `free_slot()` before assigning a child endpoint:
    `minix/servers/rs/manager.c:550`, `minix/servers/rs/manager.c:558`,
    `minix/servers/rs/manager.c:566`, `minix/servers/rs/manager.c:579`.
  - `free_slot()` unconditionally does `rproc_ptr[_ENDPOINT_P(rpub->endpoint)] = NULL`:
    `minix/servers/rs/manager.c:2108`.
- Impact / 影响:
  - When `endpoint == -1`, `_ENDPOINT_P(-1) == -1`, producing an out-of-bounds write to `rproc_ptr[]`.
  - 在资源紧张（如 `srv_fork` 失败）时可触发，破坏 RS 内部映射并导致后续不可预测故障。
- Suggested fix / 修复建议:
  - In `free_slot()`, validate endpoint slot bounds before touching `rproc_ptr[]`.
  - Initialize/normalize unset endpoints to `NONE` and treat them as “no mapping to clear”.
  - Add assertions/tests covering clone->create failure paths.
- Update / 进展:
  - `free_slot()` now bounds-checks endpoint-derived slots, clears mapping only when ownership matches (`rproc_ptr[slot] == rp`), and normalizes released endpoints to `NONE`, eliminating the `endpoint=-1` write-underflow path. Runtime/QEMU smoke validation has completed.
    `free_slot()` 现已对 endpoint 槽位做边界校验，仅在映射归属匹配（`rproc_ptr[slot] == rp`）时清理，并将释放后的 endpoint 归一为 `NONE`，消除 `endpoint=-1` 的下溢写路径。运行时/QEMU 冒烟复验已完成。
    Evidence: `minix/servers/rs/manager.c`
  - Closed related unset-endpoint write windows beyond `free_slot()`: `reincarnate_service()` no longer blindly indexes `rproc_ptr[]`, and remap paths (`swap_slot()` / `update_service()`) now validate endpoint slots before touching the mapping table.
    进一步封堵 `free_slot()` 之外的未设 endpoint 写窗口：`reincarnate_service()` 不再盲目索引 `rproc_ptr[]`，并且 `swap_slot()` / `update_service()` 在修改映射表前都会先校验 endpoint 槽位。
    Evidence: `minix/servers/rs/manager.c`, `minix/servers/rs/update.c`
  - Status / 状态: fixed + smoke-validated on 2026-02-16.

### 23) RISC-V `vm_memset` lacks fault-recovery path and may panic kernel on user-memory write faults / RISC-V `vm_memset` 缺少故障恢复路径，用户内存写故障可能直接触发内核 panic
- Evidence / 证据:
  - RISC-V `vm_memset` performs direct `phys_memset` with no fault return channel:
    `minix/kernel/arch/riscv64/memory.c:452`.
  - RISC-V declares `phys_memset` as `void`, unlike i386/ARM fault-reporting signatures:
    `minix/kernel/arch/riscv64/include/arch_proto.h:100`,
    `minix/kernel/arch/i386/include/arch_proto.h:104`,
    `minix/kernel/arch/earm/include/arch_proto.h:17`.
  - Page-fault recovery in RISC-V exception path only checks `phys_copy` window, not `memset`:
    `minix/kernel/arch/riscv64/exception.c:252-255`.
  - i386/ARM explicitly support `memset_fault` recovery points:
    `minix/kernel/arch/i386/exception.c:66-73`,
    `minix/kernel/arch/earm/exception.c:49-56`.
- Impact / 影响:
  - A write fault during kernel-assisted memset to user mappings (e.g., COW/protection transition windows) can escalate to kernel panic instead of VM-assisted suspend/retry.
  - 该问题直接影响内核健壮性，是高优先级稳定性风险。
- Suggested fix / 修复建议:
  - Add fault-aware RISC-V `phys_memset` semantics (fault address/status return or dedicated fault labels).
  - Extend RISC-V exception fault window handling to include memset recovery, matching i386/ARM behavior.
  - Ensure `vm_memset` can return `VMSUSPEND` on recoverable write faults.
- Update / 进展:
  - Added RISC-V memset fault-recovery plumbing in current working tree:
    `phys_memset` now returns fault status, `exception.c` handles `in_memset`
    windows (`memset_fault` / `memset_fault_in_kernel`), and `vm_memset`
    wraps the memset loop with `catch_pagefaults` and returns `VMSUSPEND`
    for recoverable user-mapping faults.
    已在当前工作区补齐 RISC-V memset 故障恢复链路：`phys_memset` 返回故障状态，
    `exception.c` 新增 `in_memset` 窗口处理（`memset_fault` / `memset_fault_in_kernel`），
    `vm_memset` 通过 `catch_pagefaults` 包裹并在可恢复用户映射故障时返回 `VMSUSPEND`。
  - Evidence: `minix/kernel/arch/riscv64/phys_copy.S`,
    `minix/kernel/arch/riscv64/exception.c`,
    `minix/kernel/arch/riscv64/memory.c`,
    `minix/kernel/arch/riscv64/include/arch_proto.h`
  - 2026-02-16 runtime smoke revalidation with GCC-built kernel:
    `./minix/scripts/qemu-riscv64.sh -s -k minix/kernel/obj/kernel -B obj/destdir.evbriscv64`
    and in-guest commands `ps -aux`, `cat /proc/meminfo`,
    `/sbin/minix-service sysctl srv_status` all returned `RC=0`;
    no kernel panic and no `SIGSEGV` signature were observed.
    2026-02-16 使用 GCC 重建内核后完成运行复验：
    `ps -aux`、`cat /proc/meminfo`、`minix-service sysctl srv_status`
    均返回 `RC=0`，未出现 kernel panic 或 `SIGSEGV` 特征。
    Log: `/tmp/qemu-p0-smoke.log`
  - 2026-02-16 incremental + with-disk smoke revalidation:
    `timeout 120 ./minix/scripts/qemu-riscv64.sh -s -k obj.intrgcc/minix/kernel/kernel -B obj.intrgcc/destdir.evbriscv64`
    and
    `timeout 140 ./minix/scripts/qemu-riscv64.sh -s -k obj.intrgcc/minix/kernel/kernel -B obj.intrgcc/destdir.evbriscv64 -i /tmp/minix-smoke-disk.img`
    both reached shell path with no kernel panic/SIGSEGV signature.
    Log: `/tmp/qemu-smoke-incremental.log`, `/tmp/qemu-smoke-disk.log`
  - Status / 状态: fixed + smoke-validated for current bring-up scope on 2026-02-16.
  - Optional hardening backlog / 可选加固待办:
    keep targeted fault-injection coverage to prove `VMSUSPEND` recovery
    under intentional user-memory write faults.
    保留定向故障注入验证，以确认刻意构造写缺页时可稳定走 `VMSUSPEND` 恢复路径。

### 24) In-tree RISC-V linker cannot handle `R_RISCV_RELAX`, blocking incremental rebuilds (mitigated) / in-tree RISC-V 链接器不支持 `R_RISCV_RELAX`，阻断增量重建（已缓解）
- Evidence / 证据:
  - Rebuilding `minix/drivers/storage/memory` with in-tree toolchain fails at link stage:
    `ld: unrecognized relocation (0x33)` from `libblockdriver.a(driver_st.o)`.
  - In-tree linker version is old:
    `obj/tooldir.Linux-6.12.63+deb13-amd64-x86_64/riscv64-elf32-minix/bin/ld --version`
    reports `GNU ld (NetBSD Binutils nb1) 2.23.2`.
  - Affected archives include many `R_RISCV_RELAX` relocations:
    `obj/destdir.evbriscv64/usr/lib/libblockdriver.a`,
    `obj/destdir.evbriscv64/usr/lib/libchardriver.a` (`readelf -r`).
  - Temporary validation workaround: using host `riscv64-unknown-elf-ld` (binutils 2.44) allows link to proceed.
  - 2026-02-16 update: add tracked patch
    `external/gpl3/binutils/patches/0011-riscv-relax-compat.patch`
    to accept `R_RISCV_RELAX` as linker-hint/no-op in in-tree binutils bfd.
  - Validation on in-tree `ld` (2.23.2) succeeds with archives containing `R_RISCV_RELAX`:
    `ld -r --whole-archive obj/destdir.evbriscv64/usr/lib/libaudiodriver.a --no-whole-archive -o /tmp/libaudiodriver.whole.o`.
- Impact / 影响:
  - Previously blocked rebuilding core components with the intended in-tree GCC toolchain flow.
  - Current workspace mitigation removes the `0x33` linker blocker; incremental-link reproducibility improves.
- Suggested fix / 修复建议:
  - Completed in current workspace: compatibility handling for `R_RISCV_RELAX` in binutils bfd via patch `0011`.
  - Optional follow-up: upgrade/refresh in-tree RISC-V binutils (`ld`) to a newer upstream version.
  - Add a build-time toolchain capability check (fail fast with actionable message when linker is too old).
  - Keep a documented fallback path in `README-RISCV64.md` for environments with older/unpatched linker trees.

### 25) In-tree GCC rejects `-mabi=lp64d`, blocking some GCC-only incremental rebuilds / 内建 GCC 不接受 `-mabi=lp64d`，阻断部分 GCC-only 增量重建
- Evidence / 证据:
  - Forcing GCC path on memory-service incremental rebuild:
    `nbmake-evbriscv64 ... ACTIVE_CC=gcc ... -C minix/drivers/storage/memory dependall install`
    fails at compile stage with:
    `riscv64-elf32-minix-gcc: error: unrecognized command line option '-mabi=lp64d'`.
  - Same cycle confirms #24 linker path is already mitigated; failure occurs before link.
- Impact / 影响:
  - Blocks clean GCC-only incremental rebuild workflow for some components.
  - Increases divergence between default compiler path and explicit GCC validation path.
- Suggested fix / 修复建议:
  - Normalize RISC-V ABI flag selection for in-tree GCC capability (e.g., `-mabi=lp64` fallback).
  - Add compiler capability probing and emit actionable diagnostics when ABI flags are unsupported.
  - Keep per-component overrides documented until GCC flag baseline is unified.

### 26) RS slot/exec cleanup is missing on several `do_up`/`do_update` error paths, causing repeatable `RSS_COPY` memory leaks / RS 在若干 `do_up`/`do_update` 失败路径缺少 slot/exec 回收，`RSS_COPY` 可触发可重复内存泄漏
- Evidence / 证据:
  - `do_up()` allocates a slot then returns directly on duplicate checks without `free_slot()`:
    `minix/servers/rs/request.c:31`, `minix/servers/rs/request.c:64`,
    `minix/servers/rs/request.c:71-75`, `minix/servers/rs/request.c:76-80`,
    `minix/servers/rs/request.c:81-86`.
  - `do_update()` regular-update path allocates a slot and returns directly when `init_slot()` fails, also without `free_slot()`:
    `minix/servers/rs/request.c:725-736`.
  - `init_slot()` may load and retain an in-memory executable copy (`r_exec`) when `RSS_COPY` is requested:
    `minix/servers/rs/manager.c:1629-1661`, `minix/servers/rs/manager.c:1372-1403`.
  - The normal cleanup path for this memory is `free_slot()->free_exec()`:
    `minix/servers/rs/manager.c:2100-2114`, `minix/servers/rs/manager.c:1424-1454`.
- Impact / 影响:
  - Repeated `RS_UP`/`RS_UPDATE` requests that fail after `init_slot()` can leak executable-copy heap buffers in RS.
  - 典型可复现路径是：带 `RSS_COPY` 的请求在重复标签/设备号检查处失败，导致 `r_exec` 未释放并被下一次 slot 复用覆盖，形成长期泄漏。
  - This is a control-plane resource-exhaustion risk (RS heap growth / eventual ENOMEM), degrading service-management reliability.
- Suggested fix / 修复建议:
  - In `do_up()` and `do_update()`, add a unified error-exit path that always calls `free_slot(rp/new_rp)` when a slot has been initialized but not successfully created/published.
  - Clear `r_exec` ownership deterministically on all post-`init_slot()` failure branches (including duplicate checks).
  - Add a regression test that issues repeated failing `RSS_COPY` requests and asserts no net RS memory growth.

## Moderate / 中等

### 11) Minimal kernel build is not RISC-V-ready / minimal_kernel 未支持 RISC-V
- Evidence / 证据:
  - `minimal_kernel/include/minix/const.h:83-87` rejects non-i386/arm
  - Build fails due to incomplete header/machine wiring (see build logs)
- Impact / 影响:
  - `minimal_kernel/` cannot be used for RISC-V minimal boot tests. / `minimal_kernel/` 无法用于 RISC-V 最小化测试。
- Suggested fix / 修复建议:
  - Add RISC-V support in minimal kernel headers or exclude it from RISC-V builds. / 在 minimal kernel 增加 RISC-V 支持或在 RISC-V 构建中排除。

### 13) phys_copy fault handler not registered / phys_copy 缺少故障处理注册
- Evidence / 证据:
  - `minix/kernel/arch/riscv64/phys_copy.S:71-74` leaves a TODO to register the fault handler
- Impact / 影响:
  - Faulting physical copies can trap instead of returning an error. / 物理复制缺页可能直接陷入异常而非返回错误。
- Suggested fix / 修复建议:
  - Hook into the arch fault-handling mechanism (as in other architectures) for safe phys_copy. / 接入架构故障处理机制以安全执行 phys_copy。

### 14) Device tree parsing is minimal (single region, no reserved areas) / 设备树解析较简化（单一内存段、无保留区）
- Evidence / 证据:
  - `minix/kernel/arch/riscv64/bsp/virt/bsp_init.c:80-201` parses memory/CPUs/timebase but only uses a single `memory` node and ignores reserved areas
  - `minix/kernel/arch/riscv64/memory.c:69-83` still has a TODO for richer DT-driven memory layout
- Impact / 影响:
  - Multi-region or reserved-memory layouts may be ignored, leading to overlaps or wrong sizing. / 多段或保留内存布局可能被忽略，导致覆盖或尺寸错误。
- Suggested fix / 修复建议:
  - Extend FDT parsing to handle reserved regions and multiple memory ranges, then plumb into `add_memmap`. / 扩展 FDT 解析以处理保留区与多段内存，并接入 `add_memmap`。

### 17) Repeated safecopy errors during boot are still noisy and unexplained / 启动期重复 safecopy 错误仍有噪声且原因未闭环
- Evidence / 证据:
  - `/tmp/qemu-fix20.log:415` and `/tmp/qemu-fix20.log:1040` show `kcall safecopy err=...fc1c`.
  - `/tmp/qemu-fix20.log:4159-4160` shows `kcall safecopy err=...fff2` and `do_safecopy_to: err -14 caller=10`.
  - System still continues to shell after these messages.
  - 2026-02-16 `/proc/meminfo` interactive repro shows `procfs` `REQ_READ` (`call=2579`) hitting
    `kcall safecopy err=...fff2` / `do_safecopy_to: err -14`, then succeeding on immediate retry
    (`fsdriver reply ... r=-14` followed by `r=0`) and printing meminfo successfully.
- Impact / 影响:
  - Currently appears recoverable, but it adds noise and may hide real regressions.
  - 若错误路径扩大，可能在高负载或不同镜像下演变为实际功能故障。
- Suggested fix / 修复建议:
  - Correlate each safecopy failure with request type/grant lifecycle.
  - Add focused tracing around MFS/VFS grant usage for the failing offsets and gids.
- Update / 进展:
  - VFS now disables first-pass `CPF_TRY` for magic-grant read/stat/getdents/rdlink requests targeting mounts whose fs type is `procfs`, reducing fail-fast `EFAULT -> ERESTART` churn on `/proc/*` reads while keeping other filesystems unchanged.
    / VFS 已在目标文件系统类型为 `procfs` 的 magic grant 读/状态/getdents/rdlink 请求上关闭首轮 `CPF_TRY`，以减少 `/proc/*` 读取时的 `EFAULT -> ERESTART` 抖动；其他文件系统路径不变。
    Evidence: `minix/servers/vfs/request.c`
  - 2026-02-16 `qemu-p0-smoke` (`/tmp/qemu-p0-smoke.log`) still shows a recoverable
    procfs safecopy fallback (`err -996`) on `/proc/meminfo` path, but command
    return remains successful (`__RC_MEMINFO__:0`) and no crash is observed.
    2026-02-16 的 `qemu-p0-smoke`（`/tmp/qemu-p0-smoke.log`）在 `/proc/meminfo`
    路径仍可见可恢复 safecopy 回退（`err -996`），但命令返回成功
    （`__RC_MEMINFO__:0`），未出现崩溃。
- Priority assessment / 优先级评估:
  - Keep at `P1` for now: the fault appears recoverable (retry succeeds), but repeated fallback/retry
    in hot read paths (`/proc/*`) can become a performance/logging storm and obscure real regressions.
    After adding counters/rate limits and confirming no functional impact under load, consider downgrading to `P2`.

### 19) Excessive unconditional debug logging in kernel/VM/RS obscures real faults / kernel/VM/RS 无条件调试日志过多，掩盖真实故障
- Evidence / 证据:
  - Kernel has pervasive unconditional `direct_print*` tracing in hot paths
    (e.g. `minix/kernel/main.c`, `minix/kernel/proc.c`, `minix/kernel/system.c`,
    `minix/kernel/arch/riscv64/arch_do_vmctl.c`).
  - VM emits runtime traces such as `VM: recv ...` and `VM: pt_bind set_addrspace ...` in normal flow:
    `minix/servers/vm/main.c:136-145`, `minix/servers/vm/pagetable.c:2216`.
  - RS boot handshake prints `RS: wait init ready ...`/`RS: got init ready ...`:
    `minix/servers/rs/main.c:797-823`.
  - Corresponding QEMU logs (`/tmp/qemu-fix20.log`) are heavily saturated with trace lines.
- Impact / 影响:
  - Log saturation makes real regressions harder to detect and can perturb timing-sensitive behavior.
  - 长期会降低回归测试可读性与排障效率。
- Suggested fix / 修复建议:
  - Gate noisy traces behind build-time/runtime debug flags (or strict rate limits).
  - Keep only milestone-level boot markers enabled by default.

## Technical Debt / 技术债务

### TD1) Static RISC-V links require per-binary __global_pointer$ workaround / 静态链接需要每个二进制打补丁
- Evidence / 证据:
  - Link failure without workaround: `crt0.o: undefined reference to '__global_pointer$'`
  - `lib/csu/arch/riscv/crt0.S` initializes `gp` for dynamic start.
  - Per-binary stubs in `minix/servers/vfs/gp.c`, `minix/servers/rs/gp.c`,
    `minix/drivers/tty/tty/gp.c`, `minix/commands/minix-service/gp.c` (and others).
- Impact / 影响:
  - Workaround is widespread but still per-binary; new binaries can miss it. / 仍需逐个二进制打补丁，新增组件易遗漏。
- Suggested fix / 修复建议:
  - Define `__global_pointer$` in crt0 or linker script globally, then remove per-binary gp.c/LDFLAGS. / 在 crt0 或链接脚本中全局定义 `__global_pointer$`，再移除各二进制 gp.c/LDFLAGS。

### TD2) SMP support is scaffolded but not fully tested / SMP 支持尚未完整验证
- Evidence / 证据:
  - `minix/kernel/arch/riscv64/README.md:156` lists SMP as not fully tested
- Impact / 影响:
  - SMP-related paths may regress silently without coverage. / SMP 路径可能在无覆盖情况下回归。
- Suggested fix / 修复建议:
  - Add SMP boot/interrupt/regression tests and document known-good configurations. / 增加 SMP 启动/中断/回归测试并记录可用配置。

### TD3) Debug registers (hardware breakpoints) not supported / 调试寄存器（硬件断点）未支持
- Evidence / 证据:
  - `minix/kernel/arch/riscv64/README.md:158` notes missing debug register support
- Impact / 影响:
  - Kernel/user debugging via hardware breakpoints is unavailable. / 无法使用硬件断点调试内核/用户态。
- Suggested fix / 修复建议:
  - Implement RISC-V debug CSR handling and integrate with exception flow. / 实现 RISC-V 调试 CSR 支持并接入异常流程。

## Enhancement / 增强提案

### E2) LiteOS-M + LiteOS-A Emulation (QEMU-based) / LiteOS-M 与 LiteOS-A 全系统仿真（QEMU）
- Tags / 标签: `enhancement`, `emulation`, `qemu`, `epic`
- Priority / 优先级: P0
- Owner / 负责人: @yangdongstation
- Target / 目标版本: Emulation platform (host OS) / 仿真平台（宿主系统）
- Summary / 简述:
  - Build a host-based full emulation stack using QEMU + HAL + kernel logic + API mapping for LiteOS-M and LiteOS-A. / 采用 QEMU + HAL + 内核功能层 + API 映射构建全系统仿真。
- Feasibility / 可行性评估:
  - Upstream LiteOS-M dynlink expects ELF `ET_DYN`; RISC-V dynlink is ELF32 and arch tree is RV32-only. / 上游 LiteOS-M 动态加载为 ELF32 且 RISC-V 仅 RV32。  
    Evidence: `https://gitee.com/openharmony/kernel_liteos_m/blob/master/components/dynlink/los_dynlink.c#L103-L112`, `https://gitee.com/openharmony/kernel_liteos_m/blob/master/components/dynlink/los_dynlink.h#L44-L64`, `https://gitee.com/openharmony/kernel_liteos_m/blob/master/README.md#L23-L40`
  - QEMU riscv32_virt uses `gcc_riscv32` and outputs `OHOS_Image`, making RV32 the practical starting point. / QEMU riscv32_virt 工具链与产物指向 RV32 起步。  
    Evidence: `https://gitee.com/openharmony/device_qemu/blob/master/riscv32_virt/README_zh.md#L15-L18`, `https://gitee.com/openharmony/device_qemu/blob/master/riscv32_virt/README_zh.md#L41-L46`
- Architecture doc / 架构文档:
  - `docs/liteos-emulation-architecture.md`

## Fixed in Current Working Tree / 已在当前工作区修复

说明 / Note: 本节记录“已合入代码但可能仍待运行时复验”的归档项，并保留原始问题编号以便追溯。  
This section archives items with code-level fixes landed (some may still require runtime re-validation), keeping original IDs for traceability.

- Former Major #24: in-tree binutils now accepts `R_RISCV_RELAX` as a hint/no-op via
  `external/gpl3/binutils/patches/0011-riscv-relax-compat.patch`; in-tree `ld` no longer aborts
  on relocation `0x33` during archive link validation.
  历史 Major #24：已通过 `external/gpl3/binutils/patches/0011-riscv-relax-compat.patch`
  让 in-tree binutils 将 `R_RISCV_RELAX` 作为 hint/no-op 处理；归档链接验证不再因 `0x33` 中断。
- `minimal_kernel/proto.h:175` uses `reg_t` for `arch_set_secondary_ipc_return` to avoid RV64 truncation
  (matches `minix/kernel/proto.h` and arch implementations).  
  `minimal_kernel/proto.h:175` 已改为 `reg_t`，避免 RV64 截断（与 `minix/kernel/proto.h` 及架构实现一致）。
- `minix/include/minix/com.h:776` uses a 64-bit VPF_ADDR field; VM pagefault address transport is now 64-bit.  
  `minix/include/minix/com.h:776` 使用 64 位 VPF_ADDR，缺页地址传递已改为 64-bit。
- `minix/lib/libc/arch/riscv64/sys/_ipc.S:101` argument order for `senda` now matches kernel expectations.  
  `minix/lib/libc/arch/riscv64/sys/_ipc.S:101` 修正 `senda` 参数顺序以匹配内核。
- `minix/lib/libc/arch/riscv64/sys/ucontext.S:7` uses generated offsets and sets `MCF_MAGIC` for RV64 ucontext.  
  `minix/lib/libc/arch/riscv64/sys/ucontext.S:7` 使用偏移头与 `MCF_MAGIC`，统一 RV64 ucontext 约定。
- `minix/kernel/arch/riscv64/protect.c` maps `.usermapped` into the boot page table for `minix_kerninfo_user`.  
  `minix/kernel/arch/riscv64/protect.c` 在启动页表映射 `.usermapped`，修复早期 `minix_kerninfo_user` 缺页。
- `minix/drivers/storage/virtio_blk_mmio/virtio_blk_mmio.c` and `minix/drivers/storage/virtio_blk/virtio_blk.c` fix SELF iovec handling for sys_vumap.  
  `minix/drivers/storage/virtio_blk_mmio/virtio_blk_mmio.c` 与 `minix/drivers/storage/virtio_blk/virtio_blk.c` 修复 sys_vumap 的 SELF iovec 处理。
- `minix/servers/vm/slaballoc.c` increases slab size classes to cover RV64 message sizes (avoids slaballoc assert).  
  `minix/servers/vm/slaballoc.c` 扩展 slab 大小类以覆盖 RV64 message（避免 slaballoc 断言）。
- `minix/servers/vm/pagetable.c` flushes TLB after leaf-to-non-leaf splits for RV64 page tables.  
  `minix/servers/vm/pagetable.c` 在 RV64 叶子拆分后刷新 TLB。
- `minix/kernel/arch/riscv64/sbi.c` passes physical hart mask addresses to legacy SBI IPI/RFENCE calls.  
  `minix/kernel/arch/riscv64/sbi.c` 让旧 SBI IPI/RFENCE 传递物理 hart mask 地址。
- `minix/releasetools/riscv64/system.conf` adds MFS to the ramdisk service set.  
  `minix/releasetools/riscv64/system.conf` 为 ramdisk 服务集补充 MFS。
- `minix/kernel/arch/riscv64/kernel.c` defaults `ramimagename=imgrd` when the parameter buffer is empty.  
  `minix/kernel/arch/riscv64/kernel.c` 在参数缓冲为空时默认 `ramimagename=imgrd`。
- Former Critical #2: SATP root VA pointer is now passed via `SVMCTL_PTROOT_V` and used by the kernel (`minix/lib/libsys/sys_vmctl.c:30-40`,
  `minix/servers/vm/pagetable.c:2199-2208`, `minix/kernel/arch/riscv64/arch_do_vmctl.c:75-90`,
  `minix/kernel/arch/riscv64/memory.c:60-63`).  
  SATP 根地址 VA 指针已通过 `SVMCTL_PTROOT_V` 传递并被内核使用。
- Former Major #3: Timer interrupts now drive the kernel clock path (`minix/kernel/arch/riscv64/exception.c:110-112`,
  `minix/kernel/arch/riscv64/arch_clock.c:82-85`).  
  时钟中断已接入内核时钟路径。
- Former Critical #1: VMCTL transport is 64-bit on riscv64 (`minix/include/minix/com.h:370-395`,
  `minix/lib/libsys/sys_vmctl.c:3-52`, `minix/kernel/arch/riscv64/arch_do_vmctl.c:62-90`).  
  VMCTL 在 riscv64 上已使用 64-bit 字段传递 PTROOT。
- Former Major #12: FPU save/restore is implemented (`minix/kernel/arch/riscv64/klib.S:90-189`).  
  FPU 保存/恢复已实现（f0-f31 + fcsr）。
- Former Moderate #10: pagefault message is stack-local (`minix/kernel/arch/riscv64/exception.c:232-290`).  
  缺页消息已改为栈上局部变量。
- `minix/kernel/arch/riscv64/klib.S` uses `li/or` for `MF_FPU_INITIALIZED` to avoid out-of-range immediates in `ori`.  
  `minix/kernel/arch/riscv64/klib.S` 使用 `li/or` 设置 `MF_FPU_INITIALIZED`，避免 `ori` 立即数越界。
- `minix/kernel/arch/riscv64/bsp/virt/bsp_init.c` uses a local byte-swap to avoid `__bswapsi2` link errors.  
  `minix/kernel/arch/riscv64/bsp/virt/bsp_init.c` 改为本地字节翻转，避免链接缺失 `__bswapsi2`。
- `minix/include/arch/riscv64/include/machine/fpu.h` guards `SSTATUS_FS_*` to avoid redefinition with `archconst.h`.  
  `minix/include/arch/riscv64/include/machine/fpu.h` 为 `SSTATUS_FS_*` 增加宏保护，避免与 `archconst.h` 重定义。
- `minix/kernel/arch/riscv64/console.c` includes `kernel/kernel.h` to match kernel header include rules.  
  `minix/kernel/arch/riscv64/console.c` 改为包含 `kernel/kernel.h` 以符合内核头文件规则。
- `minix/drivers/tty/ns16550/Makefile` adds `gp.c` and `__global_pointer$` defsym for static RV64 builds.  
  `minix/drivers/tty/ns16550/Makefile` 增加 `gp.c` 与 `__global_pointer$` defsym，支持 RV64 静态链接。

## Vision / 愿景: pkgsrc on MINIX RV64

Goal / 目标: enable pkgsrc source builds on MINIX RV64 (not NetBSD binaries).  
在 MINIX RV64 上可源码构建 pkgsrc（非直接运行 NetBSD 二进制）。

Milestones / 里程碑:
1) Boot stability: QEMU boots to shell, PM/VM/RS/VFS stable, fork/exec/wait OK.  
   启动稳定：QEMU 进 shell，PM/VM/RS/VFS 稳定，fork/exec/wait 正常。
2) Userland ABI: RV64 ELF loading, ld.so relocations, syscalls/errno/signals OK.  
   用户态 ABI：RV64 ELF 装载、ld.so 重定位、syscall/errno/信号链路正确。
3) Toolchain & base tools: build tools + sysroot ready, bmake/sh/awk/sed/tar/gzip usable.  
   工具链与基础工具：交叉/本地工具链与 sysroot 就绪，bmake/sh/awk/sed/tar/gzip 可用。
4) pkgsrc port: MINIX/riscv64 mk files, bootstrap works, pkg_install/pkgconf builds.  
   pkgsrc 端口化：MINIX/riscv64 平台文件完善，bootstrap 完成，pkg_install/pkgconf 可构建。
5) Core libs: zlib/libarchive/libiconv/ncurses/libutil OK; networking if needed.  
   常用库：zlib/libarchive/libiconv/ncurses/libutil 可用；需要时补齐网络栈。
6) Regression & tests: smoke set + POSIX/VM/signals, QEMU automation.  
   回归与测试：smoke 套件 + POSIX/VM/信号测试，QEMU 自动化。
