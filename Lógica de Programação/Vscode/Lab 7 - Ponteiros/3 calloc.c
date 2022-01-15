/*
Mateus Vespasiano de Castro RA: 159505
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a;
    a = (int*)calloc(1, sizeof(int)); // calloc armazena 1 espaço na memória do tamanho de um int e (int*) indica que o retorno da função é um ponteiro de inteiro
    *a = 123;     
    free(a);
    return 0;
}
