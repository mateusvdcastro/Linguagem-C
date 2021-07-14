/*
Escreva um programa que receba duas matrizes A e B e retorne C = A ∗ B.
Mateus Vespasiano de Castro RA: 2248751
*/

#include <stdio.h>
#include <locale.h>
int main(){
setlocale(LC_ALL,"");
int matrizA [3][4], matrizB [3][4], matrizC[3][4];
int i,j;
printf("Insira os valores para a matriz A 3 x 4: \n");
for (i=0;i<3;i++){
    for (j=0;j<4;j++){
        printf("Linha [%d]: ", i);
        printf("Coluna [%d]: ", j);
        scanf("%d", &matrizA[i][j]);
    }
}
printf("\nA matriz A 3x4: \n");
for (i=0; i<3;i++){
    printf("[");
    for(j=0; j<4; j++){
        printf(" %d ", matrizA[i][j]);
    }
    printf("]\n");
}
printf("\nA matriz B 3x4: \n");
for (i=0;i<3;i++){
    for (j=0;j<4;j++){
        printf("Linha [%d]: ", i);
        printf("Coluna [%d]: ", j);
        scanf("%d", &matrizB[i][j]);
    }
}
for (i=0; i<3;i++){
    printf("[");
    for(j=0; j<4; j++){
        printf(" %d ", matrizB[i][j]);
    }
    printf("]\n");
}
printf("\nA matriz C 3x4: \n");
for (i=0; i<3;i++){
    printf("[");
    for(j=0; j<4; j++){
        matrizC [i][j] = matrizA[i][j] + matrizB [i][j];
        printf(" %d ", matrizC[i][j]);
    }
    printf("]\n");
}
return (0);
}
