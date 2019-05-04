#include <stdlib.h>
#include "SymTree.h"
#include "SymTable.h"

struct Tree *allocateSymTree()
{
    struct Tree *newTree = malloc(sizeof(struct Tree));
    newTree->root = NULL;
    newTree->currSymTable = NULL;
    return newTree;
}

struct SymTable *startScope(struct Tree *T)
{
    struct SymTable *newSymTable = symAllocate();
    newSymTable->parent = T->currSymTable;

    if (T->currSymTable)
    {
        T->currSymTable->children[T->currSymTable->addChildIndex++] = newSymTable;
    }
    else
    {
        T->root = newSymTable;
    }

    T->currSymTable = newSymTable;

    return newSymTable;
}

struct SymTable *endScope(struct Tree *T)
{
    if (T->currSymTable->parent)
        T->currSymTable = T->currSymTable->parent;
    return T->currSymTable;
}
