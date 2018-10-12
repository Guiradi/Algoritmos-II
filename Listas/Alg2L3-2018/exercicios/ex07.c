#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *arquivo, *arquivo2, *arquivonovo;
	char filename[81], filename2[81], ch;
	
	
	printf("Digite o nome do primeiro arquivo: ");
	gets(filename);
	if (strstr(filename,".txt") == NULL)
		strcat(filename,".txt");
	
	if ((arquivo = fopen(filename, "r")) == NULL)
	{
		printf("Nao foi possivel abrir o arquivo %s.", filename);
		exit(1);
	}
	
	printf("Digite o nome do segundo arquivo: ");
	gets(filename2);
	if (strstr(filename2,".txt") == NULL)
		strcat(filename2,".txt");
		
	if ((arquivo2 = fopen(filename2, "r")) == NULL)
	{
		printf("Nao foi possivel abrir o arquivo %s.", filename2);
		exit(1);
	}
	
	if ((arquivonovo = fopen("uniaoarquivos.txt", "w")) == NULL)
	{
		printf("Nao foi possivel criar um novo arquivo.");
		exit(1);
	}
	
	while((ch = getc(arquivo)) != EOF)
		putc(ch,arquivonovo);
	putc('\n', arquivonovo);
	
	while((ch = getc(arquivo2)) != EOF)
		putc(ch,arquivonovo);
	
	printf("Pronto irmao, tudo certo");
	
	exit(1);
	system("pause>>null");
	return 0;
	
}
