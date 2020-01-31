#include <stdio.h>
#include <string.h>
typedef struct student
{
    int id;
    char name [21];
    float percentage;
} student_t;
int main()
{
    student_t record;
    record.id = 20;
    strncpy (record.name, "Arowoiya", 21);
    record.percentage = 97.5;
    printf("The identity of the student is : %d \n", record.id);
    printf("The name of the student is %s \n", record.name);
    printf("The student percentage is %lf \n", record.percentage );
    return 0;
}
