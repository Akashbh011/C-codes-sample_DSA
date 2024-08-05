#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

void printMST(int parent[], int adj[][MAX_VERTICES], int V) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, adj[i][parent[i]]);
}

void max_spanning_tree(int adj[][MAX_VERTICES], int V) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int visited[MAX_VERTICES];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MIN;
        visited[i] = 0;
    }

    parent[0] = -1;
    key[0] = INT_MAX;

    for (int i = 0; i < V - 1; i++) {
        int max_key = INT_MIN;
        int max_idx = -1;

        for (int j = 0; j < V; j++) {
            if (!visited[j] && key[j] > max_key) {
                max_key = key[j];
                max_idx = j;
            }
        }

        visited[max_idx] = 1;


        for (int k = 0; k < V; k++) {
            if (adj[max_idx][k] && !visited[k] && adj[max_idx][k] > key[k]) {
                parent[k] = max_idx;
                key[k] = adj[max_idx][k];
            }
        }
    }

     for (int i = 1; i < V; i++){
        printf("%d - %d \t%d \n", parent[i], i, adj[i][parent[i]]);}
}


int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int adj[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges and weights:\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    max_spanning_tree(adj, V);

    return 0;
}
