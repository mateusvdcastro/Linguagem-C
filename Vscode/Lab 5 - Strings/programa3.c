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

int main(){           
    char cargo[100];              
    float sal, sal_novo;    
    sal = 0;                         
    sal_novo = 0;                                           

    printf("Informe o cargo: ");
    fgets(cargo, 100, stdin);      
    printf("Informe o salario: ");
    scanf("%f", &sal);               
    printf("%s\n", cargo);
    if (cargo == "Gerente" || cargo == "gerente"){                          
        sal_novo = sal + (sal*0.1);         
        printf("Novo salario: %.2f\nSalario antigo: %.2f\nAumento de: %.2f", sal_novo, sal, sal_novo-sal);
    }  else if (cargo == "Engenheiro" || cargo == "engenheiro"){ 
        sal_novo = sal + (sal*0.2);       
        printf("Novo salario: %.2f\n salario antigo: %.2f, aumento de: %.2f", sal_novo, sal, sal_novo-sal);
    }   
    else if (cargo == "Auxiliar" || cargo == "auxiliar"){ 
        sal_novo = sal + (sal*0.3);
        printf("Novo salario: %.2f\n salario antigo: %.2f, aumento de: %.2f", sal_novo, sal, sal_novo-sal);           
    }   
    else{
        sal_novo = sal + (sal*0.4);       
        printf("Novo salario: %.2f\n salario antigo: %.2f, aumento de: %.2f", sal_novo, sal, sal_novo-sal);
    }
    return 0;
}
