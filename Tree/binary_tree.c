#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newnode(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;

    return(temp);
}

void preorder(struct node *head){
    if(head==NULL)
        return;
    printf("%d ",head->data);
    preorder(head->left);
    preorder(head->right);
}

void inorder(struct node *head){
    if(head==NULL)
        return;
    inorder(head->left);
    printf("%d ",head->data);
    inorder(head->right);
}

void postorder(struct node *head){
    if(head==NULL)
        return;
    postorder(head->left);
    postorder(head->right);
    printf("%d ",head->data);
} 

int main(){
    struct node *root = (struct node*)malloc(sizeof(struct node));
    root->data=1;
    root->left=newnode(2);
    root->right=newnode(3);

    root->left->left=newnode(4);
    root->left->right=newnode(5);

    root->right->left=newnode(6);
    root->right->right=newnode(7);

    preorder(root);
    printf("\n");

    inorder(root);
    printf("\n");

    postorder(root);
    printf("\n");
}