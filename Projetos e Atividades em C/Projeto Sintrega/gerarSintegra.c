#include "gerarSintegra.h"
#include <locale.h>
#include<stdio.h>
  
  int encontrouCliente(int cliente);
  FILE *pont_produtos;
  FILE *pont_cliente;
  FILE *pont_vendas;
  FILE *pont_fornecedor; 
  FILE *pont_sintegra;
 
  struct info{ 
  char nomeForn[50];
  int opcao;
  char nomeCli[50]; 
  int codForn;
  char regEmp[50];
  char endereco[50]; 
  char nomeProduto[30];
  float precounit; 
  int codProd;
  int codCli;
  int cnpjForn;
  int numNota;
  int dataVenda;

  }info; 

  void cadastroCliente(); 
  void cadastroFornecedor();
  void cadastroProduto();


void menu(void){ 

  setlocale(LC_ALL, "Portuguese");
  struct info info;
  int opcao;
  int varloop = 1; 

  FILE *pont_produtos;
  FILE *pont_cliente;
  FILE *pont_vendas;
  FILE *pont_fornecedor; 
  FILE *pont_sintegra;

  pont_produtos = fopen("produtos.txt", "a");
  pont_cliente = fopen("cliente.txt", "a");
  pont_vendas = fopen("vendas.txt", "a");
  pont_fornecedor = fopen("fornecedor.txt", "a"); 
  pont_sintegra = fopen("sintegra.txt","a");

  if ((pont_produtos == NULL) && (pont_cliente == NULL) &&
      (pont_vendas == NULL) && (pont_fornecedor == NULL)) {
    printf("Erro ao tentar abrir o arquivo!");
    exit;
  } else { 
      
  while(varloop == 1){

  printf("\n");
  printf("******************************\n"); 

  printf("  Bem - Vindo \n");                  
 
  printf("******************************\n\n");


  printf("Escolha uma opção: \n");

  printf("--1 -- Cadastrar cliente --\n");
  printf("--2 -- Cadastrar Fornecedor --\n");
  printf("--3 -- Cadastro Produto --\n");
  printf("--4 -- Fazer Venda --\n"); 
  printf("--5 -- Imprimir Sintegra --\n"); 
  printf("--6 -- SAIR --\n"); 
    
  printf("--Opção digitada:");

  scanf("%d", &opcao);

    
  switch(opcao){

    case 1: { 
      
     cadastroCliente();

    }

    break;

    case 2:  {  
      
    cadastroFornecedor();
     break;
    }
   case 3: { 

    cadastroProduto();
    break;
    }
   case 4: {
  
    printf("\n--- Opção Fazer Venda selecionada --- \n\n ");

    printf("Número da Nota: \n");
    scanf("%d", &info.numNota);
    
    printf("Data Venda: \n");
    scanf("%d", &info.dataVenda);
   

    do{
      printf("Codigo Cliente: ");
      scanf("%d", &info.codCli);
      fprintf(pont_vendas, "%d %d %d \n", info.numNota, info.codCli, info.dataVenda);
    }while(!encontrouCliente(info.codCli));

    fclose(pont_vendas);

   break;
  } 
   case 5:{
     printf("Opção Sintegra selecionada"); 

      break;
    }
   case 6:{ 
     
     varloop = 0; 
     printf("\n--- Nenhuma ação escolhida --- \n\n ");


     break;
   }
    

  } 


  } 

 return;  
  }
}

int encontrouCliente(int cliente){
  
  int codcliente;
  char nomecliente[20];
  char endereco[20];

  pont_cliente = fopen("cliente.txt", "r");

  while(!feof(pont_cliente)){

    fscanf(pont_cliente,"%d%s%s", &codcliente, nomecliente, endereco);
    if(cliente == codcliente){
      return 1;
    }
  }

  return 0;

}   

int encontrousintegra(FILE *pont_sintegra, FILE *pont_produtos,FILE *pont_vendas, FILE *pont_fornecedor, FILE *pont_cliente){
  
  int a;
  int b[20];
  int c[20]; 
  int CodFor; 
  int CpnjFor; 
  char NomeForn;
  int CodProd; 
  char NomProd;
  float PrecoPro;  
  char sintegra[10000];
  
  pont_vendas = fopen("vendas.txt", "r"); 
  pont_fornecedor = fopen("fornecedor.txt", "r");
  pont_produtos = fopen("produtos.txt", "r"); 
  pont_sintegra = fopen("sintegra.txt", "a");   

  while(!feof(pont_vendas)&&(pont_fornecedor)&&(pont_produtos)){

    fscanf(pont_vendas,"%d%d%d", &a, &b, &c);
    fscanf(pont_fornecedor,"%d%d%s", &CodFor, &CpnjFor, NomeForn); 
    fscanf(pont_produtos,"%d%s%f", &CodProd, NomProd, PrecoPro);  
     
  while(fgets(sintegra,10000,pont_produtos) != NULL); 
  fputs(sintegra,pont_produtos);

    
   if(encontrousintegra == a){
      return 1;
    }
  }

  fclose(pont_vendas);
  fclose(pont_fornecedor);
  fclose(pont_produtos);

  return 0;

}   

void cadastroCliente(struct info info,FILE *pont_cliente ){ 
    pont_cliente = fopen("cliente.txt", "a");
  
    printf("\n--- Opção cadastro cliente selecionada --- \n\n "); 

    printf("Codigo cliente: ");
    scanf("%d", &info.codCli);
    fprintf(pont_cliente, "%d ", info.codCli);

    printf("Nome Cliente: ");
    scanf("%s", info.nomeCli);  
    fprintf(pont_cliente,"%s ", info.nomeCli);

    printf("Endereço Cliente: ");
    scanf("%s", info.endereco);
    fprintf(pont_cliente,"%s \n", info.endereco);
    

    fclose(pont_cliente);  
}

void cadastroFornecedor(struct info info,FILE *pont_fornecedor){
      pont_fornecedor = fopen("fornecedor.txt", "a"); 
  
      printf("\n--- Opção cadastrar fornecedor selecionada --- \n\n\n ");

      printf("Código Fornecedor: ");
      scanf("%d", &info.codForn);
      fprintf(pont_fornecedor, "%d", info.codForn);

      printf("CNPJ Fornecedor: ");
      scanf("%d", &info.cnpjForn);
      fprintf(pont_fornecedor, "%d", info.cnpjForn);

      printf("Nome Fornecedor: ");
      scanf("%s", info.nomeForn);
      fprintf(pont_fornecedor, "%s\n", info.nomeForn);
    
     fclose(pont_fornecedor); 
  
} 

void cadastroProduto(struct info info,FILE *pont_produtos){
    pont_produtos = fopen("produtos.txt", "a");
  
    printf("\n--- Opção cadastrar produto selecionada --- \n\n"); 

    printf("Codigo do produto: \n");
    scanf("%d", &info.codProd);

    printf("Nome Produto: \n");
    scanf("%s", info.nomeProduto);

    printf("Preço unitário: ");
    scanf("%f", &info.precounit);
    fprintf(pont_produtos, "%d %s %f\n", info.codProd, info.nomeProduto, info.precounit);

   
   fclose(pont_produtos); 

  
}

 


