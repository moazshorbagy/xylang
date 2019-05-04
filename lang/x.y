%{
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int yyerror(char*);
extern int yylex(); 
//prototypes
nodeType *con(conTypeEnum type,char* value);
nodeType *id(char* value);
nodeType *getid(char* value);
nodeType *opr(int oper, int nops, ...);

%}

// data types for attributes within grammar
%union {
    char* strVal;
    int intVal;
    char* boolVal;
    float floatVal;
    nodeType* nPtr;         
};

// %token for terminals

%token <intVal> INT_VAL
%token <floatVal> FLOAT_VAL
%token <strVal> STRING_VAL
%token <strVal> IDENTIFIER
%token <boolVal> BOOL_VAL
%token INT FLOAT BOOL STRING CONST INT_VAL FLOAT_VAL COND_EQ  COND_GREQ COND_LSEQ COND_NEQ WHILE IF ELSE DO FOR SWITCH CASE DEFAULT VOID RETURN FUNCTION MAIN

%start  program
// Associativity rules
%nonassoc ELSE
%left '+' '-' '&' '|'
%left '*' '/' '<' '>' COND_EQ COND_GREQ COND_LSEQ COND_NEQ 
%left '~'

//%type

%type <nPtr> expr

%%

program	: functions MAIN openbraces  stmts closebraces	{ printf("valid with functions\n");  }
		| MAIN openbraces  stmts closebraces 			{ printf("valid\n"); }
		;
	
stmts	: stmts stmt		
		| stmt
		;

stmt	: decConstant { printf("decConst\n"); }
		| decVar { printf("decVar\n"); }
		| assign ';' { printf("assignment\n"); }
		| whilestmt { printf("while\n"); }
		| dowhilestmt { printf("do\n"); }
		| forloopstmt  { printf("for\n"); }
		| switchcase { printf("switch\n"); }
		| matched { printf("if\n"); }
		| decArr { printf("dec array\n"); }
		| return { printf("return\n"); }
		| funccall ';' { printf("func call\n"); }
		| openbraces stmtornull
		;
	

	/* Declarations */

decArr	: type '['expr']' IDENTIFIER withArr
		;
		
withArr	: ';'
		| '=' openbraces  multipleExpr closebraces ';'
		;

multipleExpr	: expr
				| multipleExpr ',' expr
				;

decConstant :  CONST type IDENTIFIER '=' expr ';'
			;

decVar	: type IDENTIFIER withVal
		;

withVal	: ';'
		| '=' expr ';'
		;
		

assigndec	: IDENTIFIER '=' expr 
	 		| type IDENTIFIER '=' expr
			| IDENTIFIER '[' expr ']' '=' expr
			;


	/* Assignments */
	
assign	: IDENTIFIER '=' expr
		| IDENTIFIER '[' expr ']' '=' expr
		;


	/* Conditional if-else */

matched	: IF '(' cond ')' ifcont
		;
		
ifcont	: openbraces  stmtornull 
		| openbraces  stmtornull  ELSE openbraces stmtornull
		;
		
		
	/* Loops */

whilestmt	: WHILE '(' cond ')' openbraces stmtornull { printf("while2\n"); }
			;

dowhilestmt	: DO openbraces  stmtornull WHILE '(' cond ')' ';'
			;

forloopstmt	: FOR '(' assigndec ';' cond ';' forloopcont
			;

forloopcont	: assign ')' openbraces  stmtornull
			|  ')' openbraces  stmtornull
			;


	/* Switch-case */

switchcase	: SWITCH '(' expr ')' openbraces  cases
			;

cases		: switching nodef | closebraces | DEFAULT ':' stmtornull
			;

nodef	: DEFAULT ':' stmtornull
		| closebraces
		;

switching	: switching CASE '(' expr ')' stmtornull2
			| CASE '(' expr ')' stmtornull2
			;


	/* Expressions */

expr	: 	INT_VAL   	{char buffer[30]; itoa($1, buffer, 10); $$=con(typefloat,buffer);}
		| FLOAT_VAL	{char buffer[30]; ftoa($1, buffer, 10); $$=con(typefloat,buffer);}
		| BOOL_VAL	{$$=con(typebool,$1);}
		| STRING_VAL	{$$=con(typestring,$1);}
		|'~'expr	{$$=opr('~', 1, $2);}
		| IDENTIFIER		
		| IDENTIFIER '[' expr ']'
		| expr '+' expr	 { printf("plus\n"); }
		| expr '-' expr  { printf("minus\n"); }
		| expr '*' expr	 { printf("8\n"); }
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
		| funccall
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
		| IDENTIFIER '[' expr ']'
		| BOOL_VAL
		| INT_VAL
		| FLOAT_VAL
		;

	
stmtornull	: stmts closebraces
			| closebraces
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
		
		
	/* Functions */
	
functions	: functions func	{printf("func");}
			| func		{printf("func");}
			;
	
func	: type FUNCTION IDENTIFIER '(' args ')' openbraces  stmts closebraces
		| VOID FUNCTION IDENTIFIER '(' args ')' openbraces  stmts closebraces
		| type FUNCTION IDENTIFIER '(' ')' openbraces  stmts closebraces
		| VOID FUNCTION IDENTIFIER '(' ')' openbraces  stmts closebraces
		;
		
args	: args ',' type argName
		| type argName
		;

argName	: IDENTIFIER 
		| IDENTIFIER '[' expr ']'
    	;
    	
params	: params ',' expr
		| expr
		;
    	
funccall	: IDENTIFIER '(' params ')'
			| IDENTIFIER '(' ')'
			;
    	
return	: RETURN expr ';'
		| RETURN ';'
;
      


/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

openbraces : '{'					  { printf("openbraces\n");} 
	;
closebraces : '}'					  { printf("closebraces\n");}
	; 

%%

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

#define SIZEOF_NODETYPE ((char *)&p->con - (char *)p) 

nodeType *con(conTypeEnum type,char* value) {
     nodeType *p;     /* allocate node */

     if ((p = malloc(sizeof(nodeType))) == NULL)
         yyerror("out of memory");     

	/* copy information */
     p->type = typeCon;
     p->con.value = value;
     p->con.type = type;
     return p; 
}

nodeType *id(char*  value) {
     nodeType *p;     /* allocate node */
     if ((p = malloc(sizeof(nodeType))) == NULL)
         yyerror("out of memory");
     /* copy information */
int i = 0; // TODO
     p->type = typeId;
     p->id.i = i;
     return p;
 } 
nodeType *getid(char* value) {
     nodeType *p;     /* allocate node */
     if ((p = malloc(sizeof(nodeType))) == NULL)
         yyerror("out of memory");
//look up the symbol table to get values
int i = 0; // TODO
     /* copy information */
     p->type = typeId;
     p->id.i = i;
     return p;
 } 
nodeType *opr(int oper, int nops, ...) {    
 	va_list ap;    
 	nodeType *p;   
  	int i;
     /* allocate node */
     if ((p = malloc(sizeof(nodeType))) == NULL)
         yyerror("out of memory");
     if ((p->opr.op = malloc(nops * sizeof(nodeType))) == NULL)
         yyerror("out of memory");
     /* copy information */
     p->type = typeOpr;
     p->opr.oper = oper;
     p->opr.nops = nops;
     va_start(ap, nops);
     for (i = 0; i < nops; i++)
         p->opr.op[i] = va_arg(ap, nodeType*);
     va_end(ap);
     return p;
 } 

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
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
