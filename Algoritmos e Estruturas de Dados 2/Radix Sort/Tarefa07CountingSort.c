//Tarefa 7 - Palavras Ordenadas V 2.0

#include <stdio.h>
#include <string.h>

//Valor para facilitar no Counting Sort
#define ASCII 96

typedef struct{
    char palavra[21];
} PALAVRAS;

//Funcoes dadas pelo monitor
void countingSort(PALAVRAS A[], PALAVRAS B[], int k, int n, int d);
void radixSort(PALAVRAS A[], PALAVRAS B[], int k, int n, int d);

int main(void){
    int i, j, n, m, p, maiorPalavra = 0;

    scanf("%d", &n);
    PALAVRAS vetorA[n+1], vetorB[n+1];

    //Inicio da lista e procurando o tamanho da maior palavra
    for(i=1; i<n+1; i++){
        scanf("%s", vetorA[i].palavra);
        if(strlen(vetorA[i].palavra) > maiorPalavra){
            maiorPalavra = strlen(vetorA[i].palavra);
        }
    }

    //Retirar letras maiusculas
    for(i=1; i<n+1; i++){
        for(j=0; j<strlen(vetorA[i].palavra); j++){
            if(vetorA[i].palavra[j] < 97){
                vetorA[i].palavra[j] = vetorA[i].palavra[j] + 32;
            }
        }
    }

    //Adicionar espacos em branco e ponto final
    for(i=1; i<n+1; i++){
        strcat(vetorA[i].palavra, ".");
        for(j=strlen(vetorA[i].palavra); j<maiorPalavra+1; j++){
            strcat(vetorA[i].palavra, " ");
        }
        printf("%s\n", vetorA[i].palavra);
    }
    printf("%d\n", maiorPalavra);

    radixSort(vetorA, vetorB, 27, n, maiorPalavra);

    scanf("%d %d", &p, &m);
    //Vetor Auxiliar para retirar o ponto final
    PALAVRAS vetorAux[m];

    //Mostrar palavras escolhidas sem o ponto final
    for(i=0; i<m; i++){
        for(j=0; j<strlen(vetorB[p+i].palavra); j++){
            if(vetorB[p+i].palavra[j] == '.'){
                strncpy(vetorAux[i].palavra, vetorB[p+i].palavra, j);
                vetorAux[i].palavra[j] = '\0';
                printf("%s\n", vetorAux[i].palavra);
            }
        }
    }
    return 0;
}

void countingSort(PALAVRAS A[], PALAVRAS B[], int k, int n, int d){
    int C[k], i, j, v_ascii = ASCII;

    for(i=0; i<k; i++){
        C[i] = 0;
    }

    for(j = 1; j<n+1; j++){
        if((A[j].palavra[d] != ' ') && (A[j].palavra[d] != '.')){
            C[A[j].palavra[d] - v_ascii] = C[A[j].palavra[d] - v_ascii]+1;
        }
        else{
            C[0] = C[0]+1;
        }
    }

    for(i=1; i<k; i++){
        C[i] = C[i] + C[i-1];
    }

    //Mostrar vetor C
    printf("%d", C[0]);
    for(i=1; i<27; i++){
        printf(" %d", C[i]);
    }
    printf("\n");

    for(j=n; j>0; j--){
        if((A[j].palavra[d] != 32) && (A[j].palavra[d] != '.')){
            strcpy(B[C[A[j].palavra[d] - v_ascii]].palavra, A[j].palavra);
            C[A[j].palavra[d] - v_ascii] = C[A[j].palavra[d] - v_ascii] - 1;
        }
        else{
            strcpy(B[C[0]].palavra, A[j].palavra);
            C[0] = C[0] - 1;
        }
    }
}

void radixSort(PALAVRAS A[], PALAVRAS B[], int k, int n, int d){
    int i, j;
    for(i=d-1; i>=0; i--){
        countingSort(A, B, k, n, i);
        for(j=1; j<n+1; j++){
            strcpy(A[j].palavra, B[j].palavra);
        }
    }
}
