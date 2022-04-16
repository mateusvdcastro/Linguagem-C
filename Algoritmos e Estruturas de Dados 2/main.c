#include <stdio.h>
#include <string.h>

// A complexidade de uma busca binária é de OlogN

// deve ser usada abaixo de cada scanf para limpar o buffer
void flush(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

int main (){

    int vetor[50000], n;
    
    scanf("%[^\n]", n);
    flush();

    //printf("%d", n);
    
    /*
    for (int i=0; i<n; i++){
        scanf("%d", vetor[i]);
        flush();
    }
    */
}
