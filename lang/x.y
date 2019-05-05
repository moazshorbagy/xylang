%{
#include "header.h"
#include "structures\struct_defs.h"
#include "structures\SymTable.h"
#include "structures\SymTable.c"
#include "structures\SymTree.h"
#include "structures\SymTree.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

int yyerror(char*);
extern int yylex(); 
//prototypes
nodeType *con(conTypeEnum type,union Value);
nodeType *id(char*  label, char* type, conTypeEnum dataType);
nodeType *getid(char* value);
nodeType *opr(int oper, int nops, ...);



struct SymTable* currentSymTable;
struct Tree* tree;
%}

// data types for attributes within grammar
%union {
    char* strVal;
    int intVal;
    bool boolVal;
    float floatVal;
    nodeType* nPtr;
	conTypeEnum conType;         
};

// %token for terminals


%token <intVal> INT_VAL
%token <floatVal> FLOAT_VAL
%token <strVal> STRING_VAL
%token <strVal> IDENTIFIER
%token <boolVal> BOOL_VAL
%token CONST  COND_EQ  COND_GREQ COND_LSEQ COND_NEQ WHILE IF ELSE DO FOR SWITCH CASE DEFAULT VOID RETURN FUNCTION MAIN 

%start  program
// Associativity rules
%nonassoc ELSE
%left '+' '-' '&' '|'
%left '*' '/' '<' '>' COND_EQ COND_GREQ COND_LSEQ COND_NEQ 
%left '~'

//%type

%type <nPtr>  expr cond assign stmtornull whilestmt stmts stmt dowhilestmt assigndec forloopcont forloopstmt ifcont matched decConstant withVal decVar
%type <conType> type
%token <conType> INT
%token <conType> FLOAT
%token <conType> STRING
%token <conType> BOOL
//INT FLOAT BOOL STRING
%%

program	: functions MAIN openbraces  stmts closebraces	{ printf("valid with functions\n");  }
		| MAIN openbraces  stmts closebraces 			{ printf("valid\n"); }
		;
	
stmts	: stmts stmt	{$$ = opr(';', 2, $1, $2);}	
		| stmt			{$$ = $1;}
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

decConstant :  CONST type IDENTIFIER '=' expr ';'		{ $$ = opr('=', 2, id($3, "const_var", $2), $5); }
			;

decVar	: type IDENTIFIER withVal						{ if($3==NULL){
																 id($2, "var", $1);
																}
															else{
																 $$ = opr('=', 2, id($2, "var", $1), $3); 
															}
														}
		;

withVal	: ';'				{$$ = NULL;}
		| '=' expr ';'		{$$ = $2;}
		;
		

assigndec	: IDENTIFIER '=' expr 				{ $$ = opr('=',2,getid($1),$3);}
	 		| type IDENTIFIER '=' expr			{ $$ = opr('=', 2, id($2, "var", $1), $4); }
			| IDENTIFIER '[' expr ']' '=' expr	
			;


	/* Assignments */
	
assign	: IDENTIFIER '=' expr					{ $$ = opr('=',2,getid($1),$3);}
		| IDENTIFIER '[' expr ']' '=' expr
		;


	/* Conditional if-else */

matched	: IF '(' cond ')' ifcont				{ $$ = opr(IF, 2,  $3, $5);}
		;
		
ifcont	: openbraces  stmtornull 									{ $$ = $2;}
		| openbraces  stmtornull  ELSE openbraces stmtornull		{ $$ = opr(ELSE, 2, $2, $5);}
		;
		
		
	/* Loops */

whilestmt	: WHILE '(' cond ')' openbraces stmtornull 				{ $$ = opr(WHILE, 2, $3, $6);}
			;

dowhilestmt	: DO openbraces  stmtornull WHILE '(' cond ')' ';'		{ $$ = opr(DO, 2, $3, $6);}
			;

forloopstmt	: FOR '(' assigndec ';' cond ';' forloopcont			{ $$ = opr(FOR, 3, $3, $5, $7);}
			;

forloopcont	: assign ')' openbraces  stmtornull						{ $$ = opr(';', 2, $4, $1);}
			|  ')' openbraces  stmtornull							{ $$ = $3;}
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

expr	: 	INT_VAL   			{union Value x; x.intVal=$1; $$=con(typeint,x);}
		| FLOAT_VAL				{union Value x; x.floatVal=$1; $$=con(typefloat,x);}
		| BOOL_VAL				{union Value x; x.boolVal=$1; $$=con(typebool,x);}
		| STRING_VAL			{union Value x; x.strVal=$1; $$=con(typestring,x);}
		|'~'expr				{$$ = opr('~', 1, $2);}
		| IDENTIFIER			{$$ = getid($1);}
		| IDENTIFIER '[' expr ']'{}
		| expr '+' expr	 		{$$ = opr('+', 2, $1, $3);}
		| expr '-' expr  		{$$ = opr('-', 2, $1, $3);}
		| expr '*' expr	 		{$$ = opr('*', 2, $1, $3);}
		| expr '/' expr			{$$ = opr('/', 2, $1, $3);}
		| expr '&' expr 		{$$ = opr('&', 2, $1, $3);}
		| expr '|' expr			{$$ = opr('|', 2, $1, $3);}
		| expr '<' expr			{$$ = opr('<', 2, $1, $3);}
		| expr COND_GREQ expr	{$$ = opr(COND_GREQ, 2, $1, $3);}
		| expr '>' expr			{$$ = opr('>', 2, $1, $3);}
		| expr COND_LSEQ expr	{$$ = opr(COND_LSEQ, 2, $1, $3);}
		| expr COND_EQ expr		{$$ = opr(COND_EQ, 2, $1, $3);}
		| expr COND_NEQ expr	{$$ = opr(COND_NEQ, 2, $1, $3);}
		| '(' expr ')'			{$$ = $2;}
		| funccall
		;

cond	: cond '&' cond 		{$$ = opr('&', 2, $1, $3);}
		| cond '|' cond			{$$ = opr('|', 2, $1, $3);}
		| cond '<' cond			{$$ = opr('<', 2, $1, $3);}
		| cond COND_GREQ cond	{$$ = opr(COND_GREQ, 2, $1, $3);}
		| cond '>' cond			{$$ = opr('>', 2, $1, $3);}
		| cond COND_LSEQ cond	{$$ = opr(COND_LSEQ, 2, $1, $3);}
		| cond COND_EQ cond		{$$ = opr(COND_EQ, 2, $1, $3);}
		| cond COND_NEQ cond	{$$ = opr(COND_NEQ, 2, $1, $3);}
		| '(' cond ')'			{$$=$2;}
		| IDENTIFIER			{$$ = getid($1);}
		| IDENTIFIER '[' expr ']'
		| BOOL_VAL				{union Value x; x.boolVal=$1; $$=con(typebool,x);}
		| INT_VAL				{union Value x; x.intVal=$1; $$=con(typeint,x);}
		| FLOAT_VAL				{union Value x; x.floatVal=$1; $$=con(typefloat,x);}
		;

	
stmtornull	: stmts closebraces	{$$ = $1;}
			| closebraces		{$$ = NULL;}
			;
			
stmtornull2 : ':' stmts			
			| ':'				
			;

	/* Types */
	
type	: INT		{ $$=$1;}		
		| FLOAT		{ $$=$1;}
		| BOOL		{ $$=$1;}
		| STRING	{ $$=$1;}
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

nodeType *con(conTypeEnum type, union Value value) {
     
	nodeType *p;     /* allocate node */

    if ((p = malloc(sizeof(nodeType))) == NULL)
         yyerror("out of memory");     

	/* copy information */
    p->type = typeCon;

	if(type==typeint){
		p->con.intVal = value.intVal;
	}else if( type == typefloat){
		p->con.floatVal = value.floatVal;
	}else if( type == typebool){
		p->con.boolVal = value.boolVal;
	}else{
		p->con.strVal = value.strVal;
	}
    
    p->con.type = type;

	
    return p; 
}

nodeType *id(char*  label, char* type, conTypeEnum dataType) {
    nodeType *p;     /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL){
         yyerror("out of memory");
	}
	 
	 
	union Value  x;
	x.intVal = 1;
	int flag = symInsert(currentSymTable, label, type, x);
	 
	p->type = typeId;
	p->id.label = label;
    p->id.symTablePtr = currentSymTable;
	
	
	 return p;
 } 

nodeType *getid(char* value) {
	
     nodeType *p;     /* allocate node */
     if ((p = malloc(sizeof(nodeType))) == NULL)
         yyerror("out of memory");
	//look up the symbol table to get values
	
     /* copy information */
     p->type = typeId;
	 p->id.label = value;
     p->id.symTablePtr = currentSymTable;
	 //todo above line

	 //TODO : scope check

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

	if(oper==WHILE){
		printf("\nWHILEEEEEEEEE\n %c \n %d\n", p->opr.op[0]->opr.oper, p->opr.op[1]->opr.op[1]->opr.op[1]->opr.op[1]->con.intVal);//p->opr.op[1]->opr.op[1]->opr.op[1]->con.intVal );
	}
	if(oper==DO){
		printf("\nDOOOOOO\n %d \n %d\n",  p->opr.op[0]->opr.op[1]->opr.op[1]->opr.op[1]->con.intVal, p->opr.op[1]->opr.op[1]->con.intVal);//p->opr.op[1]->opr.op[1]->opr.op[1]->con.intVal );
	}

	/*if(oper==FOR){
		printf("\nfor\n %c \n\n", p->opr.op[2]->opr.op[1]->opr.op[1]->opr.oper ); 
	}*/

	if(oper==IF){
		printf("\nIFFFFFFFFF\n %d\n\n" , p->opr.op[1]->opr.op[0]->opr.op[1]->con.intVal );
	}
	
	
	//TODO: Semantic checks

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
  tree = allocateSymTree();
  currentSymTable = startScope(tree);
  yyin=fopen(argv[1],"r");
  yyparse();

  symTablePrint( currentSymTable);
  return 0;
}
