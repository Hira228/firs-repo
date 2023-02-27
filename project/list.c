//Пытаюсь разобраться со структурами и односвязными списками :))

#include <stdio.h>
#include <stdlib.h>
typedef int Data;  //Тип Data int
// Data pop(struct Node **list);

struct Node
    {
        Data data;  //data типа Data
        struct Node *next;   // Указатель на слудющий элемент в списке типа указатель на струтуру
    }Node;

void push (struct Node **list, Data x);
void print_list(struct Node *list);    

int main()
{
    struct Node *list = NULL;  // lits зразу указывает на конец списка (Сначала список пуст)
    struct Node a = {3}, b = {17}, c = {21}, t = {10};
    list = &a;
    
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    print_list(list);

    push(&list, 111);

    print_list(list);
    return 0;
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
// Data pop(struct Node **list)
// {

// }