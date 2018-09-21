/*11 Escreva uma função recursiva capaz de inverter uma seqüência de caracteres. Faça um programa,
com reprocessamento, que utilize esta função.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 81

void inverte(char str[MAX])
{
	int i, qtd = strlen(str);
	int j = qtd;
	char rts[MAX];
	for (i = 0; i < qtd; i++)
	{
		j--; // o ultimo caracter é um /0
		rts[j] = str[i];
	}
	strcpy(str, "");
	strcpy(str, rts);
}

void inverte_recursiva(char str[MAX], char rts[MAX], int i, int j)
{
	if (j == 0)
		rts[j] = str[i];
	else
	{
		rts[j] = str[i];
		inverte_recursiva(str,rts, i+1,j-1);
	} 
}

int main()
{
	char str[MAX], rts[MAX], resp;
	do
	{
		strcpy(rts,"");
		system("cls");
		printf("Digite uma sequencia de caracteres: ");
		gets(str);
		inverte_recursiva(str,rts,0,strlen(str)-1);
		printf("Sequencia invertida: %s", rts);	
		printf("\n\nRepetir operacao (s/n)?");
		do
		{
			resp = toupper(getch());
		} while (resp != 'S' && resp != 'N');
	} while (resp != 'N');	
}
