#include <iostream>
#include "customString.h"

using namespace std;

int main()
{
    String *string1 = createString("String 1");
    cout << "Created $string1 : \"String 1\"" << endl;

    String *string2 = createString("String 2");
    cout << "Created $string2 : \"String 2\"" << endl << endl;

    String *clonedString = clone(string1);
    cout << "Created $clonedString (\"" << getChars(clonedString) << "\") as clone of $string1 (\"" << getChars(string1) << "\")" << endl << endl;

    concat(string2, string1);
    cout << "Concat $string1 (\"" << getChars(string1) << "\") to $string2. Result: \"" << getChars(string2) << "\"" << endl << endl;

    cout << "Checking for equality $string1 (\"" << getChars(string1) << "\") and $string2 (\"" << getChars(string2) << "\") : ";
    if (equals(string1, string2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    cout << "Checking for equality $clonedString (\"" << getChars(clonedString) << "\") and $string1 (\"" << getChars(string1) << "\") : ";
    if (equals(clonedString, string1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    cout << endl << "Length of $clonedSting (\"" << getChars(clonedString) << "\") : " << length(clonedString) << endl << endl;

    String *emptyString = createString();
    cout << "Created $emptyString of course empty." << endl;
    cout << "Checking if $emptyString is empty? : ";
    if (isEmpty(emptyString))
        cout << "EMPTY" << endl;
    else
        cout << "NOT EMPTY" << endl;

    cout << "Checking if $string1 (\"" << getChars(string1) << "\") is empty: ";
    if (isEmpty(string1))
        cout << "EMPTY" << endl;
    else
        cout << "NOT EMPTY" << endl;

    String *subString = substring(string2, 8, 8);
    cout << endl << "Created substring, based on $string2 (\"" << getChars(string2) << "\") from 9th character, length - 8: \"" << getChars(subString) << "\"" << endl << endl;

    remove(string1);
    remove(string2);
    remove(clonedString);
    remove(emptyString);
    remove(subString);

    return 0;
}
