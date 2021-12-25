#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert_front(struct node **head, int a){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=a;
    temp->next=(*head);
    (*head)=temp;
}

void insert_back(struct node **head, int a){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *current = *head;
    temp->data=a;
    temp->next=NULL;
    
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

void delete_front(struct node **head){
    struct node *temp = *head;

    if(temp!=NULL){
    *head=(*head)->next;
    free(temp);
    }
}

void delete_end(struct node **head){
    struct node *temp = *head;
    struct node *prev_temp = temp;
    
    if(temp!=NULL){
    while(temp->next!=NULL){
        prev_temp=temp;
        temp=temp->next;
    }
    prev_temp->next=NULL;
    free(temp);
    }
}

void delete_key(struct node **head, int key){
    struct node *temp = *head, *prev_temp;

    while(temp!=NULL && temp->data==key){
        *head=temp->next;
        free(temp);
        temp=*head;
    }

    while(temp!=NULL){
    while(temp!=NULL && temp->data!=key){
        prev_temp=temp;
        temp=temp->next;
    }

    if(temp==NULL){
        return;
    }

    prev_temp->next=temp->next;
    free(temp);

    temp=prev_temp->next;
    }
}

void display(struct node *head){
    while(head!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));

    head->data=1;
    head->next=NULL;

    insert_front(&head,0);
    insert_back(&head,3);
    insert_middle(head,1,2);

    display(head);

    delete_key(&head, 2);
    delete_front(&head);
    delete_end(&head);

    display(head);
}