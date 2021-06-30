#include <stdio.h>
#include <locale.h>

float calcula_media(float n1, float n2, float n3, float n4){
    float media;
    media = (n1+n2+n3+n4)/4;
    return media;
}

int main(){
    setlocale(LC_ALL, "");
    float a, b, c, d, med;
    printf("Este programa cálcula a média entre 4 notas\n");
    printf("Digite uma nota: ");
    scanf("%f", &a);
    printf("Digite uma nota: ");
    scanf("%f", &b);
    printf("Digite uma nota: ");
    scanf("%f", &c);
    printf("Digite uma nota: ");
    scanf("%f", &d);
    med = calcula_media(a, b, c, d);
    printf("A média das notas foi: %f", &med);
}
