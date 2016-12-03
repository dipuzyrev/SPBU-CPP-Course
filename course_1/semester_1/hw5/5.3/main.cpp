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

bool defineFinalMultState(char line[], int posFrom, int length, bool &multOpened)
{
    if (multOpened)
    {
        for (int i = posFrom + 1; i < length; i++)
            if (line[i - 1] == '*' && line[i] == '/')
            {
                multOpened = false;
                defineFinalMultState(line, i + 1, length, multOpened);
            }
    }
    else
    {
        for (int i = posFrom + 1; i < length; i++)
            if (line[i - 1] == '/' && line[i] == '*')
            {
                multOpened = true;
                defineFinalMultState(line, i + 1, length, multOpened);
            }
    }

    return multOpened;
}

bool handleLine(char line[], int length, bool &multOpened)
{
    if (!multOpened)
    	for (int i = 0; i < length - 1; i++)
    		if (line[i] == '/' && line[i + 1] == '/')
        		return true;

    defineFinalMultState(line, 0, length, multOpened);
    return false;
}

int main()
{
    ifstream fin("input.txt");

    int const maxSize = 2048;
    char line[maxSize] = {'\0'};

    bool multilineCommentsOpened = false;

    while(!fin.eof())
    {
        fin.getline(line, maxSize);
        int length = getStrLength(line, maxSize);

        int result = handleLine(line, length, multilineCommentsOpened);
        if (result)
            cout << line << endl;
    }

    fin.close();
    return 0;
}
