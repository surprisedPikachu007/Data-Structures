#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void inorder(struct node *head){
    if(head==NULL)
        return;
    inorder(head->left);
    printf("%d ",head->data);
    inorder(head->right);
}

struct node* newNode(int item)
{
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);
 
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
 
    return node;
}


void search(struct node *head, int data){
    if(head == NULL){
        printf("Not found\n");
        return;
    }

    if(data == head->data){
        printf("Found\n");
        return;
    }

    if(data<head->data){
        search(head->left,data);
    }

    else{
        search(head->right,data);
    }
}

int main(){

    struct node *root = NULL;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 6);

    inorder(root);
    printf("\n");
}