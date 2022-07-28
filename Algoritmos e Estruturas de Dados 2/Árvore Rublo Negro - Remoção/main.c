
// Nome: Mateus Vespasiano de Castro
// RA: 159505
// Turma: IB
 
#include <stdio.h>
#include <stdlib.h>
 
#define RED 1
#define BLACK 0

// estrutura de um nó de uma árvore rublo negra
typedef struct arv
{
    int info;
    struct arv *esq;
    struct arv *dir;
    struct arv *pai;
    int cor;
} TArv;
typedef TArv *ArvLLRB;
 
typedef struct RED_BLACK_tree {
    ArvLLRB root;
    ArvLLRB NIL;
}RED_BLACK_tree;
typedef RED_BLACK_tree *REDBLACKTree;
 
/*
1 - Todo nó é rubro ou negro
2 - A raiz é negra
3 - Toda folha (NULL) é negra
4 - Se um nó é rubro, então ambos os seus filhos são negros
5 - Para cada nó, todos os caminhos desde um nó até as folhas descendestes
contêm o mesmo número de nós negros (BLACK-height)
*/

ArvLLRB cria(int num){
    ArvLLRB novo;
    novo = (ArvLLRB)malloc(sizeof(TArv));
  
    novo->info = num;
    novo->pai = novo->dir = novo->esq = NULL;
    novo->cor = RED;
    return novo;
}

REDBLACKTree new_RED_BLACK_tree(){
    
    REDBLACKTree t;

    t = (REDBLACKTree)malloc(sizeof(RED_BLACK_tree));
    
    ArvLLRB auxiliar;

    auxiliar = (ArvLLRB)malloc(sizeof(TArv));

	auxiliar->cor = BLACK;
    auxiliar->pai = NULL;
    auxiliar->esq = NULL;
    auxiliar->dir = NULL;
    auxiliar->info = 0;
    t->NIL = auxiliar;
    t->root = t->NIL;

	return t;
}
 
void rotacionaEsquerda(REDBLACKTree t ,ArvLLRB x)
{
    // ArvLLRB B = A->dir;
    // A->dir = B->esq;
    // B->esq = A;
    // B->cor = A->cor;
    // A->cor = RED;
    // return B;
 
    ArvLLRB y = x->dir;

    x->dir = y->esq;
 
    if(y->esq != t->NIL){
        y->esq->pai = x;
    }
    y->pai = x->pai;
 
    if(x->pai == t->NIL){
        t->root = y;
    }
    else if(x == x->pai->esq){
        x->pai->esq = y;
    }
    else{
        x->pai->dir = y;
    }
    y->esq = x;
    x->pai = y;
}
 
void rotacionaDireita(REDBLACKTree t ,ArvLLRB x)
{
    // ArvLLRB B = A->esq;
    // A->esq = B->dir;
    // B->dir = A;
    // B->cor = A->cor;
    // A->cor = RED;
    // return B;
  
    ArvLLRB y = x->esq;
    x->esq = y->dir;
 
    if(y->dir != t->NIL){
        y->dir->pai = x;
    }

    y->pai = x->pai;
 
    if(x->pai == t->NIL){
        t->root = y;
    }
    else if(x == x->pai->dir){
        x->pai->dir = y;
    }
    else{
        x->pai->esq = y;
    }
    y->dir = x;
    x->pai = y;
}

// imprime a árvore formatada, de melhor visualização
void imprimeT(ArvLLRB p, int nivel)
{
    int i;
 
    if (p == NULL)
        return;
 
    imprimeT(p->esq, nivel + 1);
 
    for (i = 0; i < nivel; i++)
        printf("\t");
 
    printf("%3d (%d)\n", p->info, p->cor);
 
    imprimeT(p->dir, nivel + 1);
}
 
// desaloca os nós da árvore da memória
void libera(ArvLLRB a)
{
    if (a != NULL)
    {
        libera(a->esq); /* libera sae */
        libera(a->dir); /* libera sad */
        free(a);        /* libera raiz */
    }
    return;
}
 
void BalenceiaParaInsercao(REDBLACKTree t, ArvLLRB z) {
    
    while(z->pai->cor == RED) {
        if(z->pai == z->pai->pai->esq) { 

            ArvLLRB y = z->pai->pai->dir; 

            if(y->cor == RED) { 
                z->pai->cor = BLACK;
                y->cor = BLACK;
                z->pai->pai->cor = RED;
                z = z->pai->pai;
            }
            else { 
                if(z == z->pai->dir) { 
                    z = z->pai;
                    rotacionaEsquerda(t, z);
                }
            
                z->pai->cor = BLACK; 
                z->pai->pai->cor = RED; 
                rotacionaDireita(t, z->pai->pai);
            }
        }
        else { 
            ArvLLRB y = z->pai->pai->esq; 

            if(y->cor == RED) {
                z->pai->cor = BLACK;
                y->cor = BLACK;
                z->pai->pai->cor = RED;
                z = z->pai->pai;
            }
            else {
                if(z == z->pai->esq) {
                    z = z->pai; 
                    rotacionaDireita(t, z);
                }
                z->pai->cor = BLACK;
                z->pai->pai->cor = RED; 
                rotacionaEsquerda(t, z->pai->pai);
            }
        }
        // if (z == t->root) {
        //     break;
        // }
    }
    t->root->cor = BLACK;
}

void InsereAVP(REDBLACKTree t, ArvLLRB z) {
    ArvLLRB y = t->NIL; 
    ArvLLRB temp = t->root;

    while(temp != t->NIL) {
        y = temp;
        if(z->info < temp->info)
            temp = temp->esq;
        else
            temp = temp->dir;
    }
    z->pai = y;

    if(y == t->NIL) { 
        t->root = z;
    }
    else if(z->info < y->info) 
        y->esq = z;
    else
        y->dir = z;

    z->dir = t->NIL;

    z->esq = t->NIL;

    BalenceiaParaInsercao(t, z);
}
 
int altura(REDBLACKTree t,ArvLLRB arv)
{
    if (arv == t->NIL)
    {
        return 0;
    }
    else
    {
        int alturaEsq = altura(t, arv->esq);
        int alturaDir = altura(t, arv->dir);
        if (alturaEsq > alturaDir)
        {
            return alturaEsq + 1;
        }
        else
        {
            return alturaDir + 1;
        }
    }
}

void verificaAltura(REDBLACKTree t,ArvLLRB raiz){
    int max, min;
 
    if(raiz->dir != t->NIL){
        max = altura(t, raiz->dir);
    }
    else{
        max = 0;
    }
 
    if(raiz->esq != t->NIL){
        min = altura(t, raiz->esq);
    }
    else{
        min = 0;
    }
 
    if(min > max){
        printf("%d, %d, %d\n", min, min, max);
    }
    else{
        printf("%d, %d, %d\n", max, min, max);
    }
 
}
 
// Faz o mesmo que a buscaAVP mas retorna o nó que contém o item desejado
ArvLLRB verifica(REDBLACKTree t,int n){
    ArvLLRB raizArvore; 

    raizArvore = t->root;

	while(raizArvore != t->NIL && raizArvore->info != n){
		if(n < raizArvore->info){
			raizArvore = raizArvore->esq;
		}
		else{
			raizArvore = raizArvore->dir;
		}
	}

	return raizArvore;
}
 
 
int alturaVermelha(REDBLACKTree t,ArvLLRB arv){
    int alturaDireita, alturaEsquerda;
 
    if(arv == t->NIL){
        return 0;
    }
 
    alturaEsquerda = alturaVermelha(t, arv->esq);
    alturaDireita = alturaVermelha(t, arv->dir);
 
    if(arv->cor == RED){
        if(alturaEsquerda > alturaDireita){
            return alturaEsquerda + 1;
        }
        else{
            return alturaDireita + 1;
        }
    }
    else{
        if(alturaEsquerda > alturaDireita){
            return alturaEsquerda;
        }
        else{
            return alturaDireita;
        }
    }
}

void swapNodes(REDBLACKTree t,ArvLLRB no1, ArvLLRB no2){
    if(no1->pai == t->NIL){
        t->root = no2;
    } else if (no1 == no1->pai->esq){
        no1->pai->esq = no2;
    } else {
        no1->pai->dir = no2;
    }

    no2->pai = no1->pai;
}

ArvLLRB menor_Arv(REDBLACKTree t ,ArvLLRB no){
    if (no->esq == t->NIL){
        return no;
    }
    while (no->esq != t->NIL){
        menor_Arv(t, no->esq);
    }
}

ArvLLRB minimum(REDBLACKTree t, ArvLLRB x) {
while(x->esq != t->NIL)
  x = x->esq;
return x;
}

void balanceiaParaDelecao(REDBLACKTree t,ArvLLRB x){
    ArvLLRB w;

    while (x != t->root && x->cor == BLACK){
        if (x == x->pai->esq){
            w = x->pai->dir;

            if (w->cor == RED){
                w->cor = BLACK;
                x->pai->cor = RED;
                rotacionaEsquerda(t, x->pai);
                w = x->pai->dir;
            }

            if (w->esq->cor == BLACK && w->dir->cor == BLACK){
                w->cor = RED;
                // no->pai->cor = BLACK;
                x = x->pai;
            } else {
                if (w->dir->cor == BLACK){
                    w->cor = RED;
                    w->esq->cor = BLACK;
                    rotacionaDireita(t, w);
                    w = x->pai->dir;
                }

                w->cor = x->pai->cor;
                x->pai->cor = BLACK;
                w->dir->cor = BLACK;
                rotacionaEsquerda(t, x->pai);
                x = t->root;
            }
        } else {
			ArvLLRB aux = x->pai->esq;
			if(aux->cor == RED){
				aux->cor = BLACK;
				x->pai->cor = RED;
				rotacionaDireita(t,x->pai);
				aux = x->pai->esq;
			}
			if(aux->dir->cor == BLACK && aux->esq->cor == BLACK){
				aux->cor = RED;
				// no->pai->cor = BLACK;
				x = x->pai;
			}
			else{

				if(aux->esq->cor == BLACK){
					aux->cor = RED;
					aux->dir->cor = BLACK;
					rotacionaEsquerda(t, aux);
					aux = x->pai->esq;
				}

				aux->cor = x->pai->cor;
				x->pai->cor = BLACK;
				aux->esq->cor = BLACK;
				rotacionaDireita(t, x->pai);
				x = t->root;
			}
        }
    }
    x->cor = BLACK;
}

void deletaNoAVP(REDBLACKTree t, ArvLLRB z){
    ArvLLRB y, x;
    int Aux1corOriginal;

    y = z;
    Aux1corOriginal = y->cor;

    if (z->esq == t->NIL){
        x = z->dir;
        swapNodes(t, z, z->dir);
    } else if (z->dir == t->NIL){
        x = z->esq;
        swapNodes(t, z, z->esq);
    } else {
        y = menor_Arv(t, z->dir);
        Aux1corOriginal = y->cor;

        x = y->dir;

        if (y->pai == z){
            x->pai = z;
        } else {
            swapNodes(t, y, y->dir);
            y->dir = z->dir;
            y->dir->pai = y;
        }

        swapNodes(t, z, y);
        y->esq = z->esq;
        y->esq->pai = y;
        y->cor = z->cor;
    }

    if (Aux1corOriginal == BLACK){
        balanceiaParaDelecao(t, x);
    }
    // free(z);
}

void rb_delete_fixup(REDBLACKTree t, ArvLLRB x) {
while(x != t->root && x->cor == BLACK) {
  if(x == x->pai->esq) {
    ArvLLRB w = x->pai->dir;
    if(w->cor == RED) {
      w->cor = BLACK;
      x->pai->cor = RED;
      esq_rotate(t, x->pai);
      w = x->pai->dir;
    }
    if(w->esq->cor == BLACK && w->dir->cor == BLACK) {
      w->cor = RED;
      x = x->pai;
    }
    else {
      if(w->dir->cor == BLACK) {
        w->esq->cor = BLACK;
        w->cor = RED;
        dir_rotate(t, w);
        w = x->pai->dir;
      }
      w->cor = x->pai->cor;
      x->pai->cor = BLACK;
      w->dir->cor = BLACK;
      esq_rotate(t, x->pai);
      x = t->root;
    }
  }
  else {
    ArvLLRB w = x->pai->esq;
    if(w->cor == RED) {
      w->cor = BLACK;
      x->pai->cor = RED;
      dir_rotate(t, x->pai);
      w = x->pai->esq;
    }
    if(w->dir->cor == BLACK && w->esq->cor == BLACK) {
      w->cor = RED;
      x = x->pai;
    }
    else {
      if(w->esq->cor == BLACK) {
        w->dir->cor = BLACK;
        w->cor = RED;
        esq_rotate(t, w);
        w = x->pai->esq;
      }
      w->cor = x->pai->cor;
      x->pai->cor = BLACK;
      w->esq->cor = BLACK;
      dir_rotate(t, x->pai);
      x = t->root;
    }
  }
}
x->cor = BLACK;
}

void rb_delete(REDBLACKTree t, ArvLLRB z) {
ArvLLRB y = z;
ArvLLRB x;
int y_orignal_cor = y->cor;
if(z->esq == t->NIL) {
  x = z->dir;
  swapNodes(t, z, z->dir);
}
else if(z->dir == t->NIL) {
  x = z->esq;
  swapNodes(t, z, z->esq);
}
else {
  y = menor_Arv(t, z->dir);
  y_orignal_cor = y->cor;
  x = y->dir;
  if(y->pai == z) {
    x->pai = z;
  }
  else {
    swapNodes(t, y, y->dir);
    y->dir = z->dir;
    y->dir->pai = y;
  }
  swapNodes(t, z, y);
  y->esq = z->esq;
  y->esq->pai = y;
  y->cor = z->cor;
}
if(y_orignal_cor == BLACK){
  rb_delete_fixup(t, x);
}
free(z);
}

int main()
{
    ArvLLRB n_pesquisar, n_pesquisar2;
    ArvLLRB no, no2;
 
    int n = 0, n2 = 0, n3 = 0;
    
    REDBLACKTree t = new_RED_BLACK_tree();

    scanf("%d", &n);
 
    while (n >= 0)
    {
        if (verifica(t, n) == t->NIL){
            no = cria(n);
            InsereAVP(t, no);
        }      
        scanf("%d", &n);
    }
 
    //imprimeT(arvore, 0);
 
    verificaAltura(t, t->root);
 
    scanf("%d", &n2);
 
    while (n2 >= 0)
    {
        n_pesquisar = verifica(t, n2);
       
        if (n_pesquisar != t->NIL)
        {
            // printf("Numero encontrado");
            verificaAltura(t, n_pesquisar);
            rb_delete(t, n_pesquisar);
        }
        else
        {
            // printf("O numero nao encontrado sera adicionado");
            no2 = cria(n2);
            InsereAVP(t, no2);
        }
        scanf("%d", &n2);
    }
  
    //imprimeT(arvore, 0);
  
    scanf("%d", &n3);

    n_pesquisar2 = verifica(t, n3);
 
    if (n_pesquisar2 == t->NIL)
    {
        printf("Valor nao encontrado");
    }
    else
    {
      printf("%d", alturaVermelha(t, n_pesquisar2));
    }
    //libera(t->root); // Desaloca a árvore da memória
 
    return 0;
}
