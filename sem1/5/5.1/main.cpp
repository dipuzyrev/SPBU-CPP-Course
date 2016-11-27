#include <iostream>
#include "List.h"

using namespace std;

enum Command
{
    exitCommand = 0,
    addCommand = 1,
    removeCommand = 2,
    printCommand = 3
};

void printInstructions()
{
    cout << "0: exit" << endl;
    cout << "1: add a value to sorted list" << endl;
    cout << "2: remove a value from sorted list" << endl;
    cout << "3: print list" << endl;
}

void performCommand(List *list, int command)
{

    if (command == addCommand)
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
    else if (command == removeCommand)
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
    else if (command == printCommand)
        printList(list);
}

int getCommand()
{
    int command = 0;
    cout << endl << "Input your command: ";
    cin >> command;

    if (command != exitCommand && command != addCommand && command != removeCommand && command != printCommand)
        return 0;
    else
        return command;
}

int main()
{
    List *list = createList();

    printInstructions();

    int command = getCommand();

    while (command != exitCommand)
    {
        performCommand(list, command);
        command = getCommand();
    }

    clearList(list);
    delete list;
    return 0;
}
