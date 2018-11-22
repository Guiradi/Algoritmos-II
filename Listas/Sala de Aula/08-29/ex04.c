#include <stdio.h>
#include <stdlib.h>

int Digitos (int N, int cont){
	if (abs(N) > 9) {
		Digitos(N/10, cont+1);
	}
	else
		return cont;
}

int main(){
	int N;
	printf("Digite um numero: ");
	scanf("%d", &N);
	printf("Esse numero possui %d digitos.\n\n", Digitos(N,1));
	system("pause");
	return 0;
}
