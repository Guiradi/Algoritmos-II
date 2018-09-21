/*13 Faça uma função recursiva que calcule a soma dos quadrados dos N primeiros números positivos.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int soma_quad(int n)
{
	if (n == 1)
		return 1;
	else
		return pow(n,2) + soma_quad(n-1) ;
}

int main()
{
	int n;
	printf("Soma dos quadrados dos N primeiros numeros positivos!");
	do
	{
		printf("\n\nDigite o valor de N: ");
		scanf("%d", &n);
		if (n < 1)
			printf("Tente um valor inteiro positivo:");
	} while (n < 1);
	printf("\nSoma = %d", soma_quad(n));
	system("pause>>null");
}
