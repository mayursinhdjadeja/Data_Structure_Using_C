/*
Write a program to perform following operation on singly linked list:

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
    int data;
    struct node *next;
}   *start = NULL, *newnode;

void create_linkedlist()
{
    struct node *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter value: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    for (ptr = start; ptr != NULL; ptr = ptr->next)
    {
        printf("\n %d", ptr->data);
    }
}

void insert_beginning()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter value: ");
    scanf("%d", &newnode->data);
    newnode->next = start;
    start = newnode;
    printf("Node inserted at the beginning successfully!\n");
}

void insert_end()
{
    struct node **ptr = &start;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter value: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    while (*ptr != NULL)
    {
        ptr = &((*ptr)->next);
    }
    *ptr = newnode;
    printf("Node inserted at the end successfully!\n");
}

void insert_after()
{
    int data,val;
    struct node *ptr,*preptr;
     newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter value: ");
    scanf("%d", &newnode->data);
    printf("enter the value after which want to insert");
    scanf("%d",&val);
    ptr=start;
    preptr=ptr;
    while (preptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next = newnode;
    newnode->next=ptr;
 printf("Node inserted after successfully!\n");
}

void insert_before()
{
    int num;
    struct node *ptr,*preptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter value");
    scanf("%d", &newnode->data);
    ptr = start;
    preptr = ptr;
    printf("enter the value before you want to insert");
    scanf("%d", &num);
    while (ptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = newnode;
    newnode->next = ptr;
}

void first_delete()
{
    struct node*ptr;
    if(start==NULL)
    {
        printf("linklist is empty/underflow");

    }
    ptr=start;
    start=start->next;
    free (ptr);
}

void last_delete()
{
    struct node*ptr,*preptr;
    if(start==NULL)
    {
        printf("linklist is empty/underflow ");
    }
    ptr=start;
    preptr=ptr;
    while (ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free (ptr);
}

void delete_before()
{
    int num;
    struct node *ptr, *preptr;
    printf("enter the value before which you want to delete: ");
    scanf("%d", &num);
    ptr = start;
    preptr = ptr;
    while (ptr->next->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
}

void delete_after()
{
    int num;
    struct node *ptr, *preptr;
    printf("enter the value after which you want to delete: ");
    scanf("%d", &num);
    ptr = start;
    preptr = ptr;
    while (preptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    printf("\nNode deleted after successfully!\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1 create");
        printf("\n2 display");
        printf("\n3 exit");
        printf("\n4 insert beginning");
        printf("\n5 insert end");
        printf("\n6 insert after");
        printf("\n7 insert before");
        printf("\n8 first delete");
        printf("\n9 last delete");
        printf("\n10 delete before");
        printf("\n11 delete after");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_linkedlist();
            break;

        case 2:
            display();
            break;

        case 3:
            exit(0);

        case 4:
            insert_beginning();
            break;

        case 5:
            insert_end();
            break;

        case 6:
            insert_after();
            break;

        case 7:
            insert_before();
            break;

        case 8:
            first_delete();
            break;

        case 9:
            last_delete();
            break;

        case 10:
            delete_before();
            break;

        case 11:
            delete_after();
            break;

        default:
            printf("wrong choice");
        }
    } 
    return 0;
}