#include <stdio.h>
#include <locale.h>

main(){
    setlocale (LC_ALL,"");
    int num;
    printf("--> Digite um n�mero entre 1 e 7: ");
    scanf("%d", &num);
    if (num == 1)
        printf("  Domingo");
    if (num == 2)
        printf("  Segunda");
    if (num == 3)
        printf("  Ter�a");
    if (num == 4)
        printf("  Quarta");
    if (num == 5)
        printf("  Quinta");
    if (num == 6)
        printf("  Sexta");
    if (num == 6)
        printf("  S�bado");
    if (num > 7)
        printf("  Numero fora do solicitado, n�o existe dia com este valor...");
    if (num < 1)
        printf("  Numero fora do solicitado, n�o existe dia com este valor...");
return(0);
}
