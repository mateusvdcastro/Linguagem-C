#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <math.h> // pow
// isdigit();
// Eduardo
typedef struct {
  char vet[30];
  int topo;
}TPilha;

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

// desempilhando dados
char pop (TPilha* p, char* val, int i){
  if (p->topo < 0)  // pilha vazia
    return -1;
  val[i] = p->vet[p->topo];
  // note que a variável "topo" não foi apagada de fato, nós decrescemos o índice do topo, e quando tivermos que acrescentar de novo a variável será sobrescrita
  p->topo--; // decresce o índice
  return *val;
}

TPilha *libera (TPilha* p){
  free(p);
  return (NULL);
}

void ConsultaPilha (TPilha *p){
  int i;
  for (i=0;i<=p->topo;i++)
    printf ("\n Elemento %d: %c", p->topo-i+1, p->vet[p->topo-i]); // printando do topo até a base
}

int Prioridade(TPilha* pilha, char c){

  int pe,pt;

  if(c == '^')
    pe = 4;
  else if(c == '*' || c == '/')
    pe = 2;
  else if(c == '+' || c == '-')
    pe = 1;
  else if(c == '(')
    pe = 4;

  if(pilha->vet[pilha->topo] == '^')
    pt = 3;
  else if(pilha->vet[pilha->topo] == '*' || pilha->vet[pilha->topo] == '/')
    pt = 2;
  else if(pilha->vet[pilha->topo] == '+' || pilha->vet[pilha->topo] == '-')
    pt = 1;
  else if(pilha->vet[pilha->topo] == '(')
    pt = 0;

  return (pe > pt);
}

void converter(TPilha* pilha, char string[1000]){
  int i=0, j=0;
  char c, v, PosFix[1000];


  do {
    c = string[i];
    i++; // a+b*c-d
    if(c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^'){

                //strcat(Posfix, " ");
                PosFix[j] = ' ';
                j++;

              if ((pilha->topo == -1) || Prioridade(pilha, c) == 1) {
                push(pilha, c);
              } else {
                  while(1){
                  //PosFix[j] = " ";
                 // j++;
                  pop(pilha, PosFix, j);
                  j++;
                  PosFix[j] = ' ';
                  j++;
                  //printf("%c", v);
                  if((pilha->topo == -1) || Prioridade(pilha, c) == 1){
                    //push(pilha, v);
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
    while(pilha->topo != -1){
         PosFix[j] = ' ';
         j++;
         pop(pilha, PosFix, j);
         j++;

    }
    PosFix[j] = '\0';

    strcpy(string, PosFix);
}


int main(void) {
  int i;
  TPilha *minhapilha;

  minhapilha = nova();

  char string[1000];

  printf ("\n Insira uma expressão artimetica: ");
  scanf("%[^\n]s", string);

  converter(minhapilha, string);

  printf("%s", string);

  ConsultaPilha(minhapilha);

  libera(minhapilha);

  return 0;
}