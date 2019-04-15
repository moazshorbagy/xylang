%{
#include <stdio.h>
#include <stdlib.h>
extern int yylex();
int yyerror(char *);
%}

// %token for terminals
%token INT FLOAT VAR

%%

lang: lang decl | decl			{ printf("lang reduction\n"); };
decl: type varlist ';'			{ printf("decl reduction\n"); };
type: INT | FLOAT				{ printf("type reduction\n"); };
varlist:
		VAR						{ printf("varlist reduction\n"); }
		| varlist ',' VAR		{ printf("varlist reduction\n"); };

%%

int yyerror(char *msg) {
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

extern FILE *yyin;

int main(int argc, char *argv[]) {
	yyin = fopen(argv[1], "r");
	yyparse();
	return 0;
}