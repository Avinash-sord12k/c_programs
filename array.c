#include <stdio.h>
#include <stdlib.h>

void print_array(int* array, int length) {
    for (int idx=0; idx<length; idx++)
    {
        printf("\nelement at index %d is %d ", idx, array[idx]);
    }
}

int main()
{
    // defining array size
    int arraysize = 6;
    // creating array pointer and allocating memory as required for its elements
    int* array = (int*)malloc(sizeof(int) * arraysize);
    // filling array
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
    array[5] = 6;

    print_array(array, arraysize);

    return 0;
}