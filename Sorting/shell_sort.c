#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void shell_sort(int arr[], int n)
{
    int i, j;
    int gap = n/2; 
    while (gap > 0)
    {
        for (i = gap; i < n; i++)  
        {
            int temp = arr[i]; 
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap){ 
                swap(&arr[j+gap], &arr[j]); 
            }
        }
        gap /= 2;
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
    int arr[10] = {9, 8, 3, 7, 2, 0, 5, 6, 4, 1};
    shell_sort(arr, 10);
    display(arr, 10);
    return 0;
}