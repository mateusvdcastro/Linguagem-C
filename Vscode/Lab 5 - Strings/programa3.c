/*
Uma empresa concederá um aumento de salário aos seus funcionários, variável
de acordo com o cargo:

Gerente=10% Engenheiro=20% Auxiliar=30%

Faça um programa que leia o salário e o cargo de um funcionário e calcule o
novo salário. Se o cargo do funcionário não estiver na tabela, ele deverá então
receber 40% de aumento. Mostre o salário antigo, o novo salário e a diferença.

Mateus Vespasiano de Castro RA: 159505
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

int main(){           
    char cargo[100];              
    float sal=0, sal_novo=0;                                            

    printf("Informe o cargo: ");
    fgets(cargo, 100, stdin);      
    printf("Informe o salario: ");
    scanf("%f", &sal);               
    printf("%s\n", cargo);
    if ((strcmp("Gerente", cargo)) == 0 || (strcmp("gerente", cargo)) ==0){                          
        sal_novo = sal + (sal*0.1);         
        printf("Novo salario: %.2f\nSalario antigo: %.2f\nAumento de: %.2f", sal_novo, sal, sal_novo-sal);
    } else if ((strcmp("Engenheiro", cargo))==0 || (strcmp("engenheiro", cargo))==0){ 
        sal_novo = sal + (sal*0.2);       
        printf("Novo salario: %.2f\nSalario antigo: %.2f\nAumento de: %.2f", sal_novo, sal, sal_novo-sal);
    } else if ((strcmp("Auxiliar", cargo))==0 || (strcmp("auxiliar", cargo))==0){
        sal_novo = sal + (sal*0.3);
        printf("Novo salario: %.2f\nSalario antigo: %.2f\nAumento de: %.2f", sal_novo, sal, sal_novo-sal);           
    } else {
        sal_novo = sal + (sal*0.4);       
        printf("Novo salario: %.2f\nSalario antigo: %.2f\nAumento de: %.2f", sal_novo, sal, sal_novo-sal);
    }
    return 0;
}
