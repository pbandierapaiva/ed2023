// Trabalhando com strings 
// conta número de palavras em texto terminado em "end"

#include <stdio.h>
#include <string.h>

#define TAM_MAX 200

int main() {
  char cara;
  int i=0;

  printf("Entre com um texto: \n\n");
  cara = getchar();
  while(cara != EOF) {
  	while( cara==' ' || cara=='\n')
  		cara = getchar();
  	if(cara==EOF) break;

  	if(cara=='e') {
  		cara=getchar();
  		if(cara=='n') {
  			cara=getchar();
  			if(cara=='d'){
  				break;
  				}
  			}
  		}
  	i++;
  	while( cara!=' ' && cara!='\n' && cara!=EOF )
  		cara=getchar();
  	
  	}
  printf("Encontradas %d palavras.\n\n", i);
  }
