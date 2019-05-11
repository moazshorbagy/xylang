#include <stdio.h>
#include <stdlib.h>
#include "struct_defs.h"
#include "SymTable.h"
#include "SymTree.h"

int main(int argc, char const *argv[])
{
    struct Tree *T = allocateSymTree();
    startScope(T);

    union Value v;

    v.intVal = 5;
    symInsert(T->currSymTable, "var1", variable, typeint);
    struct Symbol *symbol = symLookup(T->currSymTable, "var1");
    symUpdate(T->currSymTable, "var1", true, true, &v);

    v.intVal = 20;
    symInsert(T->currSymTable, "var2", variable, typeint);
    symUpdate(T->currSymTable, "var2", true, true, &v);

    startScope(T);

    v.intVal = 80;
    symInsert(T->currSymTable, "var1", variable, typeint);
    symUpdate(T->currSymTable, "var1", true, true, &v);

    v.intVal = 320;
    symInsert(T->currSymTable, "var4", variable, typeint);
    symUpdate(T->currSymTable, "var4", true, true, &v);

    printTree(T);

    printf("Hit count: %d\n", hitCount(T, "var6"));

    int *p0;
    int *p1;
    int **p2p = malloc(sizeof(int *));
    p2p[0] = p0;
    p2p[1] = p1;
    return 0;
}
