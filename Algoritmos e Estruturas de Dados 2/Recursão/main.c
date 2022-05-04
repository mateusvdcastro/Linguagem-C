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
 
int quantidade_livros(int quant_vales, int valor_vale, int total){
 
  int quant_livros = 0;
 
  if (quant_vales < valor_vale) {  // o código encerra quando a quantidade de 
    return total;  // vales é insuficiente para pegar mais livros
  }
 
  quant_livros = quant_vales / valor_vale;
  
  quant_vales = quant_vales % valor_vale;  // pega o resto da divisão, pois 
  // 7 / 2 resulta em 3 livros e sobra mais um vale
 
  quant_vales = quant_livros + quant_vales; // soma o resto dos vales
 
  total += quant_livros;  
 
  return quantidade_livros(quant_vales, valor_vale, total); // a cada recursão
  // a quant_vales diminui
}
 
int main (){
    int n, d, p, v;
    int num_livros, vales, quant, total;
    
    int resultado;
  
    scanf("%d", &n);
    flush();
 
    for (int i=0; i < n; i++){
      scanf("%d", &d);
      scanf("%d", &p);
      scanf("%d", &v);
 
      flush();
 
      num_livros = d/p;  // numero de livros que podem ser sem obtidos ainda sem os vales 
 
      vales = num_livros;  // num_livros é equilavente aos vales
 
      quant = quantidade_livros(vales, v, num_livros);
 
      printf("%i\n", quant); // quantidade total dos livros adquiridos
      
    }
  
    return 0;
}
