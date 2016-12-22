#include <iostream>

#include "BinaryTree.h"
#include "commandNumbers.h"

using namespace std;

void performAutomaticTest()
{
    BinaryTree *bsw = create();

    cout << "[start automatic test]" << endl << endl;

    cout << "Add values 1,2,3,4,5,6,7,8,9." << endl;

    addValue(1, bsw);
    addValue(2, bsw);
    addValue(3, bsw);
    addValue(4, bsw);
    addValue(5, bsw);
    addValue(5, bsw);
    addValue(6, bsw);
    addValue(7, bsw);
    addValue(8, bsw);
    addValue(9, bsw);

    cout << endl << "Print: " << endl;
    print(1, bsw);
    cout << endl;
    print(2, bsw);
    cout << endl;
    print(3, bsw);
    cout << endl;

    cout << endl << "Delete value (4) and print: ";
    deleteValue(4, bsw);
    print(1, bsw);
    cout << endl;
    print(2, bsw);
    cout << endl;
    print(3, bsw);
    cout << endl;

    cout << endl << "Delete value (6) and print: ";
    deleteValue(6, bsw);
    print(1, bsw);
    cout << endl;
    print(2, bsw);
    cout << endl;
    print(3, bsw);
    cout << endl;

    cout << endl << "Delete value (1) and print: ";
    deleteValue(1, bsw);
    print(1, bsw);
    cout << endl;
    print(2, bsw);
    cout << endl;
    print(3, bsw);
    cout << endl;

    cout << endl << "Is value (1) contains in tree? ";
    if (contains(1, bsw))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    cout << endl << "Is value (2) contains in tree? ";
    if (contains(2, bsw))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    cout << "[end of automatic test]" << endl;

    deleteTree(bsw);
}

void printInstructions()
{
    cout << exitCommand << ": exit" << endl;
    cout << addValueCommand << ": add a value to binary tree" << endl;
    cout << removeValueCommand << ": remove value from binary tree" << endl;
    cout << checkValueCommand << ": check if value contains in tree" << endl;
    cout << printInAscendingCommand << ": print in ascending" << endl;
    cout << printInDescendingCommand << ": print in descending" << endl;
    cout << printStructureCommand << ": print structure" << endl;
}

void performCommand(BinaryTree *bsw, int commandNumber)
{
    switch (commandNumber)
    {
        case addValueCommand:
        {
            int value = 0;
            cout << "Input value to add: ";
            cin >> value;
            addValue(value, bsw);
            break;
        }
        case removeValueCommand:
        {
            int value = 0;
            cout << "Input value to remove: ";
            cin >> value;
            deleteValue(value, bsw);
            break;
        }
        case checkValueCommand:
        {
            int value = 0;
            cout << "Input value to check: ";
            cin >> value;
            bool result = contains(value, bsw);
            if (result)
                cout << "Value (" << value << ") contains in tree" << endl;
            else
                cout << "Value (" << value << ") not found" << endl;
            break;
        }
        default:
        {
            print(commandNumber, bsw);
            cout << endl;
        }
    }
}

int getCommand()
{
    int command = 0;
    cout << endl << "Input your command: ";
    cin >> command;

    if (command != exitCommand && command != addValueCommand && command != removeValueCommand &&
        command != checkValueCommand && command != printInAscendingCommand && command != printInDescendingCommand &&
        command != printStructureCommand)
        return -1;
    else
        return command;
}

int main()
{
    //performAutomaticTest();

    BinaryTree *bsw = create();

    printInstructions();
    int command = getCommand();

    while (command != exitCommand)
    {
        performCommand(bsw, command);
        command = getCommand();
    }

    deleteTree(bsw);
    return 0;
}
