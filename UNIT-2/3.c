//  Write a program to print strings in reverse order using stack.

#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char ch)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}

// Pop function
char pop()
{
    if(top == -1)
    {
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}

int main()
{
    char str[MAX];
    int i;

    printf("Enter a string: ");
    gets(str);

    // Push each character into stack
    for(i = 0; str[i] != '\0'; i++)
    {
        push(str[i]);
    }

    // Pop and print characters
    printf("Reversed String: ");
    while(top != -1)
    {
        printf("%c", pop());
    }

    return 0;
}
