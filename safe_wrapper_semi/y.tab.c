/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20221106

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

#line 8 "cminus.y"
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"


#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
int yylex(void); /* added 11/2/11 to ensure no conflict with lex*/
void yyerror(const char *s);
#line 39 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

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

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(YYLTYPE *loc, const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(&yylloc, msg)
#endif

extern int YYPARSE_DECL();

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
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    3,    3,    5,    5,
    4,    8,    8,    8,   10,   10,   11,   11,    9,    9,
    9,    9,   12,   12,   13,   13,   14,   14,   14,   14,
   14,   15,   15,   16,   16,   17,   18,   18,   19,   19,
   20,   20,   21,   21,   23,   23,   23,   23,   23,   23,
   22,   22,   24,   24,   25,   25,   26,   26,   27,   27,
   27,   27,   27,   28,   28,   29,   29,    7,    6,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    1,    1,    1,    3,    6,    1,    1,
    6,    1,    1,    0,    3,    1,    2,    4,    4,    3,
    3,    2,    2,    1,    2,    1,    1,    1,    1,    1,
    1,    2,    1,    5,    7,    5,    2,    3,    3,    1,
    1,    4,    3,    1,    1,    1,    1,    1,    1,    1,
    3,    1,    1,    1,    3,    1,    1,    1,    3,    1,
    1,    1,    1,    3,    4,    3,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    6,    9,   10,    0,    0,    3,    4,    5,    0,    2,
   69,    0,    7,    0,    0,    0,    0,    0,    0,   16,
   68,    0,    0,    0,    0,    0,    0,    0,   11,   15,
    8,   18,   63,    0,    0,    0,   33,    0,   22,   24,
    0,    0,   62,   28,    0,    0,   26,   27,   29,   30,
   31,    0,    0,   40,    0,    0,   56,   61,    0,   37,
    0,    0,    0,    0,    0,    0,   21,   23,    0,   20,
   25,   32,    0,   53,   54,   45,   46,   47,   48,   49,
   50,    0,    0,   58,   57,    0,    0,   38,    0,   59,
   64,   67,    0,    0,   19,   39,   60,    0,    0,   55,
    0,    0,    0,   65,   42,    0,   36,   66,    0,   35,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  256,  261,  262,  287,  288,  289,  290,  291,  292,  289,
  264,  293,  276,  278,  280,  262,  292,  295,  297,  298,
  263,  294,  293,  279,  277,  281,  280,  282,  296,  298,
  276,  281,  256,  257,  259,  260,  276,  278,  283,  290,
  292,  293,  294,  296,  299,  300,  301,  302,  303,  304,
  305,  306,  307,  308,  309,  312,  314,  315,  278,  276,
  306,  278,  306,  293,  278,  280,  283,  290,  300,  283,
  301,  276,  275,  265,  266,  269,  270,  271,  272,  273,
  274,  310,  311,  267,  268,  313,  306,  276,  306,  279,
  279,  306,  316,  306,  283,  306,  307,  309,  312,  314,
  279,  279,  277,  279,  281,  301,  301,  306,  258,  301,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          4,
    5,    6,    7,    8,    9,   42,   43,   18,   44,   19,
   20,   45,   46,   47,   48,   49,   50,   51,   52,   53,
   54,   55,   82,   83,   56,   86,   57,   58,   93,
};
static const YYINT yysindex[] = {                      -245,
    0,    0,    0,    0, -245,    0,    0,    0, -257,    0,
    0, -217,    0, -137, -253,    0, -257, -258, -251,    0,
    0, -210, -197, -246, -132, -177, -179, -216,    0,    0,
    0,    0,    0, -170, -244, -161,    0, -214,    0,    0,
 -257, -241,    0,    0, -187, -178,    0,    0,    0,    0,
    0, -149, -144,    0,  -43, -156,    0,    0, -214,    0,
 -142, -214, -143, -196, -250, -214,    0,    0, -150,    0,
    0,    0, -214,    0,    0,    0,    0,    0,    0,    0,
    0, -214, -214,    0,    0, -214, -140,    0, -139,    0,
    0,    0, -224, -136,    0,    0,    0, -145, -156,    0,
 -113, -113, -214,    0,    0, -120,    0,    0, -113,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,  158,    0,    0,    0,    0,    0,
    0,    0,    0, -118,    0, -256,    0,    0, -112,    0,
    0,    0, -176,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -95,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -78,    0, -225, -117,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -189,  -61,    0,
    0,    0,    0,    0,    0, -141,    0,    0,    0,    0,
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
};
#endif
static const YYINT yygindex[] = {                         0,
    0,  161,  -23,    0,  -10,   -8,  153,    0,  159,    0,
  160,    0,  152,  -44,    0,    0,    0,    0,  -35,   11,
    0,  118,    0,    0,  119,    0,  120,    0,    0,
};
#define YYTABLESIZE 231
static const YYINT yytable[] = {                         61,
   12,   71,   63,   17,   40,   33,   11,   10,   23,   21,
    1,   33,   21,   11,   17,    2,    3,   41,   21,   11,
   24,   68,   13,   87,   71,   25,   89,   38,   91,   92,
   94,   60,   64,   38,   41,   28,   65,   96,   66,   33,
   34,   33,   35,   36,    2,    3,   21,   11,   21,   11,
   44,   44,  103,   44,  104,   44,  106,  107,   13,   37,
   14,   38,   15,   38,  110,   28,   39,  108,   33,   34,
   26,   35,   36,    2,    3,   21,   11,   33,   34,   13,
   35,   36,   27,   15,   21,   11,   43,   43,   37,   43,
   38,   43,   97,   97,   28,   67,   97,   37,   31,   38,
   17,   32,   17,   28,   70,   33,   34,   59,   35,   36,
   84,   85,   21,   11,   34,   34,   62,   34,   34,   74,
   75,   34,   34,    2,   16,   37,   72,   38,    2,    3,
   73,   28,   95,   88,   34,   90,   34,  109,  101,  102,
   34,   34,   33,   34,  105,   35,   36,   52,   52,   21,
   11,   52,   52,   52,   52,   52,   52,    1,   52,   52,
   14,   52,   37,   52,   38,   10,   12,   22,   28,   41,
   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,
   41,   41,   29,   41,   30,   41,   60,   60,   60,   60,
   60,   60,   60,   60,   60,   60,   69,   60,   60,   98,
   60,   99,   60,   51,   51,  100,    0,   51,   51,   51,
   51,   51,   51,    0,   51,   51,    0,   51,    0,   51,
    0,   74,   75,    0,    0,   76,   77,   78,   79,   80,
   81,
};
static const YYINT yycheck[] = {                         35,
    9,   46,   38,   14,   28,  256,  264,  264,   17,  263,
  256,  256,  263,  264,   25,  261,  262,   28,  263,  264,
  279,   45,  279,   59,   69,  277,   62,  278,  279,   65,
   66,  276,   41,  278,   45,  282,  278,   73,  280,  256,
  257,  256,  259,  260,  261,  262,  263,  264,  263,  264,
  276,  277,  277,  279,  279,  281,  101,  102,  276,  276,
  278,  278,  280,  278,  109,  282,  283,  103,  256,  257,
  281,  259,  260,  261,  262,  263,  264,  256,  257,  276,
  259,  260,  280,  280,  263,  264,  276,  277,  276,  279,
  278,  281,   82,   83,  282,  283,   86,  276,  276,  278,
  277,  281,  279,  282,  283,  256,  257,  278,  259,  260,
  267,  268,  263,  264,  256,  257,  278,  259,  260,  265,
  266,  263,  264,  261,  262,  276,  276,  278,  261,  262,
  275,  282,  283,  276,  276,  279,  278,  258,  279,  279,
  282,  283,  256,  257,  281,  259,  260,  265,  266,  263,
  264,  269,  270,  271,  272,  273,  274,    0,  276,  277,
  279,  279,  276,  281,  278,    5,  279,   15,  282,  265,
  266,  267,  268,  269,  270,  271,  272,  273,  274,  275,
  276,  277,   24,  279,   25,  281,  265,  266,  267,  268,
  269,  270,  271,  272,  273,  274,   45,  276,  277,   82,
  279,   83,  281,  265,  266,   86,   -1,  269,  270,  271,
  272,  273,  274,   -1,  276,  277,   -1,  279,   -1,  281,
   -1,  265,  266,   -1,   -1,  269,  270,  271,  272,  273,
  274,
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
};
#endif
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 285
#define YYUNDFTOKEN 317
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","IF","ELSE","RETURN","WHILE",
"INT","VOID","NUM","ID","PLUS","MINUS","OVER","TIMES","LT","LE","GT","GE","EQ",
"NE","ASSIGN","SEMI","COMMA","LPAREN","RPAREN","LBRACE","RBRACE","LCURLY",
"RCURLY","ERROR","XIF","$accept","program","stmt_seq","stmt","var_stmt",
"fun_stmt","type_spec","identifier","number","params","comp_stmt","param_list",
"param","local_stmt","stmt_list","statement","expr_stmt","sel_stmt","it_stmt",
"ret_stmt","expr","var","simp_expr","sum_exp","relat","sum","term","mult",
"factor","activation","args_seq","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : stmt_seq",
"stmt_seq : stmt_seq stmt",
"stmt_seq : stmt",
"stmt : var_stmt",
"stmt : fun_stmt",
"stmt : error",
"var_stmt : type_spec identifier SEMI",
"var_stmt : type_spec identifier LBRACE number RBRACE SEMI",
"type_spec : INT",
"type_spec : VOID",
"fun_stmt : type_spec identifier LPAREN params RPAREN comp_stmt",
"params : param_list",
"params : VOID",
"params :",
"param_list : param_list COMMA param",
"param_list : param",
"param : type_spec identifier",
"param : type_spec identifier LBRACE RBRACE",
"comp_stmt : LCURLY local_stmt stmt_list RCURLY",
"comp_stmt : LCURLY stmt_list RCURLY",
"comp_stmt : LCURLY local_stmt RCURLY",
"comp_stmt : LCURLY RCURLY",
"local_stmt : local_stmt var_stmt",
"local_stmt : var_stmt",
"stmt_list : stmt_list statement",
"stmt_list : statement",
"statement : expr_stmt",
"statement : comp_stmt",
"statement : sel_stmt",
"statement : it_stmt",
"statement : ret_stmt",
"expr_stmt : expr SEMI",
"expr_stmt : SEMI",
"sel_stmt : IF LPAREN expr RPAREN statement",
"sel_stmt : IF LPAREN expr RPAREN statement ELSE statement",
"it_stmt : WHILE LPAREN expr RPAREN statement",
"ret_stmt : RETURN SEMI",
"ret_stmt : RETURN expr SEMI",
"expr : var ASSIGN expr",
"expr : simp_expr",
"var : identifier",
"var : identifier LBRACE expr RBRACE",
"simp_expr : sum_exp relat sum_exp",
"simp_expr : sum_exp",
"relat : LT",
"relat : LE",
"relat : GT",
"relat : GE",
"relat : EQ",
"relat : NE",
"sum_exp : sum_exp sum term",
"sum_exp : term",
"sum : PLUS",
"sum : MINUS",
"term : term mult factor",
"term : factor",
"mult : TIMES",
"mult : OVER",
"factor : LPAREN expr RPAREN",
"factor : var",
"factor : activation",
"factor : number",
"factor : error",
"activation : identifier LPAREN RPAREN",
"activation : identifier LPAREN args_seq RPAREN",
"args_seq : args_seq COMMA expr",
"args_seq : expr",
"number : NUM",
"identifier : ID",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

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

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 254 "cminus.y"


/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}

#line 545 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
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
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

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

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
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
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 40 "cminus.y"
	{ savedTree = yystack.l_mark[0];}
#line 1218 "y.tab.c"
break;
case 2:
#line 43 "cminus.y"
	{ YYSTYPE t = yystack.l_mark[-1];
                   if (t != NULL)
                   { while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = yystack.l_mark[0];
                     yyval = yystack.l_mark[-1]; }
                     else yyval = yystack.l_mark[0];
                 }
#line 1230 "y.tab.c"
break;
case 3:
#line 51 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1235 "y.tab.c"
break;
case 4:
#line 53 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1240 "y.tab.c"
break;
case 5:
#line 54 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1245 "y.tab.c"
break;
case 6:
#line 55 "cminus.y"
	{ yyval = NULL; }
#line 1250 "y.tab.c"
break;
case 7:
#line 58 "cminus.y"
	{ yyval = newDeclNode(VarK);
                yyval->type = yystack.l_mark[-2]->kind.type;
                yyval->attr.name = yystack.l_mark[-1]->attr.name;
                yyval->lineno = yystack.l_mark[-1]->lineno;
				      }
#line 1259 "y.tab.c"
break;
case 8:
#line 64 "cminus.y"
	{ yyval = newDeclNode(VarK);
                yyval->type = yystack.l_mark[-5]->kind.type;
                yyval->attr.name = yystack.l_mark[-4]->attr.name;
                yyval->attr.val = yystack.l_mark[-2]->attr.val;
                yyval->lineno = yystack.l_mark[-4]->lineno;
				      }
#line 1269 "y.tab.c"
break;
case 9:
#line 71 "cminus.y"
	{ yyval = newTypeNode(Integer); }
#line 1274 "y.tab.c"
break;
case 10:
#line 72 "cminus.y"
	{ yyval = newTypeNode(Void); }
#line 1279 "y.tab.c"
break;
case 11:
#line 75 "cminus.y"
	{ yyval = newDeclNode(FunK); 
              yyval->type = yystack.l_mark[-5]->kind.type; 
              yyval->attr.name = yystack.l_mark[-4]->attr.name;
              yyval->child[0] = yystack.l_mark[-2];
              yyval->child[1] = yystack.l_mark[0];
              yyval->lineno = yystack.l_mark[-4]->lineno; }
#line 1289 "y.tab.c"
break;
case 12:
#line 82 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1294 "y.tab.c"
break;
case 13:
#line 83 "cminus.y"
	{ yyval = NULL; }
#line 1299 "y.tab.c"
break;
case 14:
#line 84 "cminus.y"
	{ yyval = NULL; }
#line 1304 "y.tab.c"
break;
case 15:
#line 87 "cminus.y"
	{ YYSTYPE t = yystack.l_mark[-2];
                if (t != NULL){
                  while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = yystack.l_mark[0];
                  yyval = yystack.l_mark[-2];
                }
                else yyval = yystack.l_mark[0];
				      }
#line 1317 "y.tab.c"
break;
case 16:
#line 96 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1322 "y.tab.c"
break;
case 17:
#line 99 "cminus.y"
	{ yyval = newDeclNode(ParamK);
				        yyval->type = yystack.l_mark[-1]->kind.type;
                yyval->attr.name = yystack.l_mark[0]->attr.name;
                yyval->lineno = yystack.l_mark[0]->lineno;
				      }
#line 1331 "y.tab.c"
break;
case 18:
#line 105 "cminus.y"
	{ yyval = newDeclNode(ParamK);
				        yyval->type = yystack.l_mark[-3]->kind.type;
                yyval->attr.name = yystack.l_mark[-2]->attr.name;                
                yyval->lineno = yystack.l_mark[-2]->lineno;
				      }
#line 1340 "y.tab.c"
break;
case 19:
#line 112 "cminus.y"
	{ YYSTYPE t = yystack.l_mark[-2];
                if (t != NULL){
                  while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = yystack.l_mark[-1];
                  yyval = yystack.l_mark[-2];
                }
                else yyval = yystack.l_mark[-1]; }
#line 1352 "y.tab.c"
break;
case 20:
#line 120 "cminus.y"
	{ yyval = yystack.l_mark[-1]; }
#line 1357 "y.tab.c"
break;
case 21:
#line 121 "cminus.y"
	{ yyval = yystack.l_mark[-1]; }
#line 1362 "y.tab.c"
break;
case 22:
#line 122 "cminus.y"
	{ yyval = NULL; }
#line 1367 "y.tab.c"
break;
case 23:
#line 125 "cminus.y"
	{ YYSTYPE t = yystack.l_mark[-1];
                if(t != NULL) {
                  while(t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = yystack.l_mark[0];
                  yyval = yystack.l_mark[-1];
                }
                else yyval = yystack.l_mark[0]; }
#line 1379 "y.tab.c"
break;
case 24:
#line 133 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1384 "y.tab.c"
break;
case 25:
#line 136 "cminus.y"
	{ YYSTYPE t = yystack.l_mark[-1];
                if(t != NULL){
                  while(t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = yystack.l_mark[0];
                  yyval = yystack.l_mark[-1];
                }
                else yyval = yystack.l_mark[0]; }
#line 1396 "y.tab.c"
break;
case 26:
#line 144 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1401 "y.tab.c"
break;
case 27:
#line 146 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1406 "y.tab.c"
break;
case 28:
#line 147 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1411 "y.tab.c"
break;
case 29:
#line 148 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1416 "y.tab.c"
break;
case 30:
#line 149 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1421 "y.tab.c"
break;
case 31:
#line 150 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1426 "y.tab.c"
break;
case 32:
#line 152 "cminus.y"
	{ yyval = yystack.l_mark[-1]; }
#line 1431 "y.tab.c"
break;
case 33:
#line 153 "cminus.y"
	{ yyval = NULL; }
#line 1436 "y.tab.c"
break;
case 34:
#line 156 "cminus.y"
	{ yyval = newStmtNode(IfK);
                yyval->child[0] = yystack.l_mark[-2];
                yyval->child[1] = yystack.l_mark[0]; }
#line 1443 "y.tab.c"
break;
case 35:
#line 160 "cminus.y"
	{ yyval = newStmtNode(IfK);
                yyval->child[0] = yystack.l_mark[-4];
                yyval->child[1] = yystack.l_mark[-2];
                yyval->child[2] = yystack.l_mark[0]; }
#line 1451 "y.tab.c"
break;
case 36:
#line 166 "cminus.y"
	{ yyval = newStmtNode(WhileK);
                yyval->child[0] = yystack.l_mark[-2];
                yyval->child[1] = yystack.l_mark[0]; }
#line 1458 "y.tab.c"
break;
case 37:
#line 170 "cminus.y"
	{ yyval = newStmtNode(ReturnK); }
#line 1463 "y.tab.c"
break;
case 38:
#line 172 "cminus.y"
	{ yyval = newStmtNode(ReturnK); 
                yyval->child[0] = yystack.l_mark[-1]; }
#line 1469 "y.tab.c"
break;
case 39:
#line 176 "cminus.y"
	{ yyval = newStmtNode(AssignK);
                yyval->child[0] = yystack.l_mark[-2];
                yyval->child[1] = yystack.l_mark[0]; }
#line 1476 "y.tab.c"
break;
case 40:
#line 179 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1481 "y.tab.c"
break;
case 41:
#line 181 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1486 "y.tab.c"
break;
case 42:
#line 183 "cminus.y"
	{ yyval = yystack.l_mark[-3];
                yyval->child[0] = yystack.l_mark[-1]; }
#line 1492 "y.tab.c"
break;
case 43:
#line 187 "cminus.y"
	{ yyval = yystack.l_mark[-1];
                yyval->child[0] = yystack.l_mark[-2];
                yyval->child[1] = yystack.l_mark[0]; }
#line 1499 "y.tab.c"
break;
case 44:
#line 190 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1504 "y.tab.c"
break;
case 45:
#line 192 "cminus.y"
	{ yyval = newExpNode(OpK); yyval->attr.op = LT; }
#line 1509 "y.tab.c"
break;
case 46:
#line 193 "cminus.y"
	{ yyval = newExpNode(OpK); yyval->attr.op = LE; }
#line 1514 "y.tab.c"
break;
case 47:
#line 194 "cminus.y"
	{ yyval = newExpNode(OpK); yyval->attr.op = GT; }
#line 1519 "y.tab.c"
break;
case 48:
#line 195 "cminus.y"
	{ yyval = newExpNode(OpK); yyval->attr.op = GE; }
#line 1524 "y.tab.c"
break;
case 49:
#line 196 "cminus.y"
	{ yyval = newExpNode(OpK); yyval->attr.op = EQ; }
#line 1529 "y.tab.c"
break;
case 50:
#line 197 "cminus.y"
	{ yyval = newExpNode(OpK); yyval->attr.op = NE; }
#line 1534 "y.tab.c"
break;
case 51:
#line 200 "cminus.y"
	{ yyval = yystack.l_mark[-1];
                yyval->child[0] = yystack.l_mark[-2];
                yyval->child[1] = yystack.l_mark[0]; }
#line 1541 "y.tab.c"
break;
case 52:
#line 203 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1546 "y.tab.c"
break;
case 53:
#line 205 "cminus.y"
	{ yyval = newExpNode(OpK); yyval->attr.op = PLUS; }
#line 1551 "y.tab.c"
break;
case 54:
#line 206 "cminus.y"
	{ yyval = newExpNode(OpK); yyval->attr.op = MINUS; }
#line 1556 "y.tab.c"
break;
case 55:
#line 209 "cminus.y"
	{ yyval = yystack.l_mark[-1];
                yyval->child[0] = yystack.l_mark[-2];
                yyval->child[1] = yystack.l_mark[0]; }
#line 1563 "y.tab.c"
break;
case 56:
#line 212 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1568 "y.tab.c"
break;
case 57:
#line 214 "cminus.y"
	{ yyval = newExpNode(OpK); yyval->attr.op = TIMES; }
#line 1573 "y.tab.c"
break;
case 58:
#line 215 "cminus.y"
	{ yyval = newExpNode(OpK); yyval->attr.op = OVER; }
#line 1578 "y.tab.c"
break;
case 59:
#line 217 "cminus.y"
	{ yyval = yystack.l_mark[-1]; }
#line 1583 "y.tab.c"
break;
case 60:
#line 218 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1588 "y.tab.c"
break;
case 61:
#line 219 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1593 "y.tab.c"
break;
case 62:
#line 220 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1598 "y.tab.c"
break;
case 63:
#line 221 "cminus.y"
	{ yyval = NULL; }
#line 1603 "y.tab.c"
break;
case 64:
#line 224 "cminus.y"
	{ yyval = newStmtNode(CallK);
                yyval->attr.name = yystack.l_mark[-2]->attr.name;
                yyval->lineno = yystack.l_mark[-2]->lineno; }
#line 1610 "y.tab.c"
break;
case 65:
#line 228 "cminus.y"
	{ yyval = newStmtNode(CallK);
                yyval->attr.name = yystack.l_mark[-3]->attr.name;
                yyval->lineno = yystack.l_mark[-3]->lineno;
                yyval->child[0] = yystack.l_mark[-1]; }
#line 1618 "y.tab.c"
break;
case 66:
#line 234 "cminus.y"
	{ YYSTYPE t = yystack.l_mark[-2];
                if (t != NULL){
                  while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = yystack.l_mark[0];
                  yyval = yystack.l_mark[-2];
                }
                else yyval = yystack.l_mark[0]; }
#line 1630 "y.tab.c"
break;
case 67:
#line 242 "cminus.y"
	{ yyval = yystack.l_mark[0]; }
#line 1635 "y.tab.c"
break;
case 68:
#line 245 "cminus.y"
	{ yyval = newExpNode(ConstK);
                yyval->attr.val = atoi(tokenString);
                yyval->type = Integer; }
#line 1642 "y.tab.c"
break;
case 69:
#line 250 "cminus.y"
	{ yyval = newExpNode(IdK);
                yyval->attr.name = copyString(tokenString); }
#line 1648 "y.tab.c"
break;
#line 1650 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
