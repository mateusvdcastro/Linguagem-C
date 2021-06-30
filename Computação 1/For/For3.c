#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");
    system("cls");
    printf("\033[31m");
    int contador = 0;
    for(int i=1; i <= 100; i++){
            if (i%5 == 0)
                printf("%d\n", i);
                contador++;
    }
    printf("\n O número de divisíveis por 5 é %d", contador);
    return 0;
}
