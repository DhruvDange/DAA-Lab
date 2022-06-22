#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define n 500000

int partition(int a[], int lb, int ub){

    int pivot = lb;
    int i = lb, j = ub, temp;

    while(i < j){
        while(a[pivot] >= a[i] && i < ub) // look for element greater than pivot
            i++;
        while(a[j] > a[pivot]) // look for element less than pivot
            j--;
        
        if(i < j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[pivot];
    a[pivot] = a[j];
    a[j] = temp;
    return j;
}

void quickSort(int a[], int lb, int ub){
    if(lb < ub){
        int pos = partition(a, lb, ub);
        quickSort(a, lb, pos - 1);
        quickSort(a, pos + 1, ub);
    }
}

void main(){

    int a[n];
    clock_t start, end;

    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }

    start = clock();
    quickSort(a, 0, n-1);
    end = clock();

    double total_time = (double) (end-start) / CLOCKS_PER_SEC;

    printf("Time Taken is %lf", total_time);

    

}