#include <stdio.h>

#define MAX_FILA 100

typedef struct {
    int itens [MAX_FILA];
    int n; /*numero de elementos armazenados na fila*/
    int ini; /* indice para o inicio da fila */
} TFila;
typedef TFila *PFila;

PFila cria_fila(){
    PFila fila = (PFila) malloc (sizeof (TFila));
    fila->n = 0;
    fila->ini = 0;
    return (fila); // retorna o endereço que guarda essa fila
}

int insere (PFila p, int val){
    int fim;
    if (p==NULL) {
        prinft('Fila nao inicializada!\n');
        return -1; 
    }
    if (p->n == MAX_FILA ) {
        printf('Fila cheia!\n');
        return -1; 
    }
    fim = (p->ini+p->n)%MAX_FILA;  // "p->ini+p->n"  o início da fila + a quantidade de elementos
    // é o mesmo que a posição final da minha fila. O resto da divisão
    // do número da última posição pelo Max_fila define a posição em que irei adicionar o elemento
    p->itens[fim] = val;           
    p->n++;    // acrescentra "n" que é a nossa variável de num de elementos 
    return 0;
}

int incr_indice(int i) {
    return (i+1)%MAX_FILA;
}

int retira (PFila p, int* val){
    if (p==NULL) {
        prinft('fila nao inicializada!\n');
        return -1; 
    }
    if (p->n ==0) {
        printf('Fila vazia!\n');
        return -1; 
    }
    *val = p->itens[p->ini];
    p->ini = incr_indice(p->ini);
    p->n--;
    return 0;
}

/*
➢Faça um programa que leia duas filas numéricas
ordenadas crescentemente a partir do início da fila e
que contenham uma função que transfira os
elementos dessas filas para uma terceira fila,
inicialmente vazia, de modo que ela também fique
ordenada crescentemente com o menor valor no
início da fila.
*/

/*
int main(int argc, const char * argv[]){
    PFila fila1, fila2, fila3;
    int val, i;
    fila1 = cria_fila();
    fila2 = cria_fila();

    printf('Digite os elementos da primeira fila (digite -99999 para sair:\n');
    i = 1;
    do {
        printf('Elemento %d: ', i++);
        scanf("%d", &val);
    if (val!=99999)
        if (insere(fila1, val)==-1)
            printf('Não foi possivel inserir o elemento\n');
    } while (val!=99999);
}
*/
