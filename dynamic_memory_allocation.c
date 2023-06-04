#include <stdio.h>
#include <stdlib.h>
int main()
{
    int length = 0, i = 0, n,
        *marks; // this marks pointer hold the base address
                // of the block created
    int ans;

    marks = (int *)malloc(sizeof(int)); // dynamically allocate memory using malloc

    // check if the memory is successfully allocated by malloc
    if (marks == NULL)
        printf("memory cannot be allocated");
    else
    {
        printf("Memory has been successfully allocated by using malloc\n");
        printf("\n marks array at: %pc\n", marks); // print the base or beginning

        do
        {
            printf("\n Enter Marks\n");
            scanf("%d", &marks[length]); // Get the marks
            printf("would you like to add more(1/0): ");
            scanf("%d", &ans);

            if (ans == 1)
            {
                length++;
                // Dynamically reallocate
                marks = (int *)realloc(marks, (length) * sizeof(int));

                // check if the memory is successfully allocated by realloc
                if (marks == NULL)
                {
                    printf("memory cannot be allocated");
                }
                else
                {
                    printf("Memory has been successfully reallocated using realloc:\n");
                    printf("\nbase address of marks are:%pc", marks);
                    ////print the base or beginning address of allocated memory
                }
            }
        } while (ans == 1);

        // print the marks of the students
        for (i = 0; i <= length; i++)
        {
            printf("marks of students %d are: %d\n", i, marks[i]);
        }
        free(marks);
    }
    return 0;
}
