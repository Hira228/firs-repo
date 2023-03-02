
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
void test_without_alloc();

