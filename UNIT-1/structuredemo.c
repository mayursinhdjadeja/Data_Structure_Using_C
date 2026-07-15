#include <stdio.h>

struct student {
    int rollno;
    char name[20];
};

int main() {
    struct student s1;

    printf("Enter Roll No: ");
    scanf("%d", &s1.rollno);

    printf("Enter Name: ");
    scanf("%s", s1.name);

    printf("\nStudent Data:\n");
    printf("Roll No: %d\n", s1.rollno);
    printf("Name: %s\n", s1.name);

    return 0;
}
