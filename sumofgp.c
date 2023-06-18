#include <stdio.h>

float power(int base, int exponent)
{
    int result = 1;
    for (int idx=0; idx<exponent; idx++)
    {
        result = result * base;
    }
    return result;
}

int main()
{
    float a, r;
    int n;

    printf("enter first term of gp: ");
    scanf("%f", &a);
    printf("enter common ratio of gp: ");
    scanf("%f", &r);
    printf("enter number of terms of gp: ");
    scanf("%d", &n);

    float sum = (a * (power(r, n) - 1)) / (r - 1);

    printf("sum of gp is %.3f\n", sum);

    return 0;
}