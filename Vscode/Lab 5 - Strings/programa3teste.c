#include <stdio.h>

int main(){
    char cargo[100];
    float sal, sal_novo;
    sal = 0;
    sal_novo = 0;

    printf("Informe o cargo: ");
    scanf("%s", cargo);
    printf("Informe o salario: ");
    scanf("%f", &sal);
    printf("%s\n", cargo);
    if (strcmp("Engenheiro", cargo)==0){
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