#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char palavrasecreta[20];
char chutes[26]; // 26 letras do alfabeto, se ele chutar 26 vezes ele acerta
int chutesdados = 0; // quantidade de chutes que ele já deu

// lista de funções que aparecerão no arquivo
int enforcou();
void abertura();
void chuta();
int jachutou(char letra);
int ganhou();
void desenhaforca();
void escolhepalavra();


void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta() {
    // queremos recuperar a variável tentativas na main, por isso passamos ela
    // como ponteiro
    // chutes é um array e arrays são ponteiros por natureza, então não passamos
    // o endereço como parâmetro da função
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute); // espaço para que o scanf ignore o enter

    chutes[chutesdados] = chute; 
    chutesdados++; 
}

int jachutou(char letra) {
    int achou = 0;
    for(int j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) {// se no nosso vetor de chutes houver uma letra
            achou = 1; // de igual ocorrência na palavra secreta, ele retorna achou,
            // significa que essa letra já foi chutada
            break;
        }
    }

    return achou;
}

void desenhaforca() {

    printf("Voce ja deu %d chutes\n", chutesdados);

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

// Retorna a quantidade de letras chutadas que não existem na palavra
int enforca() {

    int erros = 0;

    // loop em todos os chutes dados
    for(int i = 0; i < chutesdados; i++) {

        int existe = 0;

        // agora vamos olhar letra a letra da palavra secreta
        // e ver se encontramos o chute aqui
        for(int j = 0; j < strlen(palavrasecreta); j++) {
            if(chutes[i] == palavrasecreta[j]) {

                // encontramos, vamos quebrar o loop
                existe = 1;
                break;
            }
        }

        // se nao encontrou, soma um na quantidade de erros
        if(!existe) erros++;
    }

    // se tivermos mais do que 5 erros, retornamos 1
    // caso contrario, retornamos 0.
    return erros >= 5;
}

// Você ganha se chutar todas as letras da palavra
int ganhou() {
    for(int i = 0; i < strlen(palavrasecreta); i++) {
        if(!jachutou(palavrasecreta[i])) {
            return 0; // Se ele não chutou retorna 0 de false (não ganhou)
        }
    }

    return 1; // Se ele chutou todas retorna 1 de true (ganhou)
}

void escolhepalavra() {
    FILE* f;

    f = fopen("palavras.txt", "r");
    if(f == 0) {
        printf("Banco de dados de palavras nao disponivel\n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras; // numeros aleatorios de 0 a qtddepalavras

    for(int i = 0; i <= randomico; i++) { // lê o arquivo até chegar na linha que randomizamos
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

int main() {

    int acertou = 0;
    int enforcou = 0;


    abertura();
    escolhepalavra();

    do// do while executa todo o bloco de código na primeira iteração antes de
    // verificar a condição do while. 
    {

        desenhaforca();
        chuta();

        enforcou = enforca();
        acertou = ganhou();

    } while (!acertou && !enforcou); // O jogo não acaba enquanto
    // não acertar a palavra ou enquanto não enforca

if(ganhou()) {
        printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

    } else {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavrasecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }

}
