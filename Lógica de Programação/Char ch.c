#include <stdio.h>
int main(){
    char ch;
    ch = getche();
    if(ch == 'p')
        printf("Voce apertou a tecla p");
    else
        printf("Voce apertou outra tecla");
    return(0);
}
