// Nome: Mateus Vespasiano de Castro
// RA: 159505
// Turma: IB
 
#include <stdio.h>
#include <stdlib.h>
 
#define RED 1
#define BLACK 0
 
// estrutura de um nó de uma árvore rublo negra
typedef struct arv
{
    int info;
    struct arv *esq;
    struct arv *dir;
    struct arv *pai;
    int cor;
} TArv;
typedef TArv *ArvLLRB;
 
 
ArvLLRB arvore = NULL;
 
/*
1 - Todo nó é rubro ou negro
2 - A raiz é negra
3 - Toda folha (NULL) é negra
4 - Se um nó é rubro, então ambos os seus filhos são negros
5 - Para cada nó, todos os caminhos desde um nó até as folhas descendestes
contêm o mesmo número de nós negros (black-height)
*/
 
// Acessando a cor de um nó
int cor(ArvLLRB H)
{
    if (H == NULL)
        return BLACK;
    else
        return H->cor;
}
 
// Inveter a cor do pai e de seus filhos
// É uma operação "administrativa": não altera a estrutura ou conteúdo da
// árvore
void trocaCor(ArvLLRB H)
{
    printf("=> %d\n", H->cor);
    H->cor = !H->cor;
    if (H->esq != NULL)
        H->esq->cor = !H->esq->cor;
    if (H->dir != NULL)
    {
        H->dir->cor = !H->dir->cor;
    }
}
 
// !!! Ao rotacionar a árvore você irá criar uma violação de cores, portanto,
// devemos usar uma função de troca de cores ou rotacionar novamente, depende
// do problema em questão
 
/*
Recebe um nó "A" com "B" como filho direito, move B para o lugar de A,
A se torna o filho esquerdo de B, B recebe a cor de A, A fica vermelho
*/
void rotacionaEsquerda(ArvLLRB no)
{
    // ArvLLRB B = A->dir;
    // A->dir = B->esq;
    // B->esq = A;
    // B->cor = A->cor;
    // A->cor = RED;
    // return B;
 
    ArvLLRB noDir = no->dir;
    no->dir = noDir->esq;
 
    if(no->dir){
        no->dir->pai = no;
    }
    noDir->pai = no->pai;
 
    if(no->pai == NULL){
        arvore = noDir;
    }
    else if(no == no->pai->esq){
        no->pai->esq = noDir;
    }
    else{
        no->pai->dir = noDir;
    }
    noDir->esq = no;
    no->pai = noDir;
}
 
/*
Recebe um nó "A" com "B" como filho a esquerda, move B para o lugar de A, A se
torna o filho direito de B,
B recebe a cor de A, A fica vermelho
*/
void rotacionaDireita(ArvLLRB no)
{
    // ArvLLRB B = A->esq;
    // A->esq = B->dir;
    // B->dir = A;
    // B->cor = A->cor;
    // A->cor = RED;
    // return B;
  
    ArvLLRB noEsq = no->esq;
    no->esq = noEsq->dir;
 
    if(no->esq){
        no->esq->pai = no;
    }
    noEsq->pai = no->pai;
 
    if(no->pai == NULL){
        arvore = noEsq;
    }
    else if(no == no->pai->esq){
        no->pai->esq = noEsq;
    }
    else{
        no->pai->dir = noEsq;
    }
    noEsq->dir = no;
    no->pai = noEsq;
}
 
// imprime a árvore formatada, de melhor visualização
void imprimeT(ArvLLRB p, int nivel)
{
    int i;
 
    if (p == NULL)
        return;
 
    imprimeT(p->esq, nivel + 1);
 
    for (i = 0; i < nivel; i++)
        printf("\t");
 
    printf("%3d (%d)\n", p->info, p->cor);
 
    imprimeT(p->dir, nivel + 1);
}
 
// desaloca os nós da árvore da memória
void libera(ArvLLRB a)
{
    if (a != NULL)
    {
        libera(a->esq); /* libera sae */
        libera(a->dir); /* libera sad */
        free(a);        /* libera raiz */
        a = NULL;
    }
    return;
}
 
// Busca na árvore binária um valor desejado e retorna o nó em que ele se encontra
ArvLLRB RetornaNoDesejado(ArvLLRB arv, int num)
{
    if (arv == NULL)
    {
        return NULL;
    }
    if (arv->info == num)
    {
        return arv;
    }
    if (arv->info > num)
    {
        return RetornaNoDesejado(arv->esq, num);
    }
    return RetornaNoDesejado(arv->dir, num);
}
 
ArvLLRB cria(int num){
    ArvLLRB novo;
    novo = (ArvLLRB)malloc(sizeof(TArv));
  
    novo->info = num;
    novo->pai = novo->dir = novo->esq = NULL;
    novo->cor = RED;
    return novo;
}
 
ArvLLRB insereAVP(ArvLLRB arv , ArvLLRB no){
    if (arv == NULL){
        return(no);
    }
    if (no->info < arv->info){
        arv->esq = insereAVP(arv->esq, no);
        arv->esq->pai = arv;
    }
    else if(no->info > arv->info){
        arv->dir = insereAVP(arv->dir, no);
        arv->dir->pai = arv;
    }
 
    return(arv);
}
 
void Balanceia(ArvLLRB raiz, ArvLLRB no){
    ArvLLRB paiNo = NULL;
    ArvLLRB avoNo = NULL;
 
    while((no != raiz) && (no->cor != BLACK) && (no->pai->cor == RED)){
      paiNo = no->pai;
      avoNo = no->pai->pai;
 
      if(paiNo == avoNo->esq){
          ArvLLRB tioNo = avoNo->dir;
 
          if((tioNo != NULL) && (tioNo->cor == 1)){
              avoNo->cor = RED;
              paiNo->cor = BLACK;
              tioNo->cor = BLACK;
              no = avoNo;
          }
          else{
              if(no == paiNo->dir){
                  rotacionaEsquerda(paiNo);
                  no = paiNo;
                  paiNo = no->pai;
              }
 
              rotacionaDireita(avoNo);
              int aux = paiNo->cor;
              paiNo->cor = avoNo->cor;
              avoNo->cor = aux;
              no = paiNo;
          }
      }
      else{
          ArvLLRB tioNo = avoNo->esq;
 
          if((tioNo != NULL) && (tioNo->cor == RED)){
              avoNo->cor = RED;
              paiNo->cor = BLACK;
              tioNo->cor = BLACK;
              no = avoNo;
          }
          else{
              if(no == paiNo->esq){
                  rotacionaDireita(paiNo);
                  no = paiNo;
                  paiNo = no->pai;
              }
 
              rotacionaEsquerda(avoNo);
              int aux = paiNo->cor;
              paiNo->cor = avoNo->cor;
              avoNo->cor = aux;
              no = paiNo;
          }
      }
  }
  arvore->cor = BLACK;
}
 
ArvLLRB balancear(ArvLLRB H){
    // Nó vermelho é sempre filho a esquerda
    if(cor(H->dir) == RED)
        rotacionaEsquerda(H);
 
    //Filho da esquerda e neto da esquerda são vermelhos
    if(H->esq != NULL && cor(H->esq) == RED && cor(H->esq->esq) == RED)
        rotacionaDireita(H);
 
    //2 filhos Vermelhos: troca cor!
    if(cor(H->esq) == RED && cor(H->dir) == RED)
        trocaCor(H);
 
    return H;
    
}
 
ArvLLRB Move2EsqRED(ArvLLRB H){
    trocaCor(H);
    if (cor(H->dir->esq) == RED){
        rotacionaDireita(H->dir);
        rotacionaEsquerda(H);
        trocaCor(H);
    }
 
    return H;
}
 
 
int BuscaAVP(ArvLLRB arv, int valor)
{
    if (arv == NULL)
    {
        return 0; /* árvore vazia */
    }
    else if (valor == arv->info)
    {
        return 1; // encontrou a informação
    }
    else if (valor < arv->info)
    {
        return BuscaAVP(arv->esq, valor);
    }
    else
    {
        return BuscaAVP(arv->dir, valor);
    }
}
 
int altura(ArvLLRB arv)
{
    if (arv == NULL)
    {
        return 0;
    }
    else
    {
        int alturaEsq = altura(arv->esq);
        int alturaDir = altura(arv->dir);
        if (alturaEsq > alturaDir)
        {
            return alturaEsq + 1;
        }
        else
        {
            return alturaDir + 1;
        }
    }
}
 
 
void verificaAltura(ArvLLRB raiz){
    int max, min;
 
    if(raiz->dir != NULL){
        max = altura(raiz->dir);
    }
    else{
        max = 0;
    }
 
    if(raiz->esq != NULL){
        min = altura(raiz->esq);
    }
    else{
        min = 0;
    }
 
    if(min > max){
        printf("%d, %d, %d\n", min, min, max);
    }
    else{
        printf("%d, %d, %d\n", max, min, max);
    }
 
}
 
// Faz o mesmo que a buscaAVP mas retorna o nó que contém o item desejado
ArvLLRB verifica(ArvLLRB raizArvore, int n){
    if (raizArvore == NULL){
        return NULL;
    }
    if (raizArvore->info == n) {
        return(raizArvore);
    }
    if (raizArvore->info > n){
        return(verifica(raizArvore->esq, n));
    }else {
      return(verifica(raizArvore->dir, n));
    }
}
 
 
int alturaNegra(ArvLLRB arv){
    int alturaDireita, alturaEsquerda;
 
    if(arv == NULL){
        return 0;
    }
 
    alturaEsquerda = alturaNegra(arv->esq);
    alturaDireita = alturaNegra(arv->dir);
 
    if(arv->cor == 0){
        if(alturaEsquerda > alturaDireita){
            return alturaEsquerda + 1;
        }
        else{
            return alturaDireita + 1;
        }
    }
    else{
        if(alturaEsquerda > alturaDireita){
            return alturaEsquerda;
        }
        else{
            return alturaDireita;
        }
    }
}
 
int main()
{
    int max, min;
    ArvLLRB no, no2;
    ArvLLRB n_pesquisar, n_pesquisar2;
 
    int n = 0, n2 = 0, n3 = 0;
 
    scanf("%d", &n);
 
    while (n >= 0)
    {
 
        no = cria(n);
        arvore = insereAVP(arvore, no);
 
        Balanceia(arvore, no);
      
        scanf("%d", &n);
    }
 
    //imprimeT(arvore, 0);
 
    verificaAltura(arvore);
 
    scanf("%d", &n2);
 
    while (n2 >= 0)
    {
 
        if (BuscaAVP(arvore, n2) == 1)
        {
            // printf("Numero encontrado");
            n_pesquisar = verifica(arvore, n2);
            verificaAltura(n_pesquisar);
        }
        else
        {
            // printf("O numero nao encontrado sera adicionado");
            no2 = cria(n2);
            arvore = insereAVP(arvore, no2);
            Balanceia(arvore, no2);
        }
 
        scanf("%d", &n2);
    }
  
    //imprimeT(arvore, 0);
  
    scanf("%d", &n3);
    n_pesquisar2 = verifica(arvore, n3);
 
    if (n_pesquisar2 == NULL)
    {
        printf("Valor nao encontrado");
    }
    else
    {
      printf("%d", alturaNegra(n_pesquisar2));
    }
 
    libera(arvore); // Desaloca a árvore da memória
 
    return 0;
}
