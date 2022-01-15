/*
Nome: Mateus Vespasiano de Castro
RA: 159505
Turma: IB
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

typedef struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
} TArv;
typedef TArv *PArv;

PArv cria(char c) {  // cria um nó raiz
    PArv p = (PArv) malloc(sizeof(TArv));
    p->info = c;
    p->esq = NULL;
    p->dir = NULL;
    return p;
}

void imprime (PArv a) {
    if (a!=NULL) {
        printf("%c ", a->info);
        imprime(a->esq); /* mostra sae */
        imprime(a->dir); /* mostra sad */
    }
}

void imprimePos (PArv a) {
    if (a!=NULL) {
        imprimePos(a->esq); /* mostra sae */
        imprimePos(a->dir); /* mostra sad */
        printf("%c ", a->info);
    }
}

void imprimeT(PArv p, int nivel){
    int i;

    if(p == NULL)
        return;

    imprimeT(p->esq, nivel+1);

    for(i=0; i<nivel; i++)
        printf("\t");

    printf("%3c\n",p->info);

    imprimeT(p->dir, nivel+1); 
}

PArv libera (PArv a){
    if (a!=NULL) {
        libera(a->esq); /* libera sae */
        libera(a->dir); /* libera sad */
        free(a); /* libera raiz */
    }
    return NULL;
}

void flush(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}



PArv criar_arv_posfix (char S1[], char S2[], int pi, int pf, int N){

  int  posicao, i;
  static int passo = 0;
  char aux;

  if ((pi > pf) || (passo == N)){
    return NULL;
  }

  PArv arv_posfix = cria(S1[passo]);

  if(pi == pf){
    passo++;
    return arv_posfix;
  }

  aux = S1[passo++];

  for(i = 1; i < N; i++){
    if(aux == S2[i]){
      posicao = i;
     }
  }

  arv_posfix->esq = criar_arv_posfix(S1, S2, pi, posicao - 1, N);
  arv_posfix->dir = criar_arv_posfix(S1, S2, posicao + 1, pf, N);

  return arv_posfix;

}

int main() {  // usando a recursividade
    int val, N;
    char prefix[50], infix[50];

    printf("\n\nDigite o tamanho do conjunto de substrings: ");
    scanf("%d", &N);
    flush();
    
    val = 0;

    while (val!=1){
        if (N >= 100){
        printf("\nNúmero inválido, digite novamente com N <= 100: ");
        scanf("%d", &N);
        flush();
        } else val = 1;
    }

    val = 0;

    printf("\n\nDigite a sequencia dos nos em ordem pre-fixa: ");
    scanf("%[^\n]", prefix);
    flush();
    
    while (val!=1){
        if (N != strlen(prefix)){
        printf("\nSequencia inválida, digite novamente com uma sequencia de mesmo tamanho do conjunto: ");
        scanf("%[^\n]", prefix);
        flush();
        } else val = 1;
    }

    val = 0;

    printf("\n\nDigite a sequencia dos nos em ordem infixa: ");
    scanf("%[^\n]", infix);
    flush();
    
    while (val!=1){
        if (N != strlen(infix)){
        printf("\nSequencia inválida, digite novamente com uma sequencia de mesmo tamanho do conjunto: ");
        scanf("%[^\n]", infix);
        flush();
        } else val = 1;
    }

    val = 0;

    printf("\n==>  %d\n", N);
    printf("==>  %s\n", prefix);
    printf("==>  %s\n", infix);

    PArv arvore = criar_arv_posfix(prefix, infix, 0, N, N);

    printf("\nA arvore digitada eh: \n\n");
    imprimeT(arvore, 0);
    // imprimeT(arvore);
    libera(arvore);

    return 0;
}
