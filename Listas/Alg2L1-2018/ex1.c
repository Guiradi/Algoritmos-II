/*Defina uma estrutura que represente bandas de música. Essa estrutura deve ter o nome
da banda, que tipo de música ela toca, o número de integrantes e em que posição
do ranking essa banda está dentre as suas cinco bandas favoritas. Se a banda não estiver
tiver entre suas cinco bandas favoritas, utilize o número zero neste campo. Em seguida,
desenvolva as funções que seguem:
a) Faça uma função que cadastre um determinado número de bandas. A quantidade de
bandas a serem cadastradas deve ser fornecida pelo usuário. As bandas devem ser
armazenadas em um vetor em que cada elemento é uma estrutura conforme definido
anteriormente.
b) Faça uma função que faça uma busca de acordo com o ranking da banda. Essa função
deve exibir todas as informações da banda de um determinado ranking.
c) Crie uma função que solicite ao usuário um tipo de música e exiba as bandas com
esse tipo de música no seu ranking.
d) Crie uma função que solicite o nome de uma banda ao usuário e informe se ela está
entre suas bandas favoritas ou não*/

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
