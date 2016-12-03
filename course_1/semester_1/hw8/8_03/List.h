#pragma once
#include "Str.h"

struct List;

List* createList();
int add(List *l, Str *value);
int size(List *l);
bool isEmpty(List *l);
void printList(List *l);
void changeList(List *listToChange, List *l);
