#include <stdio.h>
#include <math.h>

int getDigits(int number)
{
    int remainder = number / 10;
    int digits = 1;
    if (remainder > 0)
    {
        digits += getDigits(remainder);
    }
    return digits;
}

int max(int array[], int length)
{
    int maxNum = array[0];
    for (int idx = 1; idx < length; idx++)
    {
        (array[idx] > maxNum) ? maxNum = array[idx] : 0;
    }
    return maxNum;
}

void printMatrixWithAlignment(int matrix[], int rows, int cols, int spacing)
{
    int columnMaxWidthArray[cols];
    int colWidth[rows];

    for (int idx = 0; idx < cols; idx++)
    {
        for (int idx2 = 0; idx2 < rows; idx2++)
        {
            colWidth[idx2] = getDigits(matrix[idx2 * cols + idx]);
        }
        columnMaxWidthArray[idx] = max(colWidth, rows);
    }

    for (int idx = 0; idx < rows; idx++)
    {
        for (int idx2 = 0; idx2 < cols; idx2++)
        {
            // printf("%d[%d]", matrix[idx * cols + idx2], columnMaxWidthArray[idx2] + spacing - getDigits(matrix[idx*rows+idx2]));
            // printf("%d[%d]", matrix[idx * cols + idx2], columnMaxWidthArray[idx2]);
            printf("%d", matrix[idx * cols + idx2]);
            for (int idx3 = 0; idx3 < columnMaxWidthArray[idx2] + spacing - getDigits(matrix[idx*cols+idx2]); idx3++)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void printArray(int *array, int length)
{
    for (int idx = 0; idx < length; idx++)
    {
        printf("\nelement at index %d is %d ", idx, array[idx]);
    }
}

int main()
{
    int rows = 50, cols = 20;
    int matrix[rows * cols];
    for (int idx = 0; idx < rows * cols; idx++)
    {
        matrix[idx] = idx + 1;
    }
    
    printMatrixWithAlignment(matrix, rows, cols, 1);
    // printArray(matrix, rows*cols);
    printf("\n");
    return 0;
}