/// creating a matrix with array and rows and columns
#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int length)
{
    for (int idx = 0; idx < length; idx++)
    {
        printf("\nelement at index %d is %d ", idx, array[idx]);
    }
}

int **createMatrix(int *array, int cols, int rows)
{
    int **matrix = (int **)malloc(sizeof(int *) * rows);
    for (int idx = 0; idx < rows; idx++)
    {
        int *r = (int *)malloc(sizeof(int) * cols);
        matrix[idx] = r;
    }
    for (int idx = 0; idx < rows; idx++)
    {
        for (int idx2 = 0; idx2 < cols; idx2++)
        {
            matrix[idx][idx2] = array[idx * rows + idx2];
        }
    }
    return matrix;
}

void printMatrix(int **matrix, int cols, int rows)
{
    for (int idx = 0; idx < rows; idx++)
    {   
        printf("|");
        for (int idx2 = 0; idx2 < cols; idx2++)
        {
            printf("%d ", matrix[idx][idx2]);
        }
        printf("|\n");
    }
}

int main()
{
    int rows = 3, cols = 3;
    int *array = (int *)malloc(sizeof(int) * (rows * cols));
    for (int idx = 0; idx < rows * cols; idx++)
    {
        array[idx] = idx;
    }
    int **matrix = createMatrix(array, cols, rows);
    printMatrix(matrix, cols, rows);
    for (int idx = 0; idx < rows; idx++)
    {
        free(matrix[idx]);
    }
    free(matrix);
    free(array);
    return 0;
}