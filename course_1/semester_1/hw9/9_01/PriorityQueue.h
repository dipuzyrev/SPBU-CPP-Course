#pragma once

struct PriorityQueue;

struct QueueElement
{
    int key;
    int value;
};

PriorityQueue *createPriorityQueue();
void deletePriorityQueue(PriorityQueue *&q);

void insert(int key, int value, PriorityQueue *q);
QueueElement *extractMin(PriorityQueue *q);
bool isEmpty(PriorityQueue *q);
