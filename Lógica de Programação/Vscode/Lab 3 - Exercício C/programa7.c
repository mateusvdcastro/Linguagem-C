#include <stdio.h>
#include <math.h>

/*Faça um programa que imprima todos os números quadrados perfeitos de um
intervalo informado pelo usuário. Números quadrados perfeitos são números cuja
raiz quadrada resultam em um valor inteiro.
Mateus Vespasiano de Castro RA: 2248751*/

int main(){
    float n1, n2;

    printf("Digite um intervalo: ");
    scanf("%f %f", &n1, &n2);

    int verificaint;
    float i = 0;
    float b, intoufloat;

    for (i = n1; i <= n2; i++) {
        b = sqrt(i);
        verificaint = b;
        intoufloat = b - verificaint;

        if (intoufloat == 0) {
            printf("%.0f ", i);
        }
    }
}
