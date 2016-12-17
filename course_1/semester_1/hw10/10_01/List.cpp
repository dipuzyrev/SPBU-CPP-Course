#include "List.h"

struct ListElement
{
    char value;
    int priority;
    ListElement *next;
};

struct List
{
    ListElement *head;
    int size;
};

ListElement *createListElement(char value ,int priority, ListElement *next)
{
    ListElement *newItem = new ListElement;
    newItem->value = value;
    newItem->priority = priority;
    newItem->next = next;
    return newItem;
}

List *createList()
{
    List *newList = new List;
    newList->head = nullptr;
    newList->size = 0;
    return newList;
}

bool isEmpty(List *l)
{
    return l->size == 0;
}

void deleteList(List *&l)
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

void addValue(List *l, char value)
{
    if (isEmpty(l))
    {
        l->head = createListElement(value, 1, nullptr);
        l->size++;
        return;
    }

    ListElement *temp = l->head;

    while (temp->next != nullptr && value != temp->value)
        temp = temp->next;

    if (temp->value == value)
        temp->priority++;
    else
    {
        ListElement *newElem = createListElement(value, 1, nullptr);
        temp->next = newElem;
        l->size++;
    }
}

ReturnValue *extractValue(List *l)
{
    if (isEmpty(l))
        return nullptr;

    ReturnValue *toReturn = new ReturnValue;
    toReturn->character = l->head->value;
    toReturn->priority = l->head->priority;

    ListElement *toDelete = l->head;
    l->head = l->head->next;
    l->size--;
    delete toDelete;
    return toReturn;
}
