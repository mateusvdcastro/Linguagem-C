#include <stdio.h>
#include <locale.h>
#include <math.h> //Para usar as fun��es de cosseno.
#include <conio.h> //Para usar o getch().
#define _USE_MATH_DEFINES //Para usar o 'M_PI' (pi= 3,14....).

int main(void){
    setlocale(LC_ALL, "Portuguese_Brazil");

    FILE *pont_arq; //Ponteiro do arquivo q vai ser criado.
    pont_arq = fopen("engrenagem.txt", "w"); //Esse ponteiro cria o arquivo txt com a fun��o open.

    if (pont_arq == NULL){ //If para, caso o arquivo n�o consiga ser criado, encerrar o programa. Caso isso ocorra o ponteiro retorna 'NULL'.
        printf("N�o foi poss�vel criar um arquivos com os dados da engrenagem...");
        return 0;
    }


    int zint; //Vari�vel(em inteiro) do n�mero de dentes
    float m, z, alin, ap, apdivang,  wk, k, x, dmr, mdr, y; //Todas vari�veis que s�o as dimens�es da engrenagem.

    //Instru��es sobre o funcionamento da cria��o de arquivos.

    printf("\n\n **ESTE PROGRAMA CRIA UM ARQUIVO TXT COM AS DIMENS�ES DA ENGRENAGEM, JUNTAMENTE DE UM ARQUIVO BAT (ARQUIVO DE LOTES).**");
    printf("\n\nAPERTE ENTER.");

    getch();

    printf("\n\n\n\n**CASO QUEIRA SALVAR O ARQUIVO DE TEXTO, E/OU EXCLUIR (TANTO O ARQUIVO TXT QUANTO O BAT) PROCURE PELOS ARQUIVOS NA PASTA\nONDE EST� O ARQUIVO DO PROGRAMA.**");
    printf("\n\n\n    EXEMPLO: \n\n**CASO O ARQUIVO DO PROGRAMA ESTEJA NA PASTA DOWNLOADS, OU NA �REA DE TRABALHO, OU CASO VOC� TENHA COLOCADO O PROGRAMA\nEM UMA PASTA ESPEC�FICA, O ARQUIVO TXT E BAT ESTAR�O L�!**");
    printf("\n\n\nAPERTE ENTER.");

    getch();

    printf("\n\n\n\n**PROCURE PELOS ARQUIVOS 'engrenagem.txt' e 'engrenagem.bat'(ARQUIVO DE LOTES) E EXCLUA-OS.**");
    printf("\n\n\nAPERTE ENTER.");

    getch();

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");


    printf("      ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n      |||||||||||||                                                        |||||||||||||");
    printf("\n      |||||||||||||   Programa para calcular dimens�es de uma engrenagem   |||||||||||||");
    printf("\n      |||||||||||||                                                        |||||||||||||\n");
    printf("      ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");


    printf("\n\nQual o n�mero de dentes: ");
    scanf("%f", &z); //z = n�mero de dentes.

    zint = (int) z; /*z est� em float para utilizar nas opera��es matem�ticas. Por�m, � necess�rio transformar em int para
utilizar para saber se o n�mero de dentes � par ou impar (usando %, que s� funciona com var int).*/

    printf("\n\nQual o m�dulo: ");
    scanf("%f", &m); // m = m�dulo.

    printf("\n\nQual o �ngulo de press�o: ");
    scanf("%f", &ap); // ap = �ngulo de press�o.

    printf("\n\n");

    alin = m*(1+((z/2)*(1-cos((90*2*M_PI/360)/z)))); // alin = alinha(ou altura do dente corrigida).

    x = m*z*sin((90*2*M_PI/360)/z); // x = espessura cordal.

    if(ap == 20.0f){ // IF para saber qual o �ngulo de press�o e assim qual f�rmula usar.
        apdivang = 20.0f/180.0f; // apdivang = �ngulo de press�o dividido pelo �ngulo (na f�rmula � sempre 180�).
    } else if (ap == 15.0f){
        apdivang = 15.0f/180.0f;
    } else {
        apdivang = 14.5f/180.0f;
    }

    k = round((z*(apdivang))+0.5); // k = n�mero min�mo de dentes que ser� medido. Deve se usar o valor arredondado.

    if(ap == 20.0f){ // IF para saber qual �ngulo de press�o...
        wk = m*(((2.952131*k)-1.476066)+(0.014904*z)); //wk = Dist�ncia entre os dentes 'k'.
    } else if (ap == 15){
        wk = m*(((3.034545*k)-1.517273)+(0.006150*z));
    } else {
        wk = m*(((3.041526*k)-1.520763)+(0.005545*z));
    }

    dmr = 1.728*m; // dmr = di�metro do cilindro calibrado usado para medir a engrenagem.

    if (zint%2==0){ // IF para saber se o n�mero de dentes � par ou �mpar.
        if(ap == 20.0f){ // �ngulos de press�o...
            y = z*cos(20*2*M_PI/360)/cos((20+90/z)*2*M_PI/360); // y = di�metro da engrenagem com os cilindros.
        } else if (ap == 15.0f){
            y = z*cos(15*2*M_PI/360)/cos((15+90/z)*2*M_PI/360);
        } else {
            y = z*cos(14.5*2*M_PI/360)/cos((14.5+90/z)*2*M_PI/360);
        }

    } else {
        if(ap == 20.0f){ //�ngulos de press�o...
            y = z*cos(20*2*M_PI/360)/cos((20+90/z)*2*M_PI/360)*(cos((90/z)*2*M_PI/360)); //y = di�metro da engrenagem com os cilindros.
        } else if (ap == 15.0f){
            y = z*cos(15*2*M_PI/360)/cos((15+90/z)*2*M_PI/360)*(cos((90/z)*2*M_PI/360));
        } else {
            y = z*cos(14.5*2*M_PI/360)/cos((14.5+90/z)*2*M_PI/360)*(cos((90/z)*2*M_PI/360));
        }
    }

    mdr = (m*y)+dmr; // mdr = di�metro primitivo.

    printf("  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    fprintf(pont_arq,"  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");

    printf("\n  ||||||||||||||||||||||||||                ||||||||||||||||||||||||||||||");
    fprintf(pont_arq, "\n  ||||||||||||||||||||||||||                ||||||||||||||||||||||||||||||");

    printf("\n  ||||||||||||||||||||||||||    Dimens�es   ||||||||||||||||||||||||||||||");
    fprintf(pont_arq, "\n  ||||||||||||||||||||||||||    Dimens�es   ||||||||||||||||||||||||||||||");

    printf("\n  ||||||||||||||||||||||||||                ||||||||||||||||||||||||||||||\n");
    fprintf(pont_arq, "\n  ||||||||||||||||||||||||||                ||||||||||||||||||||||||||||||\n");

    printf("  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    fprintf(pont_arq, "  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");


    printf("\n---> N�mero de dentres da engrenagem: %d", zint);
    fprintf(pont_arq, "\n---> N�mero de dentres da engrenagem: %d", zint);



    printf("\n\n---> M�dulo: %.0f", m);
    fprintf(pont_arq, "\n\n---> M�dulo: %.0f", m);



    printf("\n\n---> �ngulo de press�o: %.1f", ap);
    fprintf(pont_arq, "\n\n---> �ngulo de press�o: %.1f", ap);



    printf("\n\n---> Altura do dente corrigida(a'): %.3f", alin);
    fprintf(pont_arq, "\n\n---> Altura do dente corrigida(a'): %.3f", alin);



    printf("\n\n---> Espessura cordal(X): %.3f", x);
    fprintf(pont_arq, "\n\n---> Espessura cordal(X): %.3f", x);



    printf("\n\n---> N�mero m�nimo de dentes(K): %.0f", k);
    fprintf(pont_arq, "\n\n---> N�mero m�nimo de dentes(K): %.0f", k);



    printf("\n\n---> Dist�ncia entre os dentes(Wk): %.3f", wk);
    fprintf(pont_arq, "\n\n---> Dist�ncia entre os dentes(Wk): %.3f", wk);




    printf("\n\n---> Di�metro te�rico do cilindro calibrado(DMR): %.3f", dmr);
    fprintf(pont_arq, "\n\n---> Di�metro te�rico do cilindro calibrado(DMR): %.3f", dmr);




    printf("\n\n---> Di�metro da engrenagem com os cilindros(Y): %.3f", y);
    fprintf(pont_arq, "\n\n---> Di�metro da engrenagem com os cilindros(Y): %.3f", y);



    printf("\n\n---> Di�metro primitivo efetivo(MDR): %.3f\n\n", mdr);
    fprintf(pont_arq, "\n\n---> Di�metro primitivo efetivo(MDR): %.3f\n\n", mdr);


    fclose(pont_arq); //Fecha o arquivo txt.



    FILE *p_arq; //Ponteiro do arquivo.
    p_arq = fopen("engrenagem.bat", "w"); //ABre um arquivo .bat, que vai ter a fun��o de abrir o arquivo txt criado antes.

    fprintf(p_arq, "start engrenagem.txt"); //O que vai ser escrito no .bat, que ser� o que ele executar�.

    fclose(p_arq); //Fecha o arquivo .bat.



    system("engrenagem.bat"); //Abre o arquivo .bat e roda ele, fazendo que o txt seja aberto.


    getch();

    return 0;
}
