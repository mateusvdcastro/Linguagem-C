#include <stdio.h>
#include <string.h>

typedef struct{
    char palavra[21];
} Palavras;

void MaxHeapify(Palavras A[], int i, int len);
void BuildMaxHeap(Palavras A[], int len);
void HeapSort(Palavras A[], int len);

int main(void){
    int N, M, i, j, indPalavra;

    //Numero de Palavras
    scanf("%d", &N);
    Palavras vetor[N];

    //Armazenando as Palavras
    for(i=0; i<N; i++){
        scanf("%s", vetor[i].palavra);
    }

    //Verificacao de Caracteres pela tabela ASCII
    for(i=0; i<N; i++){
        for(j=0; j<strlen(vetor[i].palavra); j++){
            //A palavra precisa conter caracter entre "a" at� "z"
            if(vetor[i].palavra[j]<97 || vetor[i].palavra[j]>122){
                printf("a palavra %s eh invalida", vetor[i].palavra);
                return 0;
            }
        }
    }

    scanf("%d", &M);
    Palavras palavrasEscolhidas[M+1];

    for(i=1; i<M+1; i++){
        scanf("%d", &indPalavra);
        strcpy(palavrasEscolhidas[i].palavra, vetor[indPalavra].palavra);
    }

    HeapSort(palavrasEscolhidas, M);

    return 0;
}

void MaxHeapfy(Palavras vPalavra[], int i, int len){
    int esquerda = 2*i;
    int direita = (2*i)+1;
    int maximo;
    char varAux[21];

    if((esquerda <= len) && (strcmp(vPalavra[esquerda].palavra, vPalavra[i].palavra)>0)){
        maximo = esquerda;
    }
    else{
        maximo = i;
    }
    if ((direita <= len) && (strcmp(vPalavra[direita].palavra, vPalavra[maximo].palavra)>0)){
        maximo = direita;
    }
    if (maximo != i){
        //Swap das variaveis
        strcpy(varAux, vPalavra[i].palavra);
        strcpy(vPalavra[i].palavra, vPalavra[maximo].palavra);
        strcpy(vPalavra[maximo].palavra, varAux);

        MaxHeapfy(vPalavra, maximo, len);
    }
}

void BuildMaxHeap(Palavras vPalavra[], int len){
    int i, j;
    for (i = len/2; i > 0; i--){
        MaxHeapfy(vPalavra, i, len);
        if(i==1){
            printf("build_heap:");
            for(j=1; j<len+1; j++){
                printf(" %s", vPalavra[j].palavra);
            }
        }
    }
    printf("\n");
}


void HeapSort(Palavras vPalavra[], int len){
    int i, n, last;
    char maximo[21];
    Palavras V[len+1];
    n = len;

    BuildMaxHeap(vPalavra, len);

    while(len>0){
        strcpy(maximo, vPalavra[1].palavra);
        last = len;
        strcpy(vPalavra[1].palavra, vPalavra[last].palavra);
        MaxHeapfy(vPalavra, 1, len-1);
        strcpy(V[len].palavra, maximo);
        len--;
    }

    printf("palavras:");
    for(i=1; i<n+1; i++){
        printf(" %s", V[i].palavra);
    }

}
