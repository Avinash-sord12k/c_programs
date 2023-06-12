#include <stdio.h>

int main()
{
    FILE *ptr = NULL;
    char string[40] = "this is a sample string";
    // reading a file
    // ptr = fopen("myfile.txt", "r");
    // fscanf(ptr, "%s", string);
    // printf("the content of file is: %s/n", string);

    // writing a file
    ptr = fopen("myfile.txt", "w");
    for (int idx = 0; idx < 1000; idx++)
    {
        // fprintf(ptr, "%s index is: %d pointer at: %p\n", string, idx, ptr + idx);
        fprintf(ptr, "%p %p %p %p %p \n", ptr+idx, ptr+idx+1, ptr+idx+2, ptr+idx+3, ptr+idx+4);
    }
    fclose(ptr);
    return 0;
}