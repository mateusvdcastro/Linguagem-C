#include <stdio.h>
#include <math.h>

int main(){
    float A, P;
    char S;
    printf("\nDigite o seu sexo [M/F]: ");
    scanf("%c", &S);
    printf("\nDigite a sua altura: ");
    scanf("%f", &A);
    P = (S == 'M') ? (72.7 * A) - 58 : (62.1 * A) - 44.7;
    printf("\nO peso ideal para voce e: ");
    printf("%f", P);


    return (0);
}

