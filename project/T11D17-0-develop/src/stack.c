#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void pop_stack (struct stack **head);
void push_stack (struct stack **head, int x);
void print_stack (struct stack *head);
void init_stack (struct stack **head);

int main()
{
    struct stack *head;
    
    init_stack(&head);

    push_stack(&head, 1);
    print_stack(head);
    push_stack(&head, 2);
    print_stack(head);
    push_stack(&head, 3);
    print_stack(head);

    pop_stack(&head);
    print_stack(head);
}

void init_stack(struct stack **head)
{
    *head = NULL;
}

void push_stack(struct stack **head, int x)
{
    struct stack *ptr = malloc(sizeof(struct stack));
    ptr -> data = x;
    ptr -> next = *head;
    *head = ptr;
}

void pop_stack(struct stack **head)
{
    struct stack *ptr = *head;
    *head = ptr -> next;
    free(ptr);
}

void print_stack(struct stack *head)
{
    while (head != NULL)
    {
        printf("%d ", head -> data);
        head = head -> next;
    }

    printf("\n");
}