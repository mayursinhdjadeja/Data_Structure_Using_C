//  Write a program to find the power of a given number using stack.

#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push Function
void push(int value)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        stack[++top] = value;
    }
}

// Pop Function
int pop()
{
    if(top == -1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int main()
{
    int base, exponent, i;
    long long result = 1;

    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter exponent: ");
    scanf("%d", &exponent);

    if(exponent < 0)
    {
        printf("Negative exponent is not supported.");
        return 0;
    }

    // Push base into stack exponent times
    for(i = 1; i <= exponent; i++)
    {
        push(base);
    }

    // Pop and multiply
    while(top != -1)
    {
        result = result * pop();
    }

    printf("%d ^ %d = %lld\n", base, exponent, result);

    return 0;
}