#include <stdio.h>

//Programa para calcular o consumo médio de combustível
// Mateus Vespasiano de Castro RA: 2248751//

int main(void){
    float distancia, litros, consumo;

    printf("Digite quantos KM voce andou: \n");
    scanf("%f", &distancia);
    printf("Informe quantos Litros (L) foram consumidos: ");
    scanf("%f", &litros);

    consumo = distancia/litros;

    printf("Km rodados: %.2f", distancia);
    printf("\nLitros consumidos %.2f", litros);
    printf("\nConsumo Medio de Combustivel: %.2f", consumo);
}
