#include <stdio.h> 
#include <stdlib.h>

struct stackNode{
  char data; 
  struct stackNode *nextPtr;
}; 
typedef struct stackNode StackNode; 
typedef StackNode *StackNodePtr; 

// protótipos
void push(StackNodePtr *topPtr, char info); // empilhar um valor
char pop(StackNodePtr *topPtr);  // desempilhar, sempre o último valor
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void instructions(void);

int main(void) {
  
  char palavra[20];
  StackNodePtr pilhaLetra = NULL;
  printf("Digite o nome: "); 
  scanf("%s",palavra);
  for(int i = 0; palavra[i] != '\0'; i++){
    push(&pilhaLetra, palavra[i]);
    
  }
  printStack(pilhaLetra);
  
  return 0;
}
// display program instructions to user
void instructions(void)
{ 
   puts("Enter choice:\n"
      "1 to push a value on the stack\n"
      "2 to pop a value off the stack\n"
      "3 to end program");
} 

// insert a node at the stack top
void push(StackNodePtr *topPtr, char info)
{ 
   StackNodePtr newPtr = malloc(sizeof(StackNode)); 
   // insert the node at stack top
   if (newPtr != NULL) {  
      newPtr->data = info;           
      newPtr->nextPtr = *topPtr;     
      *topPtr = newPtr;
   }                     
   else { // no space available
      printf("%d not inserted. No memory available.\n", info);
   } 
} 

// remove a node from the stack top
char pop(StackNodePtr *topPtr)
{ 
   StackNodePtr tempPtr = *topPtr;             
   char popValue = (*topPtr)->data;  
   *topPtr = (*topPtr)->nextPtr;
   free(tempPtr);               
   return popValue;
} 

// print the stack
void printStack(StackNodePtr currentPtr)
{ 
   // if stack is empty - (currentPtr == NULL) PASSA NEXT POR NEXT
   if (currentPtr == NULL) {
      puts("The stack is empty.\n");
   } 
   else { 
      puts("O nome reverso é: ");
      // while not the end of the stack
      while (currentPtr != NULL) { 
         printf("%c ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;
      } 
      puts("\n");
   } 
} 

// return 1 if the stack is empty, 0 otherwise
int isEmpty(StackNodePtr topPtr)
{
   return topPtr == NULL;
}
