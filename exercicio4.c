#include<stdio.h>

int main(){
  char c;
  int ASCII;
  printf("Digite A, E, I, O ou U: ");
  scanf("%c",&c);
 
  ASCII = (c == 'A') ? 65 : 
          (c == 'E') ? 69 :
          (c == 'I') ? 73 :
          (c == 'O') ? 79 :
          (c == 'U') ? 85 : -1;

  ASCII!=-1 ? printf("ASCII de %c eh %d (%d)", c, ASCII, c) : printf("ASCII de %c não está disponível! ", c);
    
  return 0;
}
