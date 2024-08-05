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
