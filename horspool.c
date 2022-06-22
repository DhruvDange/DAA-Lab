#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define max 256

int t[max];

void shiftTable(char p[]){

    int m, i, j;

    m = strlen(p);
    
    for(int i = 0; i < max; i++){
        t[i] = m;
    }

    for(int j = 0; j < m-1; j++){
        t[p[j]] = m-j-1;
    }
}

// int horspool(char src[], char p[])
// {
//     int i, j, k, m, n;
//     n = strlen(src);
//     m = strlen(p);

//     i = m - 1; // lenth - 1

//     while (i < n) // cant traverse if length crossed
//     {
//         k = 0;
//         while ((k < m) && (p[m - 1 - k] == src[i - k])) // k cant exceed pattern length
//             k++;
//         if (k == m)
//             return (i - m + 1);
//         else
//             i += t[src[i]];
//     }
//     return -1;
// }

int horspool(char src[], char p[]){

    int i, j, k ,m ,n;

    n = strlen(src);
    m = strlen(p);

    i = m - 1; // position in src

    while(i < n)
    {
        k = 0;
        while((k<m) && (p[m-1-k] == src[i-k])){
            k++;
        }
        if(k==m){
            return(i-m+1);
        }else{
            i += t[src[i]];
        }
    }
    return -1;
}

void main()
{

    char src[100], p[100];
    int pos;
    printf("Enter the text in which pattern is to be searched:\n");
    gets(src);
    printf("and Enter the pattern to be searched:\n");
    gets(p);
    shiftTable(p);
    pos = horspool(src, p);
    if (pos >= 0)
        printf("\n The desired pattern was found starting from position %d", pos + 1);
    else
        printf("\n The pattern was not found in the given text\n");
}