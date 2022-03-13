#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *node, int data){
    if(node == NULL){
        node = (struct node *)malloc(sizeof(struct node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    if(data < node->data){
        node->left = insert(node->left, data);
    }
    else{
        node->right = insert(node->right, data);
    }
}

void inorder(struct node *node){
    if(node == NULL){
        return;
    }

    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

int main(){
    struct node *root = insert(NULL, 10);
    insert(root, 5);
    insert(root, 30);
    inorder(root);
    return 0;
}