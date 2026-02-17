#if HAVE_NBTOOL_CONFIG_H
#include "nbtool_config.h"
#endif
/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 4 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
/*-
 * Copyright (c)2003, 2006 Citrus Project,
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#if HAVE_NBTOOL_CONFIG_H
#include "nbtool_config.h"
#endif

#include <sys/cdefs.h>
#if !defined(lint)
__RCSID("$NetBSD: yacc.y,v 1.10 2015/06/16 22:54:10 christos Exp $");
#endif /* not lint */

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>

#include "ldef.h"

#ifndef __packed
#define __packed
#endif

#include "citrus_namespace.h"
#include "citrus_types.h"
#include "citrus_mapper_std_file.h"
#include "citrus_region.h"
#include "citrus_db_factory.h"
#include "citrus_db_hash.h"
#include "citrus_lookup_factory.h"
#include "citrus_pivot_factory.h"

int			debug = 0;
static char		*output = NULL;
static void		*table = NULL;
static size_t		table_size;
static char		*map_name;
static int		map_type;
static u_int32_t	dst_invalid, dst_ilseq, oob_mode, dst_unit_bits;
static void		(*putfunc)(void *, size_t, u_int32_t) = 0;

static u_int32_t	src_next;

static u_int32_t	done_flag = 0;
#define DF_TYPE			0x00000001
#define DF_NAME			0x00000002
#define DF_SRC_ZONE		0x00000004
#define DF_DST_INVALID		0x00000008
#define DF_DST_ILSEQ		0x00000010
#define DF_DST_UNIT_BITS	0x00000020
#define DF_OOB_MODE		0x00000040

static linear_zone_t	rowcol[_CITRUS_MAPPER_STD_ROWCOL_MAX];
static size_t		rowcol_len = 0;
static u_int32_t	rowcol_bits = 0, rowcol_mask = 0;

static void	dump_file(void);
static void	setup_map(void);
static void	set_type(int);
static void	set_name(char *);
static void	set_src_zone(u_int32_t);
static void	set_dst_invalid(u_int32_t);
static void	set_dst_ilseq(u_int32_t);
static void	set_dst_unit_bits(u_int32_t);
static void	set_oob_mode(u_int32_t);
static int	check_src(u_int32_t, u_int32_t);
static void	store(const linear_zone_t *, u_int32_t, int);
static void	put8(void *, size_t, u_int32_t);
static void	put16(void *, size_t, u_int32_t);
static void	put32(void *, size_t, u_int32_t);
static void	set_range(u_int32_t, u_int32_t);
static void	set_src(linear_zone_t *, u_int32_t, u_int32_t);
#line 107 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	u_int32_t	i_value;
	char		*s_value;
	linear_zone_t	lz_value;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 138 "yacc.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define R_TYPE 257
#define R_NAME 258
#define R_SRC_ZONE 259
#define R_DST_UNIT_BITS 260
#define R_DST_INVALID 261
#define R_DST_ILSEQ 262
#define R_BEGIN_MAP 263
#define R_END_MAP 264
#define R_INVALID 265
#define R_ROWCOL 266
#define R_ILSEQ 267
#define R_OOB_MODE 268
#define R_LN 269
#define L_IMM 270
#define L_STRING 271
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    6,    6,    6,    6,    6,    6,    6,    6,    6,
    9,   10,    3,   16,   17,   17,   11,    5,    5,   12,
   13,   14,   15,    4,    4,    7,   18,   19,   19,   20,
   20,    2,    2,    2,    1,    1,    1,    1,    8,    8,
};
static const YYINT yylen[] = {                            2,
    3,    0,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    1,    3,    0,    3,    2,    1,    6,    2,
    2,    2,    2,    1,    1,    3,    2,    0,    3,    3,
    4,    1,    1,    1,    0,    1,    3,    2,    1,    2,
};
static const YYINT yydefred[] = {                         2,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    3,    0,    4,    5,    6,    7,    8,    9,   10,   28,
   13,   12,   11,    0,   17,    0,   22,   20,   21,   39,
    0,   24,   25,   23,    0,    0,    0,    0,   40,   26,
    0,    0,    0,    0,   14,    0,    0,   38,    0,    0,
   15,   37,   33,   34,    0,   30,    0,   31,    0,    0,
   16,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  273,  279,  257,  258,  259,  260,  261,  262,  263,  268,
  269,  280,  282,  283,  284,  285,  286,  287,  288,  291,
  266,  276,  271,  270,  278,  289,  270,  270,  270,  269,
  281,  265,  267,  277,  281,  292,   45,   47,  269,  264,
  270,   45,  274,  293,  270,  289,   45,  270,   61,  281,
   47,  270,  265,  267,  270,  275,  290,   45,  270,  289,
   47,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          1,
   43,   56,   22,   34,   25,    2,   12,   31,   13,   14,
   15,   16,   17,   18,   19,   26,   57,   20,   36,   44,
};
static const YYINT yysindex[] = {                         0,
    0, -250, -261, -265, -256, -255, -249, -246, -237, -245,
    0, -237,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -12,    0,  -13,    0,    0,    0,    0,
 -224,    0,    0,    0, -224,  -43, -223, -256,    0,    0,
    1, -222,   -7, -237,    0,    5, -215,    0, -214, -224,
    0,    0,    0,    0,   12,    0, -212,    0,  -12,   13,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -232,    0,    0,    0,    0,
  -45,    0,    0,    0,   59,    2,    0,    0,    0,    0,
    3,    0,    0,    0,    0,    0,    0,    0,    0,  -44,
    0,    0,    0,    0, -208,    0,    0,    0, -219,    0,
    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,   -9,    0,    0,
    0,    0,    0,    0,    0,  -34,    0,    0,    0,    0,
};
#define YYTABLESIZE 227
static const YYINT yytable[] = {                         27,
   29,   42,   35,   46,   21,   23,    3,    4,    5,    6,
    7,    8,    9,   24,   27,   27,   29,   10,   11,   32,
   28,   33,   60,   29,   18,   18,   18,   18,   18,   18,
   18,   30,   37,   38,   50,   18,   18,   19,   19,   19,
   19,   19,   19,   19,   39,   47,   45,   48,   19,   19,
   53,   51,   54,   49,   52,   55,   58,   59,    1,   61,
   32,    0,   35,   36,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   27,   29,
   40,    0,    0,    0,   27,   29,   41,
};
static const YYINT yycheck[] = {                         45,
   45,   45,   12,   38,  266,  271,  257,  258,  259,  260,
  261,  262,  263,  270,  270,   61,   61,  268,  269,  265,
  270,  267,   57,  270,  257,  258,  259,  260,  261,  262,
  263,  269,   45,   47,   44,  268,  269,  257,  258,  259,
  260,  261,  262,  263,  269,   45,  270,  270,  268,  269,
  265,   47,  267,   61,  270,  270,   45,  270,    0,   47,
  269,   -1,   61,   61,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  264,  264,
  264,   -1,   -1,   -1,  270,  270,  270,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 271
#define YYUNDFTOKEN 294
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,0,0,"'='",0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","R_TYPE","R_NAME",
"R_SRC_ZONE","R_DST_UNIT_BITS","R_DST_INVALID","R_DST_ILSEQ","R_BEGIN_MAP",
"R_END_MAP","R_INVALID","R_ROWCOL","R_ILSEQ","R_OOB_MODE","R_LN","L_IMM",
"L_STRING","$accept","file","src","dst","types","oob_mode_sel","zone",
"property","mapping","lns","name","type","src_zone","dst_invalid","dst_ilseq",
"dst_unit_bits","oob_mode","range","ranges","begin_map","map_elems","map_elem",
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : property mapping lns",
"property :",
"property : property R_LN",
"property : property name",
"property : property type",
"property : property src_zone",
"property : property dst_invalid",
"property : property dst_ilseq",
"property : property dst_unit_bits",
"property : property oob_mode",
"name : R_NAME L_STRING",
"type : R_TYPE types",
"types : R_ROWCOL",
"range : L_IMM '-' L_IMM",
"ranges :",
"ranges : ranges range '/'",
"src_zone : R_SRC_ZONE zone",
"zone : range",
"zone : range '/' range '/' ranges L_IMM",
"dst_invalid : R_DST_INVALID L_IMM",
"dst_ilseq : R_DST_ILSEQ L_IMM",
"dst_unit_bits : R_DST_UNIT_BITS L_IMM",
"oob_mode : R_OOB_MODE oob_mode_sel",
"oob_mode_sel : R_INVALID",
"oob_mode_sel : R_ILSEQ",
"mapping : begin_map map_elems R_END_MAP",
"begin_map : R_BEGIN_MAP lns",
"map_elems :",
"map_elems : map_elems map_elem lns",
"map_elem : src '=' dst",
"map_elem : src '=' L_IMM '-'",
"dst : L_IMM",
"dst : R_INVALID",
"dst : R_ILSEQ",
"src :",
"src : L_IMM",
"src : L_IMM '-' L_IMM",
"src : '-' L_IMM",
"lns : R_LN",
"lns : lns R_LN",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 206 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"

static void
warning(const char *s)
{
	fprintf(stderr, "%s in %d\n", s, line_number);
}

int
yyerror(const char *s)
{
	warning(s);
	exit(1);
}

void
put8(void *ptr, size_t ofs, u_int32_t val)
{
	*((u_int8_t *)ptr + ofs) = val;
}

void
put16(void *ptr, size_t ofs, u_int32_t val)
{
	u_int16_t oval = htons(val);
	memcpy((u_int16_t *)ptr + ofs, &oval, 2);
}

void
put32(void *ptr, size_t ofs, u_int32_t val)
{
	u_int32_t oval = htonl(val);
	memcpy((u_int32_t *)ptr + ofs, &oval, 4);
}

static void
alloc_table(void)
{
	size_t i;
	u_int32_t val = 0;
	linear_zone_t *p;

	i = rowcol_len;
	p = &rowcol[--i];
	table_size = p->width;
	while (i > 0) {
		p = &rowcol[--i];
		table_size *= p->width;
	}
	table = (void *)malloc(table_size * dst_unit_bits / 8);
	if (table == NULL) {
		perror("malloc");
		exit(1);
	}

	switch (oob_mode) {
	case _CITRUS_MAPPER_STD_OOB_NONIDENTICAL:
		val = dst_invalid;
		break;
	case _CITRUS_MAPPER_STD_OOB_ILSEQ:
		val = dst_ilseq;
		break;
	default:
		_DIAGASSERT(0);
	}
	for (i = 0; i < table_size; i++)
		(*putfunc)(table, i, val);
}

static void
setup_map(void)
{

	if ((done_flag & DF_SRC_ZONE)==0) {
		fprintf(stderr, "SRC_ZONE is mandatory.\n");
		exit(1);
	}
	if ((done_flag & DF_DST_UNIT_BITS)==0) {
		fprintf(stderr, "DST_UNIT_BITS is mandatory.\n");
		exit(1);
	}

	if ((done_flag & DF_DST_INVALID) == 0)
		dst_invalid = 0xFFFFFFFF;
	if ((done_flag & DF_DST_ILSEQ) == 0)
		dst_ilseq = 0xFFFFFFFE;
	if ((done_flag & DF_OOB_MODE) == 0)
		oob_mode = _CITRUS_MAPPER_STD_OOB_NONIDENTICAL;

	alloc_table();
}

static void
create_rowcol_info(struct _region *r)
{
	void *ptr;
	size_t ofs, i, len;

	ofs = 0;
	ptr = malloc(_CITRUS_MAPPER_STD_ROWCOL_INFO_SIZE);
	if (ptr == NULL)
		err(EXIT_FAILURE, "malloc");
	put32(ptr, ofs, rowcol_bits); ofs++;
	put32(ptr, ofs, dst_invalid); ofs++;

	/* XXX: keep backward compatibility */
	switch (rowcol_len) {
	case 1:
		put32(ptr, ofs, 0); ofs++;
		put32(ptr, ofs, 0); ofs++;
	/*FALLTHROUGH*/
	case 2:
		len = 0;
		break;
	default:
		len = rowcol_len;
	}
	for (i = 0; i < rowcol_len; ++i) {
		put32(ptr, ofs, rowcol[i].begin); ofs++;
		put32(ptr, ofs, rowcol[i].end); ofs++;
	}
	put32(ptr, ofs, dst_unit_bits); ofs++;
	put32(ptr, ofs, len); ofs++;

	_region_init(r, ptr, ofs * 4);
}


static void
create_rowcol_ext_ilseq_info(struct _region *r)
{
	void *ptr;
	size_t ofs;

	ofs = 0;
	ptr = malloc(_CITRUS_MAPPER_STD_ROWCOL_EXT_ILSEQ_SIZE);
	if (ptr==NULL)
		err(EXIT_FAILURE, "malloc");

	put32(ptr, ofs, oob_mode); ofs++;
	put32(ptr, ofs, dst_ilseq); ofs++;

	_region_init(r, ptr, _CITRUS_MAPPER_STD_ROWCOL_EXT_ILSEQ_SIZE);
}

#define CHKERR(ret, func, a)						\
do {									\
	ret = func a;							\
	if (ret)							\
		errx(EXIT_FAILURE, "%s: %s", #func, strerror(ret));	\
} while (/*CONSTCOND*/0)

static void
dump_file(void)
{
	FILE *fp;
	int ret;
	struct _db_factory *df;
	struct _region data;
	void *serialized;
	size_t size;

	/*
	 * build database
	 */
	CHKERR(ret, _db_factory_create, (&df, _db_hash_std, NULL));

	/* store type */
	CHKERR(ret, _db_factory_addstr_by_s,
	       (df, _CITRUS_MAPPER_STD_SYM_TYPE,
		_CITRUS_MAPPER_STD_TYPE_ROWCOL));

	/* store info */
	create_rowcol_info(&data);
	CHKERR(ret, _db_factory_add_by_s,
	       (df, _CITRUS_MAPPER_STD_SYM_INFO, &data, 1));

	/* ilseq extension */
	create_rowcol_ext_ilseq_info(&data);
	CHKERR(ret, _db_factory_add_by_s,
	       (df, _CITRUS_MAPPER_STD_SYM_ROWCOL_EXT_ILSEQ, &data, 1));

	/* store table */
	_region_init(&data, table, table_size*dst_unit_bits/8);
	CHKERR(ret, _db_factory_add_by_s,
	       (df, _CITRUS_MAPPER_STD_SYM_TABLE, &data, 1));

	/*
	 * dump database to file
	 */
	if (output)
		fp = fopen(output, "wb");
	else
		fp = stdout;

	if (fp == NULL) {
		perror("fopen");
		exit(1);
	}

	/* dump database body */
	size = _db_factory_calc_size(df);
	serialized = malloc(size);
	_region_init(&data, serialized, size);
	CHKERR(ret, _db_factory_serialize,
	       (df, _CITRUS_MAPPER_STD_MAGIC, &data));
	if (fwrite(serialized, size, 1, fp) != 1)
		err(EXIT_FAILURE, "fwrite");

	fclose(fp);
}

static void
/*ARGSUSED*/
set_type(int type)
{

	if (done_flag & DF_TYPE) {
		warning("TYPE is duplicated. ignored this one");
		return;
	}

	map_type = type;

	done_flag |= DF_TYPE;
}
static void
/*ARGSUSED*/
set_name(char *str)
{

	if (done_flag & DF_NAME) {
		warning("NAME is duplicated. ignored this one");
		return;
	}

	map_name = str;

	done_flag |= DF_NAME;
}
static void
set_src_zone(u_int32_t val)
{
	size_t i;
	linear_zone_t *p;

	if (done_flag & DF_SRC_ZONE) {
		warning("SRC_ZONE is duplicated. ignored this one");
		return;
	}
	rowcol_bits = val;

	/* sanity check */
	switch (rowcol_bits) {
	case 8: case 16: case 32:
		if (rowcol_len <= 32 / rowcol_bits)
			break;
	/*FALLTHROUGH*/
	default: 
		goto bad;
	}
	rowcol_mask = 1 << (rowcol_bits - 1);
	rowcol_mask |= rowcol_mask - 1;
	for (i = 0; i < rowcol_len; ++i) {
		p = &rowcol[i];
		_DIAGASSERT(p->begin <= p->end);
		if (p->end > rowcol_mask)
			goto bad;
	}
	done_flag |= DF_SRC_ZONE;
	return;

bad:
	yyerror("Illegal argument for SRC_ZONE");
}
static void
set_dst_invalid(u_int32_t val)
{

	if (done_flag & DF_DST_INVALID) {
		warning("DST_INVALID is duplicated. ignored this one");
		return;
	}

	dst_invalid = val;

	done_flag |= DF_DST_INVALID;
}
static void
set_dst_ilseq(u_int32_t val)
{

	if (done_flag & DF_DST_ILSEQ) {
		warning("DST_ILSEQ is duplicated. ignored this one");
		return;
	}

	dst_ilseq = val;

	done_flag |= DF_DST_ILSEQ;
}
static void
set_oob_mode(u_int32_t val)
{

	if (done_flag & DF_OOB_MODE) {
		warning("OOB_MODE is duplicated. ignored this one");
		return;
	}

	oob_mode = val;

	done_flag |= DF_OOB_MODE;
}
static void
set_dst_unit_bits(u_int32_t val)
{

	if (done_flag & DF_DST_UNIT_BITS) {
		warning("DST_UNIT_BITS is duplicated. ignored this one");
		return;
	}

	switch (val) {
	case 8:
		putfunc = &put8;
		dst_unit_bits = val;
		break;
	case 16:
		putfunc = &put16;
		dst_unit_bits = val;
		break;
	case 32:
		putfunc = &put32;
		dst_unit_bits = val;
		break;
	default:
		yyerror("Illegal argument for DST_UNIT_BITS");
	}
	done_flag |= DF_DST_UNIT_BITS;
}
static int
check_src(u_int32_t begin, u_int32_t end)
{
	size_t i;
	linear_zone_t *p;
	u_int32_t m, n;

	if (begin > end)
		return 1;
	if (begin < end) {
		m = begin & ~rowcol_mask;
		n = end & ~rowcol_mask;
		if (m != n)
			return 1;
	}
	for (i = rowcol_len * rowcol_bits, p = &rowcol[0]; i > 0; ++p) {
		i -= rowcol_bits;
		m = (begin >> i) & rowcol_mask;
		if (m < p->begin || m > p->end)
			return 1;
	}
	if (begin < end) {
		n = end & rowcol_mask;
		_DIAGASSERT(p > rowcol);
		--p;
		if (n < p->begin || n > p->end)
			return 1;
	}
	return 0;
}
static void
store(const linear_zone_t *lz, u_int32_t dst, int inc)
{
	size_t i, ofs;
	linear_zone_t *p;
	u_int32_t n;

	ofs = 0;
	for (i = rowcol_len * rowcol_bits, p = &rowcol[0]; i > 0; ++p) {
		i -= rowcol_bits;
		n = ((lz->begin >> i) & rowcol_mask) - p->begin;
		ofs = (ofs * p->width) + n;
	}
	n = lz->width;
	while (n-- > 0) {
		(*putfunc)(table, ofs++, dst);
		if (inc)
			dst++;
	}
}
static void
set_range(u_int32_t begin, u_int32_t end)
{
	linear_zone_t *p;

	if (rowcol_len >= _CITRUS_MAPPER_STD_ROWCOL_MAX)
		goto bad;
	p = &rowcol[rowcol_len++];

	if (begin > end)
		goto bad;
	p->begin = begin, p->end = end;
	p->width = end - begin + 1;

	return;

bad:
	yyerror("Illegal argument for SRC_ZONE");
}
static void
set_src(linear_zone_t *lz, u_int32_t begin, u_int32_t end)
{
	_DIAGASSERT(lz != NULL);

	if (check_src(begin, end) != 0)
		yyerror("illegal zone");

	lz->begin = begin, lz->end = end;
	lz->width = end - begin + 1;

	src_next = end + 1;
}

static void
do_mkdb(FILE *in)
{
	int ret;
	FILE *out;

        /* dump DB to file */
	if (output)
		out = fopen(output, "wb");
	else
		out = stdout;

	if (out==NULL)
		err(EXIT_FAILURE, "fopen");

	ret = _lookup_factory_convert(out, in);
	fclose(out);
	if (ret && output)
		unlink(output); /* dump failure */
}

static void
do_mkpv(FILE *in)
{
	int ret;
	FILE *out;

        /* dump pivot to file */
	if (output)
		out = fopen(output, "wb");
	else
		out = stdout;

	if (out == NULL)
		err(EXIT_FAILURE, "fopen");

	ret = _pivot_factory_convert(out, in);
	fclose(out);
	if (ret && output)
		unlink(output); /* dump failure */
	if (ret)
 		errc(EXIT_FAILURE, ret, "");
}

__dead static void
usage(void)
{
	fprintf(stderr, "Usage: %s [-m|-p] [-d] [-o outfile] [infile]\n",
	    getprogname());
	exit(EXIT_FAILURE);
}

int
main(int argc, char **argv)
{
	int ch;
	extern char *optarg;
	extern int optind;
	FILE *in = NULL;
	int mkdb = 0, mkpv = 0;

	while ((ch=getopt(argc, argv, "do:mp")) != EOF) {
		switch (ch) {
		case 'd':
			debug=1;
			break;
		case 'o':
			output = strdup(optarg);
			break;
		case 'm':
			mkdb = 1;
			break;
		case 'p':
			mkpv = 1;
			break;
		default:
			usage();
		}
	}

	argc-=optind;
	argv+=optind;
	switch (argc) {
	case 0:
		in = stdin;
		break;
	case 1:
		in = fopen(argv[0], "r");
		if (!in)
			err(EXIT_FAILURE, "%s", argv[0]);
		break;
	default:
		usage();
	}

	if (mkdb)
		do_mkdb(in);
	else if (mkpv)
		do_mkpv(in);
	else {
		yyin = in;
		yyparse();
	}

	return (0);
}
#line 968 "yacc.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 127 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{ dump_file(); }
break;
case 11:
#line 139 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{ set_name(yystack.l_mark[0].s_value); yystack.l_mark[0].s_value = NULL; }
break;
case 12:
#line 140 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{ set_type(yystack.l_mark[0].i_value); }
break;
case 13:
#line 141 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{ yyval.i_value = R_ROWCOL; }
break;
case 14:
#line 142 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{ set_range(yystack.l_mark[-2].i_value, yystack.l_mark[0].i_value); }
break;
case 17:
#line 147 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{ set_src_zone(yystack.l_mark[0].i_value); }
break;
case 18:
#line 148 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{
			yyval.i_value = 32;
		}
break;
case 19:
#line 151 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{
			yyval.i_value = yystack.l_mark[0].i_value;
		}
break;
case 20:
#line 155 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{ set_dst_invalid(yystack.l_mark[0].i_value); }
break;
case 21:
#line 156 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{ set_dst_ilseq(yystack.l_mark[0].i_value); }
break;
case 22:
#line 157 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{ set_dst_unit_bits(yystack.l_mark[0].i_value); }
break;
case 23:
#line 158 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{ set_oob_mode(yystack.l_mark[0].i_value); }
break;
case 24:
#line 160 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{ yyval.i_value = _CITRUS_MAPPER_STD_OOB_NONIDENTICAL; }
break;
case 25:
#line 161 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{ yyval.i_value = _CITRUS_MAPPER_STD_OOB_ILSEQ; }
break;
case 27:
#line 164 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{ setup_map(); }
break;
case 30:
#line 170 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{ store(&yystack.l_mark[-2].lz_value, yystack.l_mark[0].i_value, 0); }
break;
case 31:
#line 172 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{ store(&yystack.l_mark[-3].lz_value, yystack.l_mark[-1].i_value, 1); }
break;
case 32:
#line 174 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{
			yyval.i_value = yystack.l_mark[0].i_value;
		}
break;
case 33:
#line 178 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{
			yyval.i_value = dst_invalid;
		}
break;
case 34:
#line 182 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{
			yyval.i_value = dst_ilseq;
		}
break;
case 35:
#line 187 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{
			set_src(&yyval.lz_value, src_next, src_next);
		}
break;
case 36:
#line 191 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{
			set_src(&yyval.lz_value, yystack.l_mark[0].i_value, yystack.l_mark[0].i_value);
		}
break;
case 37:
#line 195 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{
			set_src(&yyval.lz_value, yystack.l_mark[-2].i_value, yystack.l_mark[0].i_value);
		}
break;
case 38:
#line 199 "/home/donz/minix/tools/mkcsmapper/../../usr.bin/mkcsmapper/yacc.y"
	{
			set_src(&yyval.lz_value, src_next, yystack.l_mark[0].i_value);
		}
break;
#line 1284 "yacc.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
