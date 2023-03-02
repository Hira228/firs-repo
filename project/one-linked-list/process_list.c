void push_element_list(struct Node **plist, Data x)
{
    struct Node *ptr = malloc(sizeof(struct Node));
    ptr -> data = x;
    ptr -> next = *plist;
    *plist = ptr;
}

void pop_element_list(struct Node **plist)
{
    struct Node *ptr = *plist;
    *plist = ptr -> next;
    free(ptr);
}

void print_element_list(struct Node *plist)
{
    while(plist != NULL)
    {
        printf("%d ", plist -> data);
        plist = plist -> next;
    }
    printf("\n");
}
