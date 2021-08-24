/*
Mateus Vespasiano de Castro RA: 159505
*/
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){
    FILE *arq, *arq2;
    char *arq1, espaço[2] = " ";
    long tamarq, posini;
    arq = fopen(argv[1], "r");
    arq2 = fopen(argv[4], "w");

    posini = ftell(arq);
    fseek(arq, 0, SEEK_END);
    tamarq = ftell(arq);
    fseek(arq, posini, SEEK_SET);
    char strori[tamarq], novastr[tamarq];
    fread(&strori, sizeof(char), 100, arq);
    arq1 = strtok(strori, espaço);
    
    while (arq1 != NULL){
      if(strcmp(arq1, argv[2]) == 0){
        fprintf(arq2,"%s", argv[3]);
        fprintf(arq2, "%s", espaço);
      
      }
      else{
        fprintf(arq2,"%s", arq1);
        fprintf(arq2, "%s", espaço);
      }
      arq1 = strtok(NULL, espaço);
    }
    
    
    fclose(arq);
    fclose(arq2);
}
