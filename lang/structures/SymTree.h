#ifndef SYM_TREE
#define SYM_TREE

#include "struct_defs.h"

struct Tree *allocateSymTree();

struct SymTable *startScope(struct Tree *);

struct SymTable *endScope(struct Tree *);

void printTree(struct Tree *);

int hitCount(struct Tree *T, char *label);

void checkUnusedVars(struct Tree *T);

#endif
