#include <stdio.h>

#define MAX 100
int queue[MAX];
int front = -1;
int rear = -1;

int n=5;
int visited[5];
int adj[5][5];

void enqueue(int v)
{
    rear++;
    queue[rear] = v;
}

void dequeue()
{
    printf("%d ", queue[front]);
    front++;
}

void bfs(int v)
{
    for (int i = 0; i < n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
        {
            enqueue(i);
            visited[i] = 1;
        }
    }
    if(front<=rear)
    {
        dequeue();
        bfs(queue[front]);
    }
}

int main(){
    for(int i=0;i<n;i++){
        visited[i] = 0;
        for(int j=0;j<n;j++){
            adj[i][j] = 0;
        }
    }

    adj[0][1] = 1;
    adj[0][2] = 1;
    adj[1][3] = 1;  
    adj[2][4] = 1;
    
    bfs(0);

    return 0;
}