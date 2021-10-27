#include <stdio.h>

int main(){
  int num, num2;
  scanf("%d %d",&num, &num2); 

  printf("O numero %d eh %s",num, (num%2) == 0 ? "par":"impar");

  printf("\nO numero %d %s %d",num, ((num==num2) ? "==":((num>num2) ? ">":"<")), num2);

  return 0;
}
