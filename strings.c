#include <stdio.h>

int main()
{
    char string [] = "Hello World";
    for (int i = 0; i < sizeof(string); i++)
    {
        printf("%c-", string[i]);
    }
    printf("\n%d ", sizeof(string));
}