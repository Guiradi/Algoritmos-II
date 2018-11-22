// Vetor v = [20, 12, 28, 05, 10, 18]

#include <stdio.h>
#include <stdlib.h>

void mostra_vetor(int v[], int n)
{
	int i;
	printf("\n\nV =");
	for (i = 0; i < n; i++)
	{
		if (i == n-1)
			printf(" %d.", v[i]);
		else 
			printf(" %d,", v[i]);
	}
}

void troca(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}


void insert_sort (int v[], int n)
{
	int i, j, aux, cont = 0;
	for (i = 1; i < n; i++)
	{
		aux = v[i];
		for (j = i-1; j >= 0 && aux < v[j]; j--)
			v[j + 1] = v[j];
		v[j + 1] = aux;
		mostra_vetor(v,n);
		printf("\tIteracao %d", ++cont);
	}
}

void select_sort(int v[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)
		for (j = i + 1; j < n; j++)
			if (v[j] < v[i])
				troca(&v[j], &v[i]);
}

void bubble_sort(int v[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if(v[j] > v[j+1])
				troca(&v[j+1], &v[j]);
}

int main()
{
	int n = 6;
	int v[6] = {20, 12, 28, 05, 10, 18};
	
	mostra_vetor(v,n);
	//insert_sort(v,n);
	//select_sort(v,n);
	bubble_sort(v,n);
	mostra_vetor(v,n);
	system("pause>>null");
}
