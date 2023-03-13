#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "function_tree.h"

int main()
{
    struct Node *tree = NULL;   // Указатель на корень
    Data tests_data[] = {7, 3, 2, 1, 9, 5, 4, 6};

    for (size_t i = 0; i < sizeof(tests_data) / sizeof(tests_data[0]); i++)
    {
        tree = add_tree(tree, tests_data[i]);
        print(tree);
    }

}

void print_tree(struct Node *tree)
{
    //Дерево пустое

    if (tree == NULL)
    {
        return;
    }

    //Дерево не пустое

    print_tree(tree -> left);
    printf("%d ", tree -> data);
    print_tree(tree -> right);
}

void print(struct Node *tree)

{
    print_tree(tree);
    printf("\n");
}

struct Node *add_tree(struct Node *tree, Data x)
{
    if (tree == NULL)
    {
        struct Node *ptr = malloc(sizeof(struct Node));
        ptr -> data = x;
        ptr -> left = ptr -> right = NULL;
        print(tree);
        return ptr;
    }

    if (x < tree -> data)
    {
        tree -> left = add_tree(tree -> left, x);
    }

    if(x > tree -> data)
    {
        tree -> right = add_tree(tree -> right, x);
    }
    return tree;
}