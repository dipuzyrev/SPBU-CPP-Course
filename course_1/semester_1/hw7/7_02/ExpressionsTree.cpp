#include <iostream>
#include <fstream>
#include <cstring>
#include <limits.h>
#include "ExpressionsTree.h"

using namespace std;

enum Directions
{
    leftDirection = 1,
    rightDirection = 2
};

struct Node
{
    int value;
    char operation;
    Node *left;
    Node *right;
};

Node *createNode(int value, Node *left, Node *right, char operation = '\0')
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->operation = operation;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

struct ExpressionsTree
{
    Node *root;
};

ExpressionsTree *create()
{
    ExpressionsTree *newTree = new ExpressionsTree;
    newTree->root = nullptr;
    return newTree;
}

void loadToNode(char *buffer, int &temp, int maxIndex, Node *parentNode, Directions direction)
{
    if (temp >= maxIndex)
        return;

    if (buffer[temp] == '(')
    {
        temp += 1;

        if (direction == leftDirection)
        {
            parentNode->left = createNode(INT_MAX, nullptr, nullptr, buffer[temp]);
            temp += 2;
            loadToNode(buffer, temp, maxIndex, parentNode->left, leftDirection);
            loadToNode(buffer, temp, maxIndex, parentNode->left, rightDirection);
        }
        else
        {
            parentNode->right = createNode(INT_MAX, nullptr, nullptr, buffer[temp]);
            temp += 2;
            loadToNode(buffer, temp, maxIndex, parentNode->right, leftDirection);
            loadToNode(buffer, temp, maxIndex, parentNode->right, rightDirection);
        }
    }
    else if(buffer[temp] >= '0' && buffer[temp] <= '9')
    {
        int number = 0;

        while(buffer[temp] >= '0' && buffer[temp] <= '9')
        {
            number = number * 10 + (buffer[temp] - '0');
            temp++;
        }

        if (direction == leftDirection)
        {
            parentNode->left = createNode(number, nullptr, nullptr);
            temp += 1;
        }
        else
        {
            parentNode->right = createNode(number, nullptr, nullptr);
            temp += 2;
        }
    }
}

void loadExpressionsFromFile(char const *fileName, ExpressionsTree *t, const int bufferSize)
{
    ifstream fin(fileName);

    char buffer[bufferSize] = {'\0'};
    fin.getline(buffer, bufferSize);

    int maxIndex = strlen(buffer) - 1;
    int temp = 0;

    if (maxIndex > 1 && buffer[temp] == '(')
    {
        t->root = createNode(INT_MAX, nullptr, nullptr, buffer[1]);
        temp += 3;
        loadToNode(buffer, temp, maxIndex, t->root, leftDirection);
        loadToNode(buffer, temp, maxIndex, t->root, rightDirection);
    }

    fin.close();
}

double computeOperation(int num1, int num2, char operation)
{
    switch (operation)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return (double) num1 / num2;
    default:
        return 0;
        break;
    }
}

double computeNode(Node *parentNode)
{
    if (parentNode == nullptr)
        return 0;

    if (parentNode->left == nullptr && parentNode->right == nullptr)
        return parentNode->value;

    int num1 = computeNode(parentNode->left);
    int num2 = computeNode(parentNode->right);
    return computeOperation(num1, num2, parentNode->operation);
}

double compute(ExpressionsTree *expressions)
{
    return computeNode(expressions->root);
}

void printNode(Node *parentNode)
{
    if (parentNode == nullptr)
        return;

    if (parentNode->left == nullptr && parentNode->right == nullptr)
        cout << parentNode->value;
    else
    {
        cout << "(";
        printNode(parentNode->left);
        cout << " " << parentNode->operation << " ";
        printNode(parentNode->right);
        cout << ")";
        return;
    }
}

void print(ExpressionsTree *t)
{
    if (t->root == nullptr)
        return;

    Node *temp = t->root;

    if (temp->left == nullptr && temp->right == nullptr)
    {
        cout << temp->value;
        return;
    }

    cout << "(";
    printNode(temp->left);
    cout << " " << temp->operation << " ";
    printNode(temp->right);
    cout << ")";
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

void deleteTree(ExpressionsTree *&t)
{
    if (t->root != nullptr)
    {
        Node *temp = t->root;
        deleteNode(temp->left);
        deleteNode(temp->right);
        delete temp;
    }

    delete t;
    t = nullptr;
}
