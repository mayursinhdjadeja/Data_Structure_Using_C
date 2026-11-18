// WRITE A PROGRAM TO PERFORM OPERATIONS ON QUEUE: INSERT, DELETE, DIPLAY, EXIT

#include <stdio.h>
#define MAX 50

int queue[MAX];
int front = -1;
int rare = -1;

void insert()
{
    int x;
    if(rare == MAX - 1)
    {
        printf("Overflow!\n");
    }
    else
    {
        if ( front == -1 )
        {
            front = 0;
        }
        printf("Enter Element:- ");
        scanf("%d", &x);
        rare++;
        queue[rare] = x ;
    }
}

void delete()
{
    if(front == -1 || front > rare)
    {
        printf("Underflow!\n");
    }
    else
    {
        printf("Delete element\n");
        front++;
    }
}

void display()
{
    int i;
    if(front == -1 || front > rare )
    {
        printf("Empty!\n");
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

int main()
{
    int choice;

    do
    {
        printf("\nMENU\n");
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
