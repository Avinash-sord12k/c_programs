#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[30];
    int marks;
};

void showStudentData(struct student *studentArray, int length, char title[100])
{
    (strcmp(title, "") == 0) ? strcpy(title, "Students Data") : 0;

    printf("\n%s: \n", title);
    for (int index = 0; index < length; index++)
    {
        printf("%d => %s got %d marks.\n", index, studentArray[index].name, studentArray[index].marks);
    }
    printf("\ntotal results: %d\n", length);
}

void addStudentInArray(struct student **studentArray, int *length, const char name[30], int marks)
{
    (*length)++;
    struct student temp_student;
    strncpy(temp_student.name, name, sizeof(temp_student.name));
    temp_student.name[sizeof(temp_student.name) - 1] = '\0'; // Ensure null-termination
    temp_student.marks = marks;
    *studentArray = (struct student *)realloc(*studentArray, (*length) * sizeof(struct student));
    (*studentArray)[*length - 1] = temp_student;
}

void removeStudentInArray(struct student **studentArray, int *length, int id)
{
    for (int idx = id; idx < *length - 1; idx++)
    {
        (*studentArray)[idx] = (*studentArray)[idx + 1];
    }
    (*length)--;
    *studentArray = (struct student *)realloc(*studentArray, (*length) * sizeof(struct student));
}

int main()
{
    int length = 0;
    struct student *studentsArray = NULL;

    // Add some dummy data
    addStudentInArray(&studentsArray, &length, "Avinash", 29);
    addStudentInArray(&studentsArray, &length, "Ashish", 40);
    addStudentInArray(&studentsArray, &length, "Liam", 82);
    addStudentInArray(&studentsArray, &length, "Olivia", 90);
    addStudentInArray(&studentsArray, &length, "Noah", 78);
    addStudentInArray(&studentsArray, &length, "Emma", 85);
    addStudentInArray(&studentsArray, &length, "Ava", 92);
    addStudentInArray(&studentsArray, &length, "Isabella", 80);
    addStudentInArray(&studentsArray, &length, "Sophia", 88);
    addStudentInArray(&studentsArray, &length, "Jackson", 76);
    addStudentInArray(&studentsArray, &length, "Aiden", 95);
    addStudentInArray(&studentsArray, &length, "Lucas", 83);
    addStudentInArray(&studentsArray, &length, "Mia", 89);
    addStudentInArray(&studentsArray, &length, "Luna", 87);
    addStudentInArray(&studentsArray, &length, "Ethan", 81);
    addStudentInArray(&studentsArray, &length, "Lily", 93);
    addStudentInArray(&studentsArray, &length, "Oliver", 77);
    addStudentInArray(&studentsArray, &length, "Charlotte", 94);
    addStudentInArray(&studentsArray, &length, "Amelia", 86);
    addStudentInArray(&studentsArray, &length, "Harper", 79);
    addStudentInArray(&studentsArray, &length, "Elijah", 84);
    addStudentInArray(&studentsArray, &length, "Henry", 91);

    int more = 1, options, studentMarks, id, justStarted = 1;
    char studentName[30];
    char title[150];

    do
    {
        if (justStarted == 0)
        {
            printf("do you want more operation? (1, 0): ");
            scanf("%d", &more);
            getchar();
        }
        justStarted = 0;
        if (more == 1)
        {
            printf("options(1: add, 2: delete, 3:edit) :");
            scanf("%d", &options);
            getchar();

            if (options == 1 || length == 0)
            {
                printf("\nenter student's name: ");
                fgets(studentName, sizeof(studentName), stdin);
                studentName[strcspn(studentName, "\n")] = '\0';
                printf("enter student's marks: ");
                scanf("%d", &studentMarks);
                getchar(); // Consume the newline character

                addStudentInArray(&studentsArray, &length, studentName, studentMarks);
            }
            else if (options == 2)
            {
                showStudentData(studentsArray, length, title);
                printf("\nEnter the serial number of the student you want to delete:\n");
                scanf("%d", &id);
                getchar(); // Consume the newline character

                removeStudentInArray(&studentsArray, &length, id);
            }
        }
        else if (more == 0)
        {
            showStudentData(studentsArray, length, title);
        }
    } while (more);

    free(studentsArray);
    printf("\n");
    return 0;
}
