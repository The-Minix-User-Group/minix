#ifndef _MINIX_VERSION_H
#define _MINIX_VERSION_H

/*
 * Central MINIX version identifiers.
 *
 * Keep all user-visible OS version strings here, so kernel/userland
 * components and build scripts share one source of truth.
 */
#define OS_NAME "Minix Cat"
#define OS_RELEASE "4.0.0"	/* x.m.p */
#define OS_REV 400000000	/* see NetBSD sys/param.h: xmm00pp00 */
#define OS_CONFIG "GENERIC"
#define OS_VERSION OS_NAME " " OS_RELEASE " (" OS_CONFIG ")"

#endif /* _MINIX_VERSION_H */
