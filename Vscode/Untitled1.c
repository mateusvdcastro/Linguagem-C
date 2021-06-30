#include <stdio.h>
#include <math.h>

int main(){
    float dis, xa, ya, xb, yb;
    printf("Entre com os pontos <xa ya xb yb>: ");
    scanf("%f %f %f %f", &xa, &ya, &xb, &yb);

    dis = sqrt(pow(xb-xa, 2) + pow(yb-ya, 2));
    printf("Distância entre A(%.2f)")
}
