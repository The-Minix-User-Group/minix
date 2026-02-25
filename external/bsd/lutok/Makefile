# $NetBSD: Makefile,v 1.1 2013/02/16 21:29:45 jmmv Exp $

.include <bsd.own.mk>

SUBDIR= lib .WAIT share

.if ${MKTESTS:Uno} != "no"
.if ${MKATF:Uno} != "no"
.if !defined(__MINIX)
SUBDIR+= tests
.endif
.endif
.endif

.include <bsd.subdir.mk>
