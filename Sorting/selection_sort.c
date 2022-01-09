#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int arr[], int size){
    int min;

    for(int i=0;i<size-1;i++){
        min = i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
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
    selection_sort(arr, 10);
    display(arr, 10);
    return 0;
}