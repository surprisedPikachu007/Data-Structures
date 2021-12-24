#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert_front(struct node *head, int a){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=a;
    temp->next=head;
    head=temp;
}

void insert_back(struct node *head, int a){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *current = (struct node*)malloc(sizeof(struct node));
    temp->data=a;
    temp->next=NULL;
    
    current=head;
    while(current->next!=NULL){
        current=current->next;
    }

    current->next=temp;
}

void insert_middle(struct node *head, int key, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp=head;

    while(temp->data!=key && temp!=NULL)
    {
        temp=temp->next;
    }

    if(temp!=NULL){
        struct node *new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data=data;
        new_node->next=temp->next;
        temp->next=new_node;
    }
    else{
        printf("\nKey not found");
    }
}

void delete_front(struct node *head){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp=head;
    head=head->next;
    free(temp);
}

void delete_end(struct node *head){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *current = (struct node*)malloc(sizeof(struct node));
    temp=head;
    current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=NULL;
    free(current);
}

void display(struct node *head){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp->next!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d->NULL",temp->data);
}
int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *second = (struct node*)malloc(sizeof(struct node));
    struct node *third = (struct node*)malloc(sizeof(struct node));
    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=4;
    third->next=NULL;
    
    insert_middle(head,2,3);
    printf("%d",head->next->next->data);
}