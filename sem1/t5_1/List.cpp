#include <iostream>
#include "List.h"

using namespace std;

struct ListItem
{
    ListItem *next;
    int value;
};

struct List
{
    ListItem *head;
    int size;
};

ListItem *createListItem(int value, ListItem *next)
{
    ListItem *newItem = new ListItem;
    newItem->next = next;
    newItem->value = value;
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

bool compareStrings(char *str1, char *str2, int length1, int length2)
{
    if (length1 != length2)
        return false;

    for (int i = 0; i < length1; i++)
        if (str1[i] != str2[i])
            return false;

    return true;
}

int errorNum(char *errorTitle, int length)
{
    char error1[] = "List empty";
    char error2[] = "Value doesn't exist";
    char error3[] = "Value already exist";

    int const length1 = 10;
    int const length2 = 19;
    int const length3 = 19;

    if (compareStrings(errorTitle, error1, length, length1))
        return 1;
    else if (compareStrings(errorTitle, error2, length, length2))
        return 2;
    else if (compareStrings(errorTitle, error3, length, length3))
        return 3;
    else
        return -1;
}

//addValue:
//returns 0 - value added, 1 - value already in the list
int addValue(List *l, int value)
{
    if (isEmpty(l))
    {
        l->head = createListItem(value, nullptr);
        l->size++;
        return 0;
    }

    if (l->head->value > value)
    {
        l->head = createListItem(value, l->head);
        l->size++;
        return 0;
    }

    if (l->head->next == nullptr)
    {
        if (l->head->value == value)
            return errorNum("Value already exist", 19);
        else if (l->head->value < value)
            l->head->next = createListItem(value, nullptr);
        else
            l->head = createListItem(value, l->head);

        l->size++;
        return 0;
    }

    ListItem *temp = l->head;
    while (temp->next->next != nullptr && temp->next->value < value)
        temp = temp->next;

    if (temp->next->next == nullptr)
    {
        if (temp->next->value == value)
            return errorNum("Value already exist", 19);
        else
        {
            if (temp->next->value < value)
                temp->next->next = createListItem(value, nullptr);
            else if (temp->next->value > value)
                temp->next = createListItem(value, temp->next);

            l->size++;
            return 0;
        }
    }
    else if (temp->next->value == value)
        return errorNum("Value already exist", 19);
    else
    {
        temp->next = createListItem(value, temp->next);
        l->size++;
        return 0;
    }
}

//removeValue:
//returns 0 - value removed, 1 - value isn't in the list, 2 - list empty
int removeValue(List *l, int value)
{
    if (isEmpty(l))
        return errorNum("List empty", 10);

    if (l->head->next == nullptr)
    {
        if (l->head->value == value)
        {
            ListItem *toDelete = l->head;
            l->head = nullptr;
            delete toDelete;
            l->size--;
            return 0;
        }
        else
            return errorNum("Value doesn't exist", 19);
    }

    ListItem *temp = l->head;

    while (temp->next->next != nullptr && temp->next->value < value)
        temp = temp->next;

    if (temp->value == value)
    {
        ListItem *toDelete = l->head;
        l->head = toDelete->next;
        delete toDelete;
    }
    else if (temp->next->value == value)
    {
        ListItem *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
    else if (temp->next->next == nullptr)
    {
        return errorNum("Value doesn't exist", 19);
    }

    l->size--;
    return 0;
}

void printList(List *l)
{
    if (isEmpty(l))
        return;

    ListItem *temp = l->head;
    int i = 1;

    while (temp != nullptr)
    {
        cout << i << ") " << temp->value << endl;
        i++;
        temp = temp->next;
    }
}

//clearList:
//returns 0 - list saccessfully cleared, 1 - list empty
int clearList(List *l)
{
    if (isEmpty(l))
        return errorNum("List empty", 10);

    ListItem *toDelete = l->head;

    while (toDelete != nullptr)
    {
        l->head = toDelete->next;
        delete toDelete;
        toDelete = l->head;
    }

    l->size = 0;
    return 0;
}
