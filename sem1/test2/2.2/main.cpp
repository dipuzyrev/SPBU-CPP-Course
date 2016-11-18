#include <iostream>
#include <fstream>

using namespace std;

bool isDate(char *str)
{
    for (int i = 0; i < 10; i++)
    {
        if (i == 2 || i == 5)
        {
            if (str[i] != '.')
                return false;
        }
        else
        {
            if ((int) str[i] < (int) '0' || (int) str[i] > (int) '9')
                return false;
        }
    }

    return true;
}

bool isEarlier(char *date, char *dateToCompare)
{
    int y1 = 0;
    int y2 = 0;
    int m1 = 0;
    int m2 = 0;
    int d1 = 0;
    int d2 = 0;

    for (int i = 6; i < 10; i++)
    {
        y1 = y1 * 10 + ((int) date[i] - (int) '0');
        y2 = y2 * 10 + ((int) dateToCompare[i] - (int) '0');
    }

    for (int i = 3; i < 5; i++)
    {
        m1 = m1 * 10 + ((int) date[i] - (int) '0');
        m2 = m2 * 10 + ((int) dateToCompare[i] - (int) '0');
    }

    for (int i = 0; i < 2; i++)
    {
        d1 = d1 * 10 + ((int) date[i] - (int) '0');
        d2 = d2 * 10 + ((int) dateToCompare[i] - (int) '0');
    }

    if (y2 > y1)
        return true;
    else if (y2 == y1)
    {
        if (m2 > m1)
            return true;
        else if (m2 == m1)
        {
            if (d2 > d1)
                return true;
        }
    }

    return false;
}

void updateDate(char *dateToUpdate, char *value)
{
    for (int i = 0; i < 10; i++)
        dateToUpdate[i] = value[i];
}

int main()
{
    char const *fileName = "input.txt";
    ifstream fin(fileName);

    if (fin.fail())
    {
        cout << "Input file not exist!" << endl;
        return 0;
    }

    char buffer[1024] = {'\0'};
    char minDate[1024] = "99.99.9999";

    while (!fin.eof())
    {
        fin >> buffer;
        if (isDate(buffer))
        {
            if (isEarlier(buffer, minDate))
                updateDate(minDate, buffer);
        }
    }

    cout << "Minimal date: " << minDate << endl;

    fin.close();
    return 0;
}
