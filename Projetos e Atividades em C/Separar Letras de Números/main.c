#include <stdio.h> 
#include<stdlib.h>

int main(){

  FILE *entradaPtr; 
  FILE *saidaPtr; 
  FILE *saida2Ptr;
   
  char letra;
  char texto[100];

  entradaPtr = fopen("entrada.txt","r");
  saidaPtr = fopen("saida.txt","w");
  saida2Ptr = fopen("saida2.txt","w");

  if ((entradaPtr  == NULL) && (saidaPtr == NULL) && (saida2Ptr == NULL) )
  {
      printf("arquivo não pode ser aberto");
      return 0;
  }
  
  printf("letras digitadas:%c\n",letra); 
  fscanf(entradaPtr,"%c", &letra); 

  while (!feof(entradaPtr)){  
    if (letra < '0' || letra > '9'){
      fprintf(saidaPtr,"%c",letra); 
    } 
    if (letra >= '0' && letra <= '9'){
      fprintf(saida2Ptr,"%c",letra);
    }  
    if (letra==' ') {
    

    }
    fscanf(entradaPtr,"%c",&letra);
  }
 fclose(saidaPtr); 
 fclose(saida2Ptr);
 fclose(entradaPtr);

return 0;

}
