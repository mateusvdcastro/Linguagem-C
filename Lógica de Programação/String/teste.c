#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

int main(){
    setlocale(LC_ALL, "");
    int tamanho=0, maior=0;
    char cidade[40];
    for(int contador=1; contador <= 5; contador++){
        printf("\nDigite uma cidade:\n ");
        gets(cidade);
        tamanho = strlen(cidade);
        printf("A %d cidade foi %s e ela tem %d caracteres\n", contador, cidade, tamanho);
 }
}
