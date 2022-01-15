/*
Dado um vetor de tamanho t, faça uma
função que inverta os valores do mesmo.

Mateus Vespasiano de Castro RA: 159505
*/

#include <stdio.h>
#include <stdlib.h>

void inverte(int *v, int t){
    int i;
    for(i=t-1; i>=0; i--)
		{
			printf("v[%d] = %d ", i+1,*(v+i));
		}
}

int main(){
    int *vet;
    int t, i;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &t);
    vet = (int*)calloc(t, sizeof(int));
    for (i=0; i<t; i++){
        printf("Digite o valor de v[%d]: ", i+1);
        scanf("%i", &vet[i]);
    }
    for (i=0; i< t; i++){
        printf("v[%d] = %d ", i+1, vet[i]);  
    }

    printf("\n");
    inverte(vet, t);

}
