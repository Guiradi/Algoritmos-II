/* 5 Suponha um cadastro de alunos onde cada aluno contém os seguintes campos: Nome,
Data de Nascimento (dia, mês, ano), RG, Sexo, Endereço (Rua, Cidade, Estado, CEP),
RA (Registro de Aluno) e CR (Coeficiente de Rendimento: número real no intervalo
[0,1]). Faça um programa que realize o cadastro de alunos em um vetor com 100 posições.
O programa deve manipular este cadastro com as seguintes opções:
1) Inserir um novo aluno no cadastro.
2) Ordenar o cadastro por nome em ordem alfabética.
3) Ordenar o cadastro por CR, maiores primeiro.
4) Ler o valor de um RA e imprimir os dados do aluno no cadastro com mesmo RA.
5) Imprimir o cadastro na ordem atual. */

#include <stdio.h>
#include <stdlib.h>
/******************/
#define MAX 100
/******************/
typedef struct {
	char nome[30];			// Espaço para 30 caracteres no nome
	int dia, mes, ano;		// dd mm aaaa ou dd mm aa (3 inteiros para a data)
	int RG;					// inteiro rg
	char sexo;				// f ou m
	char rua[30], cidade[30], estado[30], cep[10];	// endereço completo
	int RA;					// numero de registro de aluno
	float CR;				// real que representa o cr
} reg;
/******************/
reg aluno[MAX];
int num = 0;
/******************/
void menu (char *opcao) {
	system("cls");
	printf ("--------------------------------------------------------");   
    printf ("\n M E N U\tE S C O L I N H A\tZ I K A"); 
	printf("\nAlunos registrados: %d", num);
    printf ("\n[1] - Cadastrar alunos.");
    printf ("\n[2] - Ordenar o cadastro por nome em ordem alfabetica.");
    printf ("\n[3] - Ordenar o cadastro por CR, maiores primeiro.");
    printf ("\n[4] - Ler o valor de um RA e imprimir os dados do aluno no cadastro com mesmo RA.");
    printf ("\n[5] - Imprimir o cadastro na ordem atual.");
    printf ("\n[6] - Sair");
    printf ("\nopcao --> ");
    do {
    	*opcao = getch();
    } while (*opcao < '1' || *opcao > '6'); 
    printf ("%c",*opcao);   
    printf ("\n--------------------------------------------------------\n");   
}  
/******************/
void cadastro(){
	system("cls");
	printf("Aluno[%d]\n\nDados Pessoais\n", num+1);
	printf("Nome: ");
	fflush(stdin);
	gets(aluno[num].nome);
	printf("Data de Nascimento(dd mm aa): ");
	scanf("%d %d %d", &aluno[num].dia, &aluno[num].mes, &aluno[num].ano);
	printf("RG: ");
	scanf("%d", &aluno[num].RG);
	fflush(stdin);
	printf("Sexo (m ou f): ");
	scanf("%c", &aluno[num].sexo);
	printf("\nDados de Endereco\nRua: ");
	fflush(stdin);
	gets(aluno[num].rua);
	printf("Cidade: ");
	gets(aluno[num].cidade);
	printf("Estado: ");
	gets(aluno[num].estado);
	printf("CEP (XXXXX-XXX): ");
	gets(aluno[num].cep);
	printf("\nDados Escolares:\nRA: ");
	scanf("%d", &aluno[num].RA);
	printf("CR: ");
	scanf("%f", &aluno[num].CR);
	if (aluno[num].CR < 0 || aluno[num].CR > 1){
		do{
			printf("[ERRO] Digite um valor de CR valido (0 a 1): ");
			scanf("%f", &aluno[num].CR);
		} while (aluno[num].CR < 0 || aluno[num].CR > 1);
	}
	num++;
}
/******************/
void troca (reg a[MAX], reg b[MAX], int j, int k){
	reg aux;
	aux = a[j];
	a[j] = b[j+1];
	b[j+1] = aux;
}
/******************/
void ordenaAlfabetica() {
	int i, j, trocado = 1;
	for (i = 0; i < num - 1 && trocado; i++){
		trocado = 0;
		for (j = 0; j < num - i - 1; j++){
			if (strcmp(aluno[j].nome,aluno[j+1].nome) > 0){
				trocado = 1;
				troca (aluno, aluno, j, j+1);
			}
		}
	}
}
/********************/
void ordenaCR() {
	int i, j, trocado = 1;
	for (i = 0; i < num - 1 && trocado; i++){
		trocado = 0;
		for (j = 0; j < num - i - 1; j++){
			if (aluno[j].CR < aluno[j+1].CR){
				trocado = 1;
				troca (aluno, aluno, j, j+1);
			}
		}
	}
}
/********************/
void imprimeCadastros(){
	int i;
	system("cls");
	printf("Cadastros:\n\n");
	for (i = 0; i < num; i++){
		printf("Aluno[%d]\n", i+1);
		printf("Nome: %s", aluno[i].nome);
		printf("\tData de Nascimento: %d/%d/%d", aluno[i].dia, aluno[i].mes, aluno[i].ano);
		printf("\nRG: %d", aluno[i].RG);
		printf("\nSexo: %c", aluno[i].sexo);
		printf("\nEndereco\nRua: %s", aluno[i].rua);
		printf("\n%s\t-\t%s\t-\t%s", aluno[i].cidade, aluno[i].estado, aluno[i].cep);
		printf("\n\nRA: %d\tCR: %.2f\n\n", aluno[i].RA, aluno[i].CR);
	}
	system("pause");
}
/********************/
void imprimeporRA(){
	int i, ra, flag = 0;
	system("cls");
	printf("Procurar por RA: ");
	scanf("%d",&ra);
	for (i = 0; i < num ; i++){
		if (ra == aluno[i].RA){
			flag = 1;
			printf("\n\nAluno[%d]\n", i+1);
			printf("Nome: %s", aluno[i].nome);
			printf("\tData de Nascimento: %d/%d/%d", aluno[i].dia, aluno[i].mes, aluno[i].ano);
			printf("\nRG: %d", aluno[i].RG);
			printf("\nSexo: %c", aluno[i].sexo);
			printf("\nEndereco\nRua: %s", aluno[i].rua);
			printf("\n%s\t-\t%s\t-\t%s", aluno[i].cidade, aluno[i].estado, aluno[i].cep);
			printf("\n\nRA: %d\tCR: %.2f\n\n", aluno[i].RA, aluno[i].CR);	
		}
	}
	if (flag == 0)
		printf("\n\nNenhum registro encontrado.");
	system("pause");
}
/********************/
int main() {
	char opcao;
	do {
		menu(&opcao);
    	switch (opcao) {
    		case '1':
				cadastro();
                break;
      		case '2':
				ordenaAlfabetica();
            	break;
      		case '3':
	  			ordenaCR();
	  			break;
	  		case '4':
	  			imprimeporRA();
	  			break;
	  		case '5':
	  			imprimeCadastros();
	  			break;
    	}
  } while (opcao != '6');       
}
