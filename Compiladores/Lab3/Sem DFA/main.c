#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {

  char *tam; // Tamanho da string da linha
  char c; // Caractere retornado pela get_next_char
  int cont = 0;
  
  if (argc != 2) {
    printf("%s <nome> <qnt>\n", argv[0]);
    exit(1);
  }
  
  FILE *arquivo;

  arquivo = fopen(argv[1], "r");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }
  
  pBuffer buf = NULL;

  pLexema lex = NULL;
  
  /*Buffer aux;
  pBuffer buf = &aux;*/
  
  buf = allocate_buffer();

  lex = allocate_lexema();

  buf->numLinha = 1;
  buf->pos = 0;

  lex->numLinha = 1;
  lex->token = 0;

  do {
    
    c = get_next_char(buf, arquivo);

    // Vamos preencher o buffer lexema com cada string reconhecida como lexema
    // e depois vamos imprimir o buffer lexema
    if (!isalpha(c)) {
      lex->buffer[cont] = '\0';
      if (c == '\n') {
        lex->numLinha++;
      }

      if (strlen(lex->buffer) != 0){
        print_lex(lex);
      }
      cont = 0;
    } else if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' ||
               c == '6' || c == '7' || c == '8' || c == '9' || c == '0') {
        ;
    }else {
      lex->buffer[cont] = c;
      cont++;
    }
    
  } while (c != EOF);
  
  deallocate_buffer(buf);

  fclose(arquivo);

}
