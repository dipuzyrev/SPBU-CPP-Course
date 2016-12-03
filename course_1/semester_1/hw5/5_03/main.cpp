#include <iostream>
#include <fstream>

using namespace std;

int getStrLength(char str[], int size)
{
    int i = 0;

    while (i < size && str[i] != '\0')
        i++;

    return i;
}


int defineMultilineCommentsCloseIndex(char line[], int length, int index, bool &multOpened)
{
    if (!multOpened)
        return index;

    int i = index;

    while (i < length + 1)
    {
        if (line[i] == '*' && line[i+1] == '/')
        {
            multOpened = false;
            return i + 2;
        }

        i++;
    }

    return -1;
}

int defineStringCloseIndex(char line[], int length, int index, bool &strOpened)
{
    if (!strOpened)
        return index;

    int i = index;

    while (i < length)
    {
        if (line[i] == '"')
        {
            strOpened = false;
            return i + 1;
        }

        i++;
    }

    return -1;
}

int handleLine(char line[], int length, int index, bool &multOpened, bool &strOpened)
{
    if (index < 0)
        return -1;

    if (multOpened)
    {
        int closeIndex = defineMultilineCommentsCloseIndex(line, length, index, multOpened);
        if (closeIndex >= 0)
            return handleLine(line, length, closeIndex + 1, multOpened, strOpened);
        else
            return -1;
    }

    if (strOpened)
    {
        int closeIndex = defineStringCloseIndex(line, length, index, strOpened);
        if (closeIndex >= 0)
            return handleLine(line, length, closeIndex + 1, multOpened, strOpened);
        else
            return -1;
    }

    int i = index;

    while (i < length - 1)
    {
        if (line[i] == '/' && line[i+1] == '*')
        {
            multOpened = true;
            return handleLine(line, length, i + 2, multOpened, strOpened);
        }

        if (line[i] == '"')
        {
            strOpened = true;
            return handleLine(line, length, i + 1, multOpened, strOpened);
        }

        if (line[i] == '/' && line[i+1] == '/')
            return i;

        i++;
    }

    return -1;
}

int main()
{
    ifstream fin("input.txt");

    int const maxSize = 2048;
    char line[maxSize] = {'\0'};

    bool multilineCommentsOpened = false;
    bool stringOpened = false;

    while(!fin.eof())
    {
        fin.getline(line, maxSize);
        int length = getStrLength(line, maxSize);

        int index = handleLine(line, length, 0, multilineCommentsOpened, stringOpened);
        if (index >= 0)
        {
            for (int i = index; i < length; i++)
                cout << line[i];
            cout << endl;
        }
    }

    fin.close();
    return 0;
}
