#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
// Mateus Vespasiano de Castro RA 159505

// https://pt.khanacademy.org/computing/computer-science/algorithms/binary-search/a/implementing-binary-search-of-an-array

// A complexidade de uma busca binária é de OlogN

// deve ser usada abaixo de cada scanf para limpar o buffer
void flush(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

int busca_binaria (int vetor[], int ini, int fim, int item, int *rec) {
  
    //*rec = *rec + 1;
    (*rec)++;
    
  /* Índice representando o meio do vetor */  
    int meio = (ini + fim) / 2; // exemplo: se ini = 0 e fim =9, teremos (0 + 9)  / 2 = 9 / 2 =  a posição 4 (retorna a parte inteira).

    if (ini > fim){  /* Ponto de parada. Item não está no vetor. Se para a esqueda fim = -1 e início = 0, se para a direita inicio = n + 1 e fim = n. Portanto ini > fim é ponto de parada */
        return -1;
    }

    if (vetor[meio] == item) {  /* Item encontrado */
        return *rec;
    }

    if (vetor[meio] < item) {  /* Item está no vetor à direita */
        return busca_binaria(vetor, meio + 1, fim, item, rec); // i + 1 significa que o novo início será o meio do vetor + 1


    } else {  /* vector[i] > item. Item está no vetor à esquerda */
        return busca_binaria(vetor, ini, meio - 1, item, rec);
    }
}

int main (){
    int n, n_busca, rec = -1;
    
    int resultado;
  
    scanf("%d", &n);
    flush();
  
    int *vetor = malloc(n * sizeof(int));
  
    for(int i=0; i < n; i++)
      scanf("%d", &vetor[i]);
    flush();

    scanf("%d", &n_busca);
    flush();

    //for(int i=0; i < n; i++)
    //  printf("\n%d", vetor[i]);

    resultado = busca_binaria(vetor, 0, n-1, n_busca, &rec); 

    if (resultado == -1) {
      printf("%d nao foi encontrado", n_busca);
    } else {
      printf("\n%d", resultado);
    }
  
    free(vetor);
    return 0;
}
