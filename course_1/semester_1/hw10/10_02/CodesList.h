#pragma once
#include "CustomString.h"

struct CodesList;

CodesList *createCodesList();
void deleteCodesList(CodesList *&table);

void addToCodesList(char value, String *code, CodesList *list);
String *getCode(char value, CodesList *list);
char getValue(String *code, CodesList *list);
