// Programa que faz busca no Cadastro Geral de Servidores

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cadastro.h"

int main( int argc, char *argv[] ){

	FILE *fp, *indfp;

	char linha[TAM_MAX];
	char nome[100];
	char nlido[100];
	char *p;
	
	CADBAS reg;
	CADIND regind;

	printf("Executando busca indexada no arquivo.\n");
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

// Busca indexada no cadastro		
	fp = fopen( "/home/pub/ed/Cadastro.csv", "r" );
	indfp = fopen( "Cadastro.ind", "r" );
	if(!fp || !indfp){
		printf("Erro de abertura de arquivo.\n");
		exit(-1);
		}

	while( fread( &regind, sizeof(regind), 1, indfp ) ){
		if( ! strcmp(nome,regind.Nome) ) {
			fseek( fp, regind.posicao, 0 );
			fgets( linha, TAM_MAX, fp );
			pegaReg( &reg, linha );
			imprimeReg( reg );
			}
		}
	fclose(fp);
	fclose(indfp);

	return 0;
	}
