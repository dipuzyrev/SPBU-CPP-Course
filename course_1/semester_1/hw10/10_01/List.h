#pragma once

struct List;

struct ReturnValue
{
    char character;
    int priority;
};

List *createList();
void deleteList(List *&l);

void addValue(List *l, char value);
ReturnValue *extractValue(List *l);
bool isEmpty(List *l);
