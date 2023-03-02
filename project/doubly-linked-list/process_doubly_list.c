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
