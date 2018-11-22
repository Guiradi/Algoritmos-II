#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *arquivo;
	char filename[81], palavra[30], aux[30], linha[81], *tok;
	int match = 0, i;
	
	printf("Digite o nome do arquivo que deseja abrir: ");
	gets(filename);
	if (strstr(filename,".txt") == NULL)
		strcat(filename,".txt");
	
	if ((arquivo = fopen(filename, "r")) == NULL)
	{
		printf("Nao foi possivel abrir o arquivo selecionado.");
		exit(1);
	}
	
	printf("Digite uma palavra para pesquisar no arquivo %s: ", filename);
	gets(aux);
	for (i = 0; i < sizeof(aux); i++)
		palavra[i] = tolower(aux[i]);
	
	while (fgets(linha,80,arquivo) != NULL)
	{
		tok = strtok(linha, " ");
		while (tok != NULL)
		{
			if (!strcmp(tok,palavra))
				match++;
			tok = strtok(NULL," ");
		}
	}
	
	printf("Numero de vezes em que aparece a palavra %s: %d", palavra,match);
	
	system("pause>>null");
	return 0;	
}
