// Write a program to demonstrate structure in C.

#include <stdio.h>
// Structure declaration
struct student
{
    int rollno;
    char name[20];
};
int main()
{
    struct student s1;
    printf("Enter Roll Number: ");
    scanf("%d", &s1.rollno);
    printf("Enter Name: ");
    scanf("%s", s1.name);
    printf("\nStudent Details :- ");
    printf("Roll Number : %d\n", s1.rollno);
    printf("Name : %s\n", s1.name);
    return 0;
}
