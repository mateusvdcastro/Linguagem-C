/*
Mateus Vespasiano de Castro RA: 159505
*/
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    char string[100], ler;
    int i;

    FILE *fr, *fw;
    char c;
    fr = fopen(argv[1], "r");
    fw = fopen(argv[4], "w");

    if(argc != 5){
      printf("Quantidade de parametros errados!");
      return 0;
    }
    if(fr == NULL){ 
        printf("Erro! O arquivo de entrada nao existe.");
        return 0;
    }
    if(fw == NULL){ 
        printf("Erro! Nao foi possivel criar o arquivo de saida.");
        return 0;
    }

    ler = getc(fr); 
    while(ler != EOF){ 

      string[i] = ler; 

      i++;
      ler = getc(fr);
    }
    printf("%s", &ler);

    if(strcmp(string, argv[2])==0){ 
      argv[3] = string; 
    }

    while (fscanf(fr, "%c", &c) != EOF)
        fprintf(fw, "%c", c);

    
    fclose(fr);
    fclose(fw);
    return 0;
}

/*
./main arquivo_ex.txt arquivo_ex2.txt
*/

/*
./main arquivo_ex.txt arquivo_ex2.txt
*/
