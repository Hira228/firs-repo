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
    Data test[] = {21, 17, 3, 10};
    struct Node *list = NULL;  // lits зразу указывает на конец списка (Сначала список пуст)
    
    for(size_t i = 0; i < sizeof(test) / sizeof(test[0]); i++)
    {
        push(&list, test[i]);
        print_list(list);
    }

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
