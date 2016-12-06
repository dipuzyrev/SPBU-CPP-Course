#pragma once

#include "CustomString.h"
#include "List.h"

struct HashTable;

HashTable *createHashTable(int size);
void deleteHashTable(HashTable *&t);
void loadFile(const char *fileName, HashTable *t, const int bufferSize);

void addWord(String *word, HashTable *t);
List *getWords(int hash, HashTable *t);
double getLoadFactor(HashTable *t);
double getAverageChainLength(HashTable *t);
List* getMaxChain(HashTable *t);
int getAddedWordsCount(HashTable *t);
int getUniqueWordsCount(HashTable *t);
int getfEmptyCellsCount(HashTable *t);
