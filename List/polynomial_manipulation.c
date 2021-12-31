#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff;
    int exp;
    struct node *next;
};

void insert_back(struct node **head, int coeff, int exp){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *current = *head;
    temp->coeff=coeff;
    temp->exp=exp;
    temp->next=NULL;
    
    if(current==NULL){
        (*head)=temp;
        return;
    }

    while(current->next!=NULL){
        current=current->next;
    }

    current->next=temp;
}

void add_poly(struct node *poly1, struct node *poly2, struct node **poly3){
    struct node *temp1 = poly1;
    struct node *temp2 = poly2;

    while(temp1!=NULL && temp2!=NULL){
        if(temp1->exp==temp2->exp){
            insert_back(poly3, temp1->coeff+temp2->coeff, temp1->exp);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->exp>temp2->exp){
            insert_back(poly3, temp1->coeff, temp1->exp);
            temp1=temp1->next;
        }
        else{
            insert_back(poly3, temp2->coeff, temp2->exp);
            temp2=temp2->next;
        }
    }

    while(temp1!=NULL){
        insert_back(poly3, temp1->coeff, temp1->exp);
        temp1=temp1->next;
    }

    while(temp2!=NULL){
        insert_back(poly3, temp2->coeff, temp2->exp);
        temp2=temp2->next;
    }
}

void sub_poly(struct node *poly1, struct node *poly2, struct node **poly3){
    struct node *temp1 = poly1;
    struct node *temp2 = poly2;

    while(temp1!=NULL && temp2!=NULL){
        if(temp1->exp==temp2->exp){
            insert_back(poly3, temp1->coeff-temp2->coeff, temp1->exp);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->exp>temp2->exp){
            insert_back(poly3, temp1->coeff, temp1->exp);
            temp1=temp1->next;
        }
        else{
            insert_back(poly3, -temp2->coeff, temp2->exp);
            temp2=temp2->next;
        }
    }

    while(temp1!=NULL){
        insert_back(poly3, temp1->coeff, temp1->exp);
        temp1=temp1->next;
    }

    while(temp2!=NULL){
        insert_back(poly3, -temp2->coeff, temp2->exp);
        temp2=temp2->next;
    }
}

void mul_poly(struct node *poly1, struct node *poly2, struct node **poly3){
    struct node *temp1 = poly1;
    struct node *temp2 = poly2;

    while(temp1!=NULL){
        while(temp2!=NULL){
            insert_back(poly3, temp1->coeff*temp2->coeff, temp1->exp+temp2->exp);
            temp2=temp2->next;
        }
        temp1=temp1->next;
        temp2=poly2;
    }
}

void clean_poly(struct node **poly){
    struct node  *ptr1, *ptr2, *temp;
    ptr1 = *poly;
 
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
 
        while (ptr2->next != NULL) {
 
            if (ptr1->exp == ptr2->next->exp) {
 
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                temp = ptr2->next;
                ptr2->next = ptr2->next->next;
 
                free(temp);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}      

void display(struct node *head){
    struct node *temp = head;
    while(temp->next!=NULL){
        if(temp->coeff>0){
        printf("%dx^%d+", temp->coeff, temp->exp);
        temp=temp->next;
        }

    }
    printf("%dx^%d", temp->coeff, temp->exp);
}

int main(){
    struct node *poly1 = NULL;
    struct node *poly2 = NULL;
    struct node *added_poly = NULL;
    struct node *subbed_poly = NULL;
    struct node *mulled_poly = NULL;
    
    insert_back(&poly1,2,2);
    insert_back(&poly1,3,1);
    insert_back(&poly1,4,0);

    insert_back(&poly2,1,2);
    insert_back(&poly2,2,1);
    insert_back(&poly2,3,0);
    
    printf("\nPolynomial 1: ");
    display(poly1);

    printf("\nPolynomial 2: ");
    display(poly2);

    add_poly(poly1, poly2, &added_poly);
    printf("\nSum of the two polynomials: ");
    display(added_poly); 

    sub_poly(poly1, poly2, &subbed_poly);
    printf("\nDifference of the two polynomials: ");
    display(subbed_poly);

    mul_poly(poly1, poly2, &mulled_poly);
    clean_poly(&mulled_poly);
    printf("\nProduct of the two polynomials: ");
    display(mulled_poly);

    printf("\n");

    return 0;
}