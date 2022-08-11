#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int partition(int lb, int ub, int arr[])
{

    int pivot = lb;
    int i = lb;
    int j = ub;
    while (i < j)
    {
        while ((arr[i] <= arr[pivot]) && i < ub)
            i++;
        while (arr[j] > arr[pivot])
            j--;
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int lb, int ub, int arr[]){
    if(lb < ub)
    {
        int pos = partition(lb, ub, arr);
        quickSort(lb, pos-1, arr);
        quickSort(pos+1, ub, arr);
    }
}

void main()
{

    int arr[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand();
    }
    

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d \t", arr[i]);
    }
    
    printf("\n\n");

    quickSort(0, SIZE-1, arr);
    
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d \t", arr[i]);
    }
}