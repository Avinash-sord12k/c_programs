#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decToBin(int num)
{
    int binary[32], i = 0;
    char *binStr = (char *)malloc(32 * sizeof(char));

    while (num > 0)
    {
        binary[i++] = num % 2;
        num /= 2;
    }

    // Convert binary array to string
    int j = 0;
    for (int k = i - 1; k >= 0; k--)
    {
        binStr[j++] = binary[k] + '0';
    }
    binStr[j] = '\0';

    return binStr;
}

// int main()
// {
//     int num = 10;
//     char* binStr = decToBin(num);
//     printf("%d in binary is %s\n", num, binStr);
//     free(binStr);
//     return 0;
// }

/// ====== accessing array values with different approaches ====
// int main()
// {
//     int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
//     int (*p)[4] = a;
//     printf("%d\n", p[1][2]);
//     printf("%d\n", *(p[1]+2));
//     printf("%d\n", *(*(p+1)+2));
//     printf("%p + 1 = %p\n", p, p+1);
//     printf("%p + 2 = %p\n", p, p+2);
//     return 0;
// }

//// ==== creating a 2d array ====
// int main() {
//     int l1 = 3;
//     int l2 = 3;
//     int a[l1][l2];
//     int i = 0, j = 0, k = 1;
//     while (i < l1) {
//         a[i][j] = k;
//         k++; j++;
//         if (j == l2) {
//             i++; j=0; continue;
//         }
//     }
//     for (i=0; i<l1; i++) {
//         for (j=0; j<l2; j++) {
//             printf("%d ", a[i][j]);
//             // printf("a[%d][%d] = %d ", i, j, a[i][j]);
//         }
//         printf("\n");
//     }
// }

// int main() {
//     int p, q, r;
//     p = 1 == (5 > 3);
//     printf("%d\n", p);
//     return 0;
// }

int main()
{
    // unsigned char a = 0xFA;
    // unsigned int a = -1;
    // printf("a = %d\n", a);
    // int a = 10, b = 20;
    // printf("%d\n", (a+1) & (b+1)); // 1
    // printf("%d\n", 10 ^ 21);
    // printf("%d\n", 1 | 1);

    // for (int i = 0; i<30; i++ ) {
    //     for (int idx=0; idx<30; idx++)
    //     {
    //     printf(" %d(%s) ^ %d(%s) = %d(%s)\n", i, decToBin(i), idx+1, decToBin(idx+1), i ^ (idx+1), decToBin(i ^ (idx+1)));
    //     }
    // }
    int a = 5, b = 3;
    for (int idx = 0; idx < 5; idx++)
    {
        for (int idx2 = 0; idx2 < 5; idx2++)
        {
            printf("%d(%s) << %d(%s) = %d(%s)\n", idx, decToBin(idx), idx2, decToBin(idx2), idx << idx2, decToBin(idx << idx2));
        }
    }
}