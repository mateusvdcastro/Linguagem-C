#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");
    system("cls");
    printf("\033[31m");
    int numero,contador = 0;
    for(int i=1; i <= 5; i++){
            printf("Ler um número: ");
            scanf("%d", &numero);
            if (numero < 0)
                contador++;
    }
    printf("\n O número de negativos é %d", contador);
    return 0;
}

