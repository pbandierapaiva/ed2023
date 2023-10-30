//  buscaArvoreBin - lê Cadastro e armazena em memória uma árvore binária com um índice 
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cadastro.h"

void insere( NOCAD **noPai, CADIND valor ){
	NOCAD *novoNo;
	
	novoNo = malloc( sizeof(NOCAD) );
	if(novoNo==NULL) exit(-1);
	
	strcpy( novoNo->carga.Nome, valor.Nome);
	novoNo->carga.posicao = valor.posicao;
	novoNo->noE = NULL;
	novoNo->noD = NULL;	
	
	if( *noPai == NULL ) { 
		*noPai = novoNo;
		return;
		}
	if( strcmp( (*noPai)->carga.Nome, valor.Nome) > 0  ) 
		insere( &((*noPai)->noE ), valor);
	else
		insere( &((*noPai)->noD ), valor);
}

int altura( NOCAD *meuNo ){
	int alturaD=0;
	int alturaE=0;
	
	if( meuNo->noD == NULL && meuNo->noE == NULL )
		return 0;
	if( meuNo->noD )   // meuNo->noD != NULL
		alturaD = altura( meuNo->noD );
	if( meuNo->noE )  // meuNo->noE != NULL
		alturaE = altura( meuNo->noE );
	if( alturaE > alturaD )
		return alturaE+1;
	else
		return alturaD+1;
}


int main( ){
	FILE *fp;
	long int pos;
	long int conta=0;
	char linha[TAM_MAX];
	CADIND regind;
	NOCAD *arvore = NULL;

	fp = fopen( "/home/pub/ed/UNIFESP.csv", "r" );
	if( !fp ) {
		printf("Arquivo de cadastro não encontrado.\n\n");
		return -1;
		}
	
	// despreza linha de cabeçalho	
	fgets( linha, TAM_MAX, fp );
	pos = ftell(fp);
	while( fgets( linha, TAM_MAX, fp ) ) {
		conta++;
		if( conta%10 == 0 ) {
			printf("\r%ld", conta);
			fflush(stdout);
			}
		if(conta>=4000) {
			printf( "Árvore de altura: %d\n", altura(arvore) );
			return 0;
			}
		pegaCampo(linha, NOME, regind.Nome);
		regind.posicao = pos;
		
		insere( &arvore, regind );
		
		pos = ftell(fp);	 
		}
	
	
	
	
}


