#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *arquivo;
	char ch;
	int upprox = 0;
	
	if ((arquivo = fopen("teste.txt", "r")) == NULL)
	{
		printf("Nao foi possivel abrir o arquivo.");
		exit(1);
	}
	
	while ((ch = getc(arquivo)) != EOF)
	{
		if (upprox == 0)
		{
			printf("%c", toupper(ch));
			upprox = 2;
		}
		else
		{
			if (ch == '.' || ch == ' ' || ch == '\n')
				upprox--;
			else
				upprox = 2;
			printf("%c", tolower(ch));
		}
	}
	
	fclose(arquivo);
	system("pause>>null");
	return 0;
		
}
