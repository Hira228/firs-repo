#include "door_struct.h"

struct node *init (struct door *door);
struct node *add_door (struct node *elem, struct door *door);
struct node *find_door(int door_id, struct node *root);
void destroy(struct node* root);

struct node{
    struct node *next;
    struct door door;
};