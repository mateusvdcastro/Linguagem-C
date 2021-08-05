/*
Escreva uma função que receba um número inteiro que representa um intervalo de tempo medido em minutos e
devolva o correspondente número de horas e minutos (por exemplo, converte 131 minutos em 2 horas e 11
minutos).
Mateus Vespasiano de Castro
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int horas;
    int minutos;
}hm;

hm tempo;

hm converter(int min){
    tempo.horas = min  / 60;
    tempo.minutos = ((int)min) % 60;
    return tempo;
}
int main(){
    float min;
    printf("Insira os minutos: ");
    scanf("%f",&min);
    converter(min);
    printf("\n%.0f minutos equivale a %dh:%dmin\n\n", min, tempo.horas, tempo.minutos);
    return 0;
}
