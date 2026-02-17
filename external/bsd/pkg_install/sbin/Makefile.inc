# $NetBSD: Makefile.inc,v 1.3 2010/11/05 09:09:01 he Exp $

.include <bsd.own.mk>

.include "${.PARSEDIR}/../Makefile.inc"

LIBINSTALLDIR != cd ${.PARSEDIR}/../lib && ${PRINTOBJDIR}

BINDIR?=	/usr/sbin
CPPFLAGS+=	-DBINDIR='"${BINDIR}"'

DPADD+=	${LIBINSTALLDIR}/libinstall.a
LDADD+=	-L${LIBINSTALLDIR} -linstall -ltermcap

DPADD+=		${LIBFETCH} ${LIBSSL} ${LIBCRYPTO}
LDADD+=		-lfetch -lssl -lcrypto

DPADD+=		${LIBARCHIVE}
LDADD+=		-larchive

DPADD+=		${LIBZ} ${LIBBZ2}
LDADD+=		-lz -lbz2

DPADD+=		${LIBLZMA}
LDADD+=		-llzma
