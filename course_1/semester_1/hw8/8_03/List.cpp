#include <iostream>
#include "List.h"
#include "Str.h"

using namespace std;

struct ListElement
{
    Str *value;
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

ListElement *createListElement(Str *value, ListElement *next)
{
	ListElement *newElement = new ListElement;
	newElement->value = value;
    newElement->count = 1;
	newElement->next = next;
	return newElement;
}

bool isEmpty(List *l)
{
    return l->length == 0;
}

int size(List *l)
{
    return l->length;
}

int add(List *l, Str *value)
{
	if (isEmpty(l))
	{
		l->head = createListElement(value, nullptr);
        l->length = 1;
        return 0;
	}

	ListElement *temp = l->head;

    while (temp->next != nullptr && !compareStr(value, temp->value))
		temp = temp->next;

    if (compareStr(value, temp->value))
    {
        temp->count++;
        return 2;
    }
    else if (temp->next == nullptr)
    {
        temp->next = createListElement(value, temp->next);
        l->length++;
        return 1;
    }
}

void printList(List *l)
{
    if (isEmpty(l))
        return;

    ListElement *temp = l->head;

    while (temp->next != nullptr)
    {
        printStr(temp->value);
        cout << ", ";
        temp = temp->next;
    }

    printStr(temp->value);
}

void changeList(List *listToChange, List *l)
{
    listToChange->head = l->head;
    listToChange->length = l->length;
}
