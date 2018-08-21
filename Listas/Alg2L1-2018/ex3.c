/*3. Um número complexo é dividido em duas partes na forma z=a+b.i, onde a e b são números
reais. Defina um tipo chamado complexo usando struct para contemplar estas
duas partes. Além disso, faça funções para ler, somar, subtrair e multiplicar números
complexos.
A linguagem C possui a biblioteca complex.h mas não deve ser usada para desenvolver
esse exercício. */

#include <stdio.h>
#include <stdlib.h>
/************************/
typedef struct {
	float a, b;
} complexo;
/************************/
void ler (complexo *z, int i){
	printf("\n\nSendo z[%d] = a + b*i um numero complexo\nDe o valor de a: ", i);
	scanf("%f", &(*z).a);
	printf("Agora, de o valor de b: ");
	scanf("%f", &(*z).b);
	printf("\nz[%d] = %.2f + %.2f * i", i, (*z).a, (*z).b);
}
/************************/
void soma (complexo z1, complexo z2, complexo *soma){
	(*soma).a = z1.a + z2.a;
	(*soma).b = z1.b + z2.b;
}
/************************/
void sub (complexo z1, complexo z2, complexo *soma){
	(*soma).a = z1.a - z2.a;
	(*soma).b = z1.b - z2.b;
}
/************************/
void mult (complexo z1, complexo z2, complexo *soma){
	(*soma).a = z1.a * z2.a - z1.b * z2.b;
	(*soma).b = z1.a * z2.b + z1.b * z2.a;
}
/************************/
int main(){
	complexo z1, z2, zop;
	printf("OPERACOES COM COMPLEXOS!\n\n");
	ler (&z1, 1);
	ler (&z2, 2);
	system("cls");
	soma (z1, z2, &zop);
	printf(" z[1] + z[2] = (%.2f + %.2f * i) + (%.2f + %.2f * i) = %.2f + %.2f * i\n", z1.a, z1.b, z2.a, z2.b, zop.a, zop.b);
	sub (z1, z2, &zop);
	printf("\n\n z[1] - z[2] = (%.2f + %.2f * i) - (%.2f + %.2f * i) = %.2f + %.2f * i\n", z1.a, z1.b, z2.a, z2.b, zop.a, zop.b);
	mult (z1, z2, &zop);
	printf("\n\n z[1] * z[2] = (%.2f + %.2f * i) * (%.2f + %.2f * i) = %.2f + %.2f * i\n", z1.a, z1.b, z2.a, z2.b, zop.a, zop.b);
	
	system("pause>>null");
	return 0;	
}
