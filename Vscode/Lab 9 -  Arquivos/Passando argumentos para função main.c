
/*
Mateus Vespasiano de Castro RA: 159505
*/

#include <stdio.h>
int main(int arg, char *argv[]){
    FILE *fr, *fw;
    char c;
    fr = fopen(argv[1], "r");
    fw = fopen(argv[2], "w");
    if (fr == NULL)
        return 1;
    if (fw == NULL)
        return 2;
    while (fscanf(fr, "%c", &c) != EOF)
        fprintf(fw, "%c", c);
    printf("Insira o nome: ");
    fclose(fr);
    fclose(fw);
    return 0;
