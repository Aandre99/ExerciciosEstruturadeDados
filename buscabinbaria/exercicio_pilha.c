#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
	int info;
	struct node *next;
}node;

typedef struct stack
{
	node *top;
}Stack;

Stack *CreateStack()
{
	Stack *newStack = (Stack *)malloc(sizeof(Stack));
	if(newStack == NULL){
		puts("ERROR NA ALOCACAO DO NO, FECHANDO O PROGRAMA...");
		exit(1);
	}
	newStack->top = NULL;
	return newStack;
}
int EmptyStack(Stack *stack)
{
	return (stack->top == NULL);
}
void PrintStack(Stack *stack, node *top)
{
	if(EmptyStack(stack)){
		printf("FILA VAZIA!...\n");
		return;
	}
	if(top == NULL){
		return;
	}
	printf("%d ", top->info);
	PrintStack(stack, top->next);
}
void ClearStack(Stack *stack, node *top)
{
	if(top == NULL){
		stack->top  = NULL;
		return;

	}else{
		node *aux = top;
		top = top->next;
		free(aux);
		ClearStack(stack, top);
	}
}
void Push(Stack *stack, int data)
{
	node *newNode = (node*)malloc(sizeof(node));
	if(newNode == NULL){
		puts("ERROR NA ALOCACAO DO NO, FECHANDO O PROGRAMA...");
		exit(1);
	}
	newNode->info = data;
	newNode->next = stack->top;
	stack->top = newNode;
}
int Pop(Stack *stack)
{
	if(EmptyStack(stack)){
		printf("ERROR NA REMOCAO, PILHA VAZIA ...\n");
		exit(1);
	}
	int x = stack->top->info;
	node *aux = stack->top;
	stack->top = aux->next;

	if(aux->next == NULL){
		stack->top == NULL;
	}
	free(aux);
	return x;
}
int Is_Valid(char *str)
{
	int i=0;
	int size = strlen(str);

	if(size == 1){
		return 0;
	}
	while(str[i] != '\0')
	{
		if(isalpha(str[i])){
			return 0;
		}
		++i;
	}
	return 1;
}

Stack *Reverse_No_Impares(node *Top_main, Stack *Aux)
{
	if(Top_main == NULL){
		return Aux;
	}else{

		int x = Top_main->info;
		if(x % 2 != 1){
			Push(Aux,x);
		}
		Reverse_No_Impares(Top_main->next, Aux);
	}
}
int main()
{
	Stack * stack = CreateStack();
	Stack * aux = CreateStack();
	int qtd;
	char data[10];
	printf("Informe a quantidade de elemento que serao inseridos!\n");
	scanf("%d", &qtd);
	getchar();

	while(qtd > 0)
	{
		fgets(data,10,stdin);
		if(Is_Valid(data)){
			Push(stack, atoi(data));
		}else{
			puts("entrada invalida");
			break;
		}
		--qtd;
	}

	printf("Stack of input:\n");
	PrintStack(stack, stack->top);
	printf("\n");

	aux = Reverse_No_Impares(stack->top, aux);
	if(EmptyStack(aux)){
		printf("Nao foram inseridos numeros nao impares!\n");
	}else{
		printf("Stack of reverse no impares:\n");
		PrintStack(aux, aux->top);
	}
	ClearStack(stack, stack->top);

	return 0;
}