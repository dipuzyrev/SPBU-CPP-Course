#include <iostream>
#include "Str.h"

using namespace std;

int main()
{
    Str *s1 = createStr("aaa", 3);
    Str *s2 = createStr("bbb", 3);

    concatStr(s1, s2);
    printStr(s1);
    cout << endl;

    Str *s1_clone = cloneStr(s1);
    if (compareStr(s1, s1_clone))
        printStr(s1_clone);
    cout << " - it is clone" << endl;

    cout << "Length: " << getStrLength(s1_clone) << endl;

    Str *sub_1 = subStr(s1, 2, 4);
    cout << "Substr from 3'th symbol to 5'th: ";
    printStr(sub_1);
    cout << endl << endl;

    clearStr(s1);
    clearStr(s2);
    clearStr(s1_clone);
    delete s1;
    delete s2;
    delete s1_clone;

    return 0;
}
