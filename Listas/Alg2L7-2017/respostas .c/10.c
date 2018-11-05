/*Uma ordena��o por contagem de um vetor x de tamanho n � executada da seguinte forma:
declare um vetor count e defina count[i] como o n�mero de elementos menores que x[i]. Em
seguida, coloque x[i] na posi��o count[i] de um vetor de sa�da (leve em considera��o a possibilidade
de elementos iguais). Escreva uma fun��o para ordenar um vetor x de tamanho n
usando esse m�todo.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void mostra_vetor(int v[], int n)
{
	int i;
	printf("\n\nVetor: ");
	for (i = 0; i < n-1; i++)
		printf(" %d,", v[i]);
	printf(" %d.", v[n-1]);
}

int main()
{
	int x[MAX], count[MAX], xsaida[MAX], n, i, j, repete;
	
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		printf("x[%d] =", i+1);
		scanf("%d", &x[i]);
	}
	
	mostra_vetor(x,n);
	
	for (i = 0; i < n; i++)
	{
		count[i] = 0;
		repete = 0;
		for (j = 0; j < n; j++)
		{
			if (x[i] > x[j])
				count[i]++;
			if (x[i] == x[j])
				repete++;
		}
		xsaida[count[i]] = x[i];
		while(repete != 1)
		{
			xsaida[++count[i]] = x[i];
			repete--;
		}
	}
	
	mostra_vetor(xsaida,n);
}
