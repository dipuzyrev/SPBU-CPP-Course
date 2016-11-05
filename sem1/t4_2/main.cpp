#include <iostream>
#include <fstream>

using namespace std;

int getWordLength(char word[], int size)
{
    int i = 0;

    while (i < size && word[i] != '\0')
        i++;

    return i;
}

void clearWord(char word[], int &length)
{
    for (int i = 0; i < length; i++)
        word[i] = '\0';

    length = 0;
}

bool exist(char s, char newWord[], int newWordLength)
{
    for (int i = 0; i < newWordLength; i++)
        if (newWord[i] == s)
            return true;

    return false;
}

void markAsPrinted(char s, char newWord[], int &newWordLength)
{
    int i = 0;

    while (i < newWordLength)
        i++;

    newWord[i] = s;
    newWordLength++;
}

bool isLetter(char s)
{
    char notLetters[12] = {'.', '-', '!', '?', ',', '_', ':', '(', ')', '=', '<', '>'};

    if (exist(s, notLetters, 12))
        return false;
    else
        return true;
}

int main()
{
    ifstream fin("input.txt");

    if (fin.fail())
    {
        printf("File doesn't open! Please, title your file \"input.txt\" and try again.\n");
        return 0;
    }

    int const maxSize = 1024;
    char word[maxSize] = {'\0'};
    char newWord[maxSize] = {'\0'};
    int wordLength = 0;
    int newWordLength = 0;

    while (!fin.eof())
    {
        fin >> word;
        wordLength = getWordLength(word, maxSize);

        for (int i = 0; i < wordLength; i++)
        {
            if (!exist(word[i], newWord, newWordLength) && //if letter printed - we shouldn't print it
                !(!isLetter(word[i]) && (i == wordLength - 1 || i == 0) )) //if symbol isn't letter and it is first/last symbol - we shouldn't print it
            {
                cout << word[i];
                markAsPrinted(word[i], newWord, newWordLength);
            }
        }

        cout << endl;
        clearWord(word, wordLength);
        clearWord(newWord, newWordLength);
    }

    cout << endl << endl; //some formatting
    fin.close();
    return 0;
}
