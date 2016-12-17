#include "PriorityQueue.h"

struct InternalQueueElement
{
    InternalQueueElement *next;
    int key;
    int value;
};

struct PriorityQueue
{
    InternalQueueElement *minimal;
    int size;
};

InternalQueueElement *createInternalElement(int key, int value, InternalQueueElement *next)
{
    InternalQueueElement *newElem = new InternalQueueElement;
    newElem->key = key;
    newElem->value = value;
    newElem->next = next;
    return newElem;
}

PriorityQueue *createPriorityQueue()
{
    PriorityQueue *newQueue = new PriorityQueue;
    newQueue->minimal = nullptr;
    newQueue->size = 0;
    return newQueue;
}

bool isEmpty(PriorityQueue *q)
{
    return q->size == 0;
}

void deletePriorityQueue(PriorityQueue *&q)
{
    if (!isEmpty(q))
    {
        InternalQueueElement *temp = q->minimal;

        while (temp != nullptr)
        {
            InternalQueueElement *toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }

    delete q;
    q = nullptr;
}

void insert(int key, int value, PriorityQueue *q)
{
    InternalQueueElement *newElem = createInternalElement(key, value, q->minimal);

    if (isEmpty(q))
        q->minimal = newElem;
    else if (key <= q->minimal->key)
        q->minimal = newElem;
    else
    {
        InternalQueueElement *temp = q->minimal;
        newElem->next = nullptr;

        if (temp->next == nullptr)
            temp->next = newElem;
        else
        {
            while (temp->next->next != nullptr && key > temp->next->key)
                temp = temp->next;

            if (key <= temp->next->key)
            {
                newElem->next = temp->next;
                temp->next = newElem;
            }
            else
                temp->next->next = newElem;
        }
    }

    q->size++;
}

QueueElement *extractMin(PriorityQueue *q)
{
    if (isEmpty(q))
        return nullptr;

    QueueElement *toReturn = new QueueElement;
    toReturn->key = q->minimal->key;
    toReturn->value = q->minimal->value;

    InternalQueueElement *toDelete = q->minimal;
    q->minimal = q->minimal->next;
    delete toDelete;

    q->size--;
    return toReturn;
}
