#include <stdio.h>
#include<stdlib.h>


int main(void) { 
  
  int topo = 0;
  int pilha[20]; 
  
  FILE *pont_entrada = fopen("entrada.txt", "r");
  FILE *pont_Saida = fopen("saida.txt", "w");
  
  while(!feof(pont_entrada)){
  fscanf(pont_entrada, "%d", &pilha[topo]);
  topo++;
  }
  
  for(int i = (topo - 1); i >= 0; i--){
  fprintf(pont_Saida, "%d\n", pilha[i]);
  } 
  
  fclose(pont_Saida); 
  fclose(pont_entrada);
  printf("Concluido.");
  exit(0);
  return 0;
}
