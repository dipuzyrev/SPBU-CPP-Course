#include <iostream>
#include <fstream>
#include "List.h"

using namespace std;

int defineLength(char word[], int maxLength)
{
    int i = 0;

    while (i < maxLength && word[i] != '\0')
        i++;

    return i;
}

void handleWord(char buffer[1024], List *letters)
{
    int length = defineLength(buffer, 1024);

    for (int i = 0; i < length; i++)
    {
        char s = buffer[i];

        if ((int) s >= (int) 'a' && (int) s <= (int) 'z')
            addValue(letters, s);
    }
}

int main()
{
    char const *inputFile = "input.txt";
    char const *outputFile = "output.txt";
    ifstream fin(inputFile);

    char buffer[1024] = {'\0'};
    List *letters = createList();

    while (!fin.eof())
    {
        fin >> buffer;
        handleWord(buffer, letters);
    }

    printList(letters, outputFile);
    clearList(letters);
    delete letters;

    fin.close();
    return 0;
}
