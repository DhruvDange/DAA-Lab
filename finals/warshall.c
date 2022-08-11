#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 10

void warshall(int a[][max], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
            }
        }
    }
}

void print(int a[][max], int n){
    printf("\n");
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

void main()
{

    int a[max][max];
    int n;

    printf("Enter number of vertices");
    scanf("%d", &n);

    printf("Enter adjacency matrix");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    print(a,n);

    warshall(a, n);
    print(a,n);

}