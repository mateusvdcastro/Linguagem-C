/*
Mateus Vespasiano de Castro RA: 159505
*/

#include <stdio.h>

int main(){
    int a, b, *p;
    a = 10;
    // p = &a
    *p = 7;
    b = a + (*p);
    printf("%d", b);
    return 0; 
}
