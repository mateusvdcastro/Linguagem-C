/*
Mateus Vespasiano de Castro
RA: 159505
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void swap(char **palavras1, char **palavras2)
{

  char *aux = *palavras1;
  *palavras1 = *palavras2;
  *palavras2 = aux;
}

// Cria uma Max_Heap
void heapify(char **palavras, int n, int i)
{

  int maior = i; // nó root

  int esq = (2 * i) + 1; // filho à esquerda

  int dir = (2 * i) + 2; // filho à direita

  if (esq < n && (strcmp(palavras[esq], palavras[maior]) > 0))
  {
    maior = esq;
  }

  if (dir < n && (strcmp(palavras[dir], palavras[maior]) > 0))
  {
    maior = dir;
  }

  if (maior != i)
  {

    swap(&palavras[i], &palavras[maior]); 

    heapify(palavras, n, maior);
  }
}

void heapSort(char **palavras, int n)
{

  // Buid Heap, em que o maior elemento está no topo e todos os nós filhos
  // são os maiores também em relação aos seus filhos

  for (int i = n / 2 - 1; i >= 0; i--)
  {

    heapify(palavras, n, i);

    if (i == 0)
    {
      printf("build_heap:");
      for (int j = 0; j < n; j++)
      {
        printf(" %s", palavras[j]);
      }
    }
    printf("\n");
  }

  // Heap Sort, o maior elemento do vetor (que está no root) vai para o final do vetor
  for (int i = n - 1; i >= 0; i--)
  {

    swap(&palavras[0], &palavras[i]);

    // Heapify, coloca o maior elemento na raiz novamente

    heapify(palavras, i, 0);

    // i decresce pois a árvore está "diminuindo" (já colocamos palavras no vetor final)
  }

  // Escreve as palavras ordenadas
  printf("palavras:");
  for (int i = 0; i < n; i++)
  {
    printf(" %s", palavras[i]);
  }
}

int main(void)
{

  int n_palavras, M;
  int *vet;
  char **palavras;
  char **palavras_selecionadas;

  scanf("%d\n", &n_palavras);

  // cria um vetor de ponteiros do tipo de char
  palavras = malloc(n_palavras * sizeof(char *));

  // cada posição do vetor aponta para outro vetor
  // 21 pois o limite máximo da palavra são 20 caracteres mais o /n
  for (int i = 0; i < n_palavras; i++)
  {
    palavras[i] = malloc(21 * sizeof(char*));
  }

  for (int i = 0; i < n_palavras; i++)
  {
    scanf("%s", palavras[i]);
  }

  // Verificação de erro usando a tabela ASCII
  // dentre 97 e 122 temos as 26 letras do alfabeto em minúsculas
  for (int i = 0; i < n_palavras; i++)
  {
    for (int j = 0; j < strlen(palavras[i]); j++)
    {
      if (palavras[i][j] < 97 || palavras[i][j] > 122)
      {
        printf("a palavra %s eh invalida", palavras[i]);
        return 0;
      }
    }
  }

  scanf("%d\n", &M);

  vet = (int *)malloc(M * sizeof(int));

  // cria um vetor de ponteiros do tipo de char
  palavras_selecionadas = malloc(M * sizeof(char*));

  for (int i = 0; i < M; i++)
  {
    palavras_selecionadas[i] = malloc(21 * sizeof(char*));
  }

  for (int i = 0; i < M; i++)
  {
    scanf("%d", &vet[i]);
    strcpy(palavras_selecionadas[i], palavras[vet[i]]);
  }

  heapSort(palavras_selecionadas, M);

  for (int i = 0; i < n_palavras; i++)
  {
    free(palavras[i]);  // libera os vetores que os ponteiros indicam em cada
    // posição do vetor palavras
  }
  free(palavras); // libera o vetor todo 

  for (int i = 0; i < M; i++)
  {
    free(palavras_selecionadas[i]);
  }
  free(palavras_selecionadas);

  free(vet);

  return 0;
}

// https://wagnergaspar.com/como-alocar-uma-matriz-dinamica-em-c/
