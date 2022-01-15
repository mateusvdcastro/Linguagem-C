#include <stdio.h>
#include <math.h>

/*Faça um programa que calcule a área de um trapézio ou o volume de uma pirâmide.
O usuário deverá escolher a opção e informar os valores necessários. Considere:
Mateus Vespasiano de Castro RA: 2248751*/

int main(){
    float B, b, h, A, V, a;
    char escolha;

    printf("Quer calculular o volume de um piramide ou a area de um trapezio [P/T]: ");
    scanf("%c", &escolha);

    if (escolha == 'P'){
        printf("Digite a altura: ");
        scanf("%f", &h);
        printf("Digite a largura da base (a): ");
        scanf("%f", &a);
        printf("Digite a largura da base (b): ");
        scanf("%f", &b);

        A = a*b;
        V = (A*h)/3;

        printf("O volume da piramide e: %2.f", V);

    } else if ( escolha == 'T') {
        printf("Digite a altura: ");
        scanf("%f", &h);
        printf("Digite o comprimento da base maior (B): ");
        scanf("%f", &B);
        printf("Digite o comprimento da base menor (b): ");
        scanf("%f", &b);

        A = ((B+b)*h)/2;

        printf("A area do trapezio e: %2.f", A);
    }

    else {
        printf("Invalido");
    }
    
}
