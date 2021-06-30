#include <stdio.h>
main(){
    float media;
    printf("Informe a media: ");
    scanf("%f", &media);
    if(media>=7){
        printf("Aprovado");
        printf("\nAprovado com media %f", media);
    }
    else{
        if(media>=4)
            printf("Final");
        else
            printf("Reprovado");
    return(0);
    }
printf("\nFinalizado");
}

