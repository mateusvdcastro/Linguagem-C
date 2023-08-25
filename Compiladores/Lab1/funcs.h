#ifndef funcs_H
#define funcs_H 1

typedef struct 
{
    int bufferLen;
    char *buffer;
}Buffer;

typedef Buffer *pBuffer;

pBuffer allocate_buffer(pBuffer buffer,int size);

void replace_print(pBuffer buf);

void deallocate_buffer (pBuffer buf);

#endif
