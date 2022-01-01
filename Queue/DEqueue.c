//Double Ended queue

#include <stdio.h>

#define MAX 10
int queue[MAX];
int front = -1;
int rear = -1;

void insert_at_rear(int data){
    if(rear == MAX-1){
        printf("Queue is full\n");
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear++;
    queue[rear] = data;
}

void insert_at_front(int data){
    if(front == 0){
        printf("Queue is full\n");
        return;
    }
    if(front == -1){
        front = 0;
        rear = 0;
    }
    else{
        front--;
    }
    queue[front] = data;
}

void delete_from_end(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        rear--;
    }
}

void delete_from_front(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front++;
    }
}

void display(){
    for(int i=front;i<rear+1;i++){
        printf("%d",queue[i]);
    }
    printf("\n");
}

int main(){ 
    insert_at_front(1);
    insert_at_rear(2);
    insert_at_front(0);
    display();

    delete_from_front();
    display();

    insert_at_front(1);
    display();

    delete_from_end();
    display();
}            