#include <stdio.h>
#include <string.h>
#include <conio.h>

//Constante tamanho máximo de nomes do vetor:
#define MAX 30
//Constante tamanho máximo da qtde de letras em um vetor:
#define TAMANHO 20

//Define tamanhos dos vetores:
void leQtde(int *t){
	do{
		printf("\nDigite a quantidade de elementos (1 a %d): ", MAX);
		scanf("%d",*&t);
	} while(*t<1 || *t>MAX);
}

//Define os nomes contidos nos vetores:
void leNome(int n, char v[][TAMANHO]){
	int i;
	fflush(stdin);
	for (i = 0 ; i < n ; i++){
		printf("Nome[%d]: ", i+1);
		gets(v[i]);
	}
}

//Mostra os nomes contidos nos vetores:
void mostraNome(int n, char v[][TAMANHO]){
	int i;
	for(i = 0; i < n; i++){
		printf ("\nnome[%d]: %s",i+1,v[i]);
	}
}

//Faz a troca entre os nomes (usada na função bubblesort):
void troca (char n1[], char n2[]){
	char aux[20];
	strcpy(aux,n1);
	strcpy(n1,n2);
	strcpy(n2,aux);
}

//Ordenador bubblesort:
void BubbleSort (int n, char v[][TAMANHO]){
	int i, j, aux;
	int trocado = 1;
	for (i = 0; i < n-1 && trocado; i++){
		trocado = 0;
		for (j = 0; j < n-i-1; j++){
			if(stricmp(v[j],v[j+1])>0){
			trocado = 1;
			troca(v[j],v[j+1]);
			}
		}
	}
}

// -- Programa:
int main(){
	//Variáveis: vetores A, B e C; tamanhos T1 e T2;
	char A[MAX][TAMANHO], B[MAX][TAMANHO], C[MAX+MAX][TAMANHO];
	int i, j, t1, t2, t3;
	printf ("\n----- VETOR 1 -----");
	leQtde(&t1);
	leNome(t1,A);
	BubbleSort(t1,A);
	mostraNome(t1,A);
	printf ("\n\n----- VETOR 2 -----");
	leQtde(&t2);
	leNome(t2,B);
	BubbleSort(t2,B);
	mostraNome(t2,B);
	//Unir os dois vetores classificados:
	i = j = t3 = 0;
	while (i < t1 && j < t2)
		if (stricmp(A[i],B[j]) < 0)
			strcpy(C[t3++],A[i++]);
		else
			strcpy(C[t3++],B[j++]);
			
	while (i < t1)
		strcpy (C[t3++],A[i++]);
  	while (j < t2)
    	strcpy (C[t3++],B[j++]);
	printf ("\n\n----- VETOR 3 -----");
	mostraNome (t3,C);    
	getch();
}
