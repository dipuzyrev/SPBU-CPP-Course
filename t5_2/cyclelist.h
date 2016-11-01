#pragma once

struct CycleList;

CycleList *createList();

//addValue:
//returns 0 - value added, 1 - value already in the list
int addValue(CycleList *l, int value);

//clearList:
//returns 0 - list saccessfully cleared, 1 - list empty
int clearList(CycleList *l);

//removeCurrentPointerValue:
//returns 0 - value removed, 1 - list empty
int removeCurrentPointerValue(CycleList *l);

void movePointer(CycleList *l, int m);
int getCurrentPointerValue(CycleList *l);
