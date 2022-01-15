/*
NOME: Mateus Vespasiano de Castro 
RA: 159505
TURMA: IB
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char marca[15], modelo[50], Placa_do_Carro[6], ar_condicionado;
    int ano_de_fabricacao, numero_de_portas, Quilometragem;
}Carro;

Carro *carros[1000];

/* Opção de número 1 do Menu, aqui iremos inserir novos veículos ao arquivo
de texto carros.txt que está servindo como banco de dados */
void opcao_um(){
  int i;

  FILE *arquivo;
  arquivo = fopen("carros.txt", "a+");

  if (arquivo == NULL){
      printf("Nao foi possivel achar o arquivo");
  }
  Carro* carro = (Carro*)malloc(sizeof(Carro));

  printf("\n-------CADASTRO---------\n");
  printf("Digite a marca do carro: \n");
  scanf("%s", carro->marca);
  fprintf(arquivo, "%s\n", carro->marca);

  printf("\nQual o modelo do carro:\n");
  scanf("%s", carro->modelo);
  getchar();
  fprintf(arquivo, "%s\n", carro->modelo);

  printf("\nQual o ano de fabricacao do carro: \n");
  scanf("%d", &carro->ano_de_fabricacao);
  getchar();
  fprintf(arquivo, "%d\n", carro->ano_de_fabricacao);

  printf("\nQual a placa do carro [MAX 5 caracteres]: \n");
  scanf("%s", carro->Placa_do_Carro);
  getchar();
  fprintf(arquivo, "%s\n", carro->Placa_do_Carro);

  printf("\nQual a quilometragem do carro: \n");
  scanf("%d", &carro->Quilometragem);
  fprintf(arquivo, "%d\n", carro->Quilometragem);

  printf("\nQual o numero de portas do carro: \n");
  scanf("%d", &carro->numero_de_portas);
  fprintf(arquivo, "%d\n", carro->numero_de_portas);

  printf("\nO carro tem Ar condicionado(s/n): \n");
  scanf("%s", &carro->ar_condicionado);
  getchar();
  fprintf(arquivo, "%s\n", &carro->ar_condicionado);

  free(carro);
  fclose(arquivo);
}

/*
A função abaixo corresponde a opcão 2 do Menu, aqui podemos alterar carascte-
ristica por caracteristica de um veículo, sendo este escolhido pela placa. 
*/
void opcao_dois(){
  int i=0, op=0, pos, qtd_carros, qtd_linhas=1, existe_linha=0, r=0;
  char c;
  char placa[6], aux[15];

  FILE *arquivo;
  arquivo = fopen("carros.txt", "r");
  if (arquivo == NULL){
      printf("Nao foi possivel o arquivo");
  }
  FILE *arquivo2;
  arquivo2 = fopen("carros2.txt", "w");
  if (arquivo == NULL){
      printf("Não foi possivel abrir o arquivo2");
  }

  printf("\n\nQual a placa do carro que deseja alterar?: \n");
  scanf("%s", placa);

  while(fscanf(arquivo, "%s", aux) != EOF){
    carros[i] = (Carro*)malloc(sizeof(Carro));

    strcpy(carros[i]->marca, aux);
    fscanf(arquivo, "%s", carros[i]->modelo);
    fscanf(arquivo, "%d", &carros[i]->ano_de_fabricacao);
    fscanf(arquivo, "%s", carros[i]->Placa_do_Carro);
    fscanf(arquivo, "%d", &carros[i]->Quilometragem);
    fscanf(arquivo, "%d%*c", &carros[i]->numero_de_portas);
    carros[i]->ar_condicionado = fgetc(arquivo);
    fgetc(arquivo);

    if (strcmp(carros[i]->Placa_do_Carro, placa)==0){
      pos = i;
      r = 1;
    }
    i++;
  }

  if (r!=1){
    printf("\nNao foi possivel encontrar um veiculo com essa placa.\n");
    fclose(arquivo);
    fclose(arquivo2);
    remove("carros2.txt");
  } else{
    rewind(arquivo);  // coloca o cursor no começo do arquivo
    c = getc(arquivo);

    while(c!=EOF){
      if(c=='\n'){
        qtd_linhas++;   // Contanto a quantidade de linhas de carros.txt
      }
      c = getc(arquivo);
    }
    rewind(arquivo);  
    qtd_carros = qtd_linhas/7;

    for (i=0; i<qtd_carros; i++){ //iterando pela quantidade de carros 
      if (i==pos){
        printf("\n---Alterando cadastro---\n");
        printf("\n1) Placa: %s\n", carros[pos]->Placa_do_Carro);
        printf("2) Marca: %s\n", carros[pos]->marca);
        printf("3) Modelo: %s\n", carros[pos]->modelo);
        printf("4) Ano de Fabricacao: %d\n", carros[pos]->ano_de_fabricacao);
        printf("5) Quilometragem: %d\n", carros[pos]->Quilometragem);
        printf("6) Numero de Portas: %d\n", carros[pos]->numero_de_portas);
        printf("7) Ar Condicionado: %c\n", carros[pos]->ar_condicionado);
        printf("8) Fim das alteracoes.");

        while(op!=8){
          printf("\n\n---Alterando cadastro---");
          printf("\nDigite o numero do atributo que quer alterar:\n");
          scanf("%d", &op);
          if (op==1){
            printf("\n!!!A placa e o unico que nao podemos alterar.\n");
          }
          if (op==2){
            printf("\nDigite a nova marca:\n");
            scanf("%s", carros[pos]->marca);
          }
          if (op==3){
            printf("\nDigite o novo modelo:\n");
            scanf("%s", carros[pos]->modelo);
          }
          if (op==4){
            printf("\nDigite o novo ano de fabricacao:\n");
            scanf("%d", &carros[pos]->ano_de_fabricacao);
          }
          if (op==5){
            printf("\nDigite a nova quilometragem:\n");
            scanf("%d", &carros[pos]->Quilometragem);
          }
          if (op==6){
            printf("\nDigite o novo numero de portas:\n");
            scanf("%d%*c", &carros[pos]->numero_de_portas);
          }
          if (op==7){
            printf("\nO carro possui ar condicionado?:\n");
            scanf("%c", &carros[pos]->ar_condicionado);
          }
          if (op==8){
            printf("Fim das alteracoes.");
            break;
          }
        }
        fprintf(arquivo2, "%s\n", carros[pos]->marca);
        fprintf(arquivo2, "%s\n", carros[pos]->modelo);
        fprintf(arquivo2, "%d\n", carros[pos]->ano_de_fabricacao);
        fprintf(arquivo2, "%s\n", carros[pos]->Placa_do_Carro);
        fprintf(arquivo2, "%d\n", carros[pos]->Quilometragem);
        fprintf(arquivo2, "%d\n", carros[pos]->numero_de_portas);
        fprintf(arquivo2, "%c\n", carros[pos]->ar_condicionado);
      } else {
        fprintf(arquivo2, "%s\n", carros[i]->marca);
        fprintf(arquivo2, "%s\n", carros[i]->modelo);
        fprintf(arquivo2, "%d\n", carros[i]->ano_de_fabricacao);
        fprintf(arquivo2, "%s\n", carros[i]->Placa_do_Carro);
        fprintf(arquivo2, "%d\n", carros[i]->Quilometragem);
        fprintf(arquivo2, "%d\n", carros[i]->numero_de_portas);
        fprintf(arquivo2, "%c\n", carros[i]->ar_condicionado);
      }
    }
    fclose(arquivo);   // utilizamos de um arquivo auxiliar para fazer as alte-
    fclose(arquivo2);  //rações, ele lê o antigo arquivo, guarda as informações
    rename("carros.txt", "old.txt"); // e altera oq for necessário, dps escreve
    rename("carros2.txt", "carros.txt"); // em outro arquivo, apaga o primeiro,
    remove("old.txt"); // e renomeia o novo para o nome do primeiro.

    for(i=0; i<qtd_carros; i++){  //liberando a memória 
        free(carros[i]);
    }

  }
}

// Aqui iremos exibir as informações do veículo
void opcao_tres(){
  int i = 0, r=0;
  char placa[6], aux[15];

  FILE *arquivo;
  arquivo = fopen("carros.txt", "r");
  if (arquivo == NULL){
      printf("Nao foi possível o arquivo");
  }

  printf("\n\nQual a placa do carro que deseja exibir? [MAX 5 caracteres]: \n");
  scanf("%s", placa);

  while(fscanf(arquivo, "%s", aux) != EOF){
    carros[i] = (Carro*)malloc(sizeof(Carro));
    strcpy(carros[i]->marca, aux);
    fscanf(arquivo, "%s", carros[i]->modelo);
    fscanf(arquivo, "%d", &carros[i]->ano_de_fabricacao);
    fscanf(arquivo, "%s", carros[i]->Placa_do_Carro);
    fscanf(arquivo, "%d", &carros[i]->Quilometragem);
    fscanf(arquivo, "%d%*c", &carros[i]->numero_de_portas);
    carros[i]->ar_condicionado = fgetc(arquivo);
    fgetc(arquivo);

    if (strcmp(carros[i]->Placa_do_Carro, placa)==0){
      printf("\nPlaca: %s\n", carros[i]->Placa_do_Carro);
      printf("Marca: %s\n", carros[i]->marca);
      printf("Modelo: %s\n", carros[i]->modelo);
      printf("Ano de Fabricacao: %d\n", carros[i]->ano_de_fabricacao);
      printf("Quilometragem: %d\n", carros[i]->Quilometragem);
      printf("Numero de Portas: %d\n", carros[i]->numero_de_portas);
      printf("Ar Condicionado: %c\n", carros[i]->ar_condicionado);
      r = 1;
    }
    i++;
  }
  if (r!=1) {
  printf("\n!!!Nao foi possivel encontrar um veiculo com essa placa.\n\n");
  }
  fclose(arquivo);

  int qtd_carros = i;
  for(i=0; i<qtd_carros; i++){
      free(carros[i]);
  }
}

// Aqui iremos apagar um registro de veículo pela placa
void opcao_quatro(){
  int i=0, pos, qtd_carros, qtd_linhas=1, r=0;
  char placa[6], aux[15], c;

  FILE *arquivo;
  arquivo = fopen("carros.txt", "r");
  if (arquivo == NULL){
      printf("Nao foi possivel o arquivo");
  }
  FILE *arquivo2;
  arquivo2 = fopen("carros2.txt", "w");
  if (arquivo == NULL){
      printf("Nao foi possivel abrir o arquivo2");
  }

  printf("\n\nQual a placa do carro que deseja apagar?: \n");
  scanf("%s", placa);

  while(fscanf(arquivo, "%s", aux) != EOF){
    carros[i] = (Carro*)malloc(sizeof(Carro));
    strcpy(carros[i]->marca, aux);
    fscanf(arquivo, "%s", carros[i]->modelo);
    fscanf(arquivo, "%d", &carros[i]->ano_de_fabricacao);
    fscanf(arquivo, "%s", carros[i]->Placa_do_Carro);
    fscanf(arquivo, "%d", &carros[i]->Quilometragem);
    fscanf(arquivo, "%d%*c", &carros[i]->numero_de_portas);
    carros[i]->ar_condicionado = fgetc(arquivo);
    fgetc(arquivo);
    if (strcmp(carros[i]->Placa_do_Carro, placa)==0){
      pos = i;
      r = 1;
    }
    i++;
  }

  if (r!=1){
    printf("\nNao foi possivel encontrar um veiculo com essa placa.\n");
    fclose(arquivo);
    fclose(arquivo2);
    remove("carros2.txt");
  } else {
    rewind(arquivo);
    c = getc(arquivo);

    while(c!=EOF){
      if(c=='\n'){
        qtd_linhas++;
      }
      c = getc(arquivo);
    }
    rewind(arquivo);
    qtd_carros = qtd_linhas/7;

    for (i=0; i<qtd_carros; i++){
      if (i==pos){
        continue;  // na posição do carro que conter a placa, ele passa sem es-
      } else {  // crever nada no novo arquivo, assim conseguimos "apagar"
        fprintf(arquivo2, "%s\n", carros[i]->marca);
        fprintf(arquivo2, "%s\n", carros[i]->modelo);
        fprintf(arquivo2, "%d\n", carros[i]->ano_de_fabricacao);
        fprintf(arquivo2, "%s\n", carros[i]->Placa_do_Carro);
        fprintf(arquivo2, "%d\n", carros[i]->Quilometragem);
        fprintf(arquivo2, "%d\n", carros[i]->numero_de_portas);
        fprintf(arquivo2, "%c\n", carros[i]->ar_condicionado);
      }
    }
    fclose(arquivo);
    fclose(arquivo2);
    rename("carros.txt", "old.txt");
    rename("carros2.txt", "carros.txt");
    remove("old.txt");

    for(i=0; i<qtd_carros; i++){
        free(carros[i]);
    }
  }
}

int main(){
  int n_cad;

  while (n_cad != 5){
    printf("\n\n");
    printf("----------------MENU-------------------\n");
    printf("1) Inserir novo cadastro de veiculo");
    printf("\n2) Alterar cadastro");
    printf("\n3) Mostrar os dados de um veiculo");
    printf("\n4) Apagar registro");
    printf("\n5) sair\n");
    printf("----------------------------------------\n");

    printf("\nDigite uma opcao do Menu: ");
    scanf("%d", &n_cad);

    if (n_cad==1){
      opcao_um();
    }
    if (n_cad==2){
      opcao_dois();
    }
    if (n_cad==3){
      opcao_tres();
    }
    if (n_cad==4){
      opcao_quatro();
    }
  }
  return 0;
}
