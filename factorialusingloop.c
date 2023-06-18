#include <stdio.h>

int main()
{
    int n;
    printf("enter a number: ");
    scanf("%d", &n);
    int factorial = 1;
    for (int idx=1; idx<=n; idx++)
    {
        factorial = factorial * idx;
    }
    printf("factorial of %d is %d\n", n, factorial);
    return 0;
}