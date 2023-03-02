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
void test_alloc_node();
void *push_front_node(struct Node *list, Data x);
void *push_back_node(struct Node *list, Data x);
Data delete_node(struct Node *p);
Data pop_front_node(struct Node *list);
Data pop_back_node(struct Node *list);
void list_clear(struct Node *list);
void test_foreach_node();
void foreach_node(struct Node *list, void (*func)(Data x, void *arg), void *arg);
void print_list1(struct Node *list, FILE *fout);
void print_it_node(Data x, void *arg);
void sum_it_list(Data x, void *a);
void sum_list(struct Node *list, Data *res);

int main()
{
   test_foreach_node();
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

    t = list -> next -> next; // 17
    Data x;

    x = delete_node(t);
    print_list(list);       // 3 21 10 8
    printf("Deleted: %d\n", x);

    x = pop_front_node(list); 
    print_list(list);       // 21 10 8
    printf("Deleted: %d\n", x);  // 3

    x = pop_back_node(list); 
    print_list(list);       // 21 10
    printf("Deleted: %d\n", x);  // 8

    list_clear(list);
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

Data delete_node(struct Node *p)
{
    list_remove_node(p);
    Data x = p -> data;
    return x;
}

Data pop_front_node(struct Node *list)
{
    return delete_node(list -> next);
}

Data pop_back_node(struct Node *list)
{
    return delete_node(list -> prev);
}

void list_clear(struct Node *list)
{
    while(!list_is_empty(list))
    {
        pop_front_node(list);
        print_list(list);
        printf("\n");
    }
    
    printf("Empty %s\n", list_is_empty(list) ? "YES" : "NO");
    printf("\n");
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

void test_foreach_node()
{
    struct Node z;
    struct Node *list = &z;

    Data test_data1 [] = {8, 10, 21, 17, 3};
    
    init_node(list);

    for(size_t i = 0; i < sizeof(test_data1) / sizeof(test_data1[0]); i++)
    {
        push_front_node(list, test_data1[i]);
        print_list(list);
        printf("To stdin:\n");
        print_list1(list, stdin);
        printf("To stdout:\n");
        print_list1(list, stdout);
    }

    Data sum = 0;

    foreach_node(list, sum_it_list, &sum);
    printf("Sum is %d\n", sum);
    list_clear(list);
}

void print_it_node(Data x, void *arg)
{
    fprintf((FILE*)arg, "%d ", x);
}

void print_list1(struct Node *list, FILE *fout)
{
    foreach_node(list, print_it_node, fout);
    fprintf(fout, "\n");
}

void foreach_node(struct Node *list, void (*func)(Data x, void *arg), void *arg)
{
    for(struct Node *ptr = list -> next; ptr != list; ptr = ptr -> next)
    {
        func(ptr -> data, arg);
    }

    printf("\n");
}

void sum_all(struct Node *list, Data *res)
{
    *res = 0;

    for(struct Node *ptr = list -> next; ptr != list; ptr = ptr -> next)
    {
        *res = *res + ptr -> data;
    }
}

void sum_it_list(Data x, void *a)
{
    Data *res = (Data *)a;
    *res = *res + x;
}