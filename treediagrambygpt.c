#include <stdio.h>

void print_tree(int level) {
    if (level > 0) {
        printf("|");
        for (int i = 0; i < level - 1; i++) {
            printf("-");
        }
        printf("+-");
        printf("call print_tree(%d)\n", level - 1);
        print_tree(level - 1);
    }
}

int factorial(int n) {
    if (n == 1) {
        return 1;
    } else {
        printf("|");
        for (int i = 0; i < n - 1; i++) {
            printf("-");
        }
        printf("+-");
        printf("call factorial(%d)\n", n - 1);
        int result = factorial(n - 1) * n;
        printf("|");
        for (int i = 0; i < n - 1; i++) {
            printf("-");
        }
        printf("+-");
        printf("return %d\n", result);
        return result;
    }
}

int main() {
    int n = 5;
    printf("Tree diagram of factorial(%d):\n", n);
    print_tree(n);
    printf("|-factorial(%d)\n", n);
    int result = factorial(n);
    printf("Result: %d\n", result);
    return 0;
}
