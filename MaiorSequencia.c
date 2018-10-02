#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M(x,y) (x>y) ? (x):(y)

typedef struct node
{
	char zero_one;
	int index;
	struct node * next;
}node;

typedef struct list
{
	node *head;
}List;

List * CreateList()
{
	List *list = (List*)malloc(sizeof(List));
	if(list != NULL)
	{
		list->head = NULL;
		return list;
	}
}
void Insert(List *list, char info, int index)
{
	node *new = (node*)malloc(sizeof(node));
	if(new == NULL){
		exit(1);
	}
	new->zero_one = info;
	new->index = index;

	if(list->head == NULL)
	{
		new->next = list->head;
		list->head = new;
	}else{
		node *aux = list->head;

		while(aux->next != NULL)
		{
			aux = aux->next;
		}

		aux->next = new;
		new->next = NULL;
	}
}

void PritList(List *list)
{
	if(list->head == NULL){
		return;
	}
	node *aux = list->head, *aux2;
	while(aux!= NULL)
	{
		aux2 = aux;
		//printf("%c ", aux->zero_one);
		aux = aux->next;
		free(aux2);
	}
	list->head = NULL;
}
void Big_Sequence(List *list, int *inicio, int *fim, int size)
{
	int i,temp=0, diff=0, big = 0;
	node *aux = list->head, *aux2=NULL;

	for(i = aux->index;aux->next != NULL;aux = aux->next)
	{

		if(aux->zero_one == '0')
		{
			temp = aux->index;
			aux2 = aux->next;

			while(aux2->zero_one == '0')
			{
				*fim = M(*fim,aux2->index);
				diff++;
				aux2 = aux2->next;
			}
			big = M(big,diff);
			diff = 0;
		}
	}
	*inicio = *fim - big;
}
int main()
{

	List *list = CreateList();

	int info, i=0, size=0, inicio=0, fim=0;
	char string[100];

	do
	{
		fgets(string,100,stdin);
		size = strlen(string);
		if(size == 1 && string[0] == '0'){
			break;
		}
		for(i=0;i<size;i++)
		{
			Insert(list,string[i],i);
		}
		Big_Sequence(list,&inicio,&fim,size);
		PritList(list);
		printf("%d %d\n", inicio, fim);
		inicio = 0;
		fim = 0;
	}
	while(1);

	return 0;
}