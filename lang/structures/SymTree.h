#ifndef SYM_TREE
#define SYM_TREE

#include "struct_defs.h"

struct Tree *allocateSymTree();

struct SymTable *startScope(struct Tree *);

struct SymTable *endScope(struct Tree *);

#endif
