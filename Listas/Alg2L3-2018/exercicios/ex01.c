#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *arquivo;
	char filename[81], texto[81], tipo[4];
	
	printf("Digite o nome do arquivo que voce deseja ler: ");
	gets(filename);
	strcat(filename,".txt");
	
	if ((arquivo = fopen(filename,"r")) == NULL)
	{
		printf("Erro na abertura do arquivo.");
		exit(1);
	}
	
	while(fgets(texto,80,arquivo) != NULL)
		printf("%s", texto);
	
	fclose (arquivo);
	
	system("pause>>null");
	return 0;
}