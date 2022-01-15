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
    arq = fopen("pessoas.txt", "rb");
    Pessoa p;
    while(fread(&p, sizeof(Pessoa), 1, arq) != 0){
        printf("Nome: %s - Idade %d\n", p.nome, p.idade);
    }
    fclose(arq);
    return 0;
}
