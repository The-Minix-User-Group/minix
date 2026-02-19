# Makefile for virtio_net_mmio
PROG=	virtio_net_mmio
SRCS=	virtio_net_mmio.c

FILES=${PROG}.conf
FILESNAME=${PROG}
FILESDIR= /etc/system.conf.d

CPPFLAGS+=	-I${NETBSDSRCDIR}/minix/drivers/net/virtio_net

DPADD+=	${LIBNETDRIVER} ${LIBSYS} ${LIBVIRTIO_MMIO}
LDADD+=	-lnetdriver -lsys -lvirtio_mmio

WARNS?= 5

.include <minix.service.mk>
