#pragma once

struct CycleList;

CycleList *createList();

bool addValue(CycleList *l, int value);
bool clearList(CycleList *l);
bool removeCurrentPointerValue(CycleList *l);
void movePointer(CycleList *l, int m);
int getCurrentPointerValue(CycleList *l);
