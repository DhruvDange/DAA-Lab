#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define n 100000

void merge(int a[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[n];

    while ((i <= mid) && (j <= ub))
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= ub)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for(k = lb; k <= ub; k++){
        a[k] = b[k];
    }
}

void mergeSort(int a[], int lb, int ub)
{
    int mid;
    if(lb >= ub)
        return;
    mid = (lb + ub) / 2;
    mergeSort(a, lb, mid);
    mergeSort(a, mid + 1, ub);
    merge(a, lb, mid, ub);
    
}

void main()
{
    int a[n];
    clock_t start, end;
    double totaltime;

    for (int i = 0; i < n; i++)
    {
        a[i] = (int)rand();
    }
    start = clock();
    mergeSort(a, 0, n-1);
    end = clock();

    totaltime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken %lf", totaltime);
}