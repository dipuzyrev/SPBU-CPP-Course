#include <iostream>
#include "BinaryTree.h"

using namespace std;

enum Command
{
    exitCommand = 0,
    addValueCommand = 1,
    removeValueCommand = 2,
    checkValueCommand = 3,
    printInAscendingCommand = 4,
    printInDescendingCommand = 5,
    printStructureCommand = 6
};

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
            bool result = addValue(value, bsw);
            if (result)
                cout << "Value (" << value << ") added" << endl;
            else
                cout << "Value (" << value << ") already exist" << endl;
            break;
        }
        case removeValueCommand:
        {
            int value = 0;
            cout << "Input value to remove: ";
            cin >> value;
            bool result = deleteValue(value, bsw);
            if (result)
                cout << "Value (" << value << ") removed" << endl;
            else
                cout << "Value (" << value << ") not found" << endl;
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
        case printInAscendingCommand:
        {
            print(1, bsw);
            cout << endl;
            break;
        }
        case printInDescendingCommand:
        {
            print(2, bsw);
            cout << endl;
            break;
        }
        case printStructureCommand:
        {
            print(3, bsw);
            cout << endl;
            break;
        }
        default:
            cout << "Uncorrect command! To exit input 0" << endl;
            break;
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

void performAutomaticTest()
{
    BinaryTree *bsw = create();
    addValue(1, bsw);
    addValue(2, bsw);
    addValue(3, bsw);
    addValue(3, bsw);
    addValue(4, bsw);
    addValue(6, bsw);
    addValue(5, bsw);
    addValue(6, bsw);
    addValue(7, bsw);
    addValue(8, bsw);
    addValue(9, bsw);
    addValue(10, bsw);
    addValue(11, bsw);
    addValue(12, bsw);
    addValue(13, bsw);
    addValue(100, bsw);
    addValue(75, bsw);

    cout << "In ascending: ";
    print(1, bsw);

    cout << endl << "In descending: ";
    print(2, bsw);

    cout << endl << "Detail structure: ";
    print(3, bsw);

    cout << endl << "Delete value 15 and print in ascending: ";
    deleteValue(15, bsw);
    print(1, bsw);

    cout << endl << "Is value 15 in tree?: ";
    if (contains(15, bsw))
        cout << "YES";
    else
        cout << "NO";

    cout << endl << "Clear tree..." << endl;
    clear(bsw);
    cout << "Trying to print: ";
    print(3, bsw);
    cout << endl << "[End of automatic test]" << endl;
}

int main()
{
    performAutomaticTest();

//    BinaryTree *bsw = create();

//    printInstructions();
//    int command = getCommand();

//    while (command != 0)
//    {
//        performCommand(bsw, command);
//        command = getCommand();
//    }

//    clear(bsw);
//    delete bsw;
    return 0;
}
