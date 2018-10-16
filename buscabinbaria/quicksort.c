#include <stdio.h>

void Imprimir(int *v, int inicio , int fim)
{
	if(inicio == fim){
		return;
	}else{
		printf("%d ", v[inicio]);
		Imprimir(v, inicio+1,fim);
	}
}
void Troca(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}
void Esquerda_Direita(int *v, int *i, int *j, int inicio, int fim, int pivo)
{	
	if(*i > *j){
		return;
	}else{

		if(v[*i] < pivo && *i < fim){
			*i = *i+1;
			Esquerda_Direita(v,i,j,inicio, fim, pivo);
		}
		if(v[*j] > pivo && *j > inicio){
			*j= *j-1;
			Esquerda_Direita(v, i, j,inicio,fim, pivo);
		}
		if(*i <= *j)
		{
			Troca(&v[*i], &v[*j]);
			*i = *i+1;
			*j = *j-1;
			Esquerda_Direita(v,i,j,inicio,fim,pivo);
		}
	}
}
void QuickSort(int *v, int inicio, int fim)
{
	int i = inicio;
	int j = fim-1;
	int pivo = v[(inicio+fim)/2];

	Esquerda_Direita(v,&i,&j,inicio, fim, pivo);
	
	Imprimir(v, inicio, fim);
	printf("\n");
	
	if(j > inicio){
		QuickSort(v, inicio,j+1);
	}
	if(i < fim){
		QuickSort(v, i, fim);
	}
}
int main()
{
	int MAX;
	scanf("%d", &MAX);
	int vetor[MAX];
	int i = 0, j = MAX-1, k;

	for(k=0;k<MAX;k++)
	{
		scanf("%d", &vetor[k]);
	}

	QuickSort(vetor,0,MAX);
	Imprimir(vetor, 0,MAX-1);
	printf("\n");

	return 0;
}