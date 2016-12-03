
struct ListItem
{
    int value;
    ListItem *next;
};

struct CycleList
{
    ListItem *head;
    ListItem *pointer;
    int size;
};

ListItem *createListItem(int value, ListItem *next)
{
    ListItem *newItem = new ListItem;
    newItem->value = value;
    newItem->next = next;
    return newItem;
}

CycleList *createList()
{
    CycleList *newList = new CycleList;
    newList->head = nullptr;
    newList->pointer = nullptr;
    newList->size = 0;

    return newList;
}

bool isEmpty(CycleList *l)
{
    return l->size == 0;
}

ListItem *getLastItem(CycleList *l)
{
    if (isEmpty(l))
        return nullptr;
    else if (l->head->value == l->head->next->value)
        return l->head;
    else
    {
        int headValue = l->head->value;
        ListItem *temp = l->head->next;

        int i = 0; //to avoid loop
        while (temp->next->value != headValue && i <= l->size)
        {
            temp = temp->next;
            i++;
        }

        if (i == l->size)
            return nullptr;
        else
            return temp;
    }
}

bool addValue(CycleList *l, int value)
{
    if (isEmpty(l))
    {
        l->head = createListItem(value, nullptr);
        l->head->next = l->head;
        l->size++;
        return true;
    }

    if (value == l->head->value)
        return false;

    if (value < l->head->value)
    {
        ListItem *lastItem = getLastItem(l);
        l->head = createListItem(value, l->head);
        lastItem->next = l->head;
        l->size++;
        return true;
    }

    ListItem *temp = l->head;
    while (temp->value < temp->next->value && value > temp->next->value)
        temp = temp->next;

    if (value == temp->next->value)
        return false;
    else
    {
        temp->next = createListItem(value, temp->next);
        l->size++;
        return true;
    }
}

bool clearList(CycleList *l)
{
    if (isEmpty(l))
        return false;

    ListItem *toDelete = l->head;

    do
    {
        if (l->head->next->value != l->head->value)
        {
            l->head = l->head->next;
            delete toDelete;
            toDelete = l->head;
        }
        else
        {
            delete toDelete;
            break;
        }
    }
    while (toDelete->value != l->head->value);

    l->size = 0;
    l->head = nullptr;
    l->pointer = nullptr;

    return true;
}

int removeCurrentPointerValue(CycleList *l)
{
    if (l->pointer == nullptr)
        return false;

    if (isEmpty(l))
        return false;

    if (l->head->next->value == l->head->value)
    {
        delete l->head;
        l->head = nullptr;
        l->size = 0;
        l->pointer = nullptr;
        return true;
    }

    ListItem *temp = l->head;

    while (temp->next->next->value != l->head->value && temp->next->value < l->pointer->value)
        temp = temp->next;

    if (temp->value == l->pointer->value)
    {
        ListItem *lastItem = getLastItem(l);
        ListItem *toDelete = l->head;
        l->head = toDelete->next;
        lastItem->next = l->head;
        l->pointer = toDelete->next;
        delete toDelete;
    }
    else if ((temp->next->next->value == l->pointer->value) || (temp->next->value == l->pointer->value))
    {
        ListItem *toDelete = temp->next;
        temp->next = temp->next->next;
        l->pointer = toDelete->next;
        delete toDelete;
    }

    l->size--;
    return true;
}

void movePointer(CycleList *l, int m)
{
    if (l->pointer == nullptr)
        l->pointer = l->head;

    if (m > 0)
        for (int i = 0; i < m; i++)
            l->pointer = l->pointer->next;
}

//getCurrentPointerValue
//returns: -1 - pointer isn't defined or (int) pointer value
int getCurrentPointerValue(CycleList *l)
{
    if (l->pointer == nullptr)
        return -1;
    else
        return l->pointer->value;
}








