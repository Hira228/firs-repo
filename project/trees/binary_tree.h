#ifndef TREE_H
#define TREE_H

typedef int Data;

struct Node
{
    Data data;
    struct Node *left;   // Левый рбенок
    struct Node *right;  // Правый ребенок
}Node;

#endif