#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

void squareroot(int num) {
    float root = 0;
    int stepCount = 0;
    while (num - (root * root) > 0) {
        root += 0.01; stepCount++;
    }
    printf("root of %d is %.3f .. calculated in %d steps.", num, root, stepCount);
}