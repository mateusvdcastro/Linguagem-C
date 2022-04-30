#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Mateus Vespasiano de Castro RA 159505

// A complexidade do Insertion Sort é no melhor caso O(n) e no pior O(n^2)

void flush()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}

void insertionSort(int *V, int N){
    int i, j, chave;
    // A ideia é colocar a direita todos os valores maiores que o valor chave 
    // [i] observado e por fim adicionar o valor chave na posição em que não 
    // temos mais nenhum elemento maior que ele (para isso andamos com j até
    // o fim do vetor, comparando esse valor com a chave)
    for (i = 1; i < N; i++){
        chave = V[i];
        for (j = i; (j > 0) && (V[j - 1] > chave); j--)
            V[j] = V[j - 1 ];
        V[j] = chave;
    }
}

void insertionSortRecursivo(int *V, int N, int i, int j, int chave){
    int i, j, chave;

    if (i < N) {
        insertionSortRecursivo(V, N,  i++, j, V[i]);
        if ((j > 0) && (V[j] - 1) > chave){

        }
    }
}

int busca_binaria(int vetor[], int ini, int fim, int item, int *rec)
{

    (*rec)++;

    int meio = (ini + fim) / 2;

    if (ini > fim)
    {
        return -1;
    }

    if (vetor[meio] == item)
    {
        return *rec;
    }

    if (vetor[meio] < item)
    {
        return busca_binaria(vetor, meio + 1, fim, item, rec);
    }
    else
    {
        return busca_binaria(vetor, ini, meio - 1, item, rec);
    }
}

int main()
{
    int n;

    int *vetor = malloc(n * sizeof(int));
    
    int resultado;
  
    scanf("%d", &n);
    flush();

    for(int i=0; i < n; i++)
      scanf("%d", &vetor[i]);
    flush();


    free(vetor);

    return 0;
}
