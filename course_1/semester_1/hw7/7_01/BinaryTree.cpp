#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *leftChild;
    Node *rightChild;
};

Node *createNode(int value, Node *left, Node *right)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->leftChild = left;
    newNode->rightChild = right;
}


struct BinaryTree
{
    Node *root;
};

BinaryTree *create()
{
    BinaryTree *newTree = new BinaryTree;
    newTree->root = nullptr;
}

bool addValue(int value, BinaryTree *t)
{
    if (t->root == nullptr)
    {
        t->root = createNode(value, nullptr, nullptr);
        return true;
    }

    Node *temp = t->root;

    while (temp != nullptr)
    {
        if (value < temp->value)
        {
            if (temp->leftChild == nullptr)
            {
                temp->leftChild = createNode(value, nullptr, nullptr);
                return true;
            }
            else
                temp = temp->leftChild;
        }
        else if (value > temp->value)
        {
            if (temp->rightChild == nullptr)
            {
                temp->rightChild = createNode(value, nullptr, nullptr);
                return true;
            }
            else
                temp = temp->rightChild;
        }
        else if (value == temp->value)
        {
            return false;
        }
    }
}

//joins Node 'toJoin' to leftMost descendant of 'where'
//'whereParent' must be not nullptr!
void joinNode(Node *toJoin, Node *where, Node *whereParent)
{
    if (toJoin == nullptr)
        return;

    if (where == nullptr)
    {
        whereParent->rightChild = toJoin;
        return;
    }

    while (where->leftChild != nullptr)
        where = where->leftChild;

    where->leftChild = toJoin;
}

bool deleteValue(int value, BinaryTree *t)
{
    if (t->root == nullptr)
        return false;

    Node *temp = t->root;
    if (value == temp->value)
    {
        joinNode(temp->leftChild, temp->rightChild, temp);
        t->root = temp->rightChild;
        delete temp;
        return true;
    }

    while (temp->leftChild != nullptr || temp->rightChild != nullptr)
    {
        if (value < temp->value)
        {
            if (temp->leftChild == nullptr)
                return false;
            if (value == temp->leftChild->value)
            {
                joinNode(temp->leftChild->leftChild, temp->leftChild->rightChild, temp->leftChild);
                Node *toDelete = temp->leftChild;
                temp->leftChild = temp->leftChild->rightChild;
                delete toDelete;
                return true;
            }
            else
                temp = temp->leftChild;
        }
        else if (value > temp->value)
        {
            if (temp->rightChild == nullptr)
                return false;
            if (value == temp->rightChild->value)
            {
                joinNode(temp->rightChild->leftChild, temp->rightChild->rightChild, temp->rightChild);
                Node *toDelete = temp->rightChild;
                temp->rightChild = temp->rightChild->rightChild;
                delete toDelete;
                return true;
            }
            else
                temp = temp->rightChild;
        }
    }

    return false;
}

bool contains(int value, BinaryTree *t)
{
    if (t->root == nullptr)
        return false;

    Node *temp = t->root;

    while (temp != nullptr)
    {
        if (temp->value == value)
            return true;
        else if (value < temp->value)
            temp = temp->leftChild;
        else if (value > temp->value)
            temp = temp->rightChild;
    }

    return false;
}

void recursivePrintNode(int mode, Node *parentNode)
{
    if (parentNode == nullptr)
    {
        if (mode == 3)
            cout << " null";
        return;
    }

    switch (mode)
    {
        case 1:
        {
            if (parentNode->leftChild == nullptr && parentNode->rightChild == nullptr)
                cout << parentNode->value << " ";
            else
            {
                recursivePrintNode(1, parentNode->leftChild);
                cout << parentNode->value << " ";
                recursivePrintNode(1, parentNode->rightChild);
                return;
            }
            break;
        }
        case 2:
        {
            if (parentNode->leftChild == nullptr && parentNode->rightChild == nullptr)
                cout << parentNode->value << " ";
            else
            {
                recursivePrintNode(2, parentNode->rightChild);
                cout << parentNode->value << " ";
                recursivePrintNode(2, parentNode->leftChild);
                return;
            }
            break;
        }
        case 3:
        {
            cout << " (" << parentNode->value;
            recursivePrintNode(3, parentNode->leftChild);
            recursivePrintNode(3, parentNode->rightChild);
            cout << ")";
            break;
        }
    }
}

//1: in ascending
//2: in descending
//3: (value, (n1...), (n2...))
void print(int mode, BinaryTree *t)
{
    if (t->root == nullptr)
        return;

    Node *temp = t->root;

    switch (mode)
    {
        case 1:
        {
            if (temp->leftChild == nullptr && temp->rightChild == nullptr)
            {
                cout << temp->value;
                return;
            }
            break;
        }
        case 2:
        {
            Node *temp = t->root;

            if (temp->leftChild == nullptr && temp->rightChild == nullptr)
            {
                cout << temp->value << " ";
                return;
            }

            recursivePrintNode(2, temp->rightChild);
            cout << temp->value << " ";
            recursivePrintNode(2, temp->leftChild);
            break;
        }
        case 3:
        {
            cout << "(" << temp->value;
            recursivePrintNode(3, temp->leftChild);
            recursivePrintNode(3, temp->rightChild);
            cout << ")";
            break;
        }
    }
}

void recursiveDeleteNode(Node *n)
{
    if (n == nullptr)
        return;

    if (n->leftChild == nullptr && n->rightChild == nullptr)
        delete n;
    else
    {
        recursiveDeleteNode(n->leftChild);
        recursiveDeleteNode(n->rightChild);
        delete n;
    }
}

bool clear(BinaryTree *t)
{
    if (t->root == nullptr)
        return false;

    Node *temp = t->root;
    recursiveDeleteNode(temp->leftChild);
    recursiveDeleteNode(temp->rightChild);
    delete temp;

    t->root = nullptr;
}
