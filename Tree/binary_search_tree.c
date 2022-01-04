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

struct node* insert(struct node* node, int data)
{
    if (node == NULL)
        return newNode(data);
 
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
 
    return node;
}

struct node* findmin(struct node* node){
    if(node->left==NULL)
        return node;
    return findmin(node->left);
}

struct node* findmax(struct node* node){
    if(node->right==NULL)
        return node;
    return findmax(node->right);
}

struct node* delete(struct node *node, int key){
    if(node == NULL){
        return NULL;
    }

    if(key<node->data){
        node->left=delete(node->left,key);
    }

    else if(key>node->data){
        node->right=delete(node->right,key);
    }

    else if(node->left && node->right){
        struct node *temp= findmin(node->right);
        node->data=temp->data;
        node->right=delete(node->right,temp->data);
    }

    else{
        struct node *temp=node;
        if(node->left==NULL){
            node=node->right;
        }
        else if(node->right==NULL){
            node=node->left;
        }
        free(temp);
    }

    return node;
}


void search(struct node *head, int data){
    if(head == NULL){
        printf("%d is Not found\n",data);
        return;
    }

    if(data == head->data){
        printf("%d Found\n",data);
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
    printf("Maximum element: %d\n",findmax(root)->data);
    printf("Minimum element: %d\n",findmin(root)->data);

    search(root,7);
    search(root,8);

    root=delete(root,5);
    root=delete(root,1);

    inorder(root);
    printf("\n");
}