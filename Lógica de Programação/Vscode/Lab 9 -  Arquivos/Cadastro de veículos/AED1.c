/*
NOME: Mateus Vespasiano de Castro 
RA: 159505
TURMA: IB
*/

int main (){
    int n_cad;
    char marca[15], modelo[50], Placa_do_Carro[6], ar_condicionado;
    int ano_de_fabricacao, numero_de_portas, quilometragem;
    
    FILE *parq;
    parq = fopen("veículos.txt", "w");
    if (parq == NULL){
        printf("\n\nNao foi possivel abrir o arquivo para escrita.\n");
        exit(1);
    }
    else
        printf("Arquivo aberto para escrita.");

    fprintf(parq, "%c", "1) Inserir novo cadastro de veiculo");
    fprintf(parq, "%c", "2) Alterar cadastro");
    fprintf(parq, "%c", "3) Mostrar os dados de um veiculo");
    fprintf(parq, "%c", "4) Apagar registro");
    fprintf(parq, "%c", "5) sair");

    rewind(parq);

    while (fscanf(parq, "%c") != EOF){
        printf("%c", c);
    }

    printf("Digite uma opção de cadastro: ");
    scanf("%i", n_cad);

    printf("%i", &n_cad);
    


    fclose(parq);
}
