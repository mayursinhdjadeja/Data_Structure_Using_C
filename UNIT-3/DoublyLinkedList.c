/*
    Write a program to perform following operation on Doubly linked list:
    a. Create a linked list
    b. Display it
    c. Insert a node at the starting of the list
    d. insert a node at the end of the list
    e. insert a node after the specific node
    f. insert a node before the specific node
    g. delete first node
    h. delete last node
    i. delete specific node
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
}; struct node *head = NULL;

void Create_LinkedList()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    head = newnode;
}

void Insert_Start()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void Insert_End()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void Display()
{
    struct node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice;
    do
    {
        printf("\n1. Create Linked List");
        printf("\n2. Insert at Starting");
        printf("\n3. Insert at End");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                Create_LinkedList();
                break;

            case 2:
                Insert_Start();
                break;

            case 3:
                Insert_End();
                break;

            case 4:
                Display();
                break;

            case 5:
                printf("Exit");
                break;

            default:
                printf("Invalid choice");
        }

    } while(choice != 5);

    return 0;
}