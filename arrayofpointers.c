#include <stdio.h>

int main()
{
    char *strings[5] = {
        "hello world",
        "my name is avinash",
        "i am a developer",
        "i want to be a web developer",
        "i know a lot of programming languages"
    };
    char *string = "this type of assignment is valid in c";

    for (int idx=0; idx<5; idx++)
    {   
        printf("%d. %s. \n", idx+1, strings[idx]);
    }

    printf("%s\n", string);

}