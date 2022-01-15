#include <stdio.h>

int main(){
    char str[20] = "Teste";
    int i = 0;

    printf("Insira uma palavra: \n");
    gets(str);

    while(str[i] != '\0'){
        i ++;
    }

    printf("A palavra %s tem %d caracteres", str, i);
}

