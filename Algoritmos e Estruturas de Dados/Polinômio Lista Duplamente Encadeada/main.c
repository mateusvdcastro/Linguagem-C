/*
Mateus Vespasiano de Castro
RA: 159505
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

typedef struct lista2 {
    int expoente;
    int coeficiente;
    struct lista2* ant;  // ponteiro para o anterior elemento
    struct lista2* prox; // ponteiro para o próximo elemento
}TLista2;
typedef TLista2 *PLista2;

// inserção no início da lista
PLista2 insere (PLista2 l, int c, int ex) {
  PLista2 novo = (PLista2) malloc(sizeof(TLista2));
  novo->coeficiente = c;
  novo->expoente = ex;
  novo->prox = l;
  novo->ant = NULL;
  if (l != NULL) {
    if(l->expoente > novo->expoente){  // adiconando maior grau de polinomio à esquerda (início da lista)
      novo->prox = l->prox;
      l->prox = novo;
      novo->ant = l;
      novo = l;
    } else {
      l->ant = novo;
    }
  }
  return novo;
}


// função que irá inserir os monômios de grau maior primeiro
PLista2 Insere_Ordenado (PLista2 l, int coef, int exp) {
  PLista2 aux, ant;
  PLista2 novo = (PLista2) malloc(sizeof(TLista2));

  novo->expoente = exp;
  novo->coeficiente = coef;

  if (l == NULL) { // sera o primeiro
    novo->ant = NULL; 
    novo->prox = NULL;
    l = novo;
  }
  else {
    aux = l;
  while(aux->prox != NULL && aux->expoente>exp)
    aux = aux->prox;
  if(aux->expoente>exp){ /* insere novo no fim */
    novo->prox = NULL; novo->ant = aux;
    aux->prox = novo;
  }
  else{ /* insere depois de aux */
    novo->prox = aux; novo->ant = aux->ant;
  if(aux->ant!=NULL) /* se não for o 1o. nó */
    aux->ant->prox = novo;
  else{
    l = novo;/*atualiza início da lista */
    novo->ant = NULL; }
    aux->ant = novo;
    }
  }
  return l;
}

PLista2* clean_lista(PLista2 lista){  // libera a lista usando recursividade
    if(lista!=NULL){
        clean_lista(lista->prox);
        free(lista);
    }
    return NULL;
}

PLista2 busca (PLista2 l, int v){
PLista2 p;
  for (p=l; p!=NULL; p=p->prox)
    if (p->coeficiente == v)
      return p;
  return NULL; /* não achou o elemento */
}

PLista2 inicializar(){  // inicializa as listas
  return NULL;
}

void imprime_lista (PLista2 l){
  int aux;
  PLista2 p = l;
  if (p!=NULL) {
    do {
      aux = p->expoente;
      if(p->coeficiente > 0 && p->expoente == 1){
        printf("+%dx", p->coeficiente);
        //printf("%d\n", p->expoente);
        p = p->prox;
      } else if (p->coeficiente > 0 && p->expoente == 0){
        printf("+%d", p->coeficiente);
        //printf("%d\n", p->expoente);
        p = p->prox;
      } else if (p->coeficiente > 0){
        printf("+%dx^%d", p->coeficiente, p->expoente);
        //printf("%d\n", p->expoente);
        p = p->prox;
      } else if (p->coeficiente < 0 && p->expoente == 0){
        printf("%d", p->coeficiente);
        //printf("%d\n", p->expoente);
        p = p->prox;
      } else if (p->coeficiente < 0 && p->expoente == 1){
        printf("%dx", p->coeficiente);
        //printf("%d\n", p->expoente);
        p = p->prox;
      } else if (p->coeficiente < 0){
        printf("%dx^%d", p->coeficiente, p->expoente);
        //printf("%d\n", p->expoente);
        p = p->prox;
      } else if (p->coeficiente == 0) {
        p = p->prox;
      } else{
        printf("%dx^%d", p->coeficiente, p->expoente);
        //printf("%d\n", p->expoente);
        p = p->prox; //ou p = p->ant;
      }
    } while (p != NULL);
  }
}

void flush(){  // limpa o lixo de memória e o buffer do teclado do scanf
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

void menu (){
    printf("\n\n================== OPERAÇÃO COM POLINOMIOS ====================");
    printf("\n1) Inserir novos polinômios.");
    printf("\n2) Somar polinômios.");
    printf("\n3) Subtrair polinômios.");
    printf("\n4) Derivar um polinômio.");
    printf("\n5) Sair.");
    printf("\n------------------------------------------------------------\n");
}

PLista2 insere_poli(char poli[50]){  // insere o polinômio na lista
  char operador;
  int coefs, exps, aux, qntChar;
  PLista2 lista_1;

  lista_1 = inicializar();

  char* aux2 = poli;
  // variável auxiliar qntChar que irá contar quantos elementos percorreu ao longo da string
  // pega o operador, pego o coeficiente, ignora 2 char (x^), pega o expoente 
  while(sscanf(aux2, "%c%d%*c%*c%d%n", &operador, &coefs, &exps, &qntChar) == 3){
    if(operador == '-'){
        aux = -1 * coefs;
        lista_1 = Insere_Ordenado(lista_1, aux, exps);
    }
    if(operador == '+'){
        aux = coefs;
        lista_1 = Insere_Ordenado(lista_1, aux, exps);
    }
    aux2 += qntChar;
  }


  printf("\n--------------------------------------\n");
  imprime_lista(lista_1);
  printf("\n--------------------------------------\n");

  return lista_1;
}

void soma_poli(PLista2 l, PLista2 l2){  // soma os polinômios e guarda o resul-
  int soma;                              // tado em uma terceira lista

  PLista2 list_soma;
  PLista2 list1;
  PLista2 list2;

  list_soma = inicializar();
  list1 = inicializar();
  list2 = inicializar();

  list1 = l;
  list2 = l2;

  do{
    if(list1 == NULL){ 
      Insere_Ordenado(list_soma, list2->coeficiente, list2->expoente); 
      list2 = list2->prox; 
    } else if(list2 == NULL){ 
      Insere_Ordenado(list_soma, list1->coeficiente, list1->expoente);
      list1 = list1->prox; 
    } else if (list1->expoente == list2->expoente){
      soma = list1->coeficiente + list2->coeficiente;
      list_soma = Insere_Ordenado(list_soma, soma, list1->expoente);
      list1 = list1->prox;
      list2 = list2->prox;
    } else if (list1->expoente < list2->expoente){
      list_soma = Insere_Ordenado(list_soma, list2->coeficiente, list2->expoente);
      list2 = list2->prox;
    } else if (list1->expoente > list2->expoente){
      list_soma = Insere_Ordenado(list_soma, list1->coeficiente,list1->expoente);
      list1 = list1->prox;
    }
  } while (list1 != NULL || list2 != NULL);

  printf("\n-------------SOMA----------------\n");
  imprime_lista(list_soma);
  printf("\n---------------------------------\n");

  clean_lista(list_soma);
}

void subtrai_poli(PLista2 l, PLista2 l2){
  int sub;

  PLista2 list_subtracao;
  PLista2 list1;
  PLista2 list2;

  list_subtracao = inicializar();
  list1 = inicializar();
  list2 = inicializar();

  list1 = l;
  list2 = l2;

  do{
    if(list1 == NULL){ 
      Insere_Ordenado(list_subtracao, -list2->coeficiente, list2->expoente);  // o negativo no list2 para fazer a distributiva
      list2 = list2->prox; 
    } else if(list2 == NULL){ 
      Insere_Ordenado(list_subtracao, list1->coeficiente, list1->expoente);
      list1 = list1->prox; 
    } else if (list1->expoente == list2->expoente){
      sub = list1->coeficiente - list2->coeficiente;
      list_subtracao = Insere_Ordenado(list_subtracao, sub, list1->expoente);
      list1 = list1->prox;
      list2 = list2->prox;
    } else if (list1->expoente < list2->expoente){
      list_subtracao = Insere_Ordenado(list_subtracao, -list2->coeficiente, list2->expoente); // o negativo no list2 para fazer a distributiva
      list2 = list2->prox;
    } else if (list1->expoente > list2->expoente){
      list_subtracao = Insere_Ordenado(list_subtracao, list1->coeficiente, list1->expoente);
      list1 = list1->prox;
    }
  } while (list1 != NULL || list2 != NULL);

  printf("\n-------------SUBTRAÇÃO----------------\n");
  imprime_lista(list_subtracao);
  printf("\n--------------------------------------\n");

  clean_lista(list_subtracao);
}

void deriva_poli(PLista2 l){
  int deriv_coef;
  int deriv_exp;


  PLista2 list_derivada;
  PLista2 list1;

  list_derivada = inicializar();
  list1 = inicializar();

  list1 = l;

  while (list1 != NULL){
    if (list1->expoente == 0){
      deriv_coef = list1->expoente * list1->coeficiente;  // nesta parte impedimos que retorne 0x^-1
      deriv_exp = list1->expoente;
      list_derivada = Insere_Ordenado(list_derivada, deriv_coef, deriv_exp);
      list1 = list1->prox;
    } else{
      deriv_coef = list1->expoente * list1->coeficiente;
      deriv_exp= list1->expoente - 1;

      list_derivada = Insere_Ordenado(list_derivada, deriv_coef, deriv_exp);

      list1 = list1->prox;
    }
  }
  printf("\n-------------DERIVADA-----------------\n");
  imprime_lista(list_derivada);
  printf("\n--------------------------------------\n");

  clean_lista(list_derivada);
}

// função específica paraverificar se há espaços entre números do polinômio
// Ex: 1 2+x4 5x
int valida_espacos(char *poli){
  char aux, *posfix;
  int i, erro=1, certo=0;
  posfix = poli;

  if (poli[0] == '\0'  || poli[0] == '0'){  // verifica se foi digitado um polinômio nulo
    return 1;
  }

  // verifica se há espaços entre números do polinômio
  aux = poli[0];
  for (i=1; i<strlen(poli); i++){
    if(poli[i] == ' '){
      while(poli[i] == ' '){
        i++;
      }
      if((isdigit(aux) != 0) && (isdigit(poli[i]) != 0)){
        return 1;
      }
    }
    aux = poli[i];
  }
  return certo;
}

void arruma_polinomio(char poli[50]){
  char aux_poli[50];
  int i, j=0;
  char polinomio[50], polinomio2[50];
  int ant;

  for (i=0; i < strlen(poli); i++){  // retira os espaços do poli digitado
    if (poli[i] == ' '){
      continue;
    } else {
      aux_poli[j] = poli[i];
      j++;
    }
  }
  aux_poli[j] = '\0';
  

  // iremos inserir x^1 => Ex: 12x             12x^1
  // para que fique fácil da função insere_poli separar os coefs dos exps
  j=0;
  for (i=0; i < strlen(aux_poli); i++){
    if(aux_poli[i] == 'x' && (aux_poli[i+1] == '\0' || aux_poli[i+1] != '^')) {
      poli[j] = 'x';
      j++;
      poli[j] = '^';
      j++;
      poli[j] = '1';
      j++;
    } else {
      poli[j] = aux_poli[i];
      j++;
    }
  }
  poli[j] = '\0';

  // insere um + no início para a função insere_poli
  j=0;
  for (i=0; i < strlen(poli)+1; i++){
    if (poli[0] != '+' && poli[0] != '-'){
      aux_poli[0] = '+';
      j++;
      aux_poli[j] = poli[i];
    } else {
      aux_poli[j] = poli[i];
      j++;
    } 
  }
  aux_poli[j] = '\0';


  // iremos inserir x^0 => Ex: 12             12x^0
  // para que fique fácil da função insere_poli separar os coefs dos exps
  j = 0;
  for (i = 0; i < strlen(aux_poli); i++) {
    if (aux_poli[i] == '+' || aux_poli[i] == '-' || aux_poli[i] == 'x' || aux_poli[i] == '^'){
      poli[j] = aux_poli[i];
      j++;
    } else {
      ant = aux_poli[i - 1];

      if (isdigit(ant) != 0){
        poli[j] = aux_poli[i];
        j++;
      }

      if (ant == '^') {
        poli[j] = aux_poli[i];
        j++;
      }
      if (ant == '+' || ant == '-') {
        while (aux_poli[i] != 'x' && aux_poli[i] != '^' && aux_poli[i] != '+' && aux_poli[i] != '-' && aux_poli[i] != '\0') {
          poli[j] = aux_poli[i];
          j++;

          if(aux_poli[i+1] == 'x'){
            poli[j] = aux_poli[i+1];
            j++;
          }
          if (aux_poli[i + 1] == '+' || aux_poli[i + 1] == '-' || aux_poli[i + 1] == '\n' || aux_poli[i + 1] == '\0') {
            poli[j] = 'x';
            j++;
            poli[j] = '^';
            j++;
            poli[j] = '0';
            j++;
            break;
          }
          else {
            i++;
          }
        }
      }
    }
  }
  poli[j] = '\0';

  strcpy(aux_poli, poli);
}


// após a lista ordenar o polinômio pelo maior grau, iremos verificar se
// ele tem coef zero, pois não podemos deixar que o monômio de maior grau
// tenha coef zero => EX: 0x^5 + 2x^2
int valida_coef_zero(PLista2 l){  
  int sub, errado = 1, certo = 0;

  PLista2 list1;

  list1 = inicializar();

  list1 = l;
  
  if(list1->coeficiente == 0){ 
    return errado;  
  } 

  return certo;
}

int main(void) {
  int op, op_deriv, val = 0, val_deriv = 0, validador_poli1 = 1, validador_poli2 = 1, validador1 = 1, validador2 = 1;
  char polinomio[50], polinomio2[50], polinomio_format[50], polinomio2_format[50];
  PLista2 p1;
  PLista2 p2;

  p1 = inicializar();
  p2 = inicializar();

  while (op!=5){
    menu();

    printf("\nDigite qual sua opção?: ");
    scanf("%d", &op);
    flush();

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
      clean_lista(p1);
      clean_lista(p2);

      memset(polinomio, 0, sizeof(polinomio)); // zera as strings
      memset(polinomio2, 0, sizeof(polinomio2)); // e adiciona '\0'

      validador_poli1 = 1;
      while (validador_poli1 == 1) {
        printf("\n1) Inserir novos polinômios: \n");
        printf("Digite o polinomio 1 (de grau maior que zero): \n");
        scanf("%[^\n]", polinomio);
        flush();

        validador1 = valida_espacos(polinomio);

        if (validador1 != 0){  // caso ambos retornem 0 de certo
          printf("\nDigite polinômios de grau maior que zero e sem espaços entre os números!!!\n");
        } else {  // caso ambos retornem 0 de certo
          
          arruma_polinomio(polinomio);  // arruma o polinômio digitado para função de inserir
          /*
          // Descomente para ver como ficou o polinômio após a formtação para
          // enviar a função, onde x ficou x^1 e onde 12 ficou 12x^0
          printf("\n-----------------------------------\n");

          printf("%s", polinomio);  

          printf("\n-----------------------------------\n");
          */
          p1 = insere_poli(polinomio);

          validador_poli1 = valida_coef_zero(p1);
          
          if (validador_poli1 == 1){
            clean_lista(p1);
            memset(polinomio, 0, sizeof(polinomio));
            printf("\nDigite um polinômio com o monômio de maior grau maior que zero!!!\n");
          }
        }
      }

      validador_poli2 = 1;
      while (validador_poli2 == 1) {
        printf("\nDigite o polinomio 2 (de grau maior que zero): \n");
        scanf("%[^\n]", polinomio2);
        flush();

        validador2 = valida_espacos(polinomio2);

        if (validador2 != 0){  // caso ambos retornem 0 de certo
          printf("\nDigite polinômios de grau maior que zero e sem espaços entre os números!!!\n");
        } else {  // caso ambos retornem 0 de certo
          arruma_polinomio(polinomio2);  // arruma o polinômio digitado para função de inserir
          /*
          // Descomente para ver como ficou o polinômio após a formtação para
          // enviar a função, onde x ficou x^1 e onde 12 ficou 12x^0
          printf("\n-----------------------------------\n");

          printf("%s", polinomio);  

          printf("\n-----------------------------------\n");
          */
          p2 = insere_poli(polinomio2);

          validador_poli2 = valida_coef_zero(p2);
          
          if (validador_poli2 == 1){
            clean_lista(p2);
            memset(polinomio2, 0, sizeof(polinomio2));
            printf("\nDigite um polinômio com o monômio de maior grau maior que zero\n");
          } 
        }
      }
    }
    if (op == 2) {
      printf("\n2) Somar polinômios:\n");
      soma_poli(p1, p2);
    }
    if (op == 3){
      printf("\n3) Subtrair polinômios:\n");
      subtrai_poli(p1, p2);
    }
    if (op == 4){
      printf("\n4) Derivar um polinômio:\n");
      printf("\nQual polinômio derivar [1/2]?: \n");
      scanf("%d", &op_deriv);
      flush();
      val_deriv = 0;
      while (val_deriv != 1){
        if (op_deriv != 1 && op_deriv != 2){
          printf("!!!Valor inválido\n\n");
          printf("\nDigite um valor válido desta vez [1/2]:\n");
          scanf("%d", &op_deriv);
          flush();
        } else val_deriv = 1;
      }
      if (op_deriv == 1){
        deriva_poli(p1);
      } else if (op_deriv == 2){
        deriva_poli(p2);
      }
    }
  }

  clean_lista(p1);
  clean_lista(p2);

  return 0;
}
