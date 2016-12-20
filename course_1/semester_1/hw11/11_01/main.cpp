#include <iostream>
#include "List.h"

using namespace std;

const int statesCount = 7;
const int columnNumber = 6;

enum columnNumber
{
    digitColumn = 0,
    dotColumn = 1,
    eColumn = 2,
    plusColumn = 3,
    minusColumn = 4,
    epsilaColumn = 5
};

StatesList *getTableValue(int line, int column, StatesList **table)
{
    StatesList *toReturn = table[line * columnNumber + column];
    return toReturn;
}

void fillTransitionsTable(StatesList **table)
{
    addState(0, getTableValue(0, 0, table));
    addState(1, getTableValue(0, 0, table));

    addState(2, getTableValue(1, 1, table));
    addState(3, getTableValue(1, 5, table));

    addState(2, getTableValue(2, 0, table));
    addState(3, getTableValue(2, 0, table));

    addState(4, getTableValue(3, 2, table));
    addState(6, getTableValue(3, 5, table));

    addState(5, getTableValue(4, 3, table));
    addState(5, getTableValue(4, 4, table));
    addState(5, getTableValue(4, 5, table));

    addState(5, getTableValue(5, 0, table));
    addState(6, getTableValue(5, 0, table));
}

void deleteTransitionsTable(StatesList **&table, const int size)
{
    for (int i = 0; i < size; i++)
        deleteStatesList(table[i]);

    delete[] table;
    table = nullptr;
}

void addStates(StatesList *whereAdd, StatesList **transitions, int line, int column)
{
    StatesList *whereToGo = getCopy(getTableValue(line, column, transitions));

    while (!isEmpty(whereToGo))
    {
        int stateId = extractState(whereToGo);
        addState(stateId, whereAdd);
    }

    deleteStatesList(whereToGo);
}

void performTransition(int stateId, char symbol, StatesList **transitions, StatesList *nextStates)
{
    if (symbol >= '0' && symbol <= '9')
    {
        addStates(nextStates, transitions, stateId, 0);
        return;
    }

    switch (symbol)
    {
        case '.':
            addStates(nextStates, transitions, stateId, dotColumn);
            break;
        case 'e':
            addStates(nextStates, transitions, stateId, eColumn);
            break;
        case '+':
            addStates(nextStates, transitions, stateId, plusColumn);
            break;
        case '-':
            addStates(nextStates, transitions, stateId, minusColumn);
            break;
    }
}

void performEpsilaTransitions(StatesList **transitions, StatesList *currentStates)
{
    StatesList *copy = getCopy(currentStates);

    while (!isEmpty(copy))
    {
        int stateId = extractState(copy);
        addStates(currentStates, transitions, stateId, epsilaColumn);
    }

    deleteStatesList(copy);
}

int main()
{
    //Regular Expression:
    //digit+ (. digit+)? (E(+ | -)? digit+)?

    const int bufferSize = 1024;

    StatesList **transitionsTable = createStatesTable(statesCount * columnNumber);
    fillTransitionsTable(transitionsTable);

    StatesList *currentStates = createStatesList();
    addState(0, currentStates);

    char buffer[bufferSize] = {'\0'};
    cout << "Input your number: ";
    cin >> buffer;

    bool result = false;

    int i = 0;
    while (i < bufferSize && !isEmpty(currentStates))
    {
        char symbol = buffer[i];

        if (symbol == '\0')
        {
            while (!isEmpty(currentStates))
                if (extractState(currentStates) == statesCount - 1)
                    result = true;

            break;
        }

        StatesList *nextStates = createStatesList();

        while(!isEmpty(currentStates))
        {
            int stateId = extractState(currentStates);
            performTransition(stateId, symbol, transitionsTable, nextStates);
        }

        performEpsilaTransitions(transitionsTable, nextStates);

        deleteStatesList(currentStates);
        currentStates = nextStates;
        i++;
    }

    if (result)
        cout << "Yes, it's float number!";
    else
        cout << "No, it isn't float number!";

    cout << endl;

    deleteTransitionsTable(transitionsTable, statesCount * columnNumber);
    deleteStatesList(currentStates);
    return 0;
}
