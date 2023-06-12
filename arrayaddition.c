#include <stdio.h>
#include <stdlib.h>


int *sumArrays(int arr1[], int arr2[], int size1, int size2, int *size3)
{
    int i, j, k;
    int *result = NULL;

    // Calculate the size of the result array
    *size3 = size1 + size2;

    // Allocate memory for the result array
    result = (int *)malloc(*size3 * sizeof(int));

    // Copy the elements of arr1 to the result array
    for (i = 0; i < size1; i++)
    {
        result[i] = arr1[i];
    }

    // Add the elements of arr2 to the result array, avoiding duplicates
    for (i = 0; i < size2; i++)
    {
        for (j = 0, k = size1; j < size1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                break;
            }
        }
        if (j == size1)
        {
            result[k] = arr2[i];
            k++;
        }
    }

    // Resize the result array to remove unused memory
    result = (int *)realloc(result, k * sizeof(int));

    // Return the result array and update the size
    *size3 = k;
    return result;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 4, 5, 6, 7, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int *result, size3, i;

    result = sumArrays(arr1, arr2, size1, size2, &size3);

    printf("Resulting array:\n");
    for (i = 0; i < size3; i++)
    {
        printf("%d ", result[i]);
    }

    free(result);

    return 0;
}