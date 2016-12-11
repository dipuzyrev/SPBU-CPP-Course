#pragma once

struct String;

String *createString();
String *createString(const char *string);
String *createString(const int number);

String *clone(String *stringToClone);
void concat(String *baseString, String *stringToConcat);
bool equals(String *string1, String *string2);
int length(String *string);
bool isEmpty(String *string);
String *substring(String *string, int indexFrom, int length);
char *getChars(String *string);

void deleteString(String *&string);
