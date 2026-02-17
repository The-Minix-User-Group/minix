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

#line 33 "/home/donz/minix/bin/expr/expr.y"
#include <sys/cdefs.h>
#ifndef lint
__RCSID("$NetBSD: expr.y,v 1.39 2016/09/05 01:00:07 sevan Exp $");
#endif /* not lint */

#include <sys/types.h>

#include <err.h>
#include <errno.h>
#include <limits.h>
#include <locale.h>
#include <regex.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char * const *av;

static void yyerror(const char *, ...) __dead;
static int yylex(void);
static int is_zero_or_null(const char *);
static int is_integer(const char *);
static int64_t perform_arith_op(const char *, const char *, const char *);

#define YYSTYPE	const char *

#line 51 "expr.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

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

#define STRING 257
#define SPEC_OR 258
#define SPEC_AND 259
#define COMPARE 260
#define ADD_SUB_OPERATOR 261
#define MUL_DIV_MOD_OPERATOR 262
#define SPEC_REG 263
#define LENGTH 264
#define LEFT_PARENT 265
#define RIGHT_PARENT 266
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    2,    2,    2,    2,    2,    2,    2,    2,
};
static const YYINT yylen[] = {                            2,
    1,    1,    3,    3,    3,    3,    3,    3,    3,    2,
    1,    1,    1,    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
   11,   15,   16,   14,   12,   13,   17,    0,    0,    0,
    0,    2,   10,    0,    0,    0,    0,    0,    0,    0,
    9,    0,    0,    0,    0,    0,    5,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  257,  258,  259,  260,  261,  262,  263,  264,  265,  268,
  269,  270,  269,  269,  258,  259,  260,  261,  262,  263,
  266,  269,  269,  269,  269,  269,  269,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                         10,
   11,   12,
};
static const YYINT yysindex[] = {                      -224,
    0,    0,    0,    0,    0,    0,    0, -248, -224,    0,
 -216,    0,    0, -255, -224, -224, -224, -224, -224, -224,
    0, -211, -207, -249, -240, -263,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,
    2,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   26,   24,   15,   19,   10,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
   12,    0,
};
#define YYTABLESIZE 292
static const YYINT yytable[] = {                         20,
   18,    1,   15,   16,   17,   18,   19,   20,    1,    7,
   21,   18,   19,   20,    8,    8,    9,    0,    6,   13,
   14,   19,   20,    4,    0,    3,   22,   23,   24,   25,
   26,   27,    1,    2,    3,    4,    5,    6,    7,    8,
    9,   15,   16,   17,   18,   19,   20,   16,   17,   18,
   19,   20,   17,   18,   19,   20,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,   18,   18,
   18,   18,   18,   18,    0,    0,   18,    7,    7,    7,
    7,    7,    8,    8,    8,    7,    6,    6,    6,    6,
    8,    4,    4,    3,    6,    0,    0,    0,    0,    4,
    0,    3,
};
static const YYINT yycheck[] = {                        263,
    0,    0,  258,  259,  260,  261,  262,  263,  257,    0,
  266,  261,  262,  263,    0,  264,  265,   -1,    0,    8,
    9,  262,  263,    0,   -1,    0,   15,   16,   17,   18,
   19,   20,  257,  258,  259,  260,  261,  262,  263,  264,
  265,  258,  259,  260,  261,  262,  263,  259,  260,  261,
  262,  263,  260,  261,  262,  263,   -1,   -1,   -1,   -1,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  258,  259,
  260,  261,  262,  263,   -1,   -1,  266,  258,  259,  260,
  261,  262,  258,  259,  260,  266,  258,  259,  260,  261,
  266,  258,  259,  258,  266,   -1,   -1,   -1,   -1,  266,
   -1,  266,
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
   -1,
};
#endif
#define YYFINAL 10
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 266
#define YYUNDFTOKEN 271
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","STRING","SPEC_OR","SPEC_AND",
"COMPARE","ADD_SUB_OPERATOR","MUL_DIV_MOD_OPERATOR","SPEC_REG","LENGTH",
"LEFT_PARENT","RIGHT_PARENT","$accept","exp","expr","item","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : exp",
"exp : expr",
"expr : item",
"expr : expr SPEC_OR expr",
"expr : expr SPEC_AND expr",
"expr : expr SPEC_REG expr",
"expr : expr ADD_SUB_OPERATOR expr",
"expr : expr MUL_DIV_MOD_OPERATOR expr",
"expr : expr COMPARE expr",
"expr : LEFT_PARENT expr RIGHT_PARENT",
"expr : LENGTH expr",
"item : STRING",
"item : ADD_SUB_OPERATOR",
"item : MUL_DIV_MOD_OPERATOR",
"item : COMPARE",
"item : SPEC_OR",
"item : SPEC_AND",
"item : SPEC_REG",
"item : LENGTH",

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
#line 246 "/home/donz/minix/bin/expr/expr.y"

/*
 * Returns 1 if the string is empty or contains only numeric zero.
 */
static int
is_zero_or_null(const char *str)
{
	char *endptr;

	return str[0] == '\0'
		|| ( strtoll(str, &endptr, 10) == 0LL
			&& endptr[0] == '\0');
}

/*
 * Returns 1 if the string is an integer.
 */
static int
is_integer(const char *str)
{
	char *endptr;

	(void) strtoll(str, &endptr, 10);
	/* note we treat empty string as valid number */
	return (endptr[0] == '\0');
}

static int64_t
perform_arith_op(const char *left, const char *op, const char *right)
{
	int64_t res, sign, l, r;
	u_int64_t temp;

	res = 0;

	if (!is_integer(left)) {
		yyerror("non-integer argument '%s'", left);
		/* NOTREACHED */
	}
	if (!is_integer(right)) {
		yyerror("non-integer argument '%s'", right);
		/* NOTREACHED */
	}

	errno = 0;
	l = strtoll(left, NULL, 10);
	if (errno == ERANGE) {
		yyerror("value '%s' is %s is %lld", left,
		    (l > 0) ? "too big, maximum" : "too small, minimum",
		    (l > 0) ? LLONG_MAX : LLONG_MIN);
		/* NOTREACHED */
	}

	errno = 0;
	r = strtoll(right, NULL, 10);
	if (errno == ERANGE) {
		yyerror("value '%s' is %s is %lld", right,
		    (l > 0) ? "too big, maximum" : "too small, minimum",
	  	    (l > 0) ? LLONG_MAX : LLONG_MIN);
		/* NOTREACHED */
	}

	switch(op[0]) {
	case '+':
		/* 
		 * Do the op into an unsigned to avoid overflow and then cast
		 * back to check the resulting signage. 
		 */
		temp = l + r;
		res = (int64_t) temp;
		/* very simplistic check for over-& underflow */
		if ((res < 0 && l > 0 && r > 0)
	  	    || (res > 0 && l < 0 && r < 0)) 
			yyerror("integer overflow or underflow occurred for "
                            "operation '%s %s %s'", left, op, right);
		break;
	case '-':
		/* 
		 * Do the op into an unsigned to avoid overflow and then cast
		 * back to check the resulting signage. 
		 */
		temp = l - r;
		res = (int64_t) temp;
		/* very simplistic check for over-& underflow */
		if ((res < 0 && l > 0 && l > r)
		    || (res > 0 && l < 0 && l < r) ) 
			yyerror("integer overflow or underflow occurred for "
			    "operation '%s %s %s'", left, op, right);
		break;
	case '/':
		if (r == 0) 
			yyerror("second argument to '%s' must not be zero", op);
		res = l / r;
			
		break;
	case '%':
		if (r == 0)
			yyerror("second argument to '%s' must not be zero", op);
		res = l % r;
		break;
	case '*':
		/* shortcut */
		if ((l == 0) || (r == 0)) {
			res = 0;
			break;
		}
				
		sign = 1;
		if (l < 0)
			sign *= -1;
		if (r < 0)
			sign *= -1;

		res = l * r;
		/*
		 * XXX: not the most portable but works on anything with 2's
		 * complement arithmetic. If the signs don't match or the
		 * result was 0 on 2's complement this overflowed.
		 */
		if ((res < 0 && sign > 0) || (res > 0 && sign < 0) || 
		    (res == 0))
			yyerror("integer overflow or underflow occurred for "
			    "operation '%s %s %s'", left, op, right);
			/* NOTREACHED */
		break;
	}
	return res;
}

static const char *x = "|&=<>+-*/%:()";
static const int x_token[] = {
	SPEC_OR, SPEC_AND, COMPARE, COMPARE, COMPARE, ADD_SUB_OPERATOR,
	ADD_SUB_OPERATOR, MUL_DIV_MOD_OPERATOR, MUL_DIV_MOD_OPERATOR, 
	MUL_DIV_MOD_OPERATOR, SPEC_REG, LEFT_PARENT, RIGHT_PARENT
};

static int handle_ddash = 1;

int
yylex(void)
{
	const char *p = *av++;
	int retval;

	if (!p)
		retval = 0;
	else if (p[1] == '\0') {
		const char *w = strchr(x, p[0]);
		if (w) {
			retval = x_token[w-x];
		} else {
			retval = STRING;
		}
	} else if (p[1] == '=' && p[2] == '\0'
			&& (p[0] == '>' || p[0] == '<' || p[0] == '!'))
		retval = COMPARE;
	else if (handle_ddash && p[0] == '-' && p[1] == '-' && p[2] == '\0') {
		/* ignore "--" if passed as first argument and isn't followed
		 * by another STRING */
		retval = yylex();
		if (retval != STRING && retval != LEFT_PARENT
		    && retval != RIGHT_PARENT) {
			/* is not followed by string or parenthesis, use as
			 * STRING */
			retval = STRING;
			av--;	/* was increased in call to yylex() above */
			p = "--";
		} else {
			/* "--" is to be ignored */
			p = yylval;
		}
	} else if (strcmp(p, "length") == 0)
		retval = LENGTH;
	else
		retval = STRING;

	handle_ddash = 0;
	yylval = p;

	return retval;
}

/*
 * Print error message and exit with error 2 (syntax error).
 */
static __printflike(1, 2) void
yyerror(const char *fmt, ...)
{
	va_list arg;

	va_start(arg, fmt);
	verrx(2, fmt, arg);
	va_end(arg);
}

int
main(int argc, const char * const *argv)
{
	setprogname(argv[0]);
	(void)setlocale(LC_ALL, "");

	if (argc == 1) {
		(void)fprintf(stderr, "usage: %s expression\n",
		    getprogname());
		exit(2);
	}

	av = argv + 1;

	exit(yyparse());
	/* NOTREACHED */
}
#line 534 "expr.c"

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
#line 73 "/home/donz/minix/bin/expr/expr.y"
	{
		(void) printf("%s\n", yystack.l_mark[0]);
		return (is_zero_or_null(yystack.l_mark[0]));
		}
break;
case 2:
#line 79 "/home/donz/minix/bin/expr/expr.y"
	{ yyval = yystack.l_mark[0]; }
break;
case 3:
#line 80 "/home/donz/minix/bin/expr/expr.y"
	{
		/*
		 * Return evaluation of first expression if it is neither
		 * an empty string nor zero; otherwise, returns the evaluation
		 * of second expression.
		 */
		if (!is_zero_or_null(yystack.l_mark[-2]))
			yyval = yystack.l_mark[-2];
		else
			yyval = yystack.l_mark[0];
		}
break;
case 4:
#line 91 "/home/donz/minix/bin/expr/expr.y"
	{
		/*
		 * Returns the evaluation of first expr if neither expression
		 * evaluates to an empty string or zero; otherwise, returns
		 * zero.
		 */
		if (!is_zero_or_null(yystack.l_mark[-2]) && !is_zero_or_null(yystack.l_mark[0]))
			yyval = yystack.l_mark[-2];
		else
			yyval = "0";
		}
break;
case 5:
#line 102 "/home/donz/minix/bin/expr/expr.y"
	{
		/*
		 * The ``:'' operator matches first expr against the second,
		 * which must be a regular expression.
		 */
		regex_t rp;
		regmatch_t rm[2];
		int eval;

		/* compile regular expression */
		if ((eval = regcomp(&rp, yystack.l_mark[0], REG_BASIC)) != 0) {
			char errbuf[256];
			(void)regerror(eval, &rp, errbuf, sizeof(errbuf));
			yyerror("%s", errbuf);
			/* NOT REACHED */
		}
		
		/* compare string against pattern --  remember that patterns 
		   are anchored to the beginning of the line */
		if (regexec(&rp, yystack.l_mark[-2], 2, rm, 0) == 0 && rm[0].rm_so == 0) {
			char *val;
			if (rm[1].rm_so >= 0) {
				(void) asprintf(&val, "%.*s",
					(int) (rm[1].rm_eo - rm[1].rm_so),
					yystack.l_mark[-2] + rm[1].rm_so);
			} else {
				(void) asprintf(&val, "%d",
					(int)(rm[0].rm_eo - rm[0].rm_so));
			}
			if (val == NULL)
				err(1, NULL);
			yyval = val;
		} else {
			if (rp.re_nsub == 0) {
				yyval = "0";
			} else {
				yyval = "";
			}
		}

		}
break;
case 6:
#line 143 "/home/donz/minix/bin/expr/expr.y"
	{
		/* Returns the results of addition, subtraction */
		char *val;
		int64_t res;
		
		res = perform_arith_op(yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]);
		(void) asprintf(&val, "%lld", (long long int) res);
		if (val == NULL)
			err(1, NULL);
		yyval = val;
                }
break;
case 7:
#line 155 "/home/donz/minix/bin/expr/expr.y"
	{
		/* 
		 * Returns the results of multiply, divide or remainder of 
		 * numeric-valued arguments.
		 */
		char *val;
		int64_t res;

		res = perform_arith_op(yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]);
		(void) asprintf(&val, "%lld", (long long int) res);
		if (val == NULL)
			err(1, NULL);
		yyval = val;

		}
break;
case 8:
#line 170 "/home/donz/minix/bin/expr/expr.y"
	{
		/*
		 * Returns the results of integer comparison if both arguments
		 * are integers; otherwise, returns the results of string
		 * comparison using the locale-specific collation sequence.
		 * The result of each comparison is 1 if the specified relation
		 * is true, or 0 if the relation is false.
		 */

		int64_t l, r;
		int res;

		res = 0;

		/*
		 * Slight hack to avoid differences in the compare code
		 * between string and numeric compare.
		 */
		if (is_integer(yystack.l_mark[-2]) && is_integer(yystack.l_mark[0])) {
			/* numeric comparison */
			l = strtoll(yystack.l_mark[-2], NULL, 10);
			r = strtoll(yystack.l_mark[0], NULL, 10);
		} else {
			/* string comparison */
			l = strcoll(yystack.l_mark[-2], yystack.l_mark[0]);
			r = 0;
		}

		switch(yystack.l_mark[-1][0]) {	
		case '=': /* equal */
			res = (l == r);
			break;
		case '>': /* greater or greater-equal */
			if (yystack.l_mark[-1][1] == '=')
				res = (l >= r);
			else
				res = (l > r);
			break;
		case '<': /* lower or lower-equal */
			if (yystack.l_mark[-1][1] == '=')
				res = (l <= r);
			else
				res = (l < r);
			break;
		case '!': /* not equal */
			/* the check if this is != was done in yylex() */
			res = (l != r);
		}

		yyval = (res) ? "1" : "0";

		}
break;
case 9:
#line 222 "/home/donz/minix/bin/expr/expr.y"
	{ yyval = yystack.l_mark[-1]; }
break;
case 10:
#line 223 "/home/donz/minix/bin/expr/expr.y"
	{
		/*
		 * Return length of 'expr' in bytes.
		 */
		char *ln;

		asprintf(&ln, "%ld", (long) strlen(yystack.l_mark[0]));
		if (ln == NULL)
			err(1, NULL);
		yyval = ln;
		}
break;
#line 924 "expr.c"
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
