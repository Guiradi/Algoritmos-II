/*21 Considere v como um vetor de inteiros. Escreva funções recursivas para calcular:
a) o elemento mínimo do vetor;
b) o elemento máximo do vetor;
c) a soma dos elementos do vetor;
d) o produto dos elementos do vetor;
e) a média dos elementos do vetor.*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 30

int min(int v[MAX], int n)
{
	if (n == 1)
		return v[0];
	else
	{
		int x = min(v,n-1);	
		if (x < v[n-1])
			return x;
		else
			return v[n-1];
	}	
}

int max(int v[MAX], int n)
{
	if (n == 1)
		return v[0];
	else
	{
		int x = max(v, n-1);
		if (x > v[n-1])
			return x;
		else
			return v[n-1];
	}
}	

int soma(int v[MAX], int n)
{
	if (n == 1)
		return v[0];
	return v[n-1] + soma(v,n-1);
}

int produto(int v[MAX], int n)
{
	if (n == 1)
		return v[0];
	return v[n-1] * produto(v,n-1);
}

float media(int v[MAX], int n, int N)
{	
	float x = (float) v[n-1] / N;
	if (n == 1)
		return x;
	return x + media(v,n-1,N);
}

int main()
{
	int v[MAX], n, i;
	printf("Digite a quantidade de elementos do vetor v: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		printf("v[%d]: ", i+1);
		scanf("%d", &v[i]);
	}
	printf("\nElemento minimo do vetor: %d", min(v,n));
	printf("\nElemento maximo do vetor: %d", max(v,n));
	printf("\nA soma dos elementos do vetor e: %d", soma(v,n));
	printf("\nO produto dos elementos do vetor e: %d", produto(v,n));
	printf("\nA media dos elementos do vetor e: %.2f", media(v,n,n));
	system("pause>>null");	
}
