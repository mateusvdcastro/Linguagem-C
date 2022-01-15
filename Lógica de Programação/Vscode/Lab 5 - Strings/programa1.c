/*
Escreva um programa que leia um string, conte quantos caracteres desta string
são iguais a ’a’ e substitua os que forem iguais a ’a’ por ’b’.

O programa deve imprimir o número de caracteres modificados e o string
modificado
Mateus Vespasiano de Castro RA: 159505
*/

#include <stdio.h>
int main()
{
  char string[100];
  int i,cont;
  printf("Digite uma palavra ou frase:\n");
  fgets(string, 100, stdin);
  printf("A frase digitada foi: %s",string);
  cont=0;
  for(i=0;string[i]!='\0';i=i+1){
   
    if(string[i]=='a'){
      cont=cont+1;
      string[i]='b';
    }
  }  
  printf("Numero de caracteres a: %d\n",cont);
  printf("A frase alterada e: %s\n",string);
  return(0);
}
