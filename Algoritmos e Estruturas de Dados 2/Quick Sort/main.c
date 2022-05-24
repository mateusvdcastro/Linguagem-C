/*
Mateus Vespasiano de Castro
RA: 159505
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void swap(int vet[], int i, int j)
{
  int aux = vet[i];
  vet[i] = vet[j];
  vet[j] = aux;
}

// retorna o índice q (local em que o pivô foi colocado no vetor ao final do
// partition)
int partition(int vet[], int ini, int fim)
{
  // Aqui, q e j começam no mesmo índice (começo do vetor) e caminham juntos
  // enquanto o valor do V[j] não for maior que o pivô, caso isso ocorra,
  // somente j é acrescido - condição que não entra no if (vet[j] <= pivo).
  // Se V[j] for menor ou igual ao pivô caminhamos com i e j juntos e trocamos
  // V[q] por V[j] (elemento mais a esquerda)

  int pivo, q;
  // pivô = último elemento
  pivo = vet[fim];
  q = ini;

  for (int j = ini; j < fim; j++)
  {
    if (vet[j] <= pivo)
    {
      swap(vet, q, j);
      q = q + 1;
    }
  }

  swap(vet, q, fim); // por fim colocamos o pivô no local em que todos os
  // elementos a direita dele são maiores que ele e a esquerda menores (esse
  // local é o índice retornado por q)

  return (q); // Por fim, retornamos esse índice descrito acima
}

void quicksort(int vet[], int ini, int fim, int k)
{
  // Nessa função utilizamos o quick sort com particionamento em tempo linear
  int q;

  // rec vai calcular o nível da recursão

  if (ini < fim)
  {

    q = partition(vet, ini, fim);

    if (q >= k)
    { // ordenada a parte da direita do vetor caso o índice do pivô
      // seja maior que a posição de interesse
      quicksort(vet, ini, q - 1, k);
    }
    else if (vet[q] == vet[k - 1])
    { // encerra o código, pois o vetor já está
      // ordenado da maneira que o exercício pede
      return;
    }
    else if (q < k)
    { // Ordena a parte da esquerda do Vetor caso o índice
      // do pivô seja menor que a posição alvo k
      quicksort(vet, q + 1, fim, k);
    }
  }
}

int main(void)
{

  int n, k;
  int *vetor;

  scanf("%d\n", &k); // elemento na posição de interesse K

  scanf("%d", &n); // Quantidade de número de chaves

  vetor = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &vetor[i]);
  }

  quicksort(vetor, 0, n - 1, k);

  printf("%do menor elemento eh o %d\n", k, vetor[k - 1]);

  for (int i = 0; i < n; i++)
  {
    printf("%d ", vetor[i]);
  }

  free(vetor);

  return 0;
}
