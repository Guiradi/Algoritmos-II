/*19 Faça uma função recursiva para somar os elementos de um vetor por bisseção. Utilize reprocessamento
no programa principal.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 30

int soma_bissec(int v[MAX], int a, int b)
{
	if ( a == b )
		return v[a];
	return soma_bissec( v, a, (floor((a+b)/2)) ) + soma_bissec(v, (floor((a+b)/2))+1, b);
}

int main()
{
	int v[MAX], n, i;
	char resp;
	do
	{
		system("cls");
		printf("Digite a qtde de elementos do vetor: ");
		scanf("%d", &n);
		for(i = 1; i <= n; i++)
		{
			printf("v[%d]: ", i);
			scanf("%d", &v[i]);
		}
		printf("Soma dos elementos por bissecao: %d", soma_bissec(v,1,n));
		printf("\n\nDeseja repetir a operacao (s/n)?\n");
		do
		{
			resp = toupper(getch());
		} while (resp != 'S' && resp != 'N');
	} while (resp != 'N');
	return 0;
}
