#ifndef _yy_defines_h_
#define _yy_defines_h_

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
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
