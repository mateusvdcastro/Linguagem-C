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

int torre_de_hanoi(){
    int discos;

    printf("Digite o numero de discos: ");
    scanf("%d", &discos);

    move_disco(discos, 'A', 'C', 'B');

    return 0;
}

