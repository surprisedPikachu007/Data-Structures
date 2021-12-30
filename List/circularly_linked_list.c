#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node *next;
};


void insert_at_front(struct node **head, int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next = *head;

    struct node *temp = *head;

    if(temp==NULL){
        *head=newnode;
        newnode->next=newnode;
        return;
    }

    if(*head!=NULL){
    while(temp->next!=*head){
        temp=temp->next;
    }
    temp->next=newnode;
    }
}

void insert_at_middle(struct node **head, int key, int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next = NULL;

    struct node *temp = *head;
    struct node *prev = NULL;

    if(temp==NULL){
        *head=newnode;
        newnode->next=newnode;
        return;
    }

    if(*head!=NULL){
    while(temp->data!=key){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    }
}

void insert_at_end(struct node **head, int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next = *head;

    struct node *temp = *head;

    if(temp==NULL){
        *head=newnode;
        newnode->next=newnode;
        return;
    }

    if(*head!=NULL){
    while(temp->next!=*head){
        temp=temp->next;
    }
    temp->next=newnode;
    }
}

void delete_at_front(struct node **head){
    struct node *temp = *head;
    if(temp==NULL){
        printf("List is empty\n");
        return;
    }
    
    if(temp->next==*head){
        *head=NULL;
        return;
    }


    else if(temp->next!=*head){
        (*head)=(*head)->next;
        free(temp);
    }
}

void delete_at_middle(struct node **head, int key){
    struct node *temp = *head;
    struct node *prev = NULL;

    if(temp==NULL){
        printf("List is empty\n");
        return;
    }

    if(*head!=NULL){
    while(temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
    }
}

void delete_at_end(struct node **head){
    struct node *temp = *head;
    struct node *prev = NULL;

    if(temp==NULL){
        printf("List is empty\n");
        return;
    }

    if(temp->next==temp){
        *head=NULL;
        return;
    }

    while(temp->next!=*head){
        prev=temp;
        temp=temp->next;
    }

    prev->next=*head;
    free(temp);
}

void display(struct node **head){
    struct node *temp = *head;

    if(temp==NULL){
        printf("List is empty\n");
        return;
    }

    if(temp!=NULL){
    do{
        printf("%d->", temp->data);
        temp=temp->next;
    }while(temp!=*head);
    }

    printf("NULL\n");
}

int main(){
    struct node *head = NULL;

    insert_at_front(&head, 1);
    display(&head);

    insert_at_end(&head, 3);
    display(&head);

    insert_at_middle(&head, 1, 2);
    display(&head);

    delete_at_middle(&head, 2);
    display(&head);

    delete_at_end(&head);
    display(&head);

    delete_at_front(&head);
    display(&head);
}