#include <stdio.h>
#include <string.h>

void P(int *v, int inicio, int tam)
{
  int i;
  for(i=inicio;i<=tam;i++)
  {
    printf("%d ", v[i]);
  }
  printf("\n");
}
int BuscaBinaria(int *v, int incio, int fim, int tam , int valor)
{
  P(v,incio,fim);
  int meio = (incio+fim)/2;

  if(incio > fim){
    return -1;
  }
  else{
    if(valor > v[meio]){
      BuscaBinaria(v,meio+1, fim,tam, valor);
    }
    else if(valor < v[meio]){
      BuscaBinaria(v,incio,meio-1,tam,valor);
    }
    else{
      return meio;
    }
  }
}
int main()
{
  
  int v[] = {5,8,10,60,614,1000,2000};

  printf("%d\n", BuscaBinaria(v,0,6,7,614));    

  return 0;
}