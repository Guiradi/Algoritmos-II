#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long int dectobin(int valor)
{
	if (valor == 0)
		return 0;
	
	return dectobin(valor/2)*10 + valor%2;
}



int main()
{
	char binario[8];
	int dec[10], i;
	FILE *arquivo;
	
	if ((arquivo = fopen("binario.txt", "w")) == NULL)
	{
		printf("Nao foi possivel abrir o arquivo");
		exit(1);
	}
	
	for (i = 0; i < 10; i++)
	{
		printf("Digite um inteiro [%d de 10]: ", i+1);
		scanf("%d", &dec[i]);
	}
	
	for (i = 0; i < 10; i++)
	{
		itoa(dectobin(dec[i]), binario, 10);
		fputs(binario,arquivo);
		putc('\n',arquivo);
	}
	
	printf("Pronto!");
	
	fclose(arquivo);
	//system("pause>>null");
	return 0;
}
