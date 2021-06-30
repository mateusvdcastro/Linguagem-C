#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int main(){
setlocale(LC_ALL,"");
int opcao,n1,n2,n3,n4,soma=0;
while (opcao != 3){
    system("cls");
    printf ("\nPrograma Exemplo Manipulação de Arquivos");
    printf ("\nSeu nome completo aqui - RA");
    printf ("\n1- Gravar \n2- Calcular \n3- Sair \n");
    printf("\nEscolha a opção desejada: ");
    scanf("%d",&opcao);
    switch (opcao){
    FILE*Arquivo;
    case 1:
        Arquivo=fopen("mateus_castro.txt", "w");
        printf("Ler 4 números: \n");
        for (int i=1; i<5; i++){
                printf("Ler o [%d] número: ", i);
                scanf("%d", &n1);
                fprintf(Arquivo, "%d ", n1);
        }
        fclose(Arquivo);
    break;

    case 2:
        Arquivo=fopen("mateus_castro.txt", "r");
        fscanf(Arquivo, "%d %d %d %d", &n1, &n2, &n3, &n4);
        soma = n1+n2+n3+n4;
        printf("\nSoma é %d\n", soma);
        getch();
    break;

    case 3:
        exit(0);
    break;
    }
}
return 0;
}

