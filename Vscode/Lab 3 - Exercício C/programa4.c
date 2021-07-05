#include <stdio.h>
#include <math.h>

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
