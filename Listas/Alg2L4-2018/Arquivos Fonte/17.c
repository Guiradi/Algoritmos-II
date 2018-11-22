/*A Torre de Han�i � um jogo com uma base hist�rica citada num ritual praticado por sacerdotes
br�manes para predizer o fim do mundo. O jogo inicia-se com uma s�rie de an�is de ouro
de tamanhos decrescentes, empilhados numa haste presa numa t�bua (os sacerdotes br�manes
usavam 64 an�is). O objetivo � empilhar todos os an�is numa segunda haste em ordem
decrescente de tamanho. Antes que isso possa ser feito, o fim do mundo chegar�. Uma
terceira haste est� dispon�vel para uso como armazenamento intermedi�rio. Construa um
programa recursivo para o problema da torre de Han�i. O problema consiste em transferir N
discos, utilizando tr�s hastes, que est�o na haste A para a haste C, utilizando as seguintes
regras:
? pode-se mover somente um disco de cada vez;
? nenhum disco deve ser colocado sobre um disco menor;
? qualquer disco pode ser movido de qualquer haste para qualquer haste, respeitando a regra
acima */

#include <stdio.h>
#include <stdlib.h>

int hanoi(int N, char torreA[10], char torreB[10], char torreC[10])
{
	if (N == 1)
	{
		printf("\nAnel %d movido da %s para a %s", N, torreA, torreC);
		return;
	}
	hanoi(N-1, torreA, torreC, torreB);
	printf("\nAnel %d movido da %s para a %s", N, torreA, torreC);
	hanoi(N-1, torreB, torreA, torreC);
}

int main()
{
	int N;
	printf("Digite a quantidade de aneis: ");
	scanf("%d", &N);
	hanoi(N, "Torre 1", "Torre 2", "Torre 3");
	system("pause>>null");
	
}
