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

void quicksort(int values[], int began, int end)
{
	int i, j, pivo, aux;
	i = began;
	j = end-1;
	pivo = values[(began + end) / 2];
	while(i <= j)
	{
		while(values[i] < pivo && i < end)
		{
			i++;
		}
		while(values[j] > pivo && j > began)
		{
			j--;
		}
		if(i <= j)
		{
			aux = values[i];
			values[i] = values[j];
			values[j] = aux;
			i++;
			j--;
		}
		Imprimir(values, began, end);
		printf("\n");
	}
	if(j > began)
		quicksort(values, began, j+1);
	if(i < end)
		quicksort(values, i, end);
}

int main()
{
	int vet[] = {1,5,4,6,3,8,7,2,9,10};
	quicksort(vet,0,10);

	Imprimir(vet, 0, 9);
	return 0;
}