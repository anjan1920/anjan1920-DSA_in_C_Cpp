#include <stdio.h>

#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix to store graph
int visited[MAX_VERTICES]; // Array to keep track of visited vertices
int stack[MAX_VERTICES]; // Array to simulate stack operations
int top = -1; // Variable to track the top of the stack

// Function to push an element onto the stack
void push(int value) {
    if (top < MAX_VERTICES - 1) {
        stack[++top] = value; // Increment top and add the value to the stack
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
int pop() {
    if (top >= 0) {
        return stack[top--]; // Return the top value and decrement top
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1; // Stack is empty if top is -1
}

// Iterative DFS function using an explicit stack
void dfs(int startVertex, int vCount) {
    push(startVertex); // Push the starting vertex onto the stack

    while (!isEmpty()) { // While the stack is not empty
        int vertex = stack[top]; // Get the top vertex from the stack

        if (visited[vertex] == 0) { // If the vertex is not visited
            visited[vertex] = 1; // Mark it as visited
            printf("%d ", vertex); // Print the vertex
        }

        int foundUnvisited = 0; // Flag to check if an unvisited adjacent vertex is found
        for (int i = 0; i < vCount; i++) { // Check all adjacent vertices
            if (adjMatrix[vertex][i] == 1 && visited[i] == 0) { // If an adjacent vertex is not visited
                push(i); // Push it onto the stack
                foundUnvisited = 1; // Set the flag
                break; // Break the loop after pushing one unvisited adjacent vertex
            }
        }

        if (foundUnvisited == 0) { // If no unvisited adjacent vertex is found
           // printf("* ");
            pop(); // Pop the top vertex from the stack
        }
    }
}

int main() {
    int vCount, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vCount);

    printf("Enter the adjacency matrix:\n");
    // Read the adjacency matrix
    for (int i = 0; i < vCount; i++) {
        for (int j = 0; j < vCount; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    // Initialize the visited array
    for (int i = 0; i < vCount; i++) {
        visited[i] = 0; // Set all values in the visited array to 0
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("DFS Traversal: ");
    dfs(startVertex, vCount); // Perform DFS traversal starting from the given vertex

    return 0;
}
