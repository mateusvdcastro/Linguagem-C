/*
Mateus Vespasiano de Castro RA: 159505

Escreva um programa que leia um arquivo texto e duas strings e um nome para um arquivo a ser criado
Todos os parâmetros devem ser passados como argumentos da função main(int argc, char *argv[])
O programa deve retornar uma mensagem ao usuário quando o número de parâmetros for incompatível com o problema (arquivoIn, string1, string2 e arquivoOut)
Uma função deve buscar por ocorrências da string1 no arquivoIn, substituí-la pela string2 durante a geração do arquivoOut
*/
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){

    FILE *arquivoln, *arquivoOut;

    char *arq1, quebra_str[2] = " ";
    long taman_arq, ini_arq;

    arquivoln = fopen(argv[1], "r");
    arquivoOut = fopen(argv[4], "w");

    if(argc != 5){ 
      printf("Quantidade de parametros diferente de 4!");
      return 0;
    }
    if(arquivoln == NULL){ 
        printf("O arquivo de entrada nao existe.");
        return 0;
    }
    if(arquivoOut == NULL){ 
        printf("Nao foi possivel criar o arquivo de saida.");
        return 0;
    }

    ini_arq = ftell(arquivoln);
    fseek(arquivoln, 0, SEEK_END);
    taman_arq = ftell(arquivoln);
    fseek(arquivoln, ini_arq, SEEK_SET);

    char str_ini[taman_arq];

    fread(&str_ini, sizeof(char), 100, arquivoln);

    arq1 = strtok(str_ini, quebra_str);
    while (arq1 != NULL){
      if(strcmp(arq1, argv[2]) == 0){
        fprintf(arquivoOut,"%s", argv[3]);
        fprintf(arquivoOut, "%s", quebra_str);
      
      }
      else{
        fprintf(arquivoOut,"%s", arq1);
        fprintf(arquivoOut, "%s", quebra_str);
      }
      arq1 = strtok(NULL, quebra_str);
    }
    
    
    fclose(arquivoln);
    fclose(arquivoOut);
}

/*
./Exercício.exe arquivo.txt unifesp carro arquivo2.txt
*/
