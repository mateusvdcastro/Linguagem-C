#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
// Mateus Vespasiano de Castro RA 159505

void flush(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

int cont = 0;

int quantidade_livros(int dinheiro, int preco, int vale, int quant_total){

  int quant, resto;

  if (quant_total < dinheiro/preco){
    quant_total =  dinheiro/preco;
  }

  if (cont < 5){

    quant = dinheiro/preco;

    quant_total += (quant / vale);

    resto += (quant % vale);

    if (resto >= vale) {
      quant_total += resto;
    }

    cont ++;

    printf("Quant: %d", quant_total);

    quantidade_livros(dinheiro, preco, vale, quant);

  }

}

int main (){
    int n, d, p, v;
    int num_livros, quant = 0;
    
    int resultado;
  
    scanf("%d", &n);
    flush();

    for (int i=0; i < n; i++){
      scanf("%d", &d);
      scanf("%d", &p);
      scanf("%d", &v);

      flush();

      quantidade_livros(d, p, v, quant);


      //printf("Quantidade de livros: %d\n", num_livros);
      
    }
  
    return 0;
}
