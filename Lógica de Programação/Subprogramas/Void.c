#include <stdio.h>
#include <locale.h>

void estado_aluno(float mf){
    if (mf>=6){
        printf("\nAluno aprovado!\n");
    }else{
        if(mf>=4.0){
            printf("\nAluno de Exame\n");
        }else{
            printf("\nAluno Reprovado!\n");
        }
    }
}

int main(){
setlocale(LC_ALL, "");
float media;
printf("Escreva a média do aluno: ");
scanf("%f", &media);
estado_aluno(media);
return (0);
}
