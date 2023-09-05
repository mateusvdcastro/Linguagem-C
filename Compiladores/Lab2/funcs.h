#ifndef funcs_H
#define funcs_H 1
#include <stdio.h>

typedef struct 
{
    int pos;
    int numLinha;
    char buffer[256];
}Buffer;

typedef Buffer *pBuffer;


char get_next_char(pBuffer buf, FILE *arquivo);

pBuffer allocate_buffer (pBuffer buf);

void replace_print(pBuffer buf);

void deallocate_buffer (pBuffer buf);

#endif
