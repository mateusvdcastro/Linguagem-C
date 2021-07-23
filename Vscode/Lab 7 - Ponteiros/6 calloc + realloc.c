/*
Mateus Vespasiano de Castro RA: 159505
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *v;
    int i, n;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);
    v = (int*)calloc(n, sizeof(int));
    for (i=0; i< n; i++){
        printf("Insira o elemento %d: ", i+1);
        scanf("%d", &v[i]);    
    }
    for (i=0; i< n; i++){
        printf("a[%d] = %d ", i, v[i]);  
    }

    v = realloc (v, (n+3)*sizeof(int));
    printf("\n");
    for (i = n; i < n+3; i++){
        printf("Insira o elemento %d: ", i+3);
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n+3; i++){
        printf("a[%d] = %d ", i, v[i]);
    }
    free(v);
    return 0;
}
