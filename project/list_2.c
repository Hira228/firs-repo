//Пытаюсь разобраться со структурами и двусвязными списками :))
// Двусвязный циклический список с барьерным элементом

#include <stdio.h>
#include <stdlib.h>
#include "list_2.h"

void print_list(struct Node *list);
void print_back(struct Node *list);
void print_dbg(struct Node *list);
void insert_node(struct Node *p, struct Node *t);
void insert_node_before(struct Node *p, struct Node *t);

int main()
{
    struct Node z, a = {3}, b = {17}, c = {21}, u = {10} , w = {8};
    struct Node *list = &z;
    z.data = 0;
    a.data = 3;
    b.data = 17;
    c.data = 21;
    u.data = 10;
    w.data = 8;
    z.next = &a;
    z.prev = &c;
    a.next = &b;
    a.prev = &z;
    b.next = &c;
    b.prev = &a;
    c.next = &z;
    c.prev = &b;

    print_list(list);  // 3 17 21
    print_back(list);  // 21 17 3
    print_dbg(list);
    
    struct Node *p = &a;
    struct Node *t = &u;

    insert_node(&a, &u);

    print_list(list);  // 3 10 17 21
    print_back(list);  // 21 17 10 3

    p = &u;
    t = &w;

    insert_node_before(&u, &w);

    print_list(list);   // 3 8 10 17 21
    print_back(list);   // 21 17 10 8 3
}

void print_list(struct Node *list)
{
    for(struct Node *ptr = list -> next; ptr != list; ptr = ptr -> next)
    {
        printf("%d ", ptr -> data);
    }
    printf("\n");
}

void print_back(struct Node *list)
{
    for(struct Node *ptr = list -> prev; ptr != list; ptr = ptr -> prev)
    {
        printf("%d ", ptr -> data);
    }
    printf("\n");
}

void print_dbg(struct Node *list)
{
    struct Node *ptr = list;
    printf("--------------------------------------------------------------------\n");
    printf("list:  prev=%p %p next=%p\n", ptr -> prev, ptr, ptr -> next);
    for(ptr = list -> next; ptr != list; ptr = ptr -> next)
    {
        printf("%d prev=%p %p next=%p\n", ptr -> data, ptr -> prev, ptr, ptr -> next);
    }
    printf("\n");
}

void insert_node(struct Node *p, struct Node *t)
{
    struct Node *q = p -> next;

    t -> prev = p;  // 1
    t -> next = q;  // 2
    p -> next = t;  // 3
    q -> prev = t;  // 4
}

void insert_node_before(struct Node *p, struct Node *t)
{
    struct Node *q = p -> prev;

    t -> next = p;  // 1
    t -> prev = q;  // 2
    p -> prev = t;  // 3
    q -> next = t;  // 4
}