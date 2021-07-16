#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Faça um programa que receba 2 strings (A e B) e retorne um terceiro string (C)
formado pelos caracteres de A e B intercalados. Ex.: Se A=’Quarta’ e
B=’Segunda’, a resposta deve ser ’QSueagrutnada’.

Mateus Vespasiano de Castro RA: 159505
*/


int main(){
    char A[20], B[20], C[40];
    int i=0,j=0, len=0, k=0;

    printf("String A: ");
    scanf(" %s", A);

    printf("String B: ");
    scanf(" %s", B);

    len = strlen(A) + strlen(B);

    for(i, j, k; i < len; i++){
        if(i%2 == 0){
            C[i] = A[j];
            j++;
        }else{
            C[i] = B[k];
            k++;
        }
    }
    printf ("String C: %s", C);
    return 0;
}
