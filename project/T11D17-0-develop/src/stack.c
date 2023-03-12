#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void pop_stack (struct stack **head);
void push_stack (struct stack **head, int x);
void print_stack (struct stack *head);
void init_stack (struct stack **head);

int main()
{
    int count = 0;
    struct stack *head = malloc(sizeof(struct stack));
    
    init_stack(&head);

    push_stack(&head, 1);  // Добавляем в стек 1
    print_stack(head);     // 1
    push_stack(&head, 2);  // Добавляем в стек 2
    print_stack(head);     // 1 2
    push_stack(&head, 3);  // Добавляем в стек 3
    print_stack(head);     // 1 2 3

    pop_stack(&head);      // Удаляем из стека последний элемент
    print_stack(head);     // 1 2
   
}

void init_stack(struct stack **head)
{
    (*head) -> counter = -1;
}

void push_stack(struct stack **head, int x)
{
    (*head) -> counter++;
    (*head) -> ptr[(*head) -> counter] = x;
}

void pop_stack(struct stack **head)
{
    (*head) -> counter--;
}

void print_stack(struct stack *head)
{
    int i = 0;
    while (i <= head -> counter)
    {
        printf("%d ", head -> ptr[i]);
        i++;
    }

    printf("\n");
}