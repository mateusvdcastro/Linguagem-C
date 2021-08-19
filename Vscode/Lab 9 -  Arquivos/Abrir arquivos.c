/*
Mateus Vespasiano de Castro RA: 159505
*/

#include <stdio.h>

int main(){
    FILE *arq;
    arq = fopen("arquivo.txt", "r");
    if (arq == NULL)
    printf("Erro ao abrir o arquivo\n");
    else
    printf("Arquivo aberto para leitura. \n");
    fprintf(arq, "Hello World!\n");
    fclose(arq);
    return 0;
}
