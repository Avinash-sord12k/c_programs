#include <stdio.h>

// Define an enumeration named Color
enum Color {
    RED,   // 0
    GREEN, // 1
    BLUE   // 2
};

int main() {
    // // Declare a variable of type Color
    // enum Color myColor;

    // // Assign a value from the Color enumeration
    // myColor = GREEN;

    // // Use the assigned value in a switch statement
    // switch (myColor) {
    //     case RED:
    //         printf("The color is red.\n");
    //         break;
    //     case GREEN:
    //         printf("The color is green.\n");
    //         break;
    //     case BLUE:
    //         printf("The color is blue.\n");
    //         break;
    //     default:
    //         printf("Unknown color.\n");
    // }
    int a = 1;

    printf("%d\n", a == GREEN);

    printf("%d\n", RED);
    printf("%d\n", GREEN);
    printf("%d\n", BLUE);

    return 0;
}
