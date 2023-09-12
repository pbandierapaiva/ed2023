// criaIndiceCadastro - Programa para gerar arquivo de indice de Cad Geral de Serv Publicos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastro.h"

int main(){

	FILE *fp, *outfp;
	char linha[TAM_MAX];
	char campo[TAM_MAX];
	long int pos=0;
	long int contador=0;
	
	CADIND regind;

	fp = fopen( "/home/pub/ed/Cadastro.csv", "r" );
	outfp = fopen( "Cadastro.ind", "w" );
	if(!fp || !outfp){
		printf("Erro de abertura de arquivo.\n");
		exit(-1);
		}
	
	fgets( linha, TAM_MAX, fp );
	pos = ftell(fp);
	while( fgets( linha, TAM_MAX, fp ) ) {
		contador++;
		if( ! contador%100 ) {
			printf("\r %ld", contador);
			fflush(stdout);
			}
		pegaCampo(linha, NOME, regind.Nome);
		regind.posicao = pos;
		fwrite( &regind, sizeof(regind), 1, outfp );
		pos = ftell(fp);	 
		}
	fclose(fp);
	fclose(outfp);
	return 0;
	}
