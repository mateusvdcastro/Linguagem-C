/*
Mateus Vespasiano de Castro
RA: 159505
Turma: IB
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define MAX 51

typedef struct lista
{ 
  char info;
  struct lista *prox;
} TLista;
typedef TLista *PLista;

PLista inicializa_lista()
{
  return NULL;
}

// inserção no final da lista
PLista insere(PLista ultimo, char val){
  PLista novo = (PLista)malloc(sizeof(TLista));
  novo->info = val;
  if(ultimo==NULL){
    ultimo = novo;
    novo->prox = novo;
  } else{
    novo->prox = ultimo->prox;
    ultimo->prox = novo;
  }
  ultimo = novo;
  return ultimo;
}

PLista pop(PLista ultimo, int *val)  // excluir da lista circular
{
  PLista p;          
  if (ultimo == NULL)
    printf("Pilha vazia!\n\n");
  else{
    p = ultimo->prox;
    *val = p->info;
    ultimo->prox = p->prox;
    if(p==ultimo)
      ultimo = NULL;
    free(p);
  }
  return ultimo;
}

void imprime(PLista ultimo)
{
  /* variável auxiliar para percorrer a lista */
  PLista p;
  if (ultimo!=NULL){
    p = ultimo->prox;
  
    /* percorre os elementos até alcançar novamente o
    início */
    do {
      printf("%c", p->info);
      p = p->prox;
    } while (p != ultimo->prox);
  }
}

void libera(PLista ultimo)  // libera a lista encadeada
{
  PLista p = ultimo->prox;
  PLista q = ultimo;

  while (p != ultimo)
  {
    q=p;
    p = p->prox;
    free(q);
  }
  free(ultimo);
}

void flush(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

int compara(PLista p, char **substrings, int M, char string_ini[51]){
  int num=0, pontuacaoFinal=0, pontuacao=0, contador=0;
  int i, a, j=0, k=0;

  PLista aux;
  PLista aux2;
  
  for(i = 0; i < M; i++){
      j=0; 
      aux = p->prox;  // ficará fixo em uma letra da string principal
      // enquanto o aux2 irá percorrer toda a string comparando com a substring
      aux2 = p->prox;   
      do{ 
          contador = 0;
          for(j=0; j<(strlen(substrings[i])-1); j++){
              if(aux2->info == substrings[i][j]){
                  contador++;
              }
              aux2 = aux2->prox;
          }
          if(contador == (strlen(substrings[i])-1)){
              //Aqui eh substring
              k++;
              num++;

              pontuacao = strlen(substrings[i])-1; // -1 para tirar o \n do fgets

              if (k == 1){
                pontuacaoFinal = pontuacao;
              } else{
                if(pontuacao < pontuacaoFinal){
                  pontuacaoFinal = pontuacao;
                }
              }
              substrings[i][strcspn(substrings[i], "\n")] = 0; //Tirando o '\n' que o fgets deixa no final da string
              printf("\n=> %s é substring de %s\n", substrings[i], string_ini);
          }
          aux = aux->prox;
          aux2 = aux; 
      }while(aux != p->prox);
  }

  printf("\n------------------------------------");
  printf("\nNúmero de Cíclicas: %d", num);
  printf("\nMenor pontuação: %d", pontuacaoFinal);
  printf("\n------------------------------------");
  return num;
}

int main()
{
  setlocale(LC_ALL,"");
  int i,  M=0, val;
  char string_ini[MAX], str_c;
  char **substrings;

  PLista p;

  p = inicializa_lista();

  printf("\nDigite a string inicial (somente letras minúsculas): ");
  scanf("%s", string_ini);

  for (i = 0; i < strlen(string_ini); i++)
  {
    str_c = string_ini[i];
    p = insere(p, str_c);
  }

  printf("----------------------------------------\n");
  imprime(p);  // imprime a lista cíclica
  printf("\n----------------------------------------");

  printf("\n\nDigite o tamanho do conjunto de substrings: ");
  scanf("%d", &M);
  flush();
  
  val = 0;
  while (val!=1){
    if (M == 0 || M < 0){
      printf("\nNúmero inválido, digite novamente: ");
      scanf("%d", &M);
    } else val = 1;
  }
  

  val = 0;

  substrings = malloc((M+1) * sizeof(*substrings));  // alocando a matriz dinâmica

  printf("\nDigite, a seguir, as substrings (uma por linha e todas com letras minúsculas): \n");

  for(i=0; i<M; i++){
    substrings[i] = malloc(51 * sizeof(*substrings[i]));  // alocando cada linha da matriz, que irá guardar cada substring por linha
  }

  for (i=0; i<M; i++){
    printf("\nDigite a %d substring: \n", i+1);
    fgets(substrings[i], MAX, stdin);  // guardando cada substring na matriz
  }
  /*
  for(i=0; i<M; i++){
    printf("string %d: %s", i+1, substrings[i]);
  }
  */
  compara(p, substrings, M, string_ini);

  for(i=0; i<M; i++){  // libera cada linha da matriz dinâmica
    free(substrings[i]);
  }

  free(substrings);  // libera a matriz inteira
  libera(p);  // libera a lista ciclica
}
