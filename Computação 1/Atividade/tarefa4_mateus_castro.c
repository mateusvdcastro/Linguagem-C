#include <stdio.h>
#include <locale.h>

int main(){
    setlocale (LC_ALL,"");
    int cont, cont2=-1;
    int idade = 1;
    float media;
    while(idade != 0){
        printf("Digite uma idade: ");
        scanf("%d", &idade);
        cont = cont + idade;
        cont2 = cont2 + 1;

}
    media = cont / cont2;

    printf("A média das idades digitas foi de %f", media);
}
