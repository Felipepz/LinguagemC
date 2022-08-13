#include <stdio.h>
#include <stdlib.h>
#define TAM 100

typedef struct{
  int head;
  int tail;
  int size;
  int vet[TAM];
}Fila;

void menu(int opcao, Fila *f);
int criarFila(Fila*f);
int inserir(Fila *f, int valor);
int remover(Fila *f);
int vazio(Fila *f);
int cheio(Fila *f);
void imprimirFila(Fila *f);
void primeiroFila(Fila *f);

int main(){

Fila *fila = malloc(sizeof(Fila));
	criarFila(fila);

  int opcao;

  printf("\nEscolha uma opção:");
  printf("\n1 - Adicionar um elemento");
  printf("\n2 - Remover um elemento");
  printf("\n3 - Ler o primeiro elemento");
  printf("\n4 - Finalizar\n");
  scanf("%d", &opcao);
  
  menu(opcao, fila);
  
	return 0;
  
}

void menu(int opcao, Fila *f) {
  int valor;
  
  while(opcao != 4) {
    
    switch(opcao) {
      case 1:
          printf("\nDigite um valor para ser inserido: ");
          scanf("%d", &valor);
          inserir(f, valor);
          printf("\nA fila está cheia!\n\n");
          imprimirFila(f);
          break;
      case 2:
          remover(f);
          imprimirFila(f);
        break;
      case 3:
          primeiroFila(f);
        break;
      default:
        printf("\nOpção inválida!");
        break;
    }
    
    printf("\n\nEscolha uma opção:");
    printf("\n1 - Adicionar um elemento");
    printf("\n2 - Remover um elemento");
    printf("\n3 - Ler o primeiro elemento");
    printf("\n4 - Finalizar\n");
    scanf("%d", &opcao);
  }
  
  printf("\nObrigado por utilizar o programa!");
} 

int criarFila(Fila*f){
 f = malloc(sizeof(Fila));
  if(f == NULL) return 0;

  f->head = 0;
  f->tail = 0;
  f->size = 0;
  return 1;
}

int inserir(Fila *f, int valor){
 if(cheio(f)) return 0;
  f->vet[f->tail] = valor;
  f->tail++;
  if(f->tail == TAM)
    f->tail = 0;
  f->size++;
}

int remover(Fila *f){
if (vazio(f)) return 0;
  int valor = f->vet[f->head];
  f->head ++;
  if(f->head == TAM)
    f->head = 0;
  f->size --;
  return valor;
}

int vazio(Fila *f){
if (f -> size == 0) return 1; 
return 0;
}

int cheio(Fila *f){
if (f -> size == TAM) return 1; 
return 0;
}

void imprimirFila(Fila *f){
  if (vazio(f)) {
    printf("A fila esta vazia");
  return;
  }  
  printf("Fila: ");
  
  for(int aux = f->head; aux <= f->tail; aux++) {
    printf("%d -> ", f->vet[aux % TAM]); 
} 
} 

void primeiroFila(Fila *f) {
  if(vazio(f)){
      puts("A fila está vazia");
      return;
  }
  printf("\nO primeiro valor da fila é: %d", f->vet[f->head % TAM]);
}
