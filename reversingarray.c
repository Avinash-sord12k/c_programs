#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *reverseIntArray(int* array, int length) {
    int *reversedArray = (int*)calloc(sizeof(int), length);
    for (int idx=0; idx<length; idx++) {
        reversedArray[idx] = array[length - 1 - idx];
    }
    return reversedArray;
}

void printIntArray(int* array, int length, char* statement) {
    printf("%s\n", statement);
    for (int idx=0; idx<length; idx++)
    {
        printf("element at index=%d is %d\n", idx, array[idx]);
    }
}

char *reverseCharArray(char str[], int length) {
    char *reversedString = (char*)calloc(sizeof(char), length);
    for (int idx=0; idx<length; idx++)
    {
        reversedString[idx] = str[length - 1 - idx];
    }
    return reversedString;
}

void printCharArray(char *text, int length, char* statement) {
    printf("%s\n", statement);
    for (int idx=0; idx<length; idx++)
    {
        printf("%c", text[idx]);
    }
}

int main()
{
    // int length = 10;
    // int *ptr = (int*)calloc(sizeof(int), length);
    // for (int idx=0; idx<length; idx++) {
    //     ptr[idx] = idx + 1;
    // }
    // int * reversedArray = reverseIntArray(ptr, length);
    // printIntArray(ptr, length, "\nBefore reversal");
    // printIntArray(reversedArray, length, "\nAfter reversal");
    // free(ptr);
    // free(reversedArray);

    int length = 100;
    char text[length];
    fgets(text, length * sizeof(char), stdin);
    text[strcspn(text, "\n")] = '\0';
    int textActualLength = strlen(text);

    char *reversedText = reverseCharArray(text, textActualLength);
    printCharArray(text, textActualLength, "\nBefore reversing");
    printCharArray(reversedText, textActualLength, "\nAfter reversing");
    free(reversedText);
    return 0;
}