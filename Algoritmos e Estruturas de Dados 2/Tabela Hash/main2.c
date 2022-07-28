/*
Mateus Vespasiano de Castro
RA: 159505
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int numero;
    struct item *proximo;
    struct item *anterior;
} Item;

typedef Item *PItem;

void inicializa(PItem tabelaHash[], int tamanho);
void printaTabelaHash(PItem tabelaHash, int tamanho);
void inserir(PItem tabelaHash[], int numero, int tamanho);
void remover(PItem tabelaHash[], PItem num, int tamanho);
PItem procura(PItem tabelaHash[], int num, int tamanho);
int pesquisaHash(PItem hash[], int num, int tamanho);
void printaLinhaHash(int linha, PItem hash[]);

int main(void)
{
    int tamanho, n;

    scanf("%d", &tamanho);

    PItem tabelaHash[tamanho];
    PItem pesquisado;

    inicializa(tabelaHash, tamanho);

    scanf("%d", &n);
    while (n >= 0)
    {
        inserir(tabelaHash, n, tamanho);
        scanf("%d", &n);
    }

    // printaTabelaHash(*tabelaHash, tamanho);

    scanf("%d", &n);

    pesquisado = procura(tabelaHash, n, tamanho);

    if (pesquisado != NULL) {
        remover(tabelaHash, pesquisado, tamanho);
    }
    else {
        printf("Valor nao encontrado\n");
    }

    scanf("%d", &n);

    printaLinhaHash(n, tabelaHash);
    
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

int pesquisaHash(PItem hash[], int num, int tamanho){
    // printf("Pesquisa");
    int indice = num & tamanho;

    PItem s = hash[indice];

    while(s != NULL)
        if (num == s->numero) return 1;
    
    return 0;
}

void inserir(PItem tabelaHash[], int numero, int tamanho)
{
    int indice;

    PItem aux;

    PItem novo = (PItem)malloc(sizeof(Item)); // alocamos o novo nó

    novo->numero = numero; // estado inical padrão do nó
    novo->proximo = NULL;

    indice = numero % tamanho; // Função Hash - Resto é a posição em que o nó será inserido na tabela hash

    if (tabelaHash[indice] == NULL)
    { // caso seja inserido um nó em um local que não tinha nenhum nó antes
        tabelaHash[indice] = novo;
        novo->anterior = NULL;
    }
    else
    { // Caso já existas outros itens naquele local
        aux = tabelaHash[indice]; // um novo nó que irá ser deslocado até o final da lista como auxiliar para adicionar o novo
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = novo;
        novo->anterior = aux;
    }
}

void printaLinhaHash(int linha, PItem hash[]){
    PItem linha_Hash;

    printf("[%d]", linha);
    linha_Hash = hash[linha];
    while(linha_Hash != NULL){
        printf(" %d", linha_Hash->numero);
        linha_Hash = linha_Hash->proximo;
    }
}

void remover(PItem tabelaHash[], PItem num, int tamanho)
{
    // printf("Remove");

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
