#include "Queue.h";

struct QueueElement
{
    QueueElement *next;
    int num;
};

struct Queue
{
    QueueElement *head;
    QueueElement *last;
};

Queue *createList()
{
    Queue *l = new Queue;
    l->head = nullptr;
    l->last = nullptr;
}

void addNumber(int value, Queue *l)
{
    QueueElement *newElem = new QueueElement;
    newElem->next = nullptr;
    newElem->num = value;

    if (l->last == nullptr)
    {
        l->head = newElem;
        l->last = newElem;
    }
    else
        l->last->next = newElem;

    l->last = newElem;
}
