#ifndef _yy_defines_h_
#define _yy_defines_h_

#define IF 257
#define ELSE 258
#define RETURN 259
#define WHILE 260
#define INT 261
#define VOID 262
#define NUM 263
#define ID 264
#define PLUS 265
#define MINUS 266
#define OVER 267
#define TIMES 268
#define LT 269
#define LE 270
#define GT 271
#define GE 272
#define EQ 273
#define NE 274
#define ASSIGN 275
#define SEMI 276
#define COMMA 277
#define LPAREN 278
#define RPAREN 279
#define LBRACE 280
#define RBRACE 281
#define LCURLY 282
#define RCURLY 283
#define ERROR 284
#define XIF 285

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
/* Default: YYLTYPE is the text position type. */
typedef struct YYLTYPE
{
    int first_line;
    int first_column;
    int last_line;
    int last_column;
    unsigned source;
} YYLTYPE;
#define YYLTYPE_IS_DECLARED 1
#endif
#define YYRHSLOC(rhs, k) ((rhs)[k])
extern YYLTYPE yylloc;

#endif /* _yy_defines_h_ */
