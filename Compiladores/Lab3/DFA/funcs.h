#ifndef funcs_H
#define funcs_H 1
#include <stdio.h>

#define MAX_LEXEMA_SIZE 64

typedef enum  {
    ID, IF, ELSE, WHILE, FOR, INT, FLOAT, CHAR, RETURN, BREAK, CONTINUE, VOID, MAIN, SCANF, PRINTF  
}TokenTypes;


typedef struct 
{
    int tamLinha;
    int pos;
    int numLinha;
    char buffer[256];
}Buffer;

typedef struct 
{
    TokenTypes token;
    int numLinha;
    char buffer[MAX_LEXEMA_SIZE];
}Lexema;

typedef Buffer *pBuffer;

typedef Lexema *pLexema;

char get_next_char(pBuffer buf, FILE *arq);

char * get_next_block(pBuffer buf, FILE *arq);

pBuffer allocate_buffer ();

pLexema allocate_lexema ();

void print_lex(pLexema lex);

void deallocate_buffer (pBuffer buf);

#endif
