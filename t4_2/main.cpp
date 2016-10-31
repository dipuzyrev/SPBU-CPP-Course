#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void clearSymbols(char symbols[])
{
    int i = 0;
    while (symbols[i] != '\0')
    {
        symbols[i] = '\0';
        i++;
    }
}

bool isPrinted(char s, char symbols[], int length)
{
    int i = 0;
    while (symbols[i] != '\0' && i < length)
    {
        if (symbols[i] == s)
            return true;
        i++;
    }
    return false;
}


void printed(char s, char symbols[], int length)
{
    int i = 0;
    while (symbols[i] != '\0' && i < length)
        i++;
    if (i < length)
        symbols[i] = s;
}

int main()
{
    ifstream fin("input.txt");

    if (fin.fail())
    {
        printf("File doesn't open! Please, title your file \"input.txt\" and try again.\n");
        return 0;
    }

    char symbols[34] = {'\0'};
    char lastSymbol = '\0';

    const int length = 1024;
    char string[length] = {'\0'};

    while (fin.getline(string, length))
    {
        int strLength = strlen(string);
        for (int i = 0; i < strLength; i++)
        {
            if (string[i] == ' ')
            {
                clearSymbols(symbols);
                if (lastSymbol != '\0')
                    printf(" ");
            }
            else
            {
                if(!isPrinted(string[i], symbols, length))
                {
                    printf("%c", string[i]);
                    printed(string[i], symbols, length);
                }
            }
            lastSymbol = string[i];
        }
    }

    cout << endl << endl; //formatting output
    fin.close();
    return 0;
}
