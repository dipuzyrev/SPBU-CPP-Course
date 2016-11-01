#pragma once

struct List;

List *createList();

//addValue:
//returns 0 - value added, 1 - value alredy in the list
int addValue(List *l, int value);

//removeValue:
//returns 0 - value removed, 1 - value isn't in the list, 2 - list empty
int removeValue(List *l, int value);

void printList(List *l);

//clearList:
//returns 0 - list saccessfully cleared, 1 - list empty
int clearList(List *l);
