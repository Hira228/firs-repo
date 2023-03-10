#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    struct door d = {1, 1};

    struct door *door = &d;
    struct node *elem = NULL;
    elem = add_door(elem, door);
    printf("%d %d\n", elem -> door.id, elem -> door.status);

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
    ptr -> next = elem;
    ptr -> door.id = door -> id;
    ptr -> door.status = door -> status;
    elem = ptr;
    return elem;
}

struct node *find_door(int door_id, struct node *root)
{

}

void destroy(struct node* root)
{

}