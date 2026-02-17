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

#line 37 "/home/donz/minix/usr.bin/menuc/parse.y"

#include <stdio.h>
#include "defs.h"

static id_rec *cur_menu;
static optn_info *cur_optn;

#line 46 "/home/donz/minix/usr.bin/menuc/parse.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char *s_value;
	int   i_value;
	optn_info *optn_value;
	action a_value;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 45 "parse.c"

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

#define X 257
#define Y 258
#define W 259
#define H 260
#define NO 261
#define BOX 262
#define SUB 263
#define HELP 264
#define MENU 265
#define NEXT 266
#define EXIT 267
#define ACTION 268
#define ENDWIN 269
#define OPTION 270
#define TITLE 271
#define DEFAULT 272
#define DISPLAY 273
#define ERROR 274
#define EXITSTRING 275
#define ALLOW 276
#define DYNAMIC 277
#define MENUS 278
#define SCROLLABLE 279
#define SHORTCUT 280
#define CLEAR 281
#define MESSAGES 282
#define ALWAYS 283
#define SCROLL 284
#define STRING 285
#define NAME 286
#define CODE 287
#define INT_CONST 288
#define CHAR_CONST 289
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    9,    9,    9,    9,    9,    9,   13,
   14,   12,   16,   11,   19,   10,   18,   18,   17,   17,
    3,    3,   15,   15,   15,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   15,   15,   15,   15,
   15,   15,   15,   15,    5,    5,   22,    4,   21,   21,
   23,   23,   24,   24,   24,   24,    7,    6,    6,   20,
   20,    8,    8,    2,    2,    2,
};
static const YYINT yylen[] = {                            2,
    2,    0,    1,    0,    2,    2,    2,    2,    2,    4,
    4,    3,    0,    5,    0,    9,    0,    1,    2,    3,
    1,    1,    2,    1,    2,    1,    2,    1,    2,    1,
    2,    1,    3,    2,    3,    2,    3,    2,    3,    3,
    3,    3,    2,    2,    1,    2,    0,    6,    1,    1,
    1,    3,    3,    3,    1,    1,    3,    0,    3,    0,
    3,    0,    3,    0,    3,    3,
};
static const YYINT yydefred[] = {                         0,
    3,    0,    4,    0,    0,   13,    0,    0,    5,    6,
    7,    8,    9,   15,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   26,    0,   24,    0,    0,    0,
   28,   30,   32,    0,    0,    0,    0,   12,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   25,    0,   23,
    0,   27,   29,   31,    0,   38,   22,   21,   43,   34,
   44,   36,    0,    0,   57,   10,   11,   19,    0,    0,
   39,   40,   41,   42,   37,   33,   35,   14,   59,   20,
    0,    0,    0,   47,   45,    0,   61,    0,    0,   46,
    0,   50,   49,    0,    0,    0,   16,    0,   63,    0,
    0,    0,    0,   56,   55,    0,   51,   65,   66,    0,
    0,   48,    0,   54,   53,   52,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  287,  291,  292,  300,  265,  272,  274,  276,  301,  302,
  303,  304,  305,  286,  307,  268,  298,  277,  310,  257,
  258,  259,  260,  261,  262,  263,  267,  271,  272,  275,
  279,  280,  281,  283,  306,   40,  297,   59,  278,  282,
   44,  308,  309,   61,   61,   61,   61,  262,  263,  267,
  272,  279,  280,  281,  283,  265,  285,  286,  294,  267,
  294,  284,  308,  269,  287,   59,   59,  306,   44,   59,
  288,  288,  288,  288,  265,  267,  284,   59,   41,  306,
  273,  311,  298,  270,  295,  296,   59,  313,  267,  295,
  299,  287,  294,  312,  298,  264,  293,   44,   59,  287,
  294,  263,  266,  267,  298,  314,  315,   59,   59,  265,
  265,   59,   44,  286,  286,  315,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          2,
    3,   97,   59,   85,   86,   37,  105,   91,    4,    9,
   10,   11,   12,   13,   35,   15,   42,   43,   19,   82,
   94,   88,  106,  107,
};
static const YYINT yysindex[] = {                      -278,
    0,    0,    0, -225, -268,    0, -244, -247,    0,    0,
    0,    0,    0,    0, -246,   -9,  -23, -272,   -2,  -11,
   -3,   -1,    4, -224,    0, -199,    0, -258, -200, -258,
    0,    0,    0, -216,   -2, -198, -217,    0,   13,   14,
 -246,   31,   17, -211, -210, -209, -208,    0, -184,    0,
 -183,    0,    0,    0, -201,    0,    0,    0,    0,    0,
    0,    0,  -39,   44,    0,    0,    0,    0, -246, -187,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -244, -182,   28,    0,    0, -248,    0, -233, -244,    0,
 -175,    0,    0,   46,   32, -223,    0, -222,    0,   33,
   34, -171, -170,    0,    0,  -36,    0,    0,    0, -190,
 -189,    0, -222,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         2,
    0,    0,    0,   98,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -188,    0,    0,   41,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   42,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -168,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,
    7,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
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
    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,    0,  -27,   18,    0,    0,   -7,    0,    0,    0,
    0,    0,    0,    0,  -37,    0,   68,    0,    0,    0,
    0,    0,    0,   -8,
};
#define YYTABLESIZE 283
static const YYINT yytable[] = {                         17,
   62,    2,   61,   68,   69,   39,   64,  113,    1,   40,
   20,   21,   22,   23,   24,   25,   26,   14,   89,   78,
   27,   84,  112,   16,   28,   29,   57,   58,   30,   18,
   36,   80,   31,   32,   33,   38,   34,   48,   49,    5,
  102,   41,   50,  103,  104,   16,    6,   51,    7,   44,
    8,   57,   58,   92,   52,   53,   54,   45,   55,   46,
   93,   57,   58,  100,   47,   56,   60,   62,  101,   65,
   64,   66,   67,   83,   69,   70,   71,   72,   73,   74,
   75,   95,   77,   76,   79,   81,   87,   84,   96,   98,
   99,  108,  109,  110,  111,  114,  115,    1,   58,   17,
   18,   60,   63,   90,  116,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,   62,   62,    2,    0,    0,    0,
    0,   64,   62,    2,   62,    2,   62,    2,   64,    0,
   64,    0,   64,
};
static const YYINT yycheck[] = {                          7,
    0,    0,   30,   41,   44,  278,    0,   44,  287,  282,
  257,  258,  259,  260,  261,  262,  263,  286,  267,   59,
  267,  270,   59,  268,  271,  272,  285,  286,  275,  277,
   40,   69,  279,  280,  281,   59,  283,  262,  263,  265,
  263,   44,  267,  266,  267,  268,  272,  272,  274,   61,
  276,  285,  286,  287,  279,  280,  281,   61,  283,   61,
   88,  285,  286,  287,   61,  265,  267,  284,   96,  287,
  269,   59,   59,   81,   44,   59,  288,  288,  288,  288,
  265,   89,  284,  267,   41,  273,   59,  270,  264,   44,
   59,   59,   59,  265,  265,  286,  286,    0,  287,   59,
   59,  270,   35,   86,  113,   -1,   -1,   -1,   -1,   -1,
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
   -1,   -1,   -1,   -1,  264,  265,  265,   -1,   -1,   -1,
   -1,  265,  272,  272,  274,  274,  276,  276,  272,   -1,
  274,   -1,  276,
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
   -1,   -1,
};
#endif
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 289
#define YYUNDFTOKEN 316
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,"'='",0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","X","Y","W",
"H","NO","BOX","SUB","HELP","MENU","NEXT","EXIT","ACTION","ENDWIN","OPTION",
"TITLE","DEFAULT","DISPLAY","ERROR","EXITSTRING","ALLOW","DYNAMIC","MENUS",
"SCROLLABLE","SHORTCUT","CLEAR","MESSAGES","ALWAYS","SCROLL","STRING","NAME",
"CODE","INT_CONST","CHAR_CONST","$accept","system","init_code","helpstr","text",
"option","option_list","act_opt","action","exitact","menu_list","menu_def",
"default_def","initerror_def","dynamic_def","msgxlat_def","opt","$$1",
"opt_list","opts","$$2","dispact","option_legend","$$3","elem_list","elem",
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : system",
"system : init_code menu_list",
"init_code :",
"init_code : CODE",
"menu_list :",
"menu_list : menu_list menu_def",
"menu_list : menu_list default_def",
"menu_list : menu_list initerror_def",
"menu_list : menu_list dynamic_def",
"menu_list : menu_list msgxlat_def",
"dynamic_def : ALLOW DYNAMIC MENUS ';'",
"msgxlat_def : ALLOW DYNAMIC MESSAGES ';'",
"initerror_def : ERROR action ';'",
"$$1 :",
"default_def : DEFAULT $$1 opt opt_list ';'",
"$$2 :",
"menu_def : MENU NAME $$2 opts ';' dispact option_list exitact helpstr",
"opts :",
"opts : opt_list",
"opt_list : ',' opt",
"opt_list : opt_list ',' opt",
"text : NAME",
"text : STRING",
"opt : NO EXIT",
"opt : EXIT",
"opt : NO BOX",
"opt : BOX",
"opt : NO SCROLLABLE",
"opt : SCROLLABLE",
"opt : NO SHORTCUT",
"opt : SHORTCUT",
"opt : NO CLEAR",
"opt : CLEAR",
"opt : NO DEFAULT EXIT",
"opt : DEFAULT EXIT",
"opt : NO ALWAYS SCROLL",
"opt : ALWAYS SCROLL",
"opt : NO SUB MENU",
"opt : SUB MENU",
"opt : X '=' INT_CONST",
"opt : Y '=' INT_CONST",
"opt : W '=' INT_CONST",
"opt : H '=' INT_CONST",
"opt : TITLE text",
"opt : EXITSTRING text",
"option_list : option",
"option_list : option_list option",
"$$3 :",
"option : OPTION $$3 option_legend ',' elem_list ';'",
"option_legend : text",
"option_legend : CODE",
"elem_list : elem",
"elem_list : elem_list ',' elem",
"elem : NEXT MENU NAME",
"elem : SUB MENU NAME",
"elem : action",
"elem : EXIT",
"action : ACTION act_opt CODE",
"act_opt :",
"act_opt : '(' ENDWIN ')'",
"dispact :",
"dispact : DISPLAY action ';'",
"exitact :",
"exitact : EXIT action ';'",
"helpstr :",
"helpstr : HELP CODE ';'",
"helpstr : HELP text ';'",

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
#line 69 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ check_defined();
	   if (!had_errors)
		   write_menu_file(yystack.l_mark[-1].s_value);
	 }
break;
case 2:
#line 75 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ yyval.s_value = ""; }
break;
case 10:
#line 88 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ do_dynamic = 1; }
break;
case 11:
#line 91 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ do_msgxlat = 1; }
break;
case 12:
#line 94 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ error_act = yystack.l_mark[-1].a_value; }
break;
case 13:
#line 97 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu = &default_menu; }
break;
case 15:
#line 101 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu = get_menu (yystack.l_mark[0].s_value);
		  if (cur_menu->info != NULL)
			  yyerror ("Menu %s defined twice", yystack.l_mark[0].s_value);
		  else {
			  cur_menu->info =
				  (menu_info *) malloc (sizeof (menu_info));
			  *(cur_menu->info) = default_info;
		  }
		}
break;
case 16:
#line 111 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ optn_info *t;
		  cur_menu->info->optns = NULL;
		  while (yystack.l_mark[-2].optn_value != NULL) {
			  t = yystack.l_mark[-2].optn_value;
			  yystack.l_mark[-2].optn_value = yystack.l_mark[-2].optn_value->next;
			  t->next = cur_menu->info->optns;
			  cur_menu->info->optns = t;
			  cur_menu->info->numopt++;
		  }
		}
break;
case 23:
#line 133 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->mopt |= MC_NOEXITOPT; }
break;
case 24:
#line 134 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->mopt &= ~MC_NOEXITOPT; }
break;
case 25:
#line 135 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->mopt |= MC_NOBOX; }
break;
case 26:
#line 136 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->mopt &= ~MC_NOBOX; }
break;
case 27:
#line 137 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->mopt &= ~MC_SCROLL; }
break;
case 28:
#line 138 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->mopt |= MC_SCROLL; }
break;
case 29:
#line 139 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->mopt |= MC_NOSHORTCUT; }
break;
case 30:
#line 140 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->mopt &= ~MC_NOSHORTCUT; }
break;
case 31:
#line 141 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->mopt |= MC_NOCLEAR; }
break;
case 32:
#line 142 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->mopt &= ~MC_NOCLEAR; }
break;
case 33:
#line 143 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->mopt &= ~MC_DFLTEXIT; }
break;
case 34:
#line 144 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->mopt |= MC_DFLTEXIT; }
break;
case 35:
#line 145 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->mopt &= ~MC_ALWAYS_SCROLL; }
break;
case 36:
#line 146 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->mopt |= MC_ALWAYS_SCROLL; }
break;
case 37:
#line 147 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->mopt &= ~MC_SUBMENU; }
break;
case 38:
#line 148 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->mopt |= MC_SUBMENU; }
break;
case 39:
#line 149 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->x = atoi(yystack.l_mark[0].s_value); }
break;
case 40:
#line 150 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->y = atoi(yystack.l_mark[0].s_value); }
break;
case 41:
#line 151 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->w = atoi(yystack.l_mark[0].s_value); }
break;
case 42:
#line 152 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->h = atoi(yystack.l_mark[0].s_value); }
break;
case 43:
#line 153 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->title = yystack.l_mark[0].s_value; }
break;
case 44:
#line 154 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->exitstr = yystack.l_mark[0].s_value;
				  cur_menu->info->mopt &= ~MC_NOEXITOPT; }
break;
case 46:
#line 159 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ yystack.l_mark[0].optn_value->next = yystack.l_mark[-1].optn_value; yyval.optn_value = yystack.l_mark[0].optn_value; }
break;
case 47:
#line 163 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_optn = (optn_info *) malloc (sizeof(optn_info));
		  cur_optn->menu = -1;
		  cur_optn->name = NULL;
		  cur_optn->name_is_code = FALSE;
		  cur_optn->issub = FALSE;
		  cur_optn->doexit = FALSE;
		  cur_optn->optact.code = "";
		  cur_optn->optact.endwin = FALSE;
		  cur_optn->next = NULL;
		}
break;
case 48:
#line 175 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ yyval.optn_value = cur_optn; }
break;
case 49:
#line 178 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_optn->name = yystack.l_mark[0].s_value; }
break;
case 50:
#line 179 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_optn->name = yystack.l_mark[0].s_value; cur_optn->name_is_code = TRUE;}
break;
case 53:
#line 186 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ id_rec *t = get_menu (yystack.l_mark[0].s_value);
		  if (cur_optn->menu != -1)
			  yyerror ("Double sub/next menu definition");
		  else {
			  cur_optn->menu = t->menu_no;
		  }
		}
break;
case 54:
#line 194 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ id_rec *t = get_menu (yystack.l_mark[0].s_value);
		  if (cur_optn->menu != -1)
			  yyerror ("Double sub/next menu definition");
		  else {
			  cur_optn->menu = t->menu_no;
			  cur_optn->issub = TRUE;
		  }
		}
break;
case 55:
#line 202 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_optn->optact = yystack.l_mark[0].a_value; }
break;
case 56:
#line 203 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_optn->doexit = TRUE; }
break;
case 57:
#line 207 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ yyval.a_value.code = yystack.l_mark[0].s_value;
		  yyval.a_value.endwin = yystack.l_mark[-1].i_value;
		}
break;
case 58:
#line 212 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ yyval.i_value = 0; }
break;
case 59:
#line 213 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ yyval.i_value = 1; }
break;
case 60:
#line 216 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->postact.code = ""; }
break;
case 61:
#line 217 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->postact = yystack.l_mark[-1].a_value; }
break;
case 62:
#line 221 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->exitact.code = ""; }
break;
case 63:
#line 222 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->exitact = yystack.l_mark[-1].a_value; }
break;
case 64:
#line 225 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->helpstr = NULL; }
break;
case 65:
#line 226 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ asprintf(&cur_menu->info->helpstr, "\"%s\"", yystack.l_mark[-1].s_value); }
break;
case 66:
#line 227 "/home/donz/minix/usr.bin/menuc/parse.y"
	{ cur_menu->info->helpstr = yystack.l_mark[-1].s_value; }
break;
#line 884 "parse.c"
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
