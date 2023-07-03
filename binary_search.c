#include <stdio.h>

int linearsearch(int array[], int length, int target)
{
    for (int idx = 0; idx < length; idx++)
    {
        if (array[idx] == target)
        {
            return idx;
        }
    }
    return -1;
}

int binarysearch(int array[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (array[mid] == target) return mid;
        if (array[mid] < target) left = mid + 1;
        if (array[mid] > target) right = mid - 1;
    }
    return -1;
}

int binarysearchwithrecursion(int array[], int left, int right, int target) {
    int mid = left + (right - left)/2;
    if (array[mid] == target) return mid;
    if (array[mid] < target) return binarysearchwithrecursion(array, mid + 1, right, target);
    if (array[mid] > target) return binarysearchwithrecursion(array, left, mid - 1, target);
    return -1;
}

int main()
{
    int arr[] = {1, 2, 4, 5, 6, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int result = binarysearchwithrecursion(arr, 0, n - 1, target);

    if (result != -1)
    {
        printf("Element %d found at index %d\n", target, result);
    }
    else
    {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}