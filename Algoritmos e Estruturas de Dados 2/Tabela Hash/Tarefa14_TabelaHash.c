// Eduardo Verissmo Faccio - 148859
// Tarefa Tabela Hash

#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int numero;
    struct item *proximo, *anterior; // Lista encadeada
} Item;

typedef Item *PItem;

void inicializa(PItem tabelaHash[], int tamanho);
void inserir(PItem tabelaHash[], int numero, int tamanho);
void remover(PItem tabelaHash[], PItem num, int tamanho);
PItem procura(PItem tabelaHash[], int num, int tamanho);

void printaTabelaHash(PItem tabelaHash, int tamanho)
{
    int aux;

    PItem p = tabelaHash;

    if (p != NULL)
    {
        do
        {
            printf("%d\n", p->numero);
            p = p->proximo;
        } while (p != NULL);
    }
}

int main(void)
{
    int tamanho, numero;
    scanf("%d", &tamanho);

    PItem tabelaHash[tamanho];
    PItem item;

    inicializa(tabelaHash, tamanho);

    scanf("%d", &numero);
    while (numero != -1)
    {
        inserir(tabelaHash, numero, tamanho);
        scanf("%d", &numero);
    }

    printaTabelaHash(*tabelaHash, tamanho);

    scanf("%d", &numero);
    item = procura(tabelaHash, numero, tamanho);
    if (item == NULL)
    {
        printf("Valor n�o encontrado\n");
    }
    else
    {
        remover(tabelaHash, item, tamanho);
    }

    scanf("%d", &numero);
    printf("[%d]", numero);
    item = tabelaHash[numero];
    while (item != NULL)
    {
        printf(" %d", item->numero);
        item = item->proximo;
    }
    return 0;
}

void inicializa(PItem tabelaHash[], int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        tabelaHash[i] = NULL;
    }
}

void inserir(PItem tabelaHash[], int numero, int tamanho)
{
    int indice;
    PItem aux;

    PItem novoItem = (PItem)malloc(sizeof(Item));
    novoItem->numero = numero;
    novoItem->proximo = NULL;

    indice = numero % tamanho;

    if (tabelaHash[indice] == NULL)
    {
        tabelaHash[indice] = novoItem;
        novoItem->anterior = NULL;
    }
    else
    {
        aux = tabelaHash[indice];
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = novoItem;
        novoItem->anterior = aux;
    }
}

void remover(PItem tabelaHash[], PItem num, int tamanho)
{
    int indice = num->numero % tamanho;

    if (tabelaHash[indice] == num)
    {
        if (num->proximo == NULL)
        {
            tabelaHash[indice] = NULL;
        }
        else
        {
            tabelaHash[indice] = num->proximo;
            num->proximo->anterior = NULL;
        }
    }
    else
    {
        if (num->proximo == NULL)
        {
            num->anterior->proximo = NULL;
        }
        else
        {
            num->proximo->anterior = num->anterior;
            num->anterior->proximo = num->proximo;
        }
    }
    free(num);
}

PItem procura(PItem tabelaHash[], int num, int tamanho)
{
    int indice = num % tamanho;

    PItem aux = tabelaHash[indice];

    while (aux != NULL && aux->numero != num)
    {
        aux = aux->proximo;
    }

    return aux;
}
