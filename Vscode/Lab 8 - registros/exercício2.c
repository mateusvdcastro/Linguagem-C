#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int h, m;
    float min, seg;
}hm;

hm tempo;
hm converter(int min){
    tempo.h = min / 60;
    tempo.m = (int)min % 60;
    tempo.seg = (min - (int)min) * 60;
    return tempo;
}

int main(){
    float min;
    printf("Insira os minutos: ");
    scanf("%f",&min);
    converter(min);
    printf("\nIsso e igual a %d horas, %d minutos e %.2f segundos\n\n",
        tempo.h, tempo.m, tempo.seg);
    return 0;
}