#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  char *tam;
  char c;
  
  
  if (argc != 2) {
    printf("%s <nome> <qnt>\n", argv[0]);
    exit(1);
  }
  

  pBuffer buf = NULL;
  
  /*Buffer aux;
  pBuffer buf = &aux;*/
  
  FILE *arquivo;
  
  buf = allocate_buffer(buf);

  arquivo = fopen(argv[1], "r");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }

  buf->pos = 0;
  buf->numLinha = 0;

  tam = fgets(buf->buffer, 256, arquivo);

  //printf("%d", strlen(tam));

  while (c = get_next_char(buf, arquivo) != EOF) {
    c = get_next_char(buf, arquivo);
    printf("%c", c);

    if (buf->pos == 112){
      break;
    }
/*
    if (c == '\n') {
      tam = fgets(buf->buffer, 256, arquivo);
      if (strlen(tam) == 0) {
        break;
      }
      break;
    }
*/
  }

  printf("\n Buf->pos %d \n", buf->pos);
  printf("\n Buf->numLinha %d \n", buf->numLinha);
  
  buf->buffer[256] = '\0';
  


  fclose(arquivo);

  printf("número de entradas=%d\n", argc);
  // printf("executável=%s\n", argv[0]);
  // printf("nome=%s\n", argv[1]);
  // printf("sobrenome=%s\n", argv[2]);
}
