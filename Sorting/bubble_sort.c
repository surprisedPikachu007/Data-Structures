#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int arr[], int size){
    for(int i=0;i<size-1;i++){
        for(int j=i;j<size-1;j++){
            if(arr[i]>arr[j+1]){
                swap(&arr[i], &arr[j+1]);
            }
        }
    }
}

void display(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[10] = {10, 5, 30, 20, 40, 50, 60, 70, 80, 90};
    bubble_sort(arr,10);
    display(arr, 10);
}