#include <stdio.h>

void insertionsort(int array[], int length)
{
    int flag = 1;
    int key = array[flag];
    for (int idx = flag; idx < length; idx++)
    {
        printf("idx: %d\n", idx);
        for (int jdx = flag - 1; jdx >= 0; jdx--)
        {
            printf("    jdx: %d\n", jdx);
            if (array[jdx] >= key)
            {
                printf("    swapped: %d => %d\n", array[jdx], array[jdx + 1]);
                printf("    current array: ");
                for (int idx = 0; idx < length; idx++)
                {
                    printf("%d, ", array[idx]);
                };
                printf("\n");
                array[jdx + 1] = array[jdx];
                array[jdx] = key;
            }
        }
        flag++;
        key = array[flag];
    }
    for (int idx = 0; idx < length; idx++)
    {
        printf("%d, ", array[idx]);
    };
}

int main()
{
    int array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    insertionsort(array, 10);
}