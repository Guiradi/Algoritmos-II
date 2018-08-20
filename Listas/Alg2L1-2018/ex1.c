/*Defina uma estrutura que represente bandas de m�sica. Essa estrutura deve ter o nome
da banda, que tipo de m�sica ela toca, o n�mero de integrantes e em que posi��o
do ranking essa banda est� dentre as suas cinco bandas favoritas. Se a banda n�o estiver
tiver entre suas cinco bandas favoritas, utilize o n�mero zero neste campo. Em seguida,
desenvolva as fun��es que seguem:
a) Fa�a uma fun��o que cadastre um determinado n�mero de bandas. A quantidade de
bandas a serem cadastradas deve ser fornecida pelo usu�rio. As bandas devem ser
armazenadas em um vetor em que cada elemento � uma estrutura conforme definido
anteriormente.
b) Fa�a uma fun��o que fa�a uma busca de acordo com o ranking da banda. Essa fun��o
deve exibir todas as informa��es da banda de um determinado ranking.
c) Crie uma fun��o que solicite ao usu�rio um tipo de m�sica e exiba as bandas com
esse tipo de m�sica no seu ranking.
d) Crie uma fun��o que solicite o nome de uma banda ao usu�rio e informe se ela est�
entre suas bandas favoritas ou n�o*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 30

typedef struct {
	char nome[30], tipo[25];
	int integrantes, ranking;
} banda;

banda bandas[MAX];
int qtde_banda;
//----------------------------------
void menu (char *opcao) {
	system("cls");
	printf ("--------------------------------------------------------");   
    printf ("\n M E N U");     
    printf ("\n[1] - Cadastrar bandas");
    printf ("\n[2] - Buscar de bandas por ranking");
    printf ("\n[3] - Buscar bandas por tipo de musica");
    printf ("\n[4] - Verificar se a banda esta entre as favoritas");
    printf ("\n[5] - Sair");
    printf ("\nopcao --> ");
    do {
    	*opcao = getch();
    } while (*opcao < '1' || *opcao > '5'); 
    printf ("%c",*opcao);   
    printf ("\n--------------------------------------------------------\n");   
}  
//----------------------------------
void cadastro(){
	system("cls");
	int i;
	qtde_banda = 0;
	do {
		printf("Quantidade de bandas que voce deseja cadastrar: ");	
    	scanf("%d", &qtde_banda);
    } while (qtde_banda < 1); 
	for (i = 0; i < qtde_banda; i++){
		printf("\n\nNome da banda[%d]: ", i+1);
		fflush(stdin);
		gets((bandas[i]).nome);
		printf("Tipo de banda: ");
		fflush(stdin);
		gets((bandas[i]).tipo);
		printf("Numero de integrantes: ");
		scanf("%d", &(bandas[i]).integrantes);
		printf("Ranking das 5 melhores: ");
		scanf("%d", &(bandas[i]).ranking);
	}	
}
//----------------------------------
void busca_ranking(){
	system("cls");
	int i, rank, flag = 0;
	printf("Digite o numero do ranking que voce deseja buscar: ");
	scanf("%d", &rank);
	for (i = 0; i < qtde_banda; i++){
		if ((bandas[i]).ranking == rank){
			printf("\n\nBanda: %s", bandas[i].nome);
			printf("\nTipo: %s", bandas[i].tipo);
			printf("\n%d integrantes", bandas[i].integrantes);
			printf("\nRanking: %d\n\n", bandas[i].ranking);
			flag = 1;
		}
	}
	if (flag == 0){
		printf("\n\nNenhum resultado encontrado.");
	}
	system("pause");
}
//----------------------------------
void busca_tipo(){
	system("cls");
	char tipobanda[25];
	int i, flag = 0;
	printf("Selecione um tipo de banda: ");
	fflush(stdin);
	gets(tipobanda);
	for (i = 0; i < qtde_banda; i++){
		if (strcmp(tipobanda,bandas[i].tipo) == 0){
			printf("\nBanda: %s\t\tRanking: %d\n", bandas[i].nome, bandas[i].ranking);
			flag = 1;
		}
	}
	if (flag == 0){
		printf("\nNenhum resultado encontrado.\n");
	}
	printf("\n\n");
	system("pause");
}
//----------------------------------
void favoritas(){
	system("cls");
	banda banda_ranking[MAX];
	int i, flag = 0;
	for (i = 0; i < qtde_banda; i++)
	if (bandas[i].ranking != 0){
		banda_ranking[bandas[i].ranking] = bandas[i];
		flag = 1;
	}
	if (flag == 0)
		printf("Nenhuma banda favorita registrada.\n\n");
	else
		for (i = 1; i <= 5; i++){
			if (banda_ranking[i].ranking != 0){
				printf("\n\nBanda: %s", banda_ranking[i].nome);
				printf("\nTipo: %s", banda_ranking[i].tipo);
				printf("\n%d integrantes", banda_ranking[i].integrantes);
				printf("\nRanking: %d\n\n", banda_ranking[i].ranking);
			}
		}
		
	system("pause");
}
//----------------------------------
int main() {
	char opcao;
	do {
		menu(&opcao);
    	switch (opcao) {
    		case '1':
				cadastro();
                break;
      		case '2':
				busca_ranking();
            	break;
      		case '3':
	  			busca_tipo();
	  			break;
	  		case '4':
	  			favoritas();
	  			break;
    	}
  } while (opcao != '5');       
}
