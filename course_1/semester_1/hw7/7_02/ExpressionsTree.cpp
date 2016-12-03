#include <iostream>
#include <fstream>
#include <limits>
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

int charToInt(char *str)
{
    int i = 0;
    int newNumber = 0;

    while (i < 1024 && str[i] >= '0' && str[i] <= '9')
    {
        newNumber = newNumber * 10 + (str[i] - '0');
        i++;
    }

    return newNumber;
}

int computeBufferLength(char *buffer)
{
    for (int i = 0; i < 2048; i++)
        if (buffer[i] == '\0')
            return i;
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

void loadExpressionsFromFile(char const *fileName, ExpressionsTree *t)
{
    ifstream fin(fileName);

    char buffer[2048] = {'\0'};
    fin.getline(buffer, 2048);

    int maxIndex = computeBufferLength(buffer) - 1;
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

bool clear(ExpressionsTree *t)
{
    if (t->root == nullptr)
        return false;

    Node *temp = t->root;
    deleteNode(temp->left);
    deleteNode(temp->right);
    delete temp;

    t->root = nullptr;
}
