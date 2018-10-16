#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ShowGraph(int size, int Graph[][size+1])
{
	int l, c;	
	for (l=0;l<size+1;l++)
	{
		for (c=0;c<size+1;c++)
		{
			printf("%d ", Graph[l][c]);
		}
		printf("\n");
	}
}

void MatrizAdjunta(int s, int Graph[][s+1], int v1, int v2)
{
	Graph[v1][v2] = 1;
}
int main()
{
	int size;
	puts("Informe a Quantidade de vertices:");
	scanf("%d", &size);

	int Graph[size+1][size+1], i, aux = 0, v1, v2;
	memset(Graph,0,sizeof(Graph));


	for(i=0;i<size+1;i++){
		Graph[i][0] = aux;
		Graph[0][i] = aux;
		++aux;
	}
	
	for(i=0;i<size;i++)
	{
		puts("Informe dois vertices:");
		scanf("%d%d", &v1, &v2);
		MatrizAdjunta(size, Graph,v1,v2);
	}	
	ShowGraph(size,Graph);
	return 0;
}