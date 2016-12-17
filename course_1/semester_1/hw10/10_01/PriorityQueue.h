#pragma once
#include "Tree.h"

struct PriorityQueue;

struct PriorityQueueReturn
{
    Tree *value;
    int key;
};

PriorityQueue *createPriorityQueue();
void deletePriorityQueue(PriorityQueue *&q);

void insert(Tree *value, int key, PriorityQueue *q);
PriorityQueueReturn *extractMin(PriorityQueue *q);
bool isEmpty(PriorityQueue *q);
