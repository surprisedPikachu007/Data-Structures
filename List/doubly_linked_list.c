#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

void insert_at_beginning(struct node **head, int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    new_node->prev = NULL;
    if(*head != NULL){
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void insert_at_middle(struct node **head, int key, int data){
    if(head==NULL){
        printf("List is empty");
        return;
    }

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;

    struct node *current = *head;

    while(current!=NULL){
        if(current->data==key){
            temp->prev = current;
            temp->next=current->next;

            current->next = temp;
            if(temp->next!=NULL){
            temp->next->prev=temp;
            }
            return;
        }
        current=current->next;
    }    

    printf("Key not found\n");
}

void insert_at_end(struct node **head, int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    if(head!=NULL){
        struct node *current = *head;

        while(current->next!=NULL){
            current=current->next;
        }
        
        current->next=temp;
        temp->prev=current;
        return;
    }
    temp->prev=NULL;
}

void delete_at_end(struct node **head){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }

    struct node *temp = *head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}

void delete_at_middle(struct node **head, int key){
    if(head==NULL){
        printf("List is empty\n");
    }

    struct node *temp=*head;

    while(temp!=NULL){
        if(temp->data==key){
            if(temp->prev!=NULL){
            temp->prev->next=temp->next;
            }
            if(temp->next!=NULL){
            temp->next->prev=temp->prev;
            }
            free(temp);
            return;
        }
        temp=temp->next;
    }

    printf("Key not found\n");
}

void delete_at_front(struct node **head){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    if(*head != NULL){
        (*head)->prev = NULL;
    }
    free(temp);
}

void display(struct node **head){
    struct node *temp=*head;

    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data=1;
    head->next=NULL;
    head->prev=NULL;

    display(&head);

    insert_at_beginning(&head,0);
    display(&head);

    insert_at_end(&head,3);
    display(&head);

    insert_at_middle(&head,1,2);
    display(&head);

    delete_at_front(&head);
    display(&head);

    delete_at_middle(&head,2);
    display(&head);

    delete_at_end(&head);
    display(&head);
}