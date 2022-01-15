/*
Mateus Vespasiano de Castro RA: 159505
*/

#include <stdio.h>

int main(){
    FILE *arq;
    char c;
    arq = fopen("arquivo1.txt", "r");
    if (arq == NULL)
    printf("Erro ao abrir o arquivo\n");
    else
    printf("Arquivo aberto para leitura. \n");
    c = getc(arq);
    while (c =! EOF){   /*EOF == end of file*/
        printf("%c", c);
        c = getc(arq);
    }
    fclose(arq);
    return 0;
}
