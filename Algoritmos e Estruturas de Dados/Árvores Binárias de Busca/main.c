/*
NOME: Mateus Vespasiano de Castro
RA: 159505
TURMA: IB
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h> 

typedef struct arv {
  int info;
  struct arv* esq;
  struct arv*dir;
}TArv;
typedef TArv *PArv;

typedef struct arvA {
  int RA;
  char nome[40];
  float N1, N2, N3;
}TArvA;
typedef TArvA *PArvA;

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

PArv insereABB (PArv arv, int c) {
  PArv novo;
  if (arv == NULL) { // arvore vazia
  novo=(PArv)malloc(sizeof(TArv));
  novo->esq = NULL;
  novo->dir = NULL;
  return(novo);
  }
  else if (c < arv->info)
  arv->esq = insereABB(arv->esq,c);
  else
  arv->dir = insereABB(arv->dir,c);
  return(arv);
}

PArv buscaABB (PArv arv, char c) {
  if (arv==NULL)
  return NULL; /*árvore vazia*/
  else if(c < arv->info)

  return(buscaABB(arv->esq,c));

  else if (c > arv->info)
  return(buscaABB(arv->dir,c));
  else
  return(arv); // encontrou a informação
}

int iguais(PArv a, PArv b){
  if (a==NULL && b==NULL) //as duas árvores são NULL

  return 1;
  if (a==NULL || b==NULL) //somente uma das árvores é NULL
  return 0;
  return((a->info==b->info) && iguais(a->esq,b->esq) &&
  iguais(a->dir,b->dir));
}

void menu (){
    printf("\n\n====================== Cadastro ======================");
    printf("\n1) Inserir um aluno na árvore.\n");
    printf("2) Imprimir a árvore atual.\n");
    printf("3) Mostrar os dados dos alunos que foram reprovados.\n");
    printf("4) Excluir da árvore todos os alunos que foram reprovados.\n");
    printf("5) Mostrar todos os alunos com chave menor ou igual a um dado RA.\n");
    printf("6) Iniciar uma nova árvore.\n");
    printf("7) Sair.");
    printf("\n----------------------------------------------------\n");
}

void flush(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

void dados_aluno(char nome[], float *N1, float *N2, float *N3){

    printf("\nDigite o seu nome: ");
    scanf("%[^\n]", nome);
    flush();

    printf("\nDigite a primeira nota: ");
    scanf("%f", &*N1);
    flush();

    printf("\nDigite a segunda nota: ");
    scanf("%f", &*N2);
    flush();

    printf("\nDigite a terceira nota: ");
    scanf("%f", &*N3);
    flush();
}

int main(void) {
  setlocale(LC_ALL,"");
  int RA;
  char nome[40];
  float N1, N2, N3;
  int op = 0, val = 0;

  while (op!=7){

    menu();

    printf("\nDigite qual sua opção?: ");
    scanf("%d", &op);

    while (val != 1){
      if (op != 1 && op != 2 && op != 3 && op != 4 && op != 5){
        printf("!!!Valor inválido\n\n");
        menu();
        printf("\nDigite um valor válido desta vez:");
        scanf("%d", &op);
        flush();
      } else val = 1;
    }
    
    if (op == 1) {
      RA = 0;
      memset(nome, 0, sizeof(nome));

      printf("\nDigite o seu RA: ");
      scanf("%d", &RA);
      flush();

      dados_aluno(nome, &N1, &N2, &N3);
      /*
      printf("\n%d\n", RA);
      printf("%s\n", nome);
      printf("%f\n", N1);
      printf("%f\n", N2);
      printf("%f\n", N3);
      */
    }
    if (op == 2) {
    }
    if (op == 3){
    }
    if (op == 4){
    }
    if (op == 5) {
    }
    if (op == 6){
    }
  }
  // desalocando a memória
  return 0;
}
