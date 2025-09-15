// // BELLFORD
#include <stdio.h>
#define V 100
#define INT_MAX 1000000
void printPath(int parent[], int j)
{
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}
void printSolution(int dist[], int n, int parent[], int src)
{
    printf("Vertex\t  Distance\tPath\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d -> %d\t  %d\t\t%d", src, i, dist[i], src);
        printPath(parent, i);
        printf("\n");
    }
}
void BellmanFord(int graph[V][V], int src, int n)
{
    int dist[V];
    int parent[V];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }
    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                printf("Graph contains negative-weight cycle!");
                return;
            }
        }
    }
    printSolution(dist, n, parent, src);
}
int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int graph[V][V];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = INT_MAX;
        }
    }
    int src;
    printf("Enter the source vertex: \n");
    scanf("%d", &src);
    BellmanFord(graph, src, n);
    return 0;
}

