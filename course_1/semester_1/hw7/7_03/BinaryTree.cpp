#include <iostream>
#include "BinaryTree.h"

using namespace std;

struct Node
{
    int value;
    int height;
    Node *left;
    Node *right;
};

Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->height = 0;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

struct BinaryTree
{
    Node *root;
};

int height(Node *node)
{
   return node ? node->height : 0;
}

int balanceFactor(Node *node)
{
    if ((node->left == nullptr || node->right == nullptr) && node->height == 2)
        return (node->left == nullptr) ? -2 : 2;

   return height(node->left) - height(node->right);
}

void updateHeight(Node *node)
{
    if (node->left == nullptr && node->right == nullptr)
        node->height = 0;
    else
    {
        int heightLeft = height(node->left);
        int heightRight = height(node->right);
        node->height = ((heightLeft > heightRight) ? heightLeft : heightRight) + 1;
    }
}

BinaryTree *create()
{
    BinaryTree *newTree = new BinaryTree;
    newTree->root = nullptr;
    return newTree;
}

Node *rotateRight(Node* root)
{
   Node* pivot = root->left;
   root->left = pivot->right;
   pivot->right = root;
   updateHeight(root);
   updateHeight(pivot);
   return pivot;
}

Node *rotateLeft(Node* root)
{
   Node* pivot = root->right;
   root->right = pivot->left;
   pivot->left = root;
   updateHeight(root);
   updateHeight(pivot);
   return pivot;
}

Node* balance(Node* p)
{
    updateHeight(p);

    if (balanceFactor(p) == 2)
    {
        if (balanceFactor(p->left) < 0)
            p->left = rotateLeft(p->left);

        return rotateRight(p);
    }

    if (balanceFactor(p) == -2)
    {
        if (balanceFactor(p->right) > 0)
            p->right = rotateRight(p->right);

        return rotateLeft(p);
    }

    updateHeight(p);
    return p;
}

Node *addValueToNode(int value, Node *parentNode)
{
    if (parentNode == nullptr)
        return createNode(value);

    if (value < parentNode->value)
    {
        parentNode->left = addValueToNode(value, parentNode->left);
        parentNode = balance(parentNode);
    }
    else if (value > parentNode->value)
    {
        parentNode->right = addValueToNode(value, parentNode->right);
        parentNode = balance(parentNode);
    }

    return parentNode;
}

void addValue(int value, BinaryTree *t)
{
    t->root = addValueToNode(value, t->root);
    t->root = balance(t->root);
}

int deleteMin(Node *parentNode)
{
    Node *temp = parentNode;

    while (temp->left->left != nullptr)
        temp = temp->left;

    int value = temp->left->value;
    Node *toDelete = temp->left;
    temp->left = temp->left->right;
    delete toDelete;
    return value;
}

Node *deleteValueInNode(Node *parentNode, int value)
{
    if (parentNode == nullptr)
        return parentNode;

    if (value < parentNode->value)
        parentNode->left = deleteValueInNode(parentNode->left, value);
    else if (value > parentNode->value)
        parentNode->right = deleteValueInNode(parentNode->right, value);
    else if (parentNode->left != nullptr && parentNode->right != nullptr)
    {
        if (parentNode->right->left == nullptr)
        {
            parentNode->value = parentNode->right->value;
            parentNode->right = parentNode->right->right;
        }
        else
        {
            parentNode->value = deleteMin(parentNode->right);
            parentNode->right = balance(parentNode->right);
        }
    }
    else
    {
        if (parentNode->left != nullptr)
            parentNode = parentNode->left;
        else
            parentNode = parentNode->right;
    }

    parentNode = balance(parentNode);
    return parentNode;
}

bool deleteValue(int value, BinaryTree *t)
{
    if (t->root == nullptr)
        return false;

    t->root = deleteValueInNode(t->root, value);

    return (t->root != nullptr);
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
            temp = temp->left;
        else if (value > temp->value)
            temp = temp->right;
    }

    return false;
}

void printNode(int mode, Node *parentNode)
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
            if (parentNode->left == nullptr && parentNode->right == nullptr)
                cout << parentNode->value << " ";
            else
            {
                printNode(1, parentNode->left);
                cout << parentNode->value << " ";
                printNode(1, parentNode->right);
                return;
            }
            break;
        }
        case 2:
        {
            if (parentNode->left == nullptr && parentNode->right == nullptr)
                cout << parentNode->value << " ";
            else
            {
                printNode(2, parentNode->right);
                cout << parentNode->value << " ";
                printNode(2, parentNode->left);
                return;
            }
            break;
        }
        case 3:
        {
            cout << " (" << parentNode->value;
            printNode(3, parentNode->left);
            printNode(3, parentNode->right);
            cout << ")";
            break;
        }
    }
}

//mode
//1: in ascending
//2: in descending
//3: structure
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

void deleteNode(Node *n)
{
    if (n == nullptr)
        return;

    if (n->left == nullptr && n->right == nullptr)
        delete n;
    else
    {
        deleteNode(n->left);
        deleteNode(n->right);
        delete n;
    }
}

bool clear(BinaryTree *t)
{
    if (t->root == nullptr)
        return false;

    Node *temp = t->root;
    deleteNode(temp->left);
    deleteNode(temp->right);
    delete temp;

    t->root = nullptr;
    return true;
}
