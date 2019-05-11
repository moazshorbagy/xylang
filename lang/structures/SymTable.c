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

    struct SymTable *tempTable = table;
    int tempHashIndex = hashIndex;
    // searching in the specified symbol table and his ancestors
    while (true)
    {
        // linear probing
        while (tempTable->symTable[tempHashIndex] != NULL && strcmp(tempTable->symTable[tempHashIndex]->label, label) != 0)
        {
            if (tempHashIndex == TABLE_SIZE - 1)
            {
                tempHashIndex = -1;
            }
            tempHashIndex++;
        }

        // if (the symbol is found) OR (i've searched in the global table) then break
        if (tempTable->symTable[tempHashIndex] != NULL || tempTable->parent == NULL)
            break;

        tempTable = tempTable->parent;
        tempHashIndex = hashIndex;
    }

    return tempTable->symTable[tempHashIndex];
}

int symInsert(struct SymTable *table, char *label, Type type, conTypeEnum datatype)
{
    if (table->symbolsCount == TABLE_SIZE - 1)
        return -1;

    int hashIndex = _hash(label);
    // Linear probing
    while (table->symTable[hashIndex] != NULL)
    {
        // if a symbol with the same label already exists in the specified symTable give a semantic error
        if (strcmp(label, table->symTable[hashIndex]->label) == 0)
            return -1;

        if (hashIndex == TABLE_SIZE - 1)
        {
            hashIndex = -1;
        }
        hashIndex++;
    }

    // allocating the new symbol
    struct Symbol *symbol = malloc(sizeof(struct Symbol));
    symbol->label = label;
    symbol->type = type;
    symbol->datatype = datatype;
    symbol->args = NULL;
    symbol->isInitialized = false;
    symbol->isUsed = false;
    symbol->symValue = NULL;
    symbol->myTable = table;

    // adding the new symbol to the specified symTable
    table->symTable[hashIndex] = symbol;

    return 1;
}

int symUpdate(struct SymTable *table, char *label, bool isInitialized, bool isUsed, union Value *value)
{
    struct Symbol *symbol = symLookup(table, label);
    if (symbol == NULL)
        return -1;

    symbol->isInitialized = isInitialized | symbol->isInitialized;
    symbol->isUsed = isUsed | symbol->isUsed;
    if (value != NULL)
    {
        // used dynamic allocation to take control of the lifetime and be independent of input changes after the function call
        union Value *v = malloc(sizeof(union Value));
        *v = *value;
        symbol->symValue = v;
    }
    return 1;
}

void symTablePrint(struct SymTable *table)
{
    printf("printing table: %p\n", table);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table->symTable[i] != NULL)
        {
            printf("label: %s index: %d", table->symTable[i]->label, i);
            /*if (table->symTable[i]->isInitialized)
                switch (table->symTable[i]->datatype)
                {
                case typeint:
                    printf(" value: %d", table->symTable[i]->symValue->intVal);
                    break;

                case typefloat:
                    printf(" value: %f", table->symTable[i]->symValue->floatVal);
                    break;

                case typestring:
                    printf(" value: %s", table->symTable[i]->symValue->strVal);
                    break;

                case typebool:
                    printf(" value: %s", table->symTable[i]->symValue->boolVal ? "true" : "false");
                    break;

                default:
                    break;
                }*/
            printf("\n");
        }
    }
    printf("\n");
}
