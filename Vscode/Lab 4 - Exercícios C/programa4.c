/*
Uma imagem em RGB pode ser representada por uma matriz tridimensional, sendo
que cada dimensão guarda os valores das intensidades de Vermelho, Verde e Azul para
cada pixel. Declare a matriz para armazenar uma imagem RGB de 128 x 128 pixels.
Mateus Vespasiano de Castro RA: 2248751
*/

#include <stdio.h>
#define MAX 128

int main(){

    int rgb, pixel, m, n, b, c, cont=1;
    int matriz[MAX][MAX][3];

    
    for (m=0; m<MAX; m++){
        for (n=0; n<MAX; n++){
            for (b=0; b<3;b++){
                matriz[m][n][b] = cont;
                cont++;
                
            }
            
        }
    }
    for (m=0; m<MAX; m++){
        for (n=0; n<MAX; n++){
            printf("[");
            for (b = 0; b<3; b++){
                printf("%d\t", matriz[m][n][b]);
            }
            printf("]");
            
        }
        printf("\n");
    }

}

