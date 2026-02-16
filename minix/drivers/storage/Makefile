.include <bsd.own.mk>

.if ${MKIMAGEONLY} == "no"
.  if ${MACHINE_ARCH} == "i386"
SUBDIR+=	ahci
SUBDIR+=	fbd
SUBDIR+=	filter
SUBDIR+=	virtio_blk
.  endif # ${MACHINE_ARCH} == "i386"

.  if ${MACHINE_ARCH} == "earm"
SUBDIR+=	mmc
.  endif # ${MACHINE_ARCH} == "earm"

.  if ${MACHINE_ARCH} == "riscv64" || ${MACHINE_ARCH} == "riscv"
SUBDIR+=	virtio_blk_mmio
.  endif # ${MACHINE_ARCH} == "riscv64" || ${MACHINE_ARCH} == "riscv"

SUBDIR+=	vnd
.endif # ${MKIMAGEONLY} == "no"

.if ${MACHINE_ARCH} == "i386"
SUBDIR+=	at_wini
SUBDIR+=	floppy
.endif # ${MACHINE_ARCH} == "i386"

# memory driver must be last for ramdisk image.
# Everything else must be done before ramdisk as it needs
# executables from other targets.
SUBDIR+=	.WAIT ramdisk .WAIT memory

.include <bsd.subdir.mk>
