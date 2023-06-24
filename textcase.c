#include <stdio.h>

// function to find the occurence of upperCase and lowercase lettercase numbers and special characters
void findOccurence(char *str) {
    int upperCase = 0, lowerCase = 0, numbers = 0, specialCharacters = 0;
    for (int idx = 0; str[idx] != '\0'; idx++) {
        if (str[idx] >= 'A' && str[idx] <= 'Z') {
            upperCase++;
        } else if (str[idx] >= 'a' && str[idx] <= 'z') {
            lowerCase++;
        } else if (str[idx] >= '0' && str[idx] <= '9') {
            numbers++;
        } else {
            specialCharacters++;
        }
    }
    printf("upperCase: %d\n", upperCase);
    printf("lowerCase: %d\n", lowerCase);
    printf("numbers: %d\n", numbers);
    printf("specialCharacters: %d\n", specialCharacters);
}

int main() {
    char str[100];
    printf("enter a string: ");
    scanf("%[^\n]%*c", str);
    findOccurence(str);
    return 0;
}