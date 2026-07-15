#include <stdio.h>
int main()
{
    int a=5 ;
    int *p;
    p=&a;

    printf("addresh of A = %d\n", p);
    printf("value of a = %d\n", *p);
    printf("Value = %d\n", &p);

    return 0;
}