#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

void main(){
    clock_t start, end;
    int arr[SIZE];
    double total_time;

    for(int i = 0; i < SIZE; i++){
        arr[i] = rand();
    }

    start = clock();
    for(int i = 0; i < SIZE - 1; i++){
        for(int j = 0; j < SIZE - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();
    total_time = (double)(end-start)/CLOCKS_PER_SEC;

    printf("Total time is %lf", total_time);
}