#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    struct door first_elem = {1, 0};
    struct door tests[] = {{1, 0}, {2, 0}, {3, 0}, {4, 0}};
    struct node *new_insert_elem = NULL;
    struct door *door = &first_elem;
    struct node *elem = NULL;
    struct node *find_elem = NULL;
    int id = 3;

    printf("Состояние списка :%s\n", list_is_empty(elem) ? "Список пуст\n" : "Список не пуст\n");

    printf("Состояние списка :%s\n", list_is_empty(elem) ? "Список пуст\n" : "Список не пуст\n");
    print_list(elem);

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        door = &tests[i];
        add_door(&elem, door);
        printf ("Добавлен новый элемент списка: %d %d\n", elem -> door.id, elem -> door.status);  // Вывод добавленного элемента door в список  1 2 | 3 4 | 5 6
    }
    
    printf ("\n");
    printf("Вывод всего спиcка:\n");
    print_list(elem);
    
    
    printf ("\n");
    printf("Поиск двери по id:\n");
    
    find_elem = find_door(id, elem);
    find_elem == NULL ? printf("Двери с таким id не найдено\n") : printf("Дверь находится в списке, ее id: %d\n", find_elem -> door.id);

    printf("\n");

    destroy(&elem);

 
    insert(elem, 0, 111);
    print_list(elem);
}

int list_is_empty(struct node *elem)
{
    return elem == NULL;
}

void init (struct door *door)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr -> door.id = door -> id;
    ptr -> door.status = door -> status;
    ptr -> next = NULL;
}

void print_list(struct node *elem)
{
    while (elem != NULL)
    {
        printf ("|%d %d|\n\n", elem -> door.id, elem -> door.status);  // Вывод всего списка дверей |5 6||3 4||1 2|
        elem = elem -> next;
    }
} 

void add_door (struct node **elem, struct door *door)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr -> next = *elem;
    ptr -> door.id = door -> id;
    ptr -> door.status = door -> status;
    *elem = ptr;
}

struct node  *find_door(int door_id, struct node *root)
{
    while (root -> door.id != door_id)
    {
        root = root -> next;
    }
    return root;
}

void destroy(struct node** root)
{
    struct node *ptr = *root;
    *root = ptr -> next;
    printf("Удален элемент списка:\n\n|%d %d|\n\n", ptr -> door.id, ptr -> door.status);
    printf("Вывод всего списка: \n");
    print_list(*root);
    printf("Состояние списка :%s\n", list_is_empty(*root) ? "Список пуст\n" : "Список не пуст\n");
    free(ptr);
}

void insert(struct node *elem, int n, int value)
{
    int i = 0;
    
    while (i < n && elem -> next != NULL)
    {
        elem = elem -> next;
        i++;
    }

    struct node *ptr = malloc(sizeof(struct node));
    ptr -> door.id = value;
    ptr -> door.status = 0;

    if(elem -> next != NULL)
    {
        ptr -> next = elem -> next;
    }
    else
    {
        ptr -> next = NULL;
    }
    elem -> next = ptr;
}