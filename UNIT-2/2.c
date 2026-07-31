//  Write a program to find out the factorial of a number using recursion (stack).

#include <stdio.h>

// Recursive Function
int factorial(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(num < 0)
    {
        printf("Factorial of negative number is not possible.");
    }
    else
    {
        printf("Factorial of %d = %d", num, factorial(num));
    }

    return 0;
}
