#include <stdio.h>
#include <stdlib.h>
#include "struct_defs.h"
#include "SymTable.h"
#include "SymTree.h"

int main(int argc, char const *argv[])
{
    struct Tree *T = allocateSymTree();
    struct SymTable *globalTable = startScope(T);
    struct SymTable *localTable1 = startScope(T);
    endScope(T);
    startScope(T);
    endScope(T);
    startScope(T);
    endScope(T);
    startScope(T);
    struct SymTable *globalAgain = endScope(T);
    struct SymTable *localTable5 = startScope(T);
    endScope(T);

    union Value v;
    v.intVal = 5;
    symInsert(T->currSymTable, "myVar", "int", v);

    struct Symbol *mySymbol = symLookup(T->currSymTable, "myVar");

    if (mySymbol)
        printf("Retrieved Symbol:\nlabel: %s\ntype: %s\nvalue: %d\n\n", mySymbol->label, mySymbol->type, (int)mySymbol->symValue.intVal);

    v.strVal = "Well, this is a string";
    symUpdate(T->currSymTable, "myVar", "string", v);

    if (mySymbol)
        printf("Retrieved Symbol:\nlabel: %s\ntype: %s\nvalue: %s\n\n", mySymbol->label, mySymbol->type, (char *)mySymbol->symValue.strVal);

    printf("Number of local scopes: %d\n", T->currSymTable->addChildIndex);
    for (int i = 0; i < T->currSymTable->addChildIndex; i++)
    {
        printf("%p\n", T->currSymTable->children[i]);
    }

    printf("Global Table: %p\n", globalTable);
    printf("Local 1 Table: %p\n", localTable1);
    printf("Should be Global: %p\n", globalAgain);
    printf("Local 5 Table: %p\n", localTable5);
    printf("Parent of Local 1 (should be Global): %p\n", localTable1->parent);
    printf("Parent of Local 5 (should be Global): %p\n", localTable5->parent);
    printf("Parent of global (should be nil): %p\n", globalTable->parent);

    int *p0;
    int *p1;
    int **p2p = malloc(sizeof(int *));
    p2p[0] = p0;
    p2p[1] = p1;
    return 0;
}
