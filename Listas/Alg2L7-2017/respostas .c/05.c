#include <stdio.h>
#include <stdlib.h>

void insert_sort (int v[], int n)
{
	int i, j, aux, cont = 0;
	for (i = 1; i < n; i++)
	{
		aux = v[i];
		for (j = i-1; j >= 0 && aux > v[j]; j--)
			v[j + 1] = v[j];
		v[j + 1] = aux;
	}
}

int main()
{
	int jogos, placar, N[10000], i;
	
	
	do
	{
		scanf("%d %d", &jogos, &placar);
	} while ((jogos < 1) && (jogos > 10000) && (placar < 1) && (placar > 500) && (placar > jogos));
	
	for (i = 0; i < jogos; i++)
		scanf("%d", &N[i]);
	
	insert_sort( N, jogos);
	printf("\n\nSaida");
	for (i = 0; i < placar; i++)
		printf("\n%d", N[i]);
		
	system("pause>>null");
	return 0;
}
