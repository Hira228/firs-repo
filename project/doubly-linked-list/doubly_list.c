//Пытаюсь разобраться со структурами и двусвязными списками :))
// Двусвязный циклический список с барьерным элементом


#include <stdio.h>
#include <stdlib.h>
#include "list_doubly.h"
#include "function_doubly_list.h"
#include "process_doubly_list.c"
#include "tests.c"

int main()
{
    #ifdef test1
    test_without_alloc();
    #endif

    #ifdef test2
    test_alloc_node();
    #endif

    #ifdef test3
    test_foreach_node();
    #endif
    
    return 0;
}


