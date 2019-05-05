#ifndef STRUCT_DEFS
#define STRUCT_DEFS
#include <stdbool.h>
#include "../header.h"

#define TABLE_SIZE 20            // number of symbols per symbol table
#define MAX_CHILDREN_IN_TABLE 20 // can be removed later

// Structures required for symbol table

typedef enum
{
    variable,
    constVariable,
    array,
    constArray,
    function,
    parameter
} Type;

union Value {
    int intVal;
    float floatVal;
    bool boolVal;
    char *strVal;
};

struct Symbol
{
    char *label;
    Type type;
    conTypeEnum datatype;
    union Value symValue;
    char **args; // datatypes for function arguments
    struct SymTable *myTable;
};

struct SymTable
{
    struct Symbol **symTable; // array of Symbol pointers
    int symbolsCount;         // current number of symbols stored in the table
    struct SymTable *parent;
    struct SymTable **children; // array of SymTable pointers
    int addChildIndex;          // index to add a child symbol table to the current symbol table
};

// Tree for hierarchy of symbol tables

struct Tree
{
    struct SymTable *root;
    struct SymTable *currSymTable;
};

#endif
