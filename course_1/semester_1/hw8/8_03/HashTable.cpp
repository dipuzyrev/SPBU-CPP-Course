#include <iostream>
#include <fstream>

#include "HashTable.h"
#include "CustomString.h"
#include "List.h"

using namespace std;

struct HashTable
{
    List **cells;
    List *maxChain;
    int size;
    int emptyCellsCount;
    int addedWordsCount;
    int addedUniqueWordsCount;
    double loadFactor;
    double averageChainLength;
};

HashTable *createHashTable(int size)
{
    HashTable *table = new HashTable;
    table->size = size;

    table->cells = new List *[size];
    for (int i = 0; i < size; i++)
        table->cells[i] = nullptr;

    table->maxChain = nullptr;
    table->emptyCellsCount = size;
    table->addedWordsCount = 0;
    table->addedUniqueWordsCount = 0;
    table->loadFactor = 0;
    table->averageChainLength = 0;

    return table;
}

int getTableSize(HashTable *t)
{
    return t->size;
}

bool isEmpty(HashTable *t)
{
    return t->size == 0;
}

void deleteHashTable(HashTable *&t)
{
    if (isEmpty(t))
        return;

    int size = getTableSize(t);

    for (int i = 0; i < size; i++)
    {
        if (t->cells[i] != nullptr)
            deleteList(t->cells[i]);
    }

    delete[] t->cells;
    delete t;
    t = nullptr;
}

unsigned int getHash(char *word, int max, int wordLength)
{
    char *temp = new char[wordLength];

    for (int i = 0; i < wordLength; i++)
        temp[i] = word[i];

    unsigned int hash = 2139062143;
    for (int i = 0; i < wordLength; i++)
        hash = 37 * hash + temp[i];

    delete[] temp;
    return hash % max;
}

void addWord(String *word, HashTable *t)
{
    char *characters = getChars(word);
    int wordLength = length(word);
    int tableSize = getTableSize(t);
    int hash = getHash(characters, tableSize, wordLength);

    if (t->cells[hash] == nullptr)
    {
        List *cellWords = createList();
        addValue(cellWords, word);
        t->cells[hash] = cellWords;
        t->loadFactor = (t->loadFactor * tableSize + 1) / tableSize;

        int filledCellCount = tableSize - t->emptyCellsCount;
        t->averageChainLength = (t->averageChainLength * (filledCellCount) + 1) / (filledCellCount + 1);

        if (t->maxChain == nullptr)
            t->maxChain = t->cells[hash];

        t->emptyCellsCount--;
        t->addedUniqueWordsCount++;
    }
    else
    {
        bool result = addValue(t->cells[hash], word);

        if (result)
        {
            //added new word
            t->loadFactor = (t->loadFactor * tableSize + 1) / tableSize;

            int filledCellCount = tableSize - t->emptyCellsCount;
            t->averageChainLength = (t->averageChainLength * (filledCellCount) + 1) / filledCellCount;

            int maxLength = getListLength(t->maxChain);
            int thisLength = getListLength(t->cells[hash]);

            if (maxLength < thisLength)
                t->maxChain = t->cells[hash];

            t->addedWordsCount++;
            t->addedUniqueWordsCount++;
            return;
        }
    }

    t->addedWordsCount++;
    return;
}

bool isLetter(char s)
{
    int engBigFrom = (int) 'A';
    int engBigTo = (int) 'Z';
    int engSmallFrom = (int) 'a';
    int engSmallTo = (int) 'z';
    int rusBigFrom = (int) 'А';
    int rusBigTo = (int) 'Я';
    int rusSmallFrom = (int) 'а';
    int rusSmallTo = (int) 'я';
    int rusSpecBig = (int) 'Ё';
    int rusSpecSmall = (int) 'ё';

    return (((int) s >= engBigFrom && (int) s <= engBigTo) || ((int) s >= engSmallFrom && (int) s <= engSmallTo) ||
        ((int) s >= rusBigFrom && (int) s <= rusBigTo) || ((int) s >= rusSmallFrom && (int) s <= rusSmallTo) ||
        (int) s == rusSpecBig || (int) s == rusSpecSmall);
}

void trimWord(char *word, int maxSize)
{
    int size = 0;

    while(size < maxSize && word[size] != '\0')
        size++;

    int i = 0;
    while (i < size && !isLetter(word[i]))
        i++;

    int j = i;
    while (j < size && (isLetter(word[j]) || (word[j] == '-' && (j + 1) < size && isLetter(word[j+1]))))
    {
        word[j - i] = word[j];
        j++;
    }

    while (j < maxSize && word[j] != '\0')
    {
        word[j] = '\0';
        j++;
    }
}

void loadFile(const char *fileName, HashTable *t, const int bufferSize)
{
    ifstream fin(fileName);
    char buffer[bufferSize] = {'\0'};

    while (!fin.eof())
    {
        fin >> buffer;
        trimWord(buffer, bufferSize);
        String *newWord = createString(buffer);
        addWord(newWord, t);
    }

    fin.close();
}

List *getWords(int hash, HashTable *t)
{
    if (hash < 0 || hash >= getTableSize(t))
        return nullptr;

    return t->cells[hash];
}

double getLoadFactor(HashTable *t)
{
    return t->loadFactor;
}

double getAverageChainLength(HashTable *t)
{
    return t->averageChainLength;
}

List* getMaxChain(HashTable *t)
{
    return t->maxChain;
}

int getAddedWordsCount(HashTable *t)
{
    return t->addedWordsCount;
}

int getUniqueWordsCount(HashTable *t)
{
    return t->addedUniqueWordsCount;
}

int getfEmptyCellsCount(HashTable *t)
{
    return t->emptyCellsCount;
}
