#include <stdio.h>
#include <locale.h>

int main(){
    int numerox, num;
    int cont = 0;
    while (cont <= 2){
        printf("\nDigite um numero: ");
        scanf("%d",&num);
        if(cont == 0){
            numerox = num;
    }
        if (num < numerox){
            numerox = num;
    }
        cont = cont + 1;
    }
    printf("O menor valor dos numeros e %d",numerox);
    return 0;
}

