#include <fstream>
#include <iostream>
#include "Str.h"
#include "List.h"

using namespace std;

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

int trimWord(char *word, int size)
{
    int i = 0;
    while (i < size && !isLetter(word[i]))
        i++;

    int j = i;
    while (j < size && (isLetter(word[j]) || (word[j] == '-' && (j + 1) < size && isLetter(word[j+1]))))
    {
        word[i - j] = word[j];
        j++;
    }

    word[j] = '\0';
    return j - i;
}

int getHashCode(Str *word, int size)
{
//    int length = getStrLength(word);
    char *str = getCharacters(word);

    unsigned int hash = 0;

    for(; *str; str++)
        hash = (hash * 1664525) + (unsigned char)(*str) + 1013904223;

    return hash % size;
}

//0 - new word with new list, 1 - new word in existing list, 2 - word is exist
int addToHashTable(List **hashTable, Str *word, int hashCode, int &maxListLength, List *maxList)
{

    List *thisHashList = hashTable[hashCode];

    if (isEmpty(hashTable[hashCode]))
    {
        hashTable[hashCode] = createList();
        add(hashTable[hashCode], word);

        if (!maxListLength)
        {
            maxListLength = 1;
            changeList(maxList, hashTable[hashCode]);
        }

        return 0;
    }

    int result = add(thisHashList, word);
    if (result == 1)
    {
        if (maxListLength < size(thisHashList))
        {
            maxListLength++;
            maxList = thisHashList;

            //cout << endl << "maxListLenght: " << maxListLength << endl;
            //cout << "This List size: " << size(thisHashList) << endl;
        }
        return 1;
    }
    else if (result == 2)
    {
        return 2;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int const tableSize = 10000;
    int const bufferSize = 1024;
    char const *inputFile = "input.txt";

    double loadFactor = 0;
    double averageListLength = 0;
    int maxListLength = 0;
    List *maxListValues = createList();
    int totalWordsCount = 0;
    int emptyCellsCount = tableSize;

    List *hashTable[tableSize];
    for (int i = 0; i < tableSize; i++)
        hashTable[i] = createList();

    ifstream fin(inputFile);

    char *buffer = new char[bufferSize];
    for (int i = 0; i < bufferSize; i++)
        buffer[i] = '\0';

    if (!fin.is_open())
    {
        cout << "Fail to open input file!\n";
        return 0;
    }

    while (!fin.eof())
    {
        fin >> buffer;
        int length = trimWord(buffer, bufferSize);
        Str *newWord = createStr(buffer, length);


//        int hashCode = getHashCode(newWord, bufferSize);
//        int result = addToHashTable(hashTable, newWord, hashCode, maxListLength, maxListValues);

//        loadFactor = (result != 2) ? (loadFactor * bufferSize + 1) / bufferSize : loadFactor;

//        int listCount = bufferSize - emptyCellsCount;
//        if (result == 0)
//            averageListLength = (listCount * averageListLength + 1) / (listCount + 1);
//        else if (result == 1)
//            averageListLength = (listCount * averageListLength + 1) / listCount;

//        totalWordsCount++;

//        emptyCellsCount -= (result == 0) ? 1 : 0;

        //cout << buffer << endl;
    }

    //output results
//    cout << "Load Factor: " << loadFactor << endl;
//    cout << "Average List Length: " << averageListLength << endl;
//    cout << "Max List Length: " << maxListLength << endl;
//    cout << "This words: ";
//    printList(maxListValues);
//    cout << endl << "Total Words Added: " << totalWordsCount << endl;
//    cout << "Count of Empty Cells: " << emptyCellsCount << endl << endl;

    fin.close();
    return 0;
}
