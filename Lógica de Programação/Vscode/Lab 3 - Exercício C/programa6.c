#include <stdio.h>

/*Faça um programa que calcule o MDC - Máximo Divisor Comum e MMC - Mínimo
Múltiplo Comum de dois números informados pelo usuário.
Mateus Vespasiano de Castro RA: 2248751*/

int mdc(int A, int B){
    int resto;

    while (B != 0)
    {
        resto = A % B;
        A = B;
        B = resto;
    }
    return A;
    
}

int mmc(int A, int  B) {

    int resto, a, b;

    a = A;
    b = B;

    do {
        resto = a % b;

        a = b;
        b = resto;

    } while (resto != 0);

    return ( A * B) / a;
}

int main(void)
{
    int in1, in2;

    printf("Digite dois numeros inteiros para calcular o MDC e MMC: ");
    scanf("%d %d", &in1, &in2);

    printf("\nVocê digitou os números: %d %d", in1, in2);
    printf("\nMDC: %d", mdc(in1, in2));
    printf("\nMMC: %d", mmc(in1, in2));

}
