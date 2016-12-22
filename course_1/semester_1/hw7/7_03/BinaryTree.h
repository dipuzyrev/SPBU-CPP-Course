#pragma once

struct BinaryTree;

BinaryTree *create();

void addValue(int value, BinaryTree *t);
void deleteValue(int value, BinaryTree *t);
bool contains(int value, BinaryTree *t);

void print(int mode, BinaryTree *t);

void deleteTree(BinaryTree *&t);

