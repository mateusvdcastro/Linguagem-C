/*
Mateus Vespasiano de Castro
RA: 159505
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

// Converter as letras maiúsculas para minúsculas
void transformaEmMinusculas(char **palavras, int n_palavras)
{

  char **palavras_min;

  for (int i = 0; i < n_palavras; i++)
  {
    for (int j = 0; j < strlen(palavras[i]); j++)
    {
      palavras[i][j] = tolower(palavras[i][j]); // Essa função da biblioteca ctype, recebe um caracter e o transforma em minúsculo caso esteja em maiúsculo
    }
  }
}

// Econtra a maior palavra e preenche com espaços em branco as outras palavras do vetor para que fiquem do mesmo tamanho da primeira
int MaiorePreencheEspacos(char **palavras, int n_palavras)
{
  int maior;

  for (int i = 0; i < n_palavras; i++)
  {
    if (i == 0)
    {
      maior = strlen(palavras[i]);
    }
    if (strlen(palavras[i]) > maior)
    {
      maior = strlen(palavras[i]);
    }
  }

  for (int i = 0; i < n_palavras; i++)
  {
    for (int j = strlen(palavras[i]); j < maior; j++)
    {
      if (palavras[i][j] < 97 || palavras[i][j] > 122)
      {
        palavras[i][j] = ' ';
      }
    }
  }

  return maior;
}

void CountingSort(char **A, char **B, int k, int n_palavras, int d)
{

  int aux_B;
  int ascii; // A[j]
  int C[k];

  // tamanho do vetor palavras
  int n = n_palavras;

  for (int i = 0; i < k; i++)
  {
    C[i] = 0;
  }

  // coloca no vetor c a quantidade de ocorrências
  for (int i = 0; i < n; i++)
  {
    // printf("\n[%d][%d]: %c ", i, d, palavras[i][d]);
    if (A[i][d] <= 122 && A[i][d] >= 97)
    {
      ascii = A[i][d] - 96; // ascii == A[j]
      C[ascii] = C[ascii] + 1;
    }
    else
    { // para caso seja espaço
      C[0] = C[0] + 1;
    }
  }

  for (int i = 1; i < k; i++)
  {
    C[i] = C[i] + C[i - 1]; // Soma préfixa
  }

  for (int i = 0; i < k; i++)
  {
    printf("%d ", C[i]);
  }

  printf("\n");

  for (int i = n - 1; i >= 0; i--)
  {
    if (A[i][d] <= 122 && A[i][d] >= 97)
    {
      ascii = A[i][d] - 96; // ascii == A[j]
      aux_B = C[ascii] - 1;
      B[aux_B] = A[i];
      C[ascii] = C[ascii] - 1;
    }
    else
    {
      // caso seja espaço
      B[C[0] - 1] = A[i];
      C[0] = C[0] - 1;
    }
  }

  for (int j = 0; j < n; j++)
  {
    A[j] = B[j];
  }
}

void RadixSort(char **A, char **B, int k, int d, int n)
{

  for (int i = d - 1; i >= 0; i--)
  {
    CountingSort(A, B, 27, n, i);
  }
}

int main(void)
{

  // k são as 26 letras do alfabeto mais o /n
  int n_palavras, M, k = 27, d;
  char **A;
  char **B;

  scanf("%d\n", &n_palavras);

  // cria um vetor de ponteiros do tipo de char
  A = malloc(n_palavras * sizeof(char *));

  // cada posição do vetor aponta para outro vetor
  // 21 pois o limite máximo da palavra são 20 caracteres mais o /n
  for (int i = 0; i < n_palavras; i++)
  {
    A[i] = malloc(21 * sizeof(char *));
  }

  for (int i = 0; i < n_palavras; i++)
  {
    scanf("%s\n", A[i]);
  }

  B = malloc(n_palavras * sizeof(char *));

  for (int i = 0; i < n_palavras; i++)
  {
    B[i] = malloc(21 * sizeof(char *));
  }

  transformaEmMinusculas(A, n_palavras);

  for (int i = 0; i < n_palavras; i++)
  {
    printf("%s.\n", A[i]);
  }

  d = MaiorePreencheEspacos(A, n_palavras);

  printf("%d\n", d);

  RadixSort(A, B, k, d, n_palavras);

  int vet[2];

  int n = sizeof(vet) / sizeof(vet[0]);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &vet[i]);
  }

  for (int i = vet[0] - 1; i < vet[0] + vet[1] - 1; i++)
  {
    printf("%s\n", B[i]);
  }

  for (int i = 0; i < n_palavras; i++)
  {
    free(A[i]); // libera os vetores que os ponteiros indicam em cada
    // posição do vetor palavras
  }
  free(A); // libera o vetor todo

  for (int i = 0; i < n_palavras; i++)
  {
    free(B[i]); // libera os vetores que os ponteiros indicam em cada
    // posição do vetor palavras
  }
  free(B); // libera o vetor todo

  return 0;
}
