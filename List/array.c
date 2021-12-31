#include <stdio.h>

#define MAX 10
int arr[MAX];
int count;

void insert_at_front(int data){
    if(count==MAX){
        printf("\nOverflow");
        return;
    }

    for(int i=count; i>0; i--){
        arr[i]=arr[i-1];
    }
    arr[0]=data;
    count++;
}

void insert_at_middle(int pos, int data){
    if(count==MAX){
        printf("\nOverflow");
        return;
    }

    for(int i=count; i>pos; i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=data;
    count++;
}

void insert_at_end(int data){
    if(count==MAX){
        printf("\nOverflow");
        return;
    }

    arr[count]=data;
    count++;
}

void delete_at_front(){
    if(count==0){
        printf("\nUnderflow");
    }

    for(int i=0; i<count-1; i++){
        arr[i]=arr[i+1];
    }
    count--;
}

void delete_at_middle(int key){
    if(count==0){
        printf("\nUnderflow");
    }

    for(int i=0; i<count; i++){
        if(arr[i]==key){                  
            for(int j=i; j<count-1; j++){
                arr[j]=arr[j+1];
            }
            count--;
            return;
        }
    }
    printf("\nElement not found");
}

void delete_at_end(){
    if(count==0){
        printf("\nUnderflow");
    }

    count--;
}

void display(){
    if(count==0){
        printf("\nEmpty");
    }

    for(int i=0; i<count; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    count = 0;

    insert_at_front(1);
    display();

    insert_at_end(3);
    display();

    insert_at_middle(1,2);
    display();

    delete_at_middle(2);
    display();

    delete_at_front();
    display();

    delete_at_end();
    display();

    return 0;
}