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

    if (commandNumber == 1)
    {
        int value = 0;
        cout << "Input value to add: ";
        cin >> value;
        int result = addValue(list, value);
        if (result)
            cout << "Value (" << value << ") added" << endl;
        else
            cout << "Value (" << value << ") already exist" << endl;
    }
    else if (commandNumber == 2)
    {
        int value = 0;
        cout << "Input value to remove: ";
        cin >> value;
        int result = removeValue(list, value);
        if (result)
            cout << "Value (" << value << ") removed" << endl;
        else
            cout << "Value (" << value << ") not removed" << endl;
    }
    else if (commandNumber == 3)
        printList(list);
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
        command = getCommand();
    }

    clearList(list);
    delete list;
    return 0;
}
