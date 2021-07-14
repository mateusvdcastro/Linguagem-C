/*
Escreva um programa que receba duas matrizes A e B e retorne C = A ∗ B.
Mateus Vespasiano de Castro RA: 2248751
*/

#include <stdio.h>

main() {


int i, j, linhaA, colunaA, linhaB, colunaB, x;


printf("\n Informe a quntidade de linhas da matriz A: ");
scanf("%d",&linhaA);
printf("\n Informe a quantidade de colunas da matriz A: ");
scanf("%d",&colunaA);
printf("\n Informe a quntidade de linhas da matriz B: ");
scanf("%d",&linhaB);
printf("\n Informe a quantidade de colunas da matriz B: ");
scanf("%d",&colunaB);

float matrizA[linhaA][colunaA], matrizB[linhaB][colunaB], matrizC[linhaA][colunaB], aux = 0;

if(colunaA == linhaB) {

	for(i = 0; i < linhaA; i++) {
		for(j = 0; j < colunaA; j++) {
			printf("\n\n Informe o valor da %d Linha e da %d Coluna da Matriz A: ", i+1, j+1);
			scanf("%f", &matrizA[i][j]);
		}
	}
    printf("\n");

	for(i = 0; i < linhaB; i++) {        
		for(j = 0; j < colunaB; j++) {
			printf("\n\n Informe o valor da %d Linha e da %d Coluna da Matriz B: ", i+1, j+1);
			scanf("%f", &matrizB[i][j]);
		}
	}
    printf("\n");

	for(i = 0; i < linhaA; i++) {
        printf("[");     
		for(j = 0; j < colunaA; j++) {
			printf(" %0.f ", matrizA[i][j]);
		}
		printf("]\n");
	}

    printf("   *   ");
    printf("\n");

	for(i = 0; i < linhaB; i++) {
        printf("[");
		for(j = 0; j < colunaB; j++) {
			printf(" %0.f ", matrizB[i][j]); 
		}
		printf("]\n");
	}

	for(i = 0; i < linhaA; i++) {
		for(j = 0; j < colunaB; j++) {
			
			matrizC[i][j] = 0;
			for(x = 0; x < linhaB; x++) {
				aux +=  matrizA[i][x] * matrizB[x][j];
			}

			matrizC[i][j] = aux;
			aux = 0;
		}
	}
	
    printf("    =  ");
    printf("\n");

	for(i = 0; i < linhaA; i++) {
        printf("[");
		for(j = 0; j < colunaB; j++) {
			printf(" %0.f ", matrizC[i][j]);
		}
		printf("]\n");
	}
	printf("\n\n");
} else {
	printf("\n\n Nao tem como multiplicar as matrizes informadas por coluna A e diferente de B :(");
    printf("\n");
}
}
