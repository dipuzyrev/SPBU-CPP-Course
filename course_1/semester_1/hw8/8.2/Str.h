#pragma once

struct Str;

Str *createStr(char *str = nullptr, int lenght = 0);
Str *cloneStr(Str *strToClone);
void *concatStr(Str *baseStr, Str *strToConcat);
bool compareStr(Str *str1, Str *str2);
int getStrLength(Str *str);
bool isEmpty(Str *str);

//this func returns substr from [indexFrom] to [indexTo] with borders
//if [indexFrom] < 0 OR [indexFrom >= [indexTo] OR [indexFrom]/[indexTo] >= str length - func returns empty str
Str *subStr(Str *str, int indexFrom, int indexTo);

char *getCharacters(Str *str);
void clearStr(Str *str);
void printStr(Str *str);
