// Trabalhando com arquivos
// Verifica o tamanho máximo da linha do arquivo "/home/pub/ed/Cadastro.csv"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 5000

int main(){

	FILE *fp;
	char linha[TAM_MAX];
	int tmax=0, tam=0;
	
	
	fp = fopen( "/home/pub/ed/Cadastro.csv", "r" );
	if(!fp){
		printf("Erro de abertura de arquivo.\n");
		exit(-1);
		}
	
	while( fgets( linha, TAM_MAX, fp ) ) {
		// printf("%s", linha);
		tam = strlen(linha);
		if( tam > tmax )
			tmax = tam;
		}
	printf("\nO tamanho máximo da linha é: %d\n\n", tmax);


	return 0;
	}
