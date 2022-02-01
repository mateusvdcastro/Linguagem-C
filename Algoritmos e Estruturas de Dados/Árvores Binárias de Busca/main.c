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

typedef struct arvA {
  int RA;
  char nome[40];
  float N1, N2, N3, media;
  struct arvA* esq;
  struct arvA* dir;
}TArvA;
typedef TArvA *PArvA;

PArvA arv_aluno = NULL; // árvore pricipal, será guardados todos os alunos
PArvA backup_aluno = NULL; // backup para a opção 4, irá salvar os alunos com nota acima da média

// imprime a árvore formatada, de melhor visualização
void imprimeT(PArvA p, int nivel){
  int i;

  if(p == NULL)
      return;

  imprimeT(p->esq, nivel+1);

  for(i=0; i<nivel; i++)
      printf("\t");

  printf("%3d\n",p->RA);

  imprimeT(p->dir, nivel+1); 
}

//libera a memoria alocada
PArvA libera (PArvA a){
    if (a!=NULL) {
        libera(a->esq); /* libera sae */
        libera(a->dir); /* libera sad */
        free(a); /* libera raiz */
    }
    return NULL;
}

// imprimerRA e imrprimirmenor são duas funções auxilires a "buscarRA" que serão utilizados na opção 5, para printar os menores RAs em comparação a um RA informado pelo usuário
void imprimirRA(PArvA a)
{
  if (a != NULL)
  {
    printf("\nRA: %i\n", a->RA);
    printf("\nNome: %s\n", a->nome);
    printf("\nNota 1: %.2f\n", a->N1);
    printf("\nNota 2: %.2f\n", a->N2);
    printf("\nNota 3: %.2f\n", a->N3);
    printf("\nMedia: %.2f\n", a->media);
    imprimirRA(a->esq); //andar à esquerda da árvore
    imprimirRA(a->dir); //andar à direita da árvore
  }
}

void imprimirmenor(PArvA a)
{
  printf("\nRA: %i\n", a->RA);
  printf("\nNome: %s\n", a->nome);
  printf("\nNota 1: %.2f\n", a->N1);
  printf("\nNota 2: %.2f\n", a->N2);
  printf("\nNota 3: %.2f\n", a->N3);
  printf("\nMedia: %.2f\n", a->media);
  imprimirRA(a->esq); // andar à esquerda da árvore
}

// será utilizada na opção 5
int buscarRA(PArvA a, int ra){
  if (a == NULL){ 
      return 0;
  }
  if(a->dir == NULL && a->RA <= ra){ // se o filho a direita for nulo e se o nó atual for menor igual ao ra digitado pelo usuário, a função "imprimermenor" é chamada para exibir esse valor menor (que é o desejado)
    imprimirmenor(a);
    return 0;
  }
  if(a->dir == NULL && a->RA > ra){ // se o  filho a direita for nulo e o RA atual for maior que o RA digitado pelo usuário nós avançamos a esquerda da árvore
    return(buscarRA(a->esq, ra));
  }
  if(a->dir->RA <= ra){ // Se o nó a direita tiver um RA menor ou igual que o RA digitado pelo usuário imprimimos antes (à "esquerda") e depois andamos para "a direita"
    imprimirmenor(a);
    return(buscarRA(a->dir, ra));
  }
  if (a->dir->RA > ra && a->RA <= ra){ //Se o RA do nó a direita for maior que o RA e o nó atual tiver RA menor ou igual ao digitado, imprimimos o nó atual
    imprimirmenor(a);
    return 0;
  }
  if(a->RA > ra){  // Se o RA atual for maior que o RA digitado, andamos para a esquerda
    return(buscarRA(a->esq, ra));
  }
  return 0;
}

// insere o nó na árvore principal e retorna a árvore principal
PArvA insereABB(PArvA arv, PArvA no){
  PArvA novo;
  if(arv == NULL){ //arvore vazia
    return no;
  } else if(no->RA < arv->RA){ // insere na ordem, menores à esquerda e maiores à direita
      arv->esq = insereABB(arv->esq, no);
    } else {
        arv->dir = insereABB(arv->dir, no);
      }
  return arv;
}

// Será usada para verificar se existem dois RAs repetidos, caso o usuário informe
int buscaABB (PArvA arv, int RA) {
  if (arv==NULL)
    return 0; /*árvore vazia*/
  else if(RA < arv->RA)
    return(buscaABB(arv->esq,RA));
  else if (RA > arv->RA)
    return(buscaABB(arv->dir,RA));
  else
    return 1; // encontrou a informação, portanto, existem RAs iguais, retornando 1 para erro

  return 0;
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

// limpa o buffer/lixo do scanf
void flush(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

// verifica se a nota é maior que 10 ou menor que zero, e retorna 1 como erro
int verifica_nota(float N){

  if(N > 10 || N < 0){
    return 1;
  }
  return 0;
}

int verifica_ra(char RA[]){
  int i, ra;
  for(i=0; i<strlen(RA); i++){ // verifica se existe algum caracter que não seja um digito de 0 a 9, para isso a função isdigit que retorna algo != 0 caso tudo seja digito e 0 caso tenha caracteres especiais ou alphanuméricos
    if(isdigit(RA[i]) == 0){
      return 1; // erro caso tenha caracteres especiais ou alphanuméricos
    }
  }
  ra = strtol(RA, NULL, 10); // strtol converte um char em int (hexadecimal)
  if(ra == 0 || ra < 1){
    return 1; // retorna erro caso o RA seja zero ou número negativo
  }
  return 0;
}

int val_nota=2;

// função utilizada na opção 1 para receber os dados dos alunos
void dados_aluno(char RA[], char nome[], float *N1, float *N2, float *N3, PArvA raiz){
    int val_ra=2 , RAint;

    while(val_ra != 0){
      do{
      printf("\nDigite o seu RA: ");
      scanf("%s", RA);
      flush();
      RAint = strtol(RA, NULL, 10);
      val_ra = verifica_ra(RA); // val_ra recebe zero caso o verifica_ra não encontre erro
      if (buscaABB(raiz, RAint) == 1){
        printf("\nRA repetido!\n");
      }
      }while(buscaABB(raiz, RAint) == 1); // pede para o usuário digitar novamente até que não aja RAs iguais 
      if (val_ra == 1){
        printf("\nRA invalido, digite novamente.\n");
      }
    }

    printf("\nDigite o seu nome: ");
    scanf("%[^\n]", nome);
    flush();

    val_nota = 2;

    while (val_nota != 0){
      printf("\nDigite a primeira nota: ");
      while(scanf("%f", &*N1) == 0){ // verifica se o input é somente float, caso não seja retorna zero e apresenta mensagem de erro
				printf("\nERRO");
				printf("\nDigite a primeira nota: ");
				flush();
			}
      flush();
      val_nota = verifica_nota(*N1); // val nota retorna zero caso a validação não encontre erros
      if (val_nota == 1){
        printf("\nNota invalida, digite novamente.\n");
      }
    }

    val_nota = 2;

    while (val_nota != 0){
      printf("\nDigite a segunda nota: ");
      while(scanf("%f", &*N2) == 0){
				printf("\nERRO");
				printf("\nDigite a primeira nota: ");
				flush();
			}
      val_nota = verifica_nota(*N2);
      if (val_nota == 1){
        printf("\nNota invalida, digite novamente.\n");
      }
    }

    val_nota = 2;

    while (val_nota != 0){
      printf("\nDigite a terceira nota: ");
      while(scanf("%f", &*N3) == 0){
				printf("ERRO");
				printf("\nDigite a primeira nota: ");
				flush();
			}
      val_nota = verifica_nota(*N3);
      if (val_nota == 1){
        printf("\nNota invalida, digite novamente.\n");
      }
    }
}

// exibe todos os alunos com nota abaixo da média
void opcao_3_reprovados(PArvA arv){
  if(arv !=NULL){
    if(arv->media < 6){
      printf("\nRA %d do aluno(a) %s", arv->RA, arv->nome);
      printf("\nNota 1: %.2f", arv->N1);
      printf("\nNota 2: %.2f", arv->N2);
      printf("\nNota 3: %.2f", arv->N3);
      printf("\nMedia Final: %.2f\n", arv->media);
    }
    opcao_3_reprovados(arv->esq);
    opcao_3_reprovados(arv->dir);
  }
}

// guarda em backup_aluno todos os alunos acima da média, apaga árvore anterior e aponta para a nova (uma forma de "remover" os alunos abaixo da média), para que futuramente seja usada na opção 4. 
PArvA nos_acima_da_media(PArvA arv){
  float media;

  PArvA aluno_media_no = malloc(sizeof(TArvA)); // nó alocado par a função insereABB

  if(arv !=NULL){
    if(arv->media >= 6){
      strcpy(aluno_media_no->nome, arv->nome);
      aluno_media_no->RA = arv->RA; // guardando as informações na struct do aluno com nota acima da média
      aluno_media_no->N1 = arv->N1;
      aluno_media_no->N2 = arv->N2;
      aluno_media_no->N3 = arv->N3;
      media = (arv->N1 + arv->N2 + arv->N3)/(float)3;
      aluno_media_no->media = media;
      backup_aluno = insereABB(backup_aluno, aluno_media_no); // guardando aluno na árvore de backup
    }
    nos_acima_da_media(arv->esq); // anda para a esquerda da árvore
  	nos_acima_da_media(arv->dir); // anda para a direita da árvore
  }
  return backup_aluno;
}

int main(void) {
  setlocale(LC_ALL,"");
  char RA[7];
  char nome[40];
  float N1, N2, N3, media;
  int op = 0, val = 0, ra, ra_5;

  while (op!=7){

    menu();

    printf("\nDigite qual sua opção?: ");
    scanf("%d", &op);

    while (val != 1){
      if (op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6 && op != 7){
        printf("!!!Valor inválido\n\n");
        menu();
        printf("\nDigite um valor válido desta vez:");
        scanf("%d", &op);
        flush();
      } else val = 1;
    }
    
    if (op == 1) {
      memset(nome, 0, sizeof(nome)); // zera a variável nome e acrescenta \0
      memset(RA, 0, sizeof(RA)); // zera a variável RA e acrescenta \0

      PArvA no_aluno = malloc(sizeof(TArvA)); // cria o nó do aluno, que será adicionado a árvore principal arv_aluno

      dados_aluno(RA, nome, &N1, &N2, &N3, arv_aluno); //recebe os dados

      ra = strtol(RA, NULL, 10);

      no_aluno->RA = ra;

      strcpy(no_aluno->nome, nome);
      no_aluno->N1 = N1;
      no_aluno->N2 = N2;
      no_aluno->N3 = N3;
    
      media = (N1 + N2 + N3)/(float)3;
      no_aluno->media = media;

      arv_aluno = insereABB(arv_aluno, no_aluno);
    }
    if (op == 2) {
      if(arv_aluno == NULL){
          printf("\nArvore vazia!\n");
      }else{
          printf("\nA arvore montada é: \n");
          imprimeT(arv_aluno, 0);
      }
    }
    if (op == 3){
      if(arv_aluno == NULL){
        printf("\nArvore vazia! Digite a opção 6 para recomeçar.\n");
      } else {
          printf("\n=>Os alunos reprovados sao: \n");
          printf("\n===============================\n");
          opcao_3_reprovados(arv_aluno);
          printf("\n===============================\n");
      }
    }
    if (op == 4){
      backup_aluno = nos_acima_da_media(arv_aluno); // árvore com alunos acima da média ( portanto sem os alunos abaixo)
      libera(arv_aluno); // libera árvore com todos os alunos
      arv_aluno = backup_aluno; // arvore antiga aponta para o endereço da árvore nova
      backup_aluno = NULL;
    }
    if (op == 5) {
      printf("\nDigite o RA : ");
      scanf("%d", &ra_5);
      flush();

      printf("\nAlunos com RA igual ou inferior a %d:\n", ra_5);
      printf("\n==========================================\n");
      buscarRA(arv_aluno, ra_5);
      printf("\n==========================================\n");

    }
    if (op == 6){
      arv_aluno = libera(arv_aluno); // libera árvore
    }
  }

  // desalocando a memória
  libera(arv_aluno);
  return 0;
}
