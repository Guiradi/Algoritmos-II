/*3 FATORIAL
a) Escreva uma função iterativa para calcular N! (fatorial de N).
b) Refaça o item anterior de maneira recursiva.
c) Execute a versão recursiva e não-recursiva da função fatorial e, examine quanto tempo
cada uma exige conforme se aumenta o valor de N.
Para n = 5
	Recursivo: 0,7474 s
	Interativo: 0,7147 s
	
Para n = 10
	Recursivo: 0,7972 s
	Interativo: 0,7862 s
*/
#include <stdio.h>
#include <stdlib.h>

/* ITEM A 
int fatorial_interativo(int n)
{
	int fat = n;
	while (n > 1)
	{
		fat *= --n;
	}
	return fat;
}

/* ITEM B 
int fatorial_recursivo(int n)
{
	if (n == 1)
		return 1;
	return n * fatorial_recursivo(n-1);
}

/* MAIN */
int main()
{
	//printf("\nMetodo interativo:\n%d! = %d", 5, fatorial_interativo(5));
	//printf("\nMetodo interativo:\n%d! = %d", 10, fatorial_interativo(10));
	//printf("\n\nMetodo recursivo:\n%d! = %d", 5, fatorial_recursivo(5));
	//printf("\n\nMetodo recursivo:\n%d! = %d", 10, fatorial_recursivo(10));
}
