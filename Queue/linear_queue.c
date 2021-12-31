#include <stdio.h>
#include<stdlib.h>

#define MAX 100
int queue[MAX];
int front, rear;

void enqueue(int data){
    if(rear == MAX-1){
        printf("Queue Overflow\n");
        return;
    }

    if(rear == -1){
        front=0;
    }

    rear++;
    queue[rear]=data;
}

void dequeue(){
    if(front==-1){
        printf("Queue Underflow\n");
        return;
    }

    if(front==rear){
        printf("\n%d was dequeued\n",queue[rear]);
        front = -1;
        rear = -1;
        return;
    }

    printf("\n%d was dequeued\n",queue[rear]);
    front++;
}

void display(){
    for(int i=front; i<rear+1; i++){
        printf("%d ",queue[i]);
    }
}

int main(){
    front = -1;
    rear = -1;

    enqueue(1);
    enqueue(2);
    display();

    dequeue();
    display();
}