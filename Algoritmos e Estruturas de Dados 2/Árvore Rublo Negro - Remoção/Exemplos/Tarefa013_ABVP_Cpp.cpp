/*
Tarefa 13 - Arvore Binaria Rubro Negra

TAD de autoria do site abaixo:
Site: https://www.programiz.com/dsa/red-black-tree

*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Node {
  int data;
  Node *parent;
  Node *left;
  Node *right;
  int color;
};

typedef Node *NodePtr;

class RedBlackTree {
  private:
  NodePtr root;
  NodePtr TNULL;

  void initializeNULLNode(NodePtr node, NodePtr parent) {
    node->data = 0;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
    node->color = 0;
  }

  NodePtr searchTreeHelper(NodePtr node, int key) {
    if (node == TNULL || key == node->data) {
      return node;
    }

    if (key < node->data) {
      return searchTreeHelper(node->left, key);
    }
    return searchTreeHelper(node->right, key);
  }

  void deleteFix(NodePtr x) {
    NodePtr s;
    while (x != root && x->color == 0) {
      if (x == x->parent->left) {
        s = x->parent->right;
        if (s->color == 1) {
          s->color = 0;
          x->parent->color = 1;
          leftRotate(x->parent);
          s = x->parent->right;
        }

        if (s->left->color == 0 && s->right->color == 0) {
          s->color = 1;
          x = x->parent;
        } else {
          if (s->right->color == 0) {
            s->left->color = 0;
            s->color = 1;
            rightRotate(s);
            s = x->parent->right;
          }

          s->color = x->parent->color;
          x->parent->color = 0;
          s->right->color = 0;
          leftRotate(x->parent);
          x = root;
        }
      } else {
        s = x->parent->left;
        if (s->color == 1) {
          s->color = 0;
          x->parent->color = 1;
          rightRotate(x->parent);
          s = x->parent->left;
        }

        if (s->right->color == 0 && s->right->color == 0) {
          s->color = 1;
          x = x->parent;
        } else {
          if (s->left->color == 0) {
            s->right->color = 0;
            s->color = 1;
            leftRotate(s);
            s = x->parent->left;
          }

          s->color = x->parent->color;
          x->parent->color = 0;
          s->left->color = 0;
          rightRotate(x->parent);
          x = root;
        }
      }
    }
    x->color = 0;
  }

  void rbTransplant(NodePtr u, NodePtr v) {
    if (u->parent == NULL) {
      root = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    v->parent = u->parent;
  }

  void deleteNodeHelper(NodePtr node, int key) {
    NodePtr z = TNULL;
    NodePtr x, y;
    while (node != TNULL) {
      if (node->data == key) {
        z = node;
      }

      if (node->data <= key) {
        node = node->right;
      } else {
        node = node->left;
      }
    }

    if (z == TNULL) {
      //cout << "Key not found in the tree" << endl;
      return;
    }

    y = z;
    int y_original_color = y->color;
    if (z->left == TNULL) {
      x = z->right;
      rbTransplant(z, z->right);
    } else if (z->right == TNULL) {
      x = z->left;
      rbTransplant(z, z->left);
    } else {
      y = minimum(z->right);
      y_original_color = y->color;
      x = y->right;
      if (y->parent == z) {
        x->parent = y;
      } else {
        rbTransplant(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }

      rbTransplant(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }
    delete z;
    if (y_original_color == 0) {
      deleteFix(x);
    }
  }

  void insertFix(NodePtr k) {
    NodePtr u;
    while (k->parent->color == 1) {
      if (k->parent == k->parent->parent->right) {
        u = k->parent->parent->left;
        if (u->color == 1) {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->left) {
            k = k->parent;
            rightRotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          leftRotate(k->parent->parent);
        }
      } else {
        u = k->parent->parent->right;

        if (u->color == 1) {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->right) {
            k = k->parent;
            leftRotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          rightRotate(k->parent->parent);
        }
      }
      if (k == root) {
        break;
      }
    }
    root->color = 0;
  }


  int alturaVerm(NodePtr no){
    int alturaDireita, alturaEsquerda, verm = 0;

    if(no == TNULL){
        return 0;
    }
    if(no->color == 1){
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
   public:
  RedBlackTree() {
    TNULL = new Node;
    TNULL->color = 0;
    TNULL->left = NULL;
    TNULL->right = NULL;
    root = TNULL;
  }

  NodePtr searchTree(int k) {
    return searchTreeHelper(this->root, k);
  }

  NodePtr minimum(NodePtr node) {
    while (node->left != TNULL) {
      node = node->left;
    }
    return node;
  }

  void leftRotate(NodePtr x) {
    NodePtr y = x->right;
    x->right = y->left;
    if (y->left != TNULL) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
      this->root = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }

  void rightRotate(NodePtr x) {
    NodePtr y = x->left;
    x->left = y->right;
    if (y->right != TNULL) {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
      this->root = y;
    } else if (x == x->parent->right) {
      x->parent->right = y;
    } else {
      x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
  }

  // Inserting a node
  void insert(int key) {
    NodePtr node = new Node;
    node->parent = NULL;
    node->data = key;
    node->left = TNULL;
    node->right = TNULL;
    node->color = 1;

    NodePtr y = NULL;
    NodePtr x = this->root;

    while (x != TNULL) {
      y = x;
      if (node->data < x->data) {
        x = x->left;
      } else {
        x = x->right;
      }
    }

    node->parent = y;
    if (y == NULL) {
      root = node;
    } else if (node->data < y->data) {
      y->left = node;
    } else {
      y->right = node;
    }

    if (node->parent == NULL) {
      node->color = 0;
      return;
    }

    if (node->parent->parent == NULL) {
      return;
    }

    insertFix(node);
  }

  NodePtr getRoot() {
    return this->root;
  }

  void deleteNode(int data) {
    deleteNodeHelper(this->root, data);
  }

 void verificaAlturaH(NodePtr raizArvore){
    int maximo, minimo;

    //Altura da Arvore pelo filho esquerdo
    if(raizArvore->left != TNULL){
        minimo = altura(raizArvore->left);
    }
    else{
        minimo = 0;
    }

    //Altura da Arvore pelo filho direito
    if(raizArvore->right != TNULL){
        maximo = altura(raizArvore->right);
    }
    else{
        maximo = 0;
    }

    //Verificacao da maior altura
    if(minimo > maximo){
        cout << minimo <<", "<< minimo << ", " << maximo << "\n";
    }
    else{
        cout << maximo <<", "<< minimo << ", " << maximo << "\n";
    }

}

int altura(NodePtr raizArvore){
    int alturaDireita, alturaEsquerda;

    if(raizArvore == TNULL){
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
  int alturaVermH(NodePtr x){
    return alturaVerm(x);
  }

  NodePtr get_TNULL(){
    return(this->TNULL);
  }

};

int main(){
    int numero; //Numero Digitado
    NodePtr numDesejado;
    RedBlackTree bst;

    cin >> numero;
    while(numero != -1){
        if(bst.searchTree(numero) == bst.get_TNULL()){
            bst.insert(numero);
        }
        cin >> numero;
    }
    bst.verificaAlturaH(bst.getRoot());

    cin >> numero;
    while(numero != -1){
        numDesejado = bst.searchTree(numero);
            if(numDesejado != bst.get_TNULL()){
                bst.verificaAlturaH(numDesejado);
                bst.deleteNode(numero);
        }
        else{
            bst.insert(numero);
        }
        cin >> numero;
    }

    scanf("%d", &numero);
    numDesejado = bst.searchTree(numero);

    if(numDesejado == bst.get_TNULL()){
        cout << "Valor nao encontrado";
    }
    else{
        cout << bst.alturaVermH(numDesejado);
        }

    return 0;

}
