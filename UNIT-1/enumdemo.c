// Write a program to demonstrate Enumeration in C

#include <stdio.h>
// Enumeration declaration
enum Week
{ MON, TUE, WED, THU, FRI, SAT, SUN };
int main()
{
    enum Week day;
    day = WED;
    printf("Value of WED = %d\n", WED);
    return 0;
}
