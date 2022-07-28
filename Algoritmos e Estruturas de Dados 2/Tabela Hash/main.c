
#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int num;
    struct item *proximo;
    struct item *anterior;
}Item;

typedef Item *PItem;

void criaTabelaHash(PItem tabelaHash[], int tamanho);
void printaTabelaHash(PItem tabelaHash, int tamanho);
void insereHash(int n, PItem hash[], int tamanho);
int pesquisaHash(PItem hash[], int num, int tamanho);
PItem retornaHashPesquisado(PItem hash[], int num, int tamanho);
void removeItemHash(PItem hash[], PItem num, int tamanho);
void printaLinhaHash(int linha, PItem hash[]);


void criaTabelaHash(PItem tabelaHash[], int tamanho){

    for (int i = 0; i < tamanho; i++){
        tabelaHash[i] = NULL;
    }
}

void printaTabelaHash(PItem tabelaHash, int tamanho){
    int aux;

    PItem p = tabelaHash;

    if (p!=NULL){
        do {
            printf("%d\n", p->num);
            p = p->proximo;
        } while (p!=NULL);
    }
}

// Iremos inserir o novo nó ao final de todos os demais itens
void insereHash(int n, PItem hash[], int tamanho){
    // printf("Insere");

    PItem novo, aux;

    novo = (PItem)malloc(sizeof(Item)); // alocamos o novo nó
    
    
    novo->num = n; // estado inical padrão do nó
    novo->proximo = NULL;
    

    int resto = n % tamanho; // Função Hash - Resto é a posição em que o nó será inserido na tabela hash

    if(hash[resto] == NULL){ // caso seja inserido um nó em um local que não tinha nenhum nó antes
        hash[resto] = novo;
        novo->anterior = NULL;
    } else { // Caso já existas outros itens naquele local
        aux = hash[resto]; // um novo nó que irá ser deslocado até o final da lista como auxiliar para adicionar o novo
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
        novo->anterior = aux;
    }

}

int pesquisaHash(PItem hash[], int num, int tamanho){
    // printf("Pesquisa");
    int indice = num & tamanho;

    PItem s = hash[indice];

    while(s != NULL)
        if (num == s->num) return 1;
    
    return 0;
}

PItem retornaHashPesquisado(PItem hash[], int num, int tamanho){
    // printf("Pesquisa");
    int indice = num & tamanho;

    PItem s = hash[indice];

    while(s != NULL && s->num != num){
        s = s->proximo;
    }

    return s;
}

void removeItemHash(PItem hash[], PItem num, int tamanho){
    // printf("Remove");

    int indice = num->num % tamanho;

    if (hash[indice] == num){
        if(num->proximo == NULL){
            hash[indice] = NULL;
        }
        else {
            hash[indice] = num->proximo;
            num->proximo->anterior = NULL;
        }
    } else {
        if (num->proximo == NULL){
            num->anterior->proximo = NULL;
        } else {
            num->proximo->anterior = num->anterior;
            num->anterior->proximo = num->proximo;
        }
    }
    free(num);
}

void printaLinhaHash(int linha, PItem hash[]){
    PItem linha_Hash;

    printf("[%d]", linha);
    linha_Hash = hash[linha];
    while(linha_Hash != NULL){
        printf(" %d", linha_Hash->num);
        linha_Hash = linha_Hash->proximo;
    }
}

int main(){

    int n, tamanho = 0, pesquisa=0, linhaHash=0;

    scanf("%d", &tamanho);

    PItem pesquisado;
    PItem tabelaHash[tamanho]; 

    criaTabelaHash(tabelaHash, tamanho);

    scanf("%d", &n);
    while (n>=0){
        insereHash(n, tabelaHash, tamanho);
        scanf("%d", &n);
    }

    // printaTabelaHash(*tabelaHash, tamanho);

    scanf("%d", &pesquisa);
    
    pesquisado = retornaHashPesquisado(tabelaHash, pesquisa, tamanho);

    if (pesquisado == NULL){
        printf("Valor nao encontrado\n");
    } else {
        // printf("Achei");
        removeItemHash(tabelaHash, pesquisado, tamanho);
    }

    scanf("%d", &linhaHash);
    printaLinhaHash(linhaHash, tabelaHash);

    return 0;
}
