#include <stdio.h>

#define MAX 100
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data){
    if(front==(rear+1)%MAX){
        printf("Queue is full\n");
        return;
    }
    if(rear==-1){
        front=0;
        rear=0;
    }
    else{
        rear=(rear+1)%MAX;
    }
    queue[rear]=data;
}

void dequeue(){
    if(front==-1){
        printf("Queue is empty\n");
        return;
    }
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front=(front+1)%MAX;
    }
}

void display(){
    if(front==-1){
        printf("Queue is empty\n");
        return;
    }
    int i;
    for(i=front;i!=rear;i=(i+1)%MAX){
        printf("%d ",queue[i]);
    }
    printf("%d\n",queue[i]);
}

int main(){
    enqueue(1);
    enqueue(2);
    display();

    dequeue();
    display();
}