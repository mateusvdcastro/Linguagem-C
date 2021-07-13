/*
Dados dois vetores v1 e v2, ambos com 5 elementos, determinar o produto escalar
destes vetores.
Mateus Vespasiano de Castro RA: 2248751
*/


# include <stdio.h>
#define MAX 5

int main(){
    int v1[MAX] = {5, 10, 2, 3, 9};
    int v2[MAX] = {10, 20, 4, 6, 18};
    int i, prod=0;
    
    printf("V1: ");
    for (i=0; i<MAX;i++){
        printf(" %d ", v1[i]);
    }
    printf("\nV2: ");
    for (i=0; i<MAX;i++){
        printf(" %d ", v2[i]);
    }

    for (i=0; i < MAX; i++){
        prod = prod + (v1[i]*v2[i]);
    }
    printf("\nV3 Produto Escalar: %d", prod);

}


