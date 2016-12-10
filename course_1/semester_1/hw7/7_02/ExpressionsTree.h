#pragma once

struct ExpressionsTree;

ExpressionsTree *create();

void loadExpressionsFromFile(char const *fileName, ExpressionsTree *expressions, const int bufferSize);
double compute(ExpressionsTree *expressions);
void print(ExpressionsTree *t);

void deleteTree(ExpressionsTree *&t);
