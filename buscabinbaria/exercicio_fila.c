#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
	int info;
	struct node *next;
}node;

typedef struct queue
{
	node *begin;
	node *end;
}Queue;

Queue *CreateQueue()
{
	Queue *newQueue = (Queue *)malloc(sizeof(Queue));
	if(newQueue == NULL){
		puts("ERRO, FECHANDO O PROGRAMA!...");
		exit(1);
	}
	newQueue->begin = NULL;
	newQueue->end = NULL;
	return newQueue;
}
int EmptyQueue(Queue *queue)
{
	return (queue->end == NULL);
}
void Enqueue(Queue *queue, int data)
{
	node *newNode = (node*)malloc(sizeof(node));
	if(newNode == NULL){
		puts("ERRO, FECHANDO O PROGRAMA!...");
		exit(1);
	}
	newNode->info = data;
	newNode->next = NULL;

	if(EmptyQueue(queue)){
		queue->end = newNode;
		queue->begin = newNode;
	}else{
		queue->end->next = newNode;
	}
	queue->end = newNode;
}
int Dequeue(Queue *queue)
{
	if(EmptyQueue(queue)){
		puts("FILA VAZIA!");
		exit(1);
	}else{

		int x = queue->begin->info;
		node *aux = queue->begin;
		queue->begin = aux->next;
		if(aux->next == NULL){
			queue->begin = NULL;
			queue->end = NULL;
		}
		free(aux);
		return x;
	}
}

void PrintQueue(Queue *queue, node *begin)
{
	if(EmptyQueue(queue)){
		puts("FILA VAZIA!");
		return;
	}
	if(begin == NULL){
		return;
	}
	printf("%d ", begin->info);
	PrintQueue(queue, begin->next);
}
void ClearQueue(Queue *queue, node *begin)
{
	if(EmptyQueue(queue)){
		puts("FILA VAZIA!");
		return;
	}
	if(begin == NULL){
		queue->begin = NULL;
		queue->end = NULL;
		return;
	}
	else{
		node *aux2 = begin;
		begin = begin->next;
		free(aux2);
		ClearQueue(queue,begin);
	}
}
void Subtraction_of_queue_elements(Queue *queue, node *current, int *answer)
{
	if(current == NULL){
		return ;
	}else{
		*answer = *answer - (current->info);
		Subtraction_of_queue_elements(queue, current->next, answer);
	}
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

int main()
{
	Queue * queue = CreateQueue();
	int answer = 0;
	char item[10];

	int qtd;
	printf("Informe quantos numeros serao inseridos!\n");
	scanf("%d", &qtd);
	getchar();

	while(qtd > 0)
	{
		fgets(item, 10,stdin);

		if(Is_Valid(item))
		{
			Enqueue(queue,atoi(item));
		}else{
			puts("Entrada Invalida, parando a analise!");
			break;
		}
		--qtd;
	}
	Subtraction_of_queue_elements(queue, queue->begin, &answer);

	printf("A subtracao dos elemetos da fila e': %d\n", answer);
	//PrintQueue(queue, queue->begin);

	//obs: a fila principal nao foi destruida!
	//ClearQueue(queue, queue->begin); // Funcão usado para liberar a fila alocada;
	return 0;
}