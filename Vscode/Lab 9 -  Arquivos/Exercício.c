#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    char string1[9999], string2[20], *resultado, ler;
    int i=0, qtd;

    FILE *arqIN, *arqOUT;
    arqIN = fopen(argv[1], "r");
    arqOUT = fopen(argv[4], "w");

    
    if(arqIN == NULL){
        printf("Erro! O arquivo de entrada n�o existe.");
        return 0;
    }
    if(arqOUT == NULL){
        printf("Erro! N�o foi poss�vel criar o arquivo de sa�da.");
        return 0;
    }

    ler = getc(arqIN);

    

    while(ler != EOF){
      string1[i] = ler;
      i++; 
      ler = getc(arqIN);
    }

    if(strcmp(string1, argv[2])==0){
      printf("sim");
      argv[3] = string1;
    } else{
      printf("nn");
    }

    printf("%s", argv[3]);

    fclose(arqIN);

    fprintf(arqOUT, "%s", argv[2]);
    fprintf(arqOUT, "\n%s", argv[3]);

    fclose(arqOUT);

    


    return 0;
}

/*
./main arquivo_ex.txt arquivo_ex2.txt
*/
