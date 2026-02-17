# RISC-V MINIX Kernel Build Log / RISC-V MINIX 内核构建日志

**Last updated / 最后更新**: 2026-02-17
**Version / 版本**: 1.9
**Purpose / 用途**: Append-only record of build commands and outcomes. / 记录构建命令与结果（追加式）。

**Baseline note / 基线说明**: active build/run baseline is `obj.intrgcc`; any
`obj/...` path in older entries is historical context only. /
当前构建与运行基线为 `obj.intrgcc`；旧条目中的 `obj/...` 路径仅用于历史记录。

## Log Entries / 日志条目

### Entry 1 — Initial Attempts (date unknown) / 初始尝试（日期未知）
**Workspace / 工作区**: `/home/donz/minix`  
**Target / 目标**: `evbriscv64` (MACHINE_ARCH: `riscv64`)  
**Toolchain / 工具链**: `riscv64-unknown-elf-gcc` (expected in PATH)

**Steps / 过程**:
1. Create build log / 创建本日志文件。
2. Build tools (`./build.sh -U -j2 -m evbriscv64 tools`) / 构建工具链：
   - First run timed out after 120s. / 首次运行 120s 超时。
   - Second run with `HAVE_LLVM=no MKLLVM=no` failed in `tools/compat` due to missing `nbtool_config.h`.  
     Clean rerun fixed it. / 使用 `HAVE_LLVM=no MKLLVM=no` 在 `tools/compat` 失败，清理后修复。
   - Later failed in `tools/binutils` with `fatal error: bfd.h: No such file or directory`.  
     Manual `nbmake -C tools/binutils/obj/build/bfd bfd.h` succeeded after specifying the correct tooldir
     and `-m /home/donz/minix/share/mk`. / 通过指定正确的 tooldir 与 `-m /home/donz/minix/share/mk` 生成 `bfd.h`。
   - Final rerun with `-u -j1` completed and installed tools to
     `/home/donz/minix/obj/tooldir.Linux-6.6.99-09058-g594deca50d73-x86_64`.
3. Build distribution (`./build.sh -U -u -j1 -m evbriscv64 distribution`) / 构建 distribution：
   - Failed in `lib/csu` because `riscv64-elf32-minix-clang` was missing.
   - Attempt to rebuild tools with `MKGCC=yes` failed in `tools/gmake` due to missing distfiles (network blocked).

**Result / 结果**: Tools eventually built; distribution failed due to missing clang/distfiles.  
**Outcome / 结论**: Build environment needed adjustments (no clang, no network fetch).

### Entry 2 — Workaround Build Success (2026-01-02) / 绕过项构建成功
**Workspace / 工作区**: `/root/minix`  
**Command / 命令**:
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
**Outputs / 产物**:
- Kernel: `minix/kernel/obj/kernel`
- Destdir: `obj/destdir.evbriscv64`

**Notes / 说明**:
- `CHECKFLIST_FLAGS='-m -e'` relaxes missing/extra files while sets are incomplete.
- LLVM/C++ disabled due to known RISC-V build gaps.

### Entry 3 — Doc Update Only (2026-01-04) / 仅更新文档
**Action / 动作**: Documentation updates; no new build executed. / 仅更新文档，未执行新的构建。

### Entry 4 — Doc Major Version (2026-01-06) / 文档大版本更新
**Action / 动作**: Promoted docs to version 1.0; no new build executed. / 文档升级为 1.0，未执行新的构建。

### Entry 5 — Doc Sync (2026-01-07) / 文档同步
**Action / 动作**: Documentation sync only; no new build or tests executed. / 仅文档同步，未执行新的构建或测试。  
**Scope / 范围**: `README.md`, `README-RISCV64.md`, `RISC64-STATUS.md`, `issue.md`,
`docs/RISCV64_PORTING_GUIDE.md`, `docs/RISCV64_PORT_PLAN.md`.

### Entry 6 — Doc Update After Pre-01:00 Review (2026-01-07) / 复核后文档更新
**Action / 动作**: Documentation update after reviewing pre-2026-01-06 01:00 code changes; no build/tests executed.  
仅根据 2026-01-06 01:00 前代码变更补充文档，未执行新的构建或测试。
**Scope / 范围**: `README.md`, `README-RISCV64.md`, `RISC64-STATUS.md`, `issue.md`,
`docs/RISCV64_PORTING_GUIDE.md`, `docs/RISCV64_PORT_PLAN.md`.

### Entry 7 — Toolchain + Kernel Rebuild (2026-01-07) / 工具链 + 内核重建
**Workspace / 工作区**: `/root/minix`  
**Commands / 命令**:
```bash
# Rebuild tools (LLVM enabled) after ValueMap.h fix
MKPCI=no HOST_CFLAGS="-O -fcommon" HAVE_GOLD=no ./build.sh -U -m evbriscv64 tools

# Kernel rebuild with GCC toolchain + out-of-tree objdir
MAKEOBJDIRPREFIX=/root/minix/obj \
  obj/tooldir.Linux-6.12.57+deb13-amd64-x86_64/bin/nbmake-evbriscv64 \
  -C minix/kernel \
  CC=/root/minix/obj/tooldir.Linux-6.12.57+deb13-amd64-x86_64/bin/riscv64-elf32-minix-gcc \
  ACTIVE_CC=gcc \
  RISCV_ARCH_FLAGS='-march=RV64IMAFD -mcmodel=medany'
```
**Result / 结果**:
- Tools build succeeded after fixing `llvm/IR/ValueMap.h` explicit bool conversion.
- Kernel build succeeded with GCC toolchain + `MAKEOBJDIRPREFIX` setup.

### Entry 8 — RV64 memset Fix + Ramdisk/Memory Rebuild + QEMU Smoke (2026-02-16) / 修复 memset + 重建 ramdisk/memory + QEMU 冒烟
**Workspace / 工作区**: `/home/donz/minix`
**Target / 目标**: `evbriscv64`
**Toolchain / 工具链**: `obj/tooldir.Linux-6.12.63+deb13-amd64-x86_64`

**Context / 背景**:
- Interactive repro showed `ps -aux` SIGSEGV with stack-top fault (`sp=0xefbffff0`) and `pc` inside userland `memset`.
- `cat /proc/meminfo` path showed repeated safecopy fallback logs (`-14` / retry).

**Code changes linked to this run / 本轮关联代码改动**:
1. `lib/libc/arch/riscv/string/Makefile.inc`  
   Added:
   ```make
   COPTS.memset.c+= -fno-builtin-memset -fno-tree-loop-distribute-patterns
   ```
   to prevent RV64 recursive memset codegen.
2. `minix/servers/vfs/request.c`  
   Added procfs-specific magic-grant cpflag selection to avoid first-pass `CPF_TRY`
   retry churn on `/proc/*` read/stat/getdents/rdlink paths.

**Build and image steps / 构建与镜像步骤**:
```bash
# Rebuild ramdisk image from in-tree obj program paths
obj/tooldir.Linux-6.12.63+deb13-amd64-x86_64/bin/nbmake-evbriscv64 \
  -C minix/drivers/storage/ramdisk \
  MACHINE=evbriscv64 MACHINE_ARCH=riscv64 \
  NETBSDSRCDIR=$PWD DESTDIR=$PWD/obj/destdir.evbriscv64 \
  image

# Rebuild/install memory service with refreshed imgrd
obj/tooldir.Linux-6.12.63+deb13-amd64-x86_64/bin/nbmake-evbriscv64 \
  -C minix/drivers/storage/memory \
  MACHINE=evbriscv64 MACHINE_ARCH=riscv64 \
  NETBSDSRCDIR=$PWD DESTDIR=$PWD/obj/destdir.evbriscv64 \
  LDFLAGS= dependall install
```

**QEMU command / QEMU 启动命令**:
```bash
./minix/scripts/qemu-riscv64.sh \
  -s \
  -k obj.intrgcc/minix/kernel/kernel \
  -B obj.intrgcc/destdir.evbriscv64
```

备注 / Note:
- 日常验证建议使用 `obj.intrgcc/minix/kernel/kernel`，避免 `obj*/destdir.../boot/minix/.temp/kernel`
  与最新内核构建产物不同步而出现版本号回退。

**In-guest smoke commands / 来宾内冒烟命令**:
```sh
ps -aux
cat /proc/meminfo
```

**Observed result / 观察结果**:
- `ps -aux`: no SIGSEGV; process list returned and shell prompt restored.
- `cat /proc/meminfo`: prints meminfo successfully.
- A single recoverable safecopy fallback is still visible on procfs read path, tracked as `issue.md` #17.

**Toolchain note / 工具链备注**:
- In-tree linker compatibility issue with `R_RISCV_RELAX` remained visible during incremental rebuild attempts
  (`ld: unrecognized relocation (0x33)`), tracked as `issue.md` #24.

### Entry 9 — #24 `R_RISCV_RELAX` Compatibility Mitigation (2026-02-16) / #24 `R_RISCV_RELAX` 兼容性缓解
**Workspace / 工作区**: `/home/donz/minix`
**Target / 目标**: `evbriscv64`
**Toolchain / 工具链**: `obj/tooldir.Linux-6.12.63+deb13-amd64-x86_64`

**Code change / 代码改动**:
- Added tracked binutils patch:
  `external/gpl3/binutils/patches/0011-riscv-relax-compat.patch`
  to treat `R_RISCV_RELAX` as a hint/no-op in in-tree bfd paths.

**Build/validation steps / 构建与验证步骤**:
```bash
# Rebuild tools pipeline (binutils rebuilt/installed before later LLVM stages)
MKPCI=no HOST_CFLAGS='-O -fcommon' HAVE_GOLD=no ./build.sh -U -m evbriscv64 tools

# Confirm in-tree linker version
obj/tooldir.Linux-6.12.63+deb13-amd64-x86_64/riscv64-elf32-minix/bin/ld --version

# Verify RELAX relocations exist in target archives
obj/tooldir.Linux-6.12.63+deb13-amd64-x86_64/bin/riscv64-elf32-minix-readelf -r \
  obj/destdir.evbriscv64/usr/lib/libaudiodriver.a | grep R_RISCV_RELAX

# Validate in-tree ld can link RELAX-bearing archive (no 0x33 abort)
obj/tooldir.Linux-6.12.63+deb13-amd64-x86_64/riscv64-elf32-minix/bin/ld -r \
  --whole-archive obj/destdir.evbriscv64/usr/lib/libaudiodriver.a \
  --no-whole-archive -o /tmp/libaudiodriver.whole.o
```

**Observed result / 观察结果**:
- `readelf -r` shows multiple `R_RISCV_RELAX` entries in `libaudiodriver.a`.
- In-tree `ld` (NetBSD binutils 2.23.2) links the RELAX-bearing archive successfully,
  no `unrecognized relocation (0x33)` appears.
- #24 is mitigated in the current workspace and moved to fixed archive in `issue.md`.

**Follow-up note / 后续说明**:
- During forced GCC-only memory-service rebuild, a separate compiler capability issue was observed:
  `riscv64-elf32-minix-gcc: error: unrecognized command line option '-mabi=lp64d'`.
  This is distinct from #24 and should be tracked separately.

### Entry 10 — `obj.intrgcc` Self-Bootstrap Distribution + QEMU Validation (2026-02-16) / `obj.intrgcc` 自举 distribution + QEMU 验证
**Workspace / 工作区**: `/home/donz/minix`  
**Target / 目标**: `evbriscv64`  
**Objdir / 对象目录**: `obj.intrgcc`  

**Goal / 目标**:
- Validate a fully isolated rebuild path (`tools -> distribution`) without injecting artifacts from `obj/`.
- Ensure QEMU can boot directly from `obj.intrgcc` outputs.

**Build commands / 构建命令**:
```bash
# 1) tools in isolated objdir
MKPCI=no HOST_CFLAGS="-O -fcommon" HAVE_GOLD=no HAVE_LLVM=no MKLLVM=no \
./build.sh -U -m evbriscv64 -O obj.intrgcc \
  -V AVAILABLE_COMPILER=gcc -V ACTIVE_CC=gcc -V ACTIVE_CPP=gcc -V ACTIVE_CXX=gcc -V ACTIVE_OBJC=gcc \
  tools

# 2) distribution in the same objdir
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

**QEMU command / QEMU 启动命令**:
```bash
./minix/scripts/qemu-riscv64.sh \
  -k obj.intrgcc/minix/kernel/kernel \
  -B obj.intrgcc/destdir.evbriscv64
```

**Observed result / 观察结果**:
- Distribution completed successfully on the `obj.intrgcc` path.
- QEMU reached interactive shell from `obj.intrgcc` outputs.
- `Boot module not found: ds` was no longer reproduced in this profile.

**Follow-up / 后续**:
- Keep `issue.md` `#17` (procfs safecopy fallback noise) and `#25`
  (GCC-only incremental ABI-flag compatibility) under ongoing tracking.

### Entry 11 — P0 Kernel Rebuild + QEMU Smoke Revalidation (2026-02-16) / P0 内核重建 + QEMU 冒烟复验
**Workspace / 工作区**: `/home/donz/minix`  
**Target / 目标**: `evbriscv64`  
**Toolchain / 工具链**: `obj/tooldir.Linux-6.12.63+deb13-amd64-x86_64`  

**Goal / 目标**:
- Rebuild the riscv64 kernel with in-tree GCC after `vm_memset` fault-recovery plumbing changes.
- Revalidate P0 smoke paths in QEMU (`ps -aux`, `cat /proc/meminfo`, RS status query).

**Build command / 构建命令**:
```bash
TOOLDIR=$(echo obj/tooldir.* | awk '{print $1}')
${TOOLDIR}/bin/nbmake-evbriscv64 \
  -C minix/kernel -j"$(nproc)" dependall \
  ACTIVE_CC=gcc \
  RISCV_ARCH_FLAGS='-march=RV64IMAFD -mcmodel=medany'
```

**Build result / 构建结果**:
- `dependall` completed successfully; kernel link finished (`minix/kernel/obj/kernel`).
- Attempt without `ACTIVE_CC=gcc` selected missing `riscv64-elf32-minix-clang` and failed; rerun with GCC succeeded.

**QEMU smoke execution / QEMU 冒烟执行**:
```bash
{ sleep 35; echo 'ps -aux'; sleep 6; echo 'cat /proc/meminfo'; sleep 6; \
  echo '/sbin/minix-service sysctl srv_status'; sleep 6; } \
| timeout 220 ./minix/scripts/qemu-riscv64.sh -s \
    -k minix/kernel/obj/kernel \
    -B obj/destdir.evbriscv64 \
  > /tmp/qemu-p0-smoke.log 2>&1 || true
```

**Observed result / 观察结果**:
- In-log markers confirm all three commands returned success:
  `__RC_PS__:0`, `__RC_MEMINFO__:0`, `__RC_SRV__:0`.
- No `SIGSEGV` signature and no kernel panic were observed in this run.
- procfs/safecopy fallback noise is still visible but recoverable (commands still succeed), consistent with `issue.md` `#17`.

**Evidence / 证据**:
- Log: `/tmp/qemu-p0-smoke.log`
- Marker lines include `__P0_BEGIN__`, `__RC_PS__:0`, `__RC_MEMINFO__:0`, `__RC_SRV__:0`, `__P0_DONE__`.

### Entry 12 — `obj.intrgcc` Fully Self-Hosted GCC Toolchain Closure (2026-02-16) / `obj.intrgcc` 完全自举 GCC 工具链收敛
**Workspace / 工作区**: `/home/donz/minix`  
**Target / 目标**: `evbriscv64`  
**Objdir / 对象目录**: `obj.intrgcc`

**Goal / 目标**:
- Close the isolated toolchain path with in-tree GCC frontend commands enabled (`MKGCCCMDS=yes`).
- Revalidate `distribution` and QEMU boot strictly from `obj.intrgcc`.

**Build commands / 构建命令**:
```bash
# 1) tools with in-tree GCC command wrappers/frontends
MKPCI=no HOST_CFLAGS='-O -fcommon' HAVE_GOLD=no HAVE_LLVM=no MKLLVM=no \
./build.sh -U -m evbriscv64 -O obj.intrgcc \
  -V AVAILABLE_COMPILER=gcc -V ACTIVE_CC=gcc -V ACTIVE_CPP=gcc -V ACTIVE_CXX=gcc -V ACTIVE_OBJC=gcc \
  -V MKGCC=yes -V MKGCCCMDS=yes \
  tools

# 2) distribution on the same isolated objdir
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

**Toolchain artifact checks / 工具链产物校验**:
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

**QEMU validation / QEMU 验证**:
```bash
timeout 45 ./minix/scripts/qemu-riscv64.sh \
  -k obj.intrgcc/minix/kernel/kernel \
  -B obj.intrgcc/destdir.evbriscv64
```

**Observed result / 观察结果**:
- `tools` completed with `MKGCC=yes` + `MKGCCCMDS=yes` (no fallback injection from `obj/` needed).
- `riscv64-elf32-minix-{gcc,c++,cpp,g++}` were present as local ELF executables under
  `obj.intrgcc/tooldir.*/bin`.
- `distribution` completed successfully on the same `obj.intrgcc`.
- QEMU boot output listed `Boot modules (12)` including `service/ds`, reached shell prompt (`#`),
  and did not reproduce `Boot module not found: ds`.

**Notes / 备注**:
- The QEMU run was bounded by `timeout`; termination by SIGTERM at timeout boundary is expected
  for log-capture runs and does not indicate runtime crash.

### Entry 17 — Strict Runtime-Aware Smoke Gate Hardening (2026-02-17) / 严格运行时感知 smoke 门禁加固
**Workspace / 工作区**: `/home/donz/minix`  
**Target / 目标**: `evbriscv64`  
**Profile / 轮廓**: `obj.intrgcc`

**Goal / 目标**:
- Raise smoke rigor from boot-only signal to boot + runtime signal.
- Make each round verify command-level usability in guest userland.

**Code updates / 代码更新**:
- Added runtime probe runner:
  `minix/tests/riscv64/qemu_runtime_probe.py`.
- Integrated runtime probe into multi-run gate with default-on behavior:
  `minix/tests/riscv64/multi_smoke_gate.sh`.
- Added probe controls:
  `--runtime-probe` / `--no-runtime-probe`,
  `--runtime-timeout`, `--runtime-cmd-timeout`.
- Fixed gate reporting bug on runtime probe failure branch (preserve non-zero probe RC).

**Commands executed / 实际执行命令**:
```bash
# 1) syntax and bytecode checks
bash -n minix/tests/riscv64/multi_smoke_gate.sh
python3 -m py_compile minix/tests/riscv64/qemu_runtime_probe.py

# 2) targeted with-disk runtime probe check
tmpimg=/tmp/minix-runtime-probe-req2.$$.img
truncate -s 128M "$tmpimg"
python3 minix/tests/riscv64/qemu_runtime_probe.py \
  --qemu-script ./minix/scripts/qemu-riscv64.sh \
  --kernel ./obj.intrgcc/minix/kernel/kernel \
  --destdir ./obj.intrgcc/destdir.evbriscv64 \
  --disk "$tmpimg" --require-disk-node \
  --timeout 70 --cmd-timeout 35
rm -f "$tmpimg"

# 3) strict multi-run gate (diskless + with-disk)
./minix/tests/riscv64/multi_smoke_gate.sh \
  --rounds 1 --timeout 70 \
  --runtime-timeout 70 --runtime-cmd-timeout 35
```

**Observed result / 观察结果**:
- Runtime probe now validates:
  `cat /proc/meminfo`, `ps -aux`, `minix-service sysctl srv_status`,
  and `/dev/c0d0` existence for with-disk rounds.
- Strict gate run passes end-to-end with summary:
  `Passed: 2`, `Failed: 0`, `Runtime passed: 2`, `Runtime failed: 0`.

**Evidence / 证据**:
- `/tmp/minix-smoke-gate-20260217-070246`

### Entry 16 — RS Leak-Path Closure + Gate Hardening Follow-up (2026-02-16) / RS 泄漏路径收敛 + 门禁加固续验
**Workspace / 工作区**: `/home/donz/minix`  
**Target / 目标**: `evbriscv64`  
**Profile / 轮廓**: `obj.intrgcc`

**Goal / 目标**:
- Close issue `#26` by fixing RS slot cleanup on post-`init_slot()` failures.
- Preserve `#28` fix while restoring no-state update semantics (no payload => `size=0`).
- Harden `#31` relax probe to avoid false-positive pass on empty archive links.
- Revalidate per-round independent with-disk reproducibility.

**Commands executed / 实际执行命令**:
```bash
# 1) targeted RS rebuild
TOOLDIR=$(ls -d obj.intrgcc/tooldir.* | head -n1)
"$TOOLDIR/bin/nbmake-evbriscv64" -C minix/servers/rs

# 2) per-round reproducibility smoke (diskless + with-disk)
./minix/tests/riscv64/multi_smoke_gate.sh \
  --kernel obj.intrgcc/minix/kernel/kernel \
  --destdir obj.intrgcc/destdir.evbriscv64 \
  --rounds 2 --timeout 60 \
  --log-root /tmp/minix-smoke-gate-indep-20260216-234830

# 3) repro gate follow-up (skip rebuild, validate gate path)
./minix/tests/riscv64/repro_build_gate.sh \
  --objdir obj.intrgcc \
  --skip-tools --skip-distribution \
  --smoke-rounds 1 --smoke-timeout 45 \
  --without-disk

# 4) relax probe behavior sanity check
TOOLDIR=$(ls -d obj.intrgcc/tooldir.* | head -n1)
LD="$TOOLDIR/riscv64-elf32-minix/bin/ld"
[ -x "$LD" ] || LD="$TOOLDIR/bin/riscv64-elf32-minix-ld"
"$LD" -r --whole-archive obj.intrgcc/destdir.evbriscv64/usr/lib/libsys.a \
  --no-whole-archive -o /tmp/ld-whole-check.o
stat -c 'whole_archive_output_size=%s' /tmp/ld-whole-check.o
```

**Observed result / 观察结果**:
- `nbmake-evbriscv64 -C minix/servers/rs` rebuilds and links successfully.
- Multi-smoke passes `4/4`; logs show per-round disk images:
  `...minix-smoke-gate.round1.img` and `...minix-smoke-gate.round2.img`.
- `repro_build_gate.sh --skip-tools --skip-distribution ...` passes diskless smoke (`1/1`).
- Whole-archive probe output is non-empty (`whole_archive_output_size=206453`), confirming
  the probe now exercises real archive-member link paths.
- Code changes landed in:
  `minix/servers/rs/request.c`,
  `minix/servers/rs/manager.c`,
  `minix/tests/riscv64/repro_build_gate.sh`.

**Evidence / 证据**:
- `/tmp/minix-smoke-gate-indep-20260216-234830`
- `/tmp/minix-smoke-gate-20260217-000150`

### Entry 15 — Full Reproducibility Gate + Fresh Multi-Run Smoke (2026-02-16) / 全量复现门禁 + 新一轮多轮 smoke
**Workspace / 工作区**: `/home/donz/minix`
**Target / 目标**: `evbriscv64`
**Profile / 轮廓**: `obj.intrgcc`

**Goal / 目标**:
- Close the loop on source-driven reproducibility (no manual patching/copying).
- Re-run multi-round smoke after the full gate to avoid single-pass bias.

**Commands executed / 实际执行命令**:
```bash
./minix/tests/riscv64/repro_build_gate.sh \
  --objdir obj.intrgcc \
  --smoke-rounds 1 \
  --smoke-timeout 60 \
  --without-disk

./minix/tests/riscv64/multi_smoke_gate.sh \
  --kernel obj.intrgcc/minix/kernel/kernel \
  --destdir obj.intrgcc/destdir.evbriscv64 \
  --rounds 2 --timeout 90
```

**Observed result / 观察结果**:
- `repro_build_gate.sh` completed `tools -> distribution -> smoke` with `exit 0`.
- `build.sh` reported `Successful make distribution` on `obj.intrgcc` in the same run.
- Re-run multi-smoke finished `4/4` pass (diskless+with-disk x2).
- All four triage reports classify first safecopy as `acceptable_noise`
  (`first_safecopy_line=414`, `safecopy_total=8`, `safecopy_pre_shell=1`).
- With-disk rounds preserved `virtio-blk-mmio: initialized` and did not reproduce
  `device not found` / `Request 0x700 to RS failed` / `couldn't start virtio_blk_mmio`.

**Evidence / 证据**:
- Repro gate smoke log root: `/tmp/minix-smoke-gate-20260216-223948`
- Fresh multi-run gate log root: `/tmp/minix-smoke-gate-20260216-224157`

### Entry 14 — Automated Multi-Run Gate + Safecopy First-Error Triage (2026-02-16) / 自动化多轮门禁 + safecopy 首错定性
**Workspace / 工作区**: `/home/donz/minix`
**Target / 目标**: `evbriscv64`
**Profile / 轮廓**: `obj.intrgcc`

**Goal / 目标**:
- Convert ad-hoc smoke checks into a minimum automated gate.
- Classify safecopy first error as acceptable noise vs potential consistency issue.
- Add a reproducible-build gate entrypoint that avoids manual artifact injection.

**Added scripts / 新增脚本**:
```text
minix/tests/riscv64/safecopy_triage.py
minix/tests/riscv64/multi_smoke_gate.sh
minix/tests/riscv64/repro_build_gate.sh
```

**Hook-up / 接入**:
- `minix/tests/riscv64/run_tests.sh` adds `gate` mode:
  `./minix/tests/riscv64/run_tests.sh gate`

**Gate command executed / 实际执行命令**:
```bash
./minix/tests/riscv64/multi_smoke_gate.sh \
  --kernel obj.intrgcc/minix/kernel/kernel \
  --destdir obj.intrgcc/destdir.evbriscv64 \
  --rounds 2 --timeout 90
```

**Observed result / 观察结果**:
- 4/4 runs passed (diskless round1/2 + with-disk round1/2).
- No panic/SIGSEGV fatal signature in any round log.
- With-disk rounds kept `virtio-blk-mmio: initialized` and did not reproduce:
  `device not found`, `Request 0x700 to RS failed`, `couldn't start virtio_blk_mmio`.
- `safecopy_triage.py` on gate logs reports:
  `classification: acceptable_noise`,
  `first_safecopy_line: 414`,
  known recoverable startup fallback pattern.

**Evidence / 证据**:
- Log root: `/tmp/minix-smoke-gate-20260216-221610`
- Files include per-round `.log` and `.triage.txt`.

### Entry 13 — RS P0 Incremental Convergence + Diskless/With-Disk Smoke (2026-02-16) / RS P0 增量收敛 + 无盘/带盘冒烟
**Workspace / 工作区**: `/home/donz/minix`
**Target / 目标**: `evbriscv64`
**Objdir / 对象目录**: `obj.intrgcc`

**Goal / 目标**:
- Run a small convergence cycle after RS P0 hardening:
  incremental rebuild/install, baseline boot smoke, with-disk boot smoke,
  and first-error check.
- Confirm that with-disk startup no longer emits the previous `virtio_blk_mmio`
  startup-failure signature.

**Incremental build/install / 增量构建与安装**:
```bash
obj.intrgcc/tooldir.Linux-6.12.63+deb13-amd64-x86_64/bin/nbmake-evbriscv64 \
  -C minix/servers/rs
obj.intrgcc/tooldir.Linux-6.12.63+deb13-amd64-x86_64/bin/nbmake-evbriscv64 \
  -C minix/servers/rs install
```

**Smoke commands / 冒烟命令**:
```bash
# diskless baseline smoke
timeout 120 ./minix/scripts/qemu-riscv64.sh -s \
  -k obj.intrgcc/minix/kernel/kernel \
  -B obj.intrgcc/destdir.evbriscv64 \
  > /tmp/qemu-smoke-incremental.log 2>&1 || true

# with-disk smoke
truncate -s 128M /tmp/minix-smoke-disk.img
timeout 140 ./minix/scripts/qemu-riscv64.sh -s \
  -k obj.intrgcc/minix/kernel/kernel \
  -B obj.intrgcc/destdir.evbriscv64 \
  -i /tmp/minix-smoke-disk.img \
  > /tmp/qemu-smoke-disk.log 2>&1 || true
```

**Observed result / 观察结果**:
- Incremental RS rebuild/install completed successfully.
- Diskless and with-disk smoke both reached shell path (`MINIX 4.0.0`, `/bin/sh`),
  and no kernel panic / `SIGSEGV` signature was observed.
- With-disk smoke shows:
  `virtio-blk-mmio: capacity: 262144 sectors` and `virtio-blk-mmio: initialized`,
  while the old warning pattern is absent:
  `virtio-blk-mmio: device not found`,
  `Request 0x700 to RS failed`,
  `WARNING: couldn't start virtio_blk_mmio`.
- First non-fatal error in both logs is still recoverable safecopy fallback noise
  (`kcall safecopy err`, `do_safecopy_*`), tracked as `issue.md` #17.

**Evidence / 证据**:
- `/tmp/qemu-smoke-incremental.log`
- `/tmp/qemu-smoke-disk.log`

### Entry 16 — neofetch Service Source Switch + Version Bump to 4.0.0 (2026-02-17) / neofetch 服务源切换 + 版本升级到 4.0.0
**Workspace / 工作区**: `/home/donz/minix`  
**Target / 目标**: `evbriscv64`  
**Profile / 轮廓**: `obj.intrgcc`

**Goal / 目标**:
- Make `neofetch` service fields (`Services/CoreSvc/Missing`) useful by default,
  without relying on noisy default `ps` probing.
- Roll system/release version to `4.0.0` and keep runtime profile consistent.

**Code changes linked to this run / 本轮关联代码改动**:
1. `minix/drivers/storage/ramdisk/neofetch`
   - default probe mode switched from `off` to `auto`;
   - `auto` now prefers `/proc/service` for service summary;
   - `ps` path remains opt-in with `NEOFETCH_SERVICE_PROBE=ps`.
2. `minix/include/minix/config.h`
   - `OS_RELEASE` updated to `4.0.0`;
   - `OS_REV` updated to `400000000`.
3. `minimal_kernel/include/minix/config.h`
   - `OS_RELEASE` / `OS_REV` aligned to `4.0.0` / `400000000`.
4. `minix/releasetools/riscv64/release.conf`
   - `MINIX_VERSION` updated to `4.0.0-riscv64`.

**Build/install commands / 构建与安装命令**:
```bash
obj.intrgcc/tooldir.Linux-6.12.63+deb13-amd64-x86_64/bin/nbmake-evbriscv64 \
  -C minix/drivers/storage/ramdisk image

obj.intrgcc/tooldir.Linux-6.12.63+deb13-amd64-x86_64/bin/nbmake-evbriscv64 \
  -C minix/drivers/storage/memory all install
```

**Runtime probe command / 运行时探针命令**:
```bash
python3 minix/tests/riscv64/qemu_runtime_probe.py \
  --qemu-script minix/scripts/qemu-riscv64.sh \
  --kernel obj.intrgcc/minix/kernel/kernel \
  --destdir obj.intrgcc/destdir.evbriscv64 \
  --require-disk-node
```

**Observed result / 观察结果**:
- Ramdisk image and memory service rebuild/install completed successfully.
- Runtime probe passed all checks:
  `meminfo`, `ps_aux`, `srv_status`, `disk_node`.
- Service-summary data path in `neofetch` now defaults to procfs (`/proc/service`)
  instead of disabled-by-default mode, with explicit `ps` opt-in retained.
- System version macros and riscv64 release profile are now aligned to `4.0.0`.

**Evidence / 证据**:
- `qemu_runtime_probe.py` result: `PASS: qemu runtime probe`
- Updated source files:
  `minix/drivers/storage/ramdisk/neofetch`,
  `minix/include/minix/config.h`,
  `minimal_kernel/include/minix/config.h`,
  `minix/releasetools/riscv64/release.conf`

### Entry 17 — GCC ABI-Flag Baseline Alignment for riscv64 (#25) (2026-02-17) / riscv64 GCC ABI 参数基线收敛（#25）
**Workspace / 工作区**: `/home/donz/minix`  
**Target / 目标**: `evbriscv64`  
**Profile / 轮廓**: `obj.intrgcc` + raw `nbmake` verification

**Goal / 目标**:
- Remove default `-mabi=lp64d` dependency from riscv64 baseline flags to avoid
  GCC-only incremental rebuild incompatibility in environments that do not
  support that ABI option.
- Eliminate wrapper-only behavior drift by making the source-tree default align
  with the validated in-tree GCC path.

**Code change / 代码改动**:
1. `share/mk/bsd.own.mk`
   - riscv64 default `RISCV_ARCH_FLAGS` changed from
     `-march=rv64gc -mabi=lp64d` to
     `-march=RV64IMAFD -mcmodel=medany`.

**Verification commands / 验证命令**:
```bash
# Verify default from source-tree mk logic (non-wrapper lookup)
TOOLDIR="$PWD/obj.intrgcc/tooldir.Linux-6.12.63+deb13-amd64-x86_64"
"$TOOLDIR/bin/nbmake" -m "$PWD/share/mk" -C minix/drivers/storage/memory \
  MACHINE=evbriscv64 MACHINE_ARCH=riscv64 USETOOLS=yes \
  TOOLDIR="$TOOLDIR" DESTDIR="$PWD/obj.intrgcc/destdir.evbriscv64" \
  NETBSDSRCDIR="$PWD" ACTIVE_CC=gcc AVAILABLE_COMPILER=gcc \
  -V RISCV_ARCH_FLAGS

# Raw (non-wrapper) GCC incremental rebuild sanity
MAKEFLAGS='-de -m /home/donz/minix/share/mk  MKOBJDIRS=yes' \
"$TOOLDIR/bin/nbmake" -C minix/servers/mib \
  MACHINE=evbriscv64 MACHINE_ARCH=riscv64 USETOOLS=yes \
  TOOLDIR="$TOOLDIR" DESTDIR="$PWD/obj.intrgcc/destdir.evbriscv64" \
  NETBSDSRCDIR="$PWD" ACTIVE_CC=gcc AVAILABLE_COMPILER=gcc \
  clean dependall
```

**Observed result / 观察结果**:
- `RISCV_ARCH_FLAGS` now resolves to `-march=RV64IMAFD -mcmodel=medany`.
- Raw (non-wrapper) `ACTIVE_CC=gcc` rebuild of `minix/servers/mib` completed
  successfully with the aligned flags.
- No `-mabi=lp64d` option was emitted in the successful compile lines.
