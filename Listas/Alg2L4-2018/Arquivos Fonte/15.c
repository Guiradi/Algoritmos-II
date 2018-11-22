/*15 A expressão em C, m % n, resulta o resto de m ao dividir n. Defina o máximo divisor comum
(MDC) de dois inteiros, x e y, por:
mdc(x,y) = y, se (y <= x) e (x % y = 0)
mdc(x,y) = mdc(y,x), se (x < y)
mdc(x,y) = mdc(y,x % y),caso contrário
Escreva uma função recursiva para calcular mdc(x,y). Descubra um método iterativo para
calcular essa função*/

#include <stdio.h>
#include <stdlib.h>

int troca(int *x, int *y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}

int mdc(int a, int b)
{
	int x = a, y = b;
	if (x < y)
		troca(&x,&y);
	if (x % y == 0)
		return y;
	else
		return mdc(y, x % y);
}

int mdc_iterativo(int a, int b)
{
	int x = a, y = b;
	if (x < y)
		troca(&x,&y);
	while (x % y != 0)
	{
		troca(&x,&y);
		y = y % x;
	} 
	return y;
		
}

int main()
{
	int x, y;
	printf("Digite x e y para calcular o MDC = ");
	scanf("%d %d", &x, &y);
	printf("MDC (metodo recursivo) de %d e %d = %d", x, y, mdc(x,y));
	printf("\nMDC (metodo iterativo) de %d e %d = %d", x, y, mdc_iterativo(x,y));
}
