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

#line 4 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
/*-
 * Copyright (c) 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Paul Borman at Krystal Technologies.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
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
#ifndef lint
#if 0
static char sccsid[] = "@(#)yacc.y	8.1 (Berkeley) 6/6/93";
static char rcsid[] = "$FreeBSD$";
#else
__RCSID("$NetBSD: yacc.y,v 1.31 2010/06/13 04:14:57 tnozaki Exp $");
#endif
#endif /* not lint */

#include <sys/types.h>
#include <netinet/in.h>	/* Needed by <arpa/inet.h> on NetBSD 1.5. */
#include <arpa/inet.h>	/* Needed for htonl on POSIX systems. */

#include <err.h>
#include <locale.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#include "runetype_file.h"

#include "ldef.h"

const char	*locale_file = "<stdout>";

rune_map	maplower = { { 0, }, };
rune_map	mapupper = { { 0, }, };
rune_map	types = { { 0, }, };

_FileRuneLocale new_locale = { { 0, }, };

size_t rl_variable_len = (size_t)0; 
void *rl_variable = NULL;

__nbrune_t	charsetbits = (__nbrune_t)0x00000000;
#if 0
__nbrune_t	charsetmask = (__nbrune_t)0x0000007f;
#endif
__nbrune_t	charsetmask = (__nbrune_t)0xffffffff;

void set_map __P((rune_map *, rune_list *, u_int32_t));
void set_digitmap __P((rune_map *, rune_list *));
void add_map __P((rune_map *, rune_list *, u_int32_t));

int		main __P((int, char *[]));
void		usage __P((void));
int		yyerror __P((const char *s));
void		*xmalloc __P((unsigned int sz));
u_int32_t	*xlalloc __P((unsigned int sz));
u_int32_t	*xrelalloc __P((u_int32_t *old, unsigned int sz));
void		dump_tables __P((void));
int		yyparse __P((void));
extern int	yylex __P((void));

/* mklocaledb.c */
extern void mklocaledb __P((const char *, FILE *, FILE *));

#line 103 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union	{
    __nbrune_t	rune;
    int		i;
    char	*str;

    rune_list	*list;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 136 "yacc.c"

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

#define RUNE 257
#define LBRK 258
#define RBRK 259
#define THRU 260
#define MAPLOWER 261
#define MAPUPPER 262
#define DIGITMAP 263
#define LIST 264
#define VARIABLE 265
#define CHARSET 266
#define ENCODING 267
#define INVALID 268
#define STRING 269
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    3,    3,    4,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    1,    1,    1,    1,    2,    2,
    2,    2,
};
static const YYINT yylen[] = {                            2,
    0,    1,    1,    2,    2,    1,    2,    3,    2,    2,
    2,    2,    2,    2,    1,    3,    2,    4,    4,    5,
    7,    8,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    6,    0,    0,    0,    0,    0,
    3,    0,    0,    0,    0,    0,    0,    0,    9,    5,
   10,    4,    0,    0,    0,    0,    8,    0,    0,    0,
   16,    0,   19,    0,    0,    0,   18,    0,   20,    0,
    0,    0,   21,    0,   22,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  261,  262,  263,  264,  265,  266,  267,  268,  271,  274,
  275,  258,  273,  273,  273,  257,  272,  257,  269,  269,
  257,  275,  257,  258,  260,  257,  257,  257,  260,  257,
  257,  260,  259,  257,  257,  260,  257,   58,  259,  257,
  257,   58,  259,  257,  259,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          9,
   17,   13,   10,   11,
};
static const YYINT yysindex[] = {                      -259,
 -248, -248, -248, -238,    0, -257, -249, -235,    0, -259,
    0, -234, -233, -233, -233, -236, -231, -230,    0,    0,
    0,    0, -246, -229, -227, -228,    0, -226, -223, -242,
    0, -222,    0,  -27, -221, -218,    0, -217,    0,  -22,
 -216, -215,    0, -213,    0,
};
static const YYINT yyrindex[] = {                        41,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   44,
    0,    0,   21,   29,   37,    1,   45,   53,    0,    0,
    0,    0,    0,    0,    0,   13,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,   14,    0,   38,
};
#define YYTABLESIZE 321
static const YYINT yytable[] = {                         18,
   15,    1,    2,    3,    4,    5,    6,    7,    8,   12,
   28,   19,   17,   29,   35,   14,   15,   36,   16,   20,
   12,   21,   23,   25,   24,   26,   27,   30,   13,   31,
   38,   32,   33,   34,   37,   42,   14,   39,   40,   41,
    1,   44,   43,    2,   11,   45,    0,   22,    0,    0,
    0,    0,    7,    0,    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   15,    0,    0,
    0,   15,   15,   15,   15,   15,   15,   15,   15,   17,
    0,    0,    0,   17,   17,   17,   17,   17,   17,   17,
   17,   12,   12,   12,   12,   12,   12,   12,   12,   13,
   13,   13,   13,   13,   13,   13,   13,   14,   14,   14,
   14,   14,   14,   14,   14,   11,   11,   11,   11,   11,
   11,   11,   11,    7,    7,    7,    7,    7,    7,    7,
    7,
};
static const YYINT yycheck[] = {                        257,
    0,  261,  262,  263,  264,  265,  266,  267,  268,  258,
  257,  269,    0,  260,  257,    2,    3,  260,  257,  269,
    0,  257,  257,  260,  258,  257,  257,  257,    0,  257,
   58,  260,  259,  257,  257,   58,    0,  259,  257,  257,
    0,  257,  259,    0,    0,  259,   -1,   10,   -1,   -1,
   -1,   -1,    0,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,   -1,
   -1,  261,  262,  263,  264,  265,  266,  267,  268,  257,
   -1,   -1,   -1,  261,  262,  263,  264,  265,  266,  267,
  268,  261,  262,  263,  264,  265,  266,  267,  268,  261,
  262,  263,  264,  265,  266,  267,  268,  261,  262,  263,
  264,  265,  266,  267,  268,  261,  262,  263,  264,  265,
  266,  267,  268,  261,  262,  263,  264,  265,  266,  267,
  268,
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
};
#endif
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 269
#define YYUNDFTOKEN 276
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"':'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","RUNE","LBRK","RBRK","THRU",
"MAPLOWER","MAPUPPER","DIGITMAP","LIST","VARIABLE","CHARSET","ENCODING",
"INVALID","STRING","$accept","locale","list","map","table","entry",
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : locale",
"locale :",
"locale : table",
"table : entry",
"table : table entry",
"entry : ENCODING STRING",
"entry : VARIABLE",
"entry : CHARSET RUNE",
"entry : CHARSET RUNE RUNE",
"entry : CHARSET STRING",
"entry : INVALID RUNE",
"entry : LIST list",
"entry : MAPLOWER map",
"entry : MAPUPPER map",
"entry : DIGITMAP map",
"list : RUNE",
"list : RUNE THRU RUNE",
"list : list RUNE",
"list : list RUNE THRU RUNE",
"map : LBRK RUNE RUNE RBRK",
"map : map LBRK RUNE RUNE RBRK",
"map : LBRK RUNE THRU RUNE ':' RUNE RBRK",
"map : map LBRK RUNE THRU RUNE ':' RUNE RBRK",

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
#line 259 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"

int debug = 0;
FILE *ofile;

int
main(ac, av)
	int ac;
	char *av[];
{
    int x;
    const char *locale_type;

    extern char *optarg;
    extern int optind;

    locale_type = NULL;
    while ((x = getopt(ac, av, "do:t:")) != EOF) {
	switch(x) {
	case 'd':
	    debug = 1;
	    break;
	case 'o':
	    locale_file = optarg;
	    if ((ofile = fopen(locale_file, "w")) == 0)
		err(1, "unable to open output file %s", locale_file);
	    break;
        case 't':
	    locale_type = optarg;
            break;
	default:
	    usage();
	}
    }

    switch (ac - optind) {
    case 0:
	break;
    case 1:
	if (freopen(av[optind], "r", stdin) == 0)
	    err(1, "unable to open input file %s", av[optind]);
	break;
    default:
	usage();
    }

    if (ofile == NULL)
	ofile = stdout;
    if (locale_type != NULL && strcasecmp(locale_type, "CTYPE")) {
	mklocaledb(locale_type, stdin, ofile);
	return 0;
    }

    for (x = 0; x < _CTYPE_CACHE_SIZE; ++x) {
	mapupper.map[x] = x;
	maplower.map[x] = x;
    }

    new_locale.frl_invalid_rune = htonl((u_int32_t)_DEFAULT_INVALID_RUNE);
    memcpy(new_locale.frl_magic, _RUNECT10_MAGIC, sizeof(new_locale.frl_magic));

    yyparse();

    return 0;

}

void
usage()
{
    fprintf(stderr,
	"usage: mklocale [-d] [-o output] [-t type] [source]\n");

    exit(1);
}

int
yyerror(s)
	const char *s;
{
    fprintf(stderr, "%s\n", s);

    return 0;
}

void *
xmalloc(sz)
	unsigned int sz;
{
    void *r = malloc(sz);
    if (!r) {
	perror("xmalloc");
	abort();
    }
    return(r);
}

u_int32_t *
xlalloc(sz)
	unsigned int sz;
{
    u_int32_t *r = (u_int32_t *)malloc(sz * sizeof(u_int32_t));
    if (!r) {
	perror("xlalloc");
	abort();
    }
    return(r);
}

u_int32_t *
xrelalloc(old, sz)
	u_int32_t *old;
	unsigned int sz;
{
    u_int32_t *r = (u_int32_t *)realloc((char *)old,
						sz * sizeof(u_int32_t));
    if (!r) {
	perror("xrelalloc");
	abort();
    }
    return(r);
}

void
set_map(map, list, flag)
	rune_map *map;
	rune_list *list;
	u_int32_t flag;
{
    list->map &= charsetmask;
    list->map |= charsetbits;
    while (list) {
	rune_list *nlist = list->next;
	add_map(map, list, flag);
	list = nlist;
    }
}

void
set_digitmap(map, list)
	rune_map *map;
	rune_list *list;
{
    __nbrune_t i;

    while (list) {
	rune_list *nlist = list->next;
	for (i = list->min; i <= list->max; ++i) {
	    if (list->map + (i - list->min)) {
		rune_list *tmp = (rune_list *)xmalloc(sizeof(rune_list));
		tmp->min = i;
		tmp->max = i;
		add_map(map, tmp, list->map + (i - list->min));
	    }
	}
	free(list);
	list = nlist;
    }
}

void
add_map(map, list, flag)
	rune_map *map;
	rune_list *list;
	u_int32_t flag;
{
    __nbrune_t i;
    rune_list *lr = 0;
    rune_list *r;
    __nbrune_t run;

    while (list->min < _CTYPE_CACHE_SIZE && list->min <= list->max) {
	if (flag)
	    map->map[list->min++] |= flag;
	else
	    map->map[list->min++] = list->map++;
    }

    if (list->min > list->max) {
	free(list);
	return;
    }

    run = list->max - list->min + 1;

    if (!(r = map->root) || (list->max < r->min - 1)
			 || (!flag && list->max == r->min - 1)) {
	if (flag) {
	    list->types = xlalloc(run);
	    for (i = 0; i < run; ++i)
		list->types[i] = flag;
	}
	list->next = map->root;
	map->root = list;
	return;
    }

    for (r = map->root; r && r->max + 1 < list->min; r = r->next)
	lr = r;

    if (!r) {
	/*
	 * We are off the end.
	 */
	if (flag) {
	    list->types = xlalloc(run);
	    for (i = 0; i < run; ++i)
		list->types[i] = flag;
	}
	list->next = 0;
	lr->next = list;
	return;
    }

    if (list->max < r->min - 1) {
	/*
	 * We come before this range and we do not intersect it.
	 * We are not before the root node, it was checked before the loop
	 */
	if (flag) {
	    list->types = xlalloc(run);
	    for (i = 0; i < run; ++i)
		list->types[i] = flag;
	}
	list->next = lr->next;
	lr->next = list;
	return;
    }

    /*
     * At this point we have found that we at least intersect with
     * the range pointed to by `r', we might intersect with one or
     * more ranges beyond `r' as well.
     */

    if (!flag && list->map - list->min != r->map - r->min) {
	/*
	 * There are only two cases when we are doing case maps and
	 * our maps needn't have the same offset.  When we are adjoining
	 * but not intersecting.
	 */
	if (list->max + 1 == r->min) {
	    lr->next = list;
	    list->next = r;
	    return;
	}
	if (list->min - 1 == r->max) {
	    list->next = r->next;
	    r->next = list;
	    return;
	}
	fprintf(stderr, "Error: conflicting map entries\n");
	exit(1);
    }

    if (list->min >= r->min && list->max <= r->max) {
	/*
	 * Subset case.
	 */

	if (flag) {
	    for (i = list->min; i <= list->max; ++i)
		r->types[i - r->min] |= flag;
	}
	free(list);
	return;
    }
    if (list->min <= r->min && list->max >= r->max) {
	/*
	 * Superset case.  Make him big enough to hold us.
	 * We might need to merge with the guy after him.
	 */
	if (flag) {
	    list->types = xlalloc(list->max - list->min + 1);

	    for (i = list->min; i <= list->max; ++i)
		list->types[i - list->min] = flag;

	    for (i = r->min; i <= r->max; ++i)
		list->types[i - list->min] |= r->types[i - r->min];

	    free(r->types);
	    r->types = list->types;
	} else {
	    r->map = list->map;
	}
	r->min = list->min;
	r->max = list->max;
	free(list);
    } else if (list->min < r->min) {
	/*
	 * Our tail intersects his head.
	 */
	if (flag) {
	    list->types = xlalloc(r->max - list->min + 1);

	    for (i = r->min; i <= r->max; ++i)
		list->types[i - list->min] = r->types[i - r->min];

	    for (i = list->min; i < r->min; ++i)
		list->types[i - list->min] = flag;

	    for (i = r->min; i <= list->max; ++i)
		list->types[i - list->min] |= flag;

	    free(r->types);
	    r->types = list->types;
	} else {
	    r->map = list->map;
	}
	r->min = list->min;
	free(list);
	return;
    } else {
	/*
	 * Our head intersects his tail.
	 * We might need to merge with the guy after him.
	 */
	if (flag) {
	    r->types = xrelalloc(r->types, list->max - r->min + 1);

	    for (i = list->min; i <= r->max; ++i)
		r->types[i - r->min] |= flag;

	    for (i = r->max+1; i <= list->max; ++i)
		r->types[i - r->min] = flag;
	}
	r->max = list->max;
	free(list);
    }

    /*
     * Okay, check to see if we grew into the next guy(s)
     */
    while ((lr = r->next) && r->max >= lr->min) {
	if (flag) {
	    if (r->max >= lr->max) {
		/*
		 * Good, we consumed all of him.
		 */
		for (i = lr->min; i <= lr->max; ++i)
		    r->types[i - r->min] |= lr->types[i - lr->min];
	    } else {
		/*
		 * "append" him on to the end of us.
		 */
		r->types = xrelalloc(r->types, lr->max - r->min + 1);

		for (i = lr->min; i <= r->max; ++i)
		    r->types[i - r->min] |= lr->types[i - lr->min];

		for (i = r->max+1; i <= lr->max; ++i)
		    r->types[i - r->min] = lr->types[i - lr->min];

		r->max = lr->max;
	    }
	} else {
	    if (lr->max > r->max)
		r->max = lr->max;
	}

	r->next = lr->next;

	if (flag)
	    free(lr->types);
	free(lr);
    }
}

void
dump_tables()
{
    int x, n;
    rune_list *list;
    FILE *fp = ofile;
    u_int32_t nranges;

    /*
     * See if we can compress some of the istype arrays
     */
    for(list = types.root; list; list = list->next) {
	list->map = list->types[0];
	for (x = 1; x < list->max - list->min + 1; ++x) {
	    if (list->types[x] != list->map) {
		list->map = 0;
		break;
	    }
	}
    }

    /*
     * Fill in our tables.  Do this in network order so that
     * diverse machines have a chance of sharing data.
     * (Machines like Crays cannot share with little machines due to
     *  word size.  Sigh.  We tried.)
     */
    for (x = 0; x < _CTYPE_CACHE_SIZE; ++x) {
	new_locale.frl_runetype[x] = htonl(types.map[x]);
	new_locale.frl_maplower[x] = htonl(maplower.map[x]);
	new_locale.frl_mapupper[x] = htonl(mapupper.map[x]);
    }

    /*
     * Count up how many ranges we will need for each of the extents.
     */
    list = types.root;

    nranges = (u_int32_t)0;
    while (list) {
	++nranges;
	list = list->next;
    }
    new_locale.frl_runetype_ext.frr_nranges =
	htonl(nranges);

    list = maplower.root;

    nranges = (u_int32_t)0;
    while (list) {
	++nranges;
	list = list->next;
    }
    new_locale.frl_maplower_ext.frr_nranges =
	htonl(nranges);

    list = mapupper.root;

    nranges = (u_int32_t)0;
    while (list) {
	++nranges;
	list = list->next;
    }
    new_locale.frl_mapupper_ext.frr_nranges =
	htonl(nranges);

    /*
     * Okay, we are now ready to write the new locale file.
     */

    /*
     * PART 1: The _RuneLocale structure
     */
    if (fwrite((char *)&new_locale, sizeof(new_locale), 1, fp) != 1)
	err(1, "writing _FileRuneLocale to %s", locale_file);
    /*
     * PART 2: The runetype_ext structures (not the actual tables)
     */
    for (list = types.root, n = 0; list != NULL; list = list->next, n++) {
	_FileRuneEntry re;

	memset(&re, 0, sizeof(re));
	re.fre_min = htonl(list->min);
	re.fre_max = htonl(list->max);
	re.fre_map = htonl(list->map);

	if (fwrite((char *)&re, sizeof(re), 1, fp) != 1)
	    err(1, "writing runetype_ext #%d to %s", n, locale_file);
    }
    /*
     * PART 3: The maplower_ext structures
     */
    for (list = maplower.root, n = 0; list != NULL; list = list->next, n++) {
	_FileRuneEntry re;

	memset(&re, 0, sizeof(re));
	re.fre_min = htonl(list->min);
	re.fre_max = htonl(list->max);
	re.fre_map = htonl(list->map);

	if (fwrite((char *)&re, sizeof(re), 1, fp) != 1)
	    err(1, "writing maplower_ext #%d to %s", n, locale_file);
    }
    /*
     * PART 4: The mapupper_ext structures
     */
    for (list = mapupper.root, n = 0; list != NULL; list = list->next, n++) {
	_FileRuneEntry re;

	memset(&re, 0, sizeof(re));
	re.fre_min = htonl(list->min);
	re.fre_max = htonl(list->max);
	re.fre_map = htonl(list->map);

	if (fwrite((char *)&re, sizeof(re), 1, fp) != 1)
	    err(1, "writing mapupper_ext #%d to %s", n, locale_file);
    }
    /*
     * PART 5: The runetype_ext tables
     */
    for (list = types.root, n = 0; list != NULL; list = list->next, n++) {
	for (x = 0; x < list->max - list->min + 1; ++x)
	    list->types[x] = htonl(list->types[x]);

	if (!list->map) {
	    if (fwrite((char *)list->types,
		       (list->max - list->min + 1) * sizeof(u_int32_t),
		       1, fp) != 1)
		err(1, "writing runetype_ext table #%d to %s", n, locale_file);
	}
    }
    /*
     * PART 5: And finally the variable data
     */
    if (rl_variable_len != 0 &&
	fwrite((char *)rl_variable, rl_variable_len, 1, fp) != 1)
	err(1, "writing variable data to %s", locale_file);
    fclose(fp);

    if (!debug)
	return;

    if (new_locale.frl_encoding[0])
	fprintf(stderr, "ENCODING	%.*s\n",
	    (int)sizeof(new_locale.frl_encoding), new_locale.frl_encoding);
    if (rl_variable)
	fprintf(stderr, "VARIABLE	%.*s\n",
	    (int)rl_variable_len, (char *)rl_variable);

    fprintf(stderr, "\nMAPLOWER:\n\n");

    for (x = 0; x < _CTYPE_CACHE_SIZE; ++x) {
	if (isprint(maplower.map[x]))
	    fprintf(stderr, " '%c'", (int)maplower.map[x]);
	else if (maplower.map[x])
	    fprintf(stderr, "%04x", maplower.map[x]);
	else
	    fprintf(stderr, "%4x", 0);
	if ((x & 0xf) == 0xf)
	    fprintf(stderr, "\n");
	else
	    fprintf(stderr, " ");
    }
    fprintf(stderr, "\n");

    for (list = maplower.root; list; list = list->next)
	fprintf(stderr, "\t%04x - %04x : %04x\n", list->min, list->max, list->map);

    fprintf(stderr, "\nMAPUPPER:\n\n");

    for (x = 0; x < _CTYPE_CACHE_SIZE; ++x) {
	if (isprint(mapupper.map[x]))
	    fprintf(stderr, " '%c'", (int)mapupper.map[x]);
	else if (mapupper.map[x])
	    fprintf(stderr, "%04x", mapupper.map[x]);
	else
	    fprintf(stderr, "%4x", 0);
	if ((x & 0xf) == 0xf)
	    fprintf(stderr, "\n");
	else
	    fprintf(stderr, " ");
    }
    fprintf(stderr, "\n");

    for (list = mapupper.root; list; list = list->next)
	fprintf(stderr, "\t%04x - %04x : %04x\n", list->min, list->max, list->map);


    fprintf(stderr, "\nTYPES:\n\n");

    for (x = 0; x < _CTYPE_CACHE_SIZE; ++x) {
	u_int32_t r = types.map[x];

	if (r) {
	    if (isprint(x))
		fprintf(stderr, " '%c':%2d", x, (int)(r & 0xff));
	    else
		fprintf(stderr, "%04x:%2d", x, (int)(r & 0xff));

	    fprintf(stderr, " %4s", (r & _RUNETYPE_A) ? "alph" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_C) ? "ctrl" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_D) ? "dig" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_G) ? "graf" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_L) ? "low" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_P) ? "punc" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_S) ? "spac" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_U) ? "upp" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_X) ? "xdig" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_B) ? "blnk" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_R) ? "prnt" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_I) ? "ideo" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_T) ? "spec" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_Q) ? "phon" : "");
	    fprintf(stderr, "\n");
	}
    }

    for (list = types.root; list; list = list->next) {
	if (list->map && list->min + 3 < list->max) {
	    u_int32_t r = list->map;

	    fprintf(stderr, "%04x:%2d", list->min, r & 0xff);

	    fprintf(stderr, " %4s", (r & _RUNETYPE_A) ? "alph" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_C) ? "ctrl" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_D) ? "dig" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_G) ? "graf" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_L) ? "low" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_P) ? "punc" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_S) ? "spac" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_U) ? "upp" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_X) ? "xdig" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_B) ? "blnk" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_R) ? "prnt" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_I) ? "ideo" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_T) ? "spec" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_Q) ? "phon" : "");
	    fprintf(stderr, "\n...\n");

	    fprintf(stderr, "%04x:%2d", list->max, r & 0xff);

	    fprintf(stderr, " %4s", (r & _RUNETYPE_A) ? "alph" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_C) ? "ctrl" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_D) ? "dig" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_G) ? "graf" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_L) ? "low" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_P) ? "punc" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_S) ? "spac" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_U) ? "upp" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_X) ? "xdig" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_B) ? "blnk" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_R) ? "prnt" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_I) ? "ideo" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_T) ? "spec" : "");
	    fprintf(stderr, " %4s", (r & _RUNETYPE_Q) ? "phon" : "");
            fprintf(stderr, " %1u", (unsigned)((r & _RUNETYPE_SWM)>>_RUNETYPE_SWS));
	    fprintf(stderr, "\n");
	} else 
	for (x = list->min; x <= list->max; ++x) {
	    u_int32_t r = ntohl(list->types[x - list->min]);

	    if (r) {
		fprintf(stderr, "%04x:%2d", x, (int)(r & 0xff));

		fprintf(stderr, " %4s", (r & _RUNETYPE_A) ? "alph" : "");
		fprintf(stderr, " %4s", (r & _RUNETYPE_C) ? "ctrl" : "");
		fprintf(stderr, " %4s", (r & _RUNETYPE_D) ? "dig" : "");
		fprintf(stderr, " %4s", (r & _RUNETYPE_G) ? "graf" : "");
		fprintf(stderr, " %4s", (r & _RUNETYPE_L) ? "low" : "");
		fprintf(stderr, " %4s", (r & _RUNETYPE_P) ? "punc" : "");
		fprintf(stderr, " %4s", (r & _RUNETYPE_S) ? "spac" : "");
		fprintf(stderr, " %4s", (r & _RUNETYPE_U) ? "upp" : "");
		fprintf(stderr, " %4s", (r & _RUNETYPE_X) ? "xdig" : "");
		fprintf(stderr, " %4s", (r & _RUNETYPE_B) ? "blnk" : "");
		fprintf(stderr, " %4s", (r & _RUNETYPE_R) ? "prnt" : "");
		fprintf(stderr, " %4s", (r & _RUNETYPE_I) ? "ideo" : "");
		fprintf(stderr, " %4s", (r & _RUNETYPE_T) ? "spec" : "");
		fprintf(stderr, " %4s", (r & _RUNETYPE_Q) ? "phon" : "");
                fprintf(stderr, " %1u", (unsigned)((r & _RUNETYPE_SWM)>>_RUNETYPE_SWS));
		fprintf(stderr, "\n");
	    }
	}
    }
}
#line 1081 "yacc.c"

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
case 2:
#line 133 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{ dump_tables(); }
break;
case 5:
#line 141 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{ strncpy(new_locale.frl_encoding, yystack.l_mark[0].str, sizeof(new_locale.frl_encoding)); }
break;
case 6:
#line 143 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{ rl_variable_len = strlen(yystack.l_mark[0].str) + 1;
		  rl_variable = strdup(yystack.l_mark[0].str);
		  new_locale.frl_variable_len = htonl((u_int32_t)rl_variable_len);
		}
break;
case 7:
#line 148 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{ charsetbits = yystack.l_mark[0].rune; charsetmask = 0x0000007f; }
break;
case 8:
#line 150 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{ charsetbits = yystack.l_mark[-1].rune; charsetmask = yystack.l_mark[0].rune; }
break;
case 9:
#line 152 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{ int final = yystack.l_mark[0].str[strlen(yystack.l_mark[0].str) - 1] & 0x7f;
		  charsetbits = final << 24;
		  if (yystack.l_mark[0].str[0] == '$') {
			charsetmask = 0x00007f7f;
			if (strchr(",-./", yystack.l_mark[0].str[1]))
				charsetbits |= 0x80;
			if (0xd0 <= final && final <= 0xdf)
				charsetmask |= 0x007f0000;
		  } else {
			charsetmask = 0x0000007f;
			if (strchr(",-./", yystack.l_mark[0].str[0]))
				charsetbits |= 0x80;
			if (strlen(yystack.l_mark[0].str) == 2 && yystack.l_mark[0].str[0] == '!')
				charsetbits |= ((0x80 | yystack.l_mark[0].str[0]) << 16);
		  }

		  /*
		   * special rules
		   */
		  if (charsetbits == ('B' << 24)
		   && charsetmask == 0x0000007f) {
			/*ASCII: 94B*/
			charsetbits = 0;
			charsetmask = 0x0000007f;
		  } else if (charsetbits == (('A' << 24) | 0x80)
		  	  && charsetmask == 0x0000007f) {
		  	/*Latin1: 96A*/
			charsetbits = 0x80;
			charsetmask = 0x0000007f;
		  }
		}
break;
case 10:
#line 184 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{ new_locale.frl_invalid_rune = htonl((u_int32_t)yystack.l_mark[0].rune); }
break;
case 11:
#line 186 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{ set_map(&types, yystack.l_mark[0].list, yystack.l_mark[-1].i); }
break;
case 12:
#line 188 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{ set_map(&maplower, yystack.l_mark[0].list, 0); }
break;
case 13:
#line 190 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{ set_map(&mapupper, yystack.l_mark[0].list, 0); }
break;
case 14:
#line 192 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{ set_digitmap(&types, yystack.l_mark[0].list); }
break;
case 15:
#line 196 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{
		    yyval.list = (rune_list *)malloc(sizeof(rune_list));
		    yyval.list->min = (yystack.l_mark[0].rune & charsetmask) | charsetbits;
		    yyval.list->max = (yystack.l_mark[0].rune & charsetmask) | charsetbits;
		    yyval.list->next = 0;
		}
break;
case 16:
#line 203 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{
		    yyval.list = (rune_list *)malloc(sizeof(rune_list));
		    yyval.list->min = (yystack.l_mark[-2].rune & charsetmask) | charsetbits;
		    yyval.list->max = (yystack.l_mark[0].rune & charsetmask) | charsetbits;
		    yyval.list->next = 0;
		}
break;
case 17:
#line 210 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{
		    yyval.list = (rune_list *)malloc(sizeof(rune_list));
		    yyval.list->min = (yystack.l_mark[0].rune & charsetmask) | charsetbits;
		    yyval.list->max = (yystack.l_mark[0].rune & charsetmask) | charsetbits;
		    yyval.list->next = yystack.l_mark[-1].list;
		}
break;
case 18:
#line 217 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{
		    yyval.list = (rune_list *)malloc(sizeof(rune_list));
		    yyval.list->min = (yystack.l_mark[-2].rune & charsetmask) | charsetbits;
		    yyval.list->max = (yystack.l_mark[0].rune & charsetmask) | charsetbits;
		    yyval.list->next = yystack.l_mark[-3].list;
		}
break;
case 19:
#line 226 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{
		    yyval.list = (rune_list *)malloc(sizeof(rune_list));
		    yyval.list->min = (yystack.l_mark[-2].rune & charsetmask) | charsetbits;
		    yyval.list->max = (yystack.l_mark[-2].rune & charsetmask) | charsetbits;
		    yyval.list->map = yystack.l_mark[-1].rune;
		    yyval.list->next = 0;
		}
break;
case 20:
#line 234 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{
		    yyval.list = (rune_list *)malloc(sizeof(rune_list));
		    yyval.list->min = (yystack.l_mark[-2].rune & charsetmask) | charsetbits;
		    yyval.list->max = (yystack.l_mark[-2].rune & charsetmask) | charsetbits;
		    yyval.list->map = yystack.l_mark[-1].rune;
		    yyval.list->next = yystack.l_mark[-4].list;
		}
break;
case 21:
#line 242 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{
		    yyval.list = (rune_list *)malloc(sizeof(rune_list));
		    yyval.list->min = (yystack.l_mark[-5].rune & charsetmask) | charsetbits;
		    yyval.list->max = (yystack.l_mark[-3].rune & charsetmask) | charsetbits;
		    yyval.list->map = yystack.l_mark[-1].rune;
		    yyval.list->next = 0;
		}
break;
case 22:
#line 250 "/home/donz/minix/tools/mklocale/../../usr.bin/mklocale/yacc.y"
	{
		    yyval.list = (rune_list *)malloc(sizeof(rune_list));
		    yyval.list->min = (yystack.l_mark[-5].rune & charsetmask) | charsetbits;
		    yyval.list->max = (yystack.l_mark[-3].rune & charsetmask) | charsetbits;
		    yyval.list->map = yystack.l_mark[-1].rune;
		    yyval.list->next = yystack.l_mark[-7].list;
		}
break;
#line 1436 "yacc.c"
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
