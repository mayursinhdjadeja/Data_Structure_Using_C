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
};
struct node *start = NULL;

void Create_LinkedList()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    start = newnode;
    printf("Linked list created with first node %d\n", newnode->data);
}

void Display()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr = start;
    printf("List: START -> ");
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        if (ptr->next != NULL)
            printf(" -> ");
        ptr = ptr->next;
    }
    printf(" -> NULL\n");
}

void Insert_Start()
{
    struct node *newnode;
    int val;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)                    
    {
        printf("OVERFLOW\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &val);
    newnode->data = val;                    
    newnode->next = start;                  
    start = newnode;                        
    printf("Node %d inserted at beginning\n", val);
}

void Insert_End()
{
    struct node *newnode, *ptr;
    int val;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)                   
    {
        printf("OVERFLOW\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &val);
    newnode->data = val;                   
    newnode->next = NULL;                   
    if (start == NULL)
    {
        start = newnode;
        printf("Node %d inserted at end\n", val);
        return;
    }
    ptr = start;                            
    while (ptr->next != NULL)               
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;                   
    printf("Node %d inserted at end\n", val);
}

void Insert_After()
{
    struct node *newnode, *ptr, *preptr;
    int val, num;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)                    
    {
        printf("OVERFLOW\n");
        return;
    }
    printf("Enter data to insert: ");
    scanf("%d", &val);
    printf("Enter node value after which to insert: ");
    scanf("%d", &num);
    newnode->data = val;                    
    ptr = start;                            
    preptr = ptr;                           
    while (preptr != NULL && preptr->data != num)   
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (preptr == NULL || preptr->data != num)
    {
        printf("Node %d not found\n", num);
        free(newnode);
        return;
    }
    preptr->next = newnode;                
    newnode->next = ptr;                    
    printf("Node %d inserted after %d\n", val, num);
}

void Insert_Before()
{
    struct node *newnode, *ptr, *preptr;
    int val, num;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)                 
    {
        printf("OVERFLOW\n");
        return;
    }
    printf("Enter data to insert: ");
    scanf("%d", &val);
    printf("Enter node value before which to insert: ");
    scanf("%d", &num);
    newnode->data = val;                    
    ptr = start;                            
    preptr = ptr;                           
    while (ptr != NULL && ptr->data != num)         
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Node %d not found\n", num);
        free(newnode);
        return;
    }
    if (ptr == start)
    {
        newnode->next = start;
        start = newnode;
    }
    else
    {
        preptr->next = newnode;             
        newnode->next = ptr;                
    }
    printf("Node %d inserted before %d\n", val, num);
}

void Delete_First()
{
    struct node *ptr;
    if (start == NULL)                      
    {
        printf("UNDERFLOW\n");
        return;
    }
    ptr = start;                            
    start = start->next;                    
    free(ptr);                              
    printf("First node deleted\n");
}

void Delete_Last()
{
    struct node *ptr, *preptr;
    if (start == NULL)                      
    {
        printf("UNDERFLOW\n");
        return;
    }
    ptr = start;                            
    if (ptr->next == NULL)
    {
        start = NULL;
        free(ptr);
        printf("Last node deleted\n");
        return;
    }
    while (ptr->next != NULL)               
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;                    
    free(ptr);                              
    printf("Last node deleted\n");
}

void Delete_Specific()
{
    struct node *ptr, *preptr;
    int num;
    if (start == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    printf("Enter node value to delete: ");
    scanf("%d", &num);
    ptr = start;
    preptr = ptr;
    while (ptr != NULL && ptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Node %d not found\n", num);
        return;
    }
    if (ptr == start)
    {
        start = ptr->next;
    }
    else
    {
        preptr->next = ptr->next;
    }
    free(ptr);
    printf("Node %d deleted\n", num);
}

int main()
{
    int choice;

    do
    {
        printf("\nSINGLY LINKED LIST MENU\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Starting\n");
        printf("3. Insert at End\n");
        printf("4. Insert a node after the specific node\n");
        printf("5. Insert a node before the specific node\n");
        printf("6. Delete first node\n");
        printf("7. Delete last node\n");
        printf("8. Delete a specific node\n");
        printf("9. Display\n");
        printf("10. Exit\n");
        printf("Enter choice: ");
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
                Delete_Specific();   
                break;
            
            case 9:  
                Display();           
                break;
            
            case 10: 
                printf("Exit\n");    
                break;
            
            default: 
                printf("Invalid choice\n");
        }

    } while(choice != 10);

    return 0;
}
