#include <stdio.h>

int main(void){
    float comprimento, largura, area, alunos;

    printf("Digite o comprimento da sala: ");
    scanf("%f", &comprimento);
    printf("\nDigite a largura da sala: ");
    scanf("%f", &largura);

    area = comprimento*largura;
    alunos = area / 2.25;

    printf("\nComprimento: %.2f", comprimento);
    printf("\nLargura: %.2f", largura);
    printf("\nArea: %.2f", area);
    printf("\nQuantidades de alunos que cabem na sala: %.2f", alunos);

}
