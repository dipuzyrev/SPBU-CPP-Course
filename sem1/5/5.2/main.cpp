#include <iostream>
#include "cyclelist.h"

using namespace std;

int main()
{
    int n = 0;
    int m = 0;
    cout << "Input n - number of warriors: ";
    cin >> n;
    cout << "Input m - m-th warrior will die: ";
    cin >> m;

    int k = 0;
    CycleList *warriors = createList();

    for (int i = 0; i < n; i++)
        addValue(warriors, i + 1);

    for (int i = 0; i < n - 1; i++)
    {
        movePointer(warriors, m - 1);
        removeCurrentPointerValue(warriors);
    }

    k = getCurrentPointerValue(warriors);

    cout << "Warrior on " << k << "-th position will live!" << endl << endl;

    clearList(warriors);
    delete warriors;

    return 0;
}
