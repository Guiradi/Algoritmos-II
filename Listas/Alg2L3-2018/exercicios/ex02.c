#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	// Declaração de variáveis
	FILE *arquivo;
	char ch;
	int contc = 0, contv = 0;
	
	if ( (arquivo = fopen("teste.txt", "r")) == NULL )
	{
		printf("Nao foi possivel efetuar a leitura do arquivo.");
		exit(1);		
	}
	
	while ((ch = getc(arquivo)) != EOF)
	if ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u') || (ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') || (ch == 'U'))
		contv++;
	else
	{
		if ((ch != ' ') && (ch != ','))
			contc++;
	}
	
	printf("Quantidade de vogais no arquivo: %d\nQuantidade de consoantes no arquivo: %d", contv, contc);
	
	fclose(arquivo);
	system("pause>>null");
	return 0;
}
