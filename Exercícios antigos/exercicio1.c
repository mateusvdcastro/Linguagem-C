#include <stdio.h>

int main() {
  float n1, n2, n3, n4, n5, n6;
  float media1, media2;
  printf("Entre com os valores do grupo A <n1 n2 n3>: ");
  scanf("%f %f %f", &n1, &n2, &n3);
  printf("\nEntre com os valores do grupo B <n1 n2 n3>: ");
  scanf("%f %f %f", &n4, &n5, &n6);

  media1 = (n1+n2+n3)/3;
  media2 = (n4+n5+n6)/3;
  
  printf("\nMédias - Grupo A %.2f, Grupo B %.2f Media dos grupos = %.2f ", media1, media2, (media1+media2)/2);
  
  return 0;
}
