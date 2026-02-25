#	$NetBSD: Makefile,v 1.10 2014/06/01 19:51:02 mrg Exp $

REQUIRETOOLS=	yes
NOLINT=		# defined
NOPIC=		# defined
NOPROFILE=	# defined

CWARNFLAGS.clang+=	-Wno-parentheses
UNSUPPORTED_COMPILER.clang=	# defined

.include <bsd.init.mk>

GCC_MACHINE_ARCH?=${MACHINE_ARCH:S/earmv5/earm/}

LIB=		supc++

.if exists(${.CURDIR}/../libstdc++-v3/arch/${GCC_MACHINE_ARCH}/defs.mk) && ${MKGCC} != "no"
.include "${.CURDIR}/../libstdc++-v3/arch/${GCC_MACHINE_ARCH}/defs.mk"

SHLIB_MAJOR=	2
SHLIB_MINOR=	0

.include "${.CURDIR}/../libsupc++/Makefile.common"

SRCS=		${LIBSUPCXXSRCS} xmalloc.c
CXXFLAGS+=	${G_SECTION_FLAGS}

COPTS.cp-demangle.c = -Wno-stack-protector

.if ${HAVE_LIBGCC_EH} == "no"
G_CONFIGLINKS:= ${G_CONFIGLINKS:S,libgcc/config/arm/unwind-arm.h,libgcc/unwind-generic.h,}
.endif

.if ${MKGCC} != "no"
.if defined(G_CONFIGLINKS) && !empty(G_CONFIGLINKS)
.for _src _dst in ${G_CONFIGLINKS}
.if ${_dst} == "enable-execute-stack.c"
ENABLE_EXEC_STACK_SRC=	${_src}
.else
BUILDSYMLINKS+=	${_src} ${_dst}
DPSRCS+=	${_dst}
.endif
.endfor
.if defined(ENABLE_EXEC_STACK_SRC)
DPSRCS+=	enable-execute-stack.c
.endif
.endif
.endif

# Keep enable-execute-stack.c aligned with the current arch defs in
# incremental/update builds.
.if defined(ENABLE_EXEC_STACK_SRC)
enable-execute-stack.c: ${ENABLE_EXEC_STACK_SRC} \
    ${.CURDIR}/../libstdc++-v3/arch/${GCC_MACHINE_ARCH}/defs.mk
	rm -f ${.TARGET}
	cp -pf ${ENABLE_EXEC_STACK_SRC} ${.TARGET}
.endif

.include <bsd.lib.mk>

.PATH:	${DIST}/libstdc++-v3/src \
	${DIST}/libstdc++-v3/libsupc++ \
	${DIST}/libiberty \
	${.CURDIR}/../libstdc++-v3/arch/${GCC_MACHINE_ARCH}

${OBJS}: ${.CURDIR}/../libstdc++-v3/arch/${GCC_MACHINE_ARCH}/defs.mk
.else
.include <bsd.prog.mk> # do nothing
.endif
