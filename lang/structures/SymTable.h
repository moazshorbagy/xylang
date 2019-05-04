#ifndef SYM_TABLE
#define SYM_TABLE

#include "struct_defs.h"

struct SymTable *symAllocate();

// searches for the label sent in the specified SymTable and his ancestors
struct Symbol *symLookup(struct SymTable *, char *);

// inserts a Symbol in the SymTable specified
int symInsert(struct SymTable *, char *, char *, union Value);

// finds the Symbol in the specified SymTable and his ancestors and updates its value
int symUpdate(struct SymTable *, char *, char *, union Value);

void symTablePrint(struct SymTable *);

#endif
