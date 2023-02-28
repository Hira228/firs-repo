#ifndef LIST
#define LIST

typedef int Data;

struct Node
{
    Data data;
    struct Node *next;
}Node;

#endif