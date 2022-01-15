#include <stdio.h>
#define MAX 7

int main(void){

    int vet[MAX];
    vet[0] = 10;
    vet[1] = 22;
    vet[2] = 33;
    vet[6] = 66;

    printf("Vet[0] = %d, Vet[1] = %d, Vet[2] = %d",
    "Vet[6] = %d",vet[0], vet[1], vet[2], vet[6]);

    int i;
    for (i = 0; i<MAX; i ++){
        printf("\nEntre com o valor de Vet[%d] = ", i);
        scanf("%d", &vet[1]);
    }
    i = 0;
    while(i<MAX){
        printf("\nVet[%d]", i, vet[i]);
        i++;
    }

    for(i =0; i<3; i++){
        printf("\nEntre com o valor da posição[%d] = 
        ", i);
        scanf("%f", &posicao[i]);
    }
    for(i=0;i<3; i++){
        printf("\nPosicao[%d] = %f", i, posicao[i])
    }
}
