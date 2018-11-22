#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

void quicksort(long int x[], int inicio, int fim)
{
	int i, j, pivo, aux;
	i = inicio;
	j = fim;
	pivo = x[(i+j)/2];
	
	while (i <= j)
	{
		while (x[i] < pivo)
			i = i + 1;
		while (x[j] > pivo)
			j = j - 1;
		if (i <= j)
		{
			aux = x[i];
			x[i] = x[j];
			x[j] = aux;
			i = i + 1;
			j = j - 1;
		}
	}
	
	if (inicio < j)
		quicksort(x, inicio, j);
	if (i < fim)
		quicksort(x, i, fim);	
}


int main()
{
	int i, N, cont = 1, contvencedor = 0, aux;
	long int x[MAX], vencedor;
	do
	{
		scanf("%d", &N);
	} while ((N < 1) && (N > 100000));
	
	for (i = 0; i < N; i++)
		do
		{
			scanf("%ld", &x[i]);
		} while ((x[i] < 1) && x[i] > 1000000000);
		
	quicksort(x, 0, N-1);
	
	for (i = 0; i < N-1; i++)
	{
		if (x[i] == x[i+1])
			cont++;
		else
			cont = 1;
		if (cont > contvencedor)
		{
			contvencedor = cont;
			vencedor = x[i];
		}
	}
	
	printf("\n\nSaida\n%d", vencedor);
	
	system("pause>>null");
	return 0;
}
