#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  if (argc != 3) {
    printf("%s <nome> <qnt>\n", argv[0]);
    exit(1);
  }
  pBuffer buf = NULL;
  
  /*Buffer aux;
  pBuffer buf = &aux;*/
  
  FILE *arquivo;
  
  buf = (pBuffer)malloc(sizeof(pBuffer));
  
  buf = allocate_buffer(buf, atoi(argv[2]));

  buf->bufferLen = atoi(argv[2]);

  arquivo = fopen(argv[1], "r");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }

  // rewind(arquivo); // volta para o início do arquivo
  char c;
  for (int i = 0; i < atoi(argv[2]); i++) {
    if ((c = fgetc(arquivo)) != EOF){
      buf->buffer[i] = c;
      buf->buffer[i+1] = '\0';
    }
  }
  buf->buffer[atoi(argv[2])] = '\0';
  
  //printf("%s", buf->buffer);

  replace_print(buf);

  // printf("número de entradas=%d\n", argc);
  // printf("executável=%s\n", argv[0]);
  // printf("nome=%s\n", argv[1]);
  // printf("sobrenome=%s\n", argv[2]);
}
