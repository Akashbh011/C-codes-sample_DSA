#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

#define MAX_VERTICES 100

void kruskalsAlgo(int adj[][MAX_VERTICES], int n);
int find(int i, int parent[]);
int uni(int i, int j, int parent[]);

int main()
{
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
        scanf("%d%d%d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }
    kruskalsAlgo(adj, V);

    return 0;
}

void kruskalsAlgo(int adj[][MAX_VERTICES], int n){
    int cost[MAX_VERTICES][MAX_VERTICES];
    int parent[MAX_VERTICES];
    int count = 1;
    int mincost = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(adj[i][j] == 0){
                cost[i][j] = 9999;
            }
            else{
                cost[i][j] = adj[i][j];
            }
        }
    }

    for(int j = 0; j < n; j++){
        parent[j] = -1;
    }

    while(count < n){
        int min = INT_MAX;
        int a, b, u, v;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(cost[i][j] < min){
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u, parent);
        v = find(v, parent);
        if(uni(u, v, parent)){
            printf("%d - %d = %d\n", a, b, cost[a][b]);
            mincost += min;
        }

        cost[u][v] = cost[v][u] = 9999;
        count++;
    }
    printf("Minimum cost of spanning tree = %d", mincost);
}

int find(int i, int parent[]){
    while(parent[i] != -1){
        i = parent[i];
    }
    return i;
}

int uni(int i, int j, int parent[]){
    int parent_i = find(i, parent);
    int parent_j = find(j, parent);
    if(parent_i != parent_j){
        parent[parent_j] = parent_i;
        return 1;
    }
    return 0;
}

