#include <stdio.h>
#include <malloc.h>

#define MAX 10
int top;

struct node{
    int data;
    struct node *next;
};

struct node *head;

void push(int data){    
    if(top==MAX-1){
        printf("Stack Overflow\n");
        return;
    }
  
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=head;

    if(top==-1){
        head=newnode;
        top++;
        return;
    }

    newnode->next=head;
    head=newnode;
    top++;

}

void pop(){
    struct node *temp=head;
    if(top==-1){
        printf("Stack Underflow\n");
        return;
    }
    printf("\n%d\n\n",temp->data);

    head=head->next;
    free(temp);
}

void peek(){
    if(top==-1){
        printf("Stack Underflow\n");
        return;
    }
    printf("\n%d\n\n",head->data);
}

void display(){
    if(top==-1){
        printf("Stack Underflow\n");
        return;
    }
    struct node *temp=head;
    while(temp!=NULL){
        printf("\n%d\n|",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    head=NULL;
    top = -1;
    int choice;
    do{
    printf("\nChoice\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Display\n");
    printf("4.Peek\n");
    printf("5.Quit\n");
    printf("Enter choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter data: ");
            int data;
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            break;
        default:
            printf("Invalid choice\n");
    }
    }while (choice!=5);
}