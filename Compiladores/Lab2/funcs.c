#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>


pBuffer allocate_buffer (pBuffer buf) {

  buf = (pBuffer)malloc(sizeof(pBuffer));

  return buf;
}

char get_next_char(pBuffer buf, FILE *arquivo){
    //printf("%d", buf->pos);

    if (buf->buffer[buf->pos] == '\n') {
        buf->numLinha++;
    } 
    buf->pos++;

    return buf->buffer[buf->pos];
    
    /*
    
    printf("%s", buf->buffer);
    printf("\n Buf->pos %d \n", buf->pos);
    printf("\n Buf->numLinha %d \n", buf->numLinha);
    */
}

void deallocate_buffer (pBuffer buf) {

  free(buf);
}

void replace_print(pBuffer buf) {

    for (int i=0; i<256; i++) {
        if (buf->buffer[i] == 'A') {
            buf->buffer[i] = 'a';
        } else if (buf->buffer[i] == 'E') {
            buf->buffer[i] = 'e';
        } else if (buf->buffer[i] == 'I') {
            buf->buffer[i] = 'i';
        } else if (buf->buffer[i] == 'O') {
            buf->buffer[i] = 'o';
        } else if (buf->buffer[i] == 'U') {
            buf->buffer[i] = 'u';
        } else if (buf->buffer[i] == 'a') {
            buf->buffer[i] = 'A';
        } else if (buf->buffer[i] == 'e') {
            buf->buffer[i] = 'E';
        } else if (buf->buffer[i] == 'i') {
            buf->buffer[i] = 'I';
        } else if (buf->buffer[i] == 'o') {
            buf->buffer[i] = 'O';
        } else if (buf->buffer[i] == 'u') {
            buf->buffer[i] = 'U';
        }
    }
    printf("buf=%s\n",buf->buffer);
}

