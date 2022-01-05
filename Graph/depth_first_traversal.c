#include <stdio.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push(int data)
{
    if(top == MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = data;
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("%d ",stack[top]);
    top--;
    
}

void dfs(int graph[][5], int n, int v, int visited[]){
    visited[v] = 1;
    push(v);
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
    printf("\n");

    for(int i=top;i>=0;i--){
        pop();
    }

    return 0;
}