/*
Mateus Vespasiano de Castro RA: 159505
*/

#include <stdio.h>

int main(){
    int x = 123;
    int *p;
    p = &x;
    printf("Conteudo da variavel x: %d\n", x);
    printf("Endereco da variavel x: %p\n", &x);
    ;
    printf("Conteudo da variavel ponteiro p: %p\n", p);
    printf("Conteudo da variavel apontada pelo ponteiro p: %d\n", *p);
    return 0; 
}
