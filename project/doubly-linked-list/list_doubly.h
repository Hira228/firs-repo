#ifndef LIST_2
#define LIST_2

typedef int Data;

struct Node
{
    Data data;
    struct Node *next;
    struct Node *prev;
}Node;

#endif