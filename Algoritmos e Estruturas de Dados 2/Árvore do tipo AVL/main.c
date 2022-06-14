// Nome: Mateus Vespasiano de Castro
// RA: 159505
// Turma: IB

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

// estrutura de um nó de uma árvore binária
typedef struct arv
{
    int info;
    struct arv *esq;
    struct arv *dir;
    int fb;
} TArv;
typedef TArv *PArv;

PArv cria(int c)
{ // cria um nó raiz
    PArv p = (PArv)malloc(sizeof(TArv));
    p->info = c;
    p->esq = NULL;
    p->dir = NULL;
    return p;
}

// imprime a árvore formatada, de melhor visualização
void imprimeT(PArv p, int nivel)
{
    int i;

    if (p == NULL)
        return;

    imprimeT(p->esq, nivel + 1);

    for (i = 0; i < nivel; i++)
        printf("\t");

    printf("%3d\n", p->info);

    imprimeT(p->dir, nivel + 1);
}

// desaloca a árvore da memória
PArv libera(PArv a)
{
    if (a != NULL)
    {
        libera(a->esq); /* libera sae */
        libera(a->dir); /* libera sad */
        free(a);        /* libera raiz */
    }
    return NULL;
}


int altura(PArv arv){
    if(arv == NULL){
        return -1;
    } else {
        int alturaEsq = altura(arv->esq);
        int alturaDir = altura(arv->dir);
        if(alturaEsq > alturaDir){
        return alturaEsq + 1;
        } else {
        return alturaDir + 1;
        }
    }
}

PArv CalculaFatordeBalanceamento(PArv arv){
    if(arv == NULL){
        return arv;
    }
    arv->fb = (altura(arv->dir) - altura(arv->esq));
    return arv;
}

PArv RR(PArv p){
    PArv aux = p->esq;
    p->esq = aux->dir;
    aux->dir = p;
    return aux;
}

PArv LL(PArv p){
    PArv aux = p->dir;
    p->dir = aux->esq;
    aux->esq = p;
    return aux;
}

PArv LR(PArv p){
    PArv aux = p->dir;
    p->dir = RR(aux);
    return LL(p);
}

PArv RL(PArv p){
    PArv aux = p->esq;
    p->esq = LL(aux);
    return RR(p);
}

// insere o nó na árvore principal e retorna a árvore principal
PArv insereABB(PArv arv, PArv no){
  PArv novo;
  if(arv == NULL){ //arvore vazia
    return no;
  } else if(no->info < arv->info){ // insere na ordem, menores à esquerda e maiores à direita
      arv->esq = insereABB(arv->esq, no);
    } else {
        arv->dir = insereABB(arv->dir, no);
      }
  return arv;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int alt;
    PArv arvore=NULL, no;

    int n = 0;

    while(n >= 0) {
        if (n < 0){
            continue;
        } else {
            scanf("%d", &n);
            no = cria(n);
            arvore = insereABB(arvore, no);
        }
    }

    imprimeT(arvore, 0);

    alt = altura(arvore);

    printf("\n%d", alt);

}
