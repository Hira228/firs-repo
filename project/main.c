#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int *input_array(int *ptr, int *size);
int twoSum(int *ptr, int size, int target, int *x, int *y);

int main()
{
    // int m = 0, n = 0;
    // int target = 0;
    // int size = 0;
    // int *ptr = NULL;
    char strs[3][10] = {{"sdsd"}, {"dsdsd"}, {"dsds"}};
    for(int i = 0; i < 3; i++)
    {

        printf("%ld\n", strlen(strs[i]));
    }
    // ptr = input_array(ptr, &size);
    
    // scanf ("%d", &target);
    // twoSum(ptr, size, target, &m, &n);
    // printf("%d,%d\n", m, n);
    // free(ptr);
    
    return 0;
}

// int twoSum(int *ptr, int size, int target, int *x, int *y)
// {   
//     int flag = 0;
    
//     for (int i = 0; i < size  && flag != 1; i++)
//     {
        
//         for (int j = 0; j < size && flag != 1; j++)
//         {
//             if(ptr[i] + ptr[j] == target && i != j)
//             {
//                 *x = i;
//                 *y = j;
//                 flag = 1;
//             }
//         }
//     }
//     return 0;
// }

// int *input_array(int *ptr, int *size)
// {
//     int x = 0;
//     char c;
//     while (scanf("%d%c", &x, &c) == 2 && c == ' ')
//     {
//         ptr = realloc(ptr, sizeof(int) * ((*size) + 1));
//         ptr[*size] = x;
//         (*size)++;
//     }
    
//     return ptr;
// }







