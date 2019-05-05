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
    symInsert(T->currSymTable, "var1", variable, typeint);
    symUpdate(T->currSymTable, "var1", true, true, &v);

    v.intVal = 20;
    symInsert(T->currSymTable, "var2", variable, typeint);
    symUpdate(T->currSymTable, "var2", true, true, &v);

    struct Symbol *sym1 = symLookup(T->currSymTable, "var1");
    if (sym1)
        printf("Retrieved Symbol:\nlabel: %s\nvalue: %d\n\n", sym1->label, (int)sym1->symValue->intVal);

    struct Symbol *sym2 = symLookup(T->currSymTable, "var2");
    if (sym2)
        printf("Retrieved Symbol:\nlabel: %s\nvalue: %d\n\n", sym2->label, (int)sym2->symValue->intVal);

    symTablePrint(T->currSymTable);

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
