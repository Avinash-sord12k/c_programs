#include <stdio.h>

int main()
{
    int intsize = sizeof(int);
    int floatsize = sizeof(float);
    int doublesize = sizeof(double);
    int charsize = sizeof(char);

    printf("the size of int is %d\n", intsize);
    printf("the size of float is %d\n", floatsize);
    printf("the size of double is %d\n", doublesize);
    printf("the size of char is %d\n", charsize);
}