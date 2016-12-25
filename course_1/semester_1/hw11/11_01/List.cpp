#include "List.h"

struct ListElement
{
    int stateId;
    ListElement *next;
};

struct StatesList
{
    ListElement *head;
    int size;
};

ListElement *createListElement(int stateId, ListElement *next)
{
    ListElement *newElement = new ListElement;
    newElement->stateId = stateId;
    newElement->next = next;
    return newElement;
}

StatesList *createStatesList()
{
    StatesList *newList = new StatesList;
    newList->head = nullptr;
    newList->size = 0;
    return newList;
}

bool isEmpty(StatesList *l)
{
    return l->size == 0;
}

void deleteStatesList(StatesList *&l)
{
    if (!isEmpty(l))
    {
        ListElement *toDelete = l->head;

        while (toDelete != nullptr)
        {
            l->head = toDelete->next;
            delete toDelete;
            toDelete = l->head;
        }
    }

    delete l;
    l = nullptr;
}

bool addState(int stateId, StatesList *l)
{
    if (isEmpty(l))
    {
        l->head = createListElement(stateId, nullptr);
        l->size++;
        return true;
    }

    ListElement *temp = l->head;

    while (temp->next != nullptr && stateId != temp->stateId)
        temp = temp->next;

    if (stateId == temp->stateId)
        return false;

    ListElement *newElem = createListElement(stateId, nullptr);
    temp->next = newElem;
    l->size++;
    return true;
}

StatesList *getCopy(StatesList *l)
{
    StatesList *toReturn = createStatesList();

    if (!isEmpty(l))
    {
        ListElement *temp = l->head;

        while (temp != nullptr)
        {
            addState(temp->stateId, toReturn);
            temp = temp->next;
        }
    }

    return toReturn;
}

StatesList **createStatesTable(const int size)
{
    StatesList **states = new StatesList *[size];

    for (int i = 0; i < size; i++)
        states[i] = createStatesList();

    return states;
}

int extractState(StatesList *l)
{
    if (isEmpty(l))
        return -1;

    int stateId = l->head->stateId;

    ListElement *toDelete = l->head;
    l->head = l->head->next;
    l->size--;

    delete toDelete;
    return stateId;
}
