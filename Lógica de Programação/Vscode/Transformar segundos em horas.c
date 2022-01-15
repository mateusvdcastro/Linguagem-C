// Para compilar basta clicar no F6

#include <stdio.h>

int main(){
    int tempo, horas, minutos, segundos;
    printf("Entre com o tempo em segundos: ");
    scanf("%d", &tempo);
    printf("\nTempo em segundos = %d", tempo);
    horas = (tempo / 3600);
    printf("\nHoras = %d", horas);
    minutos = (tempo%3600/60);
    segundos = tempo%60;
    printf("\n\n%dh:%dm:%ds", horas, minutos, segundos);

    return 0;
}
