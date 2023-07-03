#include <stdio.h>
#include "utilfunctions.c"


struct person {
    char name[50];
    int age;
    char gender[10];
    char occupation[20];
} person1;



int main()
{   
    char string[] = "abcdefghij";
    char *pointer = "abcdefgh";
    char string2[100];

    // printf("%d\n", sum(1, 2));
    // gets(string2);
    // printf("%s\n%s\n%s", pointer, string, string2);

    // int p = 1;
    // int q = 1;
    // int r = 1;
    // int s = 0;
    // printf("p > q < r == s: %d\n", p > q < r == s);

    squareroot(300000000);

    return 0;
}