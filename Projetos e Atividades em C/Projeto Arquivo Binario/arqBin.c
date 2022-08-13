#include "arqBin.h" 
#include <locale.h>
#include<stdio.h>
#include<string.h>  

  
struct produtos {                           
   int  codigoProd; 
   char descricao[50]; 
   char marca[50]; 
   int unidade;
   int quantidade; 
   double precounitario;
}produtos; 

   void cadastroProduto(); 
    void eliminarProduto(); 
    void alterarPrecoProduto(); 
    void alterarQuantProduto(); 
    void exibirTotal(); 


void inicio(void){ 
    setlocale(LC_ALL, "Portuguese");
    
    FILE *pont_produtos_txt; 
    FILE *pont_produtos_bin;
    pont_produtos_txt = fopen("produtos.txt", "w"); 
    pont_produtos_bin = fopen("produtos.bin", "rb+"); 
  
    struct produtos produtos;
  
    int opcao; 
    int varloop = 1; 

   
    if ((pont_produtos_txt == NULL && pont_produtos_bin == NULL )) {
      printf("Erro ao tentar abrir o arquivo!");
      exit;
    } else { 
        
    while(varloop == 1){
    printf("\n");
    printf("******************************\n"); 
    printf("  Bem - Vindo \n");                   
    printf("******************************\n\n");
  
  
    printf("Escolha uma opção: \n");
    printf("--1 -- Cadastro Produto --\n"); 
    printf("--2 -- Eliminar um Produto --\n"); 
    printf("--3 -- Alterar preço do produto --\n");  
    printf("--4 -- Alterar quantidade do produto --\n");
    printf("--5 -- Exibir total do produto --\n"); 
      
    printf("--6 -- SAIR --\n"); 
      
    printf("--Opção digitada:");
    scanf("%d", &opcao);

    
  switch(opcao){

    case 1:  
      
    cadastroProduto();  
        
    break;
  
    case 2:   
    
    eliminarProduto();
     
    break;
  
    case 3: 
      
    alterarPrecoProduto();
  
    break;
       
    case 4:
  
    alterarQuantProduto();
  
    break;
  
    case 5:
      
    exibirTotal(produtos,pont_produtos_txt,pont_produtos_bin);
        
    break;
  
    case 6:
      varloop = 0; 
      printf("\n--- Nenhuma ação escolhida --- \n\n ");
      
    break;
   
  }
  }   
  } 
  } 

   void cadastroProduto(struct produtos produtos, FILE *pont_produtos_txt,FILE *pont_produtos_bin){ 
    
    fflush(stdin);   
    pont_produtos_txt = fopen("produtos.txt", "w"); 
    pont_produtos_bin = fopen("produtos.bin", "rb+");   
     
    if ((pont_produtos_txt == NULL && pont_produtos_bin == NULL )) {
   printf("Erro ao tentar abrir o arquivo!");
   exit;
    } else { 
       
    printf("\n--- Opção Cadastro Produto selecionada --- \n\n ");
  
    printf("\n Digite o codigo do Produto:  ");   
    scanf("%d",&produtos.codigoProd);   
   
    printf("\n Digite a descrição do Produto:  ");   
    scanf("%s",produtos.descricao); 
  
    printf("\n Digite a marca do Produto:  ");   
    scanf("%s",produtos.marca);
  
    printf("\n Digite a unidade do Produto:  ");   
    scanf("%d",&produtos.unidade);   
  
    printf("\n Digite a quantidade do Produto:  ");   
    scanf("%d",&produtos.quantidade); 
  
    printf("\n Digite o preço unitario do Produto:  ");   
    scanf("%lf",&produtos.precounitario); 
    
    
    fwrite(&produtos,sizeof(produtos),1,pont_produtos_bin);
      
     
    fclose(pont_produtos_bin); 

  }
  } 

   void eliminarProduto(struct produtos produtos,FILE *pont_produtos_txt, FILE *pont_produtos_bin ){  
     
    pont_produtos_txt = fopen("produtos.txt", "w"); 
    pont_produtos_bin = fopen("produtos.bin", "rb+"); 
     
    printf("\n--- Opção Eliminar Produto selecionada --- \n\n "); 
     
   int reg = 0; 
   int select; 
     
  printf("Informe um produto para deletar entre 1 e %d : ", reg);
    scanf("%d", &select);
    select = select - 1;
    if(select >= 0 && select <= reg){
    eliminarProduto(produtos, select, pont_produtos_bin);
    pont_produtos_bin = fopen("produtos.txt", "rb+");
    }else{
    printf("opção inválida\n");
    }
    if ((pont_produtos_txt == NULL && pont_produtos_bin == NULL )) {
    printf("Erro ao tentar abrir o arquivo!");
    exit;
    } else { 
      
    produtos.codigoProd = 0;
    produtos.descricao[50] = '\0';
    produtos.marca[50] = '\0';
    produtos.unidade = 0;
    produtos.quantidade = 0;
    produtos.precounitario = '\0';
    fclose(pont_produtos_txt);
    fclose(pont_produtos_bin);
    remove(pont_produtos_txt);
    remove(pont_produtos_bin);
      
    pont_produtos_txt = fopen("produtos.txt", "ab+"); 
    pont_produtos_bin = fopen("produtos.bin", "rb+");  
      
    fwrite(&produtos, sizeof(produtos), 1, pont_produtos_txt);
    fwrite(&produtos, sizeof(produtos), 1, pont_produtos_bin);
    


    fclose(pont_produtos_txt); 
    fclose(pont_produtos_bin); 
    
  } 
 } 

   void alterarPrecoProduto(struct produtos produtos,FILE *pont_produtos_txt, FILE *pont_produtos_bin){  
     
    pont_produtos_txt = fopen("produtos.txt", "w"); 
    pont_produtos_bin = fopen("produtos.bin", "rb+"); 
       
    printf("\n--- Opção Alterar Preço Produto selecionada --- \n\n ");
    int valor;
    printf("Informe o valor do produto que deseja atualizar: ");
    scanf("%d", &valor);
    produtos.unidade = valor;
    fclose(pont_produtos_bin);
    remove(pont_produtos_bin);
    pont_produtos_bin = fopen("produtos.bin", "ab+");
    fwrite(&produtos, sizeof(produtos), 1, pont_produtos_bin);
    fclose(pont_produtos_bin);


  } 

   void alterarQuantProduto(struct produtos produtos,FILE *pont_produtos_txt, FILE *pont_produtos_bin){  
    pont_produtos_txt = fopen("produtos.txt", "w"); 
    pont_produtos_bin = fopen("produtos.bin", "rb+"); 
    printf("\n--- Opção Alterar Quantidade do Produto selecionada --- \n\n ");   
    int valor;
    printf("Informe o novo valor do produto: ");
    scanf("%d", &valor);
    produtos.unidade = valor;
    fclose(pont_produtos_bin);
    remove(pont_produtos_bin);
    pont_produtos_bin = fopen("produtos.bin", "ab+");
    fwrite(&produtos, sizeof(produtos), 1, pont_produtos_bin);
    fclose(pont_produtos_bin); 
     
  }
    
   void exibirTotal(struct produtos produtos,FILE *pont_produtos_txt, FILE *pont_produtos_bin){
 { 
    pont_produtos_txt = fopen("produtos.txt", "w"); 
    pont_produtos_bin = fopen("produtos.bin", "rb+");
    printf("\n--- Opção Exibir total selecionada --- \n\n ");  
         
    int j;
    int valortotal = 0;
    int quantidadetotal = 0;
    for(int i = 0; i <= (j - 1); i++){
    fread(&produtos, sizeof(produtos), 1, pont_produtos_bin);
    fprintf(pont_produtos_txt, "--Produto --\n", i);
    fprintf(pont_produtos_txt, "Codigo do Produto: %d\n",produtos.codigoProd); 
    fprintf(pont_produtos_txt, "Descrição  Produto: %s",produtos.descricao);
    fprintf(pont_produtos_txt, "Marca  Produto: %s",produtos.marca);
    fprintf(pont_produtos_txt, "Preço unitario do Produto: %lf\n",produtos.precounitario);
    fprintf(pont_produtos_txt, "quantidade do Produto: %d\n", produtos.quantidade);
    fprintf(pont_produtos_txt, "Unidade do Produto: %d", produtos.unidade);
    fprintf(pont_produtos_txt, "\n");
    valortotal = valortotal + produtos.precounitario;
    quantidadetotal = quantidadetotal + produtos.quantidade;
    }
   fprintf(pont_produtos_txt, "Valor total dos produtos: R$%d.0\n", valortotal);
   fprintf(pont_produtos_txt, "Quantidade total dos produtos: %d\n", quantidadetotal);
  }

    
  }
