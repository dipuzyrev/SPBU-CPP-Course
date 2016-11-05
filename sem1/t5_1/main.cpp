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
        int value = 0;
        cout << "Input value to add: ";
        cin >> value;
        int result = addValue(list, value);
        if (result == 0)
            cout << "Value (" << value << ") added" << endl;
        else if (result == errorNum("Value already exist", 19))
            cout << "Value (" << value << ") already exist" << endl;
        break;
    }
    case 2:
    {
        int value = 0;
        cout << "Input value to remove: ";
        cin >> value;
        int result = removeValue(list, value);
        if (result == 0)
            cout << "Value (" << value << ") was removed" << endl;
        else if (result == errorNum("Value doesn't exist", 19))
            cout << "Value (" << value << ") doesn't exist" << endl;
        else if (result == errorNum("List empty", 10))
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
