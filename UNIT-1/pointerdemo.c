// Write a C program to demonstrate pointers.

#include <stdio.h>
int main()
{
    int a = 5;
    int *p;
    p = &a;
    printf("Address of a = %p\n", (void *)p);
    printf("Value of a = %d\n", *p);
    printf("Address of pointer p = %p\n", (void *)&p);
    return 0;
}
