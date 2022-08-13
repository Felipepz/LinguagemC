#include <stdio.h>
#include <stdlib.h>

int main() {

  int quant, *p;
 
  printf("informe a quantidade de elementos:");
  scanf("%d",&quant);
  
  p = (int *)malloc(quant * sizeof(int));

  for(int i = 0; i<quant; i++){
    printf("informe o valor para posição %d do vetor:",i);
    scanf("%d",&p[i]);
 } 

  for(int i = 0; i<quant; i++){
    printf("\n no vetor numero %d esta a posição de memoria %d",i,p[i]);
  }

  quant = quant * sizeof(int);
  
  printf("\nA variavel numeors ocupa %ld do em bytesz",quant); 

  free(p); 
  p = NULL;
  return 0;
}
