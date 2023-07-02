#include <stdio.h>

int pow(int base, int power) {
    int newbase = base;
    for (int idx=0; idx<power-1; idx++)
    {
        newbase = newbase * base;
    }
    return newbase;
}

int main()
{
    int a = 2, r = 2;
    printf("%d\n", pow(10, 2));
    for (int idx=1; idx<10; idx++ ) {
        printf("%d \n", a * pow(r, idx));
    }
    return 0;
}