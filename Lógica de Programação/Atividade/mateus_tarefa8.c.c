#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");
    system("cls");
    printf("\033[34m");
    int mateus_vetor[7] = {0};
    int mateus_soma, mateus_menor;

    for (int i = 0; i < 7; ++i) {
        printf(" Vetor[%d]: ", i);
        scanf("%d", &mateus_vetor[i]);
    }


    for (int i = 0; i < 7; i++){
        mateus_soma += mateus_vetor[i];
    }

     mateus_menor = mateus_vetor[0];

    for (int i = 0; i < 7; ++i) {
        if (mateus_vetor[i] < mateus_menor) mateus_menor = mateus_vetor[i];
    }

    printf("A soma do vetor em suas 7 posições é %d\n", mateus_soma);
    printf("O menor valor presente no vetor é %d", mateus_menor);
    return (0);
}
