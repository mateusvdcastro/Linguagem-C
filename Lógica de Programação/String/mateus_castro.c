#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
int main(){
setlocale(LC_ALL,"");
char opcao=1;
while (opcao !=0){
    system("cls");
    printf("\nExerc�cio sobre o uso de strings");
    printf("\nEscolha uma op��o: ");
    scanf("%c",&opcao);
    fflush(stdin);
    switch(opcao){
        case '0':
            exit(0);
            break;
        case '1':
            printf("\nSeu trabalho ser� nesta op��o\n");
            int tamanho=0, maior=0;
            char cidade[40];
            for(int contador=1; contador <= 5; contador++){
                printf("\nDigite uma cidade:\n ");
                gets(cidade);
                tamanho = strlen(cidade);
                printf("A %d cidade foi %s e ela tem %d caracteres\n", contador, cidade, tamanho);
            }
            system("pause");
            break;
        case '2':
            printf("\nEm constru��o\n");
            system("pause");
            break;
        case '3':
            printf("\nEm constru��o\n");
            system("pause");
            break;
        default:
            printf("\nOpi��o n�o encontrada\n");
            system("pause");
        }
    }
return(0);
}


