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

char * get_next_block(pBuffer buf, FILE *arq){
    char *str;

    memset(buf->buffer, '\0', sizeof(buf->buffer));

    str = fgets(buf->buffer, 256, arq);

    return str;
}



char get_next_char(pBuffer buf, FILE *arq){
    
    char c;
    char * str;

    static int flag = 0;  // Só será executada uma vez

    if (flag == 0) {
        str = get_next_block(buf, arq);
        if (str == NULL){
            return EOF;
        }
        flag = 1;
    }

    c = buf->buffer[buf->pos];

    int cont = 0;


    if (c == '\n') {
        buf->pos = 0;
        buf->numLinha++;
        str = get_next_block(buf, arq);
        if (str == NULL){
            return EOF;
        }
    } else if (buf->pos == 255){
        buf->pos = 0;
        str = get_next_block(buf, arq);
        if (str == NULL){
            return EOF;
        }
    } else {
        buf->pos++;
    }

    return c;
}


void deallocate_buffer (pBuffer buf) {

  free(buf);
}
