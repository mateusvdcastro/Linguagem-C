#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

char substitui_str(){
  char string[100];
  int i,cont;
  printf("Digite uma palavra ou frase:\n");
  fgets(string, 100, stdin);
  printf("A frase digitada foi: %s",string);
  cont=0;
  for(i=0;string[i]!='\0';i=i+1){
   
    if(string[i]=='a'){
      cont=cont+1;
      string[i]='b';
    }
  }  
  printf("Numero de caracteres a: %d\n",cont);
  printf("A frase alterada e: %s\n",string);
  return 0;
}

char imprime_nomes(){
  char nomes[5][100];
  int i;
  for (i = 0; i < 5; i++){
      printf("Digite o nome %d: ", i+1);
      fgets(nomes[i], 100, stdin);
  }
  printf("\n");
  for (i = 0; i < 5; i++)
      {
      printf("\nNome %i: %s", i+1, nomes[i]);
  }
return 0;

}

char salarios_func(){
  char cargo[100];              
  float sal=0, sal_novo=0;                                            

  printf("Informe o cargo: ");
  scanf("%s", &cargo);      
  printf("Informe o salario: ");
  scanf("%f", &sal);               
  printf("%s\n", cargo);
  if ((strcmp("Gerente", cargo)) == 0 || (strcmp("gerente", cargo)) ==0){                          
      sal_novo = sal + (sal*0.1);         
      printf("Novo salario: %.2f\nSalario antigo: %.2f\nAumento de: %.2f", sal_novo, sal, sal_novo-sal);
  } else if ((strcmp("Engenheiro", cargo))==0 || (strcmp("engenheiro", cargo))==0){ 
      sal_novo = sal + (sal*0.2);       
      printf("Novo salario: %.2f\nSalario antigo: %.2f\nAumento de: %.2f", sal_novo, sal, sal_novo-sal);
  } else if ((strcmp("Auxiliar", cargo))==0 || (strcmp("auxiliar", cargo))==0){
      sal_novo = sal + (sal*0.3);
      printf("Novo salario: %.2f\nSalario antigo: %.2f\nAumento de: %.2f", sal_novo, sal, sal_novo-sal);           
  } else {
      sal_novo = sal + (sal*0.4);       
      printf("Novo salario: %.2f\nSalario antigo: %.2f\nAumento de: %.2f", sal_novo, sal, sal_novo-sal);
  }
  return 0;
}

char capitalize(){
  char str[100];
  int i;
  printf("Digite uma frase ou palavra: ");
  fgets(str, 100, stdin);
  str[0] = str[0] - 32;
  for (i = 0; i < strlen(str); i++){
      if (str[i] == ' '){
          str[i+1] = str[i+1] - 32;
      }
  }
  
  printf("A palavra/frase digita com a primeira letra maiuscula: %s", str);
  return 0;
}

char intercala(){
  char A[20], B[20], C[40];
  int i,j, len=0, k;

  printf("String A: ");
  scanf(" %s", A);

  printf("String B: ");
  scanf(" %s", B);

  len = strlen(A) + strlen(B);

  for(i=0, j=0, k=0; i < len; i++){
      if(i%2 == 0){
          C[i] = A[j];
          j++;
      }else{
          C[i] = B[k];
          k++;
      }
  }
  printf ("String C: %s", C);
  return 0;
}
