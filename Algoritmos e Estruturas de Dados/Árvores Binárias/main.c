// Nome: Mateus Vespasiano de Castro
// RA: 159505
// Turma: IB

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

// estrutura de um nó de uma árvore binária
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

// função que imprime na forma prefixa a árvore e guarda
// uma cópia da sequência (val_prefix) para uma futura validação
int aux = 0;  // variável global, deve ser zerada na main sempre
// que utilizada
void imprimePre (PArv a, char val_prefix[]) {
    if (a!=NULL) {
        printf("%c ", a->info);
        val_prefix[aux] = a->info;
        aux++;
        imprimePre(a->esq, val_prefix); /* mostra sae */
        imprimePre(a->dir, val_prefix); /* mostra sad */
    }
    val_prefix[aux] = '\0';
}


// função que imprime na forma infixa, e faz tbm a mesma
// validação da função acima
void imprimeIn (PArv a, char val_infi[]) {
    if (a!=NULL) {
      imprimeIn(a->esq, val_infi); /* mostra sae */
      printf("%c ", a->info);
      val_infi[aux] = a->info;
      aux++;
      imprimeIn(a->dir, val_infi); /* mostra sad */
    }
    val_infi[aux] = '\0';
}


// imprime a árvore na seq. posfixa
void imprimePos (PArv a) {
    if (a!=NULL) {
        imprimePos(a->esq); /* mostra sae */
        imprimePos(a->dir); /* mostra sad */
        printf("%c ", a->info);
    }
}


// imprime a árvore formatada, de melhor visualização
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


// desaloca a árvore da memória
PArv libera (PArv a){
    if (a!=NULL) {
        libera(a->esq); /* libera sae */
        libera(a->dir); /* libera sad */
        free(a); /* libera raiz */
    }
    return NULL;
}

// deve ser usada abaixo de cada scanf para limpar o buffer
void flush(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

int passo = 0; // variável global, deve ser zerada na main,
// quando essa função for utilizada

// esta função recebe uma string na forma infixa e outra na prefixa, faz a transformação para posfixa, enquanto cria a árvore binária
PArv criar_arv_posfix (char S1[], char S2[], int pi, int pf, int N){
  int  posicao, i;
  char aux;

  if ((pi > pf) || (passo == N)){
    return NULL;
  }

  PArv arv_posfix = cria(S1[passo]);  // irá criar cada nó, como se fosse um nó raiz, e posteriormente cada nó irá apontar para alguém na direita e na esquerda

  if(pi == pf){
    passo++;
    return arv_posfix;
  }

  aux = S1[passo++];

  for(i = 1; i < N; i++){  // aqui iremos localizar a posição do nó
    if(aux == S2[i]){      // analisado na seq. infixa
      posicao = i;
     }
  }

  // agora iremos conectar a esq e direita de cada nó
  arv_posfix->esq = criar_arv_posfix(S1, S2, pi, posicao - 1, N); // o passo irá andar para a esquerda do nó analisado 
  arv_posfix->dir = criar_arv_posfix(S1, S2, posicao + 1, pf, N); //  o passo irá andar para a direita do nó analisado

  return arv_posfix;

}

int main() {  
    int val, N, infix_validacao = 0, prefix_validacao = 0;
    char prefix[50], infix[50], val_infi[50], val_prefix[50], NS[50];

    while (infix_validacao != 1 && prefix_validacao != 1){

        memset(prefix, 0, sizeof(prefix)); // zera as strings
        memset(infix, 0, sizeof(infix)); // e adiciona '\0'

        val = 0;

        // verifica se o número de nós é menor que 100, diferente de zero e se oq o usuário digitou é número ou não
        while (val!=1){
        
        printf("\n\nDigite o numero de nos da arvore: ");
          if(fgets(NS, sizeof(NS), stdin)){
            if (1 == sscanf(NS, "%d", &N) && N <= 100 && N != 0){  
                val = 1;
            } else {
              printf("\nNúmero inválido, digite novamente com N < 100: ");
            }
          }
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

        PArv arvore = criar_arv_posfix(prefix, infix, 0, N, N);
        passo = 0;

        // Passo importante para a validação
        printf("\nPrefixa ==> ");
        imprimePre(arvore, val_prefix);
        aux = 0;
        printf("\nInfixa ==> ");
        imprimeIn(arvore, val_infi);
        aux = 0;

        //Descomente para ver a infixa e prefixa da maneira correta que deveria ter sido digitada pelo usuário caso ele informe uma seq. inválida
        //printf("\nPrefixa correta ==> ");
        //printf("%s", val_prefix);
        //printf("\nInfixa correta ==> ");
        //printf("%s", val_infi);

        if (strcmp(val_infi, infix)!=0 || strcmp(val_prefix, prefix)!=0){
            printf("\n\nÁrvore inválida, digite novamente uma sequencia em ordem infixa ou prefixa válida.");
            libera(arvore);
        } else {
            infix_validacao = 1;
            prefix_validacao = 1;
            printf("\n\nA arvore digitada eh: \n\n");
            imprimeT(arvore, 0);

            libera(arvore);
        }
    }
    return 0;
}
