#pragma once

struct List;

List *createList();
char *createStr(int length);

//addValue:
//returns 0 - value added, 1 - value already in the list
int addValue(List *l, char *name, char *telephone);

char *findByName(List *l, char *name);
char *findByTelephone(List *l, char *telephone);

void loadDataFromFile(List *l);
void saveDataToFile(List *l);
