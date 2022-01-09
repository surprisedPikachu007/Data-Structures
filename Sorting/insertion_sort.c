#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insertion_sort(int arr[], int size){
    int i, j, key;

    for(i=1; i<size; i++){
        key = arr[i];
        j = i-1;
        for(; j>=0 && arr[j]>key; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1]=key;
    }
}

void display(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[10] = {10, 5, 30, 20, 40, 50, 60, 70, 90, 80};
    insertion_sort(arr, 10);
    display(arr, 10);
    return 0;
}