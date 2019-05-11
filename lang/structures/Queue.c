#include <stdlib.h>

#include "SymTree.h"
#include "SymTable.h"
#include "Queue.h"

// allocate a new linked list node.
struct QNode *createNode(struct SymTable *symTable)
{
    struct QNode *temp = (struct QNode *)malloc(sizeof(struct QNode));
    temp->key = symTable;
    temp->next = NULL;
    return temp;
}

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue *q, struct SymTable *symTable)
{
    struct QNode *temp = createNode(symTable);

    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

struct SymTable *dequeue(struct Queue *q)
{
    if (q->front == NULL)
        return NULL;

    struct QNode *tempNode = q->front;
    struct SymTable *tempSymTable = tempNode->key;
    q->front = q->front->next;

    free(tempNode);

    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;
    return tempSymTable;
}

bool queueIsEmpty(struct Queue *q)
{
    if(q->rear == NULL)
        return true;
    
    return false;
}