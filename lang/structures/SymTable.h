#ifndef SYM_TABLE
#define SYM_TABLE

#include "struct_defs.h"

struct SymTable *symAllocate();

// searches for the label sent in the specified SymTable and his ancestors
struct Symbol *symLookup(struct SymTable *, char *);

// inserts a Symbol in the SymTable specified
int symInsert(struct SymTable *, char *label, Type, conTypeEnum, struct Tree *);

// finds the Symbol in the specified SymTable and his ancestors and updates its value
int symUpdate(struct SymTable *, char *label, bool isInitialized, bool isUsed, union Value *);

void symTablePrint(struct SymTable *);

// searches for the label sent in the specified SymTable
struct Symbol *symLookupCurrent(struct SymTable *, char *label);

void genUnusedWarnings(struct SymTable *table);

#endif
