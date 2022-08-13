// Codigo Organização de Grupos - Felipe Moreira
// Bibliotecas Necessárias
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>

// Definindo tamanho
  #define TAM 500

// Definindo a estrutura do Nó
struct listNode {
    struct listNode *prevPtr;
    
    char nome[TAM];
    int prioridade; 

    struct listNode *nextPtr;
};

// Definindo a estrutura strings do tipo array
struct string {
    char grupo[TAM];
};

// Definindo os Tipos
typedef struct string stringArray;
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

// Prototipando a Funções
int menu();
void clear();
int aleatorioNum();
void imprimirList(ListNodePtr *sPtr);
void carregarGrupos(ListNodePtr *sPtr, int numeroNomes);
void inserir(ListNodePtr *sPtr, char nome[TAM], int prioridade);
void divisorGrupo(ListNodePtr *sPtr, stringArray grupos[TAM], int numeroNomes);
void gerarDocument();

int main(void) {
    int opcao;
    // Criação de aleatóriadade pela hora e data atual
    srand(time(NULL));
    do {
        // Pegando a opção do usuário
        opcao = menu();
        switch (opcao) {
            // Caso o usuário deseja sair do programa
            case 0:
                break;
            // Caso o usuário queira gerar o relatório
            case 1:
                gerarDocument();
							  break;
            // Caso a opção for inválida
            default:
                break;
        }
    // Enquanto o usuário não inserir a opção de saída no caso 0, continua o programa
    } while( opcao != 0 );
    return 0;
}

// Função para imprimir o menu, e recebe a opção do usuário
int menu() {
    // Declaração de variavéis local opcao
    int opcao;

    // imprimindo o menu
    clear();
    puts("\n\tSELECIONAR AÇÃO");
    puts("-------------------------");
    puts("\n1 - Gerar Documento");
    puts("0 - Sair\n");
    puts("-------------------------\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    clear();

    // Retorna a opção selecionada
    return opcao;
}

// Função que limpa a tela
void clear(){
    // Caso o OS seja Unix's like o comando será clear
    #if defined(__linux__) || defined(__unix__) || defined (__APPLE__)
    system("clear");
    #endif

    // Caso o OS seja Windows o comando será cls
    #if defined(_WIN32) || defined(_WIN64)
    system("cls");
    #endif
}

// Função de geração de números aleatórios inteiros de até TAM
int aleatorioNum() {
    return rand() % TAM;
}

// Função que gera o relatório .txt
void gerarDocument() {
    // Declaração de variavéis 
    int numeroNomes = 0;
    char nomeArq[TAM];
    char nome[TAM];
    FILE *nomesArq;
    ListNodePtr sPtr = NULL;

    // Pegando o nome do arquivo a ser aberto
    clear();
    puts("\nNome do arquivo dos alunos");
    puts("-------------------------\n");
    printf("Nome: ");
    scanf("%s", nomeArq);
    strcat(nomeArq, ".txt");

    // Abrindo o arquivo .txt
    nomesArq = fopen(nomeArq, "r");

    // Caso o arquivo esteja vazio 
    if ( nomesArq == NULL ){
        clear();
        puts("-------------------------");
        puts("\nO arquivo de alunos não pode ser aberto\n");
        puts("Nome errado do txt.");
        puts("-------------------------\n");
        // Sai caso esteja vazio      
        exit(1);
    }
    else {
        // Enquanto não encontrar o final continua o loop
        while ( !feof(nomesArq) ){
            fscanf(nomesArq, "%s", nome);
            numeroNomes++;

            // Inserindo um novo nó com o nome e prioridade na lista
            inserir(&sPtr, nome, aleatorioNum());
          
        }
        carregarGrupos(&sPtr, numeroNomes);
    }
    // Fechando o arquivo
    fclose(nomesArq);
}

// Função que printa a lista duplamente encadeada
void imprimirList(ListNodePtr *sPtr) {
    ListNodePtr currentPtr;
    currentPtr = *sPtr;

    // Se a lista estiver vazia imprimir
    if ( currentPtr == NULL ) {
        clear();
        puts("\nLista Vazia!\n");
    }
    else {
        // Enquanto não encontrar o final da lista ir printando
        while ( currentPtr != NULL ) {
            printf("%s %d <-> ", currentPtr->nome, currentPtr->prioridade);
            currentPtr = currentPtr->nextPtr;
        }
        puts("");
    }
}

// Função que organiza os grupos com seus grupos
void carregarGrupos(ListNodePtr *sPtr, int numeroNomes) {
    int count = 0;
    FILE *gruposArq;
    char nomeArq[TAM];
    stringArray grupos[TAM];
    ListNodePtr currentPtr = *sPtr;

    // Pegando o nome do arquivo de grupos
    clear();
    puts("-------------------------");
    puts("\nNome do arquivo dos grupos");
    puts("-------------------------\n");
    printf("Nome: ");
    scanf("%s", nomeArq);
    strcat(nomeArq, ".txt");

    // Abrindo o arquivo .txt
    gruposArq = fopen(nomeArq, "r");

    // Caso o arquivo esteja vazio avisar
    if ( gruposArq == NULL ){
        clear();
        puts("-------------------------");
        puts("\nO arquivo de grupos não pode ser aberto\n");
        puts("Nome errado do txt.");
        puts("-------------------------");
        // Saia dá função caso esteja vazio      
        exit(1);
    }
    else {
        // Enquanto não encontrar o EOF "final" continua o loop
        while ( !feof(gruposArq) ){
            fscanf(gruposArq, "%s", grupos[count].grupo);
            count++;
        }
    }
    // Fechando o arquivo
    fclose(gruposArq);  

    divisorGrupo(&currentPtr, grupos, numeroNomes);
}

void divisorGrupo(ListNodePtr *sPtr, stringArray grupos[TAM], int numeroNomes) {
    // Declaração de variáveis locais
    int opcao;
    int restoMemb;
    int novoGrupo = 0;
    int novoMembro = 0;    
    int numeroMembros;
    int numeroGrupo;
    FILE *arqDocumento;
    ListNodePtr currentPtr;
    
    currentPtr = *sPtr;

    // Pegando o número de grupos a ser feito
    do {
        clear();
        puts("-------------------------");
        puts("\nNúmeros de Grupos");
        puts("\nObs: Número de Grupos não pode ser");
        puts("maior que numero de alunos");
        puts("-------------------------\n");
        printf("Numero: ");
        scanf("%d", &numeroGrupo);
    } while (numeroGrupo <= 0);

    // Pegando o número de quantos participantes em cada grupo
    numeroMembros = numeroNomes / numeroGrupo;

    printf("Numero de nomes %d Numero de Grupos %d\n", numeroNomes, numeroGrupo);
    
    // Caso haja divisão não exata de grupos
    if ( numeroNomes % numeroGrupo != 0 ) {
        do {
            // Menu de pergunta no que o usuário deseja fazer
            clear();
            puts("\nDivisão dos grupos não é exata!\n");
            puts("\tSELECIONE A AÇÃO\n");
            puts("-------------------------\n");
            puts("1 - Forme um novo grupo");
            puts("0 - Redistribuir entre grupos");
            puts("\n-------------------------\n");
            printf("Numero: ");
            scanf("%d", &opcao);

        // Enquanto ele não escolher alguma dessas opções não sairá do menu
        } while ( opcao < 0 || opcao > 1);

        if ( opcao == 1 ) {
            // Acrecentando um grupo a mais
            novoGrupo++;
        }
        else {
            // Calculando o número de nomes que sobraram
            restoMemb = numeroNomes - (numeroMembros * numeroGrupo);

            // Acrecentando um nome a ser redestribuido
            novoMembro++;
        }
    }

    // Abrindo o arquivo .txt
    arqDocumento = fopen("relatorio.txt", "w");

    // Caso o arquivo esteja vazio avisar
    if ( arqDocumento == NULL ) {
        clear();
        puts("\nO arquivo não pode ser aberto.\n");

        // Saia dá função caso esteja vazio      
        exit(1);
    }
    else {
        // Laço para escrita de até o número de grupos especificados
        for (int count = 0; count < (numeroGrupo + novoGrupo); count++) {
            
            // Escrevendo a estrutura básica
            fprintf(arqDocumento, "Grupo %d:\n", count + 1);
            fprintf(arqDocumento, "grupo: %s\n", grupos[count].grupo);
            fprintf(arqDocumento, "Alunos: %s\n", currentPtr->nome);
            currentPtr = currentPtr->nextPtr;
  

            // Devido um nome já ter sido escrito, começa a escrita dos demais acrescentado
            for (int countNames = 1; countNames < (numeroMembros + novoMembro); countNames++) {
                fprintf(arqDocumento, "\t\t%s\n", currentPtr->nome);
                currentPtr = currentPtr->nextPtr;
                
                // Caso especial de ter menos nomes pra imprimir do que membros teoricos
                if ( currentPtr == NULL ) {
                    countNames = numeroMembros;
                }
            }
            // Caso especial de 
            if ( (count + 1) == restoMemb ) {
                novoMembro = 0;
            }
            fprintf(arqDocumento, "\n\n");
        }                
    }
    // Fechando o arquivo
    fclose(arqDocumento);
}

// Função de inserção de um na lista duplamente encadeada
void inserir(ListNodePtr *sPtr, char nome[TAM], int prioridade){
    // Declaração de variavéis locais
    ListNodePtr newPtr = NULL;
    ListNodePtr currentPtr = NULL;
    
    // Alocando espaço de memória necessário para um nó da lista
    newPtr = malloc(sizeof(ListNode));
    
    if ( newPtr != NULL ) {

        newPtr->prevPtr = NULL;
        strcpy (newPtr->nome, nome);
        newPtr->prioridade = prioridade;
        newPtr->nextPtr = NULL;
        currentPtr = *sPtr;
    
        if ( currentPtr == NULL ) {
            *sPtr = newPtr;
        }
        else {

            while ( (currentPtr->nextPtr) != NULL && prioridade > (currentPtr->prioridade) ){
                currentPtr = currentPtr->nextPtr;
            }
            if ( (currentPtr->nextPtr) == NULL && prioridade > currentPtr->prioridade ) {
                //insere no final
                currentPtr->nextPtr = newPtr;
                newPtr->prevPtr = currentPtr;
            
            } else if ( (currentPtr->prevPtr) == NULL && prioridade < currentPtr->prioridade){
                //Insere no Inicio
                newPtr->nextPtr = currentPtr;
                currentPtr->prevPtr = newPtr;
                *sPtr = newPtr;
            } 
            else {
                newPtr->nextPtr = currentPtr;
                newPtr->prevPtr = currentPtr->prevPtr;
                currentPtr->prevPtr->nextPtr = newPtr;
                currentPtr->prevPtr = newPtr;
            }
        }
    }
    else {
        clear();
        puts("Overflow na memoria!\n");
    }
}
