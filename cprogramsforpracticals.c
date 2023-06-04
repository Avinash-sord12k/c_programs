#include <stdio.h>

int main()
{
    // program 1
    int a,b;
    printf("\n\nenter two numbers a and b: ");
    scanf("%d %d", &a, &b);
    (a > b)
    ? printf("a is greater than b")
    : printf("b is greater than a");

    // program 2
    int radius;
    printf("\n\n\n\nenter the radius of circle: ");
    scanf("%d", &radius);
    float area = 3.1415 * radius * radius;
    printf("area of the circe of radius %d is %.2f", radius, area);

    // program 3
    int array[11] = {20, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int max1 = array[0], max2 = array[1];
    for (int idx=0; idx<sizeof(array)/4; idx++)
    {   
        if (array[idx] > max1) {
            max2 = max1;
            max1 = array[idx];
        }
        else if (array[idx] > max2 && array[idx] != max1) {
            max2 = array[idx];
        }
    }
    printf("\n\n\n\n\narray is [");
    for (int idx=0; idx<sizeof(array)/4; idx++)
    {
        printf("%d, ", array[idx]);
    }
    printf("]");
    printf("\nfirst maximum number in array is: %d", max1);
    printf("\nsecond maximum number in array is: %d", max2);
    printf("\n\n\n");

}