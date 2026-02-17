#	@(#)Makefile	8.1 (Berkeley) 6/6/93
#	$NetBSD: Makefile,v 1.4 1997/01/09 20:18:26 tls Exp $

PROG=	cmp
SRCS=	cmp.c misc.c regular.c special.c

.if ${MACHINE_ARCH} == "riscv64" || ${MACHINE_ARCH} == "riscv"
LDFLAGS+= -Wl,--defsym,__global_pointer$$=_gp
.endif

.include <bsd.prog.mk>
