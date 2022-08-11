#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void display(int arr[]){
    for(int i = 0; i < SIZE; i++){
        printf("%d \t", arr[i]);
    }
}

void main(){

    int arr[SIZE];
    clock_t startTime, endTime;

    for(int i = 0; i < SIZE; i++){
        arr[i] = rand() / 1000;
    }

    display(arr);

    startTime = clock();

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE - i - 1; j++){
            if(arr[j+1] < arr[j]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    endTime = clock();

    printf("\n\n");
    display(arr);

    double time = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    printf("Total time for %d items is: %lf", SIZE, time);


}