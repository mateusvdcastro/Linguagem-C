#include <stdio.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL,""); // permite colocarmos acentos
    int numero, somatorio=0, soma2=0;
    while(somatorio <20){
        printf("Leia um número: ");
        scanf("%d", &numero);
        somatorio += numero;
        if (somatorio<20){
            soma2 = soma2+numero;
        }
    }
printf("O valor da soma dos numeros maiores que 20 é %d", somatorio);
printf("\nO valor da soma dos numeros até 20 é %d", soma2);
}
