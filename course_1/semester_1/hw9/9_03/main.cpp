#include <iostream>
#include <cstring>

using namespace std;

void inputString(char *string, const char *title)
{
    cout << "Input " << title << ": ";
    cin >> string;
}

bool equals(char *str1, char *str2, int length, int from1, int from2)
{
    for (int i = 0; i < length; i++)
        if (str1[from1 + i] != str2[from2 + i])
            return false;

    return true;
}

int pow(int number, int power)
{
    if (power == 0)
        return 1;

    int multiplicator = number;

    for (int i = 1; i < power; i++)
        number *= multiplicator;

    return number;
}

int main()
{
    const int strSize   = 1024;
    const int subSize   = 256;
    const int notation  = 13;
    const int mod       = 56918;

    char str[strSize] = {'\0'};
    char subStr[subSize] = {'\0'};

    inputString(str, "string");
    inputString(subStr, "substring");

    int strLength = strlen(str);
    int subLength = strlen(subStr);

    int strHash = 0;
    int subHash = 0;

    for (int i = 0; i < subLength; i++)
    {
        strHash = (notation * strHash + str[i]) % mod;
        subHash = (notation * subHash + subStr[i]) % mod;
    }

    int largestFactor = pow(notation, subLength - 1) % mod;

    cout << "Indexes:";

    for (int i = 0; i <= strLength - subLength; i++)
    {
        if (strHash == subHash)
            if (equals(str, subStr, subLength, i, 0))
                cout << " " << i;

        if (i < (strLength - subLength))
        {
            strHash = ((strHash - str[i] * largestFactor) * notation + str[i + subLength]) % mod;
            strHash = (strHash >= 0) ? strHash : strHash + mod;
        }
    }

    cout << ";" << endl << endl;
    return 0;
}
