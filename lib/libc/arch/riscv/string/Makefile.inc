# $NetBSD: Makefile.inc,v 1.1 2014/09/19 17:36:25 matt Exp $

# Avoid recursive memset() codegen on rv64 for the generic C implementation.
COPTS.memset.c+=	-fno-builtin-memset -fno-tree-loop-distribute-patterns
