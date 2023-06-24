#include <stdio.h>

#define BUFFER_SIZE 4096

int main() {
    FILE *sourceFile, *destinationFile;
    char sourceFileName[100], destinationFileName[100];
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Get the source file name from the user
    printf("Enter the source file name: ");
    scanf("%s", sourceFileName);

    // Open the source file in read mode
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Get the destination file name from the user
    printf("Enter the destination file name: ");
    scanf("%s", destinationFileName);

    // Open the destination file in write mode
    destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Unable to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Copy the contents of the source file to the destination file
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destinationFile);
    }

    printf("File copied successfully.\n");

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
