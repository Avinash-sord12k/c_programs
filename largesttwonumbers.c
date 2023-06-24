#include <stdio.h>

int main()
{
    int array[11] = {1, 2, 3, 4, 5, 60, 29, 7, 8, 9, 10};
    int largest = array[0];
    int secondlargest = array[1];

    for (int idx=0; idx<sizeof(array)/sizeof(int); idx++)
    {
        if (array[idx] > largest)
        {
            secondlargest = largest;
            largest = array[idx];
        }
        else if (array[idx] > secondlargest)
        {
            secondlargest = array[idx];
        }
    }
    printf("array is: ");
    for (int idx=0; idx<sizeof(array)/sizeof(int); idx++)
    {
        printf("%d ", array[idx]);
    }
    printf("\nlargest = %d\n", largest);
    printf("secondlargest = %d\n", secondlargest);

}