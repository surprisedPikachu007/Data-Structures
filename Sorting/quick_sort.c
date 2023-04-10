#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;
        int j = high;
        while (1)
        {
            while (arr[++i] < pivot);
            while (arr[--j] > pivot);
            if (i >= j)
                break;
            swap(&arr[i], &arr[j]);
        }
        swap(&arr[i], &arr[high]);
        quick_sort(arr, low, i - 1);
        quick_sort(arr, i + 1, high);
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
    int arr[10]={9, 8, 3, 7, 2, 0, 5, 6, 4, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr, 0, n-1);
    display(arr, n);
    return 0;
}