# MINIX RISC-V 64-bit Port Guide / MINIX RISC-V 64-bit 移植指南

## 概述 / Overview

本文档记录 MINIX 在 RISC-V 64-bit 架构上的移植与构建运行方法，面向 QEMU virt 平台。  
This document describes the MINIX RISC-V 64-bit port, including build/run procedures
targeting the QEMU virt platform.

## 文档信息 / Document Info

**中文**
- 版本：1.25
- 最后更新：2026-02-19
- 适用范围：evbriscv64（QEMU virt）
- 文档性质：构建/运行/测试操作手册，不是开发计划

**English**
- Version: 1.25
- Last updated: 2026-02-19
- Scope: evbriscv64 (QEMU virt)
- Doc type: build/run/test manual, not a development plan

## 当前状态（截至 2026-02-19）/ Current Status (as of 2026-02-19)

**中文**
- 构建：可通过（需使用 workaround 组合，见本文构建命令与 `RISC64-STATUS.md`）
- 运行：QEMU 可稳定进入 shell，并通过 `echo SMOKE_OK`、`ps -aux`、`cat /proc/meminfo` 交互复测
- 系统版本已滚动至 `Minix Cat 4.0.0`（release profile: `4.0.0-riscv64`）。
- ramdisk 已内置 `neofetch`（`pfetch` 兼容包装），默认服务统计来源为 `/proc/service`。
- `obj.intrgcc` 独立构建链路已跑通：`tools(MKGCC=yes,MKGCCCMDS=yes) -> distribution -> QEMU`，不再出现 `Boot module not found: ds`
- 含盘 smoke 已复测：`virtio_blk_mmio` 在 `-i <disk image>` 轮廓下可正常初始化。
- `ping6` 稳定性已补强：`::1`（含不带 `-c` 的持续发送路径）与 dual-VM
  `fe80::...%vio0` 验收均通过，不再复现用户态 `SIGSEGV (bad addr 0x0)`。
- 公网连通性已在 QEMU user-net（slirp）模式验证通过：可从来宾 `ping 10.0.2.2`
  与 `ping 1.1.1.1`。
- Release 流水线已加入 QEMU 交互式 gate（`neofetch` + 关机链），并上传
  smoke 日志 artifact（失败也保留日志）。
- Nightly 流水线已固定 tag 格式为
  `nightly-master-riscv64-YYYYMMDD-<sha>`，并将 5 件产物同步上传到
  workflow artifacts 与 GitHub Release（prerelease）。
- 关键风险：`procfs` safecopy 回退噪声、SMP 未实现（详见 `issue.md`）
- A4 已闭环：`mkdisk` 产物在 S-mode U-Boot 链路下可从磁盘镜像启动到 shell。
- 进度估计：约 80%（启动链路与基础用户态已稳定，主要剩余问题集中在噪声收敛与稳定性增强）
- 代码更新（至 2026-01-06 01:00 前）：用户态 gp 初始化（crt0 + gp.c）、exec/ucontext 与
  VM 执行权限标记、IPC/缺页 ABI 修复（64 位地址、senda 参数顺序）。
- 文档更新：2026-02-16 追加 `memset` 递归修复后的 ramdisk 复测结果，`ps -aux` 不再复现 SIGSEGV。

**English**
- Build: passes with workaround flags (see commands below and `RISC64-STATUS.md`)
- Runtime: QEMU reaches a stable shell prompt and passes interactive retests:
  `echo SMOKE_OK`, `ps -aux`, and `cat /proc/meminfo`
- System version is now `Minix Cat 4.0.0` (release profile: `4.0.0-riscv64`).
- Ramdisk now includes `neofetch` (`pfetch` kept as compatibility wrapper),
  and the default service summary source is `/proc/service`.
- The isolated `obj.intrgcc` chain is validated end-to-end
  (`tools` with `MKGCC=yes` and `MKGCCCMDS=yes` -> `distribution` -> `QEMU`);
  `Boot module not found: ds` is no longer reproduced on this profile.
- With-disk smoke has been revalidated: `virtio_blk_mmio` initializes in `-i <disk image>` profile.
- `ping6` stability is strengthened: `::1` (including no-`-c` continuous mode) and
  dual-VM `fe80::...%vio0` checks pass without reproducing userland
  `SIGSEGV (bad addr 0x0)`.
- Public reachability is validated in QEMU user-net (slirp): guest can
  `ping 10.0.2.2` and `ping 1.1.1.1`.
- The release workflow now enforces an interactive QEMU gate
  (`neofetch` + shutdown chain) and uploads a smoke log artifact
  even on failure.
- The nightly workflow now uses the fixed tag format
  `nightly-master-riscv64-YYYYMMDD-<sha>` and publishes the same five build
  artifacts to both workflow artifacts and GitHub prerelease assets.
- Key risks: procfs safecopy fallback noise and SMP not implemented
  (see `issue.md`)
- A4 is closed: `mkdisk` artifacts now boot from disk image via the S-mode U-Boot chain.
- Progress estimate: ~80% (boot + basic userland path stabilized; remaining work is mostly
  noise/toolchain convergence)
- Code updates (through 2026-01-06 01:00): userland gp init (crt0 + gp.c),
  exec/ucontext + VM exec flags, IPC/pagefault ABI fixes (64-bit addr, senda arg order).
- Doc refresh: 2026-02-16 update adds post-`memset`-fix ramdisk retest; `ps` stack-top SIGSEGV
  signature is no longer reproduced in diskless profile.

## 系统要求 / System Requirements

### 主机系统 / Host System

**中文**
- Linux x86_64
- 至少 8GB RAM
- 20GB 可用磁盘空间
- GCC 交叉编译工具链支持

**English**
- Linux x86_64
- At least 8GB RAM
- 20GB free disk space
- GCC cross-compilation toolchain support

### 目标平台 / Target Platform

**中文**
- RISC-V 64-bit (RV64GC)
- QEMU virt 平台
- 支持 SBI (Supervisor Binary Interface)

**English**
- RISC-V 64-bit (RV64GC)
- QEMU virt platform
- SBI (Supervisor Binary Interface) supported

## 构建步骤 / Build Steps

### 1. 准备交叉编译工具链 / Prepare Toolchain

```bash
# 安装 RISC-V GCC 工具链（Ubuntu/Debian）
sudo apt-get install gcc-riscv64-unknown-elf

# 或从源码构建
git clone https://github.com/riscv/riscv-gnu-toolchain
cd riscv-gnu-toolchain
./configure --prefix=/opt/riscv --enable-multilib
make
```

**中文**
- 若已安装交叉编译器，可跳过源码构建。

**English**
- If a cross-compiler is already available, the source build step can be skipped.

### 2. 配置构建环境 / Configure Build Environment

```bash
cd /path/to/minix

# 设置构建变量
export TOOLDIR=/path/to/minix/obj.intrgcc/tooldir.$(uname -s)-$(uname -r)-$(uname -m)
export DESTDIR=/path/to/minix/obj.intrgcc/destdir.evbriscv64
```

**中文**
- 变量用于指定工具链与输出目录。
- 当前基线使用 `obj.intrgcc`；`obj` 路径仅作为历史记录，不用于当前构建/验证。

**English**
- These variables point to the toolchain and output directories.
- Active baseline uses `obj.intrgcc`; `obj` paths are legacy/historical only.

### 3. 构建交叉编译工具 / Build Tools

```bash
# 构建主机工具（需要较长时间）
MKPCI=no HOST_CFLAGS="-O -fcommon" HAVE_GOLD=no ./build.sh -U -m evbriscv64 tools

# 如需强制使用 GCC（避免自动选择 clang）
MKPCI=no HOST_CFLAGS="-O -fcommon" HAVE_GOLD=no \
./build.sh -U -m evbriscv64 \
  -V AVAILABLE_COMPILER=gcc -V ACTIVE_CC=gcc -V ACTIVE_CPP=gcc -V ACTIVE_CXX=gcc -V ACTIVE_OBJC=gcc \
  tools
```

**中文**
- 若工具链已在 `obj.intrgcc/tooldir.*` 中生成，可直接进入下一步。

**English**
- If `obj.intrgcc/tooldir.*` already exists, proceed to the distribution build.

### 4. 构建完整系统 / Build Distribution

```bash
# 构建 MINIX distribution（需要 2-4 小时）
# 当前可通过构建的组合：允许清单缺失/多余文件，适用于移植进行中阶段
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

**说明 / Notes**
- 若交叉编译器支持 `-march=rv64gc -mabi=lp64d`，可移除 `RISCV_ARCH_FLAGS`。  
  If the toolchain supports `-march=rv64gc -mabi=lp64d`, remove `RISCV_ARCH_FLAGS`.
- `CHECKFLIST_FLAGS='-m -e'` 允许缺失/多余文件，适用于当前不完整的 sets；若需严格检查，请移除该标志并恢复 `MKPIC/MKCXX/MKATF`。  
  `CHECKFLIST_FLAGS='-m -e'` allows missing/extra files while sets are incomplete; remove it
  and restore `MKPIC/MKCXX/MKATF` for strict checks.

## 本次移植与验证步骤（evbriscv64）/ Porting & Validation Steps (evbriscv64)

### 1. CSU 移植 / CSU Porting

**中文**
- 在 `lib/csu/arch/riscv64/` 增加 riscv64 入口与 Makefile 包装层，复用 `lib/csu/arch/riscv/*` 实现。
- 在 `lib/csu/arch/riscv64/machine/asm.h` 与 `lib/csu/arch/riscv/riscv64/machine/asm.h`
  补齐 `PTR_SCALESHIFT`，避免未安装系统头时缺宏。

**English**
- Add riscv64 entry and Makefile wrappers under `lib/csu/arch/riscv64/`, reusing
  `lib/csu/arch/riscv/*` implementations.
- Add `PTR_SCALESHIFT` in `lib/csu/arch/riscv64/machine/asm.h` and
  `lib/csu/arch/riscv/riscv64/machine/asm.h` to avoid missing macros before headers install.

### 2. CSU 编译验证 / CSU Build Check

```bash
MAKEFLAGS="-de -m $PWD/share/mk" \
MACHINE=evbriscv64 MACHINE_ARCH=riscv64 NETBSDSRCDIR="$PWD" \
TOOLDIR="$PWD/obj.intrgcc/tooldir.$(uname -s)-$(uname -r)-$(uname -m)" \
DESTDIR="$PWD/obj.intrgcc/destdir.evbriscv64" \
AVAILABLE_COMPILER=gcc ACTIVE_CC=gcc ACTIVE_CPP=gcc ACTIVE_CXX=gcc ACTIVE_OBJC=gcc \
RISCV_ARCH_FLAGS='-march=RV64IMAFD -mcmodel=medany' \
"$PWD/obj.intrgcc/tooldir.$(uname -s)-$(uname -r)-$(uname -m)/bin/nbmake" \
  -C lib/csu dependall
```

### 3. 工具链可用性验证 / Toolchain Check

```bash
obj.intrgcc/tooldir.*/bin/riscv64-elf32-minix-gcc -dumpmachine
# 期望输出：riscv64-elf32-minix
# Expected: riscv64-elf32-minix
```

### 4. 完整构建（跳过 libobjc/libgomp/C++）/ Full Build (skip libobjc/libgomp/C++)

```bash
unset EXTERNAL_TOOLCHAIN
HOST_CC="cc -Wno-implicit-int -Wno-implicit-function-declaration" \
MKPCI=no HOST_CFLAGS="-O -fcommon" HAVE_GOLD=no HAVE_LLVM=no MKLLVM=no \
./build.sh -u -j"$(nproc)" -m evbriscv64 \
  -V AVAILABLE_COMPILER=gcc -V ACTIVE_CC=gcc -V ACTIVE_CPP=gcc -V ACTIVE_CXX=gcc -V ACTIVE_OBJC=gcc \
  -V RISCV_ARCH_FLAGS='-march=RV64IMAFD -mcmodel=medany' \
  -V NOGCCERROR=yes -V MKPIC=no -V MKPICLIB=no -V MKPICINSTALL=no \
  -V MKGCC=yes -V MKGCCCMDS=no -V MKLIBSTDCXX=no \
  -V MKCXX=no -V MKLIBCXX=no -V MKATF=yes -V MKKYUA=yes -V USE_PCI=no \
  -V MKLIBOBJC=no -V MKLIBGOMP=no \
  -V CHECKFLIST_FLAGS='-m -e' \
  distribution
```

**说明 / Notes**
- `MKLIBOBJC=no` 与 `MKLIBGOMP=no` 用于避开 `pthread.h` 未齐全导致的构建失败。  
  `MKLIBOBJC=no` and `MKLIBGOMP=no` avoid failures from incomplete `pthread.h`.
- `NOGCCERROR=yes` 用于屏蔽旧 GCC 不识别的版本化警告。  
  `NOGCCERROR=yes` suppresses versioned warning flags on older GCC.

### 5. 测试与当前结果 / Tests and Current Results

```bash
./minix/tests/riscv64/run_tests.sh all
```

**中文（截至 2026-02-18）**
- 用户态编译测试：通过（脚本使用 in-tree toolchain + sysroot，统一 `-std=gnu99`）。
- 内核启动：通过，日志可见 `MINIX` banner、`VFS: init_root done`、`init: exec /bin/sh /etc/rc`。
- 交互冒烟：通过，在 QEMU shell 中执行 `echo SMOKE_OK` 返回 `SMOKE_OK`。
- 增量复测：通过，`ps -aux` 返回进程列表且不再 SIGSEGV；`cat /proc/meminfo` 可正常输出。
- 含盘复测：通过，`-i <disk image>` 轮廓下 `virtio_blk_mmio` 报告 capacity/initialized。
- IPv6 复测：通过，`/sbin/ping6 ::1`（不带 `-c`）与 dual-VM
  `fe80::...%vio0` 均不再复现 `SIGSEGV`。
- 公网可达性：通过，QEMU user-net（slirp）模式下可 `ping 10.0.2.2` 与
  `ping 1.1.1.1`。
- 已知未完成：SMP 仍为 skip（not yet implemented）；`procfs` safecopy 噪声仍待收敛。

**English (as of 2026-02-18)**
- Userland compile tests: pass (in-tree toolchain + sysroot, `-std=gnu99`).
- Kernel boot: pass; logs show `MINIX` banner, `VFS: init_root done`, and `init: exec /bin/sh /etc/rc`.
- Interactive smoke: pass; running `echo SMOKE_OK` in QEMU shell returns `SMOKE_OK`.
- Incremental retest: pass; `ps -aux` no longer crashes and `cat /proc/meminfo` returns expected output.
- With-disk retest: pass; in `-i <disk image>` profile, `virtio_blk_mmio` reports
  capacity/initialized.
- IPv6 retest: pass; `/sbin/ping6 ::1` (no `-c`) and dual-VM
  `fe80::...%vio0` no longer reproduce `SIGSEGV`.
- Public reachability: pass in QEMU user-net (slirp) with successful
  `ping 10.0.2.2` and `ping 1.1.1.1`.
- Remaining gaps: SMP remains skipped (not yet implemented); procfs safecopy noise
  still needs convergence.

#### 5.1 启动稳定化验证记录 / Boot Stabilization Validation

1. 非交互验证 / Non-interactive check:
   - `timeout 120 ./minix/scripts/qemu-riscv64.sh -k obj.intrgcc/minix/kernel/kernel -B obj.intrgcc/destdir.evbriscv64 > /tmp/qemu-fix20.log 2>&1 || true`
2. 关键日志断言 / Key log assertions:
   - 出现 `VFS: init_root done`
   - 出现 `init: exec /bin/sh /etc/rc`
   - 未出现 `VM: pagefault: SIGSEGV ... bad addr ...`
3. 交互验证 / Interactive check:
   - 进入 `#` 提示符后执行 `echo SMOKE_OK`
   - 输出 `SMOKE_OK`
4. 结论 / Conclusion:
   - 启动链路已从“早期复位/崩溃”阶段前进到“可交互 shell”阶段。

#### 5.2 测试脚本启动判定说明 / Boot Test Criteria

`run_tests.sh` 的内核启动测试通过以下条件之一判断成功：  
`run_tests.sh` considers boot successful if any of the following is present:

```bash
grep -q "MINIX" /tmp/boot_test.log
# 或 / or
grep -q "rv64: arch_post_init" /tmp/boot_test.log
# 或 / or
grep -q "rv64: arch_boot_proc VM" /tmp/boot_test.log
```

当前基线日志已输出 `MINIX`，并可继续到 `init`/`sh`。  
Current baseline logs include `MINIX` and continue to `init`/`sh`.

可选处理方式 / Options:
- 建议保留现有 `MINIX` / `arch_post_init` / `arch_boot_proc VM` 作为三重判定。  
  Keep the existing `MINIX` / `arch_post_init` / `arch_boot_proc VM` checks.
- 额外可加入 `VFS: init_root done` 以覆盖用户态前置阶段。  
  Optionally add `VFS: init_root done` to cover pre-userland milestone.

#### 5.3 运行判定标准（最低可用）/ Runtime Pass Criteria (Minimum)

通过条件（任一满足即可）/ Pass criteria (any one):
1) `/tmp/boot_test.log` 出现 `rv64: arch_post_init` 或 `rv64: arch_boot_proc VM`  
   `/tmp/boot_test.log` shows `rv64: arch_post_init` or `rv64: arch_boot_proc VM`
2) 未出现 `System reset...` 且 OpenSBI banner 不重复  
   No `System reset...` and OpenSBI banner does not repeat

失败条件（任一满足即失败）/ Fail criteria (any one):
1) `rv64: kernel_main` 后出现 `System reset...` 并重复 OpenSBI banner  
   `rv64: kernel_main` followed by `System reset...` and repeated OpenSBI banner
2) 出现 `pagefault in VM` 或 `panic`  
   `pagefault in VM` or `panic` appears

当前状态：已满足最低通过条件（可达 shell 并可执行交互命令）；详见 `RISC64-STATUS.md`。  
Current status: minimum pass criteria met (shell reachable and interactive command works); see `RISC64-STATUS.md`.

#### 5.4 2026-02-16 交互复测补充 / 2026-02-16 Interactive Retest Addendum

复测命令 / Retest commands:
```bash
./minix/scripts/qemu-riscv64.sh -s \
  -k obj.intrgcc/minix/kernel/kernel \
  -B obj.intrgcc/destdir.evbriscv64
```

注意 / Note:
- 开发调试时优先使用 `obj.intrgcc/minix/kernel/kernel`；`obj*/destdir.../boot/minix/.temp/kernel`
  可能滞后于最近一次内核重编译，导致来宾中仍显示旧版本号。

来宾内命令 / In-guest commands:
```sh
ps -aux
cat /proc/meminfo
```

结论 / Result:
- `ps -aux`：不再触发此前 `pc in memset` 的栈顶 SIGSEGV 签名。  
  `ps -aux`: no longer reproduces the previous stack-top SIGSEGV with `pc` in `memset`.
- `cat /proc/meminfo`：可返回数据；仍可见一次可恢复 safecopy fallback（已在 `issue.md` #17 跟踪）。  
  `cat /proc/meminfo`: returns data; one recoverable safecopy fallback is still observable (tracked in `issue.md` #17).

#### 5.5 2026-02-16 `obj.intrgcc` 全链路验证 / 2026-02-16 `obj.intrgcc` End-to-End Validation

构建命令 / Build commands:
```bash
# 1) tools (isolated objdir)
MKPCI=no HOST_CFLAGS="-O -fcommon" HAVE_GOLD=no HAVE_LLVM=no MKLLVM=no \
./build.sh -U -m evbriscv64 -O obj.intrgcc \
  -V AVAILABLE_COMPILER=gcc -V ACTIVE_CC=gcc -V ACTIVE_CPP=gcc -V ACTIVE_CXX=gcc -V ACTIVE_OBJC=gcc \
  tools

# 2) distribution (same objdir; workaround profile)
MKPCI=no HOST_CFLAGS="-O -fcommon" HAVE_GOLD=no HAVE_LLVM=no MKLLVM=no \
./build.sh -U -u -j"$(nproc)" -m evbriscv64 -O obj.intrgcc \
  -V AVAILABLE_COMPILER=gcc -V ACTIVE_CC=gcc -V ACTIVE_CPP=gcc -V ACTIVE_CXX=gcc -V ACTIVE_OBJC=gcc \
  -V RISCV_ARCH_FLAGS='-march=RV64IMAFD -mcmodel=medany' \
  -V NOGCCERROR=yes \
  -V MKPIC=no -V MKPICLIB=no -V MKPICINSTALL=no \
  -V MKCXX=no -V MKLIBSTDCXX=no -V MKATF=no \
  -V USE_PCI=no \
  -V CHECKFLIST_FLAGS='-m -e' \
  distribution
```

QEMU 验证命令 / QEMU validation command:
```bash
./minix/scripts/qemu-riscv64.sh \
  -k obj.intrgcc/minix/kernel/kernel \
  -B obj.intrgcc/destdir.evbriscv64
```

结果 / Result:
- 成功进入 shell，且 `ds` 等 boot modules 可正常加载，不再复现 `Boot module not found: ds`。  
  Shell prompt is reachable and boot modules (`ds` included) load correctly; `Boot module not found: ds` is no longer observed.
- 该链路可作为“完全自举可重建”（不依赖从 `obj/` 注入）的基线。  
  This chain is now a practical baseline for fully self-contained rebuilds without injecting artifacts from `obj/`.

#### 5.6 2026-02-16 `obj.intrgcc` 完全自举收敛（内建 gcc 命令）/ 2026-02-16 `obj.intrgcc` Fully Self-Hosted Closure (in-tree gcc commands)

构建命令 / Build commands:
```bash
# 1) tools with in-tree GCC frontends enabled
MKPCI=no HOST_CFLAGS='-O -fcommon' HAVE_GOLD=no HAVE_LLVM=no MKLLVM=no \
./build.sh -U -m evbriscv64 -O obj.intrgcc \
  -V AVAILABLE_COMPILER=gcc -V ACTIVE_CC=gcc -V ACTIVE_CPP=gcc -V ACTIVE_CXX=gcc -V ACTIVE_OBJC=gcc \
  -V MKGCC=yes -V MKGCCCMDS=yes \
  tools

# 2) distribution on the same objdir
MKPCI=no HOST_CFLAGS='-O -fcommon' HAVE_GOLD=no HAVE_LLVM=no MKLLVM=no \
./build.sh -U -u -j"$(nproc)" -m evbriscv64 -O obj.intrgcc \
  -V AVAILABLE_COMPILER=gcc -V ACTIVE_CC=gcc -V ACTIVE_CPP=gcc -V ACTIVE_CXX=gcc -V ACTIVE_OBJC=gcc \
  -V RISCV_ARCH_FLAGS='-march=RV64IMAFD -mcmodel=medany' \
  -V NOGCCERROR=yes \
  -V MKPIC=no -V MKPICLIB=no -V MKPICINSTALL=no \
  -V MKCXX=no -V MKLIBSTDCXX=no -V MKATF=no \
  -V USE_PCI=no \
  -V CHECKFLIST_FLAGS='-m -e' \
  distribution
```

工具链产物校验 / Toolchain artifact checks:
```bash
TOOLDIR=$(echo obj.intrgcc/tooldir.*-x86_64)
ls -l \
  "$TOOLDIR/bin/riscv64-elf32-minix-gcc" \
  "$TOOLDIR/bin/riscv64-elf32-minix-c++" \
  "$TOOLDIR/bin/riscv64-elf32-minix-cpp" \
  "$TOOLDIR/bin/riscv64-elf32-minix-g++"
file \
  "$TOOLDIR/bin/riscv64-elf32-minix-gcc" \
  "$TOOLDIR/bin/riscv64-elf32-minix-c++" \
  "$TOOLDIR/bin/riscv64-elf32-minix-cpp" \
  "$TOOLDIR/bin/riscv64-elf32-minix-g++"
```

QEMU 复测命令 / QEMU retest command:
```bash
timeout 45 ./minix/scripts/qemu-riscv64.sh \
  -k obj.intrgcc/minix/kernel/kernel \
  -B obj.intrgcc/destdir.evbriscv64
```

结果 / Result:
- `riscv64-elf32-minix-{gcc,c++,cpp,g++}` 在 `obj.intrgcc/tooldir.*/bin` 内均为本地 ELF 可执行文件。  
  `riscv64-elf32-minix-{gcc,c++,cpp,g++}` are local ELF executables under `obj.intrgcc/tooldir.*/bin`.
- `distribution` 在同一 `obj.intrgcc` 完成，且 QEMU 可达 shell（`#`）；`Boot module not found: ds` 未复现。  
  `distribution` completes on the same `obj.intrgcc`; QEMU reaches shell (`#`) and `Boot module not found: ds` is not reproduced.

#### 5.7 最小回归门禁（自动化，多轮）/ Minimum Regression Gate (Automated, Multi-Run)

建议将以下三项固定为最小门禁：
Recommended minimum gate chain:

1) safecopy 首错定性 / safecopy first-error triage:
```bash
python3 ./minix/tests/riscv64/safecopy_triage.py /tmp/qemu-smoke.log
```

2) 多轮 smoke（无盘 + 带盘）/ multi-run smoke (diskless + with-disk):
```bash
./minix/tests/riscv64/multi_smoke_gate.sh \
  --kernel obj.intrgcc/minix/kernel/kernel \
  --destdir obj.intrgcc/destdir.evbriscv64 \
  --rounds 2 --timeout 90
```

3) 可重复构建门禁（隔离 objdir）/ reproducible build gate (isolated objdir):
```bash
./minix/tests/riscv64/repro_build_gate.sh \
  --objdir obj.repro \
  --smoke-rounds 2
```

脚本说明 / Script notes:
- `multi_smoke_gate.sh` 要求每轮满足：
  shell 可达、无 fatal 签名、`safecopy_triage` 不判定为潜在一致性问题；
  带盘轮次还要求 `virtio-blk-mmio: initialized`，且不能出现历史启动失败签名。
  同时默认执行运行时命令探针（`qemu_runtime_probe.py`），要求
  `cat /proc/meminfo`、`ps -aux`、`minix-service sysctl srv_status` 返回成功；
  带盘轮次还需 `/dev/c0d0` 存在。
  Runtime command probe is enabled by default and requires
  `cat /proc/meminfo`, `ps -aux`, `minix-service sysctl srv_status` to succeed;
  with-disk rounds additionally require `/dev/c0d0`.
  默认行为为“每轮独立带盘镜像”（例如 `...round1.img`、`...round2.img`）；
  如需跨轮复用单一镜像，显式传 `--reuse-disk`。
  如需临时关闭运行时探针，使用 `--no-runtime-probe`；
  可通过 `--runtime-timeout` / `--runtime-cmd-timeout` 调整探针超时。
- `repro_build_gate.sh` 执行受控参数的 `tools -> distribution -> multi_smoke_gate`，
  并检查 `external/gpl3/binutils/patches/0011-riscv-relax-compat.patch`
  为 tracked 文件，用于避免“手工补丁/手工拷贝产物”依赖。
  其 relax 兼容探针使用
  `ld -r --whole-archive ... --no-whole-archive`，
  确保实际覆盖 archive 成员链接路径。
- `run_tests.sh` 新增 `gate` 子命令，可直接触发多轮门禁：
  `./minix/tests/riscv64/run_tests.sh gate`

## 已知问题与解决方案 / Known Issues and Workarounds

### 0. 运行时关键问题（持续跟踪）/ Runtime Key Issues (Ongoing)

1. **PTROOT/地址空间切换链路需持续回归**  
   - 现状：启动路径已稳定到 shell，但页表根切换相关修复仍需持续压力验证。  
   - 建议：保留高频 QEMU 回归并关注 `sys_vmctl`/`pt_bind` 路径。  
   **PTROOT/address-space handoff needs continued regression coverage**  
   - Status: boot is stable to shell, but PTROOT-related fixes still need stress validation.
   - Action: keep frequent QEMU regressions around `sys_vmctl`/`pt_bind`.

2. **UART 阻塞读缺少回复**  
   - 现状：代码侧已补齐挂起回复逻辑，需继续运行时验证。  
   - 建议：结合 console 交互与高频读写场景回归。  
   **UART blocking read lacks deferred reply**  
   - Status: pending-reply logic is in tree; keep validating with runtime stress.

3. **leaf → non-leaf 变换未刷新 TLB**  
   - 现状：拆分后刷新逻辑已补充，需继续观察偶发映射异常。  
   - 建议：在 VM 压测下验证无陈旧 TLB 影响。  
   **Leaf→non-leaf split lacks TLB flush**  
   - Status: flush logic added; runtime validation is still required.

4. **SBI legacy IPI/fence 仍传递 VA**  
   - 现状：已按 PA 路径修复，待后续 SMP/中断链路实测。  
   - 建议：SMP 可用后优先做 IPI/fence 回归。  
   **SBI legacy IPI/fence passes VA**  
   - Status: PA-side fix is in tree; verify in SMP-related runtime tests.

5. **virtio 启动路径含盘复测已通过（A3）**
   - 现状：`-i <disk image>` 轮廓下 `virtio_blk_mmio` 已可初始化（capacity/initialized），未复现 `device not found`/`couldn't start`。
   - 建议：将含盘启动检查纳入常规 smoke，持续防回归。
   **Virtio startup path with-disk retest passed (A3)**
   - Status: in `-i <disk image>` profile, `virtio_blk_mmio` initializes successfully and no longer reproduces `device not found`/`couldn't start`.
   - Action: keep the with-disk startup check in regular smoke runs to prevent regressions.

6. **in-tree linker `R_RISCV_RELAX` 兼容性（#24，已缓解）**  
   - 现状：已加入 `external/gpl3/binutils/patches/0011-riscv-relax-compat.patch`，
     让 in-tree `ld` 将 `R_RISCV_RELAX` 视为 hint/no-op。  
   - 验证：`ld -r --whole-archive obj.intrgcc/destdir.evbriscv64/usr/lib/libaudiodriver.a --no-whole-archive -o /tmp/libaudiodriver.whole.o`
     使用 in-tree `ld` 可通过，不再触发 `unrecognized relocation (0x33)`。  
   **in-tree linker compatibility with `R_RISCV_RELAX` (#24, mitigated)**  
   - Status: `external/gpl3/binutils/patches/0011-riscv-relax-compat.patch` handles
     `R_RISCV_RELAX` as a linker hint/no-op in in-tree `ld`.
   - Validation: in-tree `ld` now links RELAX-bearing archives without
     `unrecognized relocation (0x33)`.

7. **GCC-only 增量构建 ABI 参数兼容性（#25，已修复）**  
   - 现状：默认参数已收敛到 `-march=RV64IMAFD -mcmodel=medany`，不再默认依赖
     `-mabi=lp64d`。  
   - 建议：新脚本/新组件继续复用同一参数基线，避免局部回归。  
   **GCC-only incremental ABI-flag compatibility (#25, fixed)**  
   - Status: default flags now converge on `-march=RV64IMAFD -mcmodel=medany`,
     without requiring `-mabi=lp64d` by default.
   - Action: keep new scripts/components on the same baseline to avoid regressions.

8. **lwIP raw socket 权限误拒绝（#34，已修复）**
   - 现状：`service lwip` 已补充 `pm` IPC 权限，`ping/ping6` 不再因
     `Permission denied` 失败。
   - 建议：后续如调整 `system.conf`，保持 `lwip -> pm` IPC 权限不回退。
   **lwIP raw-socket permission false-denial (#34, fixed)**
   - Status: `service lwip` now includes `pm` in IPC permissions; `ping/ping6`
     no longer fail with `Permission denied`.
   - Action: keep `lwip -> pm` IPC permission intact when editing `system.conf`.

9. **`ping6` scoped link-local 崩溃（#35，已修复）**
   - 现状：Minix 路径已改为单调时钟软定时发送节拍 + `SO_RCVTIMEO` 接收超时；
     `ping6 ::1`（不带 `-c`）与 dual-VM `fe80::...%vio0` 验收均通过。
   - 建议：将 `::1` 连续发送与 dual-VM link-local 场景纳入常规回归门禁。
   **`ping6` scoped link-local crash (#35, fixed)**
   - Status: Minix path now uses monotonic soft-timer pacing plus
     `SO_RCVTIMEO`; both no-count `ping6 ::1` and dual-VM
     `fe80::...%vio0` checks pass.
   - Action: keep both scenarios in regular regression gates.

10. **QEMU bridge 外网模式依赖宿主预配置（网络验收注意项）**
   - 现状：若宿主缺少 bridge helper 配置（例如无 `/etc/qemu/bridge.conf`），
     `-netdev bridge` 会直接失败。
   - 建议：先用 slirp 完成公网可达性验收，再按宿主网络拓扑补齐 bridge 方案。
   **QEMU bridge external networking requires host preconfiguration**
   - Status: without host bridge-helper setup (for example missing
     `/etc/qemu/bridge.conf`), `-netdev bridge` fails immediately.
   - Action: validate reachability with slirp first, then enable bridge mode
     with host-specific bridge setup.

详细证据与文件行号见 `issue.md`。  
See `issue.md` for evidence and file/line references.

### 1. LLVM 编译问题 / LLVM Build Issues

**问题 / Problem**: LLVM 在 RISC-V 64-bit 上编译失败。  
**解决 / Fix**: 使用 `HAVE_LLVM=no MKLLVM=no` 跳过 LLVM 构建。

### 2. 交叉编译器 `-march=rv64gc` 不兼容 / `-march=rv64gc` Compatibility

**问题 / Problem**: 部分交叉编译器/本地 tooldir 的 GCC 不接受 `-march=rv64gc`。  
**解决 / Fix**: 使用 `-V RISCV_ARCH_FLAGS='-march=RV64IMAFD -mcmodel=medany'`。

### 3. distribution 清单检查失败 / distribution checkflist Failure

**问题 / Problem**: `checkflist` 报告缺失/多余文件，导致 distribution 失败。  
**解决 / Fix**: 移植阶段可用 `-V CHECKFLIST_FLAGS='-m -e'` 临时放宽；
完成 sets 后移除该标志并恢复 `MKPIC/MKCXX/MKATF`。

### 4. C++ 库目录问题（开启 C++ 时）/ C++ Include Directories (when C++ enabled)

若启用 `MKCXX/MKLIBSTDCXX`，创建 distribution 时可能需要手动创建：  
When `MKCXX/MKLIBSTDCXX` is enabled, create:

```bash
mkdir -p $DESTDIR/usr/include/g++/bits/riscv32
mkdir -p $DESTDIR/usr/include/g++/bits/riscv64
```

### 5. 静态链接需要 __global_pointer$ 兼容层 / Static Linking Needs __global_pointer$ Stub

**问题 / Problem**: 部分工具链仅导出 `_gp`，静态链接缺少 `__global_pointer$`。  
**解决 / Fix**: 目前在多个用户态组件内使用 `gp.c` 提供符号；长期建议在 crt0 或链接脚本中统一处理（详见 `issue.md`）。

## 架构特定实现 / Architecture Details

### 内存映射（QEMU virt 平台）/ Memory Map (QEMU virt)

| 地址范围 / Address Range | 设备 / Device | 描述 / Description |
|--------------------------|--------------|--------------------|
| 0x02000000               | CLINT        | Core Local Interruptor |
| 0x0C000000               | PLIC         | Platform-Level Interrupt Controller |
| 0x10000000               | UART         | NS16550 serial console |
| 0x10001000               | VirtIO       | MMIO devices |
| 0x80000000               | RAM          | Physical memory start |

### SBI 接口使用 / SBI Usage

**中文**
- 系统使用 SBI 进行控制台输出、定时器管理与关机。

**English**
- SBI is used for console I/O, timer management, and system shutdown.

## 测试 / Tests

### 运行 RISC-V 特定测试 / Run RISC-V Tests

```bash
cd minix/tests/riscv64
./run_tests.sh all
```

可用的测试类别 / Available categories:
- `csr` - 控制和状态寄存器 / CSRs
- `atomic` - 原子操作 / Atomic ops
- `sbi` - SBI 接口调用 / SBI calls
- `memory` - 内存管理 / Memory management
- `trap` - 陷阱处理 / Trap handling
- `timer` - 定时器和 CLINT / Timer and CLINT
- `ipc` - 进程间通信 / IPC
- `vm` - 虚拟内存 / Virtual memory

### 使用 QEMU 运行 / Run in QEMU

```bash
# 基本运行 / Basic run
./minix/scripts/qemu-riscv64.sh -k obj.intrgcc/minix/kernel/kernel -B obj.intrgcc/destdir.evbriscv64

# 调试模式 / Debug mode
./minix/scripts/qemu-riscv64.sh -d -k obj.intrgcc/minix/kernel/kernel -B obj.intrgcc/destdir.evbriscv64

# 使用 GDB 调试 / GDB
./minix/scripts/gdb-riscv64.sh obj.intrgcc/minix/kernel/kernel

# 交互冒烟 / Interactive smoke
# 在 shell 提示符下执行：echo SMOKE_OK
```

网络备注 / Networking notes:
- 默认 `qemu-riscv64.sh -n` 使用 user-net（slirp），可先用于公网连通性验收。
  Default `qemu-riscv64.sh -n` uses user-net (slirp), which is suitable for
  first-pass public reachability checks.
- 若出现 `hostfwd=tcp::2222-:22` 端口占用，可改用
  `/tmp/qemu-riscv64-nohostfwd.sh` 或先释放宿主 2222 端口。
  If `hostfwd=tcp::2222-:22` conflicts, use `/tmp/qemu-riscv64-nohostfwd.sh`
  or free host port 2222 first.

### 使用 mkdisk 进行 U-Boot 纯磁盘启动 / Disk-only Boot with mkdisk + U-Boot

```bash
# 1) 生成镜像（使用 obj.intrgcc 产物）
OUTPUT=/tmp/minix-rv64-diskonly.img \
DESTDIR=/home/donz/minix/obj.intrgcc \
minix/releasetools/riscv64/mkdisk.sh

# 2) 以 OpenSBI + U-Boot S-mode 方式从磁盘启动
qemu-system-riscv64 -machine virt -m 256M -nographic \
  -bios default \
  -kernel /usr/lib/u-boot/qemu-riscv64_smode/uboot.elf \
  -drive if=none,file=/tmp/minix-rv64-diskonly.img,format=raw,id=hd0 \
  -device virtio-blk-device,drive=hd0
```

预期日志关键字 / Expected key log markers:
- `Found U-Boot script /boot.scr.uimg`
- `## Starting application at 0x80200000 ...`
- `rv64: kernel_main`
- `MINIX 4.0.0`
- `virtio-blk-mmio: initialized`

说明 / Notes:
- `mkdisk.sh` 会在 root 分区放置 `/boot/kernel.bin`（包含 BSS 内容）、
  `/boot/minix.modinfo` 与 `/boot/modules/*`，并由 `boot.scr` 执行 `go 0x80200000`。
- 请使用上面的 S-mode U-Boot 链路；直接用
  `/usr/lib/u-boot/qemu-riscv64/uboot.elf` 可能进入 M-mode 路径并触发异常。

## 构建输出 / Build Outputs

1. **交叉编译工具链 / Toolchain**：`obj.intrgcc/tooldir.*/bin/riscv64-elf32-minix-*`
2. **内核镜像 / Kernel**：`obj.intrgcc/minix/kernel/kernel`
3. **系统库 / Libraries**：`obj.intrgcc/destdir.evbriscv64/usr/lib/`
4. **服务器程序 / Servers**：`obj.intrgcc/destdir.evbriscv64/sbin/`
5. **用户程序 / User programs**：`obj.intrgcc/destdir.evbriscv64/usr/bin/`

## GitHub Actions Release Pipeline / GitHub Actions 自动发布流水线

仓库已提供自动构建并发布到 GitHub Release 的流水线：  
`/.github/workflows/release-riscv64.yml`

触发方式 / Triggers:
- `push` 到 tag（模式：`v*`）
- 手动触发 `workflow_dispatch`（需输入 tag）

流水线行为 / Pipeline behavior:
1. 安装宿主依赖并按 `obj.intrgcc` 基线执行 `tools -> distribution`
2. 调用 `minix/releasetools/riscv64/mkdisk.sh` 生成磁盘镜像并压缩
3. 导出内核 ELF 与开发用 sysroot（头文件/库）
4. 生成统一 `SHA256SUMS.txt`
5. 执行 QEMU 交互式 gate（`neofetch` + 关机链），失败则阻断发布
6. 上传 QEMU smoke 日志到 workflow artifact（步骤 `if: always()`）
7. 自动创建/更新 GitHub Release 并上传以下产物

构建产物命名规范（含构建提交 hash）/ Artifact naming (with commit hash):
- `minix-cat-<tag>-<shortsha>-riscv64.img`
- `minix-cat-<tag>-<shortsha>-riscv64.img.gz`
- `minix-cat-<tag>-<shortsha>-riscv64.elf`
- `minix-cat-<tag>-<shortsha>-riscv64-sysroot.tar.gz`
- `SHA256SUMS.txt`

注意 / Notes:
- Release workflow 依赖 GitHub Actions 默认 `GITHUB_TOKEN`（`contents: write`）。
- 若首次启用失败，请确认仓库 Actions 权限允许 workflow 写 Release。
- `shortsha` 来自当前构建提交（`git rev-parse --short=12 $GITHUB_SHA`）。
- 构建时间较长（完整 `distribution`），建议通过 tag 触发正式发布。
- 若发布在 QEMU gate 阶段失败，请优先下载
  `riscv64-qemu-smoke-log-<tag>-<sha>` 排查来宾输出。
- 为降低 GitHub hosted runner 磁盘不足风险，workflow 在安装依赖前会执行
  `Reclaim runner disk space`，清理预装大体积组件（dotnet/android/ghc/CodeQL）、
  swap、docker 残留与 apt 缓存，并打印清理前后磁盘占用。
- 若 `Build tools` 阶段出现
  `GAS does not know what format to use for target riscv-ucb-minix`，
  需要确保 `external/gpl3/binutils/patches/0012-riscv-gas-minix-target-format.patch`
  已包含在当前分支（该补丁为 CI 的 fresh dist 提供 `riscv*-*-minix*` 目标格式映射）。
- 若 `Build tools` 阶段出现
  `*** Configuration riscv-ucb-minix not supported`（`configure-gcc`），
  需要确保 `external/gpl3/gcc/patches/0005-riscv-minix-config.patch`
  已包含在当前分支（该补丁为 fresh gcc dist 增加 `riscv*-*-minix*` 目标配置）。
- 若 `distribution` 阶段在 `lib/csu` 出现
  `*** buffer overflow detected ***` 且后续报
  `internal compiler error: Aborted (program as)`，
  说明 host 上的 fortify/stack-protector 与旧工具链组合不兼容。
  当前 workflow 已在 `Build tools`/`Build distribution` 使用
  `HARDENING_OFF="-U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=0 -fno-stack-protector"`
  作为 CI 规避参数。
- 若 `distribution` 阶段在 `bind/dig` 链接时报
  `cannot find -lgcc` / `cannot find -lgcc_eh`，
  需要保证该步启用 `-V MKGCC=yes -V MKGCCCMDS=no`，以在 `destdir/usr/lib`
  生成目标侧 `libgcc.a` / `libgcc_eh.a`（CI clean 环境默认 `MKGCC=no`）。
- 若 `distribution` 阶段在 `lua` 动态链接时报
  `ld: cannot find -lgcc_s`，不要在该 CI 路径里强制
  `-V MKPIC=no -V MKPICLIB=no -V MKPICINSTALL=no`，否则 `libgcc_s`
  不会按期望生成/安装；当前 release workflow 已移除这三个覆盖参数。
- 若 `distribution` 阶段进一步报
  `.../usr/lib/libgcc_s.so: undefined reference to 'mprotect'`，
  需要确保 RISC-V `libgcc` 的 `enable-execute-stack` 选择为
  `enable-execute-stack-empty.c`（而不是 `...-mprotect.c`），以避免在
  MINIX 目标侧引入不可解析的 `mprotect` 依赖。
- 若 `distribution` 阶段在 `libexec/ld.elf_so` 报
  `R_TYPESZ` 隐式声明，以及 `ADDR`/`TLS_DTPMOD`/`TLS_DTPREL`
  未定义（`mdreloc.c`），需要将 RISC-V 重定位 case 按 `ELFSIZE`
  映射到显式 `R_TYPE(64/32)`、`R_TYPE(TLS_DTPMOD64/32)`、
  `R_TYPE(TLS_DTPREL64/32)`，并为 `TLS_DTV_OFFSET` 提供兜底定义。
- 若 `distribution` 阶段在 `virtio_net_mmio` 链接时报
  `ld: cannot find -lvirtio_mmio`，需要确保构建链的系统库阶段会提前构建并
  安装 `libvirtio_mmio`：
  - `lib/Makefile`（distribution 实际使用的库构建入口）中为
    `riscv64/riscv` 添加 `../minix/lib/libvirtio_mmio`
  - `minix/lib/Makefile` 同步包含 `libvirtio_mmio`

## GitHub Actions Nightly Pipeline / GitHub Actions 每日构建流水线

Nightly workflow 文件：`/.github/workflows/nightly-riscv64.yml`

触发方式 / Triggers:
- `schedule`（UTC `20 18 * * *`，每日一次）
- 手动触发 `workflow_dispatch`

Nightly 行为 / Pipeline behavior:
1. 与 release 相同的 `obj.intrgcc` 基线构建：`tools -> distribution`
2. 产出并打包 5 件标准产物（`img/img.gz/elf/sysroot/SHA256SUMS`）
3. 执行 QEMU 交互式 gate（`neofetch` + 关机链）
4. 上传 smoke 日志 artifact：`riscv64-nightly-smoke-log-<date>-<sha>`
5. 上传构建产物 artifact：`riscv64-nightly-<date>-<sha>`
6. 创建 nightly tag 并发布 prerelease

Nightly tag 规则 / Nightly tag format:
- `nightly-master-riscv64-YYYYMMDD-<shortsha>`
- 例如：`nightly-master-riscv64-20260219-abcdef123456`

Nightly 产物命名 / Nightly asset naming:
- `minix-cat-nightly-<YYYYMMDD>-<shortsha>-riscv64.img`
- `minix-cat-nightly-<YYYYMMDD>-<shortsha>-riscv64.img.gz`
- `minix-cat-nightly-<YYYYMMDD>-<shortsha>-riscv64.elf`
- `minix-cat-nightly-<YYYYMMDD>-<shortsha>-riscv64-sysroot.tar.gz`
- `SHA256SUMS.txt`

说明 / Notes:
- Nightly 会把上述 5 件产物同时放入：
  1) Actions workflow artifacts；2) GitHub Release（prerelease）资产。
- 若出现“某次 nightly 没有产物”，先确认该 run 是否被取消；取消的 run 可能显示
  `0 artifact`，不代表成功 run 未上传。

## 性能优化 / Performance Optimization

### 编译优化标志 / Compiler Flags

- `-march=rv64gc` - 通用 RISC-V 64-bit 扩展（工具链支持时）  
  RISC-V 64-bit general extensions (if toolchain supports)
- `-mabi=lp64d` - LP64 数据模型，双精度浮点  
  LP64 data model with double-precision FP
- 兼容 fallback：`-march=RV64IMAFD -mcmodel=medany`  
  Compatibility fallback: `-march=RV64IMAFD -mcmodel=medany`

### 内核优化 / Kernel Notes

- 使用内存屏障确保内存访问顺序 / Use memory barriers for ordering
- 优化中断处理路径 / Optimize interrupt paths
- SMP 仍在实现中（当前测试为单核路径）/ SMP is still under implementation (current testing focuses on single-core paths)

## 开发指南 / Development Guide

### 添加新的 RISC-V 特性 / Adding New RISC-V Features

1. 在 `minix/kernel/arch/riscv64/` 添加内核代码  
   Add kernel code under `minix/kernel/arch/riscv64/`
2. 更新 `minix/lib/libc/arch/riscv64/` 的 C 库支持  
   Update C library support under `minix/lib/libc/arch/riscv64/`
3. 添加相应的测试到 `minix/tests/riscv64/`  
   Add tests under `minix/tests/riscv64/`

### 调试技巧 / Debugging Tips

1. 使用 `-d` 参数启动 QEMU 调试模式  
   Start QEMU with `-d`
2. GDB 可以连接到 QEMU 的 GDB 服务器  
   GDB can attach to QEMU’s GDB server
3. 查看内核日志：`cat /proc/kmsg`  
   Read kernel log: `cat /proc/kmsg`

## 问题反馈与变更记录 / Issue Reporting and Change Log

1. 新问题：在 `issue.md` 记录症状、复现步骤、日志片段、涉及文件与行号、影响范围  
   New issues: record symptoms, repro steps, logs, files/lines, and impact in `issue.md`
2. 修复后：同步更新 `RISC64-STATUS.md` 的状态与风险评估  
   After fixes: update status and risk assessment in `RISC64-STATUS.md`
3. 关键变更：补充到 `docs/RISCV64_PORTING_GUIDE.md` 的移植步骤与验证记录；VirtIO 相关变更同步到 `docs/RISCV64_VIRTIO_DRIVER_GUIDE.md`  
   Key changes: add porting steps and verification notes to `docs/RISCV64_PORTING_GUIDE.md`; sync VirtIO-specific updates to `docs/RISCV64_VIRTIO_DRIVER_GUIDE.md`

## 参考资料 / References

- [RISC-V 规范](https://riscv.org/technical/specifications/)
- [SBI 规范](https://github.com/riscv-non-isa/riscv-sbi-doc)
- [QEMU RISC-V 支持](https://www.qemu.org/docs/master/system/riscv/riscv-virt.html)
- [MINIX 文档](http://www.minix3.org/docs/)
- [RISC-V VirtIO 驱动指南 / RISC-V VirtIO Driver Guide](docs/RISCV64_VIRTIO_DRIVER_GUIDE.md)

## 许可证 / License

MINIX 遵循 BSD 许可证。详见源码中的 LICENSE 文件。  
MINIX is licensed under BSD. See LICENSE in the source tree.

---

**最后更新 / Last updated**：2026-02-19  
**版本 / Version**：1.25
