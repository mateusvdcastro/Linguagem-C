#include <stdio.h>
#include <locale.h>

main(){
    setlocale (LC_ALL,"");
    float salario, salario_final;
    printf("Digite seu sal�rio bruto: ");
    scanf("%f", &salario);
    salario_final = (salario*0.92) - 60;

    printf("O funcion�rio receber� R$ %f", salario_final);
return(0);
}
