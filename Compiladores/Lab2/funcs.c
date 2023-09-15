#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUFFER_SIZE 256


pBuffer allocate_buffer () {

    pBuffer buf = NULL;

    buf = (pBuffer)malloc(sizeof(Buffer));

    return buf;
}



char get_next_char(pBuffer buf){
    
    char c;

    c = buf->buffer[buf->pos];

    int cont = 0;

    if (c == '\n') {
        buf->pos = 0;
        buf->numLinha++;
        // get_next_block(buffer, fp);
    } else if (buf->pos == 255){
        buf->pos = 0;
        //get_next_block(buffer, fp);
    } else {
        buf->pos++;
    }

    return c;
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

