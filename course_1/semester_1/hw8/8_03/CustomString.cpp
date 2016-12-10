#include <cstring>
#include "CustomString.h"

struct String
{
    char *value;
    int length;
};

String *createString()
{
    String *newString = new String;
    newString->length = 0;
    newString->value = new char[1];
    newString->value[0] = '\0';
    return newString;
}

String *createString(const char *string)
{
    int length = strlen(string);

    String *newString = new String;
    newString->length = length;
    newString->value = new char[length + 1];

    strcpy(newString->value, string);

    return newString;
}

int length(String *string)
{
    return string->length;
}

bool isEmpty(String *string)
{
    return string->length == 0;
}

char *getChars(String *string)
{
    return string->value;
}

String *clone(String *stringToClone)
{
    String *cloned = createString(getChars(stringToClone));
    return cloned;
}

void concat(String *baseString, String *stringToConcat)
{
    int newLength = length(baseString) + length(stringToConcat);

    char *value = new char[newLength + 1];
    strcpy(value, baseString->value);
    strcat(value, stringToConcat->value);

    delete[] baseString->value;
    baseString->value = value;
    baseString->length = newLength;
}

bool equals(String *string1, String *string2)
{
    return strcmp(string1->value, string2->value) == 0;
}

String *substring(String *string, int indexFrom, int length)
{
    String *substring = new String;

    substring->value = new char[length + 1];
    substring->length = length;

    strncpy(substring->value, string->value + indexFrom, length);
    substring->value[length] = 0;

    return substring;
}

void deleteString(String *&string)
{
    delete[] string->value;
    delete string;
    string = nullptr;
}
