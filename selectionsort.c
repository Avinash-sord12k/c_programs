#include <stdio.h>


void swap(int array[], int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void selection_sort(int array[], int length) {
    int temp_minimum_index = 0;
    for (int flag = 0; flag < length - 1; flag++) {
        for (int idx = flag; idx < length; idx++) {
            if (array[idx] < array[temp_minimum_index]) {
                temp_minimum_index = idx;
            }
        }
        swap(array, flag, temp_minimum_index);
    } 

    for (int idx=0; idx<length; idx++)
    {
        printf("%d, ", array[idx]);
    }
}


int main()
{
    int array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2 ,1};
    selection_sort(array, 10);
    return 0;
}