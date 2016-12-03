#pragma once

struct List;

List *createList();

void sortList(List *l);

bool addValue(List *l, int value);
bool removeValue(List *l, int value);
void printList(List *l);
bool clearList(List *l);
