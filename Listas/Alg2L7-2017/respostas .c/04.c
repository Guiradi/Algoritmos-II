#include <stdio.h>
#include <stdlib.h>

int Insercao (int n, float *vet) 
{
	float aux;
	int i, j;
	for (i = 1; i < n; i++) 
	{
		aux = vet[i];
		j = i - 1;
	
		while (j >= 0 && aux > vet[j] ) 	//inverte a comparação
		{
			vet[j+1] = vet[j];
			j = j - 1;
		}
		vet[j+1] = aux;
	}
}

void mostra_vetor(float v[], int n)
{
	int i;
	printf("\n\nV =");
	for (i = 0; i < n; i++)
	{
		if (i == n-1)
			printf(" %.2f.", v[i]);
		else 
			printf(" %.2f,", v[i]);
	}
}

int main()
{
	int n = 6;
	float v[6] = {20, 12, 28, 05, 10, 18};
	
	mostra_vetor(v,n);
	Insercao(n,v);
	mostra_vetor(v,n);
	
	system("pause>>null");
	return 0;	
}
