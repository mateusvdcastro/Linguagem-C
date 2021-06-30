#include <stdio.h>
#include <locale.h>
int main(){
setlocale(LC_ALL,"");
int matrizA [2][2], matrizB [2][2], matrizC[2][2], matrizD[2][2], valor;
int i,j;
printf("Insira os valores para a matriz B 2 x 2: \n");
for (i=0;i<2;i++){
    for (j=0;j<2;j++){
        printf("Linha [%d]: ", i);
        printf("Coluna [%d]: ", j);
        scanf("%d", &matrizB[i][j]);
    }
}
printf("\nA matriz B 2x2: é\n");
for (i=0; i<2;i++){
    printf("[");
    for(j=0; j<2; j++){
        printf(" %d ", matrizB[i][j]);
    }
    printf("]\n");
}
printf("\nDigite os valores para a matriz C 2x2: é\n");
for (i=0;i<2;i++){
    for (j=0;j<2;j++){
        printf("Linha [%d]: ", i);
        printf("Coluna [%d]: ", j);
        scanf("%d", &matrizC[i][j]);
    }
}
printf("\nA matriz C 2x2: é\n");
for (i=0; i<2;i++){
    printf("[");
    for(j=0; j<2; j++){
        printf(" %d ", matrizC[i][j]);
    }
    printf("]\n");
}
printf("\nDigite os valores para a matriz D 2x2: é\n");
for (i=0;i<2;i++){
    for (j=0;j<2;j++){
        printf("Linha [%d]: ", i);
        printf("Coluna [%d]: ", j);
        scanf("%d", &matrizD[i][j]);
    }
}
printf("\nA matriz D 2x2: é\n");
for (i=0; i<2;i++){
    printf("[");
    for(j=0; j<2; j++){
        printf(" %d ", matrizD[i][j]);
    }
    printf("]\n");
}
printf("\nA matriz A 2x2: é\n");
for (i=0; i<2;i++){
    printf("[");
    for(j=0; j<2; j++){
        valor = matrizB[i][j] - matrizC [i][j];
        matrizA[i][j] = valor;
        matrizA [i][j] = matrizA[i][j] + matrizD[i][j];
        printf(" %d ", matrizA[i][j]);
    }
    printf("]\n");
}
return (0);
}

