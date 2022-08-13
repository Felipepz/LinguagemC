#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct produto{
  int codigo;
  char descricao[20];
  char marca[20];
  int PrecoUnitario;
  char unidade[20];
  int QtdEstoque;
};

void novoregistro(struct produto vet[], int i, FILE *arq);
void limpardados(struct produto vet[], int i, FILE *arq);
void mudarvalor(struct produto vet[], int i, FILE *arq);
void mudarquantidade(struct produto vet[], int i, FILE *arq);
void imprimir(struct produto p[], int j, FILE *arq1, FILE *arq2);

int main(void) {
  
  struct produto p[100];
  int opcao;
  int registro = 0;
  int selecao;
  FILE *arqbin;
  FILE *arqtxt;
  
  setlocale(LC_ALL, "Portuguese");
  arqbin = fopen("produtos.bin", "rb+");
  arqtxt = fopen("produtos.txt", "w");
  while(1){
  printf("Selecione uma opção:\n");
  printf("\t1-Novo registro de produtos\n");
  printf("\t2-Eliminação de produtos(limpar dados)\n");
  printf("\t3-Alteração do preço de um determinado produto\n");
  printf("\t4-Alteração da quantidade de um produto\n");
  printf("\t5-Salvar informações em um arquivo de texto\n");
  printf("\t6-Sair\n");
  scanf("%d", &opcao);
  switch(opcao){
    case 1:
      system("clear");
      printf("geração do registro de produtos %d\n", (registro + 1));
      novoregistro(p, registro, arqbin);
      registro++;
    break;
    case 2:
      system("clear");
      printf("Informe um produto entre 1 e %d para deletar: ", registro);
      scanf("%d", &selecao);
      selecao = selecao - 1;
      if(selecao >= 0 && selecao <= registro){
        limpardados(p, selecao, arqbin);
        arqbin = fopen("produtos.bin", "rb+");
      }else{
        printf("opção inválida\n");
      }
    break;
    case 3:
      system("clear");
      printf("Informe um produto entre 1 e %d para mudar o valor: ", registro);
      scanf("%d", &selecao);
      selecao = selecao - 1;
      if(selecao >= 0 && selecao <= registro){
        mudarvalor(p, selecao, arqbin);
        arqbin = fopen("produtos.bin", "rb+");
      }else{
        printf("opção inválida\n");
      }
    break;
    case 4:
      system("clear");
      printf("Informe um produto entre 1 e %d para mudar o valor: ", registro);
      scanf("%d", &selecao);
      selecao = selecao - 1;
      if(selecao >= 0 && selecao <= registro){
        mudarquantidade(p, selecao, arqbin);
        arqbin = fopen("produtos.bin", "rb+");
      }else{
        printf("opção inválida\n");
      }
    break;
    case 5:
      system("clear");
      imprimir(p, registro, arqbin, arqtxt);
    break;
    case 6:
      fclose(arqbin);
      fclose(arqtxt);
      exit(0);
    break;
    default:
      printf("\n\nOpção Inválida\n\n");
    break;
  }
    }
  return 0;
}

void novoregistro(struct produto vet[], int i, FILE *arq){
  printf("Informe o codigo do produto: ");
  scanf("%d", &vet[i].codigo);
  getchar();
  printf("\nInforme a descrição do produto: ");
  fgets(vet[i].descricao, 20, stdin);
  printf("\nInforme a marca do produto: ");
  fgets(vet[i].marca, 20, stdin);
  printf("\nInforme o preço unitário do produto: ");
  scanf("%d", &vet[i].PrecoUnitario);
  getchar();
  printf("\nInforme a unidade do produto (KG, duzia, etc...): ");
  fgets(vet[i].unidade, 20, stdin);
  printf("\nInforme a quantidade de estoque do produto: ");
  scanf("%d", &vet[i].QtdEstoque);
  fwrite(vet, sizeof(vet), 1, arq);
}

void limpardados(struct produto vet[], int i, FILE *arq){
  vet[i].codigo = 0;
  vet[i].descricao[20] = '\0';
  vet[i].marca[20] = '\0';
  vet[i].PrecoUnitario = 0;
  vet[i].QtdEstoque = 0;
  vet[i].unidade[20] = '\0';
  fclose(arq);
  remove(arq);
  arq = fopen("produtos.bin", "ab+");
  fwrite(vet, sizeof(vet), 1, arq);
  fclose(arq);
}

void mudarvalor(struct produto vet[], int i, FILE *arq){
  int NovoValor;
  printf("Informe o novo valor do produto: ");
  scanf("%d", &NovoValor);
  vet[i].PrecoUnitario = NovoValor;
  fclose(arq);
  remove(arq);
  arq = fopen("produtos.bin", "ab+");
  fwrite(vet, sizeof(vet), 1, arq);
  fclose(arq);
}

void mudarquantidade(struct produto vet[], int i, FILE *arq){
  int NovoValor;
  printf("Informe a nova quantidade de estoque do produto: ");
  scanf("%d", &NovoValor);
  vet[i].QtdEstoque = NovoValor;
  fclose(arq);
  remove(arq);
  arq = fopen("produtos.bin", "ab+");
  fwrite(vet, sizeof(vet), 1, arq);
  fclose(arq);
}

void imprimir(struct produto p[], int j, FILE *arq1, FILE *arq2){
      int valortotal = 0;
      int quantidadetotal = 0;
      for(int i = 0; i <= (j - 1); i++){
        fread(p, sizeof(p), 1, arq1);
        fprintf(arq2, "-----------Produto %d-----------\n", i);
        fprintf(arq2, "Codigo do Produto: %d\n", p[i].codigo);
        fprintf(arq2, "descrição do Produto: %s", p[i].descricao);
        fprintf(arq2, "Marca do Produto: %s", p[i].marca);
        fprintf(arq2, "valor do Produto: %d\n", p[i].PrecoUnitario);
        fprintf(arq2, "quantidade de estoque do Produto: %d\n", p[i].QtdEstoque);
        fprintf(arq2, "Unidade do Produto: %s", p[i].unidade);
        fprintf(arq2, "\n\n");
        valortotal = valortotal + p[i].PrecoUnitario;
        quantidadetotal = quantidadetotal + p[i].QtdEstoque;
      }
      fprintf(arq2, "Valor total dos produtos: R$%d.00\n", valortotal);
      fprintf(arq2, "Quantidade total dos produtos: %d\n", quantidadetotal);
}
