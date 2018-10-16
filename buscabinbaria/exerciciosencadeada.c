#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int item;
	struct node *next;
}node;

typedef struct list
{
	node *head;
}List;
//---------------Verificar se a lista esta vazia---------------------

int EmptyList(List *list)
{
	return (list->head == NULL);
}

//----------------Criar e inicializar a lista--------------------

List *CreateList()
{
	List * newList = (List *)malloc(sizeof(List));
	if(newList == NULL){
		puts("ERROR!");
		exit(1);
	}
	newList->head == NULL;
	return newList;
}

//--------------Inserir Um elemento na lista----------------------

void Insert(List *list, int data)
{
	node *newNode = (node*)malloc(sizeof(node));
	newNode->item = data;

	if(newNode == NULL){
		puts("ERROR!");
		exit(1);
	}
	newNode->next = list->head;
	list->head = newNode;
}

//---------------Inserir Um elemento em ordem na lista---------------------

void Insert_in_Order(List *list, int data)
{

	node *newNode = (node*)malloc(sizeof(node));

	if(newNode == NULL){
		puts("ERROR!");
		exit(1);
	}
	newNode->item = data;
	node *current = list->head, *previous = NULL;

	while(current != NULL && data > current->item)
	{
		previous = current;
		current = current->next;
	}

	if(previous == NULL){
		newNode->next = list->head;
		list->head = newNode;
	}else if(current == NULL){
		previous->next = newNode;
		newNode->next = NULL;
	}else{
		previous->next = newNode;
		newNode->next = current;
	}
}

//--------Mostrar a lista final------

void ShowList(List *list)
{
	if(EmptyList(list)){
		puts("EmptyList");
		exit(1);
	}

	node *aux = list->head, *aux2 = NULL;
	while(aux != NULL){

		aux2 = aux;
		printf("%d ", aux->item);
		aux = aux->next;
		free(aux2);
	}
	list->head = NULL;
}
//--------ConcatenaDuasListas-----------

void ConcatList(List *list_One, List *list_Two)
{
	node *aux = list_Two->head, *aux2 = NULL;
	while(aux != NULL)
	{
		aux2 = aux2;
		Insert_in_Order(list_One, aux->item);
		aux = aux->next;
		free(aux2);
	}
	list_Two->head = NULL;
}
int main()
{
	List *list_One = CreateList();
	List *list_Two = CreateList();

	int size1,size2, num;

	scanf("%d", &size1);

	while(size1 > 0)
	{
		scanf("%d", &num);
		Insert_in_Order (list_One, num);
		size1--;
	}

	scanf("%d", &size2);

	while(size2 > 0)
	{
		scanf("%d", &num);
		Insert_in_Order(list_Two, num);
		size2--;
	}
	ConcatList(list_One, list_Two);

	ShowList(list_One);
	return 0;
}