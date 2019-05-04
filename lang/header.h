typedef enum { typeCon, typeId, typeOpr} nodeEnum;
typedef enum { typeint, typefloat, typestring,typebool} conTypeEnum;
/* constants */
typedef struct {
		
	conTypeEnum type;
	char* value;
} conNodeType;

/* identifiers*/
typedef struct {
	int i;  // id in symbol table
}idNodeType;

/* opertaor*/
typedef struct {
	int oper;
	int nops;
	struct nodeTypeTag **op;
} oprNodeType;

typedef struct nodeTypeTag{
	nodeEnum type;

	union {
		conNodeType con;
		idNodeType id;
		oprNodeType opr;
	};
}nodeType;
