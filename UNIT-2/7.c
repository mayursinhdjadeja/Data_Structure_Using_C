// Write a program to find the Smallest Common Divisor of a given number.

#include <stdio.h>

int SmallestDivisor(int n, int i)
{
    if (n % i == 0)
    {
        return i;
    }
    return SmallestDivisor(n, i + 1);
}

int main()
{
    int n, result;

    printf("Enter a number: ");
    scanf("%d", &n);

    result = SmallestDivisor(n, 2);

    printf("Smallest Divisor = %d", result);

    return 0;
}
