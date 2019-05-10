%{
#include "header.h"
#include "structures\struct_defs.h"
#include "structures\SymTable.h"
#include "structures\SymTable.c"
#include "structures\SymTree.h"
#include "structures\SymTree.c"
#include "QuadGeneration.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>


int yyerror(char*);
extern int yylex(); 
//prototypes
nodeType *con(conTypeEnum type,union Value);
nodeType *id(char*  label, Type type, conTypeEnum dataType, bool setInitialized);
nodeType *getid(char* value);
nodeType *opr(int oper, int nops, ...);
void oprSemanticChecks( nodeType* p);
int ex(nodeType *p,int lbl1,int lbl2,FILE *fp,int start);
int start=0;
FILE *fp;
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
%token CASE_JOIN DEC

%start  program
// Associativity rules
%nonassoc ELSE
%left '+' '-' '&' '|'
%left '*' '/' '<' '>' COND_EQ COND_GREQ COND_LSEQ COND_NEQ 
%left '~'

//%type

%type <nPtr>  expr cond assign stmtornull whilestmt stmts stmt dowhilestmt assigndec forloopcont forloopstmt ifcont matched decConstant withVal decVar stmtornull2 switching cases switchcase
%type <conType> type
%token <conType> INT
%token <conType> FLOAT
%token <conType> STRING
%token <conType> BOOL
//INT FLOAT BOOL STRING
%%

program	: functions MAIN openbraces  stmts closebraces	{ printf("valid with functions\n");  }
		| MAIN openbraces  stmts closebraces 			{ /*printf("valid\n")*/; fp = fopen ("out.txt","w"); ex($3,0,0,fp,start);fclose (fp);}
		;
	
stmts	: stmts stmt	{$$ = opr(';', 2, $1, $2);}	
		| stmt			{$$ = $1;}
		;

stmt	: decConstant 				{ printf("decConst\n"); $$ = $1; }
		| decVar 					{ printf("decVar\n"); $$ = $1;}
		| assign ';' 				{ printf("assignment\n"); $$ = $1; }
		| whilestmt 				{ printf("while\n"); $$ = $1;}
		| dowhilestmt 				{ printf("do\n"); $$ = $1;}
		| forloopstmt  				{ printf("for\n"); $$ = $1;}
		| switchcase 				{ printf("switch\n"); $$ = $1;}
		| matched 					{ printf("if\n"); $$ = $1;}
		| decArr 					{ printf("dec array\n"); }
		| return 					{ printf("return\n"); }
		| funccall ';' 				{ printf("func call\n"); }
		| openbraces stmtornull		{$$ = $2;}
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

decConstant :  CONST type IDENTIFIER '=' expr ';'		{ 	id($3, constVariable, $2, true);
															$$ = opr(CONST, 2, getid($3, true, false), $5); }
			;

decVar	: type IDENTIFIER withVal						{ if($3==NULL)
															{
																
																id($2, variable, $1,false);
																$$=opr(DEC,1,getid($2, false, false));
																
															}
															else{
																id($2, variable,$1,true);
																$$=opr(DEC,2,getid($2, true, false),opr('=', 2, getid($2, true, false), $3));

															}
														}
		;

withVal	: ';'				{$$ = NULL;}
		| '=' expr ';'		{$$ = $2;}
		;
		

assigndec	: IDENTIFIER '=' expr 				{ $$ = opr('=',2,getid($1, true, false),$3);}
	 		| type IDENTIFIER '=' expr			{ $$ = opr('=', 2, id($2, variable, $1, true), $4); }
			| IDENTIFIER '[' expr ']' '=' expr	
			;


	/* Assignments */
	
assign	: IDENTIFIER '=' expr					{ $$ = opr('=',2,getid($1, true, false),$3);}
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

switchcase	: SWITCH '(' expr ')' openbraces  cases					{ $$ = opr(SWITCH, 2, $3, $6);}
			;

cases		: switching closebraces									{ $$ = $1;}
			;
/*			| closebraces 
			| DEFAULT ':' stmtornull
			;

nodef	: DEFAULT ':' stmtornull
		| closebraces
		;*/

switching	: switching CASE '(' expr ')' stmtornull2				{ $$ = opr(CASE_JOIN,2, $1, opr(CASE, 2, $4, $6));}
			| CASE '(' expr ')' stmtornull2							{ $$ = opr(CASE, 2, $3, $5);}
			;


	/* Expressions */

expr	: 	INT_VAL   			{union Value x; x.intVal=$1; $$=con(typeint,x);}
		| FLOAT_VAL				{union Value x; x.floatVal=$1; $$=con(typefloat,x);}
		| BOOL_VAL				{union Value x; x.boolVal=$1; $$=con(typebool,x);}
		| STRING_VAL			{union Value x; x.strVal=$1; $$=con(typestring,x);}
		|'~'expr				{$$ = opr('~', 1, $2);}
		| IDENTIFIER			{$$ = getid($1, false, true);}
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
		| IDENTIFIER			{$$ = getid($1, false, true);}
		| IDENTIFIER '[' expr ']'
		| BOOL_VAL				{union Value x; x.boolVal=$1; $$=con(typebool,x);}
		| INT_VAL				{union Value x; x.intVal=$1; $$=con(typeint,x);}
		| FLOAT_VAL				{union Value x; x.floatVal=$1; $$=con(typefloat,x);}
		;

	
stmtornull	: stmts closebraces	{$$ = $1;}
			| closebraces		{$$ = NULL;}
			;
			
stmtornull2 : ':' stmts			{$$ = $2;}
			| ':'				{$$ = NULL;}
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

openbraces : '{'					  { currentSymTable = startScope(tree);} 
	;
closebraces : '}'					  { currentSymTable = endScope(tree);}
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
	p->retType = type;
	
    return p; 
}

nodeType *id(char*  label, Type type, conTypeEnum dataType, bool setInitialized) {
    
	
	nodeType *p;     /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL){
         yyerror("out of memory");
	}
	 
	int flag = symInsert(currentSymTable, label, type, dataType);
	
	if(flag == -1){
		yyerror("\nRedeclaration\n");
	}

	p->type = typeId;
	p->id.label = label;
    p->id.symTablePtr = currentSymTable;
	
	p->retType = dataType;
	
	 return p;
 } 

nodeType *getid(char* value, bool setInitilized, bool setUsed) {
	
    nodeType *p;     /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
         yyerror("out of memory");

	// Update the variable with initializtaion/usage info
	symUpdate(currentSymTable, value, setInitilized, setUsed, NULL);
	
	// look up the symbol table to get values
	struct Symbol* sym= symLookup(currentSymTable, value);

	if(sym == NULL){
		yyerror("var not found");
	}else{
     /* copy information */
		p->type = typeId;
		p->id.label = value;
		p->id.symTablePtr = sym->myTable;
		p->retType = sym->datatype;
	}
	 
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
	
	oprSemanticChecks(p);

    return p;
 } 

void oprSemanticChecks( nodeType* p){

	// Check for usage of uninitialized variables
	// Check the first operand
	// Different from second operand that it may be initially uninitialized in an assignment or const declaration
	if(p->opr.op[0]->type == typeId && p->opr.oper != '=' && p->opr.oper != CONST && p->opr.oper != DEC && symLookup(currentSymTable, p->opr.op[0]->id.label)->isInitialized == false ){
		char message [20];
		sprintf	(message, "usage of uninitialized variable \"%s\"", p->opr.op[0]->id.label );
		yyerror(message);
	}
	
	
	if(p->opr.nops > 1 && p->opr.op[1]->type == typeId && symLookup(currentSymTable, p->opr.op[1]->id.label)->isInitialized == false ){
		char message [20];
		sprintf	(message, "usage of uninitialized variable \"%s\"", p->opr.op[1]->id.label );
		yyerror(message);
	}

	// Arithmetic check : types are same and are numbers //
	if(p->opr.oper == '+' || p->opr.oper == '-' || p->opr.oper == '*' || p->opr.oper == '/' ){
		
		// Check types are same
		if(p->opr.op[0]->retType == p->opr.op[1]->retType) {
			
			// Check type is integer or float
			if((p->opr.op[1]->retType == typeint || p->opr.op[1]->retType == typefloat)){
				p->retType = p->opr.op[0]->retType;
			}else{
				char message [50];
				sprintf	(message, "(%c) usage error :  unallowed types", p->opr.oper );
				yyerror(message);
			}
		}else{
			
			char message [50];
			sprintf	(message, "(%c) usage error :  type mismatch", p->opr.oper );
			yyerror(message);
			
		}
		
	}

	// Logical expressions //
	// Check for == or != 
	else if( p->opr.oper == COND_EQ || p->opr.oper == COND_NEQ){
		
		// Check type mismatch
		if(p->opr.op[0]->retType == p->opr.op[1]->retType){
			
			// Check types are bool, int or float
			if(p->opr.op[1]->retType == typeint || p->opr.op[1]->retType == typefloat || p->opr.op[1]->retType == typebool){
				p->retType = typebool;
			}else{
				char message [50];
				sprintf	(message, "(%s) usage error :  unallowed types", p->opr.oper == COND_EQ ? "==" : "!=" );
				yyerror(message);
			}
		} 	
		else{

			char message [50];
			sprintf	(message, "(%s) usage error : type mismatch", p->opr.oper == COND_EQ ? "==" : "!=" );
			yyerror(message);
		}
	}

	// Check for < <= > >=
	else if( p->opr.oper == '<' || p->opr.oper == '>' || p->opr.oper == COND_GREQ 
	|| p->opr.oper == COND_LSEQ ){
		// Check types equal
		if(p->opr.op[0]->retType == p->opr.op[1]->retType){

			// Check types are integer or float
			if(p->opr.op[1]->retType == typeint || p->opr.op[1]->retType == typefloat){
				p->retType = typebool;
			}else{
				char message [50];
				sprintf	(message, "(%s) usage error :  unallowed types", p->opr.oper == '<' ? "<" : (p->opr.oper=='>' ? ">" : (p->opr.oper == COND_GREQ ? ">=" : "<=" )));
				yyerror(message);
			}

		}else{
			char message [50];
			sprintf	(message, "(%s) usage error : type mismatch",  p->opr.oper == '<' ? "<" : (p->opr.oper=='>' ? ">" : (p->opr.oper == COND_GREQ ? ">=" : "<=" )));
			yyerror(message);
		}
	}

	// Check for & |
	else if( p->opr.oper == '|' || p->opr.oper == '&'){
		// Check types are equal
		if(p->opr.op[0]->retType == p->opr.op[1]->retType){
			// Check type is boolean
			if(p->opr.op[1]->retType == typebool){
				p->retType = typebool;
			}else{
				char message [50];
				sprintf	(message, "(%c) usage error :  unallowed types", p->opr.oper);
				yyerror(message);
			}
		}else{
			char message [50];
			sprintf	(message, "(%c) usage error : type mismatch", p->opr.oper);
			yyerror(message);
		}
	}

	// CHeck for ~
	else if (p->opr.oper == '~'){
		// Check type is integer or float
		if(p->opr.op[0]-> retType == typeint || p->opr.op[0]-> retType == typefloat){
			p->retType = p->opr.op[0]->retType;
		}else{
			char message [50];
			sprintf	(message, "(%c) usage error : unallowed type", p->opr.oper);
			yyerror(message);
		}
	}

	// Check for = (Assignment)
	else if (p->opr.oper == '='){	
		struct Symbol* symbol = symLookup(p->opr.op[0]->id.symTablePtr, p->opr.op[0]->id.label );
		// Check types are equal and LHS is variable
		if(p->opr.op[0]->retType == p->opr.op[1]->retType){
			if(symbol->type == variable){
				p->retType = p->opr.op[0]->retType;
			}else{
				char message [50];
				sprintf	(message, "(=) usage error : attempt to change constant \"%s\"", p->opr.op[0]->id.label);
				yyerror(message);
			}
		}else{
			yyerror("(=) usage error : type mismatch");
		}
	}

	// Check for constnt initialization
	else if( p->opr.oper == CONST){
		// Check types are equal
		if( (p->opr.op[0]->retType == p->opr.op[1]->retType)){
			p->retType = p->opr.op[0]->retType;
		}else{
			char message [50];
			sprintf	(message, "(=) usage error : type mismatch");
			yyerror(message);

		}
	}
	// Check CASE ==> return the type of the expr
	else if (p->opr.oper == CASE){
		p->retType = p->opr.op[0]->retType;
	}
	// Check for CASE_JOIN that expr types are the same
	else if(p->opr.oper == CASE_JOIN){
		// Check types are equal
		if( (p->opr.op[0]->retType == p->opr.op[1]->retType)){
			p->retType = p->opr.op[0]->retType;
		}else{
			yyerror("\ncases types not equal");
		}
	}
	// Check for SWITCH : expr type is same as inner expressions
	else if(p->opr.oper == SWITCH){
		if(p->opr.op[0]->retType == p->opr.op[1]->retType){
			p->retType = typevoid;
		}else{
			yyerror("\nswitch and cases types not equal");
		}
	}	
	else{
		p->retType = typevoid;
	}

}


/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
extern FILE *yyin;



int main(int argc, char * argv[]){
  tree = allocateSymTree();
  currentSymTable = startScope(tree);
  
  yyin=fopen(argv[1],"r");
  yyparse();

  symTablePrint( currentSymTable);
  return 0;
}
