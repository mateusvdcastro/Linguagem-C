#include <stdio.h>

/*Programa que soma de todos os números ímpares que são múltiplos de 3 e que se
encontram no intervalo de dois números dados pelo usuário
Mateus Vespasiano de Castro RA: 2248751*/

int main(){
    int n1, n2;

    printf("Digite um intervalo com numeros inteiros: ");
    scanf("%d %d", &n1, &n2);

    int i;
    int soma = 0;

    for (i = n1; i <= n2; i++){
        if (i % 2 != 0 && i % 3 == 0){
            printf("%d ", i);
            soma = soma + i;
        }
    }
    printf("\nA soma dos multiplos de 3 e impares deu: %d", soma);
}
