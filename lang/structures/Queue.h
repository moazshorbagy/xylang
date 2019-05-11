#ifndef QUEUE
#define QUEUE

#include "struct_defs.h"

// linked list node
struct QNode
{
    struct SymTable *key;
    struct QNode *next;
};

// queue
struct Queue
{
    struct QNode *front, *rear;
};

// create an empty queue
struct Queue *createQueue();

// add key to the queue
void enqueue(struct Queue *, struct SymTable *);

// remove key from queue
struct SymTable *dequeue(struct Queue *);

// checks if the queue is empty
bool queueIsEmpty(struct Queue *);

#endif