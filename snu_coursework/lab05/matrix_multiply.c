#include <stdio.h>
#include <stdlib.h>

int num;

void multiply(int a[][num], int b[][num], int c[][num], int size){
    int i, j, k;

    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            c[i][j] = 0;
        }
    }

    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            for(k = 0; k < size; k++)
            c[i][j] += a[i][k] * b[k][j];

        }
    }

    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++)
            printf("%d\t", c[i][j]);
        printf("\n");
    }
}

int main(){

    scanf("%d", &num);
    int a[num][num], b[num][num], c[num][num];
    int i,j; 
    for(i = 0; i < num; i++)
        for(j = 0; j < num; j++)
            scanf("%d", &a[i][j]);


    for(i = 0; i < num; i++)
        for(j = 0; j < num; j++)
            scanf("%d", &b[i][j]);

    multiply(a,b,c,num);

    return 0;
}
