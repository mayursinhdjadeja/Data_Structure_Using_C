// Implement stack using array with following operations: push, pop, display, peek, update, exit.

#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push Operation
void push()
{
    int value;

    if(top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);

        top++;
        stack[top] = value;

        printf("%d pushed into stack.\n", value);
    }
}

// Pop Operation
void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("Deleted element: %d\n", stack[top]);
        top--;
    }
}

// Display Operation
void display()
{
    int i;

    if(top == -1)
    {
        printf("Stack is Empty!\n");
    }
    else
    {
        printf("Stack Elements:\n");
        for(i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

// Peek Operation
void peek()
{
    if(top == -1)
    {
        printf("Stack is Empty!\n");
    }
    else
    {
        printf("Top element: %d\n", stack[top]);
    }
}

// Update Operation
void update()
{
    int pos, value;

    if(top == -1)
    {
        printf("Stack is Empty!\n");
        return;
    }

    printf("Enter position from top (1 to %d): ", top + 1);
    scanf("%d", &pos);

    if(pos < 1 || pos > top + 1)
    {
        printf("Invalid Position!\n");
    }
    else
    {
        printf("Enter new value: ");
        scanf("%d", &value);

        stack[top - pos + 1] = value;

        printf("Value updated successfully.\n");
    }
}

// Main Function
int main()
{
    int choice;

    do
    {
        printf("\n----- STACK MENU -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Update\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            case 5:
                update();
                break;

            case 6:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}
