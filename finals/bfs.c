#include <stdio.h>


void bfs(int v, int n, int a[][10], int visited[]){
    int q[10]; // traversal queue
    int f = 0, r = -1; // queue parameters; front, rear

    q[++r] = v;
    while(f<=r){
        int u = q[f++];
        for(int i = 0; i < n; i++){
            if(visited[i] == 0 && a[u][i]==1){
                visited[i] = 1;
                q[++r] = i;
            }
        }

        printf("%d\t", u);
    }

}


void main(){
    int v, n;
    printf("Enter number of vertices");
    scanf("%d", &n);

    int a[10][10], visited[10];
    printf("Enter adjacency matrix: \n");
    for(int i = 0; i < n; i++){
        visited[i] = 0;
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter starting vertex: ");
    scanf("%d", &v);
    visited[v] = 1;

    printf("\nReachable nodes are: ");
    bfs(v, n, a, visited);
}