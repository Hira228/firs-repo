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
void init_node(struct Node *list);
void list_remove_node(struct Node *t);
int list_is_empty(struct Node *list);

int main()
{
    struct Node z, a, b, c, u, w;
    struct Node *list = &z;
    z.data = 0;
    a.data = 3;
    b.data = 17;
    c.data = 21;
    u.data = 10;
    w.data = 8;

    init_node(list);

    insert_node(list, &c);
    print_list(list);        // 17

    insert_node(list, &b);
    print_list(list);        // 17 21

    insert_node(list, &a);
    print_list(list);        // 3 17 21

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

    list_remove_node(&u);
    print_list(list);   // 3 8 17 21
    print_back(list);   // 21 17 8 3

    list_remove_node(&w);
    print_list(list);   // 3 17 21
    print_back(list);   // 21 17 3
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
    insert_node(p -> prev, t);
}

void init_node(struct Node *list)
{
    list -> prev = list;
    list -> next = list;
}

void list_remove_node(struct Node *t)
{
    struct Node *p = t -> prev;  // 1
    struct Node *q = t -> next;  // 2

    p -> next = q;
    q -> prev = p;
}

int list_is_empty(struct Node *list)
{
    return list->prev == list -> next && list -> next == list;
}