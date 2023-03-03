//Пытаюсь разобраться со структурами и односвязными списками :))

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "function_list.h"
#include "process_list.c"

int main()
{
    struct Node *list = NULL;
    Data *array = NULL;
    Data n = 0;
    Data element = 0;
    char c;
    while (scanf("%d%c", &element, &c) == 1 || c != '\n')
    {
        array = realloc(array, sizeof(Data) * (n + 1));
        array[n] = element;
        n++;
    }

    for (size_t i = 0; i < n; i++)
    {
        push_element_list(&list, array[i]);
        print_element_list(list);
    }

    while(list != NULL)
    {
        pop_element_list(&list);
        print_element_list(list);
    }
    free(array);
}

//разобрался с push pop print ;)