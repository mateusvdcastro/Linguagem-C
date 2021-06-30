#include <stdio.h>

int main (){
    char c; 
    int ASCII;
    printf('Digite A, E, I, O ou U: ');
    scanf("%c", &c);
    //printf("%d" "%o" "x" "%c", c, c, c, c); //ASCII, octal, hexadecimal
    ASCII = (c == 'A') ? 65 :
            (c == 'E') ? 69 :
            (c == 'I') ? 73 :
            (c == 'O') ? 79 :
            (c == 'U') ? 85 : -1;
    ASCII!=-1 ? printf("ASCII de %c é %d", c, ASCII) :
    printf("ASCII não está disponível!", c);
    // A = 65
    // E = 69
    // I = 73
    // O = 79
    // U = 85

    return 0;
}
