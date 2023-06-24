#include <stdio.h>

int addMatrix(int a[3][3], int b[3][3]) {
    for (int idx=0; idx<3; idx++)
    {
        for (int jdx=0; jdx<3; jdx++)
        {
            printf("%d ", a[idx][jdx] + b[idx][jdx]);
        }
        printf("\n");
    }
}

int submatrix(int a[3][3], int b[3][3]) {
    for (int idx=0; idx<3; idx++)
    {
        for (int jdx=0; jdx<3; jdx++)
        {
            printf("%d ", a[idx][jdx] - b[idx][jdx]);
        }
        printf("\n");
    }
}

int multmatrix(int a[3][3], int b[3][3]) {
    for (int idx=0; idx<3; idx++)
    {
        for (int jdx=0; jdx<3; jdx++)
        {
            int sum = 0;
            for (int kdx=0; kdx<3; kdx++)
            {
                sum = sum + a[idx][kdx] * b[kdx][jdx];
            }
            printf("%d ", sum);
        }
        printf("\n");
    }
}

int transposematrix(int a[3][3]) {
    for (int idx=0; idx<3; idx++)
    {
        for (int jdx=0; jdx<3; jdx++)
        {
            printf("%d ", a[jdx][idx]);
        }
        printf("\n");
    }
}

int printmatrix(int a[3][3]) {
    for (int idx=0; idx<3; idx++)
    {
        for (int jdx=0; jdx<3; jdx++)
        {
            printf("%d ", a[idx][jdx]);
        }
        printf("\n");
    }
}

int main()
{
    int a[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; 
    // write diffrent matrix of 3 * 3 size with different values
    int b[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printf("matrix a:\n");
    printmatrix(a);
    printf("matrix b:\n");
    printmatrix(b);
    printf("matrix addition: \n");
    addMatrix(a, b);
    printf("matrix subtraction: \n");
    submatrix(a, b);
    printf("matrix multiplication: \n");
    multmatrix(a, b);
    printf("matrix transpose: \n");
    transposematrix(a);
    return 0;

}