#include <stdio.h>
#include <stdlib.h>

void mostra_vetor(int v[], int n)
{
	int i;
	printf("\n\nVetor: ");
	for (i = 0; i < n-1; i++)
		printf("%d, ", v[i]);
	printf("%d.", v[n-1]);
}

int main()
{
	int v[30], i, n, a, b;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
	{
		printf("V[%d] = ", i+1);
		scanf("%d", &v[i]);
		
		if (i == 0)
		{
			a = v[i];
			b = v[i];
		}
		else
		{
			if (v[i] < a)
				a = v[i];
			if (v[i] > b)
				b = v[i];
		}
	}
	
	int vector[b-a+1], q, j;
	
	for (i = a; i <= b; i++)
	{
		q = 0;
		for (j = 0; j < b-a+1; j++)
			{
				if (v[j] == i) 
					q++;
				vector[j] = 
			}
	}
		
	mostra_vetor(v,n);
	
	system("pause>>null");
	return 0;
}
