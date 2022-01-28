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
  char RA[7];
  char nome[40];
  float N1, N2, N3;
}TArvA;
typedef TArvA *PArvA;


void menu (){
    printf("\n\n====================== Cadastro ======================");
    printf("\n1) Inserir um aluno na árvore.\n");
    printf("2) Imprimir a árvore atual.\n");
    printf("3) Mostrar os dados dos alunos que foram reprovados.\n");
    printf("4) Excluir da árvore todos os alunos que foram reprovados.\n");
    printf("5) Mostrar todos os alunos com chave menor ou igual a um dado RA.\n");
    printf("6) Iniciar uma nova árvore.\n");
    printf("7) Sair.\n");
    printf("\n----------------------------------------------------\n");
}

void flush(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

int main(void) {
  setlocale(LC_ALL,"");
  char RA[7];
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
      memset(RA, 0, sizeof(RA));
      printf("\nDigite o seu RA: ");
      scanf("%[^\n]", RA);
      flush();

      memset(nome, 0, sizeof(nome));
      //recebe_dados(nome, &n1, &n2, &n3);
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
