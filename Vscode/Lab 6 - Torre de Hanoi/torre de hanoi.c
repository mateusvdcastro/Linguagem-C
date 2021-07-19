/*
Fazer um programa usando uma função recursiva para resolver o problema da Torre de
Hanói usando N discos. N deverá ser informado pelo usuário. O programa deverá informar
os passos necessários para resolução do problema.
Mateus Vespasiano de Castro
*/

#include <stdio.h>

void move_disco(int discos, char origem, char destino, char auxiliar){
    
    if (discos==1){
        printf("\nMover disco %d de %c para %c", discos, origem, destino);
    } else{
        move_disco(discos-1, origem, auxiliar, destino);
        printf("\nMover disco %d de %c para %c", discos, origem, destino);
        move_disco(discos-1, auxiliar, destino, origem);
    }
}

int main(void){
    int discos;

    printf("Digite o numero de discos: ");
    scanf("%d", &discos);

    move_disco(discos, 'A', 'C', 'B');

    return 0;
}
