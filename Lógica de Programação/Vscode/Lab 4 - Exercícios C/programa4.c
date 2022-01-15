/*
Uma imagem em RGB pode ser representada por uma matriz tridimensional, sendo
que cada dimensão guarda os valores das intensidades de Vermelho, Verde e Azul para
cada pixel. Declare a matriz para armazenar uma imagem RGB de 128 x 128 pixels.
Mateus Vespasiano de Castro RA: 2248751
*/

#include <stdio.h>
#define L 128
#define C 128
#define P 3

int main(){

    int pixel[L][C][P];
    int linha, coluna, rgb;

    
    for (linha=0; linha<L; linha++){
        for (coluna=0; coluna<C; coluna++){
            for (rgb=0; rgb<3;rgb++){
                pixel[linha][coluna][rgb] = 0;
            }
            
        }
    }

    do{
        printf("Escolha um píxel {128x128}, linha X coluna: <1x128>");
        scanf("%dx%d", &linha, &coluna);
        linha = linha - 1;
        coluna = coluna - 1;
        printf("Digite R: ");
        scanf("%d", &pixel[linha][coluna][0]);
        printf("Digite G: ");
        scanf("%d", &pixel[linha][coluna][1]);
        printf("Digite B: ");
        scanf("%d", &pixel[linha][coluna][2]);
        printf("Deseja digitar outro pixel? [1: YES, -1:NO]:");
        scanf("%d", &linha);
    } while (linha != -1);

    for (linha=0; linha<L; linha++){
        for (coluna=0; coluna<C; coluna++){
            printf(" [ ");
            for (rgb = 0; rgb<3; rgb++){
                printf("%d ", pixel[linha][coluna][rgb]);
            }
            printf("]");
            
        }
        printf("\n");
    }
    return 0;
}

