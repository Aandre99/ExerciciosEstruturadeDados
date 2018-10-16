#include <stdio.h>

typedef struct node
{
	int info;
	struct list *next;
}node;

typedef struct list
{
	node *head;
}List;

List *CreateList()
{
	List *newList = (List*)malloc(sizeof(List));
	if(newList == NULL){
		puts("ERROR, CLOSING THE PROGRAM!");
	}
	newList->head = NULL;
	return newList;
}
void InsertList(List *list, int value)
{
	node *newnode = (node*)malloc(sizeof(node));
	if(newnode == NULL){
		puts("ERROR, CLOSING THE PROGRAM!");
	}
	newnode->info = value;

	if(list->head == NULL){
		list->head = newnode;
		newnode->next = newnode;
	}else{

		node *aux = list->head;
		while(aux->next != list->head)
		{
			aux = aux->next;
		}
		aux->next = newnode;
		newnode->next = list->head;
		list->head = newnode;
	}
}
void ClearList(List *list)
{
	if(list->head == NULL){
		free(list);
		return;
	}else{
		node *aux = list->head, *aux2 = NULL;
		while(aux->next != list->head)
		{
			aux2 = aux;
			aux = aux->next;
			free(aux2;)
		}
		free(aux);
		free(list);
	}
}
int main()
{
	return 0;
}