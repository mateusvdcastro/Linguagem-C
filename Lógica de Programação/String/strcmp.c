// Comparação de Strings (strcmp)
// int negativo: se a str1 for menor que a str2
// número zero: Se str1 for igual a str2
// int positivo: Sea a str1 for maior que a str2
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(){
    setlocale(LC_ALL, "");
    int comprimento, comparacao=0;
    char palavra1[40];
    char palavra2[20];
    printf("Digite uma palavra1: ");  // use aaa
    gets(palavra1);
    printf("Digite uma palavra2: ");  // use bbb
    gets(palavra2);
    comparacao=strcmp(palavra1,palavra2);
    printf("\n O valor da comparação é %d ", comparacao);
    if (comparacao>0){
        printf("\n A palavra %s é maior que % s", palavra1, palavra2);
    }
    if (comparacao == 0){
        printf("\n A palavra %s é igual que % s", palavra1, palavra2);
    }
    if (comparacao < 0){
        printf("\n A palavra %s é menor que % s", palavra1, palavra2);
    }
    printf("\n---------------------------------------------------------");
}
