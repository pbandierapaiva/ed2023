// Programa que faz busca no Cadastro Geral de Servidores usando arquivo de indice
// Armazena resultados numa lista encadeada de CADIND:  LISTACADIND
//


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
	int contador=0;
	int regInteresse;
	int maxRegs = 10;
	
	CADBAS reg;
	CADIND regind;
	
	LISTACADIND *resultado, *pres;
	
	resultado = NULL;
	pres = NULL;
	
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
	indfp = fopen( "Cadastro.ind", "r" );
	if(!indfp){
		printf("Erro de abertura de arquivo índice.\n");
		exit(-1);
		}

	while( fread( &regind, sizeof(regind), 1, indfp ) ){
		if( strstr(regind.Nome, nome) ) {
			// Encontrado registro
			resultado = malloc( sizeof(LISTACADIND) );
			if(!resultado) {
				printf("Erro de alocação de memória.\n\n");
				return -1;
				}
			resultado->cadind = regind;
			resultado->prox = pres;
			pres = resultado;	
			}
		}
	
	if( resultado == NULL ) {
		printf("\nNenhum registro encontrado\n");
		return 0;
		}
	if( resultado->prox == NULL ) {
		regInteresse=1;
		}
	else {
		printf("\nRegistros encontrados: \n");
		pres = resultado;
		contador=0;
		while( pres != NULL ){
			contador++;
			printf("%d %s\n", contador, pres->cadind.Nome);
			pres = pres->prox;
			}
		printf("\nEntre com o número do registro de interesse: \n");
		scanf( "%d", &regInteresse );
		}

	if( regInteresse<=0 || regInteresse>contador ){
		printf("\nRegistro inválido\n");
		return 0;
		}
	
	fp = fopen( "/home/pub/ed/Cadastro.csv", "r" );	
	if(!fp ){
		printf("Erro de abertura de arquivo CSV.\n");
		exit(-1);
		}

	pres = resultado;
	for(int i=0; i<(regInteresse-1); i++)
		pres = pres->prox;		
		
	fseek( fp, pres->cadind.posicao, 0 );
	fgets( linha, TAM_MAX, fp );
	pegaReg( &reg, linha );
	imprimeReg( reg );

	fclose(fp);
	fclose(indfp);

	return 0;
	}
