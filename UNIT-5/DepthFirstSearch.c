// Write a C program to find out Depth First Search.

#include <stdio.h>
#define MAX 100

int adj[MAX][MAX];    
int visited[MAX];       

void DFS(int v, int n) 
{
    visited[v] = 1;               
    printf("%d ", v);           

    for (int i = 0; i < n; i++) 
    {
        if (adj[v][i] == 1 && !visited[i])
        {
            DFS(i, n);
        }
    }
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

    printf("DFS Traversal starting from vertex %d: ", start);
    DFS(start, n);
    printf("\n");

    return 0;
}
