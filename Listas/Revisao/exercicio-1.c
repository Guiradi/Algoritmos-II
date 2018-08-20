#include <stdio.h>
#include <string.h>
#include <conio.h>
#define TAMANHO 20
#define MAX 30
//--------------------------------------
void leQte (int *qte) {
  do {
    printf ("\nDigite a quantidade de elementos (1 a %d): ",MAX);
    scanf ("%d",*&qte);
  } while (*qte<1 || *qte > MAX);      
}  
//--------------------------------------
void leNomes (int n, char v[][TAMANHO]) {
  int i;
  fflush (stdin);
  for (i = 0; i < n; i++){
    printf ("nome[%d]: ",i+1);
    gets(v[i]);
  }  
}  
//--------------------------------------
void mostraNomes (int n, char v[][TAMANHO]) {
  int i;
  for (i = 0; i < n; i++)
    printf ("\nnome[%d]: %s",i+1,v[i]);
}  
//--------------------------------------
void troca (char n1[], char n2 []) {
 char aux[10];
 strcpy (aux,n1);
 strcpy (n1,n2);
 strcpy (n2,aux);
}
//--------------------------------------
void BubbleSort (int n, char v[][TAMANHO]) {
 int i, j, aux;
 int trocado = 1;
 for (i=0; i<n-1 && trocado; i++) {
   trocado = 0;
   for (j=0; j<n-i-1; j++) {
     if (stricmp(v[j],v[j+1])>0) {
       trocado = 1;
       troca (v[j], v[j+1]);
     }
   }
 }
}
//--------------------------------------
int main () {
  char v1[MAX][TAMANHO], v2[MAX][TAMANHO], v3[MAX+MAX][TAMANHO];
  int i, j, n1, n2, n3;
  printf ("\n----- VETOR 1 -----");
  leQte (&n1);
  leNomes (n1,v1);
  BubbleSort (n1,v1);
  mostraNomes (n1,v1);
  printf ("\n\n----- VETOR 2 -----");
  leQte (&n2);
  leNomes (n2,v2);
  BubbleSort (n2,v2);
  mostraNomes (n2,v2);
  // Unir os dois vetores classificados
  i = j = n3 = 0;
  while (i < n1 && j < n2) 
    if (stricmp (v1[i],v2[j]) < 0) 
      strcpy (v3[n3++],v1[i++]);
    else  
      strcpy (v3[n3++],v2[j++]);
  while (i < n1)
    strcpy (v3[n3++],v1[i++]);
  while (j < n2)
    strcpy (v3[n3++],v2[j++]);
  printf ("\n\n----- VETOR 3 -----");
  mostraNomes (n3,v3);    
  getch();
}
