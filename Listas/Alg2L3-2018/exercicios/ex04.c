#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *arquivo;
	int contpalavras = 0, contlinhas = 1, contcaracteres = 0, comecoupalavra = 0;
	char ch, linha[81], filename[81];
	
	printf("Digite o nome do arquivo que deseja abrir: ");
	gets(filename);
	strcat(filename, ".txt");
	
	if((arquivo = fopen(filename, "r")) == NULL)
	{
		printf("Nao foi possivel abrir o arquivo.");
		exit(1);
	}
	
	while (!feof(arquivo))
	{
		fread(&ch, 1, 1, arquivo);
		contcaracteres++;
		if ((ch != ' ') && (ch != '\n') && (!comecoupalavra))
			comecoupalavra = 1;
		if (((ch == ' ') || (ch == '\n')) && (comecoupalavra))
		{
			comecoupalavra = 0;
			contpalavras++;
		}
		if (contpalavras == 0)
			contlinhas = 0;
		if (ch == '\n')
			contlinhas++;
	}
	fclose(arquivo);
	
	printf("\n\nNumero de caracteres do arquivo: %d\nNumero de palavras do arquivo: %d\nNumero de linhas do arquivo: %d", contcaracteres, contpalavras, contlinhas);
	
	system("pause>>null");
	return 0;
}
