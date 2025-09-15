#include <stdio.h>

#define MAX_VERTICES 100
int visited[MAX_VERTICES] = {0};

void bfs(int adjMatrix[][MAX_VERTICES], int vCount, int start) {
    int queue[MAX_VERTICES], front = 0, rear = 0; // Initialize queue with front and rear pointers
    visited[start] = 1; // Mark the starting vertex as visited
    queue[rear++] = start; // Enqueue the starting vertex

    while (front < rear) { // While the queue is not empty
        int current = queue[front++]; // Dequeue the front element
        printf("%d ", current); // Print the current vertex

        // Iterate through all vertices to find adjacent unvisited vertices
        for (int i = 0; i < vCount; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                visited[i] = 1; // Mark the vertex as visited
                queue[rear++] = i; // Enqueue the vertex
            }
        }
    }
}

int main() {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix for the graph
    int vCount, startVertex; // Number of vertices and starting vertex

    printf("Enter the number of vertices: ");
    scanf("%d", &vCount); // Input the number of vertices

    printf("Enter the adjacency matrix:\n");
    // Input the adjacency matrix
    for (int i = 0; i < vCount; i++) {
        for (int j = 0; j < vCount; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex); // Input the starting vertex

    printf("BFS Traversal: ");
    bfs(adjMatrix, vCount, startVertex); // Perform BFS traversal

    return 0;
}
