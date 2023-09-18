// Trabalhando com strings 

#include <stdio.h>
#include <string.h>

#define TAM_MAX 200

int main() {
  char cara;
  char texto[TAM_MAX];
  char texto2[TAM_MAX];

  printf("Entre com um texto: ");
  
  fgets(texto, TAM_MAX-1, stdin);
  
  printf("O texto entrado é %s\n\n", texto);

  for(int i=0; i<strlen(texto); i++) {
  	if( texto[i]!=' ' )
  		printf("%c",texto[i]);
  	else {
  		printf("\n");
  		while( texto[i+1]==' ' ) i++;
  	}
  
  }



}







