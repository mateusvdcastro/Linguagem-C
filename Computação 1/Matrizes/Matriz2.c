#include <stdio.h>
#include <locale.h>
int main(){
setlocale(LC_ALL,"");
int matrizA [2][2], matrizB [2][2], matrizC[2][2];
int i,j;
printf("Insira os valores para a matriz 2 x 2: \n");
for (i=0;i<2;i++){
    for (j=0;j<2;j++){
        printf("Linha [%d]: ", i);
        printf("Coluna [%d]: ", j);
        scanf("%d", &matrizA[i][j]);
    }
}
printf("\nA matriz A 2x2: é\n");
for (i=0; i<2;i++){
    printf("[");
    for(j=0; j<2; j++){
        printf(" %d ", matrizA[i][j]);
    }
    printf("]\n");
}
printf("\nA matriz B 2x2: é\n");
for (i=0;i<2;i++){
    for (j=0;j<2;j++){
        printf("Linha [%d]: ", i);
        printf("Coluna [%d]: ", j);
        scanf("%d", &matrizB[i][j]);
    }
}
for (i=0; i<2;i++){
    printf("[");
    for(j=0; j<2; j++){
        printf(" %d ", matrizB[i][j]);
    }
    printf("]\n");
}
printf("\nA matriz C 2x2: é\n");
for (i=0; i<2;i++){
    printf("[");
    for(j=0; j<2; j++){
        matrizC [i][j] = matrizA[i][j] + matrizB [i][j];
        printf(" %d ", matrizC[i][j]);
    }
    printf("]\n");
}
return (0);
}
