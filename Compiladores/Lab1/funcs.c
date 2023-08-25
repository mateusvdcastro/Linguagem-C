#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>

pBuffer allocate_buffer(pBuffer buf, int size) {

  buf->buffer = (char *)malloc(sizeof(char) * (size + 1));

  return buf;
}

void deallocate_buffer (pBuffer buf) {

  free(buf->buffer);
  free(buf);
}

void replace_print(pBuffer buf) {

    for (int i=0; i<buf->bufferLen; i++) {
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

