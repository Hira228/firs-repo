//Пытаюсь разобраться со структурами и односвязными списками :))

#include <stdio.h>
typedef int Data;  //Тип Data int
// void push (struct Node **list, Data x);
// Data pop(struct Node **list);

struct Node
    {
        Data data;  //data типа Data
        struct Node *next;   // Указатель на слудющий элемент в списке типа указатель на струтуру
    }Node;
    

int main()
{
    struct Node *list = NULL;  // lits зразу указывает на конец списка (Сначала список пуст)
    struct Node a = {3}, b = {17}, c = {21}, t = {10};
    struct Node *list = &a;
    
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    return 0;
}

// void push (struct Node **list, Data x)
// {

// }
// Data pop(struct Node **list)
// {

// }