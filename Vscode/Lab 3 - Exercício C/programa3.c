#include <stdio.h>
#include <math.h>

int main(){
    float t, v0, v, g=9.8, h;

    printf("Digite o instante: ");
    scanf("%f", &t);
    printf("Digite a velocidade inicial: ");
    scanf("%f", &v0);

    v = v0 - g*t;
    h = v0*t - (g*pow(t, 2))/2;

    printf("A velocidade final e: %2.f", v);
    printf("\nA altura e: %2.f", h);
}
