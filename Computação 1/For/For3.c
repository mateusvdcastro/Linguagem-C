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
    printf("\n O n�mero de divis�veis por 5 � %d", contador);
    return 0;
}
