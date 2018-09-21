/*7 PRODUTO
a) Escreva uma função iterativa para calcular o produto a*b usando adição, onde a e b são inteiros
não negativos.
b) Refaça o item anterior de maneira recursiva.*/

#include <stdio.h>
#include <stdlib.h>

int produto_iterativo(int a, int b)
{
	int i, produto = 0;
	for (i = 0; i < b; i++)
		produto += a;
	return produto;
}

int produto_recursivo(int a, int b)
{
	if (b == 1)
		return a;
	else
		return a + produto_recursivo(a, b-1);
}

int main()
{
	int a, b;
	printf("Digite dois inteiros nao negativos: ");
	scanf("%d %d", &a, &b);
	printf("\n%d x %d (metodo iterativo): %d", a, b, produto_iterativo(a,b));
	printf("\n%d x %d (metodo recursivo): %d", a, b, produto_recursivo(a,b));
	system("pause>>null");
}
