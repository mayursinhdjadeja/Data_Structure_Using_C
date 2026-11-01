// Write a C program to find out Bread First Search.

#include <stdio.h>
#define MAX 100

int adj[MAX][MAX];      
int visited[MAX];       
int queue[MAX];         
int front = -1, rear = -1;

void enqueue(int v) 
{
    if (rear == MAX - 1) return;   
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue(void) 
{
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty(void) 
{
    return (front == -1 || front > rear);
}

void BFS(int start, int n) 
{
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal starting from vertex %d: ", start);

    while (!isEmpty()) 
    {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) 
        {
            if (adj[v][i] == 1 && !visited[i]) 
            {
                enqueue(i);
                visited[i] = 1;   
            }
        }
    }
    printf("\n");
}

int main(void) 
{
    int n, edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter each edge as two vertices (u v):\n");
    for (int i = 0; i < edges; i++) 
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;      
        adj[v][u] = 1;      
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start, n);

    return 0;
}
