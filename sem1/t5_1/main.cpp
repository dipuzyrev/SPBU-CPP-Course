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

compare(char *str1, char *str2, int length1, int length2)
{
    if (length1 != length2)
        return false;

    for (int i = 0; i < length1; i++)
        if (str1[i] != str2[i])
            return false;

    return true;
}

int const commandNum(char *commandTitle, int length)
{
    char command1[] = "exit";
    char command2[] = "add value to list";
    char command3[] = "remove value from list";
    char command4[] = "print list";

    int const length1 = 4;
    int const length2 = 17;
    int const length3 = 22;
    int const length4 = 10;

    if (compare(commandTitle, command1, length, length1))
        return 0;
    else if (compare(commandTitle, command2, length, length2))
        return 1;
    else if (compare(commandTitle, command3, length, length3))
        return 2;
    else if (compare(commandTitle, command4 ,length, length4))
        return 3;
    else
        return -1;
}

void performCommand(List *list, int commandNumber)
{

    if (commandNumber = commandNum("add value to list", 17))
    {
        int value = 0;
        cout << "Input value to add: ";
        cin >> value;
        int result = addValue(list, value);
        if (result == 0)
            cout << "Value (" << value << ") added" << endl;
        else if (result == errorNum("Value already exist", 19))
            cout << "Value (" << value << ") already exist" << endl;
    }
    else if (commandNumber = commandNum("remove value from list", 22))
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
    }
    else if (commandNumber = commandNum("print list", 10))
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

    while (command != commandNum("exit", 4))
    {
        performCommand(list, command);
        cout << endl;
        command = getCommand();
    }

    clearList(list);
    delete list;
    return 0;
}
