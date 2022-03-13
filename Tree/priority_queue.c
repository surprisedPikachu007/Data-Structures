//priority queue using heap
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int arr[MAX];
int size = 0;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int i){
    if(size==1){
        printf("Only one element is presnet in heap\n");
        return;
    }
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<size && arr[left]>arr[largest]){
        largest = left;
    }

    if(right<size && arr[right]>arr[largest]){
        largest = right;
    }

    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        heapify(largest);
    }
}

void insert(int data){
    if(size==0){
        arr[0]=data;
        size++;
    }
    else{
        arr[size]=data;
        size++;
        for(int i=size/2-1;i>=0;i--){
            heapify(i);
        }
    }
}

void delete(int key){
    int i;
    for(i=0;i<size;i++){
        if(arr[i]==key){
            break;
        }
    }

    swap(&arr[i],&arr[size-1]);
    size--;

    for(int i=size/2-1;i>=0;i--){
        heapify(i);
    }
}

void print(){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    insert(70);
    insert(80);
    insert(90);

    print();
}