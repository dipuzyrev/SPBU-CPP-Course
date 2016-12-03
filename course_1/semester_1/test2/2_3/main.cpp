#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List *unsorted = createList();

    addValue(unsorted, 12);
    addValue(unsorted, 14);
    addValue(unsorted, 3);

    printList(unsorted);

    cout << endl << "Sorting..." << endl;

    sortList(unsorted);
    printList(unsorted);

    return 0;
}
