#include <stdio.h>
#include <math.h>

/*Escrever um algoritmo que lê um valor n inteiro e positivo e que calcula e escreve o valor de K. Considere:
Mateus Vespasiano de Castro RA: 2248751*/

float fatorial(int n){
    float fat;
    for (fat = 1; n > 1;n = n - 1)
    fat = fat * n;
    return fat;
}

int main(){
    float K;
    int n;

printf("Digite um numero inteiro: ");
scanf("%d", &n);

int i;

for (i=1; i <= n; i++){
    K = K + (1 + (1/(fatorial(i))));
 }

printf("O valor de K e: %.2f", K);

}
