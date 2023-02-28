//Пытаюсь разобраться со структурами и односвязными списками :))

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void push_element_list(struct Node **plist, Data x);
void pop_element_list(struct Node **plist);
void print_element_list(struct Node *plist);

int main()
{
    struct Node *list = NULL;
    Data *array = NULL;
    Data n = 0;
    Data element = 0;
    char c;
    while (scanf("%d%c", &element, &c) == 1 || c != '\n')
    {
        array = realloc(array, sizeof(Data) * (n + 1));
        array[n] = element;
        n++;
    }

    for (size_t i = 0; i < n; i++)
    {
        push_element_list(&list, array[i]);
        print_element_list(list);
    }

    while(list != NULL)
    {
        pop_element_list(&list);
        print_element_list(list);
    }
    free(array);
}


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