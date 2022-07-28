/*
Nome:Juan Marcos Martins;
RA:156.470;
Turma: IA, Alvaro;
*/
 
#include <stdio.h>
#include <stdlib.h>

#define VERMELHO 1
#define PRETO 0
 
typedef struct no{
    int valor, altura, cor;
	struct no *esq, *dir, *pai;
}No;

typedef No *pno;
 
//Declaracao das funcoes utilizadas;
 
pno inserir(pno raizArvore , pno noArvore);
void imprimir(pno a, int nivel);
int busca(pno raiz, int numbuscado);
int busca2(pno raiz, int numbuscado);
pno buscanegra(pno raiz, int numbuscado);
int altura(pno no);
int altneg(pno raizArvore);
pno Novono(int chave);
void Esq(pno r);
void Dir(pno r);
pno libera(pno raiz);
void balancear(pno root, pno pt);

pno aux; //Variavel global para montar a arvore;
 
//----------------------------------------------------------------------------
int main(){
    int numinseridos = 0;
    int pesquisa = 0, valordabusca, alt;
    int alturabuscada, alt1, alt2, alt3;
    pno criado;
    pno raiz = NULL;
    pno auxdoaux;
  
    scanf("%d", &numinseridos); //Inserir valores na arvore;
    while(numinseridos >= 0){
        criado = Novono(numinseridos);
        aux = inserir(aux, criado); //Passa a arvore para inserir os novos valores;
        balancear(aux, criado);
        scanf("%d", &numinseridos);
    }
  
    alt1 = altura(aux)-1;
    alt2 = altura(aux->esq);
    alt3 = altura(aux->dir);
 
    printf("%d, %d, %d\n", alt1, alt2, alt3); //Printa os valores das alturas da primeira arvore;


    scanf("%d", &pesquisa); //Pega a segunda linha para adicionar ou excluir os valores;
    while(pesquisa >= 0){
 
        valordabusca = busca(aux, pesquisa); //A variavel recebe 1 caso tenha q inserir e -2 caso tenha que remover;
        
        if(valordabusca == 1){
            criado = Novono(pesquisa);
            aux = inserir(aux, criado); //Passa a arvore para inserir os novos valores;
            balancear(aux, criado);
        }
        else if(valordabusca == -2){ //Encontrou na arvore;
            busca2(aux, pesquisa);
             //Vai remover o valor passado;
        }
        scanf("%d", &pesquisa);
    }
 
    scanf("%d", &alt); //Valor buscado na arvore;
    
    int valordabusca2 = busca(aux, alt); //Recebe um retorno int para verificar se possui o valor;
    
    if(valordabusca2 == 1){
        printf("Valor nao encontrado"); //Caso nao encontre o numero buscado
    }
    else{
        auxdoaux = buscanegra(aux, alt);
        int valor = altneg(auxdoaux);
        printf("%d", valor); //Mostra o valor da atltura negra;
    }//Chama a funcao para printar a ultima linha mostrando as alturas da arvore depois de arrumada;
 
    libera(aux); //Libera os espacos alocados;
    libera(auxdoaux);
    libera(criado);
    libera(raiz);
 
    return 0;
}
//----------------------------------------------------------------------------
pno inserir(pno raiz , pno no){ //Funcao para inserir os valores em cada no;
    if (raiz == NULL){
        return(no); //Raiz vazia;
    }
    if (no->valor < raiz->valor){
        raiz->esq = inserir(raiz->esq, no);
        raiz->esq->pai = raiz;
    }
    else if(no->valor > raiz->valor){
        raiz->dir = inserir(raiz->dir, no);
        raiz->dir->pai = raiz;
    }

    return(raiz); //Retorna a raiz com os valores ja inseridos;
}
//----------------------------------------------------------------------------
pno Novono(int chave){ //Funcao para criar novo no;
    pno novo = (pno)malloc(sizeof(No));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->valor = chave;
    novo->pai = NULL;
    novo->cor = VERMELHO; //Adicionar sempre em cor vermelha;
    return(novo); //Retorna a arvore;
}
//----------------------------------------------------------------------------
void imprimir(pno a, int nivel){ //Funcao para testar, imprimindo a arvore;
    int i;
    if (a != NULL){
        imprimir(a->dir, nivel + 1);
        for (i = 0; i < nivel; i++){
            printf("\t");
        }
        printf("%d\n", a->valor);
        imprimir(a->esq, nivel + 1);
    }
}
//----------------------------------------------------------------------------
int busca(pno raiz, int numbuscado){ //Funcao para Buscar os valores e verificar o que fazer com eles, inserir ou remover;
 
    if (raiz == NULL){
        return 1; //Nao tem arvore, entao vai inserir o valor;
    }
    else if(numbuscado < raiz->valor){ //Busca os menores a esquerda;
        busca(raiz->esq, numbuscado); //Recursao para continuar buscando;
    }
    else if(numbuscado > raiz->valor){ //Busca os maiores para a direita;
        busca(raiz->dir, numbuscado); //Recursao para continuar buscando;
    }
    else if(numbuscado == raiz->valor){
        return -2; //Encontrou o valor na arvore, entao vai remover o valor;
    }
}
//----------------------------------------------------------------------------
int busca2(pno raiz, int numbuscado){ //Funcao para Buscar os valores e verificar o que fazer com eles, inserir ou remover;
    //printf("entra aqui");
    if(numbuscado < raiz->valor){ //Busca os menores a esquerda;
        busca2(raiz->esq, numbuscado); //Recursao para continuar buscando;
    }
    else if(numbuscado > raiz->valor){ //Busca os maiores para a direita;
        busca2(raiz->dir, numbuscado); //Recursao para continuar buscando;
    }
    else if(numbuscado == raiz->valor){ //Encontrou o valor e ja printa a altura do no encontrado;
        int alt4 = altura(raiz)-1;
        int alt5 = altura(raiz->esq);
        int alt6 = altura(raiz->dir);
 
        printf("%d, %d, %d\n", alt4, alt5, alt6); //Encontrou o valor na arvore, entao vai remover o valor;
    }
}
//----------------------------------------------------------------------------
pno buscanegra(pno raiz, int numbuscado){ //Funcao para Buscar os valores e verificar o que fazer com eles, inserir ou remover;
 
    if(numbuscado < raiz->valor){ //Busca os menores a esquerda;
        return (buscanegra(raiz->esq, numbuscado)); //Recursao para continuar buscando;
    }
    else if(numbuscado > raiz->valor){ //Busca os maiores para a direita;
        return (buscanegra(raiz->dir, numbuscado)); //Recursao para continuar buscando;
    }
    else if(numbuscado == raiz->valor){
        return raiz; //Encontrou o valor na arvore, entao vai retornar o valor;
    }
}
//----------------------------------------------------------------------------
int altura(pno altno){ //Funcao para encontrar o tamanho dos nos;
    
    int altDir, altEsq;

    if(altno == NULL){ //Arvore no no, e vazia;
        return PRETO;
    }
    altEsq = altura(altno->esq); //A altura para a esquerda recebe, chamando recursivamente
    altDir = altura(altno->dir); //A altura para a direita recebe, chamndo recursivamente;

    if(altEsq > altDir){
        return (altEsq + VERMELHO); //Retorna o valor da altura da esquerda mais 1;
    }
    else{
        return (altDir + VERMELHO); //Retorna o valor da altura da direita mais 1;
    }
}
//----------------------------------------------------------------------------
int altneg(pno raiz){ //Funcao para retornar a altura do no negro;
    int altDir, altEsq;

    if(raiz == NULL){
        return PRETO;
    }

    altEsq= altneg(raiz->esq);
    altDir= altneg(raiz->dir);

    if(raiz->cor == PRETO){
        if(altEsq > altDir){
            return (altEsq + VERMELHO);
        }
        else{
            return (altDir + VERMELHO);
        }
    }
    else{
        if(altEsq > altDir){
            return (altEsq);
        }
        else{
            return (altDir);
        }
    }
}
//----------------------------------------------------------------------------

void Esq(pno no){ //Funcao para fazer a rotacao a esquerda;
    pno noDir = no->dir;
    no->dir = noDir->esq;
    
    if(no->dir){
        no->dir->pai = no;
    }
    noDir->pai = no->pai;

    if(no->pai == NULL){
        aux = noDir;
    }
    else if(no == no->pai->esq){
        no->pai->esq = noDir;
    }
    else{
        no->pai->dir = noDir;
    }
    noDir->esq = no;
    no->pai = noDir;
    
}
//----------------------------------------------------------------------------
void Dir(pno no){ //Funcao para fazer a rotacao a direita;
    pno noEsq = no->esq;
    no->esq = noEsq->dir;

    if(no->esq){
        no->esq->pai = no;
    }
    noEsq->pai = no->pai;

    if(no->pai == NULL){
        aux = noEsq;
    }
    else if(no == no->pai->esq){
        no->pai->esq = noEsq;
    }
    else{
        no->pai->dir = noEsq;
    }
    noEsq->dir = no;
    no->pai = noEsq;

}
//----------------------------------------------------------------------------
void balancear(pno raiz, pno raizraiz){
	pno pairaiz = NULL;
	pno avoraiz = NULL;

	while ((raizraiz != raiz) && (raizraiz->cor != PRETO) && (raizraiz->pai->cor == VERMELHO)){
		pairaiz = raizraiz->pai;
		avoraiz = raizraiz->pai->pai;
		
		if (pairaiz == avoraiz->esq){
			pno tioraiz = avoraiz->dir;
			if (tioraiz != NULL && tioraiz->cor == VERMELHO){
				avoraiz->cor = VERMELHO;
				pairaiz->cor = PRETO;
				tioraiz->cor = PRETO;
				raizraiz = avoraiz;
			}
			else{
				if (raizraiz == pairaiz->dir) {
					Esq(pairaiz);
					raizraiz = pairaiz;
					pairaiz = raizraiz->pai;
				}
				Dir(avoraiz);
				int t = pairaiz->cor;
				pairaiz->cor = avoraiz->cor;
				avoraiz->cor = t;
				raizraiz = pairaiz;
			}
		}
		else{
			pno tioraiz = avoraiz->esq;
			if ((tioraiz != NULL) && (tioraiz->cor == VERMELHO)){
				avoraiz->cor = VERMELHO;
				pairaiz->cor = PRETO;
				tioraiz->cor = PRETO;
				raizraiz = avoraiz;
			}
			else{
				if (raizraiz == pairaiz->esq){
					Dir(pairaiz);
					raizraiz = pairaiz;
					pairaiz = raizraiz->pai;
				}
				Esq(avoraiz);
				int t = pairaiz->cor;
				pairaiz->cor = avoraiz->cor;
				avoraiz->cor = t;
				raizraiz = pairaiz;
			}
		}
	}

	aux->cor = PRETO;
}
//----------------------------------------------------------------------------
pno libera(pno raiz){ //Funcao recursiva para liberar todos os nos da arvore, dada em aula;
    if(raiz != NULL){ //Enquanto a variavel nao for vazia;
        libera(raiz->esq); //Funcao recursiva que vai entrando em nos da esquerda;
        libera(raiz->dir); //Funcao recursiva que vai entrand em nos da direira;
        free(raiz); //Enquanto houver nos na direita ou na esquerda, vai liberando;
    }
    return NULL;
}
