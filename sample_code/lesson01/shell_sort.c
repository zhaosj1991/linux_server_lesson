#include <stdio.h>
#include <string.h>

#define ARRAY_LENGTH   18

int shell_sort(int *data, int length)
{
    int gap = 0;
    int i = 0, j = 0;
    int temp = 0;

    for (gap = length / 2; gap >= 1; gap /= 2)
    {        
        for (i = 0; i < length; i++)
        {            
            for (j = i; j >= gap; j -= gap)
            {                
                if (data[j] < data[j - gap])
                {                    
                    temp = data[j];
                    data[j] = data[j - gap];
                    data[j - gap] = temp;
                }
                else
                {                    
                    break;
                }
                
            }
        }
    }

    return 0;
}

int insert_sort(int *data, int length)
{
    int i = 0, j = 0;
    int temp = 0;

    for (i = 0; i < length; i++)
    {
        for ( j = i; j > 0; j--)
        {
            if (data[j] < data[j - 1])
            {
                temp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }

    return 0;
}

int main()
{
    int i = 0;
    int data[ARRAY_LENGTH] = { 49, 20 , 7, 10 , 8, 32, 38, 647, 3464, 3, 13, 4, 5434, 64, 4, 13, 46, 4};

    shell_sort(data, ARRAY_LENGTH);
    for (i = 0; i < ARRAY_LENGTH; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}