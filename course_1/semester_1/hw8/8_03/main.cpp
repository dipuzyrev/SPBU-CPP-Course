#include <iostream>

#include "HashTable.h"
#include "CustomString.h"
#include "List.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int const tableSize = 10000;
    int const bufferSize = 1024;
    char const *inputFile = "input.txt";

    HashTable *table = createHashTable(tableSize);
    loadFile(inputFile, table, bufferSize);;

    cout << "Table size: " << tableSize << endl;
    cout << "Load factor: " << getLoadFactor(table) << endl;
    cout << "Average chain length: " << getAverageChainLength(table) << endl;

    List *maxChain = getMaxChain(table);
    cout << "Max chain length: " << getListLength(maxChain) << endl;
    cout << "Values: ";
    printList(maxChain);

    cout << endl << "Words added: " << getAddedWordsCount(table) << endl;
    cout << "Unique: " << getUniqueWordsCount(table) << endl;
    cout << "Empty cells count: " << getfEmptyCellsCount(table) << endl << endl;

    deleteHashTable(table);
    return 0;
}
