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

typedef struct {
  char nome_do_produto[26];
  int quantidade_vendida;
  int mes_de_venda;
  char quem_comprou[35];
}Produto;

// Função que exibe o total de vendas de um determinado mês
void tot_vendas_m(Produto *produtos, Produto *ponteiro, int n){
  int mes=0, i, tot, val=0;
  printf("\n\n--------------Total de Vendas------------------");
  printf("\nDigite o mês que quer exibir o total de vendas : ");
  scanf("%d", &mes);
  while (val != 1){
    /*isalpha(mes) != 0 || */
    if (mes < 0 || mes > 12) {
      printf("Mês inválido, digite um mês válido [1 a 12]: ");
      scanf("%d", &mes);
    } else val = 1;
  }
  val = 0;

  tot =0 ;
  for (ponteiro = &produtos[0]; ponteiro<&produtos[n]; ponteiro++) {
    if (ponteiro->mes_de_venda == mes){
        tot = tot + ponteiro->quantidade_vendida;
    }
  }
  printf("Total vendido no mes %d: %d unidade(s)", mes, tot);
}

//Função que exibe o total de vendas de um determinado mês, produto e comprador
void tot_pvm(Produto *produtos, Produto *ponteiro, int n) {
  char produto[30], nome[50];
  int mes=0, tot=0, val=0, i;

  printf("\n--------- BUSCA POR PRODUTO, MÊS E COMPRADOR ---------\n");
  printf("\nNome do produto: ");
  scanf("%s", produto);
  fflush(stdin);

  while(val!=1){
    val = 0;
    for (ponteiro = &produtos[0]; ponteiro<&produtos[n]; ponteiro++){
      if(strcmp(ponteiro->nome_do_produto, produto)==0)
        val = 1;
    }
    if (val != 1){
      printf("\n!!!Este produto não está presente na base de dados.");
      printf("\nDigite novamente: ");
      scanf("%s", produto);
    }
  }

  val = 0;
  printf("\nDigite o mês: ");
  scanf("%d", &mes);

  while (val != 1){
    if (mes < 0 || mes > 12) {
      printf("Mês inválido, digite um mês válido [1 a 12]: ");
      scanf("%d", &mes);
    } else val = 1;
  }

  printf("\nNome do cliente comprador: ");
  scanf("%s", nome);
  fflush(stdin);  // limpar o buffer
  
  val = 0;
  while (val != 1){
    for (ponteiro = &produtos[0]; ponteiro<&produtos[n]; ponteiro++){
      if (strcmp(ponteiro->quem_comprou, nome) == 0){
        val = 1;
      }
    }
    if (val != 1) {
      printf("\n!!!Este nome não está presente na base de dados.");
      printf("\nDigite novamente: ");
      scanf("%s", nome);
      fflush(stdin);
    }
  }
  

  for (ponteiro=&produtos[0];ponteiro<&produtos[n];ponteiro++){
    if (ponteiro->mes_de_venda == mes && strcmp(ponteiro->nome_do_produto, produto) == 0 && strcmp(ponteiro->quem_comprou, nome) == 0){
      printf("\nMês: %d \nProduto:%s \nComprador: %s \nQuantidade Vendida: %d", ponteiro->mes_de_venda, ponteiro->nome_do_produto, ponteiro->quem_comprou, ponteiro->quantidade_vendida);
      tot = tot + ponteiro->quantidade_vendida;
    }
  }

  printf("\n\n--------------Resultados-----------------\n");
  printf("\nTotal de vendas do produto %s no mês %d\npara o(a) cliente %s: %d\n", produto, mes, nome, tot);

}

// Função que exibe o total de vendas ao longo do ano
void tot_vendas(Produto *produtos, Produto *ponteiro, int n){
  int i=0, j=0, z=0, tot=0, val=0;
  char produto[30];

  printf("\n\n----------Quantidade Vendida---------------\n");

  for (ponteiro=&produtos[0], i=0; ponteiro<&produtos[n]; ponteiro++, i++){
    val = 0;
    for (z=0; z<i; z++){
      if(strcmp(produtos[i].nome_do_produto, produtos[z].nome_do_produto)==0){
        val=1;
        break;
      }
    }
    if (val == 1){
      continue;
    }

    tot = 0;
    printf("\n-> Quantidade vendida de '%s':", ponteiro->nome_do_produto);
    for(j=0; j<n; j++){
        if(strcmp(produtos[j].nome_do_produto, ponteiro->nome_do_produto)==0){
            printf("\n+ No mês %d, a quantidade vendida foi: %d.", produtos[j].mes_de_venda, produtos[j].quantidade_vendida);
            tot += produtos[j].quantidade_vendida;
        }
    }
    printf("\n= O total de vendas de %s foi: %d unidade(s).\n", ponteiro->nome_do_produto, tot);
  }
}

// Função que exibe o total de vendas por cliente
void tot_cliente(Produto *produtos, Produto *ponteiro, int n){
  int i=0, j=0, z=0, tot=0, val=0;
  char cliente[50];

  printf("\n-----------------Total vendido por cliente--------------");
  for (ponteiro=&produtos[0], i=0; ponteiro<&produtos[n]; ponteiro++, i++){

  val = 0;
  for(z=0; z<i; z++){
      if(strcmp(produtos[i].quem_comprou, produtos[z].quem_comprou)==0){
          val=1;
          break;
      }
  }
  if (val == 1){
    continue;
  }
  tot = 0;
  for(j=0; j<n; j++){
      if(strcmp(produtos[j].quem_comprou, ponteiro->quem_comprou)==0){

          tot+= produtos[j].quantidade_vendida;
      }
  }
  
  printf("\nO cliente %s comprou, ao total: %d unidades de produtos.", ponteiro->quem_comprou, tot);
  }
  printf("\n--------------------------------------------------------\n");
}

// Função Menu
void menu (){
    printf("\n\n====================== Cadastro ======================");
    printf("\n1) Total de vendas num dado mês (de todos os produtos): ");
    printf("\n2) Total de vendas de um determinado produto num dado mês para um determinado cliente: ");
    printf("\n3) Total de vendas de cada produto (em todos os meses): ");
    printf("\n4) Total vendido para cada cliente: ");
    printf("\n5) Fim");
    printf("\n----------------------------------------------------\n");
}

int main(void) {
  setlocale(LC_ALL,"");
  int n, op, tam, val = 0, i=0;
  // A variável n indica o tamanho do vetor
  printf("\n------------------- Cadastro -----------------------\n");
  printf("Digite a quantidade de produtos a serem computados: ");
  scanf("%d", &n);
  
  val = 0;
  while (val!=1){
    if (n == 0 || n < 0){
      printf("\nNúmero inválido, digite novamente: ");
      scanf("%d", &n);
    } else val = 1;
  }

  val = 0;

  Produto *produtos, *ponteiro;
  // alocaçãp dinâmica da memória
  produtos = (Produto*)malloc(n * sizeof(Produto));

  ponteiro = &produtos[0];
  // primeiro uso de aritmética de ponteiros
  for (ponteiro=&produtos[0];ponteiro<&produtos[n];ponteiro++){
    printf("\nDigite o nome do produto: ");
    scanf("%s", ponteiro->nome_do_produto);
    printf("\nDigite a quantidade que deseja comprar:");
    scanf("%d", &ponteiro->quantidade_vendida);
    printf("\nDigite o mês em que está:");
    scanf("%d", &ponteiro->mes_de_venda);
    while (val != 1){
    if (ponteiro->mes_de_venda < 0 || ponteiro->mes_de_venda > 12) {
      printf("Mês inválido, digite um mês válido [1 a 12]: ");
      scanf("%d", &ponteiro->mes_de_venda);
    } else val = 1;
    }
    printf("\nDigite o seu nome:");
    scanf("%s", ponteiro->quem_comprou);
  }

  val = 0;
  // Descomente essa seção e comente a de cima caso queira agilizar
  /*
  strcpy(produtos[0].nome_do_produto, "Caneca");
  produtos[0].quantidade_vendida = 15;
  produtos[0].mes_de_venda = 2;
  strcpy(produtos[0].quem_comprou, "Joaquim");
  strcpy(produtos[1].nome_do_produto, "Hotwheels");
  produtos[1].quantidade_vendida = 14;
  produtos[1].mes_de_venda = 1;
  strcpy(produtos[1].quem_comprou, "AnaLuiza");
  strcpy(produtos[2].nome_do_produto, "Caneca");
  produtos[2].quantidade_vendida = 2;
  produtos[2].mes_de_venda = 2;
  strcpy(produtos[2].quem_comprou, "Carlos");
  strcpy(produtos[3].nome_do_produto, "Mochila");
  produtos[3].quantidade_vendida = 6;
  produtos[3].mes_de_venda = 1;
  strcpy(produtos[3].quem_comprou, "Carlos");
  strcpy(produtos[4].nome_do_produto, "Garrafa");
  produtos[4].quantidade_vendida = 4;
  produtos[4].mes_de_venda = 12;
  strcpy(produtos[4].quem_comprou, "Leandro");
  strcpy(produtos[5].nome_do_produto, "Caneta");
  produtos[5].quantidade_vendida = 24;
  produtos[5].mes_de_venda = 9;
  strcpy(produtos[5].quem_comprou, "Leandro");
  */
  while (op!=5){
    menu();

    printf("\nDigite qual sua opção?: ");
    scanf("%d", &op);

    while (val != 1){
    if (op != 1 && op != 2 && op != 3 && op != 4 && op != 5){
      printf("!!!Valor inválido\n\n");
      menu();
      printf("\nDigite um valor válido desta vez:");
      scanf("%d", &op);
    } else val = 1;
    }
    
    if (op == 1) {
      tot_vendas_m(produtos, ponteiro, n);
    }
    if (op == 2) {
      tot_pvm(produtos, ponteiro, n);
    }
    if (op == 3){
      tot_vendas(produtos, ponteiro, n);
    }
    if (op == 4){
      tot_cliente(produtos, ponteiro, n);
    }
  }
  // desalocando a memória
  free(produtos);
  return 0;
}
