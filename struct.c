#include <stdio.h>
#include <string.h>

struct car {
    int year;
    char brand[20];
    char model[10];
};

int main()
{
    struct car mercedes;

    mercedes.year = 2009;
    strcpy(mercedes.brand, "mercedes");
    strcpy(mercedes.model, "Xuv-2009");

    printf("\n%d, %s, %s", mercedes.year, mercedes.brand, mercedes.model);
    printf("\nsize of car structure is %lu  ", sizeof(mercedes));
}