#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{

    struct door *door = NULL;
    struct node *elem = NULL;
    elem = add_door(elem, door);
    printf("%d", elem -> door.status);

    //scanf("%d", &(door -> status));
    //elem = add_door(elem, door);

    // while (elem != NULL)
    // {
    //     printf("%d", elem -> door.status);
    //     elem = elem -> next;
    // }
}

struct node *init (struct door *door)
{

}

struct node *add_door (struct node *elem, struct door *door)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr -> door.status = 12;
    ptr -> next = elem;
    elem = ptr;
    return elem;
}

struct node *find_door(int door_id, struct node *root)
{

}

void destroy(struct node* root)
{

}