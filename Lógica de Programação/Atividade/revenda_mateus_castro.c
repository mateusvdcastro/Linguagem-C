#include <stdio.h>
#include <locale.h>

int main(){
    setlocale (LC_ALL,"");
    int salario_min = 1014, comissao = 130;
    int n_carros, tot_vendas, tot, total_vendas, total;

    printf("Quantos carros o vendedor vendeu?: ");
    scanf("%d", &n_carros);

    printf("Qual o valor total das vendas?: ");
    scanf("%d", &tot_vendas);

    tot = ((salario_min*3) + (comissao*n_carros));

    total_vendas = tot_vendas*0.07;

    total = tot + total_vendas;

    printf("O salário deste vendedor é %d", total);

}
