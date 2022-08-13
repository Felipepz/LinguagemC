#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *pont_entrada;
  FILE *pont_saida;
  FILE *pont_saida2;
  char c;

  pont_entrada = fopen("entrada.txt","r");
  pont_saida = fopen("saida.txt","w");
  pont_saida2 = fopen("saida2.txt","w");
  
  
  if ((pont_entrada == NULL) && (pont_saida == NULL) && (pont_saida2 == NULL) ){
    printf("Erro ao tentar abrir o arquivo!");
    return 0;
  } else {
    int i = 0;
    fscanf(pont_entrada, "%c", &c);
    while(!feof(pont_entrada)){
      if(c < '0' || c > '9' ){
        fprintf(pont_saida,"%c", c );
      }
      if((c > 47) && (c < 58)){
        fprintf(pont_saida2, "%c", c);
      }
      fscanf(pont_entrada, "%c", &c);
    
      i++;
    }
    
  }
  fclose(pont_entrada);
  fclose(pont_saida);
 }
 
