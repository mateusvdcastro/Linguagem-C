#include <stdio.h>
#include <string.h>
//& endereco de 
//vetor[] -> vetor (&)

/*Escreva um programa que leia um string, conte quantos caracteres desta string são iguais a ’a’ e substitua os que forem iguais a ’a’ por ’b’. 
O programa deve imprimir o número de caracteres modificados e o string modificado*/

int main() {
  char string[100]; //[0..99] //[99]->\0
  int count = 0, i = 0;
  //ler string 
  scanf(" %[^\n]",string);
  do{
    if(string[i]=='a'){
      string[i] = 'b';
      count++;
    }
    //i++; 
  }while(string[++i]!='\0');
  printf("Num modificado = %d (%s)",count, string);

 /* char nome[100];
  int x, y;
  sscanf("Alo 1 2", "%s%d%d", nome, &x, &y);
 // char end[100];
 // char email[20];
  int i = 0;
 // printf("APERTAR UMA TECLA DO TECLADO: ");
  //fgets(nome, 99, stdin);
 // scanf(" %[^\n]",nome);
  //scanf(" %s",end);
  //scanf(" %s",email);
 // nome[1] = '\n'; //primeiro elemento [0] 
  do{
    if(nome[i] == 'e')
      nome[i] = 'X';
    printf("%c\n",nome[i]);
  }while(nome[++i]!='\0');
  printf("%s\n\n",nome);

  printf("nome[0] = %c nome[5] = %c\n",nome[0],nome[5]);
  int tamanho = strlen(nome);
  printf("%d ",tamanho);
  puts(nome);
  */
  return 0;
}


