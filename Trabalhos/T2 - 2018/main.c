// Programa de 5 campos: Programa para registrar cach�s de atra��es. Campos: Nome, Tipo de Artista, N�mero de Integrantes, Valor do Cach� e Data da �ltima cota��o.
// CRIAR, ALTERAR, EXCLUIR E CONSULTAR CAMPOS
// Consultar arquivos de uma determinada pasta
// Trocar o nome e remover arquivos do disco
// Criar e alterar nome de pastas
// mudar um arquivo de pasta
// alterar data e hor�rio do sistema
// arquivo de ajuda pela tecla F1

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
//#include <windows.h>
//#include <DOS.h>

/*===DEFINES===*/
#define f1 59 // f1 na tabela ASCII
/*==STRUCTS==*/
typedef struct 
{
	char nome[81], tipo[81];
	int membros, dia, mes, ano;
	float valor;
	int ativo;
} info;

typedef struct
{
	info dados;
	int num;	
} reg;
/*==VARI�VEIS GLOBAIS==*/
reg session;

void menu();
/*==FUN��O CRIAR==*/
void create()
{
	FILE *arquivo;
	char add;
	char inttostr[81];
	if ((arquivo = fopen ("database", "a+b")) == NULL) // Acrescenta dados ou cria uma arquivo bin�rio para leitura e escrita.
	{
		system("cls");
		printf("O arquivo n�o pode ser aberto.");
		system("pause");
		menu();
	}
	do
	{
		fflush(stdin);
		fflush(arquivo);
		session.num++; //verificar se come�a em 0
		system("cls");
		printf("\t\tNOVO REGISTRO\n\n");
		printf("Nome da atra��o: ");
		gets(session.dados.nome);
		printf("Tipo de atra��o: ");
		gets(session.dados.tipo);
		printf("N�mero de integrantes: ");
		gets(inttostr);
		session.dados.membros = atoi(inttostr);
		printf("Valor da atra��o(utilize o '.' ao inv�s da ',' ): R$ ");
		gets(inttostr);
		session.dados.valor = atof(inttostr);
		printf("Data da cota��o (dd/mm/aa): ");
		scanf("%d/%d/%d", &session.dados.dia, &session.dados.mes, &session.dados.ano);
		session.dados.ativo = 1;
		fwrite(&session, sizeof(session), 1, arquivo);
		printf("\n\nFazer outro registro agora? (s/n): ");
		do
		{
			add = toupper(getch());
		} while ((add != 'S') && (add != 'N'));
	} while (add != 'N');
	fclose(arquivo);
	menu();
}
/*==FUN��O ALTERAR==*/
void update()
{
	FILE *arquivo;
	if ((arquivo = fopen ("database", "r+b")) == NULL) // Abre um arquivo bin�rio para leitura e escrita.
	{
		system("cls");
		printf("O arquivo n�o pode ser aberto.");
		system("pause");
		menu();
	}
	char add, opt, inttostr[81];
	int docvazio = 1, id = 0, num;
	do
	{
		system("cls");
		fflush(stdin);
		printf("\t\tREGISTROS:\n\n");
		printf("ID\tAtra��o\t\t\tData de Cota��o");
		rewind(arquivo);
		while(fread(&session,sizeof(reg),1,arquivo) != 0)
			{
				if (session.dados.ativo)
				{
					printf("\n%d\t%s\t\t%d/%d/%d", id+1, session.dados.nome, session.dados.dia, session.dados.mes, session.dados.ano);
					docvazio = 0;
					id++;
				}		
			}
		if (docvazio)
		{
			printf("\n\nNenhuma atra��o registrada.");
			system("pause >> null");
			menu();
		}
		printf("\n\nAlterar o registro (1 a %d): ", id);
		scanf("%d", &num);
		do
		{
			system("cls");
			printf("Dados do Registro %d", num);
			id = num - 1; 
			fseek(arquivo, id*sizeof(reg), SEEK_SET);
			fread(&session, sizeof(reg), 1, arquivo);
			printf("\na) Nome da atra��o:\t\t%s", session.dados.nome);
			printf("\nb) Tipo de atra��o:\t\t%s", session.dados.tipo);
			printf("\nc) N�mero de integrantes:\t%d", session.dados.membros);
			printf("\nd) Valor do cach�:\t\tR$ %.2f", session.dados.valor);
			printf("\ne) Data de modifica��o:\t\t%d/%d/%d", session.dados.dia, session.dados.mes, session.dados.ano);
			printf("\nf) sair");
			printf("\n\nOp��o: ");
			do
			{
				opt = toupper(getch());
			} while (opt < 65 && opt > 70); // A at� F na tabela ASCII
			fflush(stdin);
			switch (opt)
			{
				case 65:
					printf("\n\n(Modifica) Nome da atra��o: ");
					gets(session.dados.nome);
					break;
				case 66:
					printf("\n\n(Modifica) Tipo de atra��o: ");
					gets(session.dados.tipo);
					break;
				case 67:
					printf("\n\n(Modifica) N�mero de integrantes: ");
					gets(inttostr);
					session.dados.membros = atoi(inttostr);
					break;
				case 68:
					printf("\n\n(Modifica) Valor do cach�: R$ ");
					gets(inttostr);
					session.dados.valor = atof(inttostr);
					break;
				case 69:
					printf("\n\n(Modifica) Data de modifica��o: ");
					scanf("%d/%d/%d", &session.dados.dia, &session.dados.mes, &session.dados.ano);
					break;
			}
			fseek(arquivo, id*sizeof(reg), SEEK_SET);
			fwrite(&session, sizeof(reg), 1, arquivo);
			printf("\n\nAltera��o Conclu�da\n");
			system("pause");
		} while (opt != 70);
	printf("\n\nFazer outra altera��o agora? (s/n): ");
		do
		{
			add = toupper(getch());
		} while ((add != 'S') && (add != 'N'));
	} while (add != 'N');
	fclose(arquivo);
	menu();	
}
/*==FUN��O CONSULTAR==*/
void read()
{
	FILE *arquivo;
	char add, type, string[81];
	float value;
	int ok = 0;
	if ((arquivo = fopen ("database", "rb")) == NULL) // Abre um arquivo bin�rio para leitura.
	{
		system("cls");
		printf("O arquivo n�o pode ser aberto.");
		system("pause");
		menu();
	}
	fflush(stdin);
	system("cls");
	printf("Pesquisar Atra��o:");
	printf("\n\na. por nome");
	printf("\nb. por tipo");
	printf("\nc. por valor");
	printf("\nd. voltar\n");
	printf("\n\nOp��o: ");
	do
	{
		type = toupper(getch());
	} while(type < 65 && type > 68);
	switch(type)
	{
		case 65:
			//Pesquisa por Nome
			system("cls");
			printf("Pesquisa por nome\n\nDigite o nome da atra��o: ");
			gets(string);
			while(fread(&session,sizeof(reg),1,arquivo) != 0)
			{
				if(strcmp(session.dados.nome, string) == 0 && session.dados.ativo == 1)
				{
					printf("\nNome da atra��o:\t\t%s", session.dados.nome);
					printf("\nTipo de atra��o:\t\t%s", session.dados.tipo);
					printf("\nN�mero de integrantes:\t\t%d", session.dados.membros);
					printf("\nValor do cach�:\t\t\tR$ %.2f", session.dados.valor);
					printf("\nData de modifica��o:\t\t%d/%d/%d\n\n", session.dados.dia, session.dados.mes, session.dados.ano);
					ok = 1;
				}
			}
			if (ok == 0)
			printf("Nenhum resultado para a pesquisa: %s\n\n", string);
			system("pause");
			fclose(arquivo);
			menu();	
			break;
		case 66:
			//Pesquisa por Tipo
			system("cls");
			printf("Pesquisa por tipo\n\nDigite o tipo de atra��o: ");
			gets(string);
			while(fread(&session,sizeof(reg),1,arquivo) != 0)
			{
				if(strcmp(session.dados.tipo, string) == 0 && session.dados.ativo == 1)
				{
					printf("\nNome da atra��o:\t\t%s", session.dados.nome);
					printf("\nTipo de atra��o:\t\t%s", session.dados.tipo);
					printf("\nN�mero de integrantes:\t\t%d", session.dados.membros);
					printf("\nValor do cach�:\t\t\tR$ %.2f", session.dados.valor);
					printf("\nData de modifica��o:\t\t%d/%d/%d\n\n", session.dados.dia, session.dados.mes, session.dados.ano);
					ok = 1;
				}
			}
			if (ok == 0)
			printf("Nenhum resultado para a pesquisa: %s\n\n", string);
			system("pause");
			fclose(arquivo);
			menu();
			break;
		case 67:
			//Pesquisa por Valor
			system("cls");
			printf("Pesquisa por valor\n\nAtra��es de valor at�: R$ ");
			gets(string);
			value = atof(string);
			while(fread(&session,sizeof(reg),1,arquivo) != 0)
			{
				if(value >= session.dados.valor && session.dados.ativo == 1)
				{
					printf("\nNome da atra��o:\t\t%s", session.dados.nome);
					printf("\nTipo de atra��o:\t\t%s", session.dados.tipo);
					printf("\nN�mero de integrantes:\t\t%d", session.dados.membros);
					printf("\nValor do cach�:\t\t\tR$ %.2f", session.dados.valor);
					printf("\nData de modifica��o:\t\t%d/%d/%d\n\n", session.dados.dia, session.dados.mes, session.dados.ano);
					ok = 1;
				}
			}
			if (ok == 0)
			printf("Nenhum resultado para a pesquisa: %s\n\n", string);
			system("pause");
			fclose(arquivo);
			menu();	
			break;
		case 68:
			menu();
			break;
	}
}
/*==FUN��O EXCLUIR==*/
void delet()
{
	FILE *arquivo, *arquivo_aux;
	char opt, add;
	char exclusao[10] = "excluir";
	int id = 0, num, docvazio = 1;
	if ((arquivo = fopen ("database", "r+b")) == NULL) // Abre um arquivo bin�rio para leitura e escrita.
	{
		system("cls");
		printf("O arquivo n�o pode ser aberto.");
		system("pause");
		menu();
	}
	if ((arquivo_aux = fopen ("database_aux", "wb")) == NULL) // Cria um arquivo bin�rio para escrita.
	{
		system("cls");
		printf("O arquivo n�o pode ser aberto.");
		system("pause");
		menu();
	}
	fflush(stdin);
	system("cls");
	printf("\t\tREGISTROS:\n\n");
	printf("ID\tAtra��o\t\t\tData de Cota��o");
	rewind(arquivo);
	while(fread(&session,sizeof(reg),1,arquivo) != 0)
		{
			//if (session.dados.ativo == 1)
			//{
				printf("\n%d\t%s\t\t%d/%d/%d", id+1, session.dados.nome, session.dados.dia, session.dados.mes, session.dados.ano);
				docvazio = 0;
				id++;
			//}		
		}
	if (docvazio)
	{
		printf("\n\nNenhuma atra��o registrada.");
		system("pause >> null");
		menu();
	}
	printf("\n\nAlterar o registro (1 a %d): ", id);
	scanf("%d", &num);
	fflush(arquivo);
	system("cls");
	printf("Dados do Registro %d", num);
	id = num - 1; 
	fseek(arquivo, id*sizeof(reg), SEEK_SET);
	fread(&session, sizeof(reg), 1, arquivo);
	printf("\nNome da atra��o:\t\t%s", session.dados.nome);
	printf("\nTipo de atra��o:\t\t%s", session.dados.tipo);
	printf("\nN�mero de integrantes:\t\t\t%d", session.dados.membros);
	printf("\nValor do cach�:\t\t\tR$ %.2f", session.dados.valor);
	printf("\nData de modifica��o:\t\t%d/%d/%d", session.dados.dia, session.dados.mes, session.dados.ano);
	printf("\n\na. Deletar da lista\nb. Deletar do arquivo\nc. Cancelar e Voltar");
	printf("\n\nOp��o: ");
	fflush(stdin);
	do
	{
		opt = toupper(getch());
	} while (opt < 65 || opt > 67); // A at� F na tabela ASCII
	switch(opt)
	{
		case 65:
			fseek(arquivo, id*sizeof(reg), SEEK_SET);
			session.dados.ativo = 0;
			if(fwrite(&session, sizeof(reg), 1, arquivo) == 1)
			{
				printf("\n\nRegistro Exclu�do da Lista.\n");
				system("pause");
			}
			fclose(arquivo);
			break;
		case 66:
			fseek(arquivo, id*sizeof(reg), SEEK_SET);
			session.dados.ativo = 2;
			rewind(arquivo);
			while (fread(&session, sizeof(reg), 1, arquivo) != 0)
			{
				if (session.dados.ativo || session.dados.ativo == 0)
					fwrite(&session, sizeof(session), 1, arquivo_aux);
			}
			fclose(arquivo);
			fclose(arquivo_aux);
			system("del database");
			system("rename database_aux database");
			printf("\n\nRegistro Exclu�do do arquivo.\n");
			system("pause");
			break;
		case 67:
			menu();
			break;
	}
	printf("\n\nExcluir outro registro? (s/n)\nOp��o: ");
	do
	{
		add = toupper(getch());
	} while ((add != 'S') && (add != 'N'));
	if (add == 'S') 
		delet();
	else 
		menu();
}
/*==FUN��O CONFIG==*/
void config()
{
	//
}
/*==FUN��O HELP==*/
void help()
{
	//
	system("cls");
	printf("help!!");
	system("pause>>null");
}
/*==FUN��O MENU==*/
void menu()
{
	system("cls");
	char pick;
	printf("\t\tGerenciador de Atra��es\n\n");
	printf("\t1. Novo Registro\n");
	printf("\t2. Modificar Registro\n");
	printf("\t3. Consultar Registro\n");
	printf("\t4. Excluir Registro\n");
	printf("\t5. Configura��es do Sistema\n");
	printf("\t6. Sair\n");
	printf("\tF1 - Help\n");
	
	/* Escolha:*/
	do
	{
		printf("\nOp��o: ");
		pick = getch();
		if (pick == f1)
		{
			help();
			menu();	
		}
	} while (pick < 49 || pick > 54); // na tabela ascii, representam respectivamente o 1 e o 6
	
	/* Chamada */
	switch(pick)
	{
		case 49: //1
			create();
			break;
		case 50: //2
			update();
			break;
		case 51: //3
			read();
			break;
		case 52: //4
			delet();
			break;
		case 53: //5
			config();
			break;
		case 54: //6
			system("cls");
			printf("Obrigado por usar o sistema!");
			printf("\nCriado por: Guilherme Ferreira");
			system("pause>>null");
			exit(1);
			break;
	}
}
/*==FUN��O MAIN==*/
int main()
{
	setlocale(LC_ALL, "portuguese");
	menu();
}

