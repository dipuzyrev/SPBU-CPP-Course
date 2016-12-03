#include <fstream>
#include <iostream>
#include "Str.h"
#include "List.h"

using namespace std;

int trimWord(char *word, int size)
{
    int i = 0;

    while (word[i] != ' ' && word[i] != '!' && word[i] != '?' && word[i] != '.' && word[i] != ',' && word[i] != '-' && word[i] != '_' && word[i] != '\0')
        i++;

    word[i] = '\0';

    return i;
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

    int const size = 10000;
    float loadFactor = 0;
    float averageListLength = 0;
    int maxListLength = 0;
    List *maxList = createList();
    int total = 0;
    int countOfEmpty = size;

    List *hashTable[size];
    for (int i = 0; i < size; i++)
        hashTable[i] = createList();

    //cout << hashTable[0] << endl;


    ifstream fin("input.txt");

    char *word =  new char[1024];
    for (int i = 0; i < 1024; i++)
        word[i] = ' ';

    if (!fin.is_open())
    {
        cout << "Error (reading file)!\n";
        return 0;
    }

    while (!fin.eof())
    {
        fin >> word;
        int length = trimWord(word, size);
        Str *newWord = createStr(word, length);

        int hashCode = getHashCode(newWord, size);
        int result = addToHashTable(hashTable, newWord, hashCode, maxListLength, maxList);

        loadFactor = (result != 2) ? (loadFactor * size + 1) / size : loadFactor;

        int listCount = size - countOfEmpty;
        if (result == 0)
            averageListLength = (listCount * averageListLength + 1) / (listCount + 1);
        else if (result == 1)
            averageListLength = (listCount * averageListLength + 1) / listCount;

        total++;

        countOfEmpty -= (result == 0) ? 1 : 0;

        //cout << word << endl;
    }

    //output results
    cout << "Load Factor: " << loadFactor << endl;
    cout << "Average List Length: " << averageListLength << endl;
    cout << "Max List Length: " << maxListLength << endl;
    cout << "This words: ";
    printList(maxList);
    cout << endl << "Total Words Added: " << total << endl;
    cout << "Count of Empty Cells: " << countOfEmpty << endl << endl;

    fin.close();
    return 0;
}
