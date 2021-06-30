#include <stdio.h>

int main(){
    float numero1, numero2, soma;
    printf("Este programa faz a soma de 2 numeros\n");
    printf("------------------------------------------");
    printf("\nLeia o 1: ");
    scanf("%f", &numero1);
    printf("Leia o 2: ");
    scanf("%f", &numero2);
    soma = numero1 + numero2;
    printf("\nA soma e %.1f + %.1f = %.1f", numero1, numero2, soma);
    return(0);
}
