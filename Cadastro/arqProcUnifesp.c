// Trabalhando com arquivos
// Cria arquivo usando a primeira linha de "/home/pub/ed/Cadastro.csv" e
// todas as linhas que contenham o texto "Universidade Federal de São Paulo"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 1000

int main(){

	FILE *fp, *outfp;
	char linha[TAM_MAX];
	int tmax=0, tam=0;
	
	
	fp = fopen( "/home/pub/ed/Cadastro.csv", "r" );
	outfp = fopen( "UNIFESP.csv", "w" );
	if( !fp || !outfp ){
		printf("Erro de abertura de arquivo.\n");
		exit(-1);
		}
	
	fgets( linha, TAM_MAX, fp );
	fputs( linha, outfp );
	
	while( fgets( linha, TAM_MAX, fp ) ) {
		if( strstr( linha, "Universidade Federal de São Paulo") )
			fputs( linha, outfp );
		}

	fclose(fp);
	fclose(outfp);

	return 0;
	}
