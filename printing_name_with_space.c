// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int main() {
    
    char fullName[40];

    printf("enter your name: ");
    
    fgets(fullName, sizeof(fullName), stdin);
    
    int newLineIndex = strcspn(fullName , "\n");
    
    printf("new line character at %d \n", newLineIndex);
    
    fullName[newLineIndex] = '\0';

    // changing new line character with escape character.
    
    // "\0" and '\0' are not the same thing.
    
    printf("hello %s", fullName);
    return 0;
}