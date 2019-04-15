%{
#include "y.tab.h"
#include <stdlib.h>
void yyerror(char *);
%}

%%
    /* Data types */
"int" return INT;
"float" return FLOAT;

    /* Identifier */
[A-Za-z_][A-Za-z0-9_]*	return VAR;

    /* Language characters */
[,;]   return *yytext;

	/* Skip whitespaces */
[ \t\n]	;

	/* Skip comments */
("/*".*"*/")|("//".*)	;

    /*  Unmatched charachter */
.   yyerror("invalid character");

%%

int yywrap(void) {
    return 1;
}

