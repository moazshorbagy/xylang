%{
#include "y.tab.h"
#include <stdlib.h>
void yyerror(char *);
%}

%%

	/* Constants */

[-]?[0-9]+\.[0-9]+ { return FLOAT_VAL; }
\".*\" { return STRING_VAL; }
[-]?[0-9]+	{ return INT_VAL; }


   /* Keywords */

"const" 	{ return CONST; }
"while" 	{ return WHILE; }
"if"		{ return IF; }
"else"		{ return ELSE; }
"do" 		{ return DO; }
"for" 		{ return FOR; }
"switch"	{ return SWITCH; }
"case" 		{ return CASE; }
"default" 	{ return DEFAULT; }


    /* Data types */

"int"		{ return INT; }
"float"		{ return FLOAT; }
"string"	{ return STRING; }
"bool" 		{ return BOOL; }


    /* Identifier */
    
[A-Za-z_][A-Za-z0-9_]*	{ return IDENTIFIER; }


    /* Language characters */
    
[-=+*/;&|<>(){}:,]	{ return *yytext; }
"<="				{ return COND_GREQ; }
">="				{ return COND_LSEQ; }
"=="				{ return COND_EQ; }
"!="				{ return COND_NEQ; }

	/* Skip whitespaces */

[ \t\n\r\v\f]+ ;

	/* Skip comments */

("/*"(.|\n|\t|\s)*"*/")|("//".*) ;

    /* Unmatched charachter */

.   yyerror("invalid character");

%%

int yywrap(void) {
    return 1;
}
