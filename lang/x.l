%{
#include "y.tab.h"
#include "header.h"
#include <stdlib.h>
void yyerror(char *);
%}

%%

	/* Constants */

[0-9]+\.[0-9]+ { yylval.floatVal = atof(yytext); return FLOAT_VAL; }
\".*\" { yylval.strVal = yytext; return STRING_VAL; }
[0-9]+	{ yylval.intVal = atoi(yytext); return INT_VAL; }
"true"|"false"	{yylval.strVal = yytext; return BOOL_VAL;}

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
"void"		{ return VOID; }
"return"	{ return RETURN; }
"function"	{ return FUNCTION; }
"main"		{ return MAIN; }


    /* Data types */

"int"		{ return INT; }
"float"		{ return FLOAT; }
"string"	{ return STRING; }
"bool" 		{ return BOOL; }


    /* Identifier */
    
[A-Za-z_][A-Za-z0-9_]*	{ return IDENTIFIER; }


    /* Language characters */
    
[-=+*/;&|<>(){}:,\[\]~]	{ return *yytext; }
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
