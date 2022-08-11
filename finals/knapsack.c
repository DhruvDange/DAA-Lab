#include <stdio.h>

int weight[20], profit[20], selected[20] = {0}, table[20][20], capacity;


int max(int a, int b){
    return (a > b? a: b);
}

void knapsack(int n){
    
    for(int i = 0; i <= capacity; i++){
        table[0][i] = 0;
    }

    for(int i = 0; i <= n; i++){
        table[i][0] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= capacity; j++){
            if(weight[i] > j){
                table[i][j] = table[i-1][j];
            }else{
                table[i][j] = max(table[i-1][j], table[i-1][j-weight[i]] + profit[i]);
            }
        }
    }

    int netCap = capacity;
    for(int i = n; i > 0 && netCap != 0; i--){
        if(table[i][netCap] != table[i-1][netCap]){
            selected[i] = 1;
            netCap -= weight[i];
        }else{
            selected[i] = 0;
        }
    }

    int profitMax = 0;
    for(int i = 1; i <= n; i++){
        if(selected[i] == 1){
            printf("%d, ", i);
            profitMax += profit[i];
        }
    }
    printf("Max profit: %d", profitMax);
}

void main(){

    int n;
    printf("Enter number of objects");
    scanf("%d", &n);

    printf("Enter profit and weight of each obj");
    for(int i = 1; i <=n; i++){
        scanf("%d", &profit[i]);
        scanf("%d", &weight[i]);
    }

    printf("Enter capacity of knapsack");
    scanf("%d", &capacity);

    knapsack(n);

}