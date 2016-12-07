#pragma once
#include "Map.h"

struct PriorityQueue;

PriorityQueue *createPriorityQueue();
void deletePriorityQueue(PriorityQueue *&q);

void insert(MapElement *value, PriorityQueue *q);
MapElement *extractMin(PriorityQueue *q);
bool isEmpty(PriorityQueue *q);
