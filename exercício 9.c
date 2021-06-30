#include <stdio.h>
#include <math.h>

int main(){
    float A, P, IMC;
    printf("\nDigite o seu peso: ");
    scanf("%f", &P);
    printf("\nDigite a sua altura: ");
    scanf("%f", &A);
    IMC = P / (pow(A, 2));
    printf("\nSeu IMC e igual a : ");
    printf("%f", IMC);
    (IMC < 18.5) ? printf("\nAbaixo do peso") :  (IMC >= 18.5 && IMC <= 24.9) ? printf("\nPeso normal") :
    (IMC >= 25 && IMC <= 29.9) ? printf("\nSobrepeso") : (IMC >= 30 && IMC <= 34.9) ? printf("\nObesidade Grau 1") :
    (IMC >= 35 && IMC <= 39.9) ? printf("\nObesidade Grau 2") : printf("\nObesidade grau 3 ou morbida.");

    return (0);
}
