/* 8, 9, 10 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
/**********************/
#define MAX 100
/**********************/
typedef struct {
	char nome[30], rg[13], sexo;
	float salario;
	int idade, dia, mes, ano;
} TipoReg;
/**********************/
typedef struct {
	TipoReg funcionario[100];
	int quant;
} TipoCadastro;
/**********************/
void IniciaCadastro(TipoCadastro *cadastro){
	(*cadastro).quant = 0;
}
/**********************/
void LeFuncionarios (TipoCadastro *x){
	char decide;
	do {
	printf("\n\nFuncionario %d\n", (*x).quant+1);
	printf("Nome: ");
	fflush(stdin);
	gets((*x).funcionario[(*x).quant].nome);
	printf("RG: ");
	gets((*x).funcionario[(*x).quant].rg);
	printf("Salario: ");
	scanf("%f", &(*x).funcionario[(*x).quant].salario);
	printf("Idade: ");
	scanf("%d", &(*x).funcionario[(*x).quant].idade);
	printf("Sexo: ");
	fflush(stdin);
	scanf("%c", &(*x).funcionario[(*x).quant].sexo);
	printf("Data de Nascimento (dd mm aa): ");
	scanf("%d %d %d", &(*x).funcionario[(*x).quant].dia, &(*x).funcionario[(*x).quant].mes, &(*x).funcionario[(*x).quant].ano);
	(*x).quant++;
	fflush(stdin);
	printf("\nDeseja registrar outro funcionario? (s/n)\nResposta -->");
	do{
		decide = toupper(getch());
	} while (decide != 'S' && decide != 'N');
	printf("%c", decide);
	} while (decide != 'N');
}
/**********************/
void ListaFuncionarios(TipoCadastro x){
	int i;
	for (i = 0; i < x.quant; i++){
		printf("\n\nFuncionario %d\n", x.quant);
		printf("Nome: %s\n", x.funcionario[i].nome);
		printf("RG: %s\n", x.funcionario[i].rg);
		printf("Salario: R$ %.2f\n", x.funcionario[i].salario);
		printf("Idade: %d anos\n", x.funcionario[i].idade);
		printf("Sexo: %c\n", x.funcionario[i].sexo);
		printf("Data de Nascimento: %d/%d/%d\n", x.funcionario[i].dia, x.funcionario[i].mes, x.funcionario[i].ano);
		system("pause");
	}
}
/**********************/
void troca (TipoReg x, TipoReg y, int j, int k){
	TipoReg aux;
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
/**********************/
int main(){
	TipoCadastro cadastro;
	IniciaCadastro(&cadastro);
	LeFuncionarios(&cadastro);
	ListaFuncionarios(cadastro);
	return 0;
}
