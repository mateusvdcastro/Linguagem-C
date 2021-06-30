#include <stdio.h>

void savio(int s);
int main(){
  int tempo, horas, minutos, segundos;
  printf("Entre com o tempo em segundos: ");
  scanf("%d",&tempo);
  printf("\nTempo em segundos = %d", tempo);
  
  horas = (tempo/3600); 
  minutos = (tempo%3600)/60;
  segundos = tempo%60;
  printf("\n\n%dh%dm%ds\n\n",horas,minutos,segundos);

  savio(tempo);
  return 0;
}

void savio(int s){
  int h, m;
	
	m = (s / 60);
	s %= 60;
	h = (m / 60);
	m %= 60;
	
	printf("%dh%dm%ds", h, m, s);
}