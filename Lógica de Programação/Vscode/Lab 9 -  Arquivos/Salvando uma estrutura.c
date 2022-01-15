/*
Mateus Vespasiano de Castro RA: 159505
*/

#include <stdio.h>
typedef struct pessoa{
    char nome[30];
    int idade;
}Pessoa;

int main(){
    FILE *arq;
    char c;
    arq = fopen("pessoas.txt", "a+");
    Pessoa p;
    printf("Insira o nome: ");
    scanf("%[^\n]", p.nome);
    printf("Insira a idade: ");
    scanf("%d", &p.idade);
    fwrite(&p, sizeof(Pessoa), 1, arq);
    fclose(arq);
    return 0;
}