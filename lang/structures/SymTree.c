#include <stdlib.h>
#include <stdio.h>
#include "SymTree.h"
#include "SymTable.h"
#include "Queue.h"
#include "Queue.c"

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

void printTree(struct Tree *T)
{
    if (T->root->symTable == NULL)
        return;

    printf("{ \"tree\": [\n");

    struct Queue *q = createQueue();
    enqueue(q, T->root);

    struct SymTable *tempSymTable;
    bool j = false; // required to not print the first comma

    while (!queueIsEmpty(q))
    {
        tempSymTable = dequeue(q);

        if (tempSymTable->symbolsCount)
        {
            if (j)
                printf(",\n");
            else
                j = true;
            symTablePrint(tempSymTable);
        }

        for (int i = 0; i < tempSymTable->addChildIndex; i++)
        {
            enqueue(q, tempSymTable->children[i]);
        }
    }
    printf("]}\n");
}

int hitCount(struct Tree *T, char *label)
{
    if (T->root->symTable == NULL)
        return 0;

    struct Queue *q = createQueue();
    enqueue(q, T->root);

    int hitCount = 0;

    struct SymTable *tempSymTable;

    while (!queueIsEmpty(q))
    {
        tempSymTable = dequeue(q);

        if (symLookupCurrent(tempSymTable, label))
            hitCount++;

        for (int i = 0; i < tempSymTable->addChildIndex; i++)
        {
            enqueue(q, tempSymTable->children[i]);
        }
    }
    return hitCount;
}

void checkUnusedVars(struct Tree *T)
{
    if (T->root->symTable == NULL)
        return;

    struct Queue *q = createQueue();
    enqueue(q, T->root);

    struct SymTable *tempSymTable;

    while (!queueIsEmpty(q))
    {
        tempSymTable = dequeue(q);

        if (tempSymTable->symbolsCount)
        {
            genUnusedWarnings(tempSymTable);
        }

        for (int i = 0; i < tempSymTable->addChildIndex; i++)
        {
            enqueue(q, tempSymTable->children[i]);
        }
    }
}