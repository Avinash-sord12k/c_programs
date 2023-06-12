#include <stdio.h>
#include <string.h>

int lineMaxLength = 300;

int main() {
    FILE *ptr = fopen("myfile.txt", "r");
    if (ptr == NULL) {
        printf("Sorry! There is some error.\n");
        return 0;
    }
    
    char line[lineMaxLength];
    
    while (fgets(line, sizeof(line), ptr) != NULL) {
        char *slice = strtok(line, "--");
        
        if (slice != NULL) {
            printf("Data written: %s ", slice);
            
            slice = strtok(NULL, "--");
            
            if (slice != NULL) {
                printf("|| At the time: %s", slice);
            } else {
                printf("No time information found.\n");
            }
        } else {
            printf("No data found.\n");
        }
    }
    
    fclose(ptr);
    return 0;
}
