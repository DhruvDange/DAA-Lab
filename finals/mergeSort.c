#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void merge(int lb, int mid, int ub, int arr[])
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int arr1[SIZE];

    while ((i <= mid) && (j <= ub))
    {
        if (arr[i] >= arr[j])
        {
            arr1[k++] = arr[j++];
        }
        else
        {
            arr1[k++] = arr[i++];
        }
    }
    while (i != mid)
    {
        arr1[k++] = arr[i++];
    }

    while (j != ub)
    {
        arr1[k++] = arr[j++];
    }

    for(int i = lb; i <= ub; i++){
        arr[i] = arr1[i];
    }
}

void mergeSort(int lb, int ub, int arr[])
{
    if (lb >= ub)
    {
        return;
    }
    else
    {
        int mid = (lb + ub) / 2;
        mergeSort(lb, mid, arr);
        mergeSort(mid+1, ub, arr);
        merge(lb, mid, ub, arr);
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

    mergeSort(0, SIZE-1, arr);
    
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d \t", arr[i]);
    }
}