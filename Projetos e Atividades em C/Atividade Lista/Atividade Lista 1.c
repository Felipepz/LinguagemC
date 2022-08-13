#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Estrutura auto-referenciada
struct listNode {
	int data;				  // cada nó contém um inteiro
	struct listNode *nextPtr; // ponteiro para o próximo nó
};

typedef struct listNode ListNode; // tipo definido para struct listNode
typedef ListNode *ListNodePtr;	// Tipo definido para ListNode*

//Protótipos de funções
void imprime(ListNodePtr currentPtr);
void insert(ListNodePtr *sPtr, int value);
void inicializa(ListNodePtr l);
int isEmpty(ListNodePtr sPtr);
void encontraNo(ListNodePtr currentPtr);
void buscaValor(ListNodePtr currentPtr);
void numVezes(ListNodePtr currentPtr);
int tamanho(ListNodePtr currentPtr);
void numMeio(ListNodePtr currentPtr); 
void instructions(void);

int main(){
    
    ListNodePtr startPtr = NULL; // (Head) inicialização de uma lista Vazia
    int valor; // Caracter digitado pelo usuário 
    int opcao;
    //Inicializando lista
    inicializa(startPtr);
    //colocando programa em Português
    setlocale(LC_ALL, "Portuguese");
    while(1){
      instructions(); // mostra o menu
      printf("Opção digitada:  ");
      scanf("%d", &opcao);
      switch(opcao){
        // Inserir item na lista
        case 1:
          printf("\n\nDigite o numero: ");
          scanf("%d", &valor);
          insert(&startPtr, valor);
          system("clear");
        break;
        //imprime
        case 2:
          imprime(startPtr);break;
        //função que encontra o elemento do nó 
        case 3:
          encontraNo(startPtr);break;
        //função Procurar um valor na lista
        case 4:
          buscaValor(startPtr);break;
        //sFunção numero de vezes
        case 5:
          numVezes(startPtr);break;
        //Função meio
        case 6:
          numMeio(startPtr);break;
        case 7:
          exit(0);
        break;
        //mensagem de erro
        default:
          printf("\nOpção Inválida\n");
        break;
        }
  }
    return 0;
}

// mostra as instruções 
void instructions(void)
{ 
   puts("Digite sua escolha:\n"
      "   1 - Inserir valor na lista\n"
      "   2 - Imprimir lista lista\n"
      "   3 - Encontrar nó. \n"
      "   4 - Procurar um valor. \n"
      "   5 - Exbir Numero de vezes de um valor. \n"
      "   6 - Encontra o item do meio da lista. \n"

      "   7 - Sair.");
} 

//função para imprimir
void imprime(ListNodePtr currentPtr){
	// caso a lista esteja vazia
	if (isEmpty(currentPtr)) {
		printf("Lista vazia.\n");
	} else {
		printf("\nimprimindo sua lista: \n");
		while (currentPtr != NULL) {
			printf("%d --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		puts("NULL\n");
	}
}

// insere um caracter em ordem alfabética, tabela ASCII
void insert(ListNodePtr *sPtr, int value){
	ListNodePtr newPtr = malloc(sizeof(ListNode)); // cria um nó
	if (newPtr != NULL) {		// verifica se tem espaço disponível
		newPtr->data = value;   // coloca o valor no atributo >> data <<
		newPtr->nextPtr = NULL; // inicializa o ponteiro do nó para nulo

		ListNodePtr previousPtr = NULL;
		ListNodePtr currentPtr = *sPtr;

		// loop para encontrar a posição do caracter na lista
		while (currentPtr != NULL && value > currentPtr->data) {
			previousPtr = currentPtr;		  // caminha para ...
			currentPtr = currentPtr->nextPtr; // ... o próximo nó
		}

		// >> Inserção no início  <<
		if (previousPtr == NULL) {
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		} else { // >> Inserção no meio <<
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	} else {
		printf("%d não inserido. Nenhuma memória disponível\n", value);
	}
}

//inicializa
void inicializa(ListNodePtr l){
  l = NULL; 
  }

// retorna 1 (verdadeiro) se a lista estiver vazia, 0 (falso) caso contrário
int isEmpty(ListNodePtr sPtr){
	return sPtr == NULL;
}

//função que encontra o elemento do nó
void encontraNo(ListNodePtr currentPtr){
  printf("--- Opção Encontar nó selecionada ---\n\n");
  int tamnh = 0;
  int valor = 0;
  printf("Informe o nó que deseja consultar: ");
  scanf("%d", &valor);
	// caso a lista esteja vazia
	if (isEmpty(currentPtr)) {
		printf("Lista vazia.\n");
	} else {
		printf("\nValor do nó: \n");
		// enquanto não encontrar o fim da fila ...
		while (currentPtr != NULL) {
      if(tamnh == valor){
			printf("%d", currentPtr->data);
        }
      tamnh++;
			currentPtr = currentPtr->nextPtr;
		}
		puts("\n");
	}
}

//função que busca um valor
void buscaValor(ListNodePtr currentPtr){
  printf("--- Opção Procurar valor selecionada ---\n\n");
  int valor = 0;
  printf("Informe o valor: ");
  scanf("%d", &valor);
	// caso a lista esteja vazia 
	if (isEmpty(currentPtr)) {
		printf("Lista vazia.\n");
	} else {
		printf("\nProcurando ... \n");
		while (currentPtr != NULL) {
      if(currentPtr->data == valor){
			printf("O valor %d foi encontrado\n\n", valor);
        return;
        }
			currentPtr = currentPtr->nextPtr;
		}
    printf("O valor %d não foi encontrado", valor);
		puts("\n");
	}
}

//função para numero de vezes
void numVezes(ListNodePtr currentPtr){
  printf("--- Opção Numero de Vezes selecionada ---\n\n");
  int valor = 0;
  int rep = 0;
  printf("Informe o valor que deseja consultar: ");
  scanf("%d", &valor);
	// caso a lista esteja vazia
	if (isEmpty(currentPtr)) {
		printf("Lista vazia.\n");
	} else {
		printf("\nBuscando valor... \n");

		// enquanto não encontrar o fim da fila ...
		while (currentPtr != NULL) {
      if(currentPtr->data == valor){
          rep++;
        }
			currentPtr = currentPtr->nextPtr;
		}
    printf("O valor %d se repetiu %d vez(es)", valor, rep);
		puts("\n");
	}
}

//função para retornar o tamanho da lista
int tamanho(ListNodePtr currentPtr){
  int tamnh = 0;
	// caso a lista esteja vazia
	if (isEmpty(currentPtr)) {
		printf("Lista vazia.\n");
	} else {
		// enquanto não encontrar o fim da fila ...
		while (currentPtr != NULL) {
      tamnh++;
			currentPtr = currentPtr->nextPtr;
		}
	}
  return tamnh;
}

//função para encontrar o valor do meio da lista
void numMeio(ListNodePtr currentPtr){
   printf("--- Opção Encontra Numero no meio selecionada ---\n\n");
  int tamnh = tamanho(currentPtr);
  int Meio = tamnh/2;
  int PosAtual = 0;
	// caso a lista esteja vazia
	if (isEmpty(currentPtr)) {
		printf("Lista vazia.\n");
	} else {
		// enquanto não encontrar o fim da fila ...
		while (currentPtr != NULL) {
      if(PosAtual == Meio){
          printf("O valor %d esta no meio da lista\n", currentPtr->data);
        }
      PosAtual++;
			currentPtr = currentPtr->nextPtr;
		}
	}
}
