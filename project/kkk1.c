#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *input_array(int *ptr, int *size);
int twoSum(int *ptr, int size, int target, int *x, int *y);

int main()
{
    char strs[3][20] = {{"flower"}, {"flow"}, {"flight"}};
    
    int strsSize = 3;

    char *str = NULL;
    int flag_null = 0;
    int flag = 0;
    int number = 0;
    
    size_t strs_size_min = strlen(strs[0]); 
    
    for (int i = 1; i < strsSize; i++)
    {
        if (strs_size_min > strlen(strs[i]))
        {
            strs_size_min = strlen(strs[i]);
            number = i;
        }
    }
    
    int total = 0;

    for (size_t i = 0; i < strs_size_min && flag != 1; i++)
    {   
            for(int k = 0; k < strsSize  && flag != 1; k++)
            {
                if(strs[number][i] != strs[k][i])
                {
                    if(k == 0)
                    {
                        flag_null = 1;
                    }

                    flag = 1;
                }
            }
            if(flag != 1)
            {
                str = realloc(str, sizeof(char) * (total + 1));
                str[i] = strs[number][i];
                total++;   
            }    
    } 
            
    if (flag_null == 1)
    {
        str[0] = '\0';
    }
      for(int i = 0; i < total; i++)
        {
            printf("%c\n",str[i]);
        }

        

free(str);
return 0;
}
