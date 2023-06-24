#include <stdio.h>

// funciton to find length of string;
int strLength(char str[])
{
    int strlength = 0;
    while (str[strlength] != '\0') {
        strlength++;
    }
    return strlength;
}

// function to copy string from source to destination
void strCopy(char str1[], char str2[]) {
    int idx = 0;
    while (str1[idx] != '\0') {
        str2[idx] = str1[idx];
        idx++;
    }
}

// function to compare two strings
int strCompare(char str1[], char str2[]) {
    int idx = 0;
    while (str1[idx] != '\0' && str2[idx] != '\0') {
        if (str1[idx] != str2[idx]) {
            return 0;
        }
        idx++;
    }
    if (str1[idx] == '\0' && str2[idx] == '\0') {
        return 1;
    }
    return 0;
}

// function to reverse a string
void strReverse(char str[]) {
    int strlength = strLength(str);
    for (int idx=0; idx<strlength/2; idx++) {
        char temp = str[idx];
        str[idx] = str[strlength - idx - 1];
        str[strlength - idx - 1] = temp;
    }
}

// function to concatenate two strings
void strConcat(char str1[], char str2[]) {
    int str1length = strLength(str1);
    int str2length = strLength(str2);
    for (int idx=0; idx<str2length; idx++) {
        str1[str1length + idx] = str2[idx];
    }
    str1[str1length + str2length] = '\0';
}

int main()
{
    char str1[100], str2[100], str3[100];
    printf("enter a string: ");
    gets(str1);
    printf("enter another string: ");
    gets(str2);
    printf("length of string:  %s is %d\n", str1, strLength(str1));
    printf("length of string:  %s is %d\n", str2, strLength(str2));
    strCopy(str1, str3);
    printf("copy of string: %s is:  %s\n", str1, str3);
    printf("comparing string: %s and:  %s: %d\n", str1, str2, strCompare(str1, str2));
    strReverse(str1);
    printf("reverse of string: %s is %s: \n", str3, str1);
    strConcat(str1, str2);
    printf("concatenation of string: %s and: %s is:  %s\n", str3, str2, str1);

    return 0;
}