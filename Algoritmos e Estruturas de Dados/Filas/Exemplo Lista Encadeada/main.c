/*
➢Faça um programa que insira os elementos em
ordem crescente, mesmo o usuário ditando os
elementos desordenadamente. Ele deve permitir
também a retirada de elementos, conservando a
lista ordenada. O programa deve ter também as
opções de imprimir e de buscar um elemento.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    struct lista *prox;
} TLista;
typedef TLista *PLista;

PLista inicializa_lista()
{
    return NULL;
}

PLista insere(PLista l, int i)
{
    PLista novo = (PLista)malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

PLista busca(PLista l, int v)
{
    PLista p;
    for (p = l; p != NULL; p = p->prox)
        if (p->info == v)
            return p;
    return NULL; /* não achou o elemento */
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

void imprime(PLista l)
{
    /* variável auxiliar para percorrer a lista */
    PLista p;

    for (p = l; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
    printf("\n");
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

PLista Insere_ord(PLista l, int dado)
{
    PLista novo, ant = NULL, paux = l;
    /* aloca um novo nó */
    novo = (PLista)malloc(sizeof(TLista));
    novo->info = dado; /*insere a informação no novo nó*/
    /*procurando a posição de inserção*/
    while ((paux != NULL) && (paux->info) < dado)
    {
        ant = paux;
        paux = paux->prox;
    }
    /*encadeia o elemento*/
    if (ant == NULL)
    {
        /*se o anterior não existe, será inserido na 1a posição*/
        novo->prox = l;
        l = novo;
    }
    else
    { /* senão, o elemento será inserido no meio da lista*/
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return (l);
}
/*
void main(){
    printf();
}

*/
