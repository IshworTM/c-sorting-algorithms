#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n){
    int i,j;
    int swapped;

    for(i = 0; i < n - 1; i++){
        swapped = 0;

        for ( j = 0; j < n - i - 1; j++){
            if (arr[ j ] > arr[ j + 1]){
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }
        if (swapped == 0){
            break;
        }
    }
}

int main(){
    int n, i;

    printf("Enter the size of the array.\n>> ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL){
        printf("Memory allocation failed :(\n");
        return 1;
    }
    
    printf("Enter an array of numbers separated by a space.\n>> ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Un-sorted array:\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    bubbleSort(arr, n);
    printf("Sorted array:\n");
    for ( i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}