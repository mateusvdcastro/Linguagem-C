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
void transformaEmMinusculas(char **palavras, int n_palavras){

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
void MaiorePreencheEspacos(char **palavras, int n_palavras, char *maior){

  maior = malloc(21 * sizeof(char *));

  for (int i = 0; i < n_palavras; i++)
  {
    if (i == 0){
      strcpy(maior, palavras[i]);
    }
    if (strlen(palavras[i]) > strlen(maior)){
      strcpy(maior, palavras[i]);
    }
  }
  
  for (int i = 0; i < n_palavras; i++)
  {
    for (int j = 0; j < strlen(maior); j++)
    {
      if (palavras[i][j] < 97 || palavras[i][j] > 122){
        palavras[i][j] = ' ';
      }
    }
  }
}

void CountingSort(char **palavras, char **palavras_ordenadas, int k, int n_palavras){
  int aux_B;
  int *palavras_auxiliares; // vetor C
  int ascii; // A[j]
  // palavras == vetor A
  // palavras_ordenadas == vetor B
  
  palavras_auxiliares = (int *)calloc(k+1, sizeof(int));
  
  // tamanho do vetor palavras
  int n = n_palavras;
  
  
  for (int i = 0; i < k; i++)
  {
    palavras_auxiliares[i] = 0;
  }

  // coloca no vetor c a quantidade de ocorrências 
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 1; j++) // vai ver somente a primeira letra de cada palavra
    {
      //printf("%c\n", palavras[i][j]);
      if (palavras[i][j] <= 122 || palavras[i][j] >= 97){
        ascii = palavras[i][j] - 96;  // ascii == A[j]
        //printf("%d ", ascii);
        palavras_auxiliares[ascii] = palavras_auxiliares[ascii] + 1;
      }
    }
  }
  
  /*
  for (int i = 0; i < k; i++)
  {
    printf("%d %d ", i, palavras_auxiliares[i]);
  } 
  */
  
  for (int i = 0; i < k; i++)
  {
    palavras_auxiliares[i] = palavras_auxiliares[i] + palavras_auxiliares[i-1];
    //printf("%d ", palavras_auxiliares[i]);
  }

  /*
  for (int i = 0; i < k; i++)
  {
    printf("%d ", palavras_auxiliares[i]);
  } 
  */
  
  for (int i = n-1; i >= 0; i--){
    for (int j = 0; j < 1; j++)
    {
    
      ascii = palavras[i][j] - 96;  // ascii == A[j]
      //printf("%d ", ascii);
      aux_B = palavras_auxiliares[ascii];
      strcpy(palavras_ordenadas[aux_B], palavras[ascii]);
      printf("%s ", palavras_ordenadas[aux_B]);
      /*
      palavras_auxiliares[ascii] = palavras_auxiliares[ascii] - 1;
      printf("%d\n", aux_B);
      */
      //palavras_ordenadas[aux_B] = palavras[ascii];
      
    }
    
  }
  /*
  for (int i = 0; i < n; i++)
  {
    printf("%s ", palavras_ordenadas[i]);
  } 
  */
  
}


int main(void)
{

  // k são as 26 letras do alfabeto mais o /n
  int n_palavras, M, k = 27, d;
  char **palavras, *maior_palavra;
  char **palavras_ordenadas;

  scanf("%d\n", &n_palavras);

  // cria um vetor de ponteiros do tipo de char
  palavras = malloc(n_palavras * sizeof(char *));

  // cada posição do vetor aponta para outro vetor
  // 21 pois o limite máximo da palavra são 20 caracteres mais o /n
  for (int i = 0; i < n_palavras; i++)
  {
    palavras[i] = malloc(21 * sizeof(char*));
  }

  palavras_ordenadas = malloc(n_palavras * sizeof(char *));
  for (int i = 0; i < n_palavras; i++)
  {
    palavras_ordenadas[i] = malloc(21 * sizeof(char*));
  }

  for (int i = 0; i < n_palavras; i++)
  {
    scanf("%s\n", palavras[i]);
  }

  transformaEmMinusculas(palavras, n_palavras);
  
  for (int i = 0; i < n_palavras; i++)
  {
    printf("%s.\n", palavras[i]);
  } 

  MaiorePreencheEspacos(palavras, n_palavras, maior_palavra);

  d = strlen(maior_palavra);

  printf("%d\n", d);
  
  CountingSort(palavras, palavras_ordenadas, k, n_palavras);

  int vet[2];

  int n = sizeof(vet) / sizeof(vet[0]);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &vet[i]);
  }  
  
  for (int i = 0; i < n_palavras; i++)
  {
    free(palavras[i]);  // libera os vetores que os ponteiros indicam em cada
    // posição do vetor palavras
  }
  free(palavras); // libera o vetor todo 


  return 0;
}
