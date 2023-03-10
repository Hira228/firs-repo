#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    struct door tests[] = {{1, 1}, {2, 2}, {3, 3}};
    struct door *door = NULL;
    struct node *elem = NULL;
    
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        door = &tests[i];
        elem = add_door(elem, door);
        printf("%d %d\n", elem -> door.id, elem -> door.status);
    }
    
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