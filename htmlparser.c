#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void slice(char* str, int length, char* result, size_t start, size_t end)
{
    strncpy(result, str + start, end - start);
}

int searchElementIndex(char *str, int length) {
    int startIndex = strcspn(str, "<");
    int endIndex = strcspn(str, ">");
    int closeIndex = strcspn(str, "/");
    if ((startIndex < closeIndex) && (closeIndex < endIndex)) {

    }
}


void parser(char string[], int length) {

    char *stringPtr = (char *)malloc(length);
    int tagLength = 0;
    char** tags = (char**)malloc()
    
}

int main()
{
    char string[100] = "<h1>This is a heading</h1>;";
    int length = strcspn(string, ";") + 1;

    

    parser(string, length);
    return 0;
}

