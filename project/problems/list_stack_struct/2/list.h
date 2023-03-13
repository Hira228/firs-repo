#include "door_struct.h"

struct node{
    struct node *next;
    struct door door;
};

void init (struct door *door);
void add_door(struct node **elem, struct door *door);
struct node *find_door(int door_id, struct node *root);
void destroy(struct node** root);
void print_list(struct node *elem);
int list_is_empty(struct node *elem);
void insert(struct node *elem, int n, int value);
