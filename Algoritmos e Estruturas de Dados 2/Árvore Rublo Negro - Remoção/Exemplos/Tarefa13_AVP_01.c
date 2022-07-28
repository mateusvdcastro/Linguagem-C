#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

struct node{
	int key;
	int color;
	struct node *parent;
	struct node *left;
	struct node *right;
};



struct node *ROOT;
struct node *NILL;
void red_black_transplant(struct node *u, struct node *v);
struct node *inicializa();
void left_rotate(struct node *x);
void right_rotate(struct node *x);
void red_black_insert(int key);
void red_black_insert_fixup(struct node *z);
struct node *tree_search(int key);
void rb_transplant(struct node *u, struct node *v);
struct node* tree_minimum(struct node *x);
void red_black_delete_fixup(struct node *x);
void escreverArvore(struct node *raizArvore);
void red_black_delete(struct node *z);

int altura(struct node *raizArvore){
    int alturaDireita, alturaEsquerda;

    if(raizArvore == NILL){
        return 0;
    }
    alturaEsquerda = altura(raizArvore->left);
    alturaDireita = altura(raizArvore->right);

    if(alturaEsquerda > alturaDireita){
        return (alturaEsquerda + 1);
    }
    else{
        return (alturaDireita + 1);
    }
}

int alturaVerm(struct node *no){
    int alturaDireita, alturaEsquerda, verm = 0;

    if(no == NILL){
        return 0;
    }
    if(no->color == RED){
        verm = 1;
    }
    alturaEsquerda = verm + alturaVerm(no->left);
    alturaDireita = verm + alturaVerm(no->right);

    if(alturaEsquerda > alturaDireita){
        return (alturaEsquerda);
    }
    else{
        return (alturaDireita);
    }
}

void verificaAltura(struct node *raizArvore){
    int max, min;

    //Altura da Arvore pelo filho esquerdo
    if(raizArvore->left != NILL){
        min = altura(raizArvore->left);
    }
    else{
        min = 0;
    }

    //Altura da Arvore pelo filho direito
    if(raizArvore->right != NILL){
        max = altura(raizArvore->right);
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

int main(){
    int numero; //Numero Digitado
    struct node *numDesejado;

    ROOT = inicializa();

    scanf("%d", &numero);
    while(numero != -1){
        if(tree_search(numero) == NILL){ //Verifica se o numero ja esta na arvore
            red_black_insert(numero);
           // escreverArvore(ROOT);
        }
        scanf("%d", &numero);
    }
    verificaAltura(ROOT);

    scanf("%d", &numero);
    while(numero != -1){
        numDesejado = tree_search(numero);
        if(numDesejado != NILL){
            verificaAltura(numDesejado);

            red_black_delete(numDesejado);
            //escreverArvore(ROOT);
        }
        else{
            red_black_insert(numero);
            //escreverArvore(ROOT);
        }
        scanf("%d", &numero);
    }

    scanf("%d", &numero);
    numDesejado = tree_search(numero);

    if(numDesejado == NILL){
        printf("Valor nao encontrado");
    }
    else{
        printf("%d", alturaVerm(numDesejado));
        }

    return 0;

}

struct node *tree_search(int key){
	struct node *x;

	x = ROOT;
	while(x != NILL && x->key != key){
		if(key < x->key){
			x = x->left;
		}
		else{
			x = x->right;
		}
	}

	return x;
}



void red_black_insert(int key){
	struct node *z, *x, *y;
	z = malloc(sizeof(struct node));

	z->key = key;
	z->color = RED;
	z->left = NILL;
	z->right = NILL;

	x = ROOT;
	y = NILL;

	while(x != NILL){
		y = x;
		if(z->key <= x->key){
			x = x->left;
		}
		else{
			x = x->right;
		}
	}

	if(y == NILL){
		ROOT = z;
	}
	else if(z->key <= y->key){
		y->left = z;
	}
	else{
		y->right = z;
	}

	z->parent = y;

	red_black_insert_fixup(z);
}

void red_black_insert_fixup(struct node *z){
	while(z->parent->color == RED){

		if(z->parent == z->parent->parent->left){

			if(z->parent->parent->right != NULL && z->parent->parent->right->color == RED){
				z->parent->color = BLACK;
				z->parent->parent->right->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}

			else{

				if(z == z->parent->right){
					z = z->parent;
					left_rotate(z);
				}

				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				right_rotate(z->parent->parent);
			}
		}

		else{

			if(z->parent->parent->left != NULL && z->parent->parent->left->color == RED){
				z->parent->color = BLACK;
				z->parent->parent->left->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}

			else{
				if(z == z->parent->left){
					z = z->parent;
					right_rotate(z);
				}

				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				left_rotate(z->parent->parent);
			}
		}
	}

	ROOT->color = BLACK;
}


void left_rotate(struct node *x){
	struct node *y;

	y = x->right;
	x->right = y->left;
	if(y->left != NILL){
		y->left->parent = x;
	}

	y->parent = x->parent;
	if(y->parent == NILL){
		ROOT = y;
	}
	else if(x == x->parent->left){
		x->parent->left = y;
	}
	else{
		x->parent->right = y;
	}

	y->left = x;
	x->parent = y;
}

void right_rotate(struct node *x){
	struct node *y;

	y = x->left;
	x->left = y->right;
	if(y->right != NILL){
		y->right->parent = x;
	}

	y->parent = x->parent;
	if(y->parent == NILL){
		ROOT = y;
	}
	else if(x == x->parent->left){
		x->parent->left = y;
	}
	else{
		x->parent->right = y;
	}

	y->right = x;
	x->parent = y;
}

void red_black_delete(struct node *z){
	struct node *y, *x;
	int yOriginalColor;

	y = z;
	yOriginalColor = y->color;

	if(z->left == NILL){
		x = z->right;
		red_black_transplant(z, z->right);
	}
	else if(z->right == NILL){
		x = z->left;
		red_black_transplant(z, z->left);
	}
	else{
		y = tree_minimum(z->right);
		yOriginalColor = y->color;

		x = y->right;

		if(y->parent == z){
			x->parent = y;
		}
		else{
			red_black_transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}

		red_black_transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}

	if(yOriginalColor == BLACK){
		red_black_delete_fixup(x);
	}
}

void red_black_delete_fixup(struct node *x){
	struct node *w;

	while(x != ROOT && x->color == BLACK){

		if(x == x->parent->left){
			w = x->parent->right;

			if(w->color == RED){
				w->color = BLACK;
				x->parent->color = RED;
				left_rotate(x->parent);
				w = x->parent->right;
			}

			if(w->left->color == BLACK && w->right->color == BLACK){
				w->color = RED;
				x->parent->color = BLACK;
				x = x->parent;
			}
			else{

				if(w->right->color == BLACK){
					w->color = RED;
					w->left->color = BLACK;
					right_rotate(w);
					w = x->parent->right;
				}

				w->color = x->parent->color;
				x->parent->color = BLACK;
				x->right->color = BLACK;
				left_rotate(x->parent);
				x = ROOT;

			}

		}
		else{
			w = x->parent->left;

			if(w->color == RED){
				w->color = BLACK;
				x->parent->color = BLACK;
				right_rotate(x->parent);
				w = x->parent->left;
			}

			if(w->left->color == BLACK && w->right->color == BLACK){
				w->color = RED;
				x->parent->color = BLACK;
				x = x->parent;
			}
			else{

				if(w->left->color == BLACK){
					w->color = RED;
					w->right->color = BLACK;
					left_rotate(w);
					w = x->parent->left;
				}

				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				right_rotate(x->parent);
				x = ROOT;

			}
		}

	}

	x->color = BLACK;
}

/* replace node u with node v */
void red_black_transplant(struct node *u, struct node *v){
	if(u->parent == NILL){
		ROOT = v;
	}
	else if(u == u->parent->left){
		u->parent->left = v;
	}
	else{
		u->parent->right = v;
	}

	v->parent = u->parent;
}
void escreverArvore(struct node *raizArvore){
    if (raizArvore != NILL){
        printf("(");
        printf("C%d", raizArvore->key);
        escreverArvore(raizArvore->left);
        escreverArvore(raizArvore->right);
        printf(")");
    }
    else{
        printf("()");
    }
}

struct node *inicializa(){
    NILL = malloc(sizeof(struct node));
	NILL->color = BLACK;
    NILL->parent = NULL;
    NILL->left = NULL;
    NILL->right = NULL;
    NILL->key = -1;
	return(NILL);

}

struct node *tree_minimum(struct node *x){
	while(x->left != NILL){
		x = x->left;
	}
	return x;
}
