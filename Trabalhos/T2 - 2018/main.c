// Programa de 5 campos: Programa para registrar cachês de atrações. Campos: Nome, Tipo de Artista, Número de Integrantes, Valor do Cachê e Data da última cotação.
// CRIAR, ALTERAR, EXCLUIR E CONSULTAR CAMPOS
// Consultar arquivos de uma determinada pasta
// Trocar o nome e remover arquivos do disco
// Criar e alterar nome de pastas
// mudar um arquivo de pasta
// alterar data e horário do sistema
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
/*==VARIÁVEIS GLOBAIS==*/
reg session;

void menu();
/*==FUNÇÃO CRIAR==*/
void create()
{
	FILE *arquivo;
	char add;
	char inttostr[81];
	if ((arquivo = fopen ("database", "a+b")) == NULL) // Acrescenta dados ou cria uma arquivo binário para leitura e escrita.
	{
		system("cls");
		printf("O arquivo não pode ser aberto.");
		system("pause");
		menu();
	}
	do
	{
		fflush(stdin);
		fflush(arquivo);
		session.num++; //verificar se começa em 0
		system("cls");
		printf("\t\tNOVO REGISTRO\n\n");
		printf("Nome da atração: ");
		gets(session.dados.nome);
		printf("Tipo de atração: ");
		gets(session.dados.tipo);
		printf("Número de integrantes: ");
		gets(inttostr);
		session.dados.membros = atoi(inttostr);
		printf("Valor da atração(utilize o '.' ao invés da ',' ): R$ ");
		gets(inttostr);
		session.dados.valor = atof(inttostr);
		printf("Data da cotação (dd/mm/aa): ");
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
/*==FUNÇÃO ALTERAR==*/
void update()
{
	FILE *arquivo;
	if ((arquivo = fopen ("database", "r+b")) == NULL) // Abre um arquivo binário para leitura e escrita.
	{
		system("cls");
		printf("O arquivo não pode ser aberto.");
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
		printf("ID\tAtração\t\t\tData de Cotação");
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
			printf("\n\nNenhuma atração registrada.");
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
			printf("\na) Nome da atração:\t\t%s", session.dados.nome);
			printf("\nb) Tipo de atração:\t\t%s", session.dados.tipo);
			printf("\nc) Número de integrantes:\t%d", session.dados.membros);
			printf("\nd) Valor do cachê:\t\tR$ %.2f", session.dados.valor);
			printf("\ne) Data de modificação:\t\t%d/%d/%d", session.dados.dia, session.dados.mes, session.dados.ano);
			printf("\nf) sair");
			printf("\n\nOpção: ");
			do
			{
				opt = toupper(getch());
			} while (opt < 65 && opt > 70); // A até F na tabela ASCII
			fflush(stdin);
			switch (opt)
			{
				case 65:
					printf("\n\n(Modifica) Nome da atração: ");
					gets(session.dados.nome);
					break;
				case 66:
					printf("\n\n(Modifica) Tipo de atração: ");
					gets(session.dados.tipo);
					break;
				case 67:
					printf("\n\n(Modifica) Número de integrantes: ");
					gets(inttostr);
					session.dados.membros = atoi(inttostr);
					break;
				case 68:
					printf("\n\n(Modifica) Valor do cachê: R$ ");
					gets(inttostr);
					session.dados.valor = atof(inttostr);
					break;
				case 69:
					printf("\n\n(Modifica) Data de modificação: ");
					scanf("%d/%d/%d", &session.dados.dia, &session.dados.mes, &session.dados.ano);
					break;
			}
			fseek(arquivo, id*sizeof(reg), SEEK_SET);
			fwrite(&session, sizeof(reg), 1, arquivo);
			printf("\n\nAlteração Concluída\n");
			system("pause");
		} while (opt != 70);
	printf("\n\nFazer outra alteração agora? (s/n): ");
		do
		{
			add = toupper(getch());
		} while ((add != 'S') && (add != 'N'));
	} while (add != 'N');
	fclose(arquivo);
	menu();	
}
/*==FUNÇÃO CONSULTAR==*/
void read()
{
	FILE *arquivo;
	char add, type, string[81];
	float value;
	int ok = 0;
	if ((arquivo = fopen ("database", "rb")) == NULL) // Abre um arquivo binário para leitura.
	{
		system("cls");
		printf("O arquivo não pode ser aberto.");
		system("pause");
		menu();
	}
	fflush(stdin);
	system("cls");
	printf("Pesquisar Atração:");
	printf("\n\na. por nome");
	printf("\nb. por tipo");
	printf("\nc. por valor");
	printf("\nd. voltar\n");
	printf("\n\nOpção: ");
	do
	{
		type = toupper(getch());
	} while(type < 65 && type > 68);
	switch(type)
	{
		case 65:
			//Pesquisa por Nome
			system("cls");
			printf("Pesquisa por nome\n\nDigite o nome da atração: ");
			gets(string);
			while(fread(&session,sizeof(reg),1,arquivo) != 0)
			{
				if(strcmp(session.dados.nome, string) == 0 && session.dados.ativo == 1)
				{
					printf("\nNome da atração:\t\t%s", session.dados.nome);
					printf("\nTipo de atração:\t\t%s", session.dados.tipo);
					printf("\nNúmero de integrantes:\t\t%d", session.dados.membros);
					printf("\nValor do cachê:\t\t\tR$ %.2f", session.dados.valor);
					printf("\nData de modificação:\t\t%d/%d/%d\n\n", session.dados.dia, session.dados.mes, session.dados.ano);
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
			printf("Pesquisa por tipo\n\nDigite o tipo de atração: ");
			gets(string);
			while(fread(&session,sizeof(reg),1,arquivo) != 0)
			{
				if(strcmp(session.dados.tipo, string) == 0 && session.dados.ativo == 1)
				{
					printf("\nNome da atração:\t\t%s", session.dados.nome);
					printf("\nTipo de atração:\t\t%s", session.dados.tipo);
					printf("\nNúmero de integrantes:\t\t%d", session.dados.membros);
					printf("\nValor do cachê:\t\t\tR$ %.2f", session.dados.valor);
					printf("\nData de modificação:\t\t%d/%d/%d\n\n", session.dados.dia, session.dados.mes, session.dados.ano);
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
			printf("Pesquisa por valor\n\nAtrações de valor até: R$ ");
			gets(string);
			value = atof(string);
			while(fread(&session,sizeof(reg),1,arquivo) != 0)
			{
				if(value >= session.dados.valor && session.dados.ativo == 1)
				{
					printf("\nNome da atração:\t\t%s", session.dados.nome);
					printf("\nTipo de atração:\t\t%s", session.dados.tipo);
					printf("\nNúmero de integrantes:\t\t%d", session.dados.membros);
					printf("\nValor do cachê:\t\t\tR$ %.2f", session.dados.valor);
					printf("\nData de modificação:\t\t%d/%d/%d\n\n", session.dados.dia, session.dados.mes, session.dados.ano);
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
/*==FUNÇÃO EXCLUIR==*/
void delet()
{
	FILE *arquivo, *arquivo_aux;
	char opt, add;
	char exclusao[10] = "excluir";
	int id = 0, num, docvazio = 1;
	if ((arquivo = fopen ("database", "r+b")) == NULL) // Abre um arquivo binário para leitura e escrita.
	{
		system("cls");
		printf("O arquivo não pode ser aberto.");
		system("pause");
		menu();
	}
	if ((arquivo_aux = fopen ("database_aux", "wb")) == NULL) // Cria um arquivo binário para escrita.
	{
		system("cls");
		printf("O arquivo não pode ser aberto.");
		system("pause");
		menu();
	}
	fflush(stdin);
	system("cls");
	printf("\t\tREGISTROS:\n\n");
	printf("ID\tAtração\t\t\tData de Cotação");
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
		printf("\n\nNenhuma atração registrada.");
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
	printf("\nNome da atração:\t\t%s", session.dados.nome);
	printf("\nTipo de atração:\t\t%s", session.dados.tipo);
	printf("\nNúmero de integrantes:\t\t\t%d", session.dados.membros);
	printf("\nValor do cachê:\t\t\tR$ %.2f", session.dados.valor);
	printf("\nData de modificação:\t\t%d/%d/%d", session.dados.dia, session.dados.mes, session.dados.ano);
	printf("\n\na. Deletar da lista\nb. Deletar do arquivo\nc. Cancelar e Voltar");
	printf("\n\nOpção: ");
	fflush(stdin);
	do
	{
		opt = toupper(getch());
	} while (opt < 65 || opt > 67); // A até F na tabela ASCII
	switch(opt)
	{
		case 65:
			fseek(arquivo, id*sizeof(reg), SEEK_SET);
			session.dados.ativo = 0;
			if(fwrite(&session, sizeof(reg), 1, arquivo) == 1)
			{
				printf("\n\nRegistro Excluído da Lista.\n");
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
			printf("\n\nRegistro Excluído do arquivo.\n");
			system("pause");
			break;
		case 67:
			menu();
			break;
	}
	printf("\n\nExcluir outro registro? (s/n)\nOpção: ");
	do
	{
		add = toupper(getch());
	} while ((add != 'S') && (add != 'N'));
	if (add == 'S') 
		delet();
	else 
		menu();
}
/*==FUNÇÃO CONFIG==*/
void config()
{
	//
}
/*==FUNÇÃO HELP==*/
void help()
{
	//
	system("cls");
	printf("help!!");
	system("pause>>null");
}
/*==FUNÇÃO MENU==*/
void menu()
{
	system("cls");
	char pick;
	printf("\t\tGerenciador de Atrações\n\n");
	printf("\t1. Novo Registro\n");
	printf("\t2. Modificar Registro\n");
	printf("\t3. Consultar Registro\n");
	printf("\t4. Excluir Registro\n");
	printf("\t5. Configurações do Sistema\n");
	printf("\t6. Sair\n");
	printf("\tF1 - Help\n");
	
	/* Escolha:*/
	do
	{
		printf("\nOpção: ");
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
/*==FUNÇÃO MAIN==*/
int main()
{
	setlocale(LC_ALL, "portuguese");
	menu();
}

