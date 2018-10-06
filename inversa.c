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
	printf("\n");
}
//--------InverterUmaLista-----------

void ReverseList(List *One, List *Two)
{
	if(EmptyList(One)){
		puts("EmptyList");
		return;
	}

	node *aux = One->head;
	while(aux != NULL)
	{
		Insert(Two, aux->item);
		aux = aux->next;
	}
}

int main()
{
	List *list = CreateList();
	List *list1 = CreateList();

	int size1,num;

	scanf("%d", &size1);

	while(size1 > 0)
	{
		scanf("%d", &num);
		Insert(list, num);
		size1--;
	}
	ReverseList(list, list1);

	ShowList(list);
	ShowList(list1);
	return 0;
}