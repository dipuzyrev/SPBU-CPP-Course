#pragma once

struct BinaryTree;

BinaryTree *create();

bool addValue(int value, BinaryTree *t);
bool deleteValue(int value, BinaryTree *t);
bool contains(int value, BinaryTree *t);

//1: in ascending
//2: in descending
//3: (value, (n1...), (n2...))
void print(int flag, BinaryTree *t);

bool clear(BinaryTree *t);

