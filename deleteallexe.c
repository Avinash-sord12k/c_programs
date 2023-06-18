#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 4096 // Adjust the buffer size as needed

void deleteExeFilesInParentFolder() {
    // Open current directory
    DIR* dir = opendir("..");
    if (dir == NULL) {
        printf("Failed to open directory.\n");
        return;
    }

    // Traverse directory entries
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        // Check if entry is a regular file
        char filepath[MAX_PATH_LENGTH];
        snprintf(filepath, sizeof(filepath), "../%s", entry->d_name);

        struct stat st;
        if (stat(filepath, &st) == 0 && S_ISREG(st.st_mode)) {
            // Check if file ends with ".exe"
            if (strstr(entry->d_name, ".exe") != NULL) {
                // Delete the file
                if (remove(filepath) == 0) {
                    printf("Deleted: %s\n", filepath);
                } else {
                    printf("Failed to delete: %s\n", filepath);
                }
            }
        }
    }

    // Close directory
    closedir(dir);
}

int main() {
    deleteExeFilesInParentFolder();
    return 0;
}
