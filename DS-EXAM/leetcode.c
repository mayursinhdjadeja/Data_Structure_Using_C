//LEET CODE 203 : REMOVE LINK LIST ELEMENT

#include <stdio.h>
#include <stdlib.h>

void Create_LinkedList();

void Delete()
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
    free(ptr);
}

int main()
{
    int choice;
    do
    {
        printf("\nMENU\n");
        printf("1.Create Linked List\n");
        printf("2.Delete node\n");
        printf("3.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                Create_LinkedList();
                break;
            case 2:
                Delete();
                break;
            case 3:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 3);
    return 0;
}

