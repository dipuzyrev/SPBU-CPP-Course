#include <iostream>
#include <fstream>

using namespace std;

bool isEmpty(char *str, int maxSize)
{
    for (int i = 0; i < maxSize; i++)
    {
        char s = str[i];
        if (s != '\0' && s != '\t' && s != ' ')
            return false;
    }

    return true;
}

void cleanBuffer(char *buffer, int maxSize)
{
    for (int i = 0; i < maxSize; i++)
        buffer[i] = '\0';
}

int main()
{
    ifstream fin("input.txt");
    if (!fin.is_open())
    {
        cout << "File not exist!" << endl;
        return 0;
    }

    int const maxSize = 4096;
    char buffer[maxSize] = {'\0'};
    int countOfNotEmpty = 0;

    while(!fin.eof())
    {
        fin.getline(buffer, maxSize);

        if (!isEmpty(buffer, maxSize))
            countOfNotEmpty++;

        cleanBuffer(buffer, maxSize);
    }

    cout << "Count of not empty lines: " << countOfNotEmpty << endl;

    fin.close();
    return 0;
}
