/****************************************************/
/* File: tiny.y                                     */
/* The TINY Yacc/Bison specification file           */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"


#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void); // added 11/2/11 to ensure no conflict with lex
int yyerror(const char * message);
%}

%token IF ELSE RETURN WHILE
%token INT VOID NUM ID 
%token PLUS MINUS OVER TIMES LT LE GT GE EQ NE ASSIGN SEMI COMMA LPAREN RPAREN LBRACE RBRACE LCURLY RCURLY
%token ERROR
//%expect 1

%nonassoc XIF
%nonassoc ELSE

%locations
%debug


%% /* Grammar */

program     : stmt_seq
                 { savedTree = $1;} 
            ;
stmt_seq    : stmt_seq stmt
                 { YYSTYPE t = $1;
                   if (t != NULL)
                   { while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = $2;
                     $$ = $1; }
                     else $$ = $2;
                 }
            | stmt  { $$ = $1; }
            ;
stmt        : var_stmt { $$ = $1; }
            | fun_stmt { $$ = $1; }
            | error { $$ = NULL; }
            ;
var_stmt    : type_spec identifier SEMI
				      { $$ = newDeclNode(VarK);
                $$->type = $1->kind.type;
                $$->attr.name = $2->attr.name;
                $$->lineno = $2->lineno;
				      }
	    	    | type_spec identifier LBRACE number RBRACE SEMI
				      { $$ = newDeclNode(VarK);
                $$->type = $1->kind.type;
                $$->attr.name = $2->attr.name;
                $$->attr.val = $4->attr.val;
                $$->lineno = $2->lineno;
				      }
	    	    ;
type_spec   : INT { $$ = newTypeNode(Integer); }
            | VOID { $$ = newTypeNode(Void); }
            ;
fun_stmt    : type_spec identifier LPAREN params RPAREN comp_stmt
            { $$ = newDeclNode(FunK); 
              $$->type = $1->kind.type; 
              $$->attr.name = $2->attr.name;
              $$->child[0] = $4;
              $$->child[1] = $6;
              $$->lineno = $2->lineno; }
            ;
params      : param_list { $$ = $1; }
            | VOID { $$ = NULL; }
            | { $$ = NULL; }
            ;
param_list  : param_list COMMA param
				      { YYSTYPE t = $1;
                if (t != NULL){
                  while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = $3;
                  $$ = $1;
                }
                else $$ = $3;
				      }
	    	    | param { $$ = $1; }
	    	    ;
param	      : type_spec identifier
				      { $$ = newDeclNode(ParamK);
				        $$->type = $1->kind.type;
                $$->attr.name = $2->attr.name;
                $$->lineno = $2->lineno;
				      }
	    	    | type_spec identifier LBRACE RBRACE
				      { $$ = newDeclNode(ParamK);
				        $$->type = $1->kind.type;
                $$->attr.name = $2->attr.name;                
                $$->lineno = $2->lineno;
				      }
	    	    ;
comp_stmt   : LCURLY local_stmt stmt_list RCURLY
              { YYSTYPE t = $2;
                if (t != NULL){
                  while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = $3;
                  $$ = $2;
                }
                else $$ = $3; }
	    	    | LCURLY stmt_list RCURLY { $$ = $2; }
	    	    | LCURLY local_stmt RCURLY { $$ = $2; }
	    	    | LCURLY RCURLY { $$ = NULL; }
	    	    ;
local_stmt  : local_stmt var_stmt
              { YYSTYPE t = $1;
                if(t != NULL) {
                  while(t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = $2;
                  $$ = $1;
                }
                else $$ = $2; }
            | var_stmt { $$ = $1; }
            ;
stmt_list   : stmt_list statement
              { YYSTYPE t = $1;
                if(t != NULL){
                  while(t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = $2;
                  $$ = $1;
                }
                else $$ = $2; }
            | statement { $$ = $1; }
            ;
statement   : expr_stmt { $$ = $1; }
            | comp_stmt { $$ = $1; }
            | sel_stmt { $$ = $1; }
            | it_stmt { $$ = $1; }
            | ret_stmt { $$ = $1; }
            ;
expr_stmt   : expr SEMI { $$ = $1; }
            | SEMI { $$ = NULL; }
            ;
sel_stmt    : IF LPAREN expr RPAREN statement %prec XIF
              { $$ = newStmtNode(IfK);
                $$->child[0] = $3;
                $$->child[1] = $5; }
            | IF LPAREN expr RPAREN statement ELSE statement
              { $$ = newStmtNode(IfK);
                $$->child[0] = $3;
                $$->child[1] = $5;
                $$->child[2] = $7; }
            ;
it_stmt     : WHILE LPAREN expr RPAREN statement
              { $$ = newStmtNode(WhileK);
                $$->child[0] = $3;
                $$->child[1] = $5; }
            ;
ret_stmt    : RETURN SEMI { $$ = newStmtNode(ReturnK); }
            | RETURN expr SEMI
              { $$ = newStmtNode(ReturnK); 
                $$->child[0] = $2; }
            ;
expr        : var ASSIGN expr
              { $$ = newStmtNode(AssignK);
                $$->child[0] = $1;
                $$->child[1] = $3; }
            | simp_expr { $$ = $1; }
            ;
var         : identifier { $$ = $1; }
            | identifier LBRACE expr RBRACE
              { $$ = $1;
                $$->child[0] = $3; }
            ;
simp_expr   : sum_exp relat sum_exp
              { $$ = $2;
                $$->child[0] = $1;
                $$->child[1] = $3; }
            | sum_exp { $$ = $1; }
            ;
relat       : LT { $$ = newExpNode(OpK); $$->attr.op = LT; }
            | LE { $$ = newExpNode(OpK); $$->attr.op = LE; }
            | GT { $$ = newExpNode(OpK); $$->attr.op = GT; }
            | GE { $$ = newExpNode(OpK); $$->attr.op = GE; }
            | EQ { $$ = newExpNode(OpK); $$->attr.op = EQ; }
            | NE { $$ = newExpNode(OpK); $$->attr.op = NE; }
            ;
sum_exp     : sum_exp sum term
              { $$ = $2;
                $$->child[0] = $1;
                $$->child[1] = $3; }
            | term { $$ = $1; }
            ;
sum         : PLUS { $$ = newExpNode(OpK); $$->attr.op = PLUS; }
            | MINUS { $$ = newExpNode(OpK); $$->attr.op = MINUS; }
            ;
term        : term mult factor
              { $$ = $2;
                $$->child[0] = $1;
                $$->child[1] = $3; }
            | factor { $$ = $1; }
            ;
mult        : TIMES { $$ = newExpNode(OpK); $$->attr.op = TIMES; }
            | OVER { $$ = newExpNode(OpK); $$->attr.op = OVER; }
            ;
factor      : LPAREN expr RPAREN { $$ = $2; }
            | var { $$ = $1; }
            | activation { $$ = $1; }
            | number { $$ = $1; }
            | error { $$ = NULL; }
            ;
activation  : identifier LPAREN RPAREN
              { $$ = newStmtNode(CallK);
                $$->attr.name = $1->attr.name;
                $$->lineno = $1->lineno; }
            | identifier LPAREN args_seq RPAREN
              { $$ = newStmtNode(CallK);
                $$->attr.name = $1->attr.name;
                $$->lineno = $1->lineno;
                $$->child[0] = $3; }
            ;
args_seq    : args_seq COMMA expr
              { YYSTYPE t = $1;
                if (t != NULL){
                  while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = $3;
                  $$ = $1;
                }
                else $$ = $3; }
            | expr { $$ = $1; }
            ;
number      : NUM
              { $$ = newExpNode(ConstK);
                $$->attr.val = atoi(tokenString);
                $$->type = Integer; }
            ;
identifier  : ID
              { $$ = newExpNode(IdK);
                $$->attr.name = copyString(tokenString); }
            ;
%%

int yyerror(const char * message){
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}

