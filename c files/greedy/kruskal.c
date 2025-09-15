#include <stdio.h>
#include <stdlib.h>

#define INF 9999

int adj_matrix[100][100];
int n;
int parent[100], rank_arr[100];
int edges[10000][3]; // To store edges: [weight, u, v]
int edge_count = 0;

// Function to add an edge to the edge list
void add_edge(int u, int v, int weight) {
    edges[edge_count][0] = weight;
    edges[edge_count][1] = u;
    edges[edge_count][2] = v;
    edge_count++;
}

// Union-Find functions
void make_set(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank_arr[i] = 0;
    }
}

int find_set(int v) {
    if (v != parent[v])
        parent[v] = find_set(parent[v]);
    return parent[v];
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_arr[a] < rank_arr[b]) {
            parent[a] = b;
        } else if (rank_arr[b] < rank_arr[a]) {
            parent[b] = a;
        }
        else  {
            parent[b]=a;
            rank_arr[a]++;
        }
    
    }
}

// Comparison function for qsort
int compare_edges(const void *a, const void *b) {
    int *edgeA = (int *)a;
    int *edgeB = (int *)b;
    return edgeA[0] - edgeB[0];
}

// Kruskal's algorithm
void kruskal() {
    int min_cost = 0;
    int edges_selected = 0;

    // Sort edges by weight
    qsort(edges, edge_count, sizeof(edges[0]), compare_edges);

    // Process edges in sorted order
    printf("Edge \tWeight\n");
    for (int i = 0; i < edge_count && edges_selected < n - 1; i++) {
        int weight = edges[i][0];
        int u = edges[i][1];
        int v = edges[i][2];

        if (find_set(u) != find_set(v)) {
            union_sets(u, v);
            printf("%d - %d \t%d \n", u, v, weight);
            min_cost += weight;
            edges_selected++;
        }
    }

    printf("Minimum cost of spanning tree: %d\n", min_cost);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj_matrix[i][j]);
            if (adj_matrix[i][j] != 0 && adj_matrix[i][j] != INF && j > i) {
                add_edge(i, j, adj_matrix[i][j]);
            }
        }
    }

    // Initialize the union-find structure
    make_set(n);

    printf("Minimum Spanning Tree using Kruskal's algorithm:\n");
    kruskal();
    return 0;
}
