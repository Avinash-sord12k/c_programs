#include <stdio.h>

int main() 
{
    int a, b;
    
    a = 10;
    b = 20;

    printf("memory address of a is %p and size of a is %lu \n", &a, sizeof(a));
    printf("memory address of b is %p and size of b is %lu \n", &b, sizeof(b));
    

    return 0;
}