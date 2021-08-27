#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ponteiros1(){
    int x = 123;
    int *p;
    p = &x;
    printf("Conteudo da variavel x: %d\n", x);
    printf("Endereco da variavel x: %p\n", &x);
    ;
    printf("Conteudo da variavel ponteiro p: %p\n", p);
    printf("Conteudo da variavel apontada pelo ponteiro p: %d\n", *p);
    return 0; 
}

int ponteiros2(){
    int a, b, *p;
    a = 10;
    // p = &a
    *p = 7;
    b = a + (*p);
    printf("%d", b);
    return 0; 
}

int p_calloc(){
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
    free(v);
    return 0;
}

int p_malloc(){
    int *a;
    a = (int*)malloc(1 * sizeof(int));
    *a = 123;     
    free(a);
    return 0;
}

int calloc_realloc(){
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

void inverte(int *v, int t){
    int i;
    for(i=t-1; i>=0; i--)
		{
			printf("v[%d] = %d ", i+1,*(v+i));
		}
}

int inverte_vetor(){
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
    return 0;
}


