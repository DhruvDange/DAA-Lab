#include <stdio.h>

void main()
{

    int n, source, nextNode, count;
    int cost[20][20], distance[20], visited[20], pred[20];

    printf("Enter no of vertices");
    scanf("%d", &n);

    printf("Enter cost matrix");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter source");
    scanf("%d", &source);



    for (int i = 1; i <= n; i++)
    {
        distance[i] = cost[source][i];
        visited[i] = 0;
        pred[i] = source;
    }

    distance[source] = 0;
    visited[source] = 1;
    count = 1;

    while(count < n){
        int min = 999;

        for(int i = 1; i<= n; i++){
            if(!visited[i] && min > distance[i]){
                min = distance[i];
                nextNode = i;
            }
        }

        visited[nextNode] = 1;
        for(int i = 0; i <=n; i++){
            if(!visited[i]){
                if(min + cost[nextNode][i] < distance[i]){
                    distance[i] = min + cost[nextNode][i];
                }
            }
        }
        count++;
    }
    for (int i = 1; i <= n; i++)
    if (i != source) {
      printf("\nDistance from source to %d: %d", i, distance[i]);
    }
    
}