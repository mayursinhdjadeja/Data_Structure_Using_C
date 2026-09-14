//  Write a program to find the factorial of a given integer number using stack.

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
    int n, i;
    long long fact = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    if(n < 0)
    {
        printf("Factorial of negative number is not possible.");
        return 0;
    }

    // Push numbers from 1 to n
    for(i = 1; i <= n; i++)
    {
        push(i);
    }

    // Pop and multiply
    while(top != -1)
    {
        fact = fact * pop();
    }

    printf("Factorial of %d = %lld", n, fact);

    return 0;
}