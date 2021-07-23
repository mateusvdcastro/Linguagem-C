/*
Mateus Vespasiano de Castro RA: 159505
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a;
    a = (int*)malloc(1 * sizeof(int));
    *a = 123;     
    free(a);
    return 0;
}
