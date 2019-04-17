%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
int yyerror(char*);
extern int yylex(); 

//nodeType* opr(int oper, int nops, ...);
//nodeType* con(int, conType);

%}

// data types for attributes within grammar
%union {
	//nodeType* nodeTypeE;
    char* strVal;
    int intVal;
    //TODO
	char* boolVal;
    float floatVal;
    
}

// %token for terminals


%token <strVal> STRING_VAL
%token <strVal> IDENTIFIER
%token <boolVal> BOOL_VAL
%token INT FLOAT BOOL STRING  CONST INT_VAL FLOAT_VAL COND_EQ  COND_GREQ COND_LSEQ COND_NEQ WHILE IF ELSE DO FOR SWITCH CASE DEFAULT

%start  program
// Associativity rules
%nonassoc ELSE
%left '+' '-' '&' '|'
%left '*' '/' '<' '>' COND_EQ COND_GREQ COND_LSEQ COND_NEQ 

//%type <nodeType> decConst decVar identifying type value op id stmts stmt arithmExpr

%%

program	: stmts				{ printf("valid\n"); }
		;
	
stmts	: stmts stmt		
		| stmt
		| '{' stmtornull	
		;

stmt	: decConstant { printf("decConst\n"); }
		| decVar { printf("decVar\n"); }
		| assign ';' { printf("assignment\n"); }
		| whilestmt { printf("while\n"); }
		| dowhilestmt { printf("do\n"); }
		| forloopstmt  { printf("for\n"); }
		| switchcase { printf("switch\n"); }
		| matched { printf("if\n"); }
		;
	

	/* Declarations */
	
decConstant :  CONST type IDENTIFIER '=' expr ';'
			;

decVar	: type IDENTIFIER withVal
		;

withVal	: ';'
		| '=' expr ';'
		;
		
assigndec	: IDENTIFIER '=' expr 
	 		| type IDENTIFIER '=' expr
			;


	/* Assignments */
	
assign	: IDENTIFIER '=' expr
		;


	/* Conditional if-else */

matched	: IF '(' expr ')' ifcont
		;
		
ifcont	: '{' stmtornull 
		| '{' stmtornull  ELSE '{' stmtornull
		;
		
		
	/* Loops */

whilestmt	: WHILE '(' cond ')' '{' stmtornull
			;


dowhilestmt	: DO '{' stmtornull WHILE '(' cond ')' ';'
			;

forloopstmt	: FOR '(' assigndec ';' cond ';' forloopcont
			;

forloopcont	: assign ')' '{' stmtornull
			|  ')' '{' stmtornull
			;


	/* Switch-case */

switchcase	: SWITCH '(' expr ')' '{' cases
			;

cases		: switching nodef | '}' | DEFAULT ':' stmtornull
			;

nodef	: DEFAULT ':' stmtornull
		| '}'
		;

switching	: switching CASE '(' expr ')' stmtornull2
			| CASE '(' expr ')' stmtornull2
			;


	/* Expressions */

expr	: INT_VAL
		| FLOAT_VAL
		| BOOL_VAL
		| STRING_VAL
		| IDENTIFIER
		| expr '+' expr
		| expr '-' expr
		| expr '*' expr
		| expr '/' expr
		| expr '&' expr 
		| expr '|' expr
		| expr '<' expr
		| expr COND_GREQ expr
		| expr '>' expr
		| expr COND_LSEQ expr
		| expr COND_EQ expr
		| expr COND_NEQ expr
		| '(' expr ')'
		;

cond	: cond '&' cond 
		| cond '|' cond
		| cond '<' cond
		| cond COND_GREQ cond
		| cond '>' cond
		| cond COND_LSEQ cond
		| cond COND_EQ cond
		| cond COND_NEQ cond
		| '(' cond ')'
		| IDENTIFIER
		| BOOL_VAL
		| INT_VAL
		| FLOAT_VAL
		;

	
stmtornull	: stmts '}'
			| '}'
			;
			
stmtornull2 : ':' stmts
			| ':'
			;

	/* Types */
	
type	: INT 
		| FLOAT 
		| BOOL 
		| STRING
		;
      

%%

extern FILE *yyin;

int yyerror(char *msg) {
  fprintf(stderr,"%s\n",msg);
  exit(1);
}

int main(int argc, char * argv[]){
  yyin=fopen(argv[1],"r");
  yyparse();
  return 0;
}
