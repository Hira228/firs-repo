#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "function_tree.h"

int main()
{
    struct Node
        one =   {1, NULL, NULL},
        two =   {2, NULL, NULL},
        three = {3, NULL, NULL},
        five =  {5, NULL, NULL},
        six =   {6, NULL, NULL},
        seven = {7, NULL, NULL},
        eight = {8, NULL, NULL},
        nine =  {9, NULL, NULL};

    struct Node *tree = NULL;   // Указатель на корень
    tree = &seven;
    seven.left = &three;
    seven.right = &nine;
    three.left = &two;
    two.left = &one;
    three.right = &five;
    nine.left = &eight;
    
    print(tree);
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