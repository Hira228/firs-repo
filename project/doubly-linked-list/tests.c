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

