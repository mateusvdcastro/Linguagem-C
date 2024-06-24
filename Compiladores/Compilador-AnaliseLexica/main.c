#include "funcs.h"

int main(int argc, char *argv[]) {

  FILE *entrada;
  FILE *saida;
  PBuffer buf = NULL;
  PLexema lex = NULL;  //Guardará o lexema identificado
  PArv arv = NULL, busca = NULL;
  char c;
  int flag = 1;
  int prox_estado, estado_atual = 0;
  int num_palavras_reservadas;
  int i;
  char *plvr_res[] = { //Palavras reservadas da linguagem
    "else", "if", "int", "return", "void", "while",
  "+", "-", "*", "/", "<", "<=", ">", ">=", "==", "!=", "=", ";", ",", "(", ")", "[", "]", "{", "}", "/*", "*/"
  };
  
  // Verificando se a quantidade de argumentos passada é correta
  if (argc == 3) {

    num_palavras_reservadas = sizeof(plvr_res) / sizeof(plvr_res[0]);

    for(i = 0; i < num_palavras_reservadas; i++){
      arv = criaABB(arv, plvr_res[i], i);
    }   

    //imprime(arv, 0);
    
    entrada = fopen(argv[1],"r");
    saida = fopen(argv[2],"w");

    if(entrada == NULL || saida == NULL){
      printf("Erro ao abrir o arquivo...\n");
      return 0;
    }

    buf = allocate_buffer(buf);  //alocando o buffer que percorre todo o arquvo
    lex = allocate_struct_lex(lex);  //alocando a struct que guardara cada lexema de uma vez

    do{

      c = get_next_char(buf, entrada, flag); //pegando o próximo caractere do arquivo
      
      flag = 0;

      if(c != '\0'){
        prox_estado = change_state(estado_atual, c, lex);

        insert_char(lex, buf, prox_estado, c);
        estado_atual = prox_estado;
        
        if(estado_atual == 10){
          
          if(lex->insere != 2){ //Caractere que foi computado mas precisará ser recomputado
            lex->lexema[lex->pos_in - 1] = '\0';
            buf->pos_proxChar--;
          }
          
          if(c == '\n'){
            lex->linha = buf->linha - 1;
          }
          else{
            lex->linha = buf->linha;
          }
          
          build_lex(lex, arv, busca);

          fprintf(saida, "LINHA: %2d| LEXEMA: |%s| TOKEN: |%d|\n", lex->linha, lex->lexema, lex->token);
          
          refresh_lex(lex);
          estado_atual = 0;
        }
        else if(estado_atual == 9){ //Erro léxico
          
          if(c == '\n'){
            lex->linha = buf->linha - 1;
          }
          else{
            lex->linha = buf->linha;
          }


          if (c != EOF) {
            printf("LINHA: %2d| ERRO LÉXICO: |%s|\n", lex->linha, lex->lexema);
          }
          refresh_lex(lex);
          estado_atual = 0;
        }
      }

    }while(c != EOF);

    deallocate_buffer(buf);
    deallocate_struct_lex(lex);
    arv = libera(arv);
    fclose(entrada);
    fclose(saida);
    
  }
  else{
    printf("Quantidade incorreta de parâmetros...");
  }

  return 0;
}