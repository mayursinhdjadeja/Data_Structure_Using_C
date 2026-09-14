//  Write a program which performs the following operations using a simple queue. : insert() -> delete() -> display()

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rare = -1;

// Insert Operation
void insert()
{
    int x;

    if(rare == MAX - 1)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        if ( front == -1 )
            front = 0 ;

        printf("Enter Element:- ");
        scanf("%d", &x);
        rare++;
        queue[
        rare] = x ;
    }
}

// Delete Operation
void delete()
{
    if(front == -1 || front > rare)
    {
        printf("queue Underflow!\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

// Display Operation
void display()
{
    int i;

    if(front == -1 || front > rare )
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("queue Elements:\n");
        for(i = front; i <= rare; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}

// Main Function
int main()
{
    int choice;

    do
    {
        printf("\n----- STACK MENU -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 4);

    return 0;
}