/*
Faça um programa usando vetores que leia o nome de 5 pessoas e mostre os
nomes armazenados.

Mateus Vespasiano de Castro RA: 159505
*/

#include <stdio.h>
#include <stdlib.h>
int main( )
{
    char nomes[5][100];
    int i;
    for (i = 0; i < 5; i++){
        printf("Digite o nome %d: ", i+1);
        fgets(nomes[i], 100, stdin);
    }
    printf("\n");
    for (i = 0; i < 5; i++)
        {
        printf("\nNome %i: %s", i+1, nomes[i]);
    }
return 0;
}

