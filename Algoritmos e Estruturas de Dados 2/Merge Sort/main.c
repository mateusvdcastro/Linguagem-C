/*
Mateus Vespasiano de Castro
RA: 159505
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

// O melhor e o pior caso de um algoritmo de merge sort é NlogN

struct No
{ 
  int info;
  struct No *prox;
};

void libera(struct No* l)
{
  struct No* t = l;
  struct No* p = l;
  
  while (p != NULL)
  {
    /* guarda referência para o próximo elemento*/
    t = p->prox;
    free(p);
    p = t; /* faz p apontar para o próximo */
  }
}

void printa_lista(struct No* lista){
  struct No* auxiliar = lista;
  
  for (auxiliar = lista; auxiliar != NULL; auxiliar = auxiliar->prox){
    printf("%d ", auxiliar->info);
  }
  printf("\n");
}

// insere no início da lista
void insere_lista(struct No** lista, int num){ 

  struct No* novo = (struct No*)malloc(sizeof(struct No)); 

  if (novo) {
    novo->info = num; // preenche o campo info
    novo->prox = *lista; // o próximo do novo nó aponta para o inicio da lista
    *lista = novo; // o começo da lista passa a ser o novo nó
  }
}

// Aqui foi utilizado o método fast e Slow, essa técnica usa dois ponteiros
// um ponteiro slow que anda um nó e um fast que anda dois nós ao msm tempo,
// o ponteiro slow irá demarcar o meio do vetor quando o fast estiver
// no último nó ou em null
void divide_lista(struct No* chave, struct No** dir, struct No** esq){

  // caso seja passado um vetor nulo ou de tamanho menor que 2
  if (chave == NULL || chave->prox == NULL){
    *dir = chave;
    *esq = NULL;
    return;
  }

  struct No* slow = chave;
  struct No* fast = chave->prox;


  while(fast != NULL && fast->prox != NULL){
    slow = slow->prox;
    fast = fast->prox->prox;      
  }

  // q é sempre o meio do vetor para dividir ele em 2
  *dir = chave;
  *esq = slow->prox;
  slow->prox = NULL;

  //printa_lista(*dir);
  //printa_lista(*esq);
}

// Recebe duas listas ordenadas em ordem crescente e une as duas
struct No* UneListas(struct No* dir, struct No* esq){
  
  if (dir == NULL){
    return esq;
  }
  else if (esq == NULL){
    return dir;
  }

  struct No* resultante = NULL;

  if (dir->info <= esq->info){
    resultante = dir;
    resultante->prox = UneListas(dir->prox, esq);
  }else{
    resultante = esq;
    resultante->prox = UneListas(dir, esq->prox);
  }

  return resultante;
}

// Ordena uma dada lista encadeada usando o merge sort
void mergeSort(struct No** chave){

  // caso seja passado um vetor nulo ou de tamanho 1
  if (*chave == NULL || (*chave)->prox == NULL){
    return;
  }

  struct No* dir;
  struct No* esq;

  divide_lista(*chave, &dir, &esq); // divide a lista "chave" em direita e esquerda

  //printa_lista(dir);
  //printa_lista(esq);

  // ordena as sublistas da direita e esquerda
  mergeSort(&dir);
  mergeSort(&esq);

  *chave = UneListas(dir, esq); // une as listas da direita e da esquerda
}


int main(void) {

  int n;

  struct No* p = NULL;

  scanf("%d", &n);

  int *vetor = malloc(n * sizeof(int));

  for(int i=0; i < n; i++){
    scanf("%d", &vetor[i]);
    //printf("%d", vetor[i]);
    insere_lista(&p, vetor[i]);
  }

  //printa_lista(p);

  mergeSort(&p);

  printa_lista(p);

  free(vetor);

  libera(p);

  return 0;
}
