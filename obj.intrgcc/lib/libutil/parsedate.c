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

#ifndef yyparse
#define yyparse    __pdparse
#endif /* yyparse */

#ifndef yylex
#define yylex      __pdlex
#endif /* yylex */

#ifndef yyerror
#define yyerror    __pderror
#endif /* yyerror */

#ifndef yychar
#define yychar     __pdchar
#endif /* yychar */

#ifndef yyval
#define yyval      __pdval
#endif /* yyval */

#ifndef yylval
#define yylval     __pdlval
#endif /* yylval */

#ifndef yydebug
#define yydebug    __pddebug
#endif /* yydebug */

#ifndef yynerrs
#define yynerrs    __pdnerrs
#endif /* yynerrs */

#ifndef yyerrflag
#define yyerrflag  __pderrflag
#endif /* yyerrflag */

#ifndef yylhs
#define yylhs      __pdlhs
#endif /* yylhs */

#ifndef yylen
#define yylen      __pdlen
#endif /* yylen */

#ifndef yydefred
#define yydefred   __pddefred
#endif /* yydefred */

#ifndef yystos
#define yystos     __pdstos
#endif /* yystos */

#ifndef yydgoto
#define yydgoto    __pddgoto
#endif /* yydgoto */

#ifndef yysindex
#define yysindex   __pdsindex
#endif /* yysindex */

#ifndef yyrindex
#define yyrindex   __pdrindex
#endif /* yyrindex */

#ifndef yygindex
#define yygindex   __pdgindex
#endif /* yygindex */

#ifndef yytable
#define yytable    __pdtable
#endif /* yytable */

#ifndef yycheck
#define yycheck    __pdcheck
#endif /* yycheck */

#ifndef yyname
#define yyname     __pdname
#endif /* yyname */

#ifndef yyrule
#define yyrule     __pdrule
#endif /* yyrule */

#if YYBTYACC

#ifndef yycindex
#define yycindex   __pdcindex
#endif /* yycindex */

#ifndef yyctable
#define yyctable   __pdctable
#endif /* yyctable */

#endif /* YYBTYACC */

#define YYPREFIX "__pd"

#define YYPURE 1

#line 2 "/home/donz/minix/lib/libutil/parsedate.y"
/*
**  Originally written by Steven M. Bellovin <smb@research.att.com> while
**  at the University of North Carolina at Chapel Hill.  Later tweaked by
**  a couple of people on Usenet.  Completely overhauled by Rich $alz
**  <rsalz@bbn.com> and Jim Berets <jberets@bbn.com> in August, 1990;
**
**  This grammar has 10 shift/reduce conflicts.
**
**  This code is in the public domain and has no copyright.
*/
/* SUPPRESS 287 on yaccpar_sccsid *//* Unused static variable */
/* SUPPRESS 288 on yyerrlab *//* Label unused */

#include <sys/cdefs.h>
#ifdef __RCSID
__RCSID("$NetBSD: parsedate.y,v 1.20 2014/10/08 17:38:28 apb Exp $");
#endif

#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <util.h>
#include <stdlib.h>

/* NOTES on rebuilding parsedate.c (particularly for inclusion in CVS
   releases):

   We don't want to mess with all the portability hassles of alloca.
   In particular, most (all?) versions of bison will use alloca in
   their parser.  If bison works on your system (e.g. it should work
   with gcc), then go ahead and use it, but the more general solution
   is to use byacc instead of bison, which should generate a portable
   parser.  I played with adding "#define alloca dont_use_alloca", to
   give an error if the parser generator uses alloca (and thus detect
   unportable parsedate.c's), but that seems to cause as many problems
   as it solves.  */

#define EPOCH		1970
#define HOUR(x)		((time_t)(x) * 60)
#define SECSPERDAY	(24L * 60L * 60L)

#define USE_LOCAL_TIME	99999 /* special case for Convert() and yyTimezone */

/*
**  An entry in the lexical lookup table.
*/
typedef struct _TABLE {
    const char	*name;
    int		type;
    time_t	value;
} TABLE;


/*
**  Daylight-savings mode:  on, off, or not yet known.
*/
typedef enum _DSTMODE {
    DSTon, DSToff, DSTmaybe
} DSTMODE;

/*
**  Meridian:  am, pm, or 24-hour style.
*/
typedef enum _MERIDIAN {
    MERam, MERpm, MER24
} MERIDIAN;


struct dateinfo {
	DSTMODE	yyDSTmode;	/* DST on/off/maybe */
	time_t	yyDayOrdinal;
	time_t	yyDayNumber;
	int	yyHaveDate;
	int	yyHaveFullYear;	/* if true, year is not abbreviated. */
				/* if false, need to call AdjustYear(). */
	int	yyHaveDay;
	int	yyHaveRel;
	int	yyHaveTime;
	int	yyHaveZone;
	time_t	yyTimezone;	/* Timezone as minutes ahead/east of UTC */
	time_t	yyDay;		/* Day of month [1-31] */
	time_t	yyHour;		/* Hour of day [0-24] or [1-12] */
	time_t	yyMinutes;	/* Minute of hour [0-59] */
	time_t	yyMonth;	/* Month of year [1-12] */
	time_t	yySeconds;	/* Second of minute [0-60] */
	time_t	yyYear;		/* Year, see also yyHaveFullYear */
	MERIDIAN yyMeridian;	/* Interpret yyHour as AM/PM/24 hour clock */
	time_t	yyRelMonth;
	time_t	yyRelSeconds;
};
#line 96 "/home/donz/minix/lib/libutil/parsedate.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    time_t		Number;
    enum _MERIDIAN	Meridian;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 225 "parsedate.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(struct dateinfo *param, const char **yyInput)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# ifdef YYLEX_PARAM_TYPE
#  define YYLEX_DECL() yylex(YYSTYPE *yylval, YYLEX_PARAM_TYPE YYLEX_PARAM)
# else
#  define YYLEX_DECL() yylex(YYSTYPE *yylval, void * YYLEX_PARAM)
# endif
# define YYLEX yylex(&yylval, YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(YYSTYPE *yylval, const char **yyInput)
# define YYLEX yylex(&yylval, yyInput)
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(struct dateinfo *param, const char **yyInput, const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(param, yyInput, msg)
#endif

extern int YYPARSE_DECL();

#define tAGO 257
#define tDAY 258
#define tDAYZONE 259
#define tID 260
#define tMERIDIAN 261
#define tMINUTE_UNIT 262
#define tMONTH 263
#define tMONTH_UNIT 264
#define tSEC_UNIT 265
#define tSNUMBER 266
#define tUNUMBER 267
#define tZONE 268
#define tDST 269
#define AT_SIGN 270
#define YYERRCODE 256
typedef int YYINT;
static const YYINT __pdlhs[] = {                         -1,
    0,    0,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    9,   10,   12,   12,    3,    3,    3,    3,    4,
    4,    5,    5,    5,    7,    7,    7,    6,    6,    6,
    6,    6,    6,    6,    6,    8,    8,   13,   13,   13,
   13,   13,   13,   13,   13,   13,   11,    1,    1,
};
static const YYINT __pdlen[] = {                          2,
    0,    2,    1,    1,    1,    1,    1,    1,    1,    1,
    1,   11,    2,    1,    1,    2,    4,    6,    7,    4,
    6,    1,    1,    2,    1,    2,    2,    3,    5,    3,
    3,    2,    4,    2,    3,    2,    1,    2,    2,    1,
    2,    2,    1,    2,    2,    1,    1,    0,    1,
};
static const YYINT __pddefred[] = {                       1,
    0,    0,   23,   40,    0,   46,   43,    0,    0,    0,
    0,    2,    3,    4,    5,    6,    7,    8,    9,   10,
   11,    0,   26,    0,   39,   44,   41,   27,   16,   38,
    0,   45,   42,    0,    0,    0,    0,   24,   15,   14,
   13,   36,    0,   31,   35,   30,    0,    0,    0,   33,
    0,   49,   20,    0,   17,    0,    0,    0,   29,    0,
   21,    0,   18,    0,   19,    0,    0,    0,   12,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT __pdstos[] = {                         0,
  272,  258,  259,  262,  263,  264,  265,  266,  267,  268,
  270,  274,  275,  276,  277,  278,  279,  280,  281,  282,
  283,  285,   44,  267,  262,  264,  265,  258,  261,  262,
  263,  264,  265,  266,   46,   58,   47,  269,  266,  267,
  284,  257,   44,  266,  267,  266,  267,  267,  267,  267,
   46,  261,  266,   58,  273,   47,  267,  267,  267,   46,
  266,   46,  273,  267,  267,   46,  267,   46,  267,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT __pddgoto[] = {                        1,
   55,   12,   13,   14,   15,   16,   17,   18,   19,   20,
   21,   41,   22,
};
static const YYINT __pdsindex[] = {                       0,
 -246,  -42,    0,    0, -261,    0,    0, -257,  -43, -240,
 -256,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -234,    0,  -16,    0,    0,    0,    0,    0,    0,
 -241,    0,    0, -236, -235, -233, -232,    0,    0,    0,
    0,    0, -231,    0,    0,    0,  -15,  -58,  -14,    0,
 -230,    0,    0, -229,    0, -228,   -5,  -37,    0, -225,
    0, -224,    0,   -2,    0, -222,    2, -221,    0,
};
static const YYINT __pdrindex[] = {                       0,
    0,    1,    0,    0,    0,    0,    0,    0,   86,   14,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   27,    0,   40,    0,    0,    0,    0,    0,    0,
   79,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   66,   53,    0,
    0,    0,    0,    0,    0,    0,    0,   66,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#if YYBTYACC
static const YYINT __pdcindex[] = {                       0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT __pdgindex[] = {                       0,
  -11,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
#define YYTABLESIZE 356
static const YYINT __pdtable[] = {                       54,
   25,   23,   35,   37,   25,   24,   26,   27,   62,   39,
   40,    2,    3,   22,   36,    4,    5,    6,    7,    8,
    9,   10,   42,   11,   44,   45,   37,   43,   38,   46,
   51,   47,   56,   48,   49,   50,   57,   58,   59,   32,
   60,   64,   65,   66,   67,   69,   63,   68,    0,    0,
    0,    0,   28,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   48,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   34,    0,
    0,    0,    0,    0,    0,   47,    0,    0,    0,    0,
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
    0,    0,   52,    0,    0,    0,    0,   53,    0,    0,
    0,    0,    0,    0,   28,    0,    0,   29,   30,   31,
   32,   33,   34,   52,    0,    0,    0,    0,   61,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   25,   25,
    0,    0,   25,   25,   25,   25,   25,   25,   25,    0,
   25,   22,   22,    0,    0,   22,   22,   22,   22,   22,
   22,   22,    0,   22,   37,   37,    0,    0,   37,   37,
   37,   37,   37,   37,   37,    0,   37,   32,   32,    0,
    0,   32,   32,   32,   32,   32,   32,   32,    0,   32,
   28,   28,    0,    0,   28,   28,   28,   28,   28,   28,
   28,    0,   28,   48,   48,    0,    0,   48,   48,   48,
   48,    0,   48,   48,    0,   48,   34,   34,    0,    0,
   34,   34,   34,   34,   47,    0,   34,    0,   34,    0,
    0,    0,   47,   47,    0,   47,
};
static const YYINT __pdcheck[] = {                       58,
    0,   44,   46,   47,  262,  267,  264,  265,   46,  266,
  267,  258,  259,    0,   58,  262,  263,  264,  265,  266,
  267,  268,  257,  270,  266,  267,    0,   44,  269,  266,
   46,  267,   47,  267,  267,  267,  267,  267,  267,    0,
   46,  267,  267,   46,  267,  267,   58,   46,   -1,   -1,
   -1,   -1,    0,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,    0,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,    0,   -1,
   -1,   -1,   -1,   -1,   -1,    0,   -1,   -1,   -1,   -1,
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
   -1,   -1,  261,   -1,   -1,   -1,   -1,  266,   -1,   -1,
   -1,   -1,   -1,   -1,  258,   -1,   -1,  261,  262,  263,
  264,  265,  266,  261,   -1,   -1,   -1,   -1,  266,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  258,  259,
   -1,   -1,  262,  263,  264,  265,  266,  267,  268,   -1,
  270,  258,  259,   -1,   -1,  262,  263,  264,  265,  266,
  267,  268,   -1,  270,  258,  259,   -1,   -1,  262,  263,
  264,  265,  266,  267,  268,   -1,  270,  258,  259,   -1,
   -1,  262,  263,  264,  265,  266,  267,  268,   -1,  270,
  258,  259,   -1,   -1,  262,  263,  264,  265,  266,  267,
  268,   -1,  270,  258,  259,   -1,   -1,  262,  263,  264,
  265,   -1,  267,  268,   -1,  270,  258,  259,   -1,   -1,
  262,  263,  264,  265,  259,   -1,  268,   -1,  270,   -1,
   -1,   -1,  267,  268,   -1,  270,
};
#if YYBTYACC
static const YYINT __pdctable[] = {                      -1,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 270
#define YYUNDFTOKEN 286
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const __pdname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"','",0,"'.'","'/'",0,0,0,0,0,0,0,0,0,0,"':'",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","tAGO","tDAY",
"tDAYZONE","tID","tMERIDIAN","tMINUTE_UNIT","tMONTH","tMONTH_UNIT","tSEC_UNIT",
"tSNUMBER","tUNUMBER","tZONE","tDST","AT_SIGN","$accept","spec","o_merid",
"item","time","time_numericzone","zone","date","day","rel","cvsstamp",
"epochdate","number","at_number","relunit","illegal-symbol",
};
static const char *const __pdrule[] = {
"$accept : spec",
"spec :",
"spec : spec item",
"item : time",
"item : time_numericzone",
"item : zone",
"item : date",
"item : day",
"item : rel",
"item : cvsstamp",
"item : epochdate",
"item : number",
"cvsstamp : tUNUMBER '.' tUNUMBER '.' tUNUMBER '.' tUNUMBER '.' tUNUMBER '.' tUNUMBER",
"epochdate : AT_SIGN at_number",
"at_number : tUNUMBER",
"at_number : tSNUMBER",
"time : tUNUMBER tMERIDIAN",
"time : tUNUMBER ':' tUNUMBER o_merid",
"time : tUNUMBER ':' tUNUMBER ':' tUNUMBER o_merid",
"time : tUNUMBER ':' tUNUMBER ':' tUNUMBER '.' tUNUMBER",
"time_numericzone : tUNUMBER ':' tUNUMBER tSNUMBER",
"time_numericzone : tUNUMBER ':' tUNUMBER ':' tUNUMBER tSNUMBER",
"zone : tZONE",
"zone : tDAYZONE",
"zone : tZONE tDST",
"day : tDAY",
"day : tDAY ','",
"day : tUNUMBER tDAY",
"date : tUNUMBER '/' tUNUMBER",
"date : tUNUMBER '/' tUNUMBER '/' tUNUMBER",
"date : tUNUMBER tSNUMBER tSNUMBER",
"date : tUNUMBER tMONTH tSNUMBER",
"date : tMONTH tUNUMBER",
"date : tMONTH tUNUMBER ',' tUNUMBER",
"date : tUNUMBER tMONTH",
"date : tUNUMBER tMONTH tUNUMBER",
"rel : relunit tAGO",
"rel : relunit",
"relunit : tUNUMBER tMINUTE_UNIT",
"relunit : tSNUMBER tMINUTE_UNIT",
"relunit : tMINUTE_UNIT",
"relunit : tSNUMBER tSEC_UNIT",
"relunit : tUNUMBER tSEC_UNIT",
"relunit : tSEC_UNIT",
"relunit : tSNUMBER tMONTH_UNIT",
"relunit : tUNUMBER tMONTH_UNIT",
"relunit : tMONTH_UNIT",
"number : tUNUMBER",
"o_merid :",
"o_merid : tMERIDIAN",

};
#endif

int      yydebug;
int      yynerrs;

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
#line 386 "/home/donz/minix/lib/libutil/parsedate.y"

/* Month and day table. */
static const TABLE MonthDayTable[] = {
    { "january",	tMONTH,  1 },
    { "february",	tMONTH,  2 },
    { "march",		tMONTH,  3 },
    { "april",		tMONTH,  4 },
    { "may",		tMONTH,  5 },
    { "june",		tMONTH,  6 },
    { "july",		tMONTH,  7 },
    { "august",		tMONTH,  8 },
    { "september",	tMONTH,  9 },
    { "sept",		tMONTH,  9 },
    { "october",	tMONTH, 10 },
    { "november",	tMONTH, 11 },
    { "december",	tMONTH, 12 },
    { "sunday",		tDAY, 0 },
    { "monday",		tDAY, 1 },
    { "tuesday",	tDAY, 2 },
    { "tues",		tDAY, 2 },
    { "wednesday",	tDAY, 3 },
    { "wednes",		tDAY, 3 },
    { "thursday",	tDAY, 4 },
    { "thur",		tDAY, 4 },
    { "thurs",		tDAY, 4 },
    { "friday",		tDAY, 5 },
    { "saturday",	tDAY, 6 },
    { NULL,		0,    0 }
};

/* Time units table. */
static const TABLE UnitsTable[] = {
    { "year",		tMONTH_UNIT,	12 },
    { "month",		tMONTH_UNIT,	1 },
    { "fortnight",	tMINUTE_UNIT,	14 * 24 * 60 },
    { "week",		tMINUTE_UNIT,	7 * 24 * 60 },
    { "day",		tMINUTE_UNIT,	1 * 24 * 60 },
    { "hour",		tMINUTE_UNIT,	60 },
    { "minute",		tMINUTE_UNIT,	1 },
    { "min",		tMINUTE_UNIT,	1 },
    { "second",		tSEC_UNIT,	1 },
    { "sec",		tSEC_UNIT,	1 },
    { NULL,		0,		0 }
};

/* Assorted relative-time words. */
static const TABLE OtherTable[] = {
    { "tomorrow",	tMINUTE_UNIT,	1 * 24 * 60 },
    { "yesterday",	tMINUTE_UNIT,	-1 * 24 * 60 },
    { "today",		tMINUTE_UNIT,	0 },
    { "now",		tMINUTE_UNIT,	0 },
    { "last",		tUNUMBER,	-1 },
    { "this",		tMINUTE_UNIT,	0 },
    { "next",		tUNUMBER,	2 },
    { "first",		tUNUMBER,	1 },
    { "one",		tUNUMBER,	1 },
/*  { "second",		tUNUMBER,	2 }, */
    { "two",		tUNUMBER,	2 },
    { "third",		tUNUMBER,	3 },
    { "three",		tUNUMBER,	3 },
    { "fourth",		tUNUMBER,	4 },
    { "four",		tUNUMBER,	4 },
    { "fifth",		tUNUMBER,	5 },
    { "five",		tUNUMBER,	5 },
    { "sixth",		tUNUMBER,	6 },
    { "six",		tUNUMBER,	6 },
    { "seventh",	tUNUMBER,	7 },
    { "seven",		tUNUMBER,	7 },
    { "eighth",		tUNUMBER,	8 },
    { "eight",		tUNUMBER,	8 },
    { "ninth",		tUNUMBER,	9 },
    { "nine",		tUNUMBER,	9 },
    { "tenth",		tUNUMBER,	10 },
    { "ten",		tUNUMBER,	10 },
    { "eleventh",	tUNUMBER,	11 },
    { "eleven",		tUNUMBER,	11 },
    { "twelfth",	tUNUMBER,	12 },
    { "twelve",		tUNUMBER,	12 },
    { "ago",		tAGO,	1 },
    { NULL,		0,	0 }
};

/* The timezone table. */
/* Some of these are commented out because a time_t can't store a float. */
static const TABLE TimezoneTable[] = {
    { "gmt",	tZONE,     HOUR( 0) },	/* Greenwich Mean */
    { "ut",	tZONE,     HOUR( 0) },	/* Universal (Coordinated) */
    { "utc",	tZONE,     HOUR( 0) },
    { "wet",	tZONE,     HOUR( 0) },	/* Western European */
    { "bst",	tDAYZONE,  HOUR( 0) },	/* British Summer */
    { "wat",	tZONE,     HOUR( 1) },	/* West Africa */
    { "at",	tZONE,     HOUR( 2) },	/* Azores */
#if	0
    /* For completeness.  BST is also British Summer, and GST is
     * also Guam Standard. */
    { "bst",	tZONE,     HOUR( 3) },	/* Brazil Standard */
    { "gst",	tZONE,     HOUR( 3) },	/* Greenland Standard */
#endif
#if 0
    { "nft",	tZONE,     HOUR(3.5) },	/* Newfoundland */
    { "nst",	tZONE,     HOUR(3.5) },	/* Newfoundland Standard */
    { "ndt",	tDAYZONE,  HOUR(3.5) },	/* Newfoundland Daylight */
#endif
    { "ast",	tZONE,     HOUR( 4) },	/* Atlantic Standard */
    { "adt",	tDAYZONE,  HOUR( 4) },	/* Atlantic Daylight */
    { "est",	tZONE,     HOUR( 5) },	/* Eastern Standard */
    { "edt",	tDAYZONE,  HOUR( 5) },	/* Eastern Daylight */
    { "cst",	tZONE,     HOUR( 6) },	/* Central Standard */
    { "cdt",	tDAYZONE,  HOUR( 6) },	/* Central Daylight */
    { "mst",	tZONE,     HOUR( 7) },	/* Mountain Standard */
    { "mdt",	tDAYZONE,  HOUR( 7) },	/* Mountain Daylight */
    { "pst",	tZONE,     HOUR( 8) },	/* Pacific Standard */
    { "pdt",	tDAYZONE,  HOUR( 8) },	/* Pacific Daylight */
    { "yst",	tZONE,     HOUR( 9) },	/* Yukon Standard */
    { "ydt",	tDAYZONE,  HOUR( 9) },	/* Yukon Daylight */
    { "hst",	tZONE,     HOUR(10) },	/* Hawaii Standard */
    { "hdt",	tDAYZONE,  HOUR(10) },	/* Hawaii Daylight */
    { "cat",	tZONE,     HOUR(10) },	/* Central Alaska */
    { "ahst",	tZONE,     HOUR(10) },	/* Alaska-Hawaii Standard */
    { "nt",	tZONE,     HOUR(11) },	/* Nome */
    { "idlw",	tZONE,     HOUR(12) },	/* International Date Line West */
    { "cet",	tZONE,     -HOUR(1) },	/* Central European */
    { "met",	tZONE,     -HOUR(1) },	/* Middle European */
    { "mewt",	tZONE,     -HOUR(1) },	/* Middle European Winter */
    { "mest",	tDAYZONE,  -HOUR(1) },	/* Middle European Summer */
    { "swt",	tZONE,     -HOUR(1) },	/* Swedish Winter */
    { "sst",	tDAYZONE,  -HOUR(1) },	/* Swedish Summer */
    { "fwt",	tZONE,     -HOUR(1) },	/* French Winter */
    { "fst",	tDAYZONE,  -HOUR(1) },	/* French Summer */
    { "eet",	tZONE,     -HOUR(2) },	/* Eastern Europe, USSR Zone 1 */
    { "bt",	tZONE,     -HOUR(3) },	/* Baghdad, USSR Zone 2 */
#if 0
    { "it",	tZONE,     -HOUR(3.5) },/* Iran */
#endif
    { "zp4",	tZONE,     -HOUR(4) },	/* USSR Zone 3 */
    { "zp5",	tZONE,     -HOUR(5) },	/* USSR Zone 4 */
#if 0
    { "ist",	tZONE,     -HOUR(5.5) },/* Indian Standard */
#endif
    { "zp6",	tZONE,     -HOUR(6) },	/* USSR Zone 5 */
#if	0
    /* For completeness.  NST is also Newfoundland Stanard, and SST is
     * also Swedish Summer. */
    { "nst",	tZONE,     -HOUR(6.5) },/* North Sumatra */
    { "sst",	tZONE,     -HOUR(7) },	/* South Sumatra, USSR Zone 6 */
#endif	/* 0 */
    { "wast",	tZONE,     -HOUR(7) },	/* West Australian Standard */
    { "wadt",	tDAYZONE,  -HOUR(7) },	/* West Australian Daylight */
#if 0
    { "jt",	tZONE,     -HOUR(7.5) },/* Java (3pm in Cronusland!) */
#endif
    { "cct",	tZONE,     -HOUR(8) },	/* China Coast, USSR Zone 7 */
    { "jst",	tZONE,     -HOUR(9) },	/* Japan Standard, USSR Zone 8 */
#if 0
    { "cast",	tZONE,     -HOUR(9.5) },/* Central Australian Standard */
    { "cadt",	tDAYZONE,  -HOUR(9.5) },/* Central Australian Daylight */
#endif
    { "east",	tZONE,     -HOUR(10) },	/* Eastern Australian Standard */
    { "eadt",	tDAYZONE,  -HOUR(10) },	/* Eastern Australian Daylight */
    { "gst",	tZONE,     -HOUR(10) },	/* Guam Standard, USSR Zone 9 */
    { "nzt",	tZONE,     -HOUR(12) },	/* New Zealand */
    { "nzst",	tZONE,     -HOUR(12) },	/* New Zealand Standard */
    { "nzdt",	tDAYZONE,  -HOUR(12) },	/* New Zealand Daylight */
    { "idle",	tZONE,     -HOUR(12) },	/* International Date Line East */
    {  NULL,	0,	    0 }
};

/* Military timezone table. */
static const TABLE MilitaryTable[] = {
    { "a",	tZONE,	HOUR(  1) },
    { "b",	tZONE,	HOUR(  2) },
    { "c",	tZONE,	HOUR(  3) },
    { "d",	tZONE,	HOUR(  4) },
    { "e",	tZONE,	HOUR(  5) },
    { "f",	tZONE,	HOUR(  6) },
    { "g",	tZONE,	HOUR(  7) },
    { "h",	tZONE,	HOUR(  8) },
    { "i",	tZONE,	HOUR(  9) },
    { "k",	tZONE,	HOUR( 10) },
    { "l",	tZONE,	HOUR( 11) },
    { "m",	tZONE,	HOUR( 12) },
    { "n",	tZONE,	HOUR(- 1) },
    { "o",	tZONE,	HOUR(- 2) },
    { "p",	tZONE,	HOUR(- 3) },
    { "q",	tZONE,	HOUR(- 4) },
    { "r",	tZONE,	HOUR(- 5) },
    { "s",	tZONE,	HOUR(- 6) },
    { "t",	tZONE,	HOUR(- 7) },
    { "u",	tZONE,	HOUR(- 8) },
    { "v",	tZONE,	HOUR(- 9) },
    { "w",	tZONE,	HOUR(-10) },
    { "x",	tZONE,	HOUR(-11) },
    { "y",	tZONE,	HOUR(-12) },
    { "z",	tZONE,	HOUR(  0) },
    { NULL,	0,	0 }
};




/* ARGSUSED */
static int
yyerror(struct dateinfo *param, const char **inp, const char *s __unused)
{
  return 0;
}


/* Adjust year from a value that might be abbreviated, to a full value.
 * e.g. convert 70 to 1970.
 * Input Year is either:
 *  - A negative number, which means to use its absolute value (why?)
 *  - A number from 0 to 99, which means a year from 1900 to 1999, or
 *  - The actual year (>=100).
 * Returns the full year. */
static time_t
AdjustYear(time_t Year)
{
    /* XXX Y2K */
    if (Year < 0)
	Year = -Year;
    if (Year < 70)
	Year += 2000;
    else if (Year < 100)
	Year += 1900;
    return Year;
}

static time_t
Convert(
    time_t	Month,		/* month of year [1-12] */
    time_t	Day,		/* day of month [1-31] */
    time_t	Year,		/* year, not abbreviated in any way */
    time_t	Hours,		/* Hour of day [0-24] */
    time_t	Minutes,	/* Minute of hour [0-59] */
    time_t	Seconds,	/* Second of minute [0-60] */
    time_t	Timezone,	/* Timezone as minutes east of UTC,
				 * or USE_LOCAL_TIME special case */
    MERIDIAN	Meridian,	/* Hours are am/pm/24 hour clock */
    DSTMODE	DSTmode		/* DST on/off/maybe */
)
{
    struct tm tm = {.tm_sec = 0};
    time_t result;

    tm.tm_sec = Seconds;
    tm.tm_min = Minutes;
    tm.tm_hour = Hours + (Meridian == MERpm ? 12 : 0);
    tm.tm_mday = Day;
    tm.tm_mon = Month - 1;
    tm.tm_year = Year - 1900;
    switch (DSTmode) {
    case DSTon:  tm.tm_isdst = 1; break;
    case DSToff: tm.tm_isdst = 0; break;
    default:     tm.tm_isdst = -1; break;
    }

    if (Timezone == USE_LOCAL_TIME) {
	    result = mktime(&tm);
    } else {
	    /* We rely on mktime_z(NULL, ...) working in UTC */
	    result = mktime_z(NULL, &tm);
	    result += Timezone * 60;
    }

#if PARSEDATE_DEBUG
    fprintf(stderr, "%s(M=%jd D=%jd Y=%jd H=%jd M=%jd S=%jd Z=%jd"
		    " mer=%d DST=%d)",
	__func__,
	(intmax_t)Month, (intmax_t)Day, (intmax_t)Year,
	(intmax_t)Hours, (intmax_t)Minutes, (intmax_t)Seconds,
	(intmax_t)Timezone, (int)Meridian, (int)DSTmode);
    fprintf(stderr, " -> %jd", (intmax_t)result);
    fprintf(stderr, " %s", ctime(&result));
#endif

    return result;
}


static time_t
DSTcorrect(
    time_t	Start,
    time_t	Future
)
{
    time_t	StartDay;
    time_t	FutureDay;
    struct tm  *tm;

    if ((tm = localtime(&Start)) == NULL)
	return -1;
    StartDay = (tm->tm_hour + 1) % 24;

    if ((tm = localtime(&Future)) == NULL)
	return -1;
    FutureDay = (tm->tm_hour + 1) % 24;

    return (Future - Start) + (StartDay - FutureDay) * 60L * 60L;
}


static time_t
RelativeDate(
    time_t	Start,
    time_t	DayOrdinal,
    time_t	DayNumber
)
{
    struct tm	*tm;
    time_t	now;

    now = Start;
    tm = localtime(&now);
    now += SECSPERDAY * ((DayNumber - tm->tm_wday + 7) % 7);
    now += 7 * SECSPERDAY * (DayOrdinal <= 0 ? DayOrdinal : DayOrdinal - 1);
    return DSTcorrect(Start, now);
}


static time_t
RelativeMonth(
    time_t	Start,
    time_t	RelMonth,
    time_t	Timezone
)
{
    struct tm	*tm;
    time_t	Month;
    time_t	Year;

    if (RelMonth == 0)
	return 0;
    tm = localtime(&Start);
    if (tm == NULL)
	return -1;
    Month = 12 * (tm->tm_year + 1900) + tm->tm_mon + RelMonth;
    Year = Month / 12;
    Month = Month % 12 + 1;
    return DSTcorrect(Start,
	    Convert(Month, (time_t)tm->tm_mday, Year,
		(time_t)tm->tm_hour, (time_t)tm->tm_min, (time_t)tm->tm_sec,
		Timezone, MER24, DSTmaybe));
}


static int
LookupWord(YYSTYPE *yylval, char *buff)
{
    register char	*p;
    register char	*q;
    register const TABLE	*tp;
    int			i;
    int			abbrev;

    /* Make it lowercase. */
    for (p = buff; *p; p++)
	if (isupper((unsigned char)*p))
	    *p = tolower((unsigned char)*p);

    if (strcmp(buff, "am") == 0 || strcmp(buff, "a.m.") == 0) {
	yylval->Meridian = MERam;
	return tMERIDIAN;
    }
    if (strcmp(buff, "pm") == 0 || strcmp(buff, "p.m.") == 0) {
	yylval->Meridian = MERpm;
	return tMERIDIAN;
    }

    /* See if we have an abbreviation for a month. */
    if (strlen(buff) == 3)
	abbrev = 1;
    else if (strlen(buff) == 4 && buff[3] == '.') {
	abbrev = 1;
	buff[3] = '\0';
    }
    else
	abbrev = 0;

    for (tp = MonthDayTable; tp->name; tp++) {
	if (abbrev) {
	    if (strncmp(buff, tp->name, 3) == 0) {
		yylval->Number = tp->value;
		return tp->type;
	    }
	}
	else if (strcmp(buff, tp->name) == 0) {
	    yylval->Number = tp->value;
	    return tp->type;
	}
    }

    for (tp = TimezoneTable; tp->name; tp++)
	if (strcmp(buff, tp->name) == 0) {
	    yylval->Number = tp->value;
	    return tp->type;
	}

    if (strcmp(buff, "dst") == 0) 
	return tDST;

    for (tp = UnitsTable; tp->name; tp++)
	if (strcmp(buff, tp->name) == 0) {
	    yylval->Number = tp->value;
	    return tp->type;
	}

    /* Strip off any plural and try the units table again. */
    i = strlen(buff) - 1;
    if (buff[i] == 's') {
	buff[i] = '\0';
	for (tp = UnitsTable; tp->name; tp++)
	    if (strcmp(buff, tp->name) == 0) {
		yylval->Number = tp->value;
		return tp->type;
	    }
	buff[i] = 's';		/* Put back for "this" in OtherTable. */
    }

    for (tp = OtherTable; tp->name; tp++)
	if (strcmp(buff, tp->name) == 0) {
	    yylval->Number = tp->value;
	    return tp->type;
	}

    /* Military timezones. */
    if (buff[1] == '\0' && isalpha((unsigned char)*buff)) {
	for (tp = MilitaryTable; tp->name; tp++)
	    if (strcmp(buff, tp->name) == 0) {
		yylval->Number = tp->value;
		return tp->type;
	    }
    }

    /* Drop out any periods and try the timezone table again. */
    for (i = 0, p = q = buff; *q; q++)
	if (*q != '.')
	    *p++ = *q;
	else
	    i++;
    *p = '\0';
    if (i)
	for (tp = TimezoneTable; tp->name; tp++)
	    if (strcmp(buff, tp->name) == 0) {
		yylval->Number = tp->value;
		return tp->type;
	    }

    return tID;
}


static int
yylex(YYSTYPE *yylval, const char **yyInput)
{
    register char	c;
    register char	*p;
    char		buff[20];
    int			Count;
    int			sign;
    const char		*inp = *yyInput;

    for ( ; ; ) {
	while (isspace((unsigned char)*inp))
	    inp++;

	if (isdigit((unsigned char)(c = *inp)) || c == '-' || c == '+') {
	    if (c == '-' || c == '+') {
		sign = c == '-' ? -1 : 1;
		if (!isdigit((unsigned char)*++inp))
		    /* skip the '-' sign */
		    continue;
	    }
	    else
		sign = 0;
	    for (yylval->Number = 0; isdigit((unsigned char)(c = *inp++)); )
		yylval->Number = 10 * yylval->Number + c - '0';
	    if (sign < 0)
		yylval->Number = -yylval->Number;
	    *yyInput = --inp;
	    return sign ? tSNUMBER : tUNUMBER;
	}
	if (isalpha((unsigned char)c)) {
	    for (p = buff; isalpha((unsigned char)(c = *inp++)) || c == '.'; )
		if (p < &buff[sizeof buff - 1])
		    *p++ = c;
	    *p = '\0';
	    *yyInput = --inp;
	    return LookupWord(yylval, buff);
	}
	if (c == '@') {
	    *yyInput = ++inp;
	    return AT_SIGN;
	}
	if (c != '(') {
	    *yyInput = ++inp;
	    return c;
	}
	Count = 0;
	do {
	    c = *inp++;
	    if (c == '\0')
		return c;
	    if (c == '(')
		Count++;
	    else if (c == ')')
		Count--;
	} while (Count > 0);
    }
}

#define TM_YEAR_ORIGIN 1900

time_t
parsedate(const char *p, const time_t *now, const int *zone)
{
    struct tm		local, *tm;
    time_t		nowt;
    int			zonet;
    time_t		Start;
    time_t		tod, rm;
    struct dateinfo	param;
    int			saved_errno;
    
    saved_errno = errno;
    errno = 0;

    if (now == NULL) {
        now = &nowt;
	(void)time(&nowt);
    }
    if (zone == NULL) {
	zone = &zonet;
	zonet = USE_LOCAL_TIME;
	if ((tm = localtime_r(now, &local)) == NULL)
	    return -1;
    } else {
	/*
	 * Should use the specified zone, not localtime.
	 * Fake it using gmtime and arithmetic.
	 * This is good enough because we use only the year/month/day,
	 * not other fields of struct tm.
	 */
	time_t fake = *now + (*zone * 60);
	if ((tm = gmtime_r(&fake, &local)) == NULL)
	    return -1;
    }
    param.yyYear = tm->tm_year + 1900;
    param.yyMonth = tm->tm_mon + 1;
    param.yyDay = tm->tm_mday;
    param.yyTimezone = *zone;
    param.yyDSTmode = DSTmaybe;
    param.yyHour = 0;
    param.yyMinutes = 0;
    param.yySeconds = 0;
    param.yyMeridian = MER24;
    param.yyRelSeconds = 0;
    param.yyRelMonth = 0;
    param.yyHaveDate = 0;
    param.yyHaveFullYear = 0;
    param.yyHaveDay = 0;
    param.yyHaveRel = 0;
    param.yyHaveTime = 0;
    param.yyHaveZone = 0;

    if (yyparse(&param, &p) || param.yyHaveTime > 1 || param.yyHaveZone > 1 ||
	param.yyHaveDate > 1 || param.yyHaveDay > 1) {
	errno = EINVAL;
	return -1;
    }

    if (param.yyHaveDate || param.yyHaveTime || param.yyHaveDay) {
	if (! param.yyHaveFullYear) {
		param.yyYear = AdjustYear(param.yyYear);
		param.yyHaveFullYear = 1;
	}
	Start = Convert(param.yyMonth, param.yyDay, param.yyYear, param.yyHour,
	    param.yyMinutes, param.yySeconds, param.yyTimezone,
	    param.yyMeridian, param.yyDSTmode);
	if (Start == -1 && errno != 0)
	    return -1;
    }
    else {
	Start = *now;
	if (!param.yyHaveRel)
	    Start -= ((tm->tm_hour * 60L + tm->tm_min) * 60L) + tm->tm_sec;
    }

    Start += param.yyRelSeconds;
    rm = RelativeMonth(Start, param.yyRelMonth, param.yyTimezone);
    if (rm == -1 && errno != 0)
	return -1;
    Start += rm;

    if (param.yyHaveDay && !param.yyHaveDate) {
	tod = RelativeDate(Start, param.yyDayOrdinal, param.yyDayNumber);
	Start += tod;
    }

    if (errno == 0)
	errno = saved_errno;
    return Start;
}


#if	defined(TEST)

/* ARGSUSED */
int
main(int ac, char *av[])
{
    char	buff[128];
    time_t	d;

    (void)printf("Enter date, or blank line to exit.\n\t> ");
    (void)fflush(stdout);
    while (fgets(buff, sizeof(buff), stdin) && buff[0] != '\n') {
	errno = 0;
	d = parsedate(buff, NULL, NULL);
	if (d == -1 && errno != 0)
	    (void)printf("Bad format - couldn't convert: %s\n",
	        strerror(errno));
	else
	    (void)printf("%jd\t%s", (intmax_t)d, ctime(&d));
	(void)printf("\t> ");
	(void)fflush(stdout);
    }
    exit(0);
    /* NOTREACHED */
}
#endif	/* defined(TEST) */
#line 1201 "parsedate.c"

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
    int      yyerrflag;
    int      yychar;
    YYSTYPE  yyval;
    YYSTYPE  yylval;

    /* variables for the parser stack */
    YYSTACKDATA yystack;
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
case 3:
#line 119 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyHaveTime++;
	}
break;
case 4:
#line 122 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyHaveTime++;
	    param->yyHaveZone++;
	}
break;
case 5:
#line 126 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyHaveZone++;
	}
break;
case 6:
#line 129 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyHaveDate++;
	}
break;
case 7:
#line 132 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyHaveDay++;
	}
break;
case 8:
#line 135 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyHaveRel++;
	}
break;
case 9:
#line 138 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyHaveTime++;
	    param->yyHaveDate++;
	    param->yyHaveZone++;
	}
break;
case 10:
#line 143 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyHaveTime++;
	    param->yyHaveDate++;
	    param->yyHaveZone++;
	}
break;
case 12:
#line 151 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyYear = yystack.l_mark[-10].Number;
	    if (param->yyYear < 100) param->yyYear += 1900;
	    param->yyHaveFullYear = 1;
	    param->yyMonth = yystack.l_mark[-8].Number;
	    param->yyDay = yystack.l_mark[-6].Number;
	    param->yyHour = yystack.l_mark[-4].Number;
	    param->yyMinutes = yystack.l_mark[-2].Number;
	    param->yySeconds = yystack.l_mark[0].Number;
	    param->yyDSTmode = DSToff;
	    param->yyTimezone = 0;
	}
break;
case 13:
#line 165 "/home/donz/minix/lib/libutil/parsedate.y"
	{
            time_t    when = yystack.l_mark[0].Number;
            struct tm tmbuf;
            if (gmtime_r(&when, &tmbuf) != NULL) {
		param->yyYear = tmbuf.tm_year + 1900;
		param->yyMonth = tmbuf.tm_mon + 1;
		param->yyDay = tmbuf.tm_mday;

		param->yyHour = tmbuf.tm_hour;
		param->yyMinutes = tmbuf.tm_min;
		param->yySeconds = tmbuf.tm_sec;
	    } else {
		param->yyYear = EPOCH;
		param->yyMonth = 1;
		param->yyDay = 1;

		param->yyHour = 0;
		param->yyMinutes = 0;
		param->yySeconds = 0;
	    }
	    param->yyHaveFullYear = 1;
	    param->yyDSTmode = DSToff;
	    param->yyTimezone = 0;
	}
break;
case 16:
#line 193 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyHour = yystack.l_mark[-1].Number;
	    param->yyMinutes = 0;
	    param->yySeconds = 0;
	    param->yyMeridian = yystack.l_mark[0].Meridian;
	}
break;
case 17:
#line 199 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyHour = yystack.l_mark[-3].Number;
	    param->yyMinutes = yystack.l_mark[-1].Number;
	    param->yySeconds = 0;
	    param->yyMeridian = yystack.l_mark[0].Meridian;
	}
break;
case 18:
#line 205 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyHour = yystack.l_mark[-5].Number;
	    param->yyMinutes = yystack.l_mark[-3].Number;
	    param->yySeconds = yystack.l_mark[-1].Number;
	    param->yyMeridian = yystack.l_mark[0].Meridian;
	}
break;
case 19:
#line 211 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyHour = yystack.l_mark[-6].Number;
	    param->yyMinutes = yystack.l_mark[-4].Number;
	    param->yySeconds = yystack.l_mark[-2].Number;
	    param->yyMeridian = MER24;
/* XXX: Do nothing with millis */
	}
break;
case 20:
#line 220 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyHour = yystack.l_mark[-3].Number;
	    param->yyMinutes = yystack.l_mark[-1].Number;
	    param->yyMeridian = MER24;
	    param->yyDSTmode = DSToff;
	    param->yyTimezone = - (yystack.l_mark[0].Number % 100 + (yystack.l_mark[0].Number / 100) * 60);
	}
break;
case 21:
#line 227 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyHour = yystack.l_mark[-5].Number;
	    param->yyMinutes = yystack.l_mark[-3].Number;
	    param->yySeconds = yystack.l_mark[-1].Number;
	    param->yyMeridian = MER24;
	    param->yyDSTmode = DSToff;
	    param->yyTimezone = - (yystack.l_mark[0].Number % 100 + (yystack.l_mark[0].Number / 100) * 60);
	}
break;
case 22:
#line 237 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyTimezone = yystack.l_mark[0].Number;
	    param->yyDSTmode = DSToff;
	}
break;
case 23:
#line 241 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyTimezone = yystack.l_mark[0].Number;
	    param->yyDSTmode = DSTon;
	}
break;
case 24:
#line 246 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyTimezone = yystack.l_mark[-1].Number;
	    param->yyDSTmode = DSTon;
	}
break;
case 25:
#line 252 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyDayOrdinal = 1;
	    param->yyDayNumber = yystack.l_mark[0].Number;
	}
break;
case 26:
#line 256 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyDayOrdinal = 1;
	    param->yyDayNumber = yystack.l_mark[-1].Number;
	}
break;
case 27:
#line 260 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyDayOrdinal = yystack.l_mark[-1].Number;
	    param->yyDayNumber = yystack.l_mark[0].Number;
	}
break;
case 28:
#line 266 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyMonth = yystack.l_mark[-2].Number;
	    param->yyDay = yystack.l_mark[0].Number;
	}
break;
case 29:
#line 270 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    if (yystack.l_mark[-4].Number >= 100) {
		param->yyYear = yystack.l_mark[-4].Number;
		param->yyMonth = yystack.l_mark[-2].Number;
		param->yyDay = yystack.l_mark[0].Number;
	    } else {
		param->yyMonth = yystack.l_mark[-4].Number;
		param->yyDay = yystack.l_mark[-2].Number;
		param->yyYear = yystack.l_mark[0].Number;
	    }
	}
break;
case 30:
#line 281 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    /* ISO 8601 format.  yyyy-mm-dd.  */
	    param->yyYear = yystack.l_mark[-2].Number;
	    param->yyHaveFullYear = 1;
	    param->yyMonth = -yystack.l_mark[-1].Number;
	    param->yyDay = -yystack.l_mark[0].Number;
	}
break;
case 31:
#line 288 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    /* e.g. 17-JUN-1992.  */
	    param->yyDay = yystack.l_mark[-2].Number;
	    param->yyMonth = yystack.l_mark[-1].Number;
	    param->yyYear = -yystack.l_mark[0].Number;
	}
break;
case 32:
#line 294 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyMonth = yystack.l_mark[-1].Number;
	    param->yyDay = yystack.l_mark[0].Number;
	}
break;
case 33:
#line 298 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyMonth = yystack.l_mark[-3].Number;
	    param->yyDay = yystack.l_mark[-2].Number;
	    param->yyYear = yystack.l_mark[0].Number;
	}
break;
case 34:
#line 303 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyMonth = yystack.l_mark[0].Number;
	    param->yyDay = yystack.l_mark[-1].Number;
	}
break;
case 35:
#line 307 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyMonth = yystack.l_mark[-1].Number;
	    param->yyDay = yystack.l_mark[-2].Number;
	    param->yyYear = yystack.l_mark[0].Number;
	}
break;
case 36:
#line 314 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyRelSeconds = -param->yyRelSeconds;
	    param->yyRelMonth = -param->yyRelMonth;
	}
break;
case 38:
#line 321 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyRelSeconds += yystack.l_mark[-1].Number * yystack.l_mark[0].Number * 60L;
	}
break;
case 39:
#line 324 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyRelSeconds += yystack.l_mark[-1].Number * yystack.l_mark[0].Number * 60L;
	}
break;
case 40:
#line 327 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyRelSeconds += yystack.l_mark[0].Number * 60L;
	}
break;
case 41:
#line 330 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyRelSeconds += yystack.l_mark[-1].Number;
	}
break;
case 42:
#line 333 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyRelSeconds += yystack.l_mark[-1].Number;
	}
break;
case 43:
#line 336 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyRelSeconds++;
	}
break;
case 44:
#line 339 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyRelMonth += yystack.l_mark[-1].Number * yystack.l_mark[0].Number;
	}
break;
case 45:
#line 342 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyRelMonth += yystack.l_mark[-1].Number * yystack.l_mark[0].Number;
	}
break;
case 46:
#line 345 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    param->yyRelMonth += yystack.l_mark[0].Number;
	}
break;
case 47:
#line 350 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    if (param->yyHaveTime && param->yyHaveDate && !param->yyHaveRel)
		param->yyYear = yystack.l_mark[0].Number;
	    else {
		if(yystack.l_mark[0].Number>10000) {
		    param->yyHaveDate++;
		    param->yyDay= (yystack.l_mark[0].Number)%100;
		    param->yyMonth= (yystack.l_mark[0].Number/100)%100;
		    param->yyYear = yystack.l_mark[0].Number/10000;
		}
		else {
		    param->yyHaveTime++;
		    if (yystack.l_mark[0].Number < 100) {
			param->yyHour = yystack.l_mark[0].Number;
			param->yyMinutes = 0;
		    }
		    else {
		    	param->yyHour = yystack.l_mark[0].Number / 100;
		    	param->yyMinutes = yystack.l_mark[0].Number % 100;
		    }
		    param->yySeconds = 0;
		    param->yyMeridian = MER24;
	        }
	    }
	}
break;
case 48:
#line 377 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    yyval.Meridian = MER24;
	}
break;
case 49:
#line 380 "/home/donz/minix/lib/libutil/parsedate.y"
	{
	    yyval.Meridian = yystack.l_mark[0].Meridian;
	}
break;
#line 1776 "parsedate.c"
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
