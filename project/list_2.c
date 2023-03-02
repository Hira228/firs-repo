//Пытаюсь разобраться со структурами и двусвязными списками :))
// Двусвязный циклический список с барьерным элементом

#include <stdio.h>
#include <stdlib.h>
#include "list_2.h"

#define TEST_WITHOUT_ALLOC


void print_list(struct Node *list);
void print_back(struct Node *list);
void print_dbg(struct Node *list);
void insert_node(struct Node *p, struct Node *t);
void insert_node_before(struct Node *p, struct Node *t);
void init_node(struct Node *list);
void list_remove_node(struct Node *t);
int list_is_empty(struct Node *list);
void test_alloc_node();
void *push_front_node(struct Node *list, Data x);
void *push_back_node(struct Node *list, Data x);

int main()
{
   test_alloc_node();
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

void test_alloc_node()
{
    struct Node z;
    struct Node *list = &z;

    Data test_data1[] = {21, 17, 3};
    Data test_data2[] = {10, 8};

    init_node(list);
    printf("Empty %s\n", list_is_empty(list) ? "YES" : "NO");

    struct Node *t;
    
    for(size_t i = 0; i < sizeof(test_data1) / sizeof(test_data1[0]); i++)
    {
        t = push_front_node(list, test_data1[i]);
        print_list(list);
        printf("Pushed: %d\n", t -> data);
    }

    // 3 17 21

    for(size_t i = 0; i < sizeof(test_data2) / sizeof(test_data2[0]); i++)
    {
        t = push_back_node(list, test_data2[i]);
        print_list(list);
        printf("Pushed: %d\n", t -> data);
    }

    // 3 17 21 10 8
    
    print_list(list);

    printf("Pushed: %d\n", t -> data);
    printf("Empty %s\n", list_is_empty(list) ? "YES" : "NO");


}

void *push_front_node(struct Node *list, Data x)
{
    struct Node *p = malloc(sizeof(struct Node));
    p -> data = x;
    insert_node(list, p);
    return p;
}

void *push_back_node(struct Node *list, Data x)
{
    push_front_node(list -> prev, x);
}


void test_without_alloc()
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
    printf("Empty %s\n", list_is_empty(list) ? "YES" : "NO");

    insert_node(list, &c);
    print_list(list);        // 17
    printf("Empty %s\n", list_is_empty(list) ? "YES" : "NO");

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