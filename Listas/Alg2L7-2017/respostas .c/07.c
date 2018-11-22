#include <stdio.h>
#include <stdlib.h>

void mostra_vetor(int v[], int n)
{
	int i;
	printf("\nVetor:");
	for(i = 0; i < n-1; i++)
		printf(" %d,", v[i]);
	printf(" %d.", v[n-1]);
}

void troca (int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}


int bubble(int v[], int n)
{
	int i, j, trocado = 1, cont = 0;
	
	for (i = 0; i < n-1 && trocado; i++)
	{
		trocado = 0;
		
		for (j = 0; j < n - i - 1; j++)
			
			if (v[j] > v[j+1])
			{
				troca(&v[j],&v[j+1]);
				trocado = 1;
				cont++;
			}
	}
	
	return cont;
}

int main()
{
	int n = 9, modificacoes;
	int v[9] = {9,8,7,6,5,4,3,2,1};
	
	mostra_vetor(v,n);
	modificacoes = bubble(v,n);
	printf("\n\nOrdena vetor:");
	mostra_vetor(v,n);
	printf("\nNumero de alteracoes necessarios: %d", modificacoes);
	
	system("pause>>null");
	return 0;
}
