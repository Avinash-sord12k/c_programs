#include <stdio.h>
#include <stdlib.h>
#define max_size 100

void push(int* stack, int* top, int num) {
    if (*top >= max_size) {
        printf("stack overflow");
        return;
    } stack[*top++] = num;
}

int pop(int* stack, int* top) {
    if (*top <= 0) {
        printf("stack underflow");
        return -1;
    } 
    return stack[*top--];
}

int show(int* stack, int* top, char c[]) {
    printf("///// %s /////\n", c);
    printf("%d\n", *top);
    for (int i=0; i<*top ; i++) {
        printf("[%d] => %d\n", i, stack[i]);
    }
}

int main()
{   
    int *stack_one = malloc(sizeof(int) * max_size);
    stack_one[0] = 1;
    stack_one[1] = 2;
    
    int *top_one = malloc(sizeof(int));
    *top_one = 0;
    show(stack_one, top_one, "just show it");
    
    push(stack_one, top_one, 3);
    push(stack_one, top_one, 2);
    push(stack_one, top_one, 1);
    show(stack_one, top_one, "after pushing");

    return 0;
}
