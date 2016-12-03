#pragma once

struct List;

List *createList();

bool isEmpty(List *l);
char *createStr(int length);
bool addValue(List *l, char *name, char *telephone);
char *findByName(List *l, char *name);
char *findByTelephone(List *l, char *telephone);
char *getHeadName(List *l);
char *getHeadTelephone(List *l);
void deleteHead(List *l);
void clearList(List *l);
