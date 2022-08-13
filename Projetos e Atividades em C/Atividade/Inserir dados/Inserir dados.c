#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct pessoa {
  char sobrenome[15];
  char primNome[15];
  char idade[2];
}pessoa;

    void menu(); 
    void inserirPessoa(struct pessoa vet[], int i, FILE *pont_nome_idade);
    void apagarPessoa(struct pessoa vet[], int i, FILE *pont_nome_idade);
    void alterarPessoa(struct pessoa vet[], int i, FILE *pont_nome_idade);
  

int main(void){
  struct pessoa pessoa[100];
  int opcao;
  FILE *pont_nome_idade;
  int i = 0;
  int reg = 0;

  setlocale(LC_ALL, "Portuguese");
  pont_nome_idade = fopen("nomeidade.dat", "rb+");
  for(int i = 0; i < 100; i++){
    pessoa[i].sobrenome[15] = "semsobrenome";
    pessoa[i].primNome[15] = "";
    pessoa[i].idade[2] = "0";
    fwrite(pessoa[i].sobrenome, 1, sizeof(pessoa), pont_nome_idade);
    fwrite(pessoa[i].primNome, 1, sizeof(pessoa), pont_nome_idade);
    fwrite(pessoa[i].idade, 1, sizeof(pessoa), pont_nome_idade);
  }
  while(1){
    menu();
  switch(opcao){
    case 1:
      inserirPessoa(pessoa, i, pont_nome_idade);
      i++;
    break;
    case 2:
      printf("\nEscolha um registro para limpar entre 1 e %d : ", (i + 1));
      scanf("%d", &reg);
      system("clear");
      if(reg >= 0 && reg <= i){
      limpardados(pessoa, (reg - 1), pont_nome_idade);
      pont_nome_idade = fopen("nomeidade.dat", "rb+");
      }else{
      printf("Opção Inválida");
      }
    break;
    case 3:
      printf("\nEscolha um registro entre 1 e %d para alterar: ", (i + 1));
      scanf("%d", &reg);
      system("clear");
      if(reg >= 0 && reg <= i){
      alterar(pessoa, (reg - 1), pont_nome_idade);
      pont_nome_idade = fopen("nomeidade.dat", "rb+");
      }else{
      printf("Opção Inválida");
      }
    break;
    case 4:
      fclose(pont_nome_idade);
      exit(0);
    break;
    default:
      printf("\nOpção Inválida\n");
    break;
    }
  }
  return 0;
}

void menu(){
    
    printf("\n");
    printf("**************\n"); 
    printf("  Bem - Vindo \n");                   
    printf("**************\n\n");
  
    printf("Escolha uma opção: \n");
    printf("--1 -- Inserir Pessoa --\n"); 
    printf("--2 -- Apagar Pessoa--\n"); 
    printf("--3 -- Alterar Pessoa --\n");  
    printf("--4 -- SAIR --\n");


  
}

void inserirPessoa(struct pessoa vet[], int i, FILE *pont_nome_idade){
  
    printf("Informe o nome da pessoa: ");
    fgets(vet[i].primNome, 15, stdin);
    getchar();
    printf("\nDigite o sobrenome da pessoa: ");
    fgets(vet[i].sobrenome, 15, stdin);
    getchar();
    printf("\nDigite a idade da pessoa: ");
    fgets(vet[i].idade, 2, stdin);
    getchar();
    fwrite(vet, sizeof(vet), 1, pont_nome_idade);
}

void apagarPessoa(struct pessoa vet[], int i, FILE *pont_nome_idade){
  
    vet[i].idade[2] = '\0';
    vet[i].primNome[15] = '\0';
    vet[i].sobrenome[15] = '\0';
    fclose(pont_nome_idade);
    remove(pont_nome_idade);
    pont_nome_idade = fopen("nomeidade.dat", "ab+");
    fwrite(vet, sizeof(vet), 1, pont_nome_idade);
    fclose(pont_nome_idade);
}

void alterarPessoa(struct pessoa vet[], int i, FILE *pont_nome_idade){
  
    printf("Digite o novo nome: ");
    fgets(vet[i].primNome, 15, stdin);
    getchar();
    printf("Digite o novo sobrenome: ");
    fgets(vet[i].sobrenome, 15, stdin);
    getchar();
    printf("Digite a nova idade : ");
    fgets(vet[i].idade, 2, stdin);
    getchar();
    fclose(pont_nome_idade);
    remove(pont_nome_idade);
    pont_nome_idade = fopen("nomeidade.dat", "ab+");
    fwrite(vet, sizeof(vet), 1, pont_nome_idade);
    fclose(pont_nome_idade);
}
