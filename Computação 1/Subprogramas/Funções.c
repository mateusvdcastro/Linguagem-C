#include <stdio.h>
#include <locale.h>

int soma(int a, int b){   // criou uma fun��o
int z;
z = a + b;
return z;
}

int subtracao(int x, int y){
int z;
z = x - y;
return z;
}

int multiplicacao(int x, int y){
int z;
z = x * y;
return z;
}

int divisao(int x, int y){
int z;
z = x / y;
return z;
}

int main(){
setlocale(LC_ALL, "");
int a, b, sum, sub, mult, div;
printf("Leia dois n�meros : ");
scanf("%i", &a);
scanf("%i", &b);
sum = soma(a,b); // chamou a fun��o
sub = subtracao(a,b);
mult = multiplicacao(a, b);
div = divisao(a, b);
printf("A subtra��o deu: %i\n", sub);
printf("A soma � %i\n", sum);
printf("A multiplica��o deu: %i\n", mult);
printf("A divis�o deu: %i\n", div);
return (0);
}
