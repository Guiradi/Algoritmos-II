#include<stdio.h>
#include<stdlib.h>

int fiboRecurs (int n){
	if (n <= 2)		return 1;
	return fiboRecurs(n - 2) + fiboRecurs(n - 1);
}

int main(){
	int n, fibo;
	printf("Digite um numero: ");
	scanf("%d", &n);
	fibo = fiboRecurs(n);
	printf("%d numero de Fibonacci (Fibonacci Recursivo): %d\n", n, fibo );
	system("pause");
	return 0;
}
