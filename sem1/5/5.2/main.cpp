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
    CycleList *list = createList();

    for (int i = 0; i < n; i++)
        addValue(list, i + 1);

    for (int i = 0; i < n - 1; i++)
    {
        movePointer(list, m - 1);
        removeCurrentPointerValue(list);
    }

    k = getCurrentPointerValue(list);

    cout << "Warrior on " << k << "-th position will live!" << endl << endl;

    return 0;
}
