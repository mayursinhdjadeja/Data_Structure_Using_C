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
};
struct node *head = NULL;

void Create_LinkedList()
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
    newnode->prev = NULL;
    newnode->next = NULL;
    head = newnode;
    printf("Linked list created with first node %d\n", val);
}

void Display()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr = head;
    printf("List: NULL <- ");
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        if (ptr->next != NULL)
            printf(" <-> ");
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
    newnode->prev = NULL;         
    newnode->next = head;         
    if (head != NULL)
    {
        head->prev = newnode;  
    }
    head = newnode;               
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
    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
        printf("Node %d inserted at end\n", val);
        return;
    }
    ptr = head;                   
    while (ptr->next != NULL)     
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;          
    newnode->prev = ptr;         
    printf("Node %d inserted at end\n", val);
}

void Insert_After()
{
    struct node *newnode, *ptr;
    int val, num;
    if (head == NULL)
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
    ptr = head;                   
    while (ptr != NULL && ptr->data != num)   
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Node %d not found\n", num);
        free(newnode);
        return;
    }
    newnode->next = ptr->next;    
    newnode->prev = ptr;          
    if (ptr->next != NULL)
    {
        ptr->next->prev = newnode;   
    }
    ptr->next = newnode;          
    printf("Node %d inserted after %d\n", val, num);
}

void Insert_Before()
{
    struct node *newnode, *ptr;
    int val, num;
    if (head == NULL)
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
    ptr = head;                   
    while (ptr != NULL && ptr->data != num)   
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Node %d not found\n", num);
        free(newnode);
        return;
    }
    newnode->next = ptr;          
    newnode->prev = ptr->prev;    
    if (ptr->prev != NULL)
    {
        ptr->prev->next = newnode;  
    }
    else
    {
        head = newnode;  
    }
    ptr->prev = newnode;          
    printf("Node %d inserted before %d\n", val, num);
}


void Delete_First()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    ptr = head;                   
    head = head->next;            
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(ptr);                    
    printf("First node deleted\n");
}

void Delete_Last()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    ptr = head;                   
    if (ptr->next == NULL)
    {
        head = NULL;
        free(ptr);
        printf("Last node deleted\n");
        return;
    }
    while (ptr->next != NULL)     
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;       
    free(ptr);                    
    printf("Last node deleted\n");
}

void Delete_After()
{
    struct node *ptr, *temp;
    int num;
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    printf("Enter node value after which to delete: ");
    scanf("%d", &num);
    ptr = head;                   
    while (ptr != NULL && ptr->data != num)   
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Node %d not found\n", num);
        return;
    }
    if (ptr->next == NULL)
    {
        printf("No node exists after %d\n", num);
        return;
    }
    temp = ptr->next;             
    ptr->next = temp->next;       
    if (temp->next != NULL)
    {
        temp->next->prev = ptr; 
    }
    free(temp);                   
    printf("Node after %d deleted\n", num);
}

void Delete_Before()
{
    struct node *ptr, *temp;
    int num;
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    printf("Enter node value before which to delete: ");
    scanf("%d", &num);
    ptr = head;                   
    while (ptr != NULL && ptr->data != num)   
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Node %d not found\n", num);
        return;
    }
    if (ptr->prev == NULL)
    {
        printf("No node exists before %d\n", num);
        return;
    }
    temp = ptr->prev;             
    if (temp->prev != NULL)
    {
        temp->prev->next = ptr;   
    }
    else
    {
        head = ptr;    
    }
    ptr->prev = temp->prev;       
    free(temp);                   
    printf("Node before %d deleted\n", num);
}

void Delete_Specific()
{
    struct node *ptr;
    int num;
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    printf("Enter node value to delete: ");
    scanf("%d", &num);
    ptr = head;
    while (ptr != NULL && ptr->data != num)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Node %d not found\n", num);
        return;
    }
    if (ptr->prev == NULL)
    {
        head = ptr->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
    }
    else if (ptr->next == NULL)
    {
        ptr->prev->next = NULL;
    }
    else
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
    printf("Node %d deleted\n", num);
}

int main()
{
    int choice;

    do
    {
        printf("\nDOUBLY LINKED LIST MENU \n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Starting\n");
        printf("3. Insert at End\n");
        printf("4. Insert a node after the specific node\n");
        printf("5. Insert a node before the specific node\n");
        printf("6. Delete first node\n");
        printf("7. Delete last node\n");
        printf("8. Delete a node after the specific node\n");
        printf("9. Delete a node before the specific node\n");
        printf("10. Delete a specific node\n");
        printf("11. Display\n");
        printf("12. Exit\n");
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
                Delete_After();      
                break;
            
            case 9:  
                Delete_Before();     
                break;
            
            case 10: 
                Delete_Specific();   
                break;
            
            case 11: 
                Display();           
                break;
            
            case 12: 
                printf("Exit\n");    
                break;
            
            default: 
                printf("Invalid choice\n");
        }

    } while(choice != 12);

    return 0;
}
