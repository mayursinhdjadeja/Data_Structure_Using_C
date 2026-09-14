// Write a program to find GCD of two numbers. 

#include <stdio.h>

int GCD(int a, int b)
{
    if (b == 0)
        return a;

    return GCD(b, a % b);
}

int main()
{
    int a, b, result;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    result = GCD(a, b);

    printf("GCD = %d", result);

    return 0;
}