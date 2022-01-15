#include <stdio.h>
#include <locale.h>

float calcule_media(float nota1, float nota2, float nota3, float nota4, float nota5){
float mediafinal;
mediafinal=(nota1+nota2+nota3+nota4+nota5)/5;
return(mediafinal);
}

//Procedimento
void aprovacao_aluno(float mfinal){
if (mfinal>=7.0){
    printf("\nAprovado por Nota\n");
}else{
    if (mfinal > 4.0){
        printf("\nAluno em Exame de Suficiência\n");
    }else{
        printf("\nAluno Reprovado por Nota!\n");
    }
 }
}

int main(){
    setlocale(LC_ALL, "");
    float notay1, notay2, notay3,notay4, notay5, med;
    printf("Insira a Nota 1 do aluno: ");
    scanf("%f", &notay1);
    printf("\nInsira a Nota 2 do aluno: ");
    scanf("%f", &notay2);
    printf("\nInsira a Nota 3 do aluno: ");
    scanf("%f", &notay3);
    printf("\nInsira a Nota 4 do aluno: ");
    scanf("%f", &notay4);
    printf("\nInsira a Nota 5 do aluno: ");
    scanf("%f", &notay5);
    med = calcule_media(notay1, notay2, notay3, notay4, notay5);
    aprovacao_aluno(med);
    return (0);
}
