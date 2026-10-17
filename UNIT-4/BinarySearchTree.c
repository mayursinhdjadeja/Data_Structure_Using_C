/*
    Write a program to create a Binary Tree and Traverse tree in preorder , postorder and inorder.  
    and Perform A) Insert and B) Delete operations on Binary search tree, And find out 
    the Height of the tree and Totale Number of Nodes in The Tree.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure of a binary tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node
struct Node* insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Preorder Traversal: Root, Left, Right
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder Traversal: Left, Root, Right
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Postorder Traversal: Left, Right, Root
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Find the minimum value node 
struct Node* findMin(struct Node *root) 
{ 
    while (root != NULL && root->left != NULL) 
    { 
        root = root->left; 
    } 
    return root; 
}

// Function to delete a node 
struct Node* deleteNode(struct Node *root, int value) 
{ 
    if (root == NULL) 
    { 
        printf("Value not found in the tree!\n"); 
        return NULL; 
    } 

    if (value < root->data) 
    { 
        root->left = deleteNode(root->left, value); 
    } 
    else if (value > root->data) 
    { 
        root->right = deleteNode(root->right, value); 
    } 
    else 
    { 
        // Case 1: No child 
        if (root->left == NULL && root->right == NULL) 
        { 
            free(root); return NULL; 
        } 
        // Case 2: Only right child 
        else if (root->left == NULL) 
        { 
            struct Node *temp = root->right; 
            free(root); return temp; 
        } 
        // Case 2: Only left child 
        else if (root->right == NULL) 
        { 
            struct Node *temp = root->left; 
            free(root); return temp; 
        } 
        // Case 3: Two children 
        else 
        { 
            struct Node *temp = findMin(root->right); 
            root->data = temp->data; 
            root->right = deleteNode(root->right, temp->data); 
        } 
    } 
    return root; 
} 

// Function to calculate height of the tree 
int height(struct Node *root) 
{ 
    if (root == NULL) 
    { 
        return 0; 
    } 
    int leftHeight = height(root->left); 
    int rightHeight = height(root->right); 
    if (leftHeight > rightHeight) 
    { 
        return leftHeight + 1; 
    } 
    else 
    { 
        return rightHeight + 1; 
    } 
}

// Function to count total number of nodes 
int countNodes(struct Node *root) 
{ 
    if (root == NULL) 
    { 
        return 0; 
    } 
    return 1 + countNodes(root->left) + countNodes(root->right); 
} 

// Function to free the entire tree 
void freeTree(struct Node *root) 
{ 
    if (root != NULL) 
    { 
        freeTree(root->left); 
        freeTree(root->right); 
        free(root); 
    } 
}

int main()
{
    struct Node *root = NULL;
    int choice, value, oldCount;

    do
    {
        printf("\nBINARY SEARCH TREE:-\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Preorder Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Height of Tree\n");
        printf("7. Total Number of Nodes\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);

                root = insert(root, value);
                printf("Node inserted successfully.\n");
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);

                oldCount = countNodes(root);
                root = deleteNode(root, value);

                if (countNodes(root) < oldCount)
                {
                    printf("Node deleted successfully.\n");
                }
                else
                {
                    printf("Node not found.\n");
                }
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("Height of Tree: %d\n", height(root));
                break;

            case 7:
                printf("Total Number of Nodes: %d\n", countNodes(root));
                break;

            case 8:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 8);
    
    freeTree(root);
    return 0;
}
