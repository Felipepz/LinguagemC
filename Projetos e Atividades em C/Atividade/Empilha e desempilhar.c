struct Pilha{
	int pilha[30];
	int count;
};

#include <stdio.h>

int main()
{
    struct Pilha p;
    int opcao, valor;
    p.count = 0;
    while(1){
    printf("1 - Empilhar\n");
    printf("2 - Desempilhar\n");
    printf("3 - Sair\n");
    printf("Informe a opção: ");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
          if(p.count >= 30){
            printf("\npilha Cheia\n");
          }else{
        printf("informe o valor: ");
        scanf("%d", &valor);
        p.pilha[p.count] = valor;
        for(int i = 0; i <= p.count; i++){
            printf("%d ", p.pilha[i]);
        }
        puts("\n\n");
        p.count++;
            }
        break;
        case 2:
          if(p.count == 0){
            printf("\npilha vazia\n");
          }else{
        p.count--;
        p.pilha[p.count] = 0;
        for(int i = 0; i <= p.count; i++){
            printf("%d ", p.pilha[i]);
        }
        puts("\n\n");
            }
        break;
        case 3:
        exit(0);
        break;
        default:
        printf("Opcao invalida");
        break;
    }
    }
    return 0;
}
