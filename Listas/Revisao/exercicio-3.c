#include <stdio.h>
#define max 100
//-----------------------------------------------------------
int LeNumero (int maximo) {
  int n;  
  do {
    printf ("Quantas datas (1 a %d)? ",maximo);
    scanf ("%d",&n);
  } while (n < 1 || n > maximo);
  return n;
}  
//-----------------------------------------------------------
void mostraDatas (int n, int vetor[][3]){
  int i;   
  for (i = 0; i < n; i++) 
    printf ("\n%2d %2d %4d",vetor[i][0],vetor[i][1],vetor[i][2]);
}
//----------------------------------------------------------1-
void LeDatas (int n, int vetor[][3]){
  int i;   
  for (i = 0; i < n; i++) {
    printf ("Data %d:\n",i+1);
    scanf ("%d %d %d",&vetor[i][0],&vetor[i][1],&vetor[i][2]);
  }  
}
//-----------------------------------------------------------
void troca (int *a, int *b) {
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}
//--------------------------------------
void BubbleSort (int n, int v[][3]) {
  int i, j, aux;
  int trocado = 1;
  for (i=0; i<n-1 && trocado; i++) {
    trocado = 0;
    for (j=0; j<n-i-1; j++) 
      if (v[j][2] > v[j+1][2]) {
        trocado = 1;
        troca (&v[j][0],&v[j+1][0]);
        troca (&v[j][1],&v[j+1][1]);
        troca (&v[j][2],&v[j+1][2]);
      }
      else
        if (v[j][2] == v[j+1][2]) 
          if (v[j][1] > v[j+1][1]){
            trocado = 1;
            troca (&v[j][0],&v[j+1][0]);
            troca (&v[j][1],&v[j+1][1]);
          }
          else
            if (v[j][1] == v[j+1][1] && v[j][0] > v[j+1][0]){
              trocado = 1;
              troca (&v[j][0],&v[j+1][0]);
            }
  }                            
}
//-----------------------------------------------------------
int main() {
  int qte;
  int datas[max][3];
  // Leitura da quantidade de datas
  qte = LeNumero(max);
  // Leitura das datas
  LeDatas (qte,datas);  
  // Mostra datas antes de ordenadas
  printf ("\n\nDatas antes da ordenacao");
  mostraDatas (qte,datas);
  // Ordena as datas
  BubbleSort (qte,datas);
  // Mostra datas depois de ordenadas
  printf ("\n\nDatas apos da ordenacao");
  mostraDatas (qte,datas);
  getch();
}
