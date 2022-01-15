#include <stdio.h>
#include <locale.h>
int main(){
setlocale(LC_ALL,"");
int matrizA [2][2];
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
return (0);
}
