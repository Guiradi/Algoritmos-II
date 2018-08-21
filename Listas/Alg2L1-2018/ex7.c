/* 7 Considere a estrutura
struct vetor{
float x;
float y;
float z;
};
que represente um vetor no R3. Desenvolva um programa que calcule a soma de dois vetores.*/
#include <stdio.h>
#include <stdlib.h>
/*******************/
typedef struct {
	float x;
	float y;
	float z;
} vetor;

void levetor(vetor *x, int i){
	printf("\nv[%d]:\nx = ");
	scanf("%f", &(*x).x);
	printf("y = ");
	scanf("%f", &(*x).y);
	printf("z = ");
	scanf("%f", &(*x).z);
	printf("\nv[%d] = (%.2f, %.2f, %.2f)\n", i, (*x).x, (*x).y, (*x).z);
}

void soma(vetor x, vetor y, int i, int j){
	vetor soma;
	soma.x = x.x + y.x;
	soma.y = x.y + y.y;
	soma.z = x.z + y.z;
	printf("\n\nSoma: v[%d] + v[%d] = (%.2f, %.2f, %.2f)\n\n", i, j, soma.x, soma.y, soma.z);
}

int main(){
	vetor v1, v2;
	printf("SOMA DE VETORES NO R3\n\n");
	levetor(&v1, 1);
	levetor(&v2, 2);
	soma(v1,v2,1,2);
	system("pause");
	return 0;
}
