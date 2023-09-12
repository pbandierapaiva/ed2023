// Programa que faz busca no Cadastro Geral de Servidores

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cadastro.h"

int main( int argc, char *argv[] ){

	FILE *fp;

	char linha[TAM_MAX];
	char nome[100];
	char nlido[100];
	char *p;
	
	CADBAS reg;

	printf("Executando busca linear no arquivo.\n");
	if( argc < 2 ){
		printf("Entre com nome para busca: ");
		fgets(nome, 100, stdin);
		}
	else {
		strcpy(nome, argv[1]);
		}
	
	// remove \n do final do string
	for( p = nome; *p!='\n' && *p!='\0'; p++)
		*p = toupper(*p);
	*p = '\0';
	
// Busca linear no cadastro	

	
	fp = fopen( "/home/pub/ed/Cadastro.csv", "r" );
	if(!fp){
		printf("Erro de abertura de arquivo.\n");
		exit(-1);
		}

	fgets( linha, TAM_MAX, fp );
	while( fgets( linha, TAM_MAX, fp ) ) {
		pegaCampo(linha, NOME, nlido);
		if( ! strcmp(nome,nlido) ) {
			pegaReg( &reg, linha);
			imprimeReg( reg );
			}
	}
	fclose(fp);

	return 0;
	}
