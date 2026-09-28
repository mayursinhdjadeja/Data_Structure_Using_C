// Write a C Program to merge two linked list.

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node* create() 
{
    struct node *head = NULL, *temp, *newnode;
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) 
    {
        newnode = malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
        }
        else 
        {
            temp = head;
            while(temp->next != NULL)
                {
                   temp = temp->next;
                }
            temp->next = newnode;
        }
    }
    return head;
}

void display(struct node *head) 
{
    while(head != NULL) 
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct node* merge(struct node *head1, struct node *head2) 
{
    struct node *temp;
    if(head1 == NULL)
    {
        return head2;
    }
    temp = head1;
    while(temp->next != NULL)
        {
            temp = temp->next;
        }
    temp->next = head2;
    return head1;
}

int main() 
{
    struct node *head1, *head2, *head;
    printf("First List\n");
    head1 = create();
    printf("Second List\n");
    head2 = create();
    head = merge(head1, head2);
    printf("Merged List: ");
    display(head);
    return 0;
}
