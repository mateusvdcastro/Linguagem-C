/*
Mateus Vespasiano de Castro
RA: 159505
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

typedef struct lista
{ 
  int info;
  struct lista *prox;
} TLista;
typedef TLista *PLista;


PLista inicializa_lista_s()
{
  return NULL;
}

PLista inicializa_lista()
{
  return NULL;
}

PLista inicializa_lista2()
{
  return NULL;
}

PLista insere_s(PLista l, int i)  // insere na lista encadeada da soma
{
  PLista novo = (PLista)malloc(sizeof(TLista));
  novo->info = i;
  novo->prox = l;
  return novo;
}

PLista insere(PLista l, int i) // insere na lista encadeada do num 1
{
  PLista novo = (PLista)malloc(sizeof(TLista));
  novo->info = i;
  novo->prox = l;
  return novo;
}

PLista insere2(PLista l, int i) // insere na lista encadeada do num 2
{
  PLista novo = (PLista)malloc(sizeof(TLista));
  novo->info = i;
  novo->prox = l;
  return novo;
}

PLista retira_s(PLista l, int v)
{
  PLista ant = NULL; /* ponteiro para elemento anterior */
  PLista p;          /* ponteiro para percorrer a lista*/
  /* procura elemento na lista, guardando anterior */
  for (p = l; p != NULL && p->info != v; p = p->prox)
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

PLista retira(PLista l, int v)
{
  PLista ant = NULL; /* ponteiro para elemento anterior */
  PLista p;          /* ponteiro para percorrer a lista*/
  /* procura elemento na lista, guardando anterior */
  for (p = l; p != NULL && p->info != v; p = p->prox)
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

PLista retira2(PLista l, int v)
{
  PLista ant = NULL; /* ponteiro para elemento anterior */
  PLista p;          /* ponteiro para percorrer a lista*/
  /* procura elemento na lista, guardando anterior */
  for (p = l; p != NULL && p->info != v; p = p->prox)
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
  free(p); // retiro o elemento da lista e libero a memória dele
  return l;
}

void imprime(PLista l)
{
  /* variável auxiliar para percorrer a lista */
  PLista p;
  printf("Numeros registrados na lista encadeada 1: \n");
  printf("=> ");
  for (p = l; p != NULL; p = p->prox)
    printf(" %d", p->info);
  printf("\n");
}

void imprime2(PLista l)
{
  /* variável auxiliar para percorrer a lista */
  PLista p;
  printf("Numeros registrados na lista encadeada 2: \n");
  printf("=> ");
  for (p = l; p != NULL; p = p->prox)
    printf(" %d", p->info);
  printf("\n");
}

void imprime_s(PLista l)
{
  /* variável auxiliar para percorrer a lista */
  PLista p;
  printf("A soma dos numeros deu: \n");
  printf("== ");
  for (p = l; p != NULL; p = p->prox)
    printf("%d", p->info);
  printf("\n");
}

void libera_s(PLista l)
{
  PLista p = l, t;
  while (p != NULL)
  {
    /* guarda referência para o próximo elemento*/
    t = p->prox;
    free(p);
    p = t; /* faz p apontar para o próximo */
  }
}

void libera(PLista l)
{
  PLista p = l, t;
  while (p != NULL)
  {
    /* guarda referência para o próximo elemento*/
    t = p->prox;
    free(p);
    p = t; /* faz p apontar para o próximo */
  }
}

void libera2(PLista l)
{
  PLista p = l, t;
  while (p != NULL)
  {
    /* guarda referência para o próximo elemento*/
    t = p->prox;
    free(p);
    p = t; /* faz p apontar para o próximo */
  }
}

PLista somaListas(PLista p, PLista p2)
{
  int soma;
  int resto = 0;
  char str[3]; //
  PLista aux;
  PLista aux2;

  PLista ps;
  ps = inicializa_lista_s();

  for (aux = p, aux2 = p2; aux != NULL && aux2 != NULL; aux = aux->prox, aux2 = aux2->prox)
  {
    soma = aux->info + aux2->info + resto;
    if (soma >= 10)
    {
      sprintf(str, "%d", soma);
      resto = str[0] - '0';
      soma = str[1] - '0';
    }
    else
    {
      resto = 0;
    }
    ps = insere_s(ps, soma);
  }
  if (resto != 0)
  {
    ps = insere_s(ps, resto);
  }

  return ps;
}


int main()
{
  int count;
  int i = 0;
  char num1[MAX_LENGTH], num2[MAX_LENGTH];
  char numero1_c, numero2_c;
  int numero1_int, numero2_int;
  int val=0, val2=0;

  PLista p;
  PLista p2;
  PLista ps;

  p = inicializa_lista();
  p2 = inicializa_lista2();

  while (val!=1){
    val = 0;
    printf("\nDigite o primeiro numero: ");
    scanf("%s", num1);
    for (i = 0; i < strlen(num1); i++)
    {
      if (isdigit(num1[i])==0){
        printf("\n!!!Entrada invalida, digite novamente.\n");
        val = 3;
        break;
      }
    }
    if (val!=3){
      val = 1;
    }
  }

  
  while (val2!=1){
    val2 = 0;
    printf("\nDigite o segundo numero: ");
    scanf("%s", num2);
    for (i = 0; i < strlen(num2); i++)
    {
      if (isdigit(num2[i])==0){
        printf("\n!!!Entrada invalida, digite novamente.\n");
        val2 = 3;
        break;
      }
    }
    if (val2!=3){
      val2 = 1;
    }
  }
  
  if (strlen(num1) > strlen(num2)){
    count = strlen(num1) - strlen(num2);
  }

  if (strlen(num2) > strlen(num1)){
    count = strlen(num2) - strlen(num1);
  }

  while (count != 0)
  {
    if (strlen(num1) > strlen(num2))
    {
      p2 = insere2(p2, 0);
      count--;
    }
    if (strlen(num2) > strlen(num1))
    {
      p = insere(p, 0);
      count--;
    }
  }

  for (i = 0; i < strlen(num1); i++)
  {
    numero1_c = num1[i];
    numero1_int = numero1_c - '0';
    p = insere(p, numero1_int);
  }

  for (i = 0; i < strlen(num2); i++)
  {
    numero2_c = num2[i];
    numero2_int = numero2_c - '0';
    p2 = insere2(p2, numero2_int);
  }

  printf("\n-------------------------------------------\n\n");
  imprime(p);
  printf("\n");
  imprime2(p2);
  printf("\n-------------------------------------------\n\n");

  ps = somaListas(p, p2);

  printf("===============SOMA=================\n\n");
  imprime_s(ps);
  printf("\n====================================\n");

  libera(p);
  libera2(p2);
  libera_s(ps);
}
