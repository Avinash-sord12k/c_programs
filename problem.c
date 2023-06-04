#include <stdio.h>

// void add_one_v1(int *our_var_ptr)
// {
//     *our_var_ptr = *our_var_ptr +1;
// }

// void add_one_v2(int *our_var_ptr)
// {
//     (*our_var_ptr)++;
// }

int main()
{
    // int testvar;

    // testvar = 63;
    // add_one_v1(&(testvar));         /* Try first version of the function */
    // printf("%d\n", testvar);        /* Prints out 64                     */
    // printf("@ %p\n\n", &(testvar));

    // testvar = 63;
    // add_one_v2(&(testvar));         /* Try first version of the function */
    // printf("%d\n", testvar);        /* Prints 63 ?                       */
    // printf("@ %p\n", &(testvar));   /* Address remains identical         */

    int x[5] = {1, 4, 3, 4, 5};
    int *p;
    p = &x[0];
    printf("%d \n", x[0]);
    printf("%d \n", ++(*p));
    printf("%d \n", *p);

    for(int i= 0; i<=4; i++) {
        printf("%d \t", x[i]);
    }

    return 0;
}