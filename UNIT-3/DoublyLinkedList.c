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

void Insert_After();

void Insert_Before();

void Delete_First();

void Delete_Last();

void Delete_After();

void Delete_Before();

int main()
{
    int choice;
    do
    {
        printf("\n1. Create Linked List");
        printf("\n2. Insert at Starting");
        printf("\n3. Insert at End");
        printf("\n4. Insert a node after the specific node");
        printf("\n5. Dnsert a node before the specific node");
        printf("\n6. Delete first node");
        printf("\n7. Delete last node");
        printf("\n8. Delete a node after the specific node");
        printf("\n9. Delete a node before the specific node");
        printf("\n10. Display");
        printf("\n11. Exit");

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
                Insert_After();
                break;

            case 5:
                Insert_Before();
                break;

            case 6:
                Delete_First();
                break;
            
            case 7:
                Delete_Last();
                break;

            case 8:
                Delete_After();
                break;

            case 9:
                Delete_Before();
                break;

            case 10:
                Display();
                break;

            case 11:
                printf("Exit");
                break;

            default:
                printf("Invalid choice");
        }

    } while(choice != 11);

    return 0;
}
