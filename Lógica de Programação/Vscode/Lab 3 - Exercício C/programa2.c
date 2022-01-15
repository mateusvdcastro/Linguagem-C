#include <stdio.h>

/*Programa que estima quantos alunos podem ficar dentro de uma sala de
aula. Para evitar o contato, é preciso respeitar distância mínima entre as cadeiras,
de 1,0m a 1,5 m. Neste cenário, é necessário garantir pelo menos 2,25m2 por aluno.
O usuário deve informar a largura e comprimento do local. Considere a área
retangular.
Mateus Vespasiano de Castro RA: 2248751*/

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
