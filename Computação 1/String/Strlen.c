#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(){
    setlocale(LC_ALL, "");
    int comprimento;
    char palavra[40];
    printf("Digite uma palavra: ");
    gets(palavra);
    comprimento = strlen(palavra);
    printf("\n Esta palavra %s tem %d caracteres", palavra, comprimento);
    printf("\n---------------------------------------------------------");
}
