//Program to implement Merge Sort in C.

#include <stdio.h>

void merge(int array[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int Left[n1], Right[n2];

    for ( i = 0; i < n1; i++)
    {
        Left[i] = array[l + i];
    }
    for ( j = 0; j < n2; j++)
    {
        Right[j] =  array[m + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j])
        {
            array[k] = Left[i];
            i++;
        }
        else {
            array[k] = Right[j];
            j++;
        }
        k++; 
    }

    while (i < n1)
    {
        array[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int l, int r){
    if (l < r)
    {
        int m = (l+r)/2;

        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);

        merge(array, l, m, r);
    }
}

int main(){
    int array[] = {12, 11, 13, 5, 6, 7};
    int array_size = sizeof(array)/sizeof(array[0]);

    printf("The given array is: \n");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    mergeSort(array, 0, array_size - 1);

    printf("Sorted array is:\n");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}