#include <iostream>
#include "List.h"
#include "CustomString.h"

using namespace std;

struct ListElement
{
    String *value;
    int count;
    ListElement *next;
};

struct List
{
    ListElement *head;
    int length;
};

List* createList()
{
    List *list = new List;
    list->head = nullptr;
    list->length = 0;
    return list;
}

bool isEmpty(List *l)
{
    return l->length == 0;
}

void deleteList(List *&l)
{
    if(isEmpty(l))
        return;

    ListElement *temp = l->head;

    while (temp != nullptr)
    {
        ListElement *toDelete = temp;
        temp = temp->next;
        deleteString(toDelete->value);
        delete toDelete;
    }

    delete l;
    l = nullptr;
}

ListElement *createListElement(String *value, ListElement *next)
{
    ListElement *newElement = new ListElement;
    newElement->value = value;
    newElement->count = 1;
    newElement->next = next;
    return newElement;
}

int getListLength(List *l)
{
    return l->length;
}

bool addValue(List *l, String *value)
{
    if (isEmpty(l))
    {
        l->head = createListElement(value, nullptr);
        l->length = 1;
        return true;
    }

    ListElement *temp = l->head;

    while (temp->next != nullptr && !equals(value, temp->value))
        temp = temp->next;

    if (equals(value, temp->value))
    {
        temp->count++;
        return false;
    }
    else
    {
        temp->next = createListElement(value, nullptr);
        l->length++;
        return true;
    }
}

void printList(List *l)
{
    if (isEmpty(l))
        return;

    ListElement *temp = l->head;

    while (temp->next != nullptr)
    {
        cout << getChars(temp->value);
        cout << ", ";
        temp = temp->next;
    }

    cout << getChars(temp->value);
}
