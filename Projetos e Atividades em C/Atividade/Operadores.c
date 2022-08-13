#include <stdio.h>
#include <stdlib.h>
                     
struct stackNode {                   
   char data;          
   struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, char info);
void printstack(StackNodePtr currentPtr);

int main(void) {
  StackNodePtr stackPtr = NULL;
  char palavra[50];
  printf("digite os operadores [ ] { } ( ): ");
  scanf("%s", palavra);
  for(int i = 0; palavra[i] != '\0'; i++){
 push(&stackPtr, palavra[i]);
  }
  printf("Os operadores digitados  são: %s\n", palavra);
  if(palavra[0] == '{' && palavra[5] == '}' && palavra[1] == '[' && palavra[4] == ']' && palavra[2] == '(' && palavra[3] == ')'){
  printf("operadores Válidos");
  }else if(palavra[0] == '[' && palavra[3] == ']' && palavra[1] == '(' && palavra[2] == ')'){
  printf("operadores Válidos");
  }else if(palavra[0] == '(' && palavra[1] == ')'){
  printf("operadores Válidos");
  }else{
  printf("operadores Inválidos");
  }
  puts("\n");
  return 0;
}

void push(StackNodePtr *topPtr, char info)
{ 
   StackNodePtr newPtr = malloc(sizeof(StackNode));

   if (newPtr != NULL) {           
      newPtr->data = info;           
      newPtr->nextPtr = *topPtr;     
      *topPtr = newPtr;              
   }                     
   else {
      printf("Sem memória suficiente");
   } 
} 
