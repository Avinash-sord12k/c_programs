#include <stdio.h>
#include <string.h>

int str_length(char string[]) {
    int length = 0;
    static int printed = 0;
    while (string[length] != '\0') {
        length ++;
    }
    if (printed == 0) {
        printf("length of the inputted string is: %d\n", length);
        printed = 1;
    }
    return length;
}

void str_search(char string[], char letter) {
    int length = 0, total = 0;
    while (string[length] != '\0') {
        if ((string[length] == letter) && (total == 0)) {
            printf("the selected letter is at index: %d", length);
            total++;
        }
        else if ((string[length] == letter) && (total > 0)) {
            printf(", %d", length);
            total++;
        }
        length++;
    }
    printf("\ntotal matches: %d", total);
    printf("\n");
}

void str_reverse(char string[]) {
    int length = str_length(string), index = 0;
    while (index < length/2)
    {
        char temp = string[index];
        string[index] = string[length - index - 1];
        string[length - index - 1] = temp;
        index++;
    }
    printf("\nreversed string is: %s", string);
}

int main()
{   
    char input_string[5];

    printf("enter the string: ");
    gets(input_string);

    int index = 0;
    while (input_string[index] != '\0') {
        printf("%d, %c\n", index, input_string[index]);
        index++;
    }

    str_length(input_string);
    str_search(input_string, 'a');
    str_reverse(input_string);
    getchar();
    return 0;
}