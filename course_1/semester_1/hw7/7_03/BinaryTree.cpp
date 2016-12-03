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

Node *recursiveAddValue(int value, Node *parentNode)
{
    if (parentNode == nullptr)
        return createNode(value);

    if (value < parentNode->value)
    {
        parentNode->left = recursiveAddValue(value, parentNode->left);
        parentNode = balance(parentNode);
    }
    else if (value > parentNode->value)
    {
        parentNode->right = recursiveAddValue(value, parentNode->right);
        parentNode = balance(parentNode);
    }

    return parentNode;
}

void addValue(int value, BinaryTree *t)
{
    t->root = recursiveAddValue(value, t->root);
    t->root = balance(t->root);
}

int deleteMin(Node *parentNode)
{
    if (parentNode == nullptr)
        return 0;

    Node *temp = parentNode;

    while (temp->left != nullptr)
        temp = temp->left;

    int value = temp->left->value;
    delete temp->left;
    temp->left = nullptr;
    return value;
}

Node *recursiveDeleteValue(Node *parentNode, int value)
{
    if (parentNode == nullptr)
        return parentNode;

    if (value < parentNode->value)
        parentNode->left = recursiveDeleteValue(parentNode->left, value);
    else if (value > parentNode->value)
        parentNode->right = recursiveDeleteValue(parentNode->right, value);
    else if (parentNode->left != nullptr && parentNode->right != nullptr)
        parentNode->value = deleteMin(parentNode->right);
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

    if (recursiveDeleteValue(t->root, value) == nullptr)
        return false;
    else
        return true;
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

void recursivePrintNode(int flag, Node *parentNode)
{
    if (parentNode == nullptr)
    {
        if (flag == 3)
            cout << " null";
        return;
    }

    if (flag == 1)
    {
        if (parentNode->left == nullptr && parentNode->right == nullptr)
            cout << parentNode->value << " ";
        else
        {
            recursivePrintNode(1, parentNode->left);
            cout << parentNode->value << " ";
            recursivePrintNode(1, parentNode->right);
            return;
        }
    }
    else if (flag == 2)
    {
        if (parentNode->left == nullptr && parentNode->right == nullptr)
            cout << parentNode->value << " ";
        else
        {
            recursivePrintNode(2, parentNode->right);
            cout << parentNode->value << " ";
            recursivePrintNode(2, parentNode->left);
            return;
        }
    }
    else if (flag == 3)
    {
        cout << " (" << parentNode->value;
        recursivePrintNode(3, parentNode->left);
        recursivePrintNode(3, parentNode->right);
        cout << ")";
    }
}

//1: in ascending
//2: in descending
//3: (value, (n1...), (n2...))
void print(int flag, BinaryTree *t)
{
    if (t->root == nullptr)
        return;

    Node *temp = t->root;

    if (flag == 1)
    {
        if (temp->left == nullptr && temp->right == nullptr)
        {
            cout << temp->value;
            return;
        }

        recursivePrintNode(1, temp->left);
        cout << temp->value << " ";
        recursivePrintNode(1, temp->right);
    }
    else if (flag == 2)
    {
        Node *temp = t->root;

        if (temp->left == nullptr && temp->right == nullptr)
        {
            cout << temp->value << " ";
            return;
        }

        recursivePrintNode(2, temp->right);
        cout << temp->value << " ";
        recursivePrintNode(2, temp->left);
    }
    else
    {
        cout << "(" << temp->value;
        recursivePrintNode(3, temp->left);
        recursivePrintNode(3, temp->right);
        cout << ")";
    }
}

void recursiveDeleteNode(Node *n)
{
    if (n == nullptr)
        return;

    if (n->left == nullptr && n->right == nullptr)
        delete n;
    else
    {
        recursiveDeleteNode(n->left);
        recursiveDeleteNode(n->right);
        delete n;
    }
}

bool clear(BinaryTree *t)
{
    if (t->root == nullptr)
        return false;

    Node *temp = t->root;
    recursiveDeleteNode(temp->left);
    recursiveDeleteNode(temp->right);
    delete temp;

    t->root = nullptr;
    return true;
}
