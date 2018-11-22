/*9 EXPONENCIAÇÃO. Escreva uma função recursiva para calcular o valor de n elevado ao expoente
x (n^x), sendo x um número inteiro. Faça um programa, com reprocessamento, que utilize
esta função.*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int exp_recursivo(int n, int x)
{
	if (x == 0)
		return 1;
	if (x == 1)
		return n;
	else
		return n * exp_recursivo (n, x-1);
}

int main()
{
	int x, n;
	char resp;
	do
	{
		system("cls");
		printf("EXPONENCIACAO: ");
		scanf("%d", &n);
		printf("EXPONENCIACAO: %d ^ ", n);
		scanf("%d", &x);
		printf("EXPONENCIACAO: %d ^ %d = %d", n, x, exp_recursivo(n,x));
		do
		{
			printf("\n\nDeseja repetir a operacao (s/n)?\n");
			resp = toupper(getch());
		} while (resp != 'S' && resp != 'N');
	} while (resp != 'N');
}
