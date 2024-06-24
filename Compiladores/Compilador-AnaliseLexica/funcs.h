#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_BUFFER 2
#define TAM_LEXEMA 64

typedef enum {
    ID, NUM, ELSE, IF, INT, RETURN, VOID, WHILE  
}TokenTypes;


typedef struct buffer{
  int pos_proxChar;
  int linha;
  char vet[TAM_BUFFER];
}Buffer;
typedef Buffer *PBuffer;

typedef struct lexema{
  int linha;
  int insere;
  int pos_in;
  int token;
  char lexema[TAM_LEXEMA];
}Lexema;
typedef Lexema *PLexema;

typedef struct arv {
  char palavra[TAM_LEXEMA];
  int token;
  int fb;
  int altura;
  struct arv *esq;
  struct arv *dir;
} TArv;
typedef TArv *PArv;

//Buffer
PBuffer allocate_buffer(PBuffer a);

void refresh_buffer(PBuffer a);

void deallocate_buffer(PBuffer b);

//Lexema
PLexema allocate_struct_lex(PLexema l);

void deallocate_struct_lex(PLexema l);

void refresh_lex(PLexema l);

int assign_token(char palavra[]);

void build_lex(PLexema l, PArv a, PArv busca);

//Char

void insert_char(PLexema a, PBuffer b, int prox_estado, char c);

void get_next_block(PBuffer a, FILE* arq);

char get_next_char(PBuffer a, FILE *arq, int flag);

int change_state(int estado_atual, char c, PLexema l);

//Árvore AVL
int max(int a, int b);

int altura(PArv a);

PArv rotacao_RR(PArv pA);

PArv rotacao_LL(PArv pA);

PArv rotacao_LR(PArv pA);

PArv rotacao_RL(PArv pA);

PArv rebalanceamento(PArv a);

PArv criaABB(PArv a, char palavra[], int token);

PArv libera(PArv a);

void imprime(PArv a, int nivel);
