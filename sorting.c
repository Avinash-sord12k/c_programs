#include <stdio.h>
#include <time.h>

void printarraywithcaption(int array[], int length, char caption[]) {
    printf("%s\n", caption);
    for (int idx=0; idx<10; idx++)
    {
        printf("%d ", array[idx]);
    }
    printf("\n");
}

void make_array_copy(int source_array[], int copy_array[], int length) {
    for (int idx=0; idx<length; idx++)
    {
        copy_array[idx] = source_array[idx];
    }
}

void bubblesort(int given_array[], int length)
{
    // traverse from left and compare adjacent elements and the higher one is placed at right side.
    // In this way, the largest element is moved to the rightmost end at first.
    // This process is then continued to find the second largest and place it and so on until the data is sorted.
    int array[length];
    make_array_copy(given_array, array, length);
    printarraywithcaption(array, length, "\nBubble sort\nunsorted array");
    clock_t initial = clock(), final;
    for (int idx = 0; idx < length; idx++)
    {
        for (int jdx = 0; jdx < length - 1; jdx++)
        {
            if (array[jdx] > array[jdx + 1])
            {
                int temp = array[jdx];
                array[jdx] = array[jdx + 1];
                array[jdx + 1] = temp;
            }
        }
    }
    final = clock();
    double time_taken = (((double)(final - initial)) / CLOCKS_PER_SEC) * 1000000;
    printarraywithcaption(array, length, "sorted array");
    printf("time taken: %.1fus\n", time_taken);
}

int sorted(int array[], int length, int sortedIndex)
{
    if (sortedIndex > length)
    {
        printf("sorted part index is greated than length.");
        return 0;
    }
    else if (!sortedIndex)
    {
        return 1;
    };
    int last = array[0];
    for (int idx = 1; idx <= sortedIndex; idx++)
    {
        if (array[idx] < last)
        {
            return 0;
        }
        last = array[idx];
    }
    return 1;
}

void insertionsort(int given_array[], int length)
{   
    int array[length];
    make_array_copy(given_array, array, length);
    printarraywithcaption(array, length, "\nInsertion sort \nsorted array");
    int currentIndex, previousIndex, key;
    clock_t initial = clock(), final;
    // Start from the second element
    for (currentIndex = 1; currentIndex < length; currentIndex++) {
        // Select the currentIndex element to be inserted at the correct position 
        key = array[currentIndex];
        previousIndex = currentIndex - 1;

        // Move elements that are greater than the key to one position ahead: shifting the sorted subarray elements to make space for our key
        // of their currentIndex position
        while (previousIndex >= 0 && array[previousIndex] > key) {
            array[previousIndex + 1] = array[previousIndex];
            previousIndex = previousIndex - 1;
        }
        // Place the key at its correct position : the process of insertion
        array[previousIndex + 1] = key;
    }
    final = clock();
    double time_taken = (((double)(final - initial)) / CLOCKS_PER_SEC) * 1000000;
    printarraywithcaption(array, length, "sorted array");
    printf("time taken: %.1fus\n", time_taken);
}

void selectionsort(int given_array[], const int length) {
    // make a traversal key : starts from 0.
    // find the smallest element
    // swap it with key.  
    int array[length];
    make_array_copy(given_array, array, length);
    printarraywithcaption(array, length, "\nSelection sort\nunsorted array");
    int key, min_index;
    clock_t initial = clock(), final;
    for (int idx=0; idx<length-1; idx++)
    {
        key = array[idx];
        min_index = idx+1;
        for (int jdx=idx+1; jdx<length; jdx++) {
            if (array[jdx]<array[min_index]) {
                min_index = jdx;
            }
        }
        if (array[min_index] < key) {
            // perform swap
            array[idx] = array[min_index];
            array[min_index] = key;
        }
        
    }
    final = clock();
    double time_taken = (((double)(final - initial)) / CLOCKS_PER_SEC) * 1000000;
    printarraywithcaption(array, length, "sorted array");
    printf("time taken: %.1fus\n", time_taken);
} 

int main()
{
    int unsortedarray[] = {
    41, 22, 34, 70, 89, 77, 9, 19, 23, 44, 96, 40, 39, 94, 61, 65, 53, 2, 31, 96,
    34, 81, 95, 86, 76, 48, 21, 68, 40, 32, 84, 33, 18, 9, 38, 25, 78, 1, 91, 93,
    86, 99, 25, 90, 0, 15, 30, 99, 63, 87, 16, 85, 16, 35, 71, 48, 22, 71, 93, 98,
    36, 20, 89, 61, 4, 94, 76, 48, 30, 33, 65, 77, 8, 66, 53, 3, 44, 56, 39, 6,
    19, 1, 45, 88, 72, 56, 43, 71, 87, 49, 72, 70, 46, 76, 37, 54, 16, 9, 62, 14,
    99, 92, 98, 17, 74, 96, 61, 53, 16, 17, 16, 38, 69, 92, 91, 53, 11, 57, 22, 33,
    77, 60, 50, 5, 67, 38, 90, 55, 57, 83, 39, 46, 5, 23, 70, 59, 2, 88, 71, 85,
    97, 31, 93, 80, 45, 57, 18, 16, 18, 43, 33, 9, 70, 82, 92, 94, 64, 42, 30, 64,
    22, 55, 10, 3, 35, 9, 46, 30, 40, 61, 27, 48, 10, 94, 41, 94, 95, 78, 23, 21,
    46, 40, 39, 97, 99, 19, 29, 48, 7, 63, 45, 16, 22, 94, 72, 68, 43, 66, 80, 12,
    55, 72, 33, 57, 15, 30, 69, 61, 92, 58, 37, 25, 23, 33, 84, 29, 61, 7, 12, 54,
    84, 50, 51, 95, 64, 94, 0, 33, 70, 12, 13, 1, 82, 73, 49, 100, 38, 17, 2,
    41, 22, 34, 70, 89, 77, 9, 19, 23, 44, 96, 40, 39, 94, 61, 65, 53, 2, 31, 96,
    34, 81, 95, 86, 76, 48, 21, 68, 40, 32, 84, 33, 18, 9, 38, 25, 78, 1, 91, 93,
    86, 99, 25, 90, 0, 15, 30, 99, 63, 87, 16, 85, 16, 35, 71, 48, 22, 71, 93, 98,
    36, 20, 89, 61, 4, 94, 76, 48, 30, 33, 65, 77, 8, 66, 53, 3, 44, 56, 39, 6,
    19, 1, 45, 88, 72, 56, 43, 71, 87, 49, 72, 70, 46, 76, 37, 54, 16, 9, 62, 14,
    99, 92, 98, 17, 74, 96, 61, 53, 16, 17, 16, 38, 69, 92, 91, 53, 11, 57, 22, 33,
    77, 60, 50, 5, 67, 38, 90, 55, 57, 83, 39, 46, 5, 23, 70, 59, 2, 88, 71, 85,
    97, 31, 93, 80, 45, 57, 18, 16, 18, 43, 33, 9, 70, 82, 92, 94, 64, 42, 30, 64,
    22, 55, 10, 3, 35, 9, 46, 30, 40, 61, 27, 48, 10, 94, 41, 94, 95, 78, 23, 21,
    46, 40, 39, 97, 99, 19, 29, 48, 7, 63, 45, 16, 22, 94, 72, 68, 43, 66, 80, 12,
    55, 72, 33, 57, 15, 30, 69, 61, 92, 58, 37, 25, 23, 33, 84, 29, 61, 7, 12, 54,
    84, 50, 51, 95, 64, 94, 0, 33, 70, 12, 13, 1, 82, 73, 49, 100, 38, 17, 2,
    41, 22, 34, 70, 89, 77, 9, 19, 23, 44, 96, 40, 39, 94, 61, 65, 53, 2, 31, 96,
    34, 81, 95, 86, 76, 48, 21, 68, 40, 32, 84, 33, 18, 9, 38, 25, 78, 1, 91, 93,
    86, 99, 25, 90, 0, 15, 30, 99, 63, 87, 16, 85, 16, 35, 71, 48, 22, 71, 93, 98,
    36, 20, 89, 61, 4, 94, 76, 48, 30, 33, 65, 77, 8, 66, 53, 3, 44, 56, 39, 6,
    19, 1, 45, 88, 72, 56, 43, 71, 87, 49, 72, 70, 46, 76, 37, 54, 16, 9, 62, 14,
    99, 92, 98, 17, 74, 96, 61, 53, 16, 17, 16, 38, 69, 92, 91, 53, 11, 57, 22, 33,
    77, 60, 50, 5, 67, 38, 90, 55, 57, 83, 39, 46, 5, 23, 70, 59, 2, 88, 71, 85,
    97, 31, 93, 80, 45, 57, 18, 16, 18, 43, 33, 9, 70, 82, 92, 94, 64, 42, 30, 64,
    22, 55, 10, 3, 35, 9, 46, 30, 40, 61, 27, 48, 10, 94, 41, 94, 95, 78, 23, 21,
    46, 40, 39, 97, 99, 19, 29, 48, 7, 63, 45, 16, 22, 94, 72, 68, 43, 66, 80, 12,
    55, 72, 33, 57, 15, 30, 69, 61, 92, 58, 37, 25, 23, 33, 84, 29, 61, 7, 12, 54,
    84, 50, 51, 95, 64, 94, 0, 33, 70, 12, 13, 1, 82, 73, 49, 100, 38, 17, 2,
    84, 50, 51, 95, 64, 94, 0, 33, 70, 12, 13, 1, 82, 73, 49, 100, 38, 17, 2,
    41, 22, 34, 70, 89, 77, 9, 19, 23, 44, 96, 40, 39, 94, 61, 65, 53, 2, 31, 96,
    34, 81, 95, 86, 76, 48, 21, 68, 40, 32, 84, 33, 18, 9, 38, 25, 78, 1, 91, 93,
    86, 99, 25, 90, 0, 15, 30, 99, 63, 87, 16, 85, 16, 35, 71, 48, 22, 71, 93, 98,
    36, 20, 89, 61, 4, 94, 76, 48, 30, 33, 65, 77, 8, 66, 53, 3, 44, 56, 39, 6,
    19, 1, 45, 88, 72, 56, 43, 71, 87, 49, 72, 70, 46, 76, 37, 54, 16, 9, 62, 14,
    99, 92, 98, 17, 74, 96, 61, 53, 16, 17, 16, 38, 69, 92, 91, 53, 11, 57, 22, 33,
    77, 60, 50, 5, 67, 38, 90, 55, 57, 83, 39, 46, 5, 23, 70, 59, 2, 88, 71, 85,
    97, 31, 93, 80, 45, 57, 18, 16, 18, 43, 33, 9, 70, 82, 92, 94, 64, 42, 30, 64,
    22, 55, 10, 3, 35, 9, 46, 30, 40, 61, 27, 48, 10, 94, 41, 94, 95, 78, 23, 21,
    46, 40, 39, 97, 99, 19, 29, 48, 7, 63, 45, 16, 22, 94, 72, 68, 43, 66, 80, 12,
    55, 72, 33, 57, 15, 30, 69, 61, 92, 58, 37, 25, 23, 33, 84, 29, 61, 7, 12, 54,
    84, 50, 51, 95, 64, 94, 0, 33, 70, 12, 13, 1, 82, 73, 49, 100, 38, 17, 2,
    46, 40, 39, 97, 99, 19, 29, 48, 7, 63, 45, 16, 22, 94, 72, 68, 43, 66, 80, 12,
    46, 40, 39, 97, 99
    };

    bubblesort(unsortedarray, 1000);
    insertionsort(unsortedarray, 1000);
    selectionsort(unsortedarray, 1000);
}