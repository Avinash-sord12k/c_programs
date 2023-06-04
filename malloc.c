#include <stdlib.h>

int main() {

    // allocate space for 10 integers
    int* numbers = (int*)malloc(10 * sizeof(int));

    // check if allocation was successful
    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // use the allocated memory
    numbers[0] = 42;
    numbers[1] = 7;
    numbers[2] = 45;

    printf("%lu\n", sizeof(numbers));

    // free the allocated memory when done
    printf("numbers refers the address: %p \n", numbers);

    free(numbers);

    printf("still numbers refers the address: %p", numbers);

    return 0;
}
