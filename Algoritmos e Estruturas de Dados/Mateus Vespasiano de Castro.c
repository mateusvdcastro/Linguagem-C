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
#include <math.h> // pow

typedef struct {  // Esta pilha será utilizada para converter de infixo para
  char vet[30];   // posfixo
  int topo;
}TPilha;

typedef struct calcula {  // Esta pilha será utilizada para calcular a 
  float valor;  // expressão posfixa
  struct calcula *proximo;
} Calcula;

// criando pilha
TPilha* nova(){
  TPilha* np = (TPilha *)  malloc (sizeof(TPilha));
  np->topo=-1;
  return np;
}

// empilhando dados
char push(TPilha* p, char val){
  if (p->topo>= 29) // pilha cheia
    return -1;  // erro no empilhamento

  (p->topo)++;  // acresce o índice
  p->vet[p->topo] = val;
  return val;
}

Calcula *empilhar(Calcula *pilha, float num){
  Calcula *novo = malloc(sizeof(Calcula));

  if (novo){
    novo->valor = num;
    novo->proximo = pilha;
    return novo;
  } else
    printf("\nErro");
  return NULL;
}

// desempilhando dados
char pop (TPilha* p, char* val, int i){
  if (p->topo < 0)  // pilha vazia
    return -1;
  val[i] = p->vet[p->topo];
  // note que a variável "topo" não foi apagada de fato, nós decrescemos o índice do topo, e quando tivermos que acrescentar de novo a variável será sobrescrita
  p->topo--; // decresce o índice
  return *val;
}

Calcula* desempilhar(Calcula **pilha){
  Calcula *remover = NULL;

  if(*pilha){
    remover = *pilha;
    *pilha = remover->proximo;
  } else
    printf("\nPilha vazia.");
  return remover;
}

TPilha *libera (TPilha* p){
  free(p);
  return (NULL);
}

void ConsultaPilha (TPilha *p){  // não será usado
  int i;
  for (i=0;i<=p->topo;i++)
    printf ("\n Elemento %d: %c", p->topo-i+1, p->vet[p->topo-i]); // printando do topo até a base
}

int Prioridade(TPilha* pilha, char c){

  int pe, pt;

  if(c == '^')
    pe = 4;
  else if(c == '*' || c == '/')
    pe = 2;
  else if(c == '+' || c == '-')
    pe = 1;
  else if(c == '(')  // não será usado 
    pe = 4;

  if(pilha->vet[pilha->topo] == '^')
    pt = 3;
  else if(pilha->vet[pilha->topo] == '*' || pilha->vet[pilha->topo] == '/')
    pt = 2;
  else if(pilha->vet[pilha->topo] == '+' || pilha->vet[pilha->topo] == '-')
    pt = 1;
  else if(pilha->vet[pilha->topo] == '(')  // não será usado 
    pt = 0;

  return (pe > pt);  // retorna 1 se a prioridade da entrada "pe" for maior 
  // que a prioridade do operador do topo da pilha "pt", e 0 caso contrário
}

void converter(TPilha* pilha, char string[1000]){
  int i=0, j=0;
  char c, v, PosFix[1000];

  do {
    c = string[i];
    i++; 
    if(c == '+' || c == '-' ||
      c == '*' || c == '/' ||
      c == '^'){
        PosFix[j] = ' ';
        j++;

        if ((pilha->topo == -1) || Prioridade(pilha, c) == 1) {
          push(pilha, c);
        } else {
            while(1){
            pop(pilha, PosFix, j);
            j++;
            PosFix[j] = ' ';
            j++;
            if((pilha->topo == -1) || Prioridade(pilha, c) == 1){
              push(pilha, c);
              break;
          }
        }
      }
    } else{
      PosFix[j] = c;
      j++;
    }

  } while(c != '\0');
    j = j-1;
    while(pilha->topo != -1){  // desempilhar tudo oq estiver na pilha
         PosFix[j] = ' ';
         j++;
         pop(pilha, PosFix, j);
         j++;

    }
    PosFix[j] = '\0';  // para finalizar a string e o programa não superar ela
    strcpy(string, PosFix);
}

float operacao(float n1, float n2, char token){
  switch(token){
    case '+':
      return n1 + n2;
      break;
    case '-':
      return n1 - n2;
      break;
    case '/':
      return n1 / n2;
      break;
    case '*':
      return n1 * n2;
      break;
    case '^':
      return pow(n1, n2);
      break;
    default:
      return 0.0;
  }
}


float resolver(char string[40]){
  char *token;
  float num;
  Calcula *n1, *n2, *pilha = NULL;

  token = strtok(string, " ");
  while(token){
    if(token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/' || token[0] == '^'){
      n1 = desempilhar(&pilha);
      n2 = desempilhar(&pilha);
      num = operacao(n2->valor, n1->valor, token[0]);
      pilha = empilhar(pilha, num);
      free(n1);
      free(n2);
    }else{
      num = strtol(token, NULL, 10); // converter str em hexadecimal 
      pilha = empilhar(pilha, num);
    }
    token = strtok(NULL, " ");
  }
  n1 = desempilhar(&pilha);
  num = n1->valor;
  free(n1);
  return num;
}



int main(void) {
  int idx=0, val;
  char Infixa[1000], Posfixa[10000], c, aux[10000];
  float res;
  int erros=0;

  TPilha *minhapilha;

  minhapilha = nova();
                    
  printf ("\n Insira uma expressão artimetica: ");  // 5*8+4-9/5*3^4/5^2*4-6+7/8 = 15.47
  scanf("%[^\n]s", Infixa);

  converter(minhapilha, Infixa);

  strcpy(Posfixa, Infixa);

  res = resolver(Infixa);

  printf("\n\n------------RESULTADO--------------");
  printf("\n\nExpressao posfixa:");
  printf("\n=> %s\n", Posfixa);
  printf("\nResultado da expressao:");
  printf("\n=> %.1f\n", res);
  printf("\n-------------------------------------\n");

 
  libera(minhapilha);

  return 0;
}
