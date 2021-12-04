//
// Created by W0L1D on 11/23/2021.
//


#include <stdio.h>
#include <stdlib.h>




int min(int a, int b){
    if(a<b) return((int)a);
    return((int)b);
}

int main()
{
    int n=5;
    int l=(n*2)-1;
    int mat[l][l];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int v = n-min(i,j);
            mat[i][j] = v;
            if((i<(n-1)) || (j<(n-1))){
                mat[i][l-1-j] = v;
                mat[l-1-i][j] = v;
                mat[l-1-i] [l-1-j] = v;
            }
        }
    }
    for(int i=0;i<l;i++){
        printf("\n");
        for(int j=0;j<l;j++){
            printf("%d ",mat[i][j]);
        }
    }
    return 0;
}
