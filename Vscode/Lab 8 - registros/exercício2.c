#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int horas;
    int minutos;
    float min, segundos;
}hm;

hm tempo;

hm converter(int min){
    tempo.horas = min  / 60;
    tempo.minutos = (int)min  % 60;
    tempo.segundos = (min - (int)min) * 60;
    return tempo;
}
int main(){
    float min;
    printf("Insira a quantidade de minutos: ");
    scanf("%f",&min);
    converter(min);
    printf("\nIsso e igual a %d h, %d min e %.2f s\n\n",
        tempo.horas, tempo.minutos, tempo.segundos);
    return 0;
}
