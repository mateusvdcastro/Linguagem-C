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
    int verfica_var;
    struct arv* esq;
    struct arv* dir;
} TArv;
typedef TArv *PArv;

// imprime a árvore formatada, de melhor visualização
void imprimeT(PArv p, int nivel){
    int i;

    if(p == NULL)
        return;

    imprimeT(p->dir, nivel+1);

    for(i=0; i<nivel; i++)
        printf("\t");

    printf("%3c\n",p->info);

    imprimeT(p->esq, nivel+1); 
}

PArv Cria_no_raiz(int c, int verfica_var, PArv esq, PArv dir) {  // cria um nó raiz
    PArv p = (PArv) malloc(sizeof(TArv));
    p->info = c;
    p->verfica_var = verfica_var;
    p->esq = esq;
    p->dir = dir;
    return p;
}

PArv Cria_arvore(char exp[]){
  int num1, num2, qntChar;
  char operador;
  char *aux;

  PArv no_raiz = NULL;

  aux = exp;

  if (3 == sscanf(aux, "%d%c%d%n", &num1, &operador, &num2, &qntChar)){

    no_raiz = Cria_no_raiz(operador, 1,Cria_no_raiz(num1, 0, NULL, NULL), Cria_no_raiz(num2, 0, NULL, NULL));

    aux += qntChar;
  } else {
    return NULL;
  }

  while (2 == sscanf(aux, "%c%d%n", &operador, &num1, &qntChar)){

    no_raiz = Cria_no_raiz(
      operador, 1, no_raiz, Cria_no_raiz(num1, 0, NULL, NULL)
    );

    aux += qntChar;
  }

  return no_raiz;
}

void flush(){  // limpa o lixo de memória e o buffer do teclado do scanf
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

void arruma_exp(char exp[499]){
  char aux_exp[499];
  int i, j=0;

  for (i=0; i < strlen(exp); i++){  // retira os espaços da expressao
    if (exp[0] == '+'){
        exp[0] = ' ';
    }
    if (exp[i] == ' '){
      continue;
    } else {
      aux_exp[j] = exp[i];
      j++;
    }
  }
  aux_exp[j] = '\0';

  /*
  j=0;
  for (i=0; i < strlen(aux_exp); i++){
    if (aux_exp[0] == '-'){
      exp[0] = exp[1];
      j++;
      j++;
      exp[j] = exp[i];
    } else {
      exp[j] = exp[i];
      j++;
    } 
  }
  exp[j] = '\0';
  */

  strcpy(exp, aux_exp);
}

int main(){
  char expressao[500], expressao_valid[500];

  PArv arvore = NULL;

  printf("\n\nDigite a expressao: ");
  //fgets(expressao, 500, stdin);
  //expressao[strcspn(expressao, "\n")] = 0;
  scanf("%[^\n]", expressao);
  flush();

  printf("\n==> %s", expressao);

  arruma_exp(expressao);

  if (expressao[0] == '-'){
      printf("\n Tchau.");
      return -1;
  }

  printf("\n==> %s\n\n", expressao);

  arvore = Cria_arvore(expressao);

  imprimeT(arvore, 0);

  return 0;
}
