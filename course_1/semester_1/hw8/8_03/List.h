#pragma once

#include "CustomString.h"

struct List;

List* createList();
void deleteList(List *&l);

bool addValue(List *l, String *value);
int getListLength(List *l);
bool isEmpty(List *l);
void printList(List *l);
