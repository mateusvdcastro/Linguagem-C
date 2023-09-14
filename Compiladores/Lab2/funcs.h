#ifndef funcs_H
#define funcs_H 1
#include <stdio.h>

typedef struct 
{
    int tamLinha;
    int pos;
    int numLinha;
    char buffer[256];
}Buffer;

typedef Buffer *pBuffer;

char get_next_char(pBuffer buf);

pBuffer allocate_buffer ();

void replace_print(pBuffer buf);

void deallocate_buffer (pBuffer buf);

#endif
