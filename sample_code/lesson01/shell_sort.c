#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int shell_sort(int *data, int length)
{
    int gap = 0;
    int i = 0, j = 0;
    int temp = 0;

    for (gap = length / 2; gap >= 1; gap /= 2)
    {        
        for (i = gap; i < length; i++)
        {            
            temp = data[i];
            for (j = i - gap; j >= 0 && temp < data[j]; j -= gap)
            {
                data[j+gap] = data[j];
            }
            data[j+gap] = temp;
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
        temp = data[i];
        for (j = i-1; j >= 0 && temp < data[j]; j--)
        {
            data[j+1] = data[j];
        }
        data[j+1] = temp;
    }

    return 0;
}

#define ARRAY_LENGTH   18

int main()
{
    int i = 0;
    int data[18] = { 49, 20 , 7, 10 , 8, 32, 38, 647, 3464, 3, 13, 4, 5434, 64, 4, 13, 46, 4};
    int *data_copy1 = (int *) malloc(ARRAY_LENGTH * sizeof(int));
    int *data_copy2 = (int *) malloc(ARRAY_LENGTH * sizeof(int));
    memcpy(data_copy1, data, ARRAY_LENGTH * sizeof(int));
    memcpy(data_copy2, data, ARRAY_LENGTH * sizeof(int));

    insert_sort(data_copy1, ARRAY_LENGTH);
    for (i = 0; i < ARRAY_LENGTH; i++)
    {
        printf("%d ", data_copy1[i]);
    }
    printf("\n");

    shell_sort(data_copy2, ARRAY_LENGTH);
    for (i = 0; i < ARRAY_LENGTH; i++)
    {
        printf("%d ", data_copy2[i]);
    }
    printf("\n");

    free(data_copy1);
    free(data_copy2);
}