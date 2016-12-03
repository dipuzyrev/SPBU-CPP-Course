#pragma once

struct List;

List *createList();

void addValue(List *l, char character);

void printList(List *l, char const *fileName);
void deleteMax(List *l);

bool clearList(List *l);
