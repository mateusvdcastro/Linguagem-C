#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct lista {  // lista que recebe um número digitados pelo usuário
  int info;
  struct lista* prox;
}TLista;
typedef TLista *PLista;

typedef struct lista2 {  // lista que recebe outro número digitados pelo usuário
  int info;
  struct lista2* prox;
}TLista2;
typedef TLista2 *PLista2;


typedef struct listaSoma {  // lista que recebe a soma dos números digitados
  int info;
  struct listaSoma* prox;
}TListasSoma;
typedef TListasSoma *PListaSoma;

PListaSoma inicializa_lista_s(){
  return NULL;
}

PLista inicializa_lista(){
  return NULL;
}

PLista2 inicializa_lista2(){
  return NULL;
}

PListaSoma insere_s(PListaSoma l, int i){
  PListaSoma novo = (PListaSoma) malloc(sizeof(TListasSoma));
  novo->info = i;
  novo->prox = l;
  return novo; 
}

PLista insere(PLista l, int i){
  PLista novo = (PLista) malloc(sizeof(TLista));
  novo->info = i;
  novo->prox = l;
  return novo;
}

PLista2 insere2(PLista2 l, int i){
  PLista2 novo = (PLista2) malloc(sizeof(TLista2));
  novo->info = i;
  novo->prox = l;
  return novo;
}

PListaSoma busca_s(PListaSoma l, int v){
  PListaSoma p;
  for (p=l; p!=NULL; p=p->prox)
      if (p->info == v)
          return p;
  return NULL; /* não achou o elemento */
}

PLista busca (PLista l, int v){
  PLista p;
  for (p=l; p!=NULL; p=p->prox)
      if (p->info == v)
          return p;
  return NULL; /* não achou o elemento */
}

PLista2 busca2 (PLista2 l, int v){
  PLista2 p;
  for (p=l; p!=NULL; p=p->prox)
      if (p->info == v)
          return p;
  return NULL; /* não achou o elemento */
}

PListaSoma retira_s(PListaSoma l, int v){
  PListaSoma ant = NULL; /* ponteiro para elemento anterior */
  PListaSoma p; /* ponteiro para percorrer a lista*/
  /* procura elemento na lista, guardando anterior */
  for (p=l;p!=NULL && p->info!=v; p = p->prox)
      ant = p;
  
  /* verifica se achou elemento */
  if (p == NULL)
      return l; /* não achou: retorna lista original */

  /* retira elemento */
  if (ant == NULL)
      /* retira elemento do inicio */
      l = p->prox;
  else
      /* retira elemento do meio da lista */
      ant->prox = p->prox;
  free(p);
  return l;
}

PLista retira (PLista l, int v){
  PLista ant = NULL; /* ponteiro para elemento anterior */
  PLista p; /* ponteiro para percorrer a lista*/
  /* procura elemento na lista, guardando anterior */
  for (p=l;p!=NULL && p->info!=v; p = p->prox)
      ant = p;
  
  /* verifica se achou elemento */
  if (p == NULL)
      return l; /* não achou: retorna lista original */

  /* retira elemento */
  if (ant == NULL)
      /* retira elemento do inicio */
      l = p->prox;
  else
      /* retira elemento do meio da lista */
      ant->prox = p->prox;
  free(p);
  return l;
}

PLista2 retira2 (PLista2 l, int v){
  PLista2 ant = NULL; /* ponteiro para elemento anterior */
  PLista2 p; /* ponteiro para percorrer a lista*/
  /* procura elemento na lista, guardando anterior */
  for (p=l;p!=NULL && p->info!=v; p = p->prox)
      ant = p;
  
  /* verifica se achou elemento */
  if (p == NULL)
      return l; /* não achou: retorna lista original */

  /* retira elemento */
  if (ant == NULL)
      /* retira elemento do inicio */
      l = p->prox;
  else
      /* retira elemento do meio da lista */
      ant->prox = p->prox;
  free(p);  // retiro o elemento da lista e libero a memória dele
  return l;
}

void imprime (PLista l){
  /* variável auxiliar para percorrer a lista */
  PLista p;

  for (p = l; p != NULL; p = p->prox)
      printf("info = %d\n", p->info);
  printf("\n");
}


void imprime2 (PLista2 l){
  /* variável auxiliar para percorrer a lista */
  PLista2 p;

  for (p = l; p != NULL; p = p->prox)
      printf("info = %d\n", p->info);
  printf("\n");
}


void imprime_s (PListaSoma l){
  /* variável auxiliar para percorrer a lista */
  PListaSoma p;

  for (p = l; p != NULL; p = p->prox)
      printf("info = %d\n", p->info);
  printf("\n");
}

void libera_s(PListaSoma l)
{
  PListaSoma p = l, t;
  while (p != NULL){
      /* guarda referência para o próximo elemento*/
      t = p->prox;
      free(p);
      p = t; /* faz p apontar para o próximo */
  }
}

void libera (PLista l)
{
  PLista p = l, t;
  while (p != NULL){
      /* guarda referência para o próximo elemento*/
      t = p->prox;
      free(p);
      p = t; /* faz p apontar para o próximo */
  }
}

void libera2 (PLista2 l)
{
  PLista2 p = l, t;
  while (p != NULL){
      /* guarda referência para o próximo elemento*/
      t = p->prox;
      free(p);
      p = t; /* faz p apontar para o próximo */
  }
}

PListaSoma somaListas(PLista p, PLista2 p2){
  int soma;
  int resto=0;
  char str[3];  // 
  PLista aux;
  PLista2 aux2;
  
  PListaSoma ps;
  ps = inicializa_lista_s();

  for (aux=p, aux2=p2; aux != NULL && aux2 != NULL; aux=aux->prox, aux2=aux2->prox){
    soma = aux->info + aux2->info + resto;
    if (soma >= 10){
      sprintf(str, "%d", soma);
      resto =  str[0] - '0';
      soma = str[1] - '0';
    } else {
      resto = 0;
    }
    ps = insere_s(ps, soma);
  }
  if (resto != 0){
    ps = insere_s(ps, resto);
  }

  return ps;
}

int main(){
  int i = 0;
  char num1[100], num2[100];
  char numero1_c, numero2_c;
  int numero1_int, numero2_int;

  PLista p;
  PLista2 p2;
  PListaSoma ps;

  p = inicializa_lista();
  p2 = inicializa_lista2();

  printf("Digite o primeiro numero: ");
  scanf("%s", num1);
  
  for (i=0; i< strlen(num1); i++){
      numero1_c = num1[i];
      numero1_int = numero1_c - '0';
      p = insere(p, numero1_int);
  }
  
  //printf("Inteiro de num1: %d", numero1);  // teste do strtol
  
  printf("\nDigite o segundo numero: ");
  scanf("%s", num2);

  for (i=0; i< strlen(num2); i++){
      numero2_c = num2[i];
      numero2_int = numero2_c - '0';
      p2 = insere2(p2, numero2_int);
  }

  printf("\n--------------------------------\n");
  imprime(p);
  printf("--------------------------------\n");
  imprime2(p2);

  ps = somaListas(p, p2);


  printf("--------------SOMA--------------\n");
  imprime_s(ps);

  libera(p);
  libera2(p2);
  libera_s(ps);
}
