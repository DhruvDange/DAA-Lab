#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void display(int arr[]){
    for(int i = 0; i < SIZE; i++){
        printf("%d \t", arr[i]);
    }
}

void main(){

    clock_t startTime, endTime;
    int arr[SIZE];

    for(int i = 0; i < SIZE; i++){
        arr[i] = rand();
    }

    display(arr);

    startTime = clock();

    for(int i = 0; i < SIZE; i++){
        int min = i;
        for(int j = i + 1; j < SIZE; j++){
            if(arr[j] < arr[min])
                min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }

    endTime = clock();
    printf("\n\n");

    display(arr);

    printf("\n\n");

    double timeT = (double) (endTime - startTime) / CLOCKS_PER_SEC;
    printf("Total time for %d items is: %lf", SIZE, timeT);


}