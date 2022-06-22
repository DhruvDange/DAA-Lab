#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

int maxNum(int a, int b){
    return (a > b ? a: b);
}

void getMatrix(int arr[SIZE][SIZE], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
}

void printMatrix(int arr[SIZE][SIZE], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void warshall(int arr[SIZE][SIZE], int n){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                arr[i][j] = maxNum(arr[i][j], (arr[i][k] && arr[k][j]));
            }
        }
    }
}

void main(){
    int n;
    clock_t start, end;
    double time;
    printf("Enter Matrix SIZE -");
    scanf("%d",&n);
    int arr[SIZE][SIZE];
    getMatrix(arr,n);
    printMatrix(arr,n);
    printf("\n\n\n");
    start = clock();
    warshall(arr,n);
    end = clock();
    printMatrix(arr,n);
    printf("\n\n\n");
    time = (double) (end - start)/CLOCKS_PER_SEC;
    time = time * 1000;
    printf("Time Taken is %lf ms", time);
}