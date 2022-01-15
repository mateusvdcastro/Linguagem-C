#include <stdio.h>
#include <locale.h>

int main(){
    setlocale (LC_ALL,"");
    float nums=1;
    float acumulador1, media;
    float cont = 0, cont2 = 0;
    while(nums != 0){
            printf("Digite um número: ");
            scanf("%f", &nums);
            if (nums > 50){
                    acumulador1 = acumulador1+nums;
                    cont2 = cont2 + 1;
            }
            if (nums < 20)
                    cont = cont + 1;
}
    media = (acumulador1/cont2);

    printf("Temos %f números menores que 20 e a média dos maiores que 50 é %f", cont, media);
}
