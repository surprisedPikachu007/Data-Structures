#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node *newnode(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}

int max(int a, int b){
    return (a>b)?a:b;
}

int height(struct node *root){
    if(root == NULL){
        return 0;
    }
    return root->height;
}

int balance_factor(struct node *root){
    if(root==NULL){
        return 0;
    }

    return height(root->left) - height(root->right);
}

struct node *findmin(struct node *root){
    if(root->left == NULL){
        return root;
    }
    return findmin(root->left);
}

struct node *right_rotate(struct node *y){
    struct node *x;

    x = y->left;
    y->left = x->right;
    x->right = y;  
    x->height = height(x);
    y->height = height(y);

    return y;
}

struct node* left_rotate(struct node *x){
    struct node *y;

    y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = height(x);
    y->height = height(y);

    return y;
}

struct node* insert(struct node *root, int data){
    if(root == NULL){
        return newnode(data);
    }

    if(data<root->data){
        root->left = insert(root->left, data);
    }

    else if(data>root->data){
        root->right = insert(root->right, data);
    }

    else{
        return root;
    }

    int balance = balance_factor(root);

    if(balance>1 && data<root->left->data){
        return right_rotate(root);
    }

    if(balance>1 && data>root->left->data){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    if(balance<-1 && data>root->right->data){
        return left_rotate(root);
    }

    if(balance<-1 && data<root->right->data){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

struct node *delete(struct node *root, int key){
    if(root == NULL){
        return root;
    }

    if(key<root->data){
        root->left = delete(root->left, key);
    }

    else if(key>root->data){
        root->right = delete(root->right, key);
    }

    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }

        if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }

        if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = findmin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    int balance = balance_factor(root);

    if(balance>1 && balance_factor(root->left)>=0){
        return right_rotate(root);
    }

    if(balance>1 && balance_factor(root->left)<0){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    if(balance<-1 && balance_factor(root->right)<=0){
        return left_rotate(root);
    }

    if(balance<-1 && balance_factor(root->right)>0){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    struct node *root=NULL;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);

    inorder(root);
    printf("\n");

    printf("%d",findmin(root)->data);
    printf("\n");

    delete(root, 5);
    inorder(root);
    printf("\n");

    return 0;
}