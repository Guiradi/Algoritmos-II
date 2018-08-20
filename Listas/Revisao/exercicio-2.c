#include <stdio.h>
#define max 100
//-----------------------------------------------------------
int LeNumero (int maximo) {
  int n;  
  do {
    printf ("Quantos elementos (1 a %d)? ",maximo);
    scanf ("%d",&n);
  } while (n < 1 || n > maximo);
  return n;
}  
//-----------------------------------------------------------
void mostraVetor (int n, int vetor[]){
  int i;   
  printf ("\n\nVetor (%d elementos)\n",n);
  for (i = 0; i < n; i++) 
    printf ("%d  ",vetor[i]);
}
//----------------------------------------------------------1-
void LeVetor (int n, int vetor[]){
  int i;   
  for (i = 0; i < n; i++) {
    printf ("v[%d] = ",i+1);
    scanf ("%d",&vetor[i]);
  }  
}
//-----------------------------------------------------------
int contaSeg (int n, int vetor[]) {
  int i, cont = 1;
  for (i = 0; i < n-1; i++)
    if (vetor[i] != vetor[i+1])
      cont++;
  return cont;
}
//-----------------------------------------------------------
int main() {
  int tamanho;
  int v[max];
  // Leitura da quantidade de elementos do vetor
  tamanho = LeNumero(max);
  // Leitura dos elementos do vetor
  LeVetor (tamanho,v);  
  // Impressao dos vetores
  mostraVetor (tamanho,v);
  // Determinção da quantidade de segmentos de números iguais consecutivos do vetor
  printf ("\n\n\n%d segmentos de numeros iguais consecutivos.",contaSeg(tamanho,v));
  getch();
}
