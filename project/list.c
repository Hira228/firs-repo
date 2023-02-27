//Пытаюсь разобраться со структурами и односвязными списками :))

#include <stdio.h>
#include <stdlib.h>
typedef int Data;  //Тип Data int

struct Node
    {
        Data data;  //data типа Data
        struct Node *next;   // Указатель на слудющий элемент в списке типа указатель на струтуру
    }Node;


void push (struct Node **list, Data x);
void print_list(struct Node *list);    
int is_empty(struct Node *list);
Data pop(struct Node **list);

int main()
{
    Data test[] = {21, 17, 3, 10};
    
    struct Node *list = NULL;  // lits зразу указывает на конец списка (Сначала список пуст)
    
    printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");
    
    for(size_t i = 0; i < sizeof(test) / sizeof(test[0]); i++)
    {
        push(&list, test[i]);
        print_list(list);
    }
    
    printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");

    while (!is_empty(list))
    {
        Data x = pop(&list);
        printf("pop: %d ", x);
        print_list(list);
    }

    return 0;
}

int is_empty(struct Node *list)
{
    return list == NULL;
}

void print_list(struct Node *list)
{
    for(struct Node *p = list;p != NULL;p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

void push (struct Node **list, Data x)
{
    struct Node *p = malloc(sizeof(struct Node));
    p -> data = x;
    p->next = *list;
    *list = p;
}
Data pop(struct Node **list)
{
    struct Node *p = *list;
    Data res = p->data;
    *list = p->next;
    free(p);
    return res;
}
