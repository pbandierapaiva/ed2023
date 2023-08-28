// Trabalhando com caracteres

#include <stdio.h>
#include <string.h>

#define TAM_MAX 21

int main() {
  char cara;
  char texto[TAM_MAX];
  char inverso[TAM_MAX];
  char *ptr, *ptrinv;

  printf("Entre com um texto: ");
  
  fgets(texto, TAM_MAX-1, stdin);
  
  printf("O texto entrado é %s\n", texto);

  
  for(ptr = texto; *ptr!='\0'; ptr++);
  if( *(ptr-1)=='\n' ) {
  	ptr--;
  	*ptr='\0';
  	}

  printf("o tamanho da string entrada é de %ld \n", strlen( texto ));  
  for(ptr=ptr-1, ptrinv=inverso;  ptr >= texto   ; ptr--, ptrinv++)
  	*ptrinv = *ptr; 
  *ptrinv = '\0'; 
  
  printf("O texto inverso é %s \n", inverso);
  
}







