#include <stdio.h>
#include <stdlib.h>

void naturais(int x){
	if (x == 0) return;
	printf("%3d", x);
	naturais(x - 1);
}


int main () {
	int x;
	scanf("%d", &x);
	naturais(x);
	system("pause");
	return 0;
}
