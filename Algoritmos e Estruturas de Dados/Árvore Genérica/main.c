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
    int info;
    int verfica_var;
    struct arv* esq;
    struct arv* dir;
} TArv;
typedef TArv *PArv;

// desaloca a árvore da memória
PArv libera (PArv a){
    if (a!=NULL) {
        libera(a->esq); /* libera sae */
        libera(a->dir); /* libera sad */
        free(a); /* libera raiz */
    }
    return NULL;
}

// imprime a árvore formatada, de melhor visualização
void imprimeT(PArv p, int nivel){
    int i;

    if(p == NULL)
        return;

    imprimeT(p->dir, nivel+1);

    for(i=0; i<nivel; i++)
        printf("\t");

    if (p->verfica_var == 1) {
        printf("%3c\n",p->info);
    } else{
        printf("%3d\n",p->info);
    }

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

int verifica_letras_numeros (char exp[499]){
    int i;
    for (i = 0; i<strlen(exp); i++){
      if ((exp[i] >= 48 && exp[i] <= 57) || exp[i] == '+' || exp[i] == '-' || exp[i] == ' '){
          continue;
      } else {
          printf("\nHa caracteres invalidos na expressao, digite novamente.\n");
          return -1;
      }
    }

    for (i = 0; i<strlen(exp); i++){
        if ((exp[i] >= 48 && exp[i] <= 57) && (exp[i+1] ==' ') && (exp[i+2] >= 48 && exp[i+2] <= 57)){
        printf("\nNão digite espaços entre numeros.\n");
        return -1;
      }
    }

    return 0;
}

// esta função retira os espaços da expressao
void arruma_exp(char exp[499]){
  char aux_exp[499];
  int i, j=0;

  for (i=0; i < strlen(exp); i++){  
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
  strcpy(exp, aux_exp);
}

int soma_folha(PArv raiz) {
    int soma;

    if(raiz != NULL){

      if ((raiz->esq != NULL) && (raiz->dir != NULL)){
        if (raiz->info == '+'){
            soma = soma_folha(raiz->esq) + raiz->dir->info;
        }else {
            soma = soma_folha(raiz->esq) - raiz->dir->info;
        }
      } else {
            soma= raiz->info;
        }
    }
    return soma;
}

int main(){
  char expressao[500], expressao_valid[500];
  int i, rec = 0, soma = 0;

  PArv arvore = NULL;

  printf("\n\nDigite a expressao: \n");
  //fgets(expressao, 500, stdin);
  //expressao[strcspn(expressao, "\n")] = 0;
  scanf("%[^\n]", expressao);
  flush();

  printf("\n==> %s\n", expressao);

  rec = verifica_letras_numeros(expressao);

  if (rec == 0){
      printf("");
  } else {
      return -1;    
  }

  arruma_exp(expressao);

  if (expressao[0] == '-'){
      printf("\n Erro, o primeiro numero não pode ser negativo, reinicie o programa por favor.\n");
      return -1;
  } else {
      for (i = 0; i<strlen(expressao); i++){
          if ((expressao[i] == '+' && expressao[i+1] == '+') || (expressao[i] == '+' && expressao[i+1] == '-') || (expressao[i] == '-' && expressao[i+1] == '+') || (expressao[i] == '-' && expressao[i+1] == '-')){
              printf("\nNão digite dois operadores seguidos, digite a expressao novamente.\n");
              return -1;
          }
      }
  }

  printf("\n==> %s\n\n", expressao);

  arvore = Cria_arvore(expressao);

  imprimeT(arvore, 0);

  soma = soma_folha(arvore);

  printf("\nA soma da arvore eh: %d\n", soma);

  libera(arvore);
  
  return 0;
}

