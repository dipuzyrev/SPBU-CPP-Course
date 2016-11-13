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

//handleLine:
//returns: 0 - one-line comment, should print
//         1 - comment inside multiline comment or line, or it isn't comment
int handleLine(char line[], int length, bool &multOpened)
{
    if (!multOpened && line[0] == '/' && line[1] == '/')
        return 0;

    defineFinalMultState(line, 0, length, multOpened);
    return 1;
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
        //cout << line << " (length) " << length << endl;

        int result = handleLine(line, length, multilineCommentsOpened);
        if (result == 0)
            cout << line << endl;
    }

    fin.close();
    return 0;
}
