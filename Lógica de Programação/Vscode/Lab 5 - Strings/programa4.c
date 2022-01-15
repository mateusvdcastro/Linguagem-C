/*
Faça um programa que leia um string e faça com que a primeira letra de cada
palavra fique em maiúscula. Para isso, basta subtrair 32 do elemento que deseja
alterar para maiúsculo

chrNome[0] = chrNome[0] – 32;

Ex. Entrada: lab. de linguagem de programação Ex. Saída : Lab. De Linguagem
De Programação

Mateus Vespasiano de Castro RA: 159505
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i;
    printf("Digite uma frase ou palavra: ");
    fgets(str, 100, stdin);
    str[0] = str[0] - 32;
    for (i = 0; i < strlen(str); i++){
        if (str[i] == ' '){
            str[i+1] = str[i+1] - 32;
        }
    }
    
    printf("A palavra/frase digita com a primeira letra maiuscula: %s", str);
}
