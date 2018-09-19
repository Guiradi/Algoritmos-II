#include <stdio.h>
#include <stdlib.h>

int y = 1;

int x (int n){
	if (n == 0)
	return 0;
	if (n == 1)
	return 1;
	if (n == 2)
	return 2;
	printf("Chamada %d\n", y++);
	return x(n-1) + x(n-2) + x(n-3);
}

int main()
{
	printf("%d", x(6));
	system("pause>>null");
}

