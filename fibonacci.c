#include <stdio.h>

int fibonacci(int number) {
    if ((number == 0) || (number == 1)) {
        return number;
    }
    return fibonacci(number - 1) + fibonacci(number - 2);
}

int main()
{
    int n;
    printf("enter a number: ");
    scanf("%d", &n);
    printf("fibonacci series upto %d is: ", n);
    for (int idx=0; idx<n; idx++)
    {
        printf("%d ", fibonacci(idx));
    }
    printf("\n");
    printf("\n");
    printf("\n");
    return 0;
}