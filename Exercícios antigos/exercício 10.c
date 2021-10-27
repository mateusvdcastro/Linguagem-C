#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int ano;
    printf("\nDigite o ano: ");
    scanf("%d", &ano);
    (ano % 400 == 0) ? printf("%d é bissexto\n", ano) : 
    (ano % 4 == 0 && ano % 100 !=0) ? printf("%d é bissexto\n", ano) :
    printf("%d não é bissexto\n", ano);

    return (0);
}

