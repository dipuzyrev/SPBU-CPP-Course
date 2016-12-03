#include <iostream>
using namespace std;

struct Str
{
    char *value;
    int length;
};

char *newStr(int length)
{
    if (!length)
        return nullptr;

    char *s = new char[length];

    for (int i = 0; i < length; i++)
        s[i] = '\0';

    return s;
}

Str *createStr(char *str = nullptr, int length = 0)
{
    char *s = newStr(length);

    for (int i = 0; i < length; i++)
        s[i] = str[i];

    Str *newStr = new Str;
    newStr->length = length;
    newStr->value = s;
    return newStr;
}

int getStrLength(Str *str)
{
    return str->length;
}

bool isEmpty(Str *str)
{
    return str->length == 0;
}

char *getCharacters(Str *str)
{
    int length = getStrLength(str);

    char *characters = new char[length];

    for (int i = 0; i < length; i++)
        characters[i] = '\0';

    if (!length)
        return characters;

    char temp = 0;

    while (temp < length)
    {
        characters[temp] = str->value[temp];
        temp++;
    }

    return characters;
}

Str *cloneStr(Str *strToClone)
{
    char *characters = getCharacters(strToClone);
    Str *clonedStr = createStr(characters, getStrLength(strToClone));
    return clonedStr;
}

void concatStr(Str *baseStr, Str *strToConcat)
{
    char *value1 = getCharacters(baseStr);
    char *value2 = getCharacters(strToConcat);
    int length1 = getStrLength(baseStr);
    int length2 = getStrLength(strToConcat);
    int newLength = length1 + length2;

    char *newString = newStr(newLength);

    for (int i = 0; i < length1; i++)
        newString[i] = value1[i];

    for (int i = 0; i < length2; i++)
        newString[i + length1] = value2[i];

    delete baseStr->value;
    baseStr->value = newString;
    baseStr->length = newLength;
}

bool compareStr(Str *str1, Str *str2)
{
    int length1 = getStrLength(str1);
    int length2 = getStrLength(str2);

    if (length1 != length2)
        return false;

    char *value1 = getCharacters(str1);
    char *value2 = getCharacters(str2);

    for (int i = 0; i < length1; i++)
        if (value1[i] != value2[i])
            return false;

    return true;
}

Str *subStr(Str *str, int indexFrom, int indexTo)
{
    Str *substr = createStr();
    int length = getStrLength(str);

    if (indexFrom >= length || indexTo >= length || indexFrom >= indexTo || indexFrom < 0)
        return substr;

    int temp = indexFrom;
    char *characters = getCharacters(str);
    char *newString = newStr(indexTo - indexFrom + 1);

    while (temp <= indexTo)
    {
        newString[temp - indexFrom] = characters[temp];
        temp++;
    }

    substr->length = indexTo - indexFrom + 1;
    substr->value = newString;
    return substr;
}

void clearStr(Str *str)
{
    delete str->value;
    str->value = nullptr;
    str->length = 0;
}

void printStr(Str *str)
{
    if(isEmpty(str))
        return;

    char *characters = getCharacters(str);
    int length = getStrLength(str);

    for (int i = 0; i < length; i++)
        cout << characters[i];
}
