#define max 30
//----------------------------------------------------
int strPalindrome (char str[]) {
  int i;
  for (i = 0; i < strlen(str)/2; i++)
    if (toupper(str[i]) != toupper(str[strlen(str)-i-1]))
      return 0;
  return 1;
}          
//----------------------------------------------------
int numPalindrome (int num) {
  char texto[max];  
  itoa (num,texto,10);
  return strPalindrome(texto);
}          
//----------------------------------------------------
int main() {
  char texto[max];
  int numero;
    //--------------------- Texto ----------------------  
  printf ("Digite uma palavra: ");
  gets (texto);
  if (strPalindrome(texto))
    printf ("\n%s eh palindrome.",texto);
  else
    printf ("\n%s nao eh palindrome.",texto);  
  //--------------------- Numero ---------------------
  printf ("\n\n\nDigite um numero: ");
  scanf ("%d",&numero);;
  if (numPalindrome(numero))
    printf ("\n%d eh palindrome.",numero);
  else
    printf ("\n%d nao eh palindrome.",numero);  
  getch();
}  
