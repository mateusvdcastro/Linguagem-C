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

  do {
    tam = fgets(buf->buffer, BUFFER_SIZE, arquivo);
    buf->tamLinha = strlen(tam);

    printf("\nNumero da linha: %d\n", buf->numLinha);
    printf("\nTamanho da linha: %d\n", buf->tamLinha);

    buf->pos = 0;
   
    for (int i = 0; i < buf->tamLinha; i++){
      c = get_next_char(buf);
      printf("%c", c);
    }

  } while (tam != NULL);
  
  deallocate_buffer(buf);
  printf("\nOIOIOIOIO");
  fclose(arquivo);

}
