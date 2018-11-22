#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *arquivo, *arquivonovo;
	char ch, vogal[10], filename[30];
	int i;
	strcpy(vogal,"aeiouAEIOU");
	
	printf("Digite o nome do arquivo: ");
	gets(filename);
	if (strstr(filename,".txt") == NULL)
		strcat(filename,".txt");
	
	if ((arquivo = fopen(filename,"r")) == NULL)
	{
		printf("Nao foi possivel abrir o arquivo %s", filename);
		exit(1);
	}
	
	if ((arquivonovo = fopen("tiravogal.txt","w")) == NULL)
	{
		printf("Nao foi possivel abrir o arquivo tiravogal.txt");
		exit(1);
	}
	
	while((ch = getc(arquivo)) != EOF)
	{
		for (i = 0; i < sizeof(vogal); i++)
			if (ch == vogal[i])
				ch = '*';
		putc(ch,arquivonovo);
	}
	
	printf("Pronto!");
	
	system("pause>>null");
	return 0;
}
