#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


char* getCurrentTimeString() {
    time_t currentTime;
    time(&currentTime);
    struct tm* timeInfo;
    timeInfo = localtime(&currentTime);
    char* timeString = (char*)malloc(20 * sizeof(char));  // Allocate memory for the time string
    strftime(timeString, 20, "%Y:%m:%d %H:%M:%S", timeInfo);  // Format the time into the string
    printf("saved at: %s\n", timeString);
    return timeString;
}

int main()
{
    FILE *ptr = fopen("myfile.txt", "a");
    
    int again = 1;
    char data[100];
    char *timeString;

    while(again==1) {
        printf("\n-----------------------------");
        printf("\nenter the data you want to save: ");
        fgets(data, 100, stdin);
        data[strcspn(data, "\n")] = '\0';
        printf("do you want to add more data? [1: yes, 2: no]");
        scanf("%d", &again);
        getchar();
        timeString = getCurrentTimeString();
        printf("data to be saved is: %s\n", data);
        fprintf(ptr, "%s -- %s\n", data, timeString);
    }
    printf("data saved success fully.");

    fclose(ptr);
    return 0;
}