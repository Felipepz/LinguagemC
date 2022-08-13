#include <stdio.h>

void escrita();

int main(void){
  
 escrita();
  
} 

void escrita(){

  FILE *pont_tamanho_dados; 
  pont_tamanho_dados = fopen("tamanhoDados.dat", "w"); 

  if ((pont_tamanho_dados == NULL )) {
     printf("Erro ao tentar abrir o arquivo!");
     exit;
    } else { 
  
    fprintf(pont_tamanho_dados," char..............: %d bytes\n", sizeof(char)); 
    fprintf(pont_tamanho_dados," unsigned char.....: %d bytes\n", sizeof(unsigned char));
    fprintf(pont_tamanho_dados," short int.........: %d bytes\n", sizeof(short int)); 
    fprintf(pont_tamanho_dados," int...............: %d bytes\n", sizeof(int)); 
    fprintf(pont_tamanho_dados," unsigned short int: %d bytes\n", sizeof(unsigned short int )); 
    fprintf(pont_tamanho_dados," unsigned int......: %d bytes\n", sizeof(unsigned int )); 
    fprintf(pont_tamanho_dados," long int..........: %d bytes\n", sizeof(long int));
    fprintf(pont_tamanho_dados," unsigned long int.: %d bytes\n", sizeof(unsigned long int ));
    fprintf(pont_tamanho_dados," float.............: %d bytes\n", sizeof(float));
    fprintf(pont_tamanho_dados," double............: %d bytes\n", sizeof(double));
    fprintf(pont_tamanho_dados," long double.......: %d bytes\n\n", sizeof(long double)); 

    printf("*--- Escrita realizada ---*\n");
    
 fclose(pont_tamanho_dados);
}


}
