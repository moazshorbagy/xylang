#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "SymTable.h"
#include "SymTree.h"

struct SymTable *symAllocate()
{
    struct SymTable *newSymTable = malloc(sizeof(struct SymTable));

    newSymTable->symTable = malloc(TABLE_SIZE * sizeof(struct Symbol *));
    for (int i = 0; i < TABLE_SIZE; i++)
        newSymTable->symTable[i] = NULL;

    newSymTable->parent = NULL;

    newSymTable->children = malloc(MAX_CHILDREN_IN_TABLE * sizeof(struct SymTable *));

    newSymTable->addChildIndex = 0;

    return newSymTable;
}

int _hash(char *label)
{
    int _hash = 39 * (int)label[0];
    for (int j = 1; j < strlen(label); j++)
    {
        _hash += (391 + j) * (int)label[j];
    }
    return _hash % TABLE_SIZE;
}

struct Symbol *symLookup(struct SymTable *table, char *label)
{
    int hashIndex = _hash(label);
    // Linear probing
    while (table->symTable[hashIndex] != NULL && strcmp(table->symTable[hashIndex]->label, label) == 0)
    {
        if (hashIndex == TABLE_SIZE - 1)
        {
            hashIndex = -1;
        }
        hashIndex++;
    }

    return table->symTable[hashIndex];
}

int symInsert(struct SymTable *table, char *label, char *type, union Value value)
{
    if (table->symbolsCount == TABLE_SIZE - 1)
        return -1;

    struct Symbol *symbol = malloc(sizeof(struct Symbol));
    symbol->label = label;
    symbol->type = type;
    if (strcmp(type, "int") != 0)
        symbol->symValue.intVal = value.intVal;
    else if (strcmp(type, "float") != 0)
        symbol->symValue.floatVal = value.floatVal;
    else if (strcmp(type, "bool") != 0)
        symbol->symValue.boolVal = value.boolVal;
    else if (strcmp(type, "string") != 0)
        symbol->symValue.strVal = value.strVal;

    int hashIndex = _hash(label);
    // Linear probing
    while (table->symTable[hashIndex] != NULL)
    {
        if (hashIndex == TABLE_SIZE - 1)
        {
            hashIndex = -1;
        }
        hashIndex++;
    }
    table->symTable[hashIndex] = symbol;

    return 1;
}

int symUpdate(struct SymTable *table, char *label, char *type, union Value value)
{
    struct Symbol *symbol = symLookup(table, label);
    if (symbol == NULL)
        return -1;

    symbol->type = type;
    if (strcmp(type, "int") != 0)
        symbol->symValue.intVal = value.intVal;
    else if (strcmp(type, "float") != 0)
        symbol->symValue.floatVal = value.floatVal;
    else if (strcmp(type, "bool") != 0)
        symbol->symValue.boolVal = value.boolVal;
    else if (strcmp(type, "string") != 0)
        symbol->symValue.strVal = value.strVal;

    return 1;
}
