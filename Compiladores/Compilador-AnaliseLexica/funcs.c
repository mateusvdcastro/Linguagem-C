#include "funcs.h"

/*--------------------------------------------------------
------------------------- BUFFER -------------------------
--------------------------------------------------------*/

PBuffer allocate_buffer(PBuffer a){

  PBuffer novo;

  if(a == NULL){
    novo = (PBuffer) malloc(sizeof(Buffer));
    novo->linha = 1;
    novo->pos_proxChar = 0;
  }

  return novo;
}

void refresh_buffer(PBuffer a){

  int i = TAM_BUFFER;
  for (i=0; i < TAM_BUFFER; i++){
    a->vet[i] = '\0';
  }

}

void deallocate_buffer(PBuffer b){

  free(b);

}




/*--------------------------------------------------------
------------------------- LEXEMA -------------------------
--------------------------------------------------------*/

PLexema allocate_struct_lex(PLexema l){

  PLexema novo;

  if(l == NULL){
    novo = (PLexema) malloc(sizeof(Lexema));
    novo->linha = 1;
    novo->pos_in = 0;
  }

  return novo;
}

void deallocate_struct_lex(PLexema l){

  free(l);

}

void refresh_lex(PLexema l){

  int i;

  for(i = 0; i < TAM_LEXEMA; i++){
    l->lexema[i] = '\0';
  }

  l->pos_in = 0;
}

void insert_char(PLexema a, PBuffer b, int prox_estado, char c){
  
  if(prox_estado != 4 && prox_estado != 5 && prox_estado != 0){//Estados de comentário e espaço em branco
    if(a->insere != 2){ //Para inserirmos apenas os caracteres corretos
      a->lexema[a->pos_in] = c;
      a->pos_in++;
    }
  }
  else{
    if(prox_estado != 10){ //Para não perdermos o lexema formado
      refresh_lex(a);
    }
  }
}

PArv buscaABB(PArv a, char palavra[]){

  if (a == NULL){
    return NULL; //árvore vazia
  }
  else if(strcmp(a->palavra, palavra) < 0){
    return buscaABB(a->esq, palavra);
  }
  else if(strcmp(a->palavra, palavra) > 0){
    return buscaABB(a->dir, palavra);
  }
  else{
    return a; // encontrou o valor
  }
}

void build_lex(PLexema l, PArv a, PArv busca){

  if(l->lexema[0] != '\0'){ //Para não montar os lexemas 'vazios' quando faço a chamada na main
    busca = buscaABB(a, l->lexema);
    
    if(busca == NULL){//Não esta nas palavras reservadas
      if (isalpha(l->lexema[0]) != 0){  //Letra
        l->token = 27; //ID
      }
      else{
        l->token = 28; //NUM
      }
    }
    else{//Esta nas palavras reservadas
      l->token = busca->token;
    }
  }
}



/*--------------------------------------------------------
-------------------------- CHAR --------------------------
--------------------------------------------------------*/

void get_next_block(PBuffer a, FILE* arq) {

  refresh_buffer(a);

  //O fgets lê uma string até achar um \n e ele insere na última posição do vetor um caractere '\0'
  if (fgets(a->vet, TAM_BUFFER, arq) == NULL) {
    a->vet[0] = EOF; // Definir o primeiro caractere como EOF para indicar o final do arquivo
  }
  //Precisamos fazer isso pois após ler a ultima linha (\n da última linha), o buffer sofre um refresh e o carcatere de EOF é lido, como só ele é lido, colocamos ele na posição 0 para parar o loop while na main
}

char get_next_char(PBuffer a, FILE *arq, int flag){

  char c;

  //Vamos carregar o buffer pela primeira vez
  if(flag == 1){
    get_next_block(a, arq);
  }

  c = a->vet[a->pos_proxChar];

  if (c == EOF) {
    return EOF; // Retornar EOF para indicar o final do arquivo
  }

  //Verificando se chegamos ao fim da linha do arquivo
  if(c == '\n'){

    get_next_block(a, arq);
    a->linha++;
    a->pos_proxChar = -1; //resetamos a posição pois o fgets lê só até o \n ou até encher o buffer

  }else if(c == '\0'){ //enchemos o buffer

    get_next_block(a, arq);
    a->pos_proxChar = -1;
  }

  a->pos_proxChar++;

  return c;

}




/*--------------------------------------------------------
-------------------------- DFA ---------------------------
--------------------------------------------------------*/

int select_char(char c){
  int column;
  
  if (isalpha(c) != 0){  //Letra
    column = 0;
  }
  else if (isdigit(c) != 0){
    column = 1;
  }
  else if(c == ' ' || c == '\n' || c == '\t'){
    column = 2;
  }
  else if(c == '/'){
    column = 3;
  }
  else if (c == '+' || c == '-' || c == '*' || c == ';' || c == ',' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}'){
    column = 4;
  }
  else if (c == '<' || c == '>'){
    column = 5;
  }
  else if (c == '='){
   column = 6;
  }
  else if (c == '!'){
    column = 7;
  }
  else{
    column = 8;
  }

  return column;
}

int change_state(int estado_atual, char c, PLexema l){

  int selecao;
  int novo_estado;

  int matriz[10][9] = {
      { 1,  2,  0,  3,  6,  7,  7,  8,  9},
      { 1, 10, 10, 10, 10, 10, 10, 10, 10},
      {10,  2, 10, 10, 10, 10, 10, 10, 10},
      {10, 10, 10, 10,  4, 10, 10, 10, 10},
      { 4,  4,  4,  4,  5,  4,  4, 10,  4},
      { 4,  4,  4,  0,  5,  4,  4,  4,  4},
      {10, 10, 10, 10, 10, 10, 10, 10, 10},
      {10, 10, 10, 10, 10, 10,  6, 10, 10},
      { 9,  9,  9,  9,  9,  9,  6,  9,  9},
      {10, 10, 10, 10, 10, 10, 10, 10, 10},
  };

  selecao = select_char(c);
  l->insere = selecao;
  novo_estado = matriz[estado_atual][selecao];
  
  return novo_estado;
}




/*--------------------------------------------------------
---------------------- ÁRVORE AVL ------------------------
--------------------------------------------------------*/

int max(int a, int b){ // usaremos para calcular as alturas das árvores
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int altura(PArv a){
  if (a == NULL) {
    return 0;
  }
  return 1 + max(altura(a->esq), altura(a->dir));
}

int fator_balanceamento(PArv a) {

  if (a == NULL) {
    return 0;
  }
  return (altura(a->esq) - altura(a->dir));
}

PArv rotacao_RR(PArv pA) {

  PArv pB = pA->dir;
  PArv aux;

  pA->dir = pB->esq;
  pB->esq = pA;
  aux = pA;
  pA = pB;
  pB = aux;

  pA->altura = altura(pA);
  pA->fb = fator_balanceamento(pA);

  pB->altura = altura(pB);
  pB->fb = fator_balanceamento(pB);

  return pA;
}

PArv rotacao_LL(PArv pA){

  PArv pB = pA->esq;
  PArv aux;

  pA->esq = pB->dir;
  pB->dir = pA;
  aux = pA;
  pA = pB;
  pB = aux;


  pA->altura = altura(pA);
  pA->fb = fator_balanceamento(pA);

  pB->altura = altura(pB);
  pB->fb = fator_balanceamento(pB);

  return pA;
}

PArv rotacao_LR(PArv pA){

  PArv pB = pA->esq;
  PArv pC = pB->dir;
  PArv aux;

  pB->dir = pC->esq;
  pC->esq = pB;
  pA->esq = pC->dir;
  pC->dir = pA;

  aux = pA;
  pA = pC;
  pC = aux;

  pA->altura = altura(pA);
  pA->fb = fator_balanceamento(pA);

  pB->altura = altura(pB);
  pB->fb = fator_balanceamento(pB);

  pC->altura = altura(pC);
  pC->fb = fator_balanceamento(pC);

  return pA;
}

PArv rotacao_RL(PArv pA){

  PArv pB = pA->dir;
  PArv pC = pB->esq;
  PArv aux;

  pB->esq = pC->dir;
  pC->dir = pB;
  pA->dir = pC->esq;
  pC->esq = pA;

  aux = pA;
  pA = pC;
  pC = aux;

  pA->altura = altura(pA);
  pA->fb = fator_balanceamento(pA);

  pB->altura = altura(pB);
  pB->fb = fator_balanceamento(pB);

  pC->altura = altura(pC);
  pC->fb = fator_balanceamento(pC);

  return pA;
}

PArv rebalanceamento(PArv a){

  a->fb = fator_balanceamento(a);
  a->altura = altura(a);

  if (a->fb > 1 && a->esq->fb >= 0) {
    return rotacao_LL(a);
  }
  if (a->fb < -1 && a->dir->fb <= 0) {
    return rotacao_RR(a);
  }
  if (a->fb > 1 && a->esq->fb < 0) {
    return rotacao_LR(a);
  }
  if (a->fb < -1 && a->dir->fb > 0) {
    return rotacao_RL(a);
  }

  return a;
}

PArv criaABB(PArv a, char palavra[], int token){

  PArv novo;
  
  int i;

  if (a == NULL){ //árvore vazia
    novo = (PArv)malloc(sizeof(TArv));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->token = token;
    strcpy(novo->palavra, palavra);
    novo->altura = 1;
    novo->fb = 0;

    return novo;
  }
  else if(strcmp(a->palavra, palavra) < 0){
    a->esq = criaABB(a->esq, palavra, token);
  }
  else if (strcmp(a->palavra, palavra) > 0){
    a->dir = criaABB(a->dir, palavra, token);
  }
  else{
    return a;
  }

  a = rebalanceamento(a);

  return a;
}

PArv libera(PArv a){

  if (a != NULL) {
    libera(a->esq);
    libera(a->dir);
    free(a);
  }

  return NULL;
}

void imprime(PArv a, int nivel){

  int i;

  if(a == NULL) return;
  else{
      imprime(a->dir, nivel+1);

    for(i=0;i<nivel;i++){
          printf("\t");
    }

    printf("%d\n", a->token);
      imprime(a->esq, nivel + 1);
    } 
}