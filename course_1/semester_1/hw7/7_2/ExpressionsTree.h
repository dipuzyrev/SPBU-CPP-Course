#pragma once

struct ExpressionsTree;

ExpressionsTree *create();

void loadExpressionsFromFile(char const *fileName, ExpressionsTree *expressions);
double compute(ExpressionsTree *expressions);
void print(ExpressionsTree *t);

bool clear(ExpressionsTree *t);
