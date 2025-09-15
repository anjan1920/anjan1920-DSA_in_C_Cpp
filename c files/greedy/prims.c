#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define MAX_VERTICES 100

// Global adjacency matrix
int adjMatrix[MAX_VERTICES][MAX_VERTICES];

void prims(int vCount, int start) {
    int key[vCount];
    int mst[vCount];
    int parent[vCount];

    // Initialization of arrays
    for (int i = 0; i < vCount; i++) {
        key[i] = INF;
        mst[i] = 0;
        parent[i] = -1;
    }

    // Starting vertex
    key[start] = 0;
    parent[start] = -1;

    // Main algorithm
    for (int i = 0; i < vCount - 1; i++) {
        // Find the minimum key vertex not yet included in the MST
        int min = INF, u;

        for (int j = 0; j < vCount; j++) {
            if (mst[j] == 0 && key[j] < min) {
                //min vertex found 
                min = key[j];
                u = j;
            }
        }

        // Include the vertex in the MST
        mst[u] = 1;

        // Update key values and parent index of the adjacent vertices
        for (int k = 0; k < vCount; k++) {

            if (adjMatrix[u][k] !=0 && mst[k] == 0 && adjMatrix[u][k] < key[k]) {
                parent[k] = u;//parent of the k(adj)vertex is u 
                key[k] = adjMatrix[u][k];//update the key value
            }
        }
    }


    
   // Print the MST and calculate the total cost
 int totalCost = 0;
 printf("Edge \tWeight\n");
for (int i = 0; i < vCount; i++) {
    if (parent[i] != -1) {
        printf("%d - %d \t%d \n", parent[i], i, key[i]);
        totalCost += key[i];
    }
}
printf("Total cost of MST: %d\n", totalCost);

}

int main() {
    int vCount ;
    
    printf("Enter no of vertices:");
    scanf("%d",&vCount);
    
    printf("Enter adjMatrix with edge cost--\n");
    // Copy example matrix to global adjMatrix
    for (int i = 0; i < vCount; i++) {
       for (int j = 0; j < vCount; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    

    int startVertex ;
    printf("Enter starting vertex:");
    scanf("%d",&startVertex);

    prims(vCount, startVertex);

 
    return 0;
}
