/*
Fazer um programa usando uma função recursiva para resolver o problema da Torre de
Hanói usando N discos. N deverá ser informado pelo usuário. O programa deverá informar
os passos necessários para resolução do problema.
Mateus Vespasiano de Castro
*/

#include <stdio.h>


void move_disco(int d, char ori, char dest, char aux){
    
    if (d==1){
        printf("\nMover disco %d de %c para %c", d, ori, dest);
    } else{
        move_disco(d-1, ori, aux, dest);
        printf("\nMover disco %d de %c para %c", d, ori, dest);
        move_disco(d-1, aux, dest, ori);
    }
}

int main(void){
    int discos;

    printf("Digite o numero de discos: ");
    scanf("%d", &discos);

    move_disco(discos, 'A', 'C', 'B');

    return 0;
}

