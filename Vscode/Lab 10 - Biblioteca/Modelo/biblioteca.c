#include "biblioteca.h"
#include <stdio.h>
#include <math.h>

float calculadora(float a, float b, char operador){
  float valor;
  if(operador == '-')
    valor = a - b; 
  else if (operador == '+')
    valor = a + b;
  else // implementar outros operadores
    valor = 0;
  return valor;
}

Ponto soma(Ponto a, Ponto b)
{
  Ponto aux;

  aux.x = a.x + b.x;
  aux.y = a.y + b.y;
  aux.z = a.z + b.z; 
  
  return aux;
}


void imprimePonto(Ponto a){
  printf("\n ----------------------\n");
  printf("| x= %.2f             |\n",a.x);
  printf("| y= %.2f             |\n",a.y);
  printf("| z= %.2f            |\n",a.z);
  printf("----------------------- \n");

}


float distancia (Ponto a, Ponto b){
  float d;
  d = sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2)+pow(b.z-a.z,2));
  return d;
}