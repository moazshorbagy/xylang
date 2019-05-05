#ifndef MY_HEADER
#define MY_HEADER
#include <stdbool.h>
#include "structures\struct_defs.h"

typedef enum { typeCon, typeId, typeOpr} nodeEnum;
typedef enum { typeint, typefloat, typestring, typebool, typevoid} conTypeEnum;


/* constants */
typedef struct {		
	conTypeEnum type;

	union {
		char* strVal;
		int intVal;
		bool boolVal;
		float floatVal;
	};
} conNodeType;



/* identifiers*/
typedef struct {
	// Name of the id
	char* label;
	// Pointer to the symbol table where this identifier lies
	struct SymTable* symTablePtr;  
}idNodeType;



/* opertaor*/
typedef struct {
	int oper;
	int nops;
	struct nodeTypeTag **op;
} oprNodeType;



typedef struct nodeTypeTag{
	nodeEnum type;
	conTypeEnum retType;
	union {
		conNodeType con;
		idNodeType id;
		oprNodeType opr;
	};
}nodeType;

#endif
