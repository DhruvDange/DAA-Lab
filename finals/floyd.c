#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 4
#define inf 9999

void print(int a[][max]){
    printf("\n");
    printf("\n");
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            if(a[i][j] == inf)
                printf("%4s ", "INF");
            else
                printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
}

void floyd(int a[][max]){
    for(int k = 0; k < max; k++){
        for(int i = 0; i < max; i++){
            for(int j = 0; j < max; j++){
                int sum = a[i][k] + a[k][j];

                if(a[i][j] > sum)
                    a[i][j] = sum;
            }
        }
    }
}

void main(){
    int graph[max][max];
    printf("\nENter DIstance Matrix -\n");
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            printf("\nGraph[%d][%d] - ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\nDistance Matrix - \n");
    print(graph);
    printf("\nShortest path matrix - \n");
    floyd(graph);
    print(graph);

}
