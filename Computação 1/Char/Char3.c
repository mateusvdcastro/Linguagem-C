#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");
    char nome[21], outronome[21];

    printf("Insira o seu nome: ");
    scanf("%s", nome);
    printf("Insira o nome de um  amigo(a): ");
    fflush(stdin);
    gets(outronome);
    printf("Meu nome eh %s, \n", nome);
    printf("O nome de meu amigo(a) eh %s, \n", outronome);
    return 0;
}
