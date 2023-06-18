#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum studentdbschema {
    roll = 0,
    name = 1,
    physics_marks = 2,
    chemistry_marks = 3,
    mathematics_marks = 4,
    programming_marks = 5,
    mechanical_marks = 6,
};

typedef struct markssheet
{
    int physics;
    int chemistry;
    int mathematics;
    int programming;
    int mechanical;
} marksheet;

typedef struct student
{
    int roll;
    char *name;
    struct markssheet *marks;
} student;

int maxlength(char* inputstring, char* delimiter) {
    char* copy = strdup(inputstring);
    char* word = strtok(copy, delimiter);
    int index = 1;
    while (word != NULL) {
        word = strtok(NULL, delimiter);
        if (word != NULL) {
            index++;
        }
    }
    return index;
}

char *splitstring(char* inputstring, char* delimeter, int index) {
    if (index+1 > maxlength(inputstring, delimeter)) {
        printf("index error\n");
        return "";
    }
    char * copy = strdup(inputstring);
    char * word = strtok(copy, delimeter);
    for (int idx = 0; idx < index; idx++) {
        word = strtok(NULL, delimeter);
    }
    return word;
}

char **readstudentdata(int *length)
{
    FILE *ptr = fopen("studentdb.txt", "r");
    if (ptr == NULL) { printf("\ncould not connect to database file."); return 0;}
    char line[200];
    char **data = (char **)calloc(sizeof(char *), 200);
    int idx = 0;
    while (fgets(line, sizeof(line), ptr) != NULL)
    {
        data[idx] = (char *)calloc(sizeof(char), 200);
        strcpy(data[idx], line);
        idx++;
        (*length)++;
    }
    fclose(ptr);
    return data;
}

student *allocatestudentdata(char *datastring) {
    student* s = (student *)calloc(sizeof(student), 1);
    s->marks = (struct markssheet *)calloc(sizeof(struct markssheet), 1);

    char *roll_str = splitstring(datastring, " ", roll);
    char *name_str = splitstring(datastring, " ", name);
    char *physics_str = splitstring(datastring, " ", physics_marks);
    char *chemistry_str = splitstring(datastring, " ", chemistry_marks);
    char *mathematics_str = splitstring(datastring, " ", mathematics_marks);
    char *programming_str = splitstring(datastring, " ", programming_marks);
    char *mechanical_str = splitstring(datastring, " ", mechanical_marks);

    s->roll = atoi(roll_str);
    s->name = name_str;
    s->marks->physics = atoi(physics_str);
    s->marks->chemistry = atoi(chemistry_str);
    s->marks->mathematics = atoi(mathematics_str);
    s->marks->programming = atoi(programming_str);
    s->marks->mechanical = atoi(mechanical_str);

    return s;
}

void printstudentdatastring(char **data, int length) {
    for (int idx=0; idx<length; idx++)
    {
        (data[idx] == NULL) ? printf("NULL\n") : 0;
        printf("%s", data[idx]);
    }
}

void printstudentdatastructure(student *s1) {
    printf("id: %d, name: %s, marks: physics: %d, chemistry: %d, mathematics: %d, programming: %d, mechanics: %d \n",
    s1->roll, 
    s1->name, 
    s1->marks->physics, 
    s1->marks->chemistry, 
    s1->marks->mathematics, 
    s1->marks->programming, 
    s1->marks->mechanical);
}

student **studentsArray(char **data, int studentcount) {
    student **array = (student **)malloc(sizeof(student*) * 1);
    for (int idx=0; idx<studentcount; idx++)
    {   
        array = (student**)realloc(array, sizeof(student *) * idx+1);
        student *s1 = allocatestudentdata(data[idx]);
        array[idx] = s1;
    }
    return array;
}

student *searchbyroll(int roll, student ** data, int studentcount) {
    for (int idx=0; idx<studentcount; idx++)
    {
        if (data[idx]->roll == roll) {
            return data[idx];
        }
    }
    printf("could not find student with id: %d\n", roll);
    return NULL;
}
student *searchbyname(char *name, student ** data, int studentcount) {
    for (int idx=0; idx<studentcount; idx++)
    {
        if (strcmp(data[idx]->name, name)) {
            return data[idx];
        }
    }
    printf("could not find student with name: %s\n", name);
    return NULL;
}

int main()
{   
    int studentcount = 0;
    char **studentdata = readstudentdata(&studentcount);
    student **studentArray = studentsArray(studentdata, studentcount);
    for (int idx=0; idx<studentcount; idx++)
    {
        printstudentdatastructure(studentArray[idx]);
    }
    return 0;
}