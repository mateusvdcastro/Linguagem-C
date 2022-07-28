// Nome: Mateus Vespasiano de Castro
// RA: 159505
// Turma: IB

#include <stdio.h>
#include <stdlib.h>

enum COLOR {Red, Black};

// estrutura de um nó de uma árvore rublo negra
typedef struct tree_node {
  int data;
  struct tree_node *right;
  struct tree_node *left;
  struct tree_node *parent;
  enum COLOR color;
}tree_node;

typedef struct red_black_tree {
  tree_node *root;
  tree_node *NIL;
}red_black_tree;

/*
1 - Todo nó é rubro ou negro
2 - A raiz é negra
3 - Toda folha (NULL) é negra
4 - Se um nó é rubro, então ambos os seus filhos são negros
5 - Para cada nó, todos os caminhos desde um nó até as folhas descendestes
contêm o mesmo número de nós negros (BLACK-height)
*/

tree_node* new_tree_node(int data) {
    tree_node* n = malloc(sizeof(tree_node));
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    n->data = data;
    n->color = Red;
    return n;
}

red_black_tree* new_red_black_tree() {
    red_black_tree *t = malloc(sizeof(red_black_tree));
    tree_node *nil_node = malloc(sizeof(tree_node));
    nil_node->left = NULL;
    nil_node->right = NULL;
    nil_node->parent = NULL;
    nil_node->color = Black;
    nil_node->data = 0;
    t->NIL = nil_node;
    t->root = t->NIL;

    return t;
}

//A rotação para a esquerda “pivota” ao redor da ligação de x para y. 
//Transforma y na nova raiz da subárvore, com x como filho à esquerda de y e o 
//filho à esquerda de y como filho à direita de x.
// O pseudocódigo para LEFT-ROTATE supõe que x.direita ≠ T.nil e que o pai da raiz é T.nil.
// LEFT-ROTATE e RIGHT-ROTATE são executados no tempo O(1).
void left_rotate(red_black_tree *t, tree_node *x) {
    // ArvLLRB B = A->dir;
    // A->dir = B->esq;
    // B->esq = A;
    // B->cor = A->cor;
    // A->cor = RED;
    // return B;
    tree_node *y = x->right;

    x->right = y->left;
    if(y->left != t->NIL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == t->NIL) { 
        t->root = y;
    }
    else if(x == x->parent->left) { 
        x->parent->left = y;
    }
    else { 
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void right_rotate(red_black_tree *t, tree_node *x) {
    // ArvLLRB B = A->esq;
    // A->esq = B->dir;
    // B->dir = A;
    // B->cor = A->cor;
    // A->cor = RED;
    // return B;
    tree_node *y = x->left;

    x->left = y->right;

    if(y->right != t->NIL) {
        y->right->parent = x;
    }
        y->parent = x->parent;
    if(x->parent == t->NIL) { 
        t->root = y;
    }
    else if(x == x->parent->right) { 
        x->parent->right = y;
    }
    else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

// Colorimos z de vermelho na função insert. Visto que colorir z de vermelho pode causar uma violação de uma das propriedades vermelho-preto, chamamos RB-Insert-Fixup(T, z) para restaurar as propriedades vermelho-preto.
void insertion_fixup(red_black_tree *t, tree_node *z) {
  while(z->parent->color == Red) {
    if(z->parent == z->parent->parent->left) { 

      tree_node *y = z->parent->parent->right; 

      if(y->color == Red) { 
        z->parent->color = Black;
        y->color = Black;
        z->parent->parent->color = Red;
        z = z->parent->parent;
      }
      else { 
        if(z == z->parent->right) { 
          z = z->parent;
          left_rotate(t, z);
        }
        z->parent->color = Black; 
        z->parent->parent->color = Red;
        right_rotate(t, z->parent->parent);
      }
    }
    else { 
      tree_node *y = z->parent->parent->left; 

      if(y->color == Red) {
        z->parent->color = Black;
        y->color = Black;
        z->parent->parent->color = Red;
        z = z->parent->parent;
      }
      else {
        if(z == z->parent->left) {
          z = z->parent; 
          right_rotate(t, z);
        }
        z->parent->color = Black; 
        z->parent->parent->color = Red; 
        left_rotate(t, z->parent->parent);
      }
    }
  }
  t->root->color = Black;
}

//A chamada RB-INSERT(T, z) insere o nó z — cuja chave considera-se já ter sido inserida — na árvore vermelho-preto T.
//inserir um nó em uma árvore vermelho-preto de n nós no tempo O(lg n)
void insert(red_black_tree *t, tree_node *z) {
  tree_node* y = t->NIL; 
  tree_node* x = t->root;

  while(x != t->NIL) {
    y = x;
    if(z->data < x->data)
      x = x->left;
    else
      x = x->right;
  }
  z->parent = y;

  if(y == t->NIL) { 
    t->root = z;
  }
  else if(z->data < y->data) /// !!! No cormen y->data é x->data
    y->left = z;
  else
    y->right = z;

  z->right = t->NIL;
  z->left = t->NIL;
  //z->color = Red; /// !!! no cormen aqui é red (mas já colocamos red na função de criar o nó)

  insertion_fixup(t, z);
}

void rb_transplant(red_black_tree *t, tree_node *u, tree_node *v) {
  if(u->parent == t->NIL)
    t->root = v;
  else if(u == u->parent->left)
    u->parent->left = v;
  else
    u->parent->right = v;
  v->parent = u->parent;
}

tree_node* minimum(red_black_tree *t, tree_node *x) {
  while(x->left != t->NIL)
    x = x->left;
  return x;
}

void rb_delete_fixup(red_black_tree *t, tree_node *x) {
  while(x != t->root && x->color == Black) {
    if(x == x->parent->left) {
      tree_node *w = x->parent->right;
      if(w->color == Red) {
        w->color = Black;
        x->parent->color = Red;
        left_rotate(t, x->parent);
        w = x->parent->right;
      }
      if(w->left->color == Black && w->right->color == Black) {
        w->color = Red;
        x = x->parent;
      }
      else {
        if(w->right->color == Black) {
          w->left->color = Black;
          w->color = Red;
          right_rotate(t, w);
          w = x->parent->right;
        }
        w->color = x->parent->color; // !!! diferente do cormen
        x->parent->color = Black; // !!!
        w->right->color = Black;
        left_rotate(t, x->parent);
        x = t->root;
      }
    }
    else {
      tree_node *w = x->parent->left;
      if(w->color == Red) {
        w->color = Black;
        x->parent->color = Red;
        right_rotate(t, x->parent);
        w = x->parent->left;
      }
      if(w->right->color == Black && w->left->color == Black) {
        w->color = Red;
        x = x->parent;
      }
      else {
        if(w->left->color == Black) {
          w->right->color = Black;
          w->color = Red;
          left_rotate(t, w);
          w = x->parent->left;
        }
        w->color = x->parent->color; // !!!
        x->parent->color = Black; // !!!
        w->left->color = Black;
        right_rotate(t, x->parent);
        x = t->root;
      }
    }
  }
  x->color = Black;
}

/*
Quando queremos eliminar o nó z e z tem menos do que dois filhos, z é removido da árvore e queremos que y seja z. Quando z tem dois filhos, y deve ser o sucessor de z, e y passa para a posição de z na árvore. Também lembramos a cor de y antes de ele ser eliminado da árvore ou passar para dentro dela, e rastreamos o nó x que passa para a posição original de y na árvore porque o nó x também poderia causar violações das propriedades vermelho-preto. Após eliminar o nó z, RB-DELETE chama um procedimento auxiliar RB-DELETE-FIXUP, que muda as cores e executa rotações para restaurar as propriedades vermelho-preto.
*/
void rb_delete(red_black_tree *t, tree_node *z) {
    tree_node *y = z;
    tree_node *x;
    enum COLOR y_orignal_color = y->color;

    // while (t->root != t->NIL) {
    //   if (t->root->data == z->data) {
    //     z = t->root;
    //   }

    //   if (t->root->data <= z->data) {
    //     t->root = t->root->right;
    //   } else {
    //     t->root = t->root->left;
    //   }
    // }

    // if (z == t->NIL) {
    //   //cout << "Key not found in the tree" << endl;
    //   return;
    // }

    if(z->left == t->NIL) {
        x = z->right;
        rb_transplant(t, z, z->right);
    }
    else if(z->right == t->NIL) {
        x = z->left;
        rb_transplant(t, z, z->left);
    }
    else {
        y = minimum(t, z->right);
        y_orignal_color = y->color;
        x = y->right;
        if(y->parent == z) {
            x->parent = z;
        }
        else {
            rb_transplant(t, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        rb_transplant(t, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    free(z);  //!!! Retirei o free
    if(y_orignal_color == Black){
      rb_delete_fixup(t, x);
    }
}

// desaloca os nós da árvore da memória
void libera(red_black_tree* t, tree_node* a)
{
    if (a != NULL)
    {
        libera(a->left, t); /* libera sae */
        libera(a->right, t); /* libera sad */
        rb_delete(t, a);        /* libera raiz */
    }
    return;
}

int altura(red_black_tree *t, tree_node *z){
    int alturaDireita, alturaEsquerda;

    if(z == t->NIL){
        return 0;
    }
    alturaEsquerda = altura(t ,z->left);
    alturaDireita = altura(t, z->right);

    if(alturaEsquerda > alturaDireita){
        return (alturaEsquerda + 1);
    }
    else{
        return (alturaDireita + 1);
    }
}

int alturaVerm(red_black_tree *t, tree_node *z){
    int alturaDireita, alturaEsquerda, verm = 0;

    if(z == t->NIL){
        return 0;
    }
    if(z->color == Red){
        verm = 1;
    }
    alturaEsquerda = verm + alturaVerm(t, z->left);
    alturaDireita = verm + alturaVerm(t, z->right);

    if(alturaEsquerda > alturaDireita){
        return (alturaEsquerda);
    }
    else{
        return (alturaDireita);
    }
}

void verificaAltura(red_black_tree *t, tree_node *z){
    int max, min;

    //Altura da Arvore pelo filho esquerdo
    if(z->left != t->NIL){
        min = altura(t, z->left);
    }
    else{
        min = 0;
    }

    //Altura da Arvore pelo filho direito
    if(z->right != t->NIL){
        max = altura(t, z->right);
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

tree_node *tree_search(red_black_tree *t, int key){
	tree_node *x;

	x = t->root;
	while(x != t->NIL && x->data != key){
		if(key < x->data){
			x = x->left;
		}
		else{
			x = x->right;
		}
	}

	return x;
}

int main(){
    int numero; //Numero Digitado

    red_black_tree *t = new_red_black_tree();
    tree_node *numDesejado;

    scanf("%d", &numero);
    while(numero != -1){

        if(tree_search(t, numero) == t->NIL){ 

            insert(t, new_tree_node(numero));

        }
        scanf("%d", &numero);
    }
    verificaAltura(t, t->root);

    scanf("%d", &numero);
    while(numero != -1){
        numDesejado = tree_search(t, numero);
        if(numDesejado != t->NIL){
            verificaAltura(t, numDesejado);
            rb_delete(t, numDesejado);  
        }
        else{
            insert(t, new_tree_node(numero));
            
        }
        scanf("%d", &numero);
    }

    scanf("%d", &numero);
    numDesejado = tree_search(t, numero);

    if(numDesejado == t->NIL){
        printf("Valor nao encontrado");
    }
    else{
        printf("%d", alturaVerm(t, numDesejado));
    }

    // libera(t->NIL);
    // libera(t, t->root);

    return 0;
}
