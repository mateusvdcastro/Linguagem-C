/*
Mateus Vespasiano de Castro RA: 159505
*/
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){
    FILE *arquivoln, *arquivoOut;
    char *arq1, quebra_str[2] = " ";
    long tamarq, ini_arq;
    arquivoln = fopen(argv[1], "r");
    arquivoOut = fopen(argv[4], "w");

    ini_arq = ftell(arquivoln);
    fseek(arquivoln, 0, SEEK_END);
    tamarq = ftell(arquivoln);
    fseek(arquivoln, ini_arq, SEEK_SET);
    char strori[tamarq], novastr[tamarq];
    fread(&strori, sizeof(char), 100, arquivoln);
    arq1 = strtok(strori, quebra_str);

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
