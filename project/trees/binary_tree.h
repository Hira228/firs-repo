#ifndef TREE_H
#define TREE_H

typedef int Data;

struct Node
{
    Data data;
    struct Node *left;
    struct Node *right;
}Node;

#endif