#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

/***** CONSTANTES *****/
#define MAXUSER 30 //Qtde máxima de usuários que podem ser cadastrados para utilizar o programa

/***** STRUCT DE LOGIN *****/
typedef struct {
	char login[32];
	char senha[32];
	char nome_cliente[32];
} user;

/***** VARIÁVEIS GLOBAIS *****/
int usuario = 0; 			// variável que controlará os registros de usuários
int usuario_logado = -1; 	// variável que armazena o correspondente ao usuário logado
user cadastro[MAXUSER];		// cria possibilidades para 30 cadastros
/*notas de B$100,00, B$50,00, B$20,00, B$10,00, B$5,00 e B$2,00 e, moedas de B$1,00, B$0,50, B$0,25, B$0,10 e B$0,01. */
int saque_nota[7] = {100, 50, 20, 10, 5, 2, 1};
int saque_moeda[4] = {50, 25, 10, 1};
/* CHEQUE */
char extenso[255];

/***** CADASTRO *****/
int fazcadastro()
{
	fflush(stdin);
	printf("CADASTRO - NOVO CLIENTE\n\n");
	int i = usuario;
	usuario++;
	printf("Digite seu nome: ");
	gets((cadastro[i]).nome_cliente);
	printf("Digite um nome de usuário: ");
	gets((cadastro[i]).login);
	do{
		printf("Digite uma senha [8 a 32 digitos]: ");
		gets((cadastro[i]).senha);
	} while(strlen((cadastro[i]).senha)<8 || strlen((cadastro[i]).senha)>32);
	printf("\n\nCadastro concluído com sucesso!\n");
	system("pause");
	return 0;
}

/***** LOGIN *****/
int login(){
	system("cls");
	printf("LOGIN\n\n");
	int i, senha = 1, tentativa = 0;
	char ver_user[32], ver_senha[32];
	fflush(stdin);
	do{
		printf("Usuário: ");
		gets(ver_user);
		for (i = 0; i < usuario; i++)
			if(stricmp(ver_user,cadastro[i].login)==0)
				usuario_logado = i;
		if(usuario_logado == -1 && tentativa < 2)
		{
			tentativa++;
			printf("[ERRO] Usuário Inválido [%d]\n", tentativa);
		} else if (tentativa == 2)
			{
				printf("[ERRO] Usuário Inválido [%d]\n", tentativa+1);
				return 0;	
			}
	}while (usuario_logado == -1);
	
	tentativa = 0;
	do{
		printf("Senha: ");
		gets(ver_senha);
		if(stricmp(ver_senha,cadastro[usuario_logado].senha) != 0 && tentativa < 2)
		{
			tentativa++;
			printf("[ERRO] Senha inválida [%d]\n", tentativa);
		} else if (tentativa == 2)
			{
				printf("[ERRO] Senha inválida [%d]\n", tentativa+1);
				usuario_logado = -1;
				return 0;
			} else
					senha = 0;
	}while (senha);
	printf("\n\nSessão iniciada!\nSeja Bem vindo, %s\n",cadastro[usuario_logado].nome_cliente);
	system("pause");
	system("cls");
	return 1;
}

/***** SAQUE *****/
int saque()
{
	system("cls");
	int notas[7]={0,0,0,0,0,0,0}; 			// conta quanto será sacado de notas de 100 até moedas de 1 bit
	int moedas[4]={0,0,0,0}; 				// conta quanto será sacado de moedas de 50 até de 1 centbits
	char intstr[81], money[81];				// variaveis char para leitura do dinheiro
	int nota, moeda, i = 0, j = 0;			// inteiro que receberá as notas, inteiro que receberá as moedas e inteiros i e j para laços for
	fflush(stdin);							// limpa qualquer registro
	printf("Digite o valor do saque: B$ ");	// impressão para digitar saque	
	gets(intstr);							// digita saque
	strcpy(money,intstr);					// salva valor sacado para mostrar depois
	nota = atoi(strtok(intstr, ","));		// transforma lado esquerdo da vírgula no int nota
	moeda = atoi(strtok(NULL, ","));		// transforma lado direito da vírgula no int moeda
	while(nota>=1 && i < 7){				// laço while para contar notas de 100 até moedas de 1 bit
		if(nota - saque_nota[i] > 0)		
		{
			nota -= saque_nota[i];			
			notas[i]++;
		} else
		{
			if (nota - saque_nota[i] == 0)
			{
				nota -= saque_nota[i];
				notas[i]++;
			}
			i++;
		}
	}
	
	while(moeda>=1 && j < 4){				// laço while para contar moedas de 50 até 1 centbit	
		if(moeda - saque_moeda[j] > 0)
		{
			moeda -= saque_moeda[j];
			moedas[j]++;
		} else
		{
			if (moeda - saque_moeda[j] == 0)
			{
				moeda -= saque_moeda[j];
				moedas[j]++;
			}
			j++;
		}
	}
	
	/* IMPRIME VALOR SACADO */
	printf("\n\n\tValor sacado: B$ %s\n", money);
	
	/* IMPRIME NOTAS DE 100 A 2 BITS */
	for (i = 0; i < 6; i++)
	if (notas[i] == 1)
		printf("\t1 nota de B$ %d,00\n", saque_nota[i]);
	else if (notas[i] != 0)
		printf("\t%d notas de B$ %d,00\n", notas[i], saque_nota[i]);	
	
	/* IMPRIME NOTAS DE 1 BIT */
	if (notas[6] == 1)
		printf("\t1 moeda de 1 Bit\n");
	else if (notas[6] != 0)
		printf("\t%d moedas de 1 Bit\n", notas[6]);
	
	/* IMPRIME MOEDAS DE 50 A 1 CENTBIT */
	for (j = 0; j < 4; j++)
	if (moedas[j] == 1)
		printf("\t1 moeda de %d CentBits\n", saque_moeda[j]);
	else if (moedas[j] != 0)
		printf("\t%d moedas de %d CentBits\n", moedas[j], saque_moeda[j]);
	
	system("pause>>null");
	/* ENCERRA O SAQUE */
	return 0;
}

/***** PREENCHER CHEQUES *****/

void centena (int money)
{
	int dinheiro;
	if ((money % 100) != 0)
	{
		dinheiro = money - (money % 100);
		dinheiro /= 100;
		switch (dinheiro)
		{
			case 1: strcat(extenso,"cento e "); break;
			case 2: strcat(extenso,"duzentos e "); break;
			case 3: strcat(extenso,"trezentos e "); break;
			case 4: strcat(extenso,"quatrocentos e "); break;
			case 5: strcat(extenso,"quinhentos e "); break;
			case 6: strcat(extenso,"seiscentos e "); break;
			case 7: strcat(extenso,"setecentos e "); break;
			case 8: strcat(extenso,"oitocentos e "); break;
			case 9: strcat(extenso,"novecentos e "); break;
		}
	}
	else
	{
		dinheiro = money / 100;
		switch (dinheiro)
		{
			case 1: strcat(extenso, "cem "); break;
			case 2: strcat(extenso, "duzentos "); break;
			case 3: strcat(extenso, "trezentos "); break;
			case 4: strcat(extenso, "quatrocentos "); break;
			case 5: strcat(extenso, "quinhentos "); break;
			case 6: strcat(extenso, "seiscentos "); break;
			case 7: strcat(extenso, "setecentos "); break;
			case 8: strcat(extenso, "oitocentos "); break;
			case 9: strcat(extenso, "novecentos "); break;
		}
	}
}

void dezena (int money)
{
	int dinheiro;
	if ((money % 10) != 0 && money > 20)
	{
		dinheiro = money - (money % 10);
		dinheiro /= 10;
		switch (dinheiro)
		{
			case 2: strcat(extenso,"vinte e "); break;
			case 3: strcat(extenso,"trinta e "); break;
			case 4: strcat(extenso,"quarenta e "); break;
			case 5: strcat(extenso,"cinquenta e "); break;
			case 6: strcat(extenso,"sessenta e "); break;
			case 7: strcat(extenso,"setenta e "); break;
			case 8: strcat(extenso,"oitenta e "); break;
			case 9: strcat(extenso,"noventa e "); break;
		}
	}
	else if ((money % 10) == 0 && money > 19)
	{
		dinheiro = money / 100;
		switch (dinheiro)
		{
			case 2: strcat(extenso,"vinte "); break;
			case 3: strcat(extenso,"trinta "); break;
			case 4: strcat(extenso,"quarenta "); break;
			case 5: strcat(extenso,"cinquenta "); break;
			case 6: strcat(extenso,"sessenta "); break;
			case 7: strcat(extenso,"setenta "); break;
			case 8: strcat(extenso,"oitenta "); break;
			case 9: strcat(extenso,"noventa "); break;
		}
	}
	else
	{
		dinheiro = money;
		switch (dinheiro)
		{
			case 10: strcat(extenso, "dez "); break;
			case 11: strcat(extenso, "onze "); break;
			case 12: strcat(extenso, "doze "); break;
			case 13: strcat(extenso, "treze "); break;
			case 14: strcat(extenso, "quatorze "); break;
			case 15: strcat(extenso, "quinze "); break;
			case 16: strcat(extenso, "dezesseis "); break;
			case 17: strcat(extenso, "dezessete "); break;
			case 18: strcat(extenso, "dezoito "); break;
			case 19: strcat(extenso, "dezenove "); break;
		}
	}
}

void unidade (int money)
{
	int dinheiro = money;
	switch (dinheiro)
	{
		case 1: strcat(extenso, "um "); break;
		case 2: strcat(extenso, "dois "); break;
		case 3: strcat(extenso, "três "); break;
		case 4: strcat(extenso, "quatro "); break;
		case 5: strcat(extenso, "cinco "); break;
		case 6: strcat(extenso, "seis "); break;
		case 7: strcat(extenso, "sete "); break;
		case 8: strcat(extenso, "oito "); break;
		case 9: strcat(extenso, "nove "); break;
	}
}

void ler (int money, int i)
{
	int unid, deze, cente;
	cente = money;
	deze = money % 100;
	unid = deze % 10;
	if (money >= 100)
	centena(cente);
	dezena(deze);
	unidade(unid);
	switch(i)
	{
		case 0:
			if (money > 1)
				strcat(extenso, "bitCents");
			else
				strcat(extenso, "bitCent");
			break;
		case 1:
			if (money > 1)
				strcat(extenso, "bits");
			else
				strcat(extenso, "bit");
			break;
		case 2:
			strcat(extenso, "mil ");
			break;
		case 3:
			if (money > 1)
				strcat(extenso, "milhões");
			else
				strcat(extenso, "milhão");
			break;
		case 4:
			if (money > 1)
				strcat(extenso, "bilhões");
			else
				strcat(extenso, "bilhão");
			break;			
	}
}

int cheque(){
	system("cls");
	strcpy(extenso,"");
	int nota, moeda, leitura, flag = 0;
	int unidade, dezena, centena;
	char intstr[81], money[81];
	fflush(stdin);								// limpa qualquer registro
	printf("Digite o valor do cheque: B$ ");	// impressão para digitar cheque
	gets(intstr);								// digita cheque
	strcpy(money,intstr);						// salva valor do cheque
	nota = atoi(strtok(intstr, ","));			// transforma lado esquerdo da vírgula no int nota
	moeda = atoi(strtok(NULL, ","));			// transforma lado direito da vírgula no int moeda
	
	// moeda = 0 / até 999 = 1 / mil = 2 / milhão = 3 / bilhão = 4
	
	if(nota >= 1000000000)
	{
		leitura = nota - (nota % 1000000000);
		leitura = leitura / 1000000000;
		nota = nota % 1000000000;
		ler (leitura, 4);
		flag = 1;
	}
	
	if(nota >= 1000000)
	{
		if (flag == 1)
		strcat(extenso, ", ");
		leitura = nota - (nota % 1000000);
		leitura = leitura / 1000000;
		nota = nota % 1000000;
		ler (leitura, 3);
		flag = 1;
	}
	
	if(nota >= 1000)
	{
		if (flag == 1)
		strcat(extenso, ", ");
		leitura = nota - (nota % 1000);
		leitura = leitura / 1000;
		nota = nota % 1000;
		ler (leitura, 2);
		flag = 1;
	}
	
	if(flag == 1 && nota > 0)
	strcat(extenso, ", ");
	ler (nota,1);
	
	if (moeda >= 1)
	{
		strcat(extenso, " e ");
		ler (moeda, 0);
	}
	
	printf("\n\nCheque: %s\n\n", extenso);
		
	system("pause");
	
	return 0;	
}

/***** MENU PRINCIPAL *****/
int menu_principal(){
	int opt;
	do{
		fflush(stdin);
		printf("\t\tMENU PRINCIPAL\n\nUsuário: %s\nO que deseja fazer?\n\n(1) - Sacar Bits\n(2) - Preencher Cheques\n(0) - Sair\n\nOpção: ", cadastro[usuario_logado].nome_cliente);
		scanf("%d",&opt);
			switch(opt){
			case 0:
			{
				usuario_logado = -1;
				system("cls");
				return 0;
			}
			case 1:
			{
				while(saque()) {system("cls");};
				return 1;
			}
			case 2:
			{
				while(cheque()) {system("cls");};
				return 1;
			}
			default:
				system("cls");
				printf("[ERRO] - DIGITE UMA OPÇÃO VÁLIDA!\n\n");
		}
	} while (opt < 0 || opt > 3);
}

/***** MENU INICIAL *****/
int inicio(){
	printf("\t\t\t*****\tWEBLANDS BANK\t*****\n\n");
	int opta;
	do{
		fflush(stdin);
		printf("\t\tSeja bem-vindo!\n\n(1) - Efetuar Login\n(2) - Cadastrar-se\n(0) - Sair\n\nOpção: ");
		scanf("%d",&opta);
			switch(opta){
			case 0:
			{
				return 0;
			}
			case 1:
			{
				if (login())
				{
					do {system("cls");} while (menu_principal());
				}
				else
				{
					printf("\n\nLOGIN FALHOU");
					system("pause>>null");
				}
				return 1;
			}
			case 2:
			{
				do {system("cls");} while (fazcadastro());
				return 1;
			}
			default:
				system("cls");
				printf("[ERRO] - DIGITE UMA OPÇÃO VÁLIDA!\n\n");
				return 1;
		}
	} while (opta < 0 || opta > 2);
}

/***** MAIN - PROGRAMA *****/
int main(){
	setlocale(LC_ALL, "portuguese");
	do {system("cls");} while (inicio());
	system("cls");
	printf("O Weblands Bank agradece sua preferência!\nVolte Sempre =D");
	system("pause>>null");
	return 0;
}
