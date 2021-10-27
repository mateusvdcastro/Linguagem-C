#include <stdio.h>

int main(void){
  int num;
  scanf("%d",&num);
   
  printf("%d %d %d", num-1, num, num+1); 


  printf("\nNúmero: %d", num--);
  printf("\nAntecessor: %d", num++); 
  printf("\nSucessor: %d", ++num); 

  return 0;
}
