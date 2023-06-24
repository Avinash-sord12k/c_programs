#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    int salary;
} person;

void printperson(person person)
{
    printf("name: %s\n", person.name);
    printf("age: %d\n", person.age);
    printf("salary: %d\n", person.salary);
}

void printData(person record[], int size) {
    FILE *managerfile, *workerfile;
    int i;
    managerfile = fopen("manager.txt", "w");
    if (managerfile == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    workerfile = fopen("worker.txt", "w");
    if (workerfile == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    for (i = 0; i < size; ++i) {
        if (record[i].salary > 5000) {
            fprintf(managerfile, "%s %d %d\n", record[i].name, record[i].age, record[i].salary);
            printf("saved %s as manager with %d salary\n", record[i].name, record[i].salary);
        } else {
            fprintf(workerfile, "%s %d %d\n", record[i].name, record[i].age, record[i].salary);
            printf("saved %s as worker with %d salary\n", record[i].name, record[i].salary);
        }
    }
    fclose(managerfile);
    fclose(workerfile);
    printf("\nall data stored successfully\n");
}

// print worker data form file
void personData(char *filename) {
    FILE *workerfile;
    char name[50];
    int age, salary;
    workerfile = fopen(filename, "r");
    if (workerfile == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    printf("printing data from %s\n", filename);
    while (fscanf(workerfile, "%s %d %d", name, &age, &salary) != EOF) {
        printf("name: %s ", name);
        printf("age: %d ", age);
        printf("salary: %d\n", salary);
    }
    fclose(workerfile);
}

int main()
{
    person  record[10] = {
        {"Raju", 25, 10000},
        {"Rahul", 22, 5000},
        {"Ravi", 21, 3000},
        {"Rohit", 20, 8000},
        {"Rakesh", 24, 7000},
        {"Rajesh", 25, 6000},
        {"Rajat", 23, 2000},
        {"Raj", 22, 9000},
        {"Rajeev", 21, 4000},
        {"Rajendra", 20, 1000}
    };
    int i, size = 10;
    printData(record, size);
    printf("\n\n");
    personData("manager.txt");
    printf("\n\n");
    personData("worker.txt");
    return 0;
}