#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Mateus Vespasiano de Castro RA 159505

// A complexidade do Insertion Sort é no melhor caso O(n) e no pior O(n^2)


// void insertionSort(int *V, int N){
//     int i, j, chave;
//     // A ideia é colocar a direita todos os valores maiores que o valor chave
//     // [i] observado e por fim adicionar o valor chave na posição em que não
//     // temos mais nenhum elemento maior que ele (para isso andamos com j até
//     // o fim do vetor, comparando esse valor com a chave)
//     for (i = 1; i < N; i++){
//         chave = V[i];
//         for (j = i; (j > 0) && (V[j - 1] > chave); j--)
//             V[j] = V[j - 1 ];
//         V[j] = chave;
//     }
// }

int busca_binaria(int *vetor, int ini, int fim, int item, int tamanho)
{

    // printf("\nini %d fim %d item %d tam %d\n", ini, fim, item, tamanho);

    int meio = (ini + fim) / 2;

    // if (ini > fim) return -1;

    if (meio <= 0)
    {
        if (vetor[meio] > item)
        {
        return meio;
        }
        else
        {
        return meio + 1;
        }
    }

    if (vetor[meio] == item)
    {
        return meio;
    }

    if (vetor[meio + 1] < item)
    {
        return busca_binaria(vetor, meio + 1, fim, item, tamanho);
    }

    if (vetor[meio - 1] > item)
    {
        return busca_binaria(vetor, ini, meio - 1, item, tamanho);
    }

    if (vetor[meio] < item && item < vetor[meio + 1])
    {
        return meio + 1;
    }

    if (vetor[meio - 1] < item && item < vetor[meio])
    {
        return meio;
    }
    
    return tamanho;
}

void insertionSortRecursivo(int vet[], int n, int nivel_recursao) 
{
    // Caso base
    if (n <= 0)
        return;

    insertionSortRecursivo(vet, n - 1, ++nivel_recursao);

    int chave = vet[n];

    // printf("\n==> vet%d\n", chave);

    int indice = busca_binaria(vet, 0, n, chave, n);

    // int indice = buscaBinaria(vet, n, chave);

    printf("%d %d %d\n", nivel_recursao, chave, indice);

    // Ordena os primeiros n-1 elementos
    // insertionSortRecursivo(vet, n, nivel_recursao - 1, i + 1);

    // Insere o último elemento na posição correta
    // em um vetor ordenado
    int ultimo = vet[n];
    int j = n - 1;

    /* Move elementos do vetor[0,...,i-1] que são maiores que o valor chave
    para uma posição a frente da sua posição atual  */
    while (j >= indice)
    {
        vet[j + 1] = vet[j];
        j--;
    }
    vet[j + 1] = ultimo;
}

int main()
{
    int n;

    // int vetor[10000];

    scanf("%d", &n);

    int *vetor = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &vetor[i]);

    insertionSortRecursivo(vetor, n - 1, 0);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }

    free(vetor);
    return 0;
}
