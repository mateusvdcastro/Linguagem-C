#include <stdio.h>
#include <locale.h>

main(){
    setlocale (LC_ALL,"");
    int num=8;
    int numerox;
    while(num!=0){
        system("cls");
        printf("\n--> Digite um número entre 1 e 7: ");
        scanf("%d", &num);
        switch (num){
            case 1:
                printf("  Domingo\n");
                system("pause");
                break;
            case 2:
                printf("  Segunda\n");
                system("pause");
                break;
            case 3:
                printf("  Terça\n");
                system("pause");
                break;
            case 4:
                printf("  Quarta\n");
                system("pause");
                break;
            case 5:
                printf("  Quinta\n");
                system("pause");
                break;
            case 6:
                printf("  Sexta\n");
                system("pause");
                break;
            case 7:
                printf("  Sábado\n");
                system("pause");
                break;
            case 8:
                printf("\n--> Digite um número para exibir sua tabuada: ");
                scanf("%d", &numerox);
                for(int x=1; x<=10; x++)
                    printf("\n %d X %d = %d\n" , x, numerox, x*numerox);
                system("pause");
                break;
            case 0:
                exit(0);
            default:
                printf("  Numero fora do solicitado, não existe dia com este valor...\n");
                system("pause");
        }
    }
    return(0);
}
