#include <stdio.h>
#include <stdlib.h>


void registro(int v[], int d[], int i);
void calcula(int v[], int d[], int x);

int main(void) {
  int opcao;
  int i = 0;
  int mes[12];
  int dolar[12];

  while(1){
  printf("1 - Registrar Valor\n ");
  printf("2 - Calcular média móvel\n");
  printf("3 - Sair\n");
  printf("Selecione a opção: ");
  scanf("%d", &opcao);
  switch(opcao){
    case 1:  
    registro(mes, dolar, i);
    i++; 
    break;
    
    case 2: 
    calcula(mes, dolar, i);  
    break;
    
    case 3:
    exit(0);
    break; 
    
    default:
    printf("Opção Inválida\n\n");
    break;
  }
  }
  return 0;
}

void registro(int v[], int d[], int i){
  printf("Informe o valor de venda: ");
  scanf("%d", &v[i]);
  printf("Informe o valor do dolar ");
  scanf("%d", &d[i]);
  system("clear");
}

void calcula(int v[], int d[], int x){
  
  int mediaReal;
  int mediaDolar;
  system("clear");
  
  for(int i = 0; i < x; i++){
  mediaReal = mediaReal + v[i];
  } 
  mediaReal = mediaReal/x;
  printf("A média móvel em reais é: %d\n", mediaReal);
  
  for(int i = 0; i < x; i++){
  mediaDolar = mediaDolar + (v[i] * d[i]);
  }
  mediaDolar = mediaDolar/x;
  printf("A média móvel do dolar é: %d\n", mediaDolar);
  }
