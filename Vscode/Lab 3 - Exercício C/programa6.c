#include <stdio.h>


int mdc(int A, int B){
    int resto;

    while (B != 0)
    {
        resto = A % B;
        A = B;
        B = resto;
    }
    return A;
    
}

int main()
{
    int in1, in2;
    printf("Digite dos números inteiros para calcular o MDC e MMC");
    scanf("%d %d", &in1, in2);

    printf("%d %d", in1, in2);

    return 0;

}
