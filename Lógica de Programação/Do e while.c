#include <stdio.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL,""); // permite colocarmos acentos
    float ma, soma;
    int cont=0;
    printf("Somar a média dos alunos: ");
    printf("\nPara sair escolha/digite -1: ");
    while (ma != -1){
            printf("\nInsira uma média: ");
            scanf("%f", &ma);
            soma = soma+ma;
            cont=cont+1;
}
printf("\nForam digitadas %d médias", cont- 1);
printf("\nO valor da soma é %f", soma+1);
}
