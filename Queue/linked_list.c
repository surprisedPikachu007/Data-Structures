#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front, *rear;

void enqueue(int data){
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if(rear == NULL){
        front = new_node;
        rear = new_node;
    }
    else{
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue(){
    if(front == NULL){
        printf("Queue Underflow\n");
        return;
    }

    struct node *temp = front;
    front = front->next;
    free(temp);
}

void display(){
    struct node *temp = front;
    while(temp != NULL){
        printf("_ ");
        temp = temp->next;
    }
    printf("\n");

    temp = front;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");

    temp = front;
    while(temp != NULL){
        printf("_ ");
        temp = temp->next;
    }
    printf("\n\n");
}

int main(){
    front = NULL;
    rear = NULL;

    enqueue(1);
    enqueue(2);
    display();

    dequeue();
    display();
}