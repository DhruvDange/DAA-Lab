#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

int st[MAX];

void shiftTable(char p[]){
    int len = strlen(p);
    for(int i = 0; i < MAX; i++){
        st[i] = len;
    }

    for(int i = 0; i < len-1; i++){
        st[p[i]] = len-i-1;
    }
}

int horspool(char txt[], char p[]){

    int n = strlen(txt);
    int m = strlen(p);

    int i = m-1; // position in txt

    while(i < n){
        int k = 0;
        while(k<m && txt[i-k] == p[m - k - 1]){
            k++;
        }
        if(k == m){
            return(i-m+1);
        }else{
            i += st[txt[i]];
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