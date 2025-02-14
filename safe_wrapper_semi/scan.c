#include "globals.h"
#include "util.h"
#include "scan.h"


/* states in scanner DFA */
typedef enum
   { START,INNUM,INID,INASSIGN,INLT,INGT,INNE,INOVER,INCOMMENT,INCOMMENT_,DONE }
   StateType;

/* lexeme of identifier or reserved word */
char tokenString[MAXTOKENLEN+1];

/* BUFLEN = length of the input buffer for
   source code lines */
#define BUFLEN 256

static char lineBuf[BUFLEN]; /* holds the current line */
static int linepos = 0; /* current position in LineBuf */
static int bufsize = 0; /* current size of buffer string */
static int EOF_flag = FALSE; /* corrects ungetNextChar behavior on EOF */

/* getNextChar fetches the next non-blank character
   from lineBuf, reading in a new line if lineBuf is
   exhausted */
static int getNextChar(void)
{ if (!(linepos < bufsize))
  { lineno++;
    if (fgets(lineBuf,BUFLEN-1,source))
    { if (EchoSource) fprintf(listing,"%4d: %s",lineno,lineBuf);
      bufsize = strlen(lineBuf);
      linepos = 0;
      return lineBuf[linepos++];
    }
    else
    { EOF_flag = TRUE;
      return EOF;
    }
  }
  else return lineBuf[linepos++];
}

/* ungetNextChar backtracks one character
   in lineBuf */
static void ungetNextChar(void)
{ if (!EOF_flag) linepos-- ;}

/* lookup table of reserved words */
static struct
    { char* str;
      TokenType tok;
    } reservedWords[MAXRESERVED]
   = {{"if",IF},{"else",ELSE},{"while",WHILE},
      {"return",RETURN},{"int",INT},{"void",VOID}};

/* lookup an identifier to see if it is a reserved word */
/* uses linear search */
static TokenType reservedLookup (char * s)
{ int i;
  for (i=0;i<MAXRESERVED;i++)
    if (!strcmp(s,reservedWords[i].str))
      return reservedWords[i].tok;
  return ID;
}

/****************************************/
/* the primary function of the scanner  */
/****************************************/
/* function getToken returns the 
 * next token in source file
 */
TokenType getToken(void)
{  /* index for storing into tokenString */
   int tokenStringIndex = 0;
   /* holds current token to be returned */
   TokenType currentToken;
   /* current state - always begins at START */
   StateType state = START;
   /* flag to indicate save to tokenString */
   int save;
   int c;
   while (state != DONE)
   { c = getNextChar();
     save = TRUE;
     switch (state)
     { case START://Start state
         if (isdigit(c)) state = INNUM;//Judge whether it is a number if it enters 
         else if (isalpha(c)) state = INID;//Judge whether it is a letter if it enters 
         else if (c == '=') state = INASSIGN;//If =, enter and continue to judge
         else if (c == '<') state = INLT;//If <, enter and continue to judge
         else if (c == '>') state = INGT;//If >, enter and continue to judge
         else if (c == '!') state = INNE;//If eqaul! Enter and continue to judge
         else if (c == '/'){ 
	   state = INOVER;
	   save = FALSE;
	 }
         else if ((c == ' ') || (c == '\t') || (c == '\n')) save = FALSE;
         else
         { state = DONE;//Indicates that the current state is DONE, and then continue to judge
           switch (c)
           { case EOF:
               save = FALSE;
               currentToken = ENDFILE;
               break;
             case '+': currentToken = PLUS;     break;
             case '-': currentToken = MINUS;    break;
             case '*': currentToken = TIMES;    break;
             case '(': currentToken = LPAREN;   break;
             case ')': currentToken = RPAREN;   break;
             case '{': currentToken = LCURLY;   break;
             case '}': currentToken = RCURLY;   break;
             case '[': currentToken = LBRACE;   break;
             case ']': currentToken = RBRACE;   break;
             case ';': currentToken = SEMI;     break;
             case ',': currentToken = COMMA;    break;
             default:  currentToken = ERROR;    break;
           }
         }
         break;
       case INNUM://The judgment ends until it is not a number and
         if (!isdigit(c))// state is set to DONE, currentToken is set to
         { /* backup in the input */
           ungetNextChar();
           save = FALSE;
           state = DONE;
           currentToken = NUM;
         }
         break;
       case INID:
         if (!(isalpha(c) || isdigit(c)))
         { /* backup in the input */
           ungetNextChar();
           save = FALSE;
           state = DONE;
           currentToken = ID;
         }
         break;
       case INASSIGN://Judge whether there is another = after =, if there is
         state = DONE;// = indicates EQ, otherwise ASSIGN
         if (c == '=')
           currentToken = EQ;
         else
         { /* backup in the input */
           ungetNextChar();
           save = FALSE;
           currentToken = ASSIGN;
         }
         break;
       case INLT: /* <, <= */ //Judge whether there is an = after <, if so, it means yes
        state = DONE;
        if (c == '=') {
          currentToken = LE;
        } else {
          /* backup in the input */
          ungetNextChar();
          save = FALSE;
          currentToken = LT;
        }
        break;
       case INGT: /* >, >= */ //Judge whether there is an = after >, if so, it means yes
        state = DONE;
        if (c == '=') {
          currentToken = GE;
        } else {
          /* backup in the input */
          ungetNextChar();
          save = FALSE;
          currentToken = GT;
        }
        break;
       case INNE: /* != */ //Judge whether there is an = after !, if so, it means
        state = DONE;
        if (c == '=') {
          currentToken = NE;
        } else {
          /* backup in the input */
          ungetNextChar();
          save = FALSE;
          currentToken = ERROR;
        }
        break;
       case INOVER:
        if (c == '*') {
          save = FALSE;
          state = INCOMMENT;
          tokenStringIndex = 0;
        } else {
          /* backup in the input */
          state = DONE;
          ungetNextChar();
          save = FALSE;
          currentToken = OVER;
        }
        break;
       case INCOMMENT:
         save = FALSE;
         if (c == EOF)
         { state = DONE;
           currentToken = ENDFILE;
         }
         else if (c == '*') state = INCOMMENT_;
         break;
       case INCOMMENT_:
        save = FALSE;
        if (c == EOF) {
          state = DONE;
          currentToken = ENDFILE;
        }
        else if (c == '/') {
          state = START;
        }
	else if (c == '*') {
	  state = INCOMMENT_;
	}
        else {
          state = INCOMMENT;
        }
        break;
       case DONE:
       default: /* should never happen */
         fprintf(listing,"Scanner Bug: state= %d\n",state);
         state = DONE;
         currentToken = ERROR;
         break;
     }
     if ((save) && (tokenStringIndex <= MAXTOKENLEN))
       tokenString[tokenStringIndex++] = (char) c;
     if (state == DONE)
     { tokenString[tokenStringIndex] = '\0';
       if (currentToken == ID)
         currentToken = reservedLookup(tokenString);
     }
   }
   if (TraceScan) {
     fprintf(listing,"\t%d: ",lineno);
     printToken(currentToken,tokenString);
     //if(currentToken == ERROR) fprintf(listing,"\t\t\tError pos -> ascii val of it -> '%d'\n", (int)c);
   }
   return currentToken;
} /* end getToken */
