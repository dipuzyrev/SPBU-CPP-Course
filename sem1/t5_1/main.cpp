#include <iostream>
#include "List.h"

using namespace std;

void printInstructions()
{
    cout << "0: exit" << endl;
    cout << "1: add a value to sorted list" << endl;
    cout << "2: remove a value from sorted list" << endl;
    cout << "3: print list" << endl;
}

void performCommand(List *list, int commandNumber)
{
    switch (commandNumber) {
    case 1:
    {
        int v = 0;
        cout << "Input value to add: ";
        cin >> v;
        int result = addValue(list, v);
        if (result == 0)
            cout << "Value (" << v << ") was added" << endl;
        else if (result == 1)
            cout << "Value (" << v << ") already exist" << endl;
        break;
    }
    case 2:
    {
        int v = 0;
        cout << "Input value to remove: ";
        cin >> v;
        int result = removeValue(list, v);
        if (result == 0)
            cout << "Value (" << v << ") was removed" << endl;
        else if (result == 1)
            cout << "Value (" << v << ") doesn't exist" << endl;
        else if (result == 2)
            cout << "List is empty" << endl;
        break;
    }
    case 3:
        printList(list);
    }
}

int getCommand()
{
    int command = 0;
    cout << endl << "Input your command: ";
    cin >> command;

    if (command > 3 || command < 0)
        return 0;
    else
        return command;
}

int main()
{
    List *list = createList();

    printInstructions();

    int command = getCommand();

    while (command != 0)
    {
        performCommand(list, command);
        cout << endl;
        command = getCommand();
    }

    clearList(list);
    delete list;
    return 0;
}
