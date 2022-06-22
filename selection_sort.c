#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 100000

void main(){
    clock_t start, end;
    double total_time;
    int arr[n];

    for(int i = 0; i < n; i++){
        arr[i] = rand();
    }

    int min, pos, temp;

    start = clock();

    for(int i = 0; i < n - 1; i++){
        min = arr[i];
        pos = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < min){
                min = arr[j];
                pos = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
    end = clock();

    total_time = (double) (end-start) / CLOCKS_PER_SEC;

    printf("Total time is %lf", total_time);
}