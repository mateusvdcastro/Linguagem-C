/*
Programa que armazena 64 números inteiros em um vetor, solicita um número chave
K ao usuário e verifica se a chave está entre os 64 números. Em caso positivo, imprima
a posição do vetor em que a chave foi encontrada.
Mateus Vespasiano de Castro RA: 2248751
*/
#include <stdio.h>
#define MAX 64

int main (){
    int vet[MAX], i, K=0;
    printf("Digite o seu valor chave K: ");
    scanf("%d", &K);

    for (i=0; i<MAX; i++){
        vet[i] = i;
    }
    
    for (i=0; i<MAX; i++){
        printf("%d ", vet[i]);
    }

    for (i=0; i<MAX; i++){
        if (K == vet[i]){
            printf("\nA(s) posicao(oes) em que a sua chave se encontra: %d", i);
        }
    }

}

