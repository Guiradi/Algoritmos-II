#include<stdio.h>
#include<stdlib.h>

int par(int x, int n){
	if (n == 0) return;
	if (x % 2 == 0){
		printf("%4d", x);
		par(x+2, n-1);
	}
	else
		par(x+1, n);
}

int main(){
	int n;
	scanf("%d", &n);
	par(1, n);
	system("pause");
}
