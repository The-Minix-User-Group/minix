# RISC-V MINIX Kernel Build Log / RISC-V MINIX 内核构建日志

**Last updated / 最后更新**: 2026-02-16  
**Version / 版本**: 1.3  
**Purpose / 用途**: Append-only record of build commands and outcomes. / 记录构建命令与结果（追加式）。

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
  -k obj/destdir.evbriscv64/boot/minix/.temp/kernel \
  -B obj/destdir.evbriscv64
```

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
