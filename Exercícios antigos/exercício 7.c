#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){
    setlocale(LC_ALL, "");
    float M, C, i, J;
    int t;
    printf("Digite o Capital: ");
    scanf("%f", &C);
    printf("\nDigite a taxa em porcentagem: ");
    scanf("%f", &i);
    printf("\nDigite o tempo em meses: ");
    scanf("%d", &t);

    printf("\nO montante e: ");
    M = C*pow((1 + (i/100)), t);
    printf("%.2f", M);
    printf("\n");
    printf("\nPortanto, o juros foi igual a: ");
    J = M - C;
    printf("%.2f", J);


    return (0);

}
