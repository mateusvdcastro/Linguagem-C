#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {

  char *tam; // Tamanho da string da linha
  char c; // Caractere retornado pela get_next_char
  int cont = 0;
  
  if (argc != 2) {
    printf("%s <nome> <qnt>\n", argv[0]);
    exit(1);
  }
  

  pBuffer buf = NULL;
  
  /*Buffer aux;
  pBuffer buf = &aux;*/
  
  FILE *arquivo;
  
  buf = allocate_buffer();

  arquivo = fopen(argv[1], "r");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }

  buf->numLinha = 0;
  buf->pos = 0;

  do {
  
    c = get_next_char(buf);

    printf("%c", c);
    
  } while (c != EOF);
  
  deallocate_buffer(buf);
  printf("\nOIOIOIOIO");
  fclose(arquivo);

}
