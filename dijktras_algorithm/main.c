#include <stdio.h>
#include <stdlib.h>
int no_vertices;

void dijkstra(int start,int adj[][ no_vertices]){
    int cost[no_vertices][no_vertices];
    int dist[no_vertices];
    int parent[no_vertices];
    int visited[no_vertices];
    int n=no_vertices;
    for (int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            if(adj[i][j]==0){
                cost[i][j]=9999;
            }
            else{
                cost[i][j]=adj[i][j];
            }
        }
    }

    for(int i =0;i<n;i++){
            dist[i]=cost[start][i];
            parent[i]=start;
            visited[i]=0;
    }

    dist[start]=0;
    visited[start]=1;
    int count =1;
    int nextnode;
    while(count < n){
        int mindist =9999;
        for(int i=0;i<n;i++){

            if(dist[i]<mindist && visited[i]!=1){
                mindist=dist[i];
                nextnode=i;
            }

        }
        visited[nextnode]=1;
        count ++;
        for(int i=0;i<n;i++){

            if(visited[i]==0 ){

                if((mindist+cost[nextnode][i])<dist[i]){
                    dist[i]=mindist+cost[nextnode][i];
                    parent[i]=nextnode;
                }

            }
        }

    }
    for(int j=0;j<no_vertices;j++){
        printf("%d - %d = %d\n",start,j,dist[j]);


        }


}
void printGraph(int adj[][no_vertices]){
    for(int i=0;i<no_vertices;i++){
        for(int j=0;j<no_vertices;j++){
            printf("%d",adj[i][j]);
        }
        printf("\n");
    }
}

int main(){

    printf("Enter the no. of vertices: ");
    scanf("%d",&no_vertices);
    int adj[no_vertices][no_vertices];
    int choice=1;
    for(int i=0;i<no_vertices;i++){
        for(int j=0;j<no_vertices;j++){

                adj[i][j]=0;

        }
    }
    while(choice==1){
        int i,j,cost;
        printf("Enter the vertices between which you want edges: ");
        scanf("%d%d",&i,&j);
        printf("Enter the cost: ");
        scanf("%d",&cost);
        adj[i][j]=cost;
        adj[j][i]=cost;
        printf("Enter 1 if you want to add more edges: ");
        scanf("%d",&choice);
    }
    printGraph(adj);
    dijkstra(0,adj);




   return 0;

}
/*
#include<stdio.h>
int no_vertices;
void printGraph(int adj[][no_vertices]){
    for(int i=0;i<no_vertices;i++){
        for(int j=0;j<no_vertices;j++){
            printf("%d",adj[i][j]);
        }
        printf("\n");
    }
}
void prims(int i,int adj[][no_vertices]){
    int key[no_vertices];
    int visited[no_vertices];
    int parent[no_vertices];
    for(int j=0;j<no_vertices;j++){
        key[j]=9999;
        visited[j]=0;
        parent[j]=-1;
    }
    // int mincost=0;
    int count=0;

    while(1){
        for(int j=0;j<no_vertices;j++){
            if(visited[j]!=1 && adj[i][j]<key[j]){
                key[j]=adj[i][j];
                parent[j]=i;
            }
        }
        int smallest=9999;
        for(int j=0;j<no_vertices;j++){
            if(smallest>key[j] && visited[j]!=1){
                smallest=key[j];
                i=j;
            }
        }
        visited[i]=1;
        count++;
        if(count==6){
            break;
        }
    }
    for(int j=0;j<no_vertices;j++){
        printf("%d - %d = %d\n",j,parent[j],key[j]);
    }
}
int main(){
    printf("Enter the no. of vertices: ");
    scanf("%d",&no_vertices);
    int adj[no_vertices][no_vertices];
    int choice=1;
    for(int i=0;i<no_vertices;i++){
        for(int j=0;j<no_vertices;j++){
            if(i==j){
                adj[i][j]=0;
            }else{
                adj[i][j]=9999;
            }
        }
    }
    while(choice==1){
        int i,j,cost;
        printf("Enter the vertices between which you want edges: ");
        scanf("%d%d",&i,&j);
        printf("Enter the cost: ");
        scanf("%d",&cost);
        adj[i][j]=cost;
        adj[j][i]=cost;
        printf("Enter 1 if you want to add more edges: ");
        scanf("%d",&choice);
    }
    printGraph(adj);
    // int adj[6][6]={
    //     {0,4,9999,9999,9999,2},
    //     {4,0,6,9999,9999,3},
    //     {9999,6,0,3,9999,1},
    //     {9999,9999,3,0,2,9999},
    //     {9999,9999,9999,2,0,4},
    //     {2,3,1,9999,4,0}
    // };
    prims(5,adj);
    return 0;
}
*/
