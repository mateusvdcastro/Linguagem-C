#ifndef _BIBLIOTECA_H
#define _BIBLIOTECA_H

typedef struct ponto{
  float x;
  float y;
  float z;
}Ponto;

Ponto soma(Ponto a, Ponto b);

void imprimePonto(Ponto a);

float distancia (Ponto a, Ponto b);

//
//
float calculadora(float a, float b, char operador);




#endif