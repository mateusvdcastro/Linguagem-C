#include <stdio.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL,""); // permite colocarmos acentos
    float ma, soma;
    int cont=0;
    printf("Somar a m�dia dos alunos: ");
    printf("\nPara sair escolha/digite -1: ");
    while (ma != -1){
            printf("\nInsira uma m�dia: ");
            scanf("%f", &ma);
            soma = soma+ma;
            cont=cont+1;
}
printf("\nForam digitadas %d m�dias", cont- 1);
printf("\nO valor da soma � %f", soma+1);
}
