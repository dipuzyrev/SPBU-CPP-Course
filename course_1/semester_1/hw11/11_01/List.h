#pragma once

struct StatesList;

StatesList *createStatesList();
StatesList **createStatesTable(int size);
StatesList *getCopy(StatesList *l);
void deleteStatesList(StatesList *&l);

bool addState(int stateId, StatesList *l);
int extractState(StatesList *l);
bool isEmpty(StatesList *l);
