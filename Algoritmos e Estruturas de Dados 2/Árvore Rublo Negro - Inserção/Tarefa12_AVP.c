//Eduardo Verissimo Faccio - 148859 - AED2
//Implementa��o Arvore Rubro Negra

//TAD de ABB utilizada com base na aula da UNIVESP
//Funcoes de Rotacoes e Balanceamento da Arvore foram baseadas do site Geeks for Geeks

#include <stdio.h>
#include <stdlib.h>

typedef struct auxNo{
    int numero;
    struct auxNo *esquerda, *direita, *pai;
    int cor; //Vermelho: 1, Preto: 0
}NO;

typedef NO* PONTEIRONO;

// imprime a árvore formatada, de melhor visualização
void imprimeT(PONTEIRONO p, int nivel)
{
    int i;

    if (p == NULL)
        return;

    imprimeT(p->esquerda, nivel + 1);

    for (i = 0; i < nivel; i++)
        printf("\t");

    printf("%3d\n", p->numero);

    imprimeT(p->direita, nivel + 1);
}

PONTEIRONO iniciarArvore();
PONTEIRONO novoNo(int num);
PONTEIRONO colocaNo(PONTEIRONO raizArvore , PONTEIRONO noArvore);
PONTEIRONO verifica(int num, PONTEIRONO raizArvore);
int altura(PONTEIRONO raizArvore);
int alturaNegra(PONTEIRONO raizArvore);
void verificaAltura(PONTEIRONO raizArvore);
void rotacaoEsq(PONTEIRONO temp);
void rotacaoDir(PONTEIRONO temp);
void arrumarPropriedades(PONTEIRONO raiz, PONTEIRONO pt);


//Variavel global para a arvore
PONTEIRONO arvoreBinaria;

int main(void){
    int numero; //Numero Digitado
    PONTEIRONO noCriado;
    arvoreBinaria = iniciarArvore();
    PONTEIRONO numDesejado;

    scanf("%d", &numero);
    while(numero != -1){
        if(verifica(numero, arvoreBinaria) == NULL){ //Verifica se o numero ja esta na arvore
            noCriado = novoNo(numero);
            arvoreBinaria = colocaNo(arvoreBinaria, noCriado);
            arrumarPropriedades(arvoreBinaria, noCriado);
        }
        scanf("%d", &numero);
    }

    imprimeT(arvoreBinaria, 0);

    verificaAltura(arvoreBinaria);

    scanf("%d", &numero);
    while(numero != -1){
        numDesejado = verifica(numero, arvoreBinaria);
        if(numDesejado != NULL){
            verificaAltura(numDesejado);
        }
        else{
            noCriado = novoNo(numero);
            arvoreBinaria = colocaNo(arvoreBinaria, noCriado);
            arrumarPropriedades(arvoreBinaria, noCriado);
        }
        scanf("%d", &numero);
    }

    scanf("%d", &numero);
    numDesejado = verifica(numero, arvoreBinaria);

    if(numDesejado == NULL){
        printf("Valor nao encontrado");
    }
    else{
        printf("%d", alturaNegra(numDesejado));
        }

    return 0;
}

PONTEIRONO iniciarArvore(){
    return(NULL);
}

PONTEIRONO novoNo(int num){
    PONTEIRONO newNo = (PONTEIRONO)malloc(sizeof(NO));
    newNo->esquerda = NULL;
    newNo->direita = NULL;
    newNo->numero = num;
    newNo->pai = NULL;
    newNo->cor = 1; //Adicionar sempre em cor vermelha
    return(newNo);
}

PONTEIRONO colocaNo(PONTEIRONO raizArvore , PONTEIRONO noArvore){
    if (raizArvore == NULL){
        return(noArvore);
    }
    if (noArvore->numero < raizArvore->numero){
        raizArvore->esquerda = colocaNo(raizArvore->esquerda, noArvore);
        raizArvore->esquerda->pai = raizArvore;
    }
    else if(noArvore->numero > raizArvore->numero){
        raizArvore->direita = colocaNo(raizArvore->direita, noArvore);
        raizArvore->direita->pai = raizArvore;
    }

    return(raizArvore);
}

PONTEIRONO verifica(int num, PONTEIRONO raizArvore){
    if (raizArvore == NULL){
        return(NULL);
    }
    if (raizArvore->numero == num) {
        return(raizArvore);
    }
    if (raizArvore->numero > num){
        return(verifica(num, raizArvore->esquerda));
    }
    return(verifica(num, raizArvore->direita));
}

int altura(PONTEIRONO raizArvore){
    int alturaDireita, alturaEsquerda;

    if(raizArvore == NULL){
        return 0;
    }
    alturaEsquerda = altura(raizArvore->esquerda);
    alturaDireita = altura(raizArvore->direita);

    if(alturaEsquerda > alturaDireita){
        return (alturaEsquerda + 1);
    }
    else{
        return (alturaDireita + 1);
    }
}

int alturaNegra(PONTEIRONO raizArvore){
    int alturaDireita, alturaEsquerda;

    if(raizArvore == NULL){
        return 0;
    }

    alturaEsquerda = alturaNegra(raizArvore->esquerda);
    alturaDireita = alturaNegra(raizArvore->direita);

    if(raizArvore->cor == 0){
        if(alturaEsquerda > alturaDireita){
            return (alturaEsquerda + 1);
        }
        else{
            return (alturaDireita + 1);
        }
    }
    else{
        if(alturaEsquerda > alturaDireita){
            return (alturaEsquerda);
        }
        else{
            return (alturaDireita);
        }
    }
}

void verificaAltura(PONTEIRONO raizArvore){
    int max, min;

    //Altura da Arvore pelo filho esquerdo
    if(raizArvore->esquerda != NULL){
        min = altura(raizArvore->esquerda);
    }
    else{
        min = 0;
    }

    //Altura da Arvore pelo filho direito
    if(raizArvore->direita != NULL){
        max = altura(raizArvore->direita);
    }
    else{
        max = 0;
    }

    //Verificacao da maior altura
    if(min > max){
        printf("%d, %d, %d\n", min, min, max);
    }
    else{
        printf("%d, %d, %d\n", max, min, max);
    }

}

void rotacaoEsq(PONTEIRONO no){
    PONTEIRONO noDir = no->direita;
    no->direita = noDir->esquerda;

    if(no->direita){
        no->direita->pai = no;
    }
    noDir->pai = no->pai;

    if(no->pai == NULL){
        arvoreBinaria = noDir;
    }
    else if(no == no->pai->esquerda){
        no->pai->esquerda = noDir;
    }
    else{
        no->pai->direita = noDir;
    }
    noDir->esquerda = no;
    no->pai = noDir;
}

void rotacaoDir(PONTEIRONO no){
    PONTEIRONO noEsq = no->esquerda;
    no->esquerda = noEsq->direita;

    if(no->esquerda){
        no->esquerda->pai = no;
    }
    noEsq->pai = no->pai;

    if(no->pai == NULL){
        arvoreBinaria = noEsq;
    }
    else if(no == no->pai->esquerda){
        no->pai->esquerda = noEsq;
    }
    else{
        no->pai->direita = noEsq;
    }
    noEsq->direita = no;
    no->pai = noEsq;
}

void arrumarPropriedades(PONTEIRONO raiz, PONTEIRONO no){
    PONTEIRONO paiNo = NULL;
    PONTEIRONO avoNo = NULL;

    while((no != raiz) && (no->cor != 0) && (no->pai->cor == 1)){
        paiNo = no->pai;
        avoNo = no->pai->pai;

        if(paiNo == avoNo->esquerda){
            PONTEIRONO tioNo = avoNo->direita;

            if((tioNo != NULL) && (tioNo->cor == 1)){
                avoNo->cor = 1;
                paiNo->cor = 0;
                tioNo->cor = 0;
                no = avoNo;
            }
            else{
                if(no == paiNo->direita){
                    rotacaoEsq(paiNo);
                    no = paiNo;
                    paiNo = no->pai;
                }

                rotacaoDir(avoNo);
                int aux = paiNo->cor;
                paiNo->cor = avoNo->cor;
                avoNo->cor = aux;
                no = paiNo;
            }
        }
        else{
            PONTEIRONO tioNo = avoNo->esquerda;

            if((tioNo != NULL) && (tioNo->cor == 1)){
                avoNo->cor = 1;
                paiNo->cor = 0;
                tioNo->cor = 0;
                no = avoNo;
            }
            else{
                if(no == paiNo->esquerda){
                    rotacaoDir(paiNo);
                    no = paiNo;
                    paiNo = no->pai;
                }

                rotacaoEsq(avoNo);
                int aux = paiNo->cor;
                paiNo->cor = avoNo->cor;
                avoNo->cor = aux;
                no = paiNo;
            }
        }
    }
    arvoreBinaria->cor = 0;
}
