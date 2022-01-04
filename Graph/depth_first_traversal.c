#include <stdio.h>

void dfs(int graph[][5], int n, int v, int visited[]){
    visited[v] = 1;
    printf("%d ", v);
    for(int i=0;i<n;i++){
        if(graph[v][i]==1 && visited[i]==0){
            dfs(graph, n, i, visited);
        }
    }
}

int main(){
    int graph[][5]={
        {0,0,1,1,0},
        {0,0,1,0,1},
        {1,1,0,0,1},
        {1,0,0,0,1},
        {0,1,1,1,0}
    };
    int n = 5;
    int visited[n];
    for(int i=0;i<n;i++){
        visited[i] = 0;
    }
    dfs(graph, n, 0, visited);
    return 0;
}