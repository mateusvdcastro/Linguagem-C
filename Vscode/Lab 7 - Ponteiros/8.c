#include <stdio.h>
#include <stdlib.h>

void inverte(int *v, int t){
    int i, *aux;
    int cont = 0;
    for (i = t-1; i >=0; i--){
        aux = &v[i];
        printf("Endereco: v[%d] = %i ", i+1, aux);
        printf("Valor do endereco: %i \n", *aux);
    }
    return v;
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

    printf("\n");
    for (i=0; i< t; i++){
        printf("v[%d] = %d ", i+1, vet[i]);  
    }

}
