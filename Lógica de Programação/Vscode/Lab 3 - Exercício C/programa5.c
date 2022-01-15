#include <stdio.h>

/*Programa para classificar um triângulo. Informe os tamanhos dos segmentos e
classifique de acordo com equilátero, isósceles e escaleno.
Mateus Vespasiano de Castro RA: 2248751*/

int main(){
    float s1, s2, s3;

    printf("Digite o  segmento a: ");
    scanf("%f", &s1);
    printf("Digite o  segmento b: ");
    scanf("%f", &s2);
    printf("Digite o  segmento c: ");
    scanf("%f", &s3);

    if (s1 < (s2 + s3) && s2 < (s1 + s3) && s3 < (s2 + s1)){
        if (s1 == s2 && s2 == s3)
            printf("Os segmentos formam um triangulo Equilatero!");
        else if (s1 == s2|| s1 == s3 || s2 == s3)
            printf("O triangulo e Isoceles");
        else
            printf("O triangulo e Escaleno");
    } else 
        printf("Não podem formar um triangulo");
}
